/*****************************************************
             PROJECT  : svUnitTest
             VERSION  : 0.3.0-dev
             DATE     : 03/2011
             AUTHOR   : Valat Sébastien
             LICENSE  : CeCILL-C
*****************************************************/

/********************  HEADERS  *********************/
#include "UnitTestExtra.h"
#include <iostream>
#include <cppunit/TestCase.h>
#include <cppunit/extensions/TestFactoryRegistry.h>
#include <cppunit/extensions/HelperMacros.h>
#include <svutListenerSummary.h>
#include "UnitTestMockTestCase2.h"

/**********************  USING  *********************/
using namespace std;
using namespace svUnitTest;
using namespace CPPUNIT_NS;

/*********************  CLASS  **********************/
class UnitTest_svutListenerSummary : public TestCase
{
	CPPUNIT_TEST_SUITE(UnitTest_svutListenerSummary);
	CPPUNIT_TEST(testGetSummary);
	CPPUNIT_TEST(testEvents_1);
	CPPUNIT_TEST(testEvents_2);
	CPPUNIT_TEST_SUITE_END();

	public:
		void setUp(void);
		void tearDown(void);

		void testGetSummary(void);
		void testEvents_1(void);
		void testEvents_2(void);
	protected:
		svutListenerSummary * listener;
		UnitTestMockTestCase2 * testCase;
};

/*******************  FUNCTION  *********************/
void UnitTest_svutListenerSummary::setUp(void)
{
	listener = new svutListenerSummary();
	testCase = new UnitTestMockTestCase2();
	testCase->useTests(UnitTestMockTestCase2::REGISTER_ALL);
}

/*******************  FUNCTION  *********************/
void UnitTest_svutListenerSummary::tearDown(void)
{
	delete testCase;
	delete listener;
}

/*******************  FUNCTION  *********************/
void UnitTest_svutListenerSummary::testGetSummary(void )
{
	svutResultSummary summary = listener->getSummary();
	CPPUNIT_ASSERT_EQUAL(0u,summary.getCount(SVUT_STATUS_FAILED));
	CPPUNIT_ASSERT_EQUAL(0u,summary.getCount(SVUT_STATUS_INDEV));
	CPPUNIT_ASSERT_EQUAL(0u,summary.getCount(SVUT_STATUS_SUCCESS));
	CPPUNIT_ASSERT_EQUAL(0u,summary.getCount(SVUT_STATUS_SKIPED));
	CPPUNIT_ASSERT_EQUAL(0u,summary.getCount(SVUT_STATUS_UNKNOWN));
	CPPUNIT_ASSERT_EQUAL(0u,summary.getCount(SVUT_STATUS_TODO));
}

/*******************  FUNCTION  *********************/
void UnitTest_svutListenerSummary::testEvents_1(void )
{
	svutResultSummary summary = listener->getSummary();
	CPPUNIT_ASSERT_EQUAL(0u,summary.getCount(SVUT_STATUS_FAILED));
	CPPUNIT_ASSERT_EQUAL(0u,summary.getCount(SVUT_STATUS_INDEV));
	CPPUNIT_ASSERT_EQUAL(0u,summary.getCount(SVUT_STATUS_SUCCESS));
	CPPUNIT_ASSERT_EQUAL(0u,summary.getCount(SVUT_STATUS_SKIPED));
	CPPUNIT_ASSERT_EQUAL(0u,summary.getCount(SVUT_STATUS_UNKNOWN));
	CPPUNIT_ASSERT_EQUAL(0u,summary.getCount(SVUT_STATUS_TODO));

	testCase->runTestCase(listener);
	summary = listener->getSummary();
	CPPUNIT_ASSERT_EQUAL(1u,summary.getCount(SVUT_STATUS_FAILED));
	CPPUNIT_ASSERT_EQUAL(2u,summary.getCount(SVUT_STATUS_INDEV));
	CPPUNIT_ASSERT_EQUAL(1u,summary.getCount(SVUT_STATUS_SUCCESS));
	CPPUNIT_ASSERT_EQUAL(0u,summary.getCount(SVUT_STATUS_SKIPED));
	CPPUNIT_ASSERT_EQUAL(2u,summary.getCount(SVUT_STATUS_UNKNOWN));
	CPPUNIT_ASSERT_EQUAL(4u,summary.getCount(SVUT_STATUS_TODO));
}

/*******************  FUNCTION  *********************/
void UnitTest_svutListenerSummary::testEvents_2(void )
{
	svutResultSummary summary = listener->getSummary();
	CPPUNIT_ASSERT_EQUAL(0u,summary.getCount(SVUT_STATUS_FAILED));
	CPPUNIT_ASSERT_EQUAL(0u,summary.getCount(SVUT_STATUS_INDEV));
	CPPUNIT_ASSERT_EQUAL(0u,summary.getCount(SVUT_STATUS_SUCCESS));
	CPPUNIT_ASSERT_EQUAL(0u,summary.getCount(SVUT_STATUS_SKIPED));
	CPPUNIT_ASSERT_EQUAL(0u,summary.getCount(SVUT_STATUS_UNKNOWN));
	CPPUNIT_ASSERT_EQUAL(0u,summary.getCount(SVUT_STATUS_TODO));

	testCase->runTestCase(listener);
	testCase->runTestCase(listener);
	summary = listener->getSummary();
	CPPUNIT_ASSERT_EQUAL(2u,summary.getCount(SVUT_STATUS_FAILED));
	CPPUNIT_ASSERT_EQUAL(4u,summary.getCount(SVUT_STATUS_INDEV));
	CPPUNIT_ASSERT_EQUAL(2u,summary.getCount(SVUT_STATUS_SUCCESS));
	CPPUNIT_ASSERT_EQUAL(0u,summary.getCount(SVUT_STATUS_SKIPED));
	CPPUNIT_ASSERT_EQUAL(4u,summary.getCount(SVUT_STATUS_UNKNOWN));
	CPPUNIT_ASSERT_EQUAL(8u,summary.getCount(SVUT_STATUS_TODO));
}

CPPUNIT_TEST_SUITE_REGISTRATION(UnitTest_svutListenerSummary);
