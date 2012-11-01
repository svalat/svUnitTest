/*****************************************************
             PROJECT  : svUnitTest
             VERSION  : 0.4.0
             DATE     : 11/2012
             AUTHOR   : Valat Sébastien
             LICENSE  : CeCILL-C
*****************************************************/

/********************  HEADERS  *********************/
#include "UnitTestExtra.h"
#include "UnitTestMockListener.h"
#include "UnitTestMockTestCase2.h"
#include <svutTestCase.h>

/**********************  USING  *********************/
using namespace svUnitTest;
using namespace CPPUNIT_NS;

/*********************  CLASS  **********************/
class UnitTestsvutTestCaseResult : public TestCase
{
	CPPUNIT_TEST_SUITE(UnitTestsvutTestCaseResult);
	CPPUNIT_TEST(testSuccess);
	CPPUNIT_TEST(testFailure);
	CPPUNIT_TEST(testTodo);
	CPPUNIT_TEST(testIndev);
	CPPUNIT_TEST(testUnknown_1);
	CPPUNIT_TEST(testUnknown_2);
	CPPUNIT_TEST(testFailIsTodo_1);
	CPPUNIT_TEST(testFailIsTodo_2);
	CPPUNIT_TEST(testFailIsTodo_3);
	CPPUNIT_TEST(testSuccessIsIndev);
	CPPUNIT_TEST_SUITE_END();

	public:
		void setUp(void);
		void tearDown(void);
		
		void testSuccess(void);
		void testFailure(void);
		void testTodo(void);
		void testIndev(void);
		void testUnknown_1(void);
		void testUnknown_2(void);
		void testFailIsTodo_1(void);
		void testFailIsTodo_2(void);
		void testFailIsTodo_3(void);
		void testSuccessIsIndev(void);

	protected:
		UnitTestMockListener * listener;
		UnitTestMockTestCase2 * testCase;
};

/*******************  FUNCTION  *********************/
void UnitTestsvutTestCaseResult::setUp(void)
{
	this->listener = new UnitTestMockListener();
	this->testCase = new UnitTestMockTestCase2();
}

/*******************  FUNCTION  *********************/
void UnitTestsvutTestCaseResult::tearDown(void)
{
	delete this->listener;
	delete this->testCase;
}

/*******************  FUNCTION  *********************/
void UnitTestsvutTestCaseResult::testSuccess(void )
{
	CPPUNIT_ASSERT_EQUAL(0,listener->mockTime);
	
	testCase->useTests(UnitTestMockTestCase2::REGISTER_SUCCESS);
	testCase->runTestCase(listener);

	CPPUNIT_ASSERT_EQUAL(4,listener->mockTime);
	CPPUNIT_ASSERT_EQUAL(SVUT_STATUS_SUCCESS,listener->finalResults["testSuccess"].getStatus());
}

/*******************  FUNCTION  *********************/
void UnitTestsvutTestCaseResult::testFailure(void )
{
	CPPUNIT_ASSERT_EQUAL(0,listener->mockTime);

	testCase->useTests(UnitTestMockTestCase2::REGISTER_FAILURE);
	testCase->runTestCase(listener);

	CPPUNIT_ASSERT_EQUAL(4,listener->mockTime);
	CPPUNIT_ASSERT_EQUAL(SVUT_STATUS_FAILED,listener->finalResults["testFailure"].getStatus());
}

/*******************  FUNCTION  *********************/
void UnitTestsvutTestCaseResult::testIndev(void )
{
	CPPUNIT_ASSERT_EQUAL(0,listener->mockTime);

	testCase->useTests(UnitTestMockTestCase2::REGISTER_INDEV);
	testCase->runTestCase(listener);

	CPPUNIT_ASSERT_EQUAL(4,listener->mockTime);
	CPPUNIT_ASSERT_EQUAL(SVUT_STATUS_INDEV,listener->finalResults["testIndev"].getStatus());
}

/*******************  FUNCTION  *********************/
void UnitTestsvutTestCaseResult::testTodo(void )
{
	CPPUNIT_ASSERT_EQUAL(0,listener->mockTime);

	testCase->useTests(UnitTestMockTestCase2::REGISTER_TODO);
	testCase->runTestCase(listener);

	CPPUNIT_ASSERT_EQUAL(4,listener->mockTime);
	CPPUNIT_ASSERT_EQUAL(SVUT_STATUS_TODO,listener->finalResults["testTodo"].getStatus());
}

/*******************  FUNCTION  *********************/
void UnitTestsvutTestCaseResult::testUnknown_1(void )
{
	CPPUNIT_ASSERT_EQUAL(0,listener->mockTime);

	testCase->useTests(UnitTestMockTestCase2::REGISTER_UNKNOWN_1);
	testCase->runTestCase(listener);

	CPPUNIT_ASSERT_EQUAL(4,listener->mockTime);
	CPPUNIT_ASSERT_EQUAL(SVUT_STATUS_UNKNOWN,listener->finalResults["testUnknown_1"].getStatus());
}

/*******************  FUNCTION  *********************/
void UnitTestsvutTestCaseResult::testUnknown_2(void )
{
	CPPUNIT_ASSERT_EQUAL(0,listener->mockTime);

	testCase->useTests(UnitTestMockTestCase2::REGISTER_UNKNOWN_2);
	testCase->runTestCase(listener);

	CPPUNIT_ASSERT_EQUAL(4,listener->mockTime);
	CPPUNIT_ASSERT_EQUAL(SVUT_STATUS_UNKNOWN,listener->finalResults["testUnknown_2"].getStatus());
}

/*******************  FUNCTION  *********************/
void UnitTestsvutTestCaseResult::testFailIsTodo_1(void )
{
	CPPUNIT_ASSERT_EQUAL(0,listener->mockTime);

	testCase->useTests(UnitTestMockTestCase2::REGISTER_FAIL_IS_TODO_1);
	testCase->runTestCase(listener);

	CPPUNIT_ASSERT_EQUAL(4,listener->mockTime);
	CPPUNIT_ASSERT_EQUAL(SVUT_STATUS_TODO,listener->finalResults["testFailIsTodo_1"].getStatus());
}

/*******************  FUNCTION  *********************/
void UnitTestsvutTestCaseResult::testFailIsTodo_2(void )
{
	CPPUNIT_ASSERT_EQUAL(0,listener->mockTime);

	testCase->useTests(UnitTestMockTestCase2::REGISTER_FAIL_IS_TODO_2);
	testCase->runTestCase(listener);

	CPPUNIT_ASSERT_EQUAL(4,listener->mockTime);
	CPPUNIT_ASSERT_EQUAL(SVUT_STATUS_TODO,listener->finalResults["testFailIsTodo_2"].getStatus());
}

/*******************  FUNCTION  *********************/
void UnitTestsvutTestCaseResult::testFailIsTodo_3(void )
{
	CPPUNIT_ASSERT_EQUAL(0,listener->mockTime);

	testCase->useTests(UnitTestMockTestCase2::REGISTER_FAIL_IS_TODO_3);
	testCase->runTestCase(listener);

	CPPUNIT_ASSERT_EQUAL(4,listener->mockTime);
	CPPUNIT_ASSERT_EQUAL(SVUT_STATUS_TODO,listener->finalResults["testFailIsTodo_3"].getStatus());
}

/*******************  FUNCTION  *********************/
void UnitTestsvutTestCaseResult::testSuccessIsIndev(void )
{
	CPPUNIT_ASSERT_EQUAL(0,listener->mockTime);

	testCase->useTests(UnitTestMockTestCase2::REGISTER_SUCCESS_IS_INDEV);
	testCase->runTestCase(listener);

	CPPUNIT_ASSERT_EQUAL(4,listener->mockTime);
	CPPUNIT_ASSERT_EQUAL(SVUT_STATUS_INDEV,listener->finalResults["testSuccessIsIndev"].getStatus());
}

CPPUNIT_TEST_SUITE_REGISTRATION(UnitTestsvutTestCaseResult);
