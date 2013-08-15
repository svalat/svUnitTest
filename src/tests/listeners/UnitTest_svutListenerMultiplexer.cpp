/*****************************************************
             PROJECT  : svUnitTest
             VERSION  : 0.5.0-dev
             DATE     : 11/2012
             AUTHOR   : Valat Sébastien
             LICENSE  : CeCILL-C 2.1
*****************************************************/

/********************  HEADERS  *********************/
#include "UnitTestExtra.h"
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
	CPPUNIT_TEST(testOnListingStart);
	CPPUNIT_TEST(testOnListMethod);
	CPPUNIT_TEST(testOnListingEnd);
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
		void testOnListingStart(void);
		void testOnListMethod(void);
		void testOnListingEnd(void);

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
	svutTestMethod meth("test",SVUT_CODE_LOCATION,NULL);
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
	svutTestMethod meth("test",SVUT_NO_LOCATION,NULL);
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
	CPPUNIT_ASSERT_EQUAL(2u,obj->countListener());
}

/*******************  FUNCTION  *********************/
void UnitTest_svutListenerMultiplexer::testAddListener(void )
{
	CPPUNIT_ASSERT_EQUAL(2u,obj->countListener()),
	obj->addListener(mock3);
	CPPUNIT_ASSERT_EQUAL(3u,obj->countListener());
}

/*******************  FUNCTION  *********************/
void UnitTest_svutListenerMultiplexer::testRemoveListener_good(void )
{
	try {
		CPPUNIT_ASSERT_EQUAL(2u,obj->countListener());
		obj->removeListener(mock1);
		CPPUNIT_ASSERT_EQUAL(1u,obj->countListener());
	} catch (svutExInternalError) {
		CPPUNIT_FAIL("Throw not expected svutExInternalError.");
	}
}

/*******************  FUNCTION  *********************/
void UnitTest_svutListenerMultiplexer::testRemoveListener_bad(void )
{
	CPPUNIT_ASSERT_EQUAL(2u,obj->countListener());
	try {
		obj->removeListener(mock3);
		CPPUNIT_FAIL("Not throw svutExInternalError as expected.");
	} catch (svutExInternalError) {
	}
	CPPUNIT_ASSERT_EQUAL(2u,obj->countListener());
}

/*******************  FUNCTION  *********************/
void UnitTest_svutListenerMultiplexer::testOnListingStart(void )
{
	CPPUNIT_ASSERT_EQUAL(0,mock1->mockTime);
	CPPUNIT_ASSERT_EQUAL(0,mock2->mockTime);
	CPPUNIT_ASSERT_EQUAL(-1,mock1->mockEvents.listing_start);
	CPPUNIT_ASSERT_EQUAL(-1,mock2->mockEvents.listing_start);

	obj->onListingStart();

	CPPUNIT_ASSERT_EQUAL(1,mock1->mockTime);
	CPPUNIT_ASSERT_EQUAL(0,mock1->mockEvents.listing_start);
	CPPUNIT_ASSERT_EQUAL(1,mock2->mockTime);
	CPPUNIT_ASSERT_EQUAL(0,mock2->mockEvents.listing_start);
}

/*******************  FUNCTION  *********************/
void UnitTest_svutListenerMultiplexer::testOnListMethod(void )
{
	CPPUNIT_ASSERT_EQUAL(0,mock1->mockTime);
	CPPUNIT_ASSERT_EQUAL(0,mock2->mockTime);
	CPPUNIT_ASSERT_EQUAL(-1,mock1->mockEvents.list_method);
	CPPUNIT_ASSERT_EQUAL(-1,mock2->mockEvents.list_method);

	UnitTestMockTestCase testCase;
	svutTestMethod meth("test",SVUT_CODE_LOCATION,NULL);
	obj->onListMethod(testCase,meth);

	CPPUNIT_ASSERT_EQUAL(1,mock1->mockTime);
	CPPUNIT_ASSERT_EQUAL(0,mock1->mockEvents.list_method);
	CPPUNIT_ASSERT_EQUAL(1,mock2->mockTime);
	CPPUNIT_ASSERT_EQUAL(0,mock2->mockEvents.list_method);
}

/*******************  FUNCTION  *********************/
void UnitTest_svutListenerMultiplexer::testOnListingEnd(void )
{
	CPPUNIT_ASSERT_EQUAL(0,mock1->mockTime);
	CPPUNIT_ASSERT_EQUAL(0,mock2->mockTime);
	CPPUNIT_ASSERT_EQUAL(-1,mock1->mockEvents.listing_end);
	CPPUNIT_ASSERT_EQUAL(-1,mock2->mockEvents.listing_end);

	obj->onListingEnd();

	CPPUNIT_ASSERT_EQUAL(1,mock1->mockTime);
	CPPUNIT_ASSERT_EQUAL(0,mock1->mockEvents.listing_end);
	CPPUNIT_ASSERT_EQUAL(1,mock2->mockTime);
	CPPUNIT_ASSERT_EQUAL(0,mock2->mockEvents.listing_end);
}

CPPUNIT_TEST_SUITE_REGISTRATION(UnitTest_svutListenerMultiplexer);
