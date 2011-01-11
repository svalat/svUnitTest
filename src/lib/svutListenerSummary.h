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
#include "svutResultSummary.h"

/********************  NAMESPACE  *******************/
namespace svUnitTest
{

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
