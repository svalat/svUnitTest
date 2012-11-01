/*****************************************************
             PROJECT  : svUnitTest
             VERSION  : 0.4.0
             DATE     : 11/2012
             AUTHOR   : Valat Sébastien
             LICENSE  : CeCILL-C
*****************************************************/

/********************  HEADERS  *********************/
#include <svutTestMethod.h>
#include "UnitTestMockListener.h"

/**********************  USING  *********************/
using namespace svUnitTest;

/*******************  FUNCTION  *********************/
UnitTestMockListener::UnitTestMockListener(void )
{
	mockReset();
}

/*******************  FUNCTION  *********************/
void UnitTestMockListener::mockReset(void )
{
	mockTime = 0;
	mockEvents.case_end = -1;
	mockEvents.case_start = -1;
	mockEvents.global_end = -1;
	mockEvents.global_start = -1;
	mockEvents.meth_end = -1;
	mockEvents.meth_start = -1;
	mockEvents.list_method = -1;
	mockEvents.listing_end = -1;
	mockEvents.listing_start = -1;
}

/*******************  FUNCTION  *********************/
void UnitTestMockListener::onGlobalStart(void )
{
	mockEvents.global_start = mockTime++;
}

/*******************  FUNCTION  *********************/
void UnitTestMockListener::onGlobalEnd(void )
{
	mockEvents.global_end = mockTime++;
}

/*******************  FUNCTION  *********************/
void UnitTestMockListener::onTestCaseStart(const svUnitTest::svutTestCase& /*testCase*/)
{
	mockEvents.case_start = mockTime++;
}

/*******************  FUNCTION  *********************/
void UnitTestMockListener::onTestCaseEnd(const svUnitTest::svutTestCase& /*testCase*/)
{
	mockEvents.case_end = mockTime++;
}

/*******************  FUNCTION  *********************/
void UnitTestMockListener::onTestMethodStart(const svUnitTest::svutTestCase & /*testCase*/,const svUnitTest::svutTestMethod& /*method*/)
{
	mockEvents.meth_start = mockTime++;
}

/*******************  FUNCTION  *********************/
void UnitTestMockListener::onTestMethodEnd(const svUnitTest::svutTestCase & /*testCase*/,const svUnitTest::svutTestMethod& method, svUnitTest::svutStatusInfo status)
{
	mockEvents.meth_end = mockTime++;
	finalResults[method.getName()] = status;
}

/*******************  FUNCTION  *********************/
void UnitTestMockListener::onListingStart(void )
{
	mockEvents.listing_start = mockTime++;
}

/*******************  FUNCTION  *********************/
void UnitTestMockListener::onListingEnd(void )
{
	mockEvents.listing_end = mockTime++;
}

/*******************  FUNCTION  *********************/
void UnitTestMockListener::onListMethod(const svUnitTest::svutTestCase& testCase, const svUnitTest::svutTestMethod& method)
{
	mockEvents.list_method = mockTime++;
}




