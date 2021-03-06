/*****************************************************
             PROJECT  : svUnitTest
             VERSION  : 0.5.0-dev
             DATE     : 11/2012
             AUTHOR   : Valat Sébastien
             LICENSE  : CeCILL-C 2.1
*****************************************************/

/********************  HEADERS  *********************/
//needed to build a new test case.
#include <svUnitTest/svUnitTest.h>
#include <string>

/**********************  USING  *********************/
using namespace svUnitTest;
using namespace std;

/*********************  CLASS  **********************/
class testString : public svutTestCase
{
	public:
		testString(void);
		virtual void setUp(void);
		virtual void tearDown(void);
		virtual void testMethodsRegistration(void);
	protected:
		void testSize(void);
		void testClear(void);
		void testOperatorPlus(void);
		string * obj;
};

/*******************  FUNCTION  *********************/
//Now register the test case and generate the default main function
SVUT_REGISTER_STANDALONE(testString);

/*******************  FUNCTION  *********************/
testString::testString(void)
	:svutTestCase("testString")
{
	obj = NULL;
};

/*******************  FUNCTION  *********************/
void testString::testMethodsRegistration(void )
{
	SVUT_REG_TEST_METHOD(testSize);
	SVUT_REG_TEST_METHOD(testClear);
	SVUT_REG_TEST_METHOD(testOperatorPlus);
}

/*******************  FUNCTION  *********************/
void testString::setUp(void)
{
	this->obj = new string("Hello World !!!");
}

/*******************  FUNCTION  *********************/
void testString::tearDown(void)
{
	delete this->obj;
}

/*******************  FUNCTION  *********************/
void testString::testSize(void)
{
	//assume "Hello World !!!" contain 15 characters
	SVUT_ASSERT_EQUAL(15,obj->size());
}

/*******************  FUNCTION  *********************/
void testString::testClear(void)
{
	//pre check
	SVUT_ASSERT_EQUAL(15,obj->size());
	SVUT_ASSERT_EQUAL("Hello World !!!",*obj);

	obj->clear();

	//post check
	SVUT_ASSERT_EQUAL(0,obj->size());
	SVUT_ASSERT_EQUAL("",*obj);
}

/*******************  FUNCTION  *********************/
void testString::testOperatorPlus(void)
{
	//pre check
	SVUT_ASSERT_EQUAL(15,obj->size());
	SVUT_ASSERT_EQUAL("Hello World !!!",*obj);

	*obj = (*obj) + " Tested.";

	//post check
	SVUT_ASSERT_EQUAL(23,obj->size());
	SVUT_ASSERT_EQUAL("Hello World !!! Tested.",*obj);
}
