/*****************************************************
             PROJECT  : svUnitTest
             VERSION  : 0.5.0-dev
             DATE     : 11/2012
             AUTHOR   : Valat Sébastien
             LICENSE  : CeCILL-C 2.1
*****************************************************/

/********************  HEADERS  *********************/
#include "svutFlatTestCase.h"
#include "svutAutoRegister.h"
#include <cassert>
#include <vector>
#include <cstdlib>

/**********************  USING  *********************/
using namespace std;

/********************  NAMESPACE  *******************/
namespace svUnitTest
{

/********************  GLOBALS  *********************/
/**
 * Glocal registry used to remember all function defined via SVUT_DECLARE_FLAT_TEST macro
 * Only accessible localy. It must be used only by svutFlatTestCase class and registerFlatTestCaseMethod.
**/
static std::vector<svutFlatRegistryEntry> * globalFlatTestRegistry = NULL;
/** Store the temp builder to delete them at exit. They will be allocated by getRegistredFlatTestCase(). **/
static std::vector<svutFlatTestCaseBuilder*> * globalFlatTestBuilderRegistry = NULL;
/**
 * Global pointer to get current svutTestCase in execution. This is used by getCurrentSvutTestCase() which
 * serve in SVUT_PRINTF/SVUT_COUT/SVUT_*CONTEXT functions to get the current svutTestCase.
 * To support parallel execution of test cases, we must transform this into TLS variable (not done up to now).
**/
static svutTestCase * globalCurrentFlatTestCase = NULL;

/*******************  FUNCTION  *********************/
void finiGlobalFlatTestRegistry(void)
{
	if (globalFlatTestRegistry != NULL)
		delete globalFlatTestRegistry;
	if (globalFlatTestBuilderRegistry != NULL)
	{
		for (std::vector<svutFlatTestCaseBuilder*>::iterator it = globalFlatTestBuilderRegistry->begin() ; it != globalFlatTestBuilderRegistry->end() ; ++it)
			delete *it;
		delete globalFlatTestBuilderRegistry;
	}
}

/*******************  FUNCTION  *********************/
void initGlobalFlatTestRegistry(void)
{
	if (globalFlatTestRegistry == NULL)
	{
		globalFlatTestRegistry = new std::vector<svutFlatRegistryEntry>;
		globalFlatTestBuilderRegistry = new std::vector<svutFlatTestCaseBuilder*>;
		atexit(finiGlobalFlatTestRegistry);
	}
}

/*******************  FUNCTION  *********************/
/**
 * Function used to register a new methe by link time trick.
 * @param testCaseName Define the name of test case to create.
 * @param functionName Define the name of the function to use as test case.
 * @param methodPtr Define the pointer of C method to call.
 * @param location Define the location of the method.
 * @return Return always true, this is the trick to call the method at init time without depending
 * on compilers/linker keywords, see SVUT_REGISTER_FLAT_TEST macro.
**/
bool registerFlatTestCaseMethod(const char* testCaseName, const char* functionName, svUnitTest::svutTestMethodPtr methodPtr,const svUnitTest::svutCodeLocation & location)
{
	if (globalFlatTestRegistry == NULL)
		initGlobalFlatTestRegistry();
	svutFlatRegistryEntry entry;
	entry.testCaseName = testCaseName;
	entry.testName = functionName;
	entry.methodPtr = methodPtr;
	entry.fixtureTest = NULL;
	entry.location = location;
	globalFlatTestRegistry->push_back(entry);
	return true;
}

/*******************  FUNCTION  *********************/
/**
 * Function used to register a new method by link time trick.
 * @param testCaseName Define the name of test case to create.
 * @param functionName Define the name of the function to use as test case.
 * @param fixture Define the pointer to fixture object to find seutp/run/teardown methods.
 * @param location Define the location of the method.
 * @return Return always true, this is the trick to call the method at init time without depending
 * on compilers/linker keywords, see SVUT_REGISTER_FLAT_TEST_F macro.
**/
bool registerFlatTestCaseMethod(const char* testCaseName, const char* functionName, svutFlatFixture * fixtureTest, const svutCodeLocation& location)
{
	if (globalFlatTestRegistry == NULL)
		initGlobalFlatTestRegistry();
	svutFlatRegistryEntry entry;
	entry.testCaseName = testCaseName;
	entry.testName = functionName;
	entry.methodPtr = NULL;
	entry.fixtureTest = fixtureTest;
	entry.location = location;
	globalFlatTestRegistry->push_back(entry);
	return true;
}

/*******************  FUNCTION  *********************/
/**
 * Constructor of flat test case.
 * @param name Simply define the name of the flat test case. This name will be used by
 * testMethodsRegistration() to find the related tests.
**/
svutFlatTestCase::svutFlatTestCase(string name)
	: svutTestCase(name)
{
	setUpPtr = NULL;
	tearDownPtr = NULL;
}

/*******************  FUNCTION  *********************/
/**
 * Register a new test method to the current flat test case.
 * @param name Define the name of the test.
 * @param methodPtr Define the test function to use.
 * @param location Define the location of the function in source code.
**/
void svutFlatTestCase::registerFlatTestMethod(string name, svutTestMethodPtr methodPtr, const svUnitTest::svutCodeLocation& location)
{
	if (name == "__SVUT_SPECIAL_TEST_CASE_SETUP__")
	{
		this->setUpPtr = methodPtr;
	} else if (name == "__SVUT_SPECIAL_TEST_CASE_TEAR_DOWN__") {
		this->tearDownPtr = methodPtr;
	} else {
		svutObjectMethod * meth = new svutFlatObjectMethod(methodPtr);
		svutObjectMethod * setupMeth = new svutObjectMethodGeneric<svutFlatTestCase>(this,&svutFlatTestCase::setUp);
		svutObjectMethod * tearDown = new svutObjectMethodGeneric<svutFlatTestCase>(this,&svutFlatTestCase::tearDown);
		svutTestMethod * test = new svutTestMethod(name,location,meth,setupMeth,tearDown);
		this->registerTestMethod(test);
	}
}

/*******************  FUNCTION  *********************/
/**
 * Register a new test method to the current flat test case.
 * @param name Define the name of the test.
 * @param fixtureTest Define the fixture test to register.
 * @param location Define the location of the function in source code.
**/
void svutFlatTestCase::registerFlatTestMethod(string name, svutFlatFixture* fixtureTest, const svutCodeLocation& location)
{
	svutObjectMethod * meth = new svutObjectMethodGeneric<svutFlatFixture>(fixtureTest,&svutFlatFixture::run);
	svutObjectMethod * setupMeth = new svutObjectMethodGeneric<svutFlatFixture>(fixtureTest,&svutFlatFixture::setUp);
	svutObjectMethod * tearDown = new svutObjectMethodGeneric<svutFlatFixture>(fixtureTest,&svutFlatFixture::tearDown);
	svutTestMethod * test = new svutTestMethod(name,location,meth,setupMeth,tearDown);
	this->registerTestMethod(test);
}

/*******************  FUNCTION  *********************/
/**
 * Search all corresponding tests by checking testCaseName and create entries in current test case.
**/
void svutFlatTestCase::testMethodsRegistration(void )
{
	if (globalFlatTestRegistry != NULL)
	for (std::vector<svutFlatRegistryEntry>::const_iterator it = globalFlatTestRegistry->begin() ; it != globalFlatTestRegistry->end() ; ++it)
	{
		if (it->testCaseName == getName())
		{
			assert(it->methodPtr != NULL || it->fixtureTest != NULL);

			if (it->methodPtr != NULL)
				registerFlatTestMethod(it->testName,it->methodPtr,it->location);
			else if (it->fixtureTest != NULL)
				registerFlatTestMethod(it->testName,it->fixtureTest,it->location);
		}
	}
}

/*******************  FUNCTION  *********************/
/**
 * Call related tearDown method.
**/
void svutFlatTestCase::tearDown(void )
{
	//unmark current
	//assert(globalCurrentFlatTestCase == this);
	globalCurrentFlatTestCase = NULL;

	//call registred C function
	if (tearDownPtr != NULL)
		tearDownPtr();
}

/*******************  FUNCTION  *********************/
/**
 * Call related setup method.
**/
void svutFlatTestCase::setUp(void )
{
	//mark current
	//assert(globalCurrentFlatTestCase == NULL);
	globalCurrentFlatTestCase = this;

	//call registred C function
	if (setUpPtr != NULL)
		setUpPtr();
}

/*******************  FUNCTION  *********************/
/**
 * Return the list of test case builder corresponding to all flat test case registred by
 * SVUT_REGISTER_FLAT_TEST macro.
**/
const std::set< svutTestCaseBuilder* > getRegistredFlatTestCases(void )
{
	std::set< svutTestCaseBuilder* > res;
	std::map<std::string,bool> filter;

	if (globalFlatTestRegistry != NULL)
		for (std::vector<svutFlatRegistryEntry>::const_iterator it = globalFlatTestRegistry->begin() ; it != globalFlatTestRegistry->end() ; ++it)
		{
			if (filter.find(it->testCaseName) == filter.end())
			{
				filter[it->testCaseName] = true;
				svutFlatTestCaseBuilder * tmp = new svutFlatTestCaseBuilder(it->testCaseName);
				res.insert(tmp);
				globalFlatTestBuilderRegistry->push_back(tmp);
			}
		}

	return res;
}

/*******************  FUNCTION  *********************/
svutFlatTestCaseBuilder::svutFlatTestCaseBuilder(string testCaseName)
{
	this->testCaseName = testCaseName;
}

/*******************  FUNCTION  *********************/
svutTestCase* svutFlatTestCaseBuilder::build(void ) const
{
	return new svutFlatTestCase(testCaseName);
}

/*******************  FUNCTION  *********************/
svutTestCase& getCurrentSvutTestCase(void )
{
	assert(globalCurrentFlatTestCase != NULL);
	return *globalCurrentFlatTestCase;
}

}
