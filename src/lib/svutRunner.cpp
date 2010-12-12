/*****************************************************
             PROJECT  : svUnitTest
             VERSION  : 0.0.2
             DATE     : 12/2010
             AUTHOR   : Valat Sébastien
             LICENSE  : CeCILL-C
*****************************************************/

/********************  HEADERS  *********************/
#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include <iostream>
#include <cstdlib>
#include <list>
#include <string>
#include <cstdio>
#include "svutRunner.h"
#include "svutListenerDirectOutputter.h"
#include "svutResultFormatterStdBW.h"
#include "svutResultFormatterStdColored.h"
//#include "svutAutoRegister.h"

using namespace std;
namespace svUnitTest
{

/********************  METHODE  *********************/
/**
 * Class constructor to initialize the output formatting classe.
 * @param mode Define the prefered output mode.
**/
svutRunner::svutRunner(svutOutputMode mode)
{
	this->config = NULL;
	this->init(mode);
}

/********************  METHODE  *********************/
/**
 * Class constructor used to init the output formatting object and activation or desactivation of
 * rendering options.
 * @param config Define the confifucation object to use to read the parameters of the program.
**/
svutRunner::svutRunner(svutRunnerConfig & config)
{
	this->config = &config;
	this->init(config.getMode());
	this->setDisplay(config.hasDisplaySuccess(),config.hasDisplayDetails());
	this->config = &config;
}

/********************  METHODE  *********************/
/**
 * Class constructor used to directly define our own formatter.
 * @param listener Reference the custom formatter to insert in the runner.
**/
svutRunner::svutRunner(svutResultFormatter& formatter)
{
	this->config = NULL;
	this->init(formatter);
}

/********************  METHODE  *********************/
/**
 * Class constructor used to directly define our own event listener and outputter.
 * @param listener Reference the custom listener to insert in the runner.
**/
svutRunner::svutRunner(svutListener & listener)
{
	this->config = NULL;
	this->init(listener);
}

/********************  METHODE  *********************/
/**
 * Class destructor. He must free the listener if it use his own one.
**/
svutRunner::~svutRunner(void)
{
	if (this->summary!=NULL)
		delete this->summary;
	if (this->ownTheFormatter && this->formatter!=NULL)
		delete this->formatter;
}

/********************  METHODE  *********************/
/**
 * Run the test suites.
 * @return Return the final status of the test. True if all tests are SUCCESS, false otherwise.
**/
bool svutRunner::run(void)
{
	if (config == NULL || config->getAction() == SVUT_ACTION_RUN_TESTS)
		return run_tests();
	else
		return run_list_tests();
}

/********************  METHODE  *********************/
/**
 * Execute all the tests suites registerd  into the runner.
 * @return Return the final status of the test. True if all tests are SUCCESS, false otherwise.
**/
bool svutRunner::run_tests(void)
{
	//TODO how to support that now ?
	//formater->setDisplayFullName(hasMultipleTestCase());
	this->listener.onGlobalStart();
	for(list<svutTestCase *>::iterator it=suites.begin();it!=suites.end();it++)
	{
		//TODO re-insert it when filters will be available
		//if (config->getFilter().accept( (*it)->getName()))
		(*it)->runTestCase(&listener);
	}
	this->listener.onGlobalEnd();
	return (summary->getSummary().getStatus() == SVUT_STATUS_SUCCESS);
}

/********************  METHODE  *********************/
/**
 * Display the names of all the test methodes available in the programe.
 * This is mostly implemented for the compatibility of QT test suite.
 * @return Return true final state.
**/
bool svutRunner::run_list_tests(void)
{
	bool fullName = hasMultipleTestCase();
	//search all
	for(list<svutTestCase *>::iterator it=suites.begin();it!=suites.end();it++)
	{
		list<string> tmp = (*it)->getTestMethods(false);
		for (list<string>::iterator it2=tmp.begin();it2!=tmp.end();++it2)
		{
			//if (config->getFilter().accept((*it)->getName(),*it2))
			if (true)
			{
				if (fullName)
					printf("%s::%s()\n",(*it)->getName().c_str(),it2->c_str());
				else
					printf("%s()\n",it2->c_str());
			}
		}
	}
	//end
	return true;
}

/********************  METHODE  *********************/
/**
 * Initialisation method of the class members.
**/
void svutRunner::init(void)
{
	this->ownTheFormatter = false;
	this->formatter = NULL;
	this->summary = NULL;
}

/********************  METHODE  *********************/
/**
 * Permet à tout moment de change la verbosité des formatteur utilisés.
 * @param success Définit s'il faut ou no nafficher les succès, par défaut ils sont masqués
 * sauf en XML.
 * @param details Définit s'il faut afficher les détails des erreurs ou juste afficher le status.
**/
void svutRunner::setDisplay(bool success,bool details)
{
// 	if (formatter!=NULL)
// 	{
// 		formatter->setDisplayDetails(details);
// 		formatter->setDisplaySuccess(success);
// 	} else {
// 	}
}

/********************  METHODE  *********************/
/**
 * Import test cases registred with the macro SVUT_REGISTER_TEST_CASE().
**/
void svutRunner::loadAutoDetected(void)
{
// 	for(list<svutTestCaseBuilder *>::iterator it=__SVUT_autoFoundTests__.begin();it!=__SVUT_autoFoundTests__.end();it++)
// 	{
// 		svutTestCase * tmp = (*it)->build();
// 		tmp->setAutodetected();
// 		this->suites.push_back(tmp);
// 	}
}

/********************  METHODE  *********************/
/**
 * Free the memory allocated by the test cases registred via the macro SVUT_REGISTER_TEST_CASE() and
 * fetched by loadAutoDetected().
**/
void svutRunner::unloadAutoDetected(void)
{
	list<svutTestCase *>::iterator it=suites.begin();
	while (it!=suites.end())
	{
		if ((*it)->isAutodetected())
		{
			delete *it;
			suites.erase(it);
			--it;
		}
		++it;
	}
}

/********************  METHODE  *********************/
/**
 * Test if their is multiple test case accepted by the filter. This is used to adapt the output
 * if need. For exemple disable the display of testCase name if their is only one.
 * @return True s'il y a plus d'un cas de test.
**/
bool svutRunner::hasMultipleTestCase(void)
{
	int cnt = 0;
	for(list<svutTestCase *>::iterator it=suites.begin();it!=suites.end();it++)
	{
		list<string> tmp = (*it)->getTestMethods(false);
		//if (config->getFilter().accept((*it)->getName()))
		cnt++;
	}
	return cnt > 1;
}

/********************  METHODE  *********************/
/**
 * Manually register a test case into the runner.
 * @param tcase Define the test case to register.
**/
void  svutRunner::registerTestCase(svutTestCase & tcase)
{
	this->suites.push_back(&tcase);
}

/********************  METHODE  *********************/
/**
 * Methode used to init the class members.
 * @param mode Define the output mode to use.
**/
void svutRunner::init(svutOutputMode mode)
{
	this->init();
	this->ownTheFormatter = true;
	ostream * out = &cout;
	if (config != NULL)
		out = &config->getOutput();
	switch(mode)
	{
		case SVUT_OUT_STD_COLOR:
			this->formatter = new svutResultFormatterStdColored(*out);
			break;
		case SVUT_OUT_STD_BW:
			this->formatter = new svutResultFormatterStdBW(*out);
			break;
		/*case SVUT_OUT_XML:
			this->formater = new svutResultFormaterXml(*out);
			break;
		case SVUT_OUT_QT_XML:
			this->formater = new svutResultFormaterQtXml(*out);
			break;*/
		default:
			cerr << "Unknown type of formater : " << mode << endl;
			exit(1);
	}
	this->summary = new svutListenerDirectOutputter(*(this->formatter));
}

/********************  METHODE  *********************/
/**
 * Methode used to init the class members.
 * @param mode Define the formatter to use.
**/
void svutRunner::init(svutResultFormatter& formatter)
{
	this->init();
	this->ownTheFormatter = false;
	this->formatter = &formatter;
	this->summary = new svutListenerDirectOutputter(formatter);
}

/********************  METHODE  *********************/
/**
 * Methode used to init the class members.
 * @param mode Define the listener mode to use.
**/
void svutRunner::init(svutListener& listener)
{
	this->init();
	this->ownTheFormatter = false;
	this->summary = new svutListenerSummary();
}

};
