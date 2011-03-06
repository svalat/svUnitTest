/*****************************************************
             PROJECT  : svUnitTest
             VERSION  : 0.3.0-dev
             DATE     : 03/2011
             AUTHOR   : Valat Sébastien
             LICENSE  : CeCILL-C
*****************************************************/

/********************  HEADERS  *********************/
#include "UnitTestExtra.h"
#include "UnitTestMockListener.h"
#include "UnitTestMockTestCase.h"
#include <iostream>
#include <cppunit/TestCase.h>
#include <cppunit/extensions/TestFactoryRegistry.h>
#include <cppunit/extensions/HelperMacros.h>
#include <svutTestCase.h>

/**********************  USING  *********************/
using namespace svUnitTest;
using namespace CPPUNIT_NS;

/*********************  CLASS  **********************/
class UnitTestsvutListener : public TestCase
{
	CPPUNIT_TEST_SUITE(UnitTestsvutListener);
	CPPUNIT_TEST(testOnGlobalStart);
	CPPUNIT_TEST(testOnGlobalEnd);
	CPPUNIT_TEST(testOnTestCaseStart);
	CPPUNIT_TEST(testOnTestCaseEnd);
	CPPUNIT_TEST(testOnTestMethodStart);
	CPPUNIT_TEST(testOnTestMethodEnd);
	CPPUNIT_TEST(testSetListener);
	CPPUNIT_TEST_SUITE_END();

	public:
		void setUp(void);
		void tearDown(void);

		void testOnGlobalStart(void);
		void testOnGlobalEnd(void);
		void testOnTestCaseStart(void);
		void testOnTestCaseEnd(void);
		void testOnTestMethodStart(void);
		void testOnTestMethodEnd(void);
		void testSetListener(void);
	protected:
		UnitTestMockListener * listener;
		UnitTestMockTestCase * testCase;
};

/*******************  FUNCTION  *********************/
void UnitTestsvutListener::setUp(void)
{
	this->listener = new UnitTestMockListener();
	this->testCase = new UnitTestMockTestCase();
}

/*******************  FUNCTION  *********************/
void UnitTestsvutListener::tearDown(void)
{
	delete this->listener;
	delete this->testCase;
}

/*******************  FUNCTION  *********************/
void UnitTestsvutListener::testOnGlobalStart(void )
{
	CPPUNIT_ASSERT_EQUAL(0,listener->mockTime);
	CPPUNIT_ASSERT_EQUAL(-1,listener->mockEvents.global_start);

	testCase->runTestCase(listener);

	CPPUNIT_ASSERT_EQUAL(6,listener->mockTime);
	CPPUNIT_ASSERT_EQUAL(-1,listener->mockEvents.global_start);
}

/*******************  FUNCTION  *********************/
void UnitTestsvutListener::testOnGlobalEnd(void )
{
	CPPUNIT_ASSERT_EQUAL(0,listener->mockTime);
	CPPUNIT_ASSERT_EQUAL(-1,listener->mockEvents.global_end);

	testCase->runTestCase(listener);

	CPPUNIT_ASSERT_EQUAL(6,listener->mockTime);
	CPPUNIT_ASSERT_EQUAL(-1,listener->mockEvents.global_end);
}

/*******************  FUNCTION  *********************/
void UnitTestsvutListener::testOnTestCaseStart(void )
{
	CPPUNIT_ASSERT_EQUAL(0,listener->mockTime);
	CPPUNIT_ASSERT_EQUAL(-1,listener->mockEvents.case_start);

	testCase->runTestCase(listener);

	CPPUNIT_ASSERT_EQUAL(6,listener->mockTime);
	CPPUNIT_ASSERT_EQUAL(0,listener->mockEvents.case_start);
}

/*******************  FUNCTION  *********************/
void UnitTestsvutListener::testOnTestCaseEnd(void )
{
	CPPUNIT_ASSERT_EQUAL(0,listener->mockTime);
	CPPUNIT_ASSERT_EQUAL(-1,listener->mockEvents.case_end);

	testCase->runTestCase(listener);

	CPPUNIT_ASSERT_EQUAL(6,listener->mockTime);
	CPPUNIT_ASSERT_EQUAL(5,listener->mockEvents.case_end);
}

/*******************  FUNCTION  *********************/
void UnitTestsvutListener::testOnTestMethodStart(void )
{
	CPPUNIT_ASSERT_EQUAL(0,listener->mockTime);
	CPPUNIT_ASSERT_EQUAL(-1,listener->mockEvents.meth_start);

	testCase->runTestCase(listener);

	CPPUNIT_ASSERT_EQUAL(6,listener->mockTime);
	CPPUNIT_ASSERT_EQUAL(3,listener->mockEvents.meth_start);
}

/*******************  FUNCTION  *********************/
void UnitTestsvutListener::testOnTestMethodEnd(void )
{
	CPPUNIT_ASSERT_EQUAL(0,listener->mockTime);
	CPPUNIT_ASSERT_EQUAL(-1,listener->mockEvents.meth_end);

	testCase->runTestCase(listener);

	CPPUNIT_ASSERT_EQUAL(6,listener->mockTime);
	CPPUNIT_ASSERT_EQUAL(4,listener->mockEvents.meth_end);
}

/*******************  FUNCTION  *********************/
void UnitTestsvutListener::testSetListener(void )
{
	UnitTestMockListener list;

	CPPUNIT_ASSERT_EQUAL(0,listener->mockTime);
	CPPUNIT_ASSERT_EQUAL(0,list.mockTime);

	testCase->runTestCase(&list);
	
	CPPUNIT_ASSERT_EQUAL(0,listener->mockTime);
	CPPUNIT_ASSERT_EQUAL(6,list.mockTime);
}


CPPUNIT_TEST_SUITE_REGISTRATION(UnitTestsvutListener);
