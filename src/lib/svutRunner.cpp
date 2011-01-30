/*****************************************************
             PROJECT  : svUnitTest
             VERSION  : 0.1.0
             DATE     : 01/2011
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
#include "svutResultFormatterXml.h"
#include "svutAutoRegister.h"

/**********************  USING  *********************/
using namespace std;

/********************  NAMESPACE  *******************/
namespace svUnitTest
{

/*******************  FUNCTION  *********************/
/**
 * Class constructor to initialize the output formatting classe.
 * @param mode Define the prefered output mode.
 * @param out Define the output stream to use.
**/
svutRunner::svutRunner(svutOutputMode mode,std::ostream & out)
{
	this->config = NULL;
	this->init(mode,out);
}

/*******************  FUNCTION  *********************/
/**
 * Class constructor used to init the output formatting object and activation or desactivation of
 * rendering options.
 * @param config Define the confifucation object to use to read the parameters of the program.
**/
svutRunner::svutRunner(svutRunnerConfig & config)
{
	this->init(config.getMode(),config.getOutput());
	this->config = &config;
	this->setDisplay(config.hasDisplaySuccess(),config.hasDisplayDetails());
	this->setFilter(&config.getFilter());
}

/*******************  FUNCTION  *********************/
/**
 * Class constructor used to directly define our own formatter.
 * @param formatter Reference the custom formatter to insert in the runner.
**/
svutRunner::svutRunner(svutResultFormatter& formatter)
{
	this->config = NULL;
	this->init(formatter);
}

/*******************  FUNCTION  *********************/
/**
 * Class constructor used to directly define our own event listener and outputter.
 * @param listener Reference the custom listener to insert in the runner.
**/
svutRunner::svutRunner(svutListener & listener)
{
	this->config = NULL;
	this->init(listener);
}

/*******************  FUNCTION  *********************/
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

/*******************  FUNCTION  *********************/
/**
 * Run the test suites. Run the test suites. The default action is SVUT_ACTION_RUN_TESTS or the one
 * defined into svutRunnerConfig if available.
 * @return Return the final status of the test. True if all tests are SUCCESS, false otherwise.
**/
bool svutRunner::run(void)
{
	if (config == NULL)
		return this->run(SVUT_ACTION_RUN_TESTS);
	else
		return this->run(config->getAction());
}

/*******************  FUNCTION  *********************/
/**
 * Run the test suites wihle using a specific action (default is SVUT_ACTION_RUN_TESTS or the one
 * defined into svutRunnerConfig if defined).
 * @param action Define the related action to execute :
 *     - SVUT_ACTION_RUN_TESTS to run the tests.
 *     - SVUT_ACTION_LIST_TESTS to list the available tests.
 * @return Return the final status of the test. True if all tests are SUCCESS, false otherwise.
**/
bool svutRunner::run(svutRunnerAction action)
{
	switch(action)
	{
		case SVUT_ACTION_RUN_TESTS:
			return run_tests();
		case SVUT_ACTION_LIST_TESTS:
			return run_list_tests();
		default:
			cerr << "INTERNAL ERROR : bad action : " << action << endl;
			return false;
	}
}

/*******************  FUNCTION  *********************/
/**
 * Execute all the tests suites registerd  into the runner.
 * @return Return the final status of the test. True if all tests are SUCCESS, false otherwise.
**/
bool svutRunner::run_tests(void)
{
	if (this->formatter != NULL)
		formatter->setDisplayFullName(hasMultipleTestCase());
	this->listener.onGlobalStart();
	for(list<svutTestCase *>::iterator it=suites.begin();it!=suites.end();it++)
	{
		if (testFilter == NULL || testFilter->accept((*it)->getName()))
			(*it)->runTestCase(&listener,this->testFilter);
	}
	this->listener.onGlobalEnd();
	return (summary->getSummary().getStatus() == SVUT_STATUS_SUCCESS);
}

/*******************  FUNCTION  *********************/
/**
 * Display the names of all the test methodes available in the programe.
 * This is mostly implemented for the compatibility of QT test suite.
 * @return Return true final state.
**/
bool svutRunner::run_list_tests(void)
{
	bool fullName = hasMultipleTestCase();
	std::ostream * out = NULL;
	if (config == NULL)
		out = & cout;
	else
		out = & config->getOutput();
	//search all
	for(list<svutTestCase *>::iterator it=suites.begin();it!=suites.end();it++)
	{
		list<string> tmp = (*it)->getTestMethods(false);
		for (list<string>::iterator it2=tmp.begin();it2!=tmp.end();++it2)
		{
			if (testFilter == NULL || testFilter->accept((*it)->getName(),*it2))
			{
				if (fullName)
					*out << (*it)->getName().c_str() << "::" << it2->c_str() << "()\n";
				else
					*out << it2->c_str() << "()\n";
			}
		}
	}
	//end
	return true;
}

/*******************  FUNCTION  *********************/
/**
 * Initialisation method of the class members.
**/
void svutRunner::init(void)
{
	this->ownTheFormatter = false;
	this->formatter = NULL;
	this->summary = NULL;
	this->testFilter = NULL;
}

/*******************  FUNCTION  *********************/
/**
 * Permit to change the verbosity of the output formatter. It's available only for the internal
 * formatter, if you provide your own one, this methode has no effect.
 * @param success Define if the success must be displayed of not
 * @param details Define if the failure details must be displayed or not.
**/
void svutRunner::setDisplay(bool success,bool details)
{
 	if (formatter != NULL)
	{
		formatter->setDisplayDetails(details);
		formatter->setDisplaySuccess(success);
	}
}

/*******************  FUNCTION  *********************/
/**
 * Import test cases registred with the macro SVUT_REGISTER_TEST_CASE().
**/
void svutRunner::loadAutoDetected(void)
{
	for(set<svutTestCaseBuilder *>::const_iterator it=getRegistredTestCase().begin();it!=getRegistredTestCase().end();it++)
	{
		svutTestCase * tmp = (*it)->build();
		if ( hasTestNamed(tmp->getName()))
		{
			delete tmp;
		} else {
			tmp->setAutodetected();
			this->suites.push_back(tmp);
		}
	}
}

/*******************  FUNCTION  *********************/
/**
 * Check if the test suite already contain a test case of the given name.
 * @param name Define the test case name to search.
 * @return True if such a test case exist, false otherwise.
**/
bool svutRunner::hasTestNamed(string name)
{
	for( list<svutTestCase *>::iterator it=suites.begin(); it != suites.end() ; ++it)
	{
		if ((*it)->getName() == name)
			return true;
	}
	return false;
}

/*******************  FUNCTION  *********************/
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

/*******************  FUNCTION  *********************/
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
		if (testFilter == NULL || testFilter->accept((*it)->getName()))
			cnt++;
	}
	return cnt > 1;
}

/*******************  FUNCTION  *********************/
/**
 * Manually register a test case into the runner.
 * @param tcase Define the test case to register.
**/
void  svutRunner::registerTestCase(svutTestCase & tcase)
{
	this->suites.push_back(&tcase);
}

/*******************  FUNCTION  *********************/
/**
 * Methode used to init the class members.
 * @param mode Define the output mode to use.
 * @param out Define the output stream to use.
**/
void svutRunner::init(svutOutputMode mode,std::ostream & out)
{
	this->init();
	this->ownTheFormatter = true;
	switch(mode)
	{
		case SVUT_OUT_STD_COLOR:
			this->formatter = new svutResultFormatterStdColored(out);
			break;
		case SVUT_OUT_STD_BW:
			this->formatter = new svutResultFormatterStdBW(out);
			break;
		case SVUT_OUT_XML:
			this->formatter = new svutResultFormatterXml(out);
			break;
		/*case SVUT_OUT_QT_XML:
			this->formater = new svutResultFormaterQtXml(*out);
			break;*/
		default:
			cerr << "Unknown type of formater : " << mode << endl;
			exit(1);
	}
	this->summary = new svutListenerDirectOutputter(*(this->formatter));
	this->listener.addListener(this->summary);
}

/*******************  FUNCTION  *********************/
/**
 * Methode used to init the class members.
 * @param formatter Define the formatter to use.
**/
void svutRunner::init(svutResultFormatter& formatter)
{
	this->init();
	this->ownTheFormatter = false;
	this->formatter = &formatter;
	this->summary = new svutListenerDirectOutputter(formatter);
	this->listener.addListener(this->summary);
}

/*******************  FUNCTION  *********************/
/**
 * Define a test case filter to filter which test case and method to execute.
 * @param filter Define the filter to use. Set NULL a not filter and execute all defined tests.
**/
void svutRunner::setFilter(svutTestFilter* filter)
{
	this->testFilter = filter;
}

/*******************  FUNCTION  *********************/
/**
 * Methode used to init the class members.
 * @param listener Define the listener mode to use.
**/
void svutRunner::init(svutListener& listener)
{
	this->init();
	this->ownTheFormatter = false;
	this->summary = new svutListenerSummary();
	this->listener.addListener(&listener);
	this->listener.addListener(this->summary);
}

}
