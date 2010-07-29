/*****************************************************
             PROJECT  : svUnitTest
             VERSION  : 0.0.2
             DATE     : 07/2010
             AUTHOR   : Valat Sébastien
             LICENSE  : CeCILL-C
*****************************************************/

#ifndef SVUT_LISTENER_HEADER
#define SVUT_LISTENER_HEADER

/********************  HEADERS  *********************/
#include "svutTestCase.h"

namespace svUnitTest
{

/********************* CLASS ************************/
class svutTestCase;

/********************* CLASS ************************/
/**
 * This abstract class is used to factorized event definition of test event. It was used to aggregate
 * the results, generate global stats and display progression. All thoses steps can be based on this
 * definition, so it may be easier to extend and change the global comportement.
 * @brief Abstract definition of test events.
 * @author Sébastien Valat
 * @version 0.0.2
**/
class svutListener
{
	public:
		/** Class destructor. It was just define fot inheritance supporting. **/
		virtual ~svutListener(void){};
		/** This method is called when starting to run the tests. **/
		virtual void onGlobalStart(void) = 0;
		/**
		 * This method is called when starting to run a test case. Caution, in the future it may
		 * be multiples tests running at same time, and the running order is not determined, so
		 * didn't supposed that property is valid even if it was the case for moment.
		 * @param testCase Define the current test case which is starting.
		**/
		virtual void onTestCaseStart(const svutTestCase & testCase) = 0;
		/**
		 * This method is called when a test case was finished. in the future it may
		 * be multiples tests running at same time, and the running order is not determined, so
		 * didn't supposed that property is valid even if it was the case for moment.
		 * @param testCase Define the current test case which is ended.
		 **/
		virtual void onTestCaseEnd(const svutTestCase & testCase) = 0;
		/**
		 * This method si called when a method start. Same as for test case, didn't suppose any order
		 * or sequential properties here.
		 * @param method Define the methode which is starting.
		**/
		virtual void onTestMethodStart(const svutTestMethod & method) = 0;
		/**
		 * This method si called when a method end. Same as for test case, didn't suppose any order
		 * or sequential properties here.
		 * @param method Define the methode which is ended.
		 * @param status Define the final status of the test method.
		**/
		virtual void onTestMethodEnd(const svutTestMethod & method,svutStatusInfo status) = 0;
		/**
		 * Method called at the end of all tests.
		**/
		virtual void onGlobalEnd(void) = 0;
};

}

#endif
