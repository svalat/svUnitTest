/*****************************************************
             PROJECT  : svUnitTest
             VERSION  : 0.4.0
             DATE     : 11/2012
             AUTHOR   : Valat Sébastien
             LICENSE  : CeCILL-C
*****************************************************/

/********************  HEADERS  *********************/
//needed to build a new test case.
#include <svUnitTest/svUnitTest.h>
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
		virtual void testMethodsRegistration(void );
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
	obj = NULL;
};

/*******************  FUNCTION  *********************/
void testNothing::testMethodsRegistration(void )
{
    SVUT_REG_TEST_METHOD(testFunc1);
	SVUT_REG_TEST_METHOD(testFunc2);
	SVUT_REG_TEST_METHOD(testFunc3);
	SVUT_REG_TEST_METHOD(testFunc4);
}

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