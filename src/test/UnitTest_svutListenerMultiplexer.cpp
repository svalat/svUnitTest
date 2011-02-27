/*****************************************************
             PROJECT  : svUnitTest
             VERSION  : 0.2.0
             DATE     : 02/2011
             AUTHOR   : Valat Sébastien
             LICENSE  : CeCILL-C
*****************************************************/

/********************  HEADERS  *********************/
#include "UnitTestExtra.h"
#include <iostream>
#include <cppunit/TestCase.h>
#include <cppunit/extensions/TestFactoryRegistry.h>
#include <cppunit/extensions/HelperMacros.h>
#include <svutListenerMultiplexer.h>
#include "UnitTestMockListener.h"
#include "UnitTestMockTestCase.h"

/**********************  USING  *********************/
using namespace svUnitTest;
using namespace CPPUNIT_NS;

/*********************  CLASS  **********************/
class UnitTest_svutListenerMultiplexer : public TestCase
{
	CPPUNIT_TEST_SUITE(UnitTest_svutListenerMultiplexer);
	CPPUNIT_TEST(testOnGlobalStart);
	CPPUNIT_TEST(testOnGlobalEnd);
	CPPUNIT_TEST(testOnTestCaseStart);
	CPPUNIT_TEST(testOnTestCaseEnd);
	CPPUNIT_TEST(testOnTestMethodStart);
	CPPUNIT_TEST(testOnTestMethodEnd);
	CPPUNIT_TEST(testAddListener);
	CPPUNIT_TEST(testRemoveListener_good);
	CPPUNIT_TEST(testRemoveListener_bad);
	CPPUNIT_TEST(testCountListener);
	CPPUNIT_TEST_SUITE_END();

	public:
		void setUp(void);
		void tearDown(void);

	protected:
		void testOnGlobalStart(void);
		void testOnGlobalEnd(void);
		void testOnTestCaseStart(void);
		void testOnTestCaseEnd(void);
		void testOnTestMethodStart(void);
		void testOnTestMethodEnd(void);
		void testAddListener(void);
		void testRemoveListener_good(void);
		void testRemoveListener_bad(void);
		void testCountListener(void);

		svutListenerMultiplexer * obj;
		UnitTestMockListener * mock1;
		UnitTestMockListener * mock2;
		UnitTestMockListener * mock3;
};

/*******************  FUNCTION  *********************/
void UnitTest_svutListenerMultiplexer::setUp(void)
{
	obj = new svutListenerMultiplexer();
	mock1 = new UnitTestMockListener();
	mock2 = new UnitTestMockListener();
	mock3 = new UnitTestMockListener();
	obj->addListener(mock1);
	obj->addListener(mock2);
}

/*******************  FUNCTION  *********************/
void UnitTest_svutListenerMultiplexer::tearDown(void)
{
	delete obj;
	delete mock1;
	delete mock2;
	delete mock3;
}

/*******************  FUNCTION  *********************/
void UnitTest_svutListenerMultiplexer::testOnGlobalStart(void )
{
	CPPUNIT_ASSERT_EQUAL(0,mock1->mockTime);
	CPPUNIT_ASSERT_EQUAL(0,mock2->mockTime);

	obj->onGlobalStart();

	CPPUNIT_ASSERT_EQUAL(1,mock1->mockTime);
	CPPUNIT_ASSERT_EQUAL(0,mock1->mockEvents.global_start);
	CPPUNIT_ASSERT_EQUAL(1,mock2->mockTime);
	CPPUNIT_ASSERT_EQUAL(0,mock2->mockEvents.global_start);
}

/*******************  FUNCTION  *********************/
void UnitTest_svutListenerMultiplexer::testOnGlobalEnd(void )
{
	CPPUNIT_ASSERT_EQUAL(0,mock1->mockTime);
	CPPUNIT_ASSERT_EQUAL(0,mock2->mockTime);

	obj->onGlobalEnd();

	CPPUNIT_ASSERT_EQUAL(1,mock1->mockTime);
	CPPUNIT_ASSERT_EQUAL(0,mock1->mockEvents.global_end);
	CPPUNIT_ASSERT_EQUAL(1,mock2->mockTime);
	CPPUNIT_ASSERT_EQUAL(0,mock2->mockEvents.global_end);
}

/*******************  FUNCTION  *********************/
void UnitTest_svutListenerMultiplexer::testOnTestCaseStart(void )
{
	CPPUNIT_ASSERT_EQUAL(0,mock1->mockTime);
	CPPUNIT_ASSERT_EQUAL(0,mock2->mockTime);

	UnitTestMockTestCase testCase;
	obj->onTestCaseStart(testCase);

	CPPUNIT_ASSERT_EQUAL(1,mock1->mockTime);
	CPPUNIT_ASSERT_EQUAL(0,mock1->mockEvents.case_start);
	CPPUNIT_ASSERT_EQUAL(1,mock2->mockTime);
	CPPUNIT_ASSERT_EQUAL(0,mock2->mockEvents.case_start);
}

/*******************  FUNCTION  *********************/
void UnitTest_svutListenerMultiplexer::testOnTestCaseEnd(void )
{
	CPPUNIT_ASSERT_EQUAL(0,mock1->mockTime);
	CPPUNIT_ASSERT_EQUAL(0,mock2->mockTime);

	UnitTestMockTestCase testCase;
	obj->onTestCaseEnd(testCase);

	CPPUNIT_ASSERT_EQUAL(1,mock1->mockTime);
	CPPUNIT_ASSERT_EQUAL(0,mock1->mockEvents.case_end);
	CPPUNIT_ASSERT_EQUAL(1,mock2->mockTime);
	CPPUNIT_ASSERT_EQUAL(0,mock2->mockEvents.case_end);
}

/*******************  FUNCTION  *********************/
void UnitTest_svutListenerMultiplexer::testOnTestMethodStart(void )
{
	CPPUNIT_ASSERT_EQUAL(0,mock1->mockTime);
	CPPUNIT_ASSERT_EQUAL(0,mock2->mockTime);

	UnitTestMockTestCase testCase;
	svutTestMethod meth("test",NULL,SVUT_CODE_LOCATION);
	obj->onTestMethodStart(testCase,meth);

	CPPUNIT_ASSERT_EQUAL(1,mock1->mockTime);
	CPPUNIT_ASSERT_EQUAL(0,mock1->mockEvents.meth_start);
	CPPUNIT_ASSERT_EQUAL(1,mock2->mockTime);
	CPPUNIT_ASSERT_EQUAL(0,mock2->mockEvents.meth_start);
}

/*******************  FUNCTION  *********************/
void UnitTest_svutListenerMultiplexer::testOnTestMethodEnd(void )
{
	CPPUNIT_ASSERT_EQUAL(0,mock1->mockTime);
	CPPUNIT_ASSERT_EQUAL(0,mock2->mockTime);

	UnitTestMockTestCase testCase;
	svutTestMethod meth("test",NULL,SVUT_NO_LOCATION);
	svutStatusInfo status(svUnitTest::SVUT_STATUS_INDEV,"test",SVUT_NO_LOCATION);
	obj->onTestMethodEnd(testCase,meth,status);

	CPPUNIT_ASSERT_EQUAL(1,mock1->mockTime);
	CPPUNIT_ASSERT_EQUAL(0,mock1->mockEvents.meth_end);
	CPPUNIT_ASSERT_EQUAL(1,mock2->mockTime);
	CPPUNIT_ASSERT_EQUAL(0,mock2->mockEvents.meth_end);
}

/*******************  FUNCTION  *********************/
void UnitTest_svutListenerMultiplexer::testCountListener(void )
{
	CPPUNIT_ASSERT_EQUAL(2,obj->countListener());
}

/*******************  FUNCTION  *********************/
void UnitTest_svutListenerMultiplexer::testAddListener(void )
{
	CPPUNIT_ASSERT_EQUAL(2,obj->countListener()),
	obj->addListener(mock3);
	CPPUNIT_ASSERT_EQUAL(3,obj->countListener());
}

/*******************  FUNCTION  *********************/
void UnitTest_svutListenerMultiplexer::testRemoveListener_good(void )
{
	try {
		CPPUNIT_ASSERT_EQUAL(2,obj->countListener());
		obj->removeListener(mock1);
		CPPUNIT_ASSERT_EQUAL(1,obj->countListener());
	} catch (svutExInternalError) {
		CPPUNIT_FAIL("Throw not expected svutExInternalError.");
	}
}

/*******************  FUNCTION  *********************/
void UnitTest_svutListenerMultiplexer::testRemoveListener_bad(void )
{
	CPPUNIT_ASSERT_EQUAL(2,obj->countListener());
	try {
		obj->removeListener(mock3);
		CPPUNIT_FAIL("Not throw svutExInternalError as expected.");
	} catch (svutExInternalError) {
	}
	CPPUNIT_ASSERT_EQUAL(2,obj->countListener());
}

CPPUNIT_TEST_SUITE_REGISTRATION(UnitTest_svutListenerMultiplexer);
