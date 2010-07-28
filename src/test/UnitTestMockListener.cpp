/*****************************************************
             PROJECT  : svUnitTest
             VERSION  : 0.0.2
             DATE     : 06/2010
             AUTHOR   : Valat Sébastien
             LICENSE  : CeCILL-C
*****************************************************/

/********************  HEADERS  *********************/
#include "UnitTestMockListener.h"

using namespace svUnitTest;

/********************  METHOD  **********************/
UnitTestMockListener::UnitTestMockListener(void )
{
	mockReset();
}

/********************  METHOD  **********************/
void UnitTestMockListener::mockReset(void )
{
	mockTime = 0;
	mockEvents.case_end = -1;
	mockEvents.case_start = -1;
	mockEvents.global_end = -1;
	mockEvents.global_start = -1;
	mockEvents.meth_end = -1;
	mockEvents.meth_start = -1;
}

/********************  METHOD  **********************/
void UnitTestMockListener::onGlobalStart(void )
{
	mockEvents.global_start = mockTime++;
}

/********************  METHOD  **********************/
void UnitTestMockListener::onGlobalEnd(void )
{
	mockEvents.global_end = mockTime++;
}

/********************  METHOD  **********************/
void UnitTestMockListener::onTestCaseStart(const svUnitTest::svutTestCase& /*testCase*/)
{
	mockEvents.case_start = mockTime++;
}

/********************  METHOD  **********************/
void UnitTestMockListener::onTestCaseEnd(const svUnitTest::svutTestCase& /*testCase*/)
{
	mockEvents.case_end = mockTime++;
}

/********************  METHOD  **********************/
void UnitTestMockListener::onTestMethodStart(const svUnitTest::svutTestMethod& /*method*/)
{
	mockEvents.meth_start = mockTime++;
}

/********************  METHOD  **********************/
void UnitTestMockListener::onTestMethodEnd(const svUnitTest::svutTestMethod& /*method*/, svUnitTest::svutStatusInfo /*status*/)
{
	mockEvents.meth_end = mockTime++;
}

