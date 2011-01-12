/*****************************************************
             PROJECT  : svUnitTest
             VERSION  : 0.1.0
             DATE     : 01/2011
             AUTHOR   : Valat Sébastien
             LICENSE  : CeCILL-C
*****************************************************/

#ifndef UNIT_TEST_MOCK_LISTENER_HEADER
#define UNIT_TEST_MOCK_LISTENER_HEADER

/********************  HEADERS  *********************/
#include <svutTestMethod.h>
#include <svutStatusInfo.h>
#include <svutListener.h>
#include <map>

/********************* STRUCT ***********************/
struct UnitTestMockListener_Events
{
	int global_start;
	int global_end;
	int case_start;
	int case_end;
	int meth_start;
	int meth_end;
};

/********************* CLASS ************************/
class UnitTestMockListener : public svUnitTest::svutListener
{
	public:
		UnitTestMockListener(void);
		virtual void onGlobalStart(void);
		virtual void onTestCaseStart(const svUnitTest::svutTestCase & testCase);
		virtual void onTestCaseEnd(const svUnitTest::svutTestCase & testCase);
		virtual void onTestMethodStart(const svUnitTest::svutTestCase & testCase,const svUnitTest::svutTestMethod & method);
		virtual void onTestMethodEnd(const svUnitTest::svutTestCase & testCase,const svUnitTest::svutTestMethod & method,svUnitTest::svutStatusInfo status);
		virtual void onGlobalEnd(void);
		void mockReset(void);
	
		int mockTime;
		UnitTestMockListener_Events mockEvents;
		std::map<std::string,svUnitTest::svutStatusInfo> finalResults;
};

#endif
