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
	protected:
		void testSize(void);
		void testClear(void);
		void testOperatorPlus(void);
		string * obj;
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
