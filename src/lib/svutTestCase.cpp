/*****************************************************
             PROJECT  : svUnitTest
             VERSION  : 0.3.0-dev
             DATE     : 03/2011
             AUTHOR   : Valat Sébastien
             LICENSE  : CeCILL-C
*****************************************************/

/********************  HEADERS  *********************/
#include "svutTestCase.h"
#include "svutListenerMultiplexer.h"
#include <cassert>

/**********************  USING  *********************/
using namespace std;

/********************  NAMESPACE  *******************/
namespace svUnitTest
{

/********************  GLOBALS  *********************/
/*
 * Liste contenant les cas de tests auto-enregistrés pour pouvoir les récupérer depuis
 * svutRunner.
*/

/*******************  FUNCTION  *********************/
/**
 * Class constructor of the test case.
 * @param name Define the name of the test case. Generaly we may use the name of the class or module
 * to test. Caution, it must be unique in the test suite.
**/
svutTestCase::svutTestCase(std::string name)
{
	this->autodtected = false;
	this->caseName = name;
	this->nameLocked = false;
	this->registrationDone = false;
}

/*******************  FUNCTION  *********************/
/**
 * Copy constructor of the class, it was required as we create interal dynamic object in constructor.
 * Here for moment copying svutTestCase objects is not allowed, so we just throw an internal exception
 * here.
 * @param testCase Define the original testCase to copy on current object.
**/
svutTestCase::svutTestCase(const svUnitTest::svutTestCase& /*testCase*/)
{
	assert(false);
	throw new svutExInternalError("Can't made a copy of svutTestCase, it was forbidden.");
}

/*******************  FUNCTION  *********************/
/**
 * Class detroyer, it free the test methode register.
**/
svutTestCase::~svutTestCase(void)
{
	for (svutTestMethodPtrList::iterator it = tests.begin();it!=tests.end();++it)
		delete *it;
}

/*******************  FUNCTION  *********************/
/**
 * Start the test execution. It will run all the tests registerd in the test case in registration
 * order for moment.
 * @param listener Give a listener to capture internal event as progression, tests results to
 * redirect them to the user.
 * @param filter Provide a simple way to filter which test to execute.
**/
void svutTestCase::runTestCase(svutListener * listener,svutTestFilter * filter)
{
	svutStatusInfo res;
	//send notification
	if (listener != NULL)
		listener->onTestCaseStart(*this);

	//done the job
	for (svutTestMethodPtrList::iterator it = tests.begin();it!=tests.end();++it)
	{
		//check if need to execute the methode
		if (filter == NULL || filter->accept(this->getName(),(*it)->getName()))
		{
			//send notification
			if (listener != NULL)
				listener->onTestMethodStart(*this,**it);

			//run the method
			res = this->runTestMethod(*it);

			//send notification
			if (listener != NULL)
				listener->onTestMethodEnd(*this,**it,res);
		}
	}

	//send notification
	if (listener != NULL)
		listener->onTestCaseEnd(*this);
}

/*******************  FUNCTION  *********************/
/**
 * Run the given test method.
 * @param test Define the test method to run.
 * @return Return the final status of the test.
**/
svutStatusInfo svutTestCase::runTestMethod(svutTestMethod * test)
{
	bool needTearDown = false;
	svutStatusInfo res(SVUT_STATUS_SUCCESS,"SUCCESS",test->getLocation());

	//notify start
	try {
		//disable failIsTodo by default
		this->tmpFailIsTodo = false;

		this->setUp();
		needTearDown = true;
		test->call();
		this->tearDown();
		needTearDown = false;
	} catch (const svutExTestStatus & e) {
		if (needTearDown)
			this->tearDown();
		res = e.getInfos();
	} catch (std::exception & e) {
		string tmp = "Unexpected std exception : ";
		res = svutStatusInfo(SVUT_STATUS_UNKNOWN,tmp+e.what(),test->getLocation());
	} catch (...) {
		res = svutStatusInfo(SVUT_STATUS_UNKNOWN,"Unexpected exception.",test->getLocation());
	}

	//status replacement
	if (tmpFailIsTodo)
	{
		if (res.getStatus() == SVUT_STATUS_SUCCESS)
		{
			//Support replacement of SUCCESS by INDEV if failIsTodo() was invoqued.
			svutExNotifyIndev indev("Success replace by temporary INDEV. "+tmpFailMessage,test->getLocation());
			res = indev.getStatus();
		} else if (res.getStatus() == SVUT_STATUS_FAILED) {
			//Support replacement of FAILED by TODO if failIsTodo() was invoqued.
			svutExNotifyTodo todo("Failed replace by temporary TODO. "+tmpFailMessage,res.getLocation());
			res = todo.getInfos();
		} else if (res.getStatus() == SVUT_STATUS_UNKNOWN) {
			//Support replacement of UNKNOWN by TODO if failIsTodo() was invoqued.
			svutExNotifyTodo todo("Unknown replace by temporary TODO. "+tmpFailMessage,res.getLocation());
			res = todo.getInfos();
		}
	}
	
	return res;
}

/*******************  FUNCTION  *********************/
/**
 * After first call of getName(), the test case name was locked and cannot be changed by
 * calling setTestCaseName().
 * @return Return the name of the test case.
**/
std::string svutTestCase::getName(void) const
{
	//we lock the name
	this->nameLocked = true;
	return this->caseName;
}

/*******************  FUNCTION  *********************/
/**
 * Add a test method to the current test case. This method may be called in the class constructor of
 * each test case via the macro SVUT_REG_TEST_FUNCTION().
 * @param test Define the pointer to the method to register to the test case.
**/
void svutTestCase::registerTestMethod(svutTestMethod * test)
{
	this->tests.push_back(test);
}

/*******************  FUNCTION  *********************/
/**
 * If this method is invoqued during a test method, and this method terminate with FAILED status,
 * so the finish status may be replace by TODO status. SUCCESS status will be replaced by INDEV
 * status.
 *
 * This is used to distinguish known error where the tests must be updated from new and real error
 * which my appear when you develop.
 * @param message Define a message to associate to the new status if append.
**/
void svutTestCase::MARK_AS_KNOWN_ERROR(std::string message)
{
	this->tmpFailIsTodo = true;
	this->tmpFailMessage = message;
}

/*******************  FUNCTION  *********************/
/** Tag the current test case as buil by automatic registration. **/
void svutTestCase::setAutodetected(void)
{
	autodtected = true;
}

/*******************  FUNCTION  *********************/
/**
 * @return Return true is the current test case was built by the automatic test case builder.
 * This is used to know if the clean method of svutRunner must free it's memory or not.
**/
bool svutTestCase::isAutodetected(void) const
{
	return autodtected;
}

/*******************  FUNCTION  *********************/
/**
 * Return the list of test methods registers in the test case as a string list.
 * @param prefix Define if the names are prefixed by the test case name or not (using :: as separator).
 * @return Return the list of names in string list format.
**/
svutTestMethodNameList svutTestCase::getTestMethods(bool prefix) const
{
	list<string> res;
	string pf;
	if (prefix) pf = this->caseName + "::";
	for (svutTestMethodPtrList::const_iterator it = tests.begin();it!=tests.end();++it)
		res.push_back(pf + (*it)->getName());
	return res;
}

/*******************  FUNCTION  *********************/
/**
 * Methode which can be used to déclare your tests méthode. It was automatically called
 * just aster the construction of the test.
 * This is also possible to redefine the test case name here by returning a non empty string.
**/
void svutTestCase::testMethodsRegistration(void )
{

}

/*******************  FUNCTION  *********************/
/**
 * Permit to change the test case name if it wasn't in execution. This will lead to crash if
 * change after test execution start point. This is only to be called in construtor of from
 * testMethodsRegistration().
 * @param name Define the name of the test suite.
 * @throw svutExInternalError This exception is thrown when tying to change the test case name
 * after test execution start point.
**/
void svutTestCase::setTestCaseName(string name) throw (svutExInternalError)
{
	if (this->nameLocked)
	{
		throw svutExInternalError("svutTestCase::setTestCaseName() mustn't be called ou of test constructor() and testMethodsRegistration()");
	} else {
		this->caseName = name;
	}
}

/*******************  FUNCTION  *********************/
/**
 * Ensuite that we called testMethodsRegistration one time. If already called, return immediately.
**/
void svutTestCase::callTestMethodsRegistration(void )
{
	if (registrationDone == false)
	{
		testMethodsRegistration();
		registrationDone = true;
	}
}

/*******************  FUNCTION  *********************/
/**
 * @return Return the number of test methods registered in the current test case. It may help to
 * calculate progression.
**/
unsigned int svutTestCase::getNbTests(void) const
{
	return tests.size();
}

/*******************  FUNCTION  *********************/
/*
 * Méthode permettant d'enregistrer le cas de test dans la liste des tests auto-détectés.
 * Elle est utilisée par la macro SVUT_REGISTER_TEST_CASE().
 * Ce mécanisme permet d'éviter de devoir instancier nous mêmes les cas de tests dans la
 * méthode main, pour ajouter un nouveau test il suffit donc juste de le compiler avec l'exécuteur
 * principal et la classe svutRunner se chargera de le trouver.
 * @param builder Définit l'instance d'un constructeur de la classe de test afin de différer
 * la construction au moment de chargement effectif dans svutRunner. Le constructeur lui est
 * instancié avant l'exécution du main mais comme il ne contient rien ce n'est pas un
 * problème. Nos tests peuvent ainsi utiliser des librairies nécessitant une pré-initialisation
 * en début de programme via main.
int registerTestCase(svutTestCaseBuilder & builder)
{
	__SVUT_autoFoundTests__.push_back(&builder);
	return 0;
}*/

}
