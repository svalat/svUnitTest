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
#include <svUnitTest/svutDefaultMain.h>

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
SVUT_REGISTER_STANDELONE(testString);

/*******************  FUNCTION  *********************/
testString::testString(void)
           :svutTestCase("testString")
{
	SVUT_REG_TEST_METHOD(testString,testSize);
	SVUT_REG_TEST_METHOD(testString,testClear);
	SVUT_REG_TEST_METHOD(testString,testOperatorPlus);
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
