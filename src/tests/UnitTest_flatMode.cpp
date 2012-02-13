/*****************************************************
             PROJECT  : svUnitTest
             VERSION  : 0.3.0
             DATE     : 05/2011
             AUTHOR   : Valat Sébastien
             LICENSE  : CeCILL-C
*****************************************************/

/********************  HEADERS  *********************/
#include <svUnitTest.h>

/**********************  USING  *********************/
using namespace svUnitTest;

/********************  GLOBALS  *********************/
int globalInt = 0;

/*******************  FUNCTION  *********************/
SVUT_DECLARE_FLAT_TEST(TestCase1,testMethod1)
{
	SVUT_ASSERT_EQUAL(0,globalInt);
}

/*******************  FUNCTION  *********************/
SVUT_DECLARE_FLAT_TEST(TestCase1,testMethod2)
{
	SVUT_ASSERT_EQUAL(0,globalInt);
}

/*******************  FUNCTION  *********************/
SVUT_DECLARE_FLAT_TEST(TestCase2,testMethodAAAAAAA1)
{
	SVUT_ASSERT_EQUAL(0,globalInt);
}

/*******************  FUNCTION  *********************/
void testMethodAAAAAAA2(void)
{
	SVUT_ASSERT_EQUAL(0,globalInt);
}
SVUT_REGISTER_FLAT_TEST(TestCase2,testMethodAAAAAAA2);

/*******************  FUNCTION  *********************/
SVUT_DECLARE_FLAT_SETUP(TestCase3)
{
	SVUT_ASSERT_EQUAL(0,globalInt);
	globalInt = 1;
}

/*******************  FUNCTION  *********************/
SVUT_DECLARE_FLAT_TEAR_DOWN(TestCase3)
{
	SVUT_ASSERT_EQUAL(2,globalInt);
	globalInt = 0;
}

/*******************  FUNCTION  *********************/
SVUT_DECLARE_FLAT_TEST(TestCase3,testMethod1)
{
	SVUT_ASSERT_EQUAL(1,globalInt);
	globalInt = 2;
	SVUT_ASSERT_EQUAL(2,globalInt);
}

/*******************  FUNCTION  *********************/
SVUT_DECLARE_FLAT_TEST(TestCase3,testMethod2)
{
	SVUT_ASSERT_EQUAL(1,globalInt);
	globalInt = 2;
	SVUT_ASSERT_EQUAL(2,globalInt);
}

/*******************  FUNCTION  *********************/
void setupTestCase4(void)
{
	SVUT_ASSERT_EQUAL(0,globalInt);
	globalInt = 10;
}
SVUT_REGISTER_FLAT_SETUP(TestCase4,setupTestCase4);

/*******************  FUNCTION  *********************/
void tearDownTestCase4(void)
{
	SVUT_ASSERT_EQUAL(20,globalInt);
	globalInt = 0;
}
SVUT_REGISTER_FLAT_TEAR_DOWN(TestCase4,tearDownTestCase4);

/*******************  FUNCTION  *********************/
SVUT_DECLARE_FLAT_TEST(TestCase4,testMethod1)
{
	SVUT_ASSERT_EQUAL(10,globalInt);
	globalInt = 20;
	SVUT_ASSERT_EQUAL(20,globalInt);
}

/*******************  FUNCTION  *********************/
SVUT_DECLARE_FLAT_TEST(TestCase4,testMethod2)
{
	SVUT_ASSERT_EQUAL(10,globalInt);
	globalInt = 20;
	SVUT_ASSERT_EQUAL(20,globalInt);
}

/*******************  FUNCTION  *********************/
SVUT_DECLARE_FLAT_TEST(TestCase5,testPrintf)
{
	SVUT_PRINTF("Test printf %d\n",10);
}

/*******************  FUNCTION  *********************/
SVUT_DECLARE_FLAT_TEST(TestCase6,testPuts)
{
	SVUT_PUTS("Test puts");
}

/*******************  FUNCTION  *********************/
SVUT_DECLARE_FLAT_TEST(TestCase6,testCout)
{
	SVUT_COUT << "Test cout" << std::endl;
}

/*******************  FUNCTION  *********************/
SVUT_DECLARE_FLAT_TEST(TestCase6,testContext)
{
	SVUT_SET_CONTEXT("value",10);
	SVUT_UNSET_CONTEXT("value");
	SVUT_RESET_CONTEXT();
}

SVUT_USE_DEFAULT_MAIN
