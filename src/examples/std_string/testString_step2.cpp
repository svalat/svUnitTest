//needed to build a new test case.
#include <svUnitTest/svutTestCase.h>
#include <svUnitTest/svutDefaultMain.h>
#include <string>

using namespace svUnitTest;
using namespace std;

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

//Now register the test case and generate the default main function
SVUT_REGISTER_STANDELONE(testString);


testString::testString(void)
	:svutTestCase("testString")
{
	SVUT_REG_TEST_METHOD(testString,testSize);
	SVUT_REG_TEST_METHOD(testString,testClear);
	SVUT_REG_TEST_METHOD(testString,testOperatorPlus);
};

void testString::setUp(void)
{
	this->obj = new string("Hello World !!!");
}

void testString::tearDown(void)
{
	delete this->obj;
}


void testString::testSize(void)
{
	//assume "Hello World !!!" contain 15 characters
	SVUT_ASSERT_EQUAL(15,obj->size());
}

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
