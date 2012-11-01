/*****************************************************
             PROJECT  : svUnitTest
             VERSION  : 0.4.0
             DATE     : 11/2012
             AUTHOR   : Valat Sébastien
             LICENSE  : CeCILL-C
*****************************************************/

/********************  HEADERS  *********************/
#include <svUnitTest.h>

/**********************  USING  *********************/
using namespace std;
using namespace svUnitTest;

/********************* CLASS ************************/
class UnitTest_MyTestCaseBase : public svutTestCase
{
	public:
		UnitTest_MyTestCaseBase(std::string name);
	    virtual void testMethodsRegistration(void );
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
		UnitTest_MyTestCase1():UnitTest_MyTestCaseBase("UnitTest_MyTestCase1"){}
};
SVUT_REGISTER_TEST_CASE(UnitTest_MyTestCase1);

/********************* CLASS ************************/
class UnitTest_MyTestCase2 : public UnitTest_MyTestCaseBase
{
	public:
		UnitTest_MyTestCase2():UnitTest_MyTestCaseBase("UnitTest_MyTestCase2"){}
};
SVUT_REGISTER_TEST_CASE(UnitTest_MyTestCase2);

/********************* CLASS ************************/
class UnitTest_MyTestCase3 : public UnitTest_MyTestCaseBase
{
	public:
		UnitTest_MyTestCase3():UnitTest_MyTestCaseBase("UnitTest_MyTestCase3"){}
};
SVUT_REGISTER_TEST_CASE(UnitTest_MyTestCase3);

/*******************  FUNCTION  *********************/
UnitTest_MyTestCaseBase::UnitTest_MyTestCaseBase(string name)
	:svutTestCase(name)
{
	hasCallTest = false;
}

/*******************  FUNCTION  *********************/
void UnitTest_MyTestCaseBase::testMethodsRegistration(void )
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
int main(int argc, char * argv[])
{
	return svUnitTest::defaultMain(argc,argv);
}

SVUT_FAKE_DECLARE_GLOBAL_VARS
