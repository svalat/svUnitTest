/*****************************************************
             PROJECT  : svUnitTest
             VERSION  : 0.3.0-dev
             DATE     : 03/2011
             AUTHOR   : Valat Sébastien
             LICENSE  : CeCILL-C
*****************************************************/

/********************  HEADERS  *********************/
#include <svutTestCase.h>
#include <svutAssert.h>
#include <svutDefaultMain.h>
#include <iostream>

/**********************  USING  *********************/
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

/*******************  FUNCTION  *********************/
UnitTest_MyTestCaseBase::UnitTest_MyTestCaseBase()
	:svutTestCase("UnitTest_MyTestCaseBase")
{
	SVUT_REG_TEST_METHOD(test1);
	SVUT_REG_TEST_METHOD(test2);
}

/*******************  FUNCTION  *********************/
void UnitTest_MyTestCaseBase::setUp(void )
{
	this->hasCallTest = false;
}

/*******************  FUNCTION  *********************/
void UnitTest_MyTestCaseBase::tearDown(void )
{
	SVUT_ASSERT_TRUE(this->hasCallTest);
}

/*******************  FUNCTION  *********************/
void UnitTest_MyTestCaseBase::test1(void )
{
	this->hasCallTest = true;
}

/*******************  FUNCTION  *********************/
void UnitTest_MyTestCaseBase::test2(void )
{
	this->hasCallTest = true;
}

/*******************  FUNCTION  *********************/
SVUT_REGISTER_STANDELONE(UnitTest_MyTestCaseBase)
