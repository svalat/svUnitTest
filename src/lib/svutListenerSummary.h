/*****************************************************
             PROJECT  : svUnitTest
             VERSION  : 0.0.2
             DATE     : 07/2010
             AUTHOR   : Valat Sébastien
             LICENSE  : CeCILL-C
*****************************************************/

#ifndef SVUT_LISTENER_SUMMARY_HEADER
#define SVUT_LISTENER_SUMMARY_HEADER

/********************  HEADERS  *********************/
#include "svutListener.h"

namespace svUnitTest
{

/*********************  TYPES  **********************/
/**
 * Structure used to aggregate global summary of tests.
 * @brief Structure used to aggregate global summary of tests.
 * @author Valat Sébastien
 * @version 0.0.2
**/
struct svutResultSummary
{
	/** Count the number of success occured during the tests.**/
	unsigned int success;
	/** Count the number of todo occured during the tests.**/
	unsigned int todo;
	/** Count the number of failed occured during the tests.**/
	unsigned int failed;
	/** Count the number of unknown occured during the tests.**/
	unsigned int unknown;
	/** Count the number of skiped occured during the tests.**/
	unsigned int skiped;
	/** Count the number of indev occured during the tests.**/
	unsigned int indev;
};

/********************* CLASS ************************/
/**
 * Listener implamentation used to aggregate test results as a global summary which only count
 * the number of each status reached during the tests.
 * @brief Listener implementation do build a global summary of tests.
 * @author Valat Sébastien
 * @version 0.0.2
**/
class svutListenerSummary : public svutListener
{
	public:
		svutListenerSummary(void);
		svutResultSummary getSummary(void) const;

		virtual void onGlobalStart(void);
		virtual void onTestCaseStart(const svUnitTest::svutTestCase & testCase);
		virtual void onTestCaseEnd(const svUnitTest::svutTestCase & testCase);
		virtual void onTestMethodStart(const svUnitTest::svutTestCase & testCase,const svUnitTest::svutTestMethod & method);
		virtual void onTestMethodEnd(const svUnitTest::svutTestCase & testCase,const svUnitTest::svutTestMethod & method,svUnitTest::svutStatusInfo status);
		virtual void onGlobalEnd(void);
	protected:
		/** Store the global summary to fill. **/
		svutResultSummary summary;
};

}

#endif //SVUT_LISTENER_SUMMARY_HEADER
