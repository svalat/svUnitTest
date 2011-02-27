/*****************************************************
             PROJECT  : svUnitTest
             VERSION  : 0.2.0
             DATE     : 02/2011
             AUTHOR   : Valat Sébastien
             LICENSE  : CeCILL-C
*****************************************************/

/********************  HEADERS  *********************/
//needed to build a new test case.
#include <svUnitTest/svutTestCase.h>
#include <string>

/**********************  USING  *********************/
using namespace svUnitTest;
using namespace std;

/*********************  CLASS  **********************/
class testNothing : public svutTestCase
{
	public:
		testNothing(void);
		virtual void setUp(void);
		virtual void tearDown(void);
	protected:
		void testFunc1(void);
		void testFunc2(void);
		void testFunc3(void);
		void testFunc4(void);
		string * obj;
};

/*******************  FUNCTION  *********************/
//Now register the test case and generate the default main function
SVUT_REGISTER_TEST_CASE(testNothing);

/*******************  FUNCTION  *********************/
testNothing::testNothing(void)
	:svutTestCase("testNothing")
{
	SVUT_REG_TEST_METHOD(testNothing,testFunc1);
	SVUT_REG_TEST_METHOD(testNothing,testFunc2);
	SVUT_REG_TEST_METHOD(testNothing,testFunc3);
	SVUT_REG_TEST_METHOD(testNothing,testFunc4);
};

/*******************  FUNCTION  *********************/
void testNothing::setUp(void)
{
}

/*******************  FUNCTION  *********************/
void testNothing::tearDown(void)
{
}

/*******************  FUNCTION  *********************/
void testNothing::testFunc1(void)
{
	SVUT_ASSERT_TODO("Nothing to test !");
}

/*******************  FUNCTION  *********************/
void testNothing::testFunc2(void)
{
	SVUT_ASSERT_TODO("Nothing to test !");
}

/*******************  FUNCTION  *********************/
void testNothing::testFunc3(void)
{
	SVUT_ASSERT_TODO("Nothing to test !");
}

/*******************  FUNCTION  *********************/
void testNothing::testFunc4(void)
{
	SVUT_ASSERT_TODO("Nothing to test !");
}