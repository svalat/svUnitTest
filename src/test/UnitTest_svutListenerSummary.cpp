/*****************************************************
             PROJECT  : svUnitTest
             VERSION  : 0.0.2
             DATE     : 06/2010
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

using namespace std;
using namespace svUnitTest;
using namespace CPPUNIT_NS;

/********************  CLASSE  **********************/
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

/********************  METHODE  *********************/
void UnitTest_svutListenerSummary::setUp(void)
{
	listener = new svutListenerSummary();
	testCase = new UnitTestMockTestCase2();
	testCase->setListener(listener);
	testCase->useTests(UnitTestMockTestCase2::REGISTER_ALL);
}

/********************  METHODE  *********************/
void UnitTest_svutListenerSummary::tearDown(void)
{
	delete testCase;
	delete listener;
}

/********************  METHODE  *********************/
void UnitTest_svutListenerSummary::testGetSummary(void )
{
	svutResultSummary summary = listener->getSummary();
	CPPUNIT_ASSERT_EQUAL(0,summary.failed);
	CPPUNIT_ASSERT_EQUAL(0,summary.indev);
	CPPUNIT_ASSERT_EQUAL(0,summary.success);
	CPPUNIT_ASSERT_EQUAL(0,summary.skiped);
	CPPUNIT_ASSERT_EQUAL(0,summary.unknown);
	CPPUNIT_ASSERT_EQUAL(0,summary.todo);
}

/********************  METHODE  *********************/
void UnitTest_svutListenerSummary::testEvents_1(void )
{
	svutResultSummary summary = listener->getSummary();
	CPPUNIT_ASSERT_EQUAL(0,summary.failed);
	CPPUNIT_ASSERT_EQUAL(0,summary.indev);
	CPPUNIT_ASSERT_EQUAL(0,summary.success);
	CPPUNIT_ASSERT_EQUAL(0,summary.skiped);
	CPPUNIT_ASSERT_EQUAL(0,summary.unknown);
	CPPUNIT_ASSERT_EQUAL(0,summary.todo);

	testCase->runTestCase();
	summary = listener->getSummary();
	CPPUNIT_ASSERT_EQUAL(1,summary.failed);
	CPPUNIT_ASSERT_EQUAL(2,summary.indev);
	CPPUNIT_ASSERT_EQUAL(1,summary.success);
	CPPUNIT_ASSERT_EQUAL(0,summary.skiped);
	CPPUNIT_ASSERT_EQUAL(2,summary.unknown);
	CPPUNIT_ASSERT_EQUAL(4,summary.todo);
}

/********************  METHODE  *********************/
void UnitTest_svutListenerSummary::testEvents_2(void )
{
	svutResultSummary summary = listener->getSummary();
	CPPUNIT_ASSERT_EQUAL(0,summary.failed);
	CPPUNIT_ASSERT_EQUAL(0,summary.indev);
	CPPUNIT_ASSERT_EQUAL(0,summary.success);
	CPPUNIT_ASSERT_EQUAL(0,summary.skiped);
	CPPUNIT_ASSERT_EQUAL(0,summary.unknown);
	CPPUNIT_ASSERT_EQUAL(0,summary.todo);

	testCase->runTestCase();
	testCase->runTestCase();
	summary = listener->getSummary();
	CPPUNIT_ASSERT_EQUAL(2,summary.failed);
	CPPUNIT_ASSERT_EQUAL(4,summary.indev);
	CPPUNIT_ASSERT_EQUAL(2,summary.success);
	CPPUNIT_ASSERT_EQUAL(0,summary.skiped);
	CPPUNIT_ASSERT_EQUAL(4,summary.unknown);
	CPPUNIT_ASSERT_EQUAL(8,summary.todo);
}

CPPUNIT_TEST_SUITE_REGISTRATION(UnitTest_svutListenerSummary);
