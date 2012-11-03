/*****************************************************
             PROJECT  : svUnitTest
             VERSION  : 0.5.0-dev
             DATE     : 11/2012
             AUTHOR   : Valat Sébastien
             LICENSE  : CeCILL-C
*****************************************************/

/********************  HEADERS  *********************/
//needed to build a new test case.
#include <svUnitTest/svUnitTest.h>

/**********************  USING  *********************/
using namespace svUnitTest;

/*********************  CLASS  **********************/
class testString : public svutTestCase
{
	public:
		testString(void);
		virtual void setUp(void);
		virtual void tearDown(void);
	protected:
		void testSize(void);
		void testClear(void);
		void testOperatorPlus(void);
};

/*******************  FUNCTION  *********************/
//Now register the test case and generate the default main function
SVUT_REGISTER_STANDALONE(testString);

/*******************  FUNCTION  *********************/
testString::testString(void)
           :svutTestCase("testString")
{
	SVUT_REG_TEST_METHOD(testSize);
	SVUT_REG_TEST_METHOD(testClear);
	SVUT_REG_TEST_METHOD(testOperatorPlus);
};

/*******************  FUNCTION  *********************/
void testString::setUp(void)    {};
/*******************  FUNCTION  *********************/
void testString::tearDown(void) {};

/*******************  FUNCTION  *********************/
void testString::testSize(void)            { SVUT_ASSERT_TODO("Need implementation");};
/*******************  FUNCTION  *********************/
void testString::testClear(void)           { SVUT_ASSERT_TODO("Need implementation");};
/*******************  FUNCTION  *********************/
void testString::testOperatorPlus(void   ) { SVUT_ASSERT_TODO("Need implementation");};
