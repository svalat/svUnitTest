/*****************************************************
             PROJECT  : svUnitTest
             VERSION  : 0.0.2
             DATE     : 12/2010
             AUTHOR   : Valat Sébastien
             LICENSE  : CeCILL-C
*****************************************************/

/********************  HEADERS  *********************/
#include <svutTestCase.h>
#include <svutAssert.h>
#include <svutDefaultMain.h>
#include <iostream>

using namespace std;
using namespace svUnitTest;

/********************* CLASS ************************/
class UnitTest_MyTestCaseBase : public svutTestCase
{
	public:
		UnitTest_MyTestCaseBase();
	protected:
		virtual void setUp(void);
		virtual void tearDown(void);
		void test1(void);
		void test2(void);
		bool hasCallTest;
};

/********************  METHODE  *********************/
UnitTest_MyTestCaseBase::UnitTest_MyTestCaseBase()
	:svutTestCase("UnitTest_MyTestCaseBase")
{
	SVUT_REG_TEST_METHOD(UnitTest_MyTestCaseBase,test1);
	SVUT_REG_TEST_METHOD(UnitTest_MyTestCaseBase,test2);
}

/********************  METHODE  *********************/
void UnitTest_MyTestCaseBase::setUp(void )
{
	this->hasCallTest = false;
}

/********************  METHODE  *********************/
void UnitTest_MyTestCaseBase::tearDown(void )
{
	SVUT_ASSERT_TRUE(this->hasCallTest);
}

/********************  METHODE  *********************/
void UnitTest_MyTestCaseBase::test1(void )
{
	this->hasCallTest = true;
}

/********************  METHODE  *********************/
void UnitTest_MyTestCaseBase::test2(void )
{
	this->hasCallTest = true;
}

/********************  METHODE  *********************/
SVUT_REGISTER_STANDELONE(UnitTest_MyTestCaseBase);