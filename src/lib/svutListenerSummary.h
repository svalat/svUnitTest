/*****************************************************
             PROJECT  : svUnitTest
             VERSION  : 0.3.0-dev
             DATE     : 03/2011
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
		virtual void onListingStart(void );
		virtual void onListMethod(const svUnitTest::svutTestCase& testCase, const svUnitTest::svutTestMethod& method);
		virtual void onListingEnd(void );
	protected:
		/** Store the global summary to fill. **/
		svutResultSummary summary;
};

}

#endif //SVUT_LISTENER_SUMMARY_HEADER
