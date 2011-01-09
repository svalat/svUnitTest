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
		UnitTest_MyTestCaseBase(std::string name);
	protected:
		virtual void setUp(void);
		virtual void tearDown(void);
		void test1(void);
		void test2(void);
		bool hasCallTest;
};

/********************* CLASS ************************/
class UnitTest_MyTestCase1 : public UnitTest_MyTestCaseBase
{
	public:
		UnitTest_MyTestCase1():UnitTest_MyTestCaseBase("UnitTest_MyTestCase1"){};
};
SVUT_REGISTER_TEST_CASE(UnitTest_MyTestCase1);

/********************* CLASS ************************/
class UnitTest_MyTestCase2 : public UnitTest_MyTestCaseBase
{
	public:
		UnitTest_MyTestCase2():UnitTest_MyTestCaseBase("UnitTest_MyTestCase2"){};
};
SVUT_REGISTER_TEST_CASE(UnitTest_MyTestCase2);

/********************* CLASS ************************/
class UnitTest_MyTestCase3 : public UnitTest_MyTestCaseBase
{
	public:
		UnitTest_MyTestCase3():UnitTest_MyTestCaseBase("UnitTest_MyTestCase3"){};
};
SVUT_REGISTER_TEST_CASE(UnitTest_MyTestCase3);

/********************  METHODE  *********************/
UnitTest_MyTestCaseBase::UnitTest_MyTestCaseBase(string name)
	:svutTestCase(name)
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
int main(int argc, char * argv[])
{
	return svUnitTest::defaultMain(argc,argv);
}