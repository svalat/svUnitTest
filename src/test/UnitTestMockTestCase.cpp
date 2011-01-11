/*****************************************************
             PROJECT  : svUnitTest
             VERSION  : 0.0.2
             DATE     : 06/2010
             AUTHOR   : Valat Sébastien
             LICENSE  : CeCILL-C
*****************************************************/

/********************  HEADERS  *********************/
#include "UnitTestMockTestCase.h"


/*******************  FUNCTION  *********************/
UnitTestMockTestCase::UnitTestMockTestCase(void ):
	svutTestCase("MyTest")
{
	calls = 0;
	setup = -1;
	teardown = -1;
	t1 = -1;
	t2 = -1;
	t3 = -1;
	SVUT_REG_TEST_METHOD(UnitTestMockTestCase,test1);
	SVUT_REG_TEST_METHOD(UnitTestMockTestCase,test3);
}

/*******************  FUNCTION  *********************/
void UnitTestMockTestCase::setUp(void)
{
	setup = calls++;
}

/*******************  FUNCTION  *********************/
void UnitTestMockTestCase::tearDown(void)
{
	teardown = calls++;
}

/*******************  FUNCTION  *********************/
void UnitTestMockTestCase::test1(void )
{
	t1 = calls ++;
}

/*******************  FUNCTION  *********************/
void UnitTestMockTestCase::test2(void )
{
	t2 = calls ++;
}

/*******************  FUNCTION  *********************/
void UnitTestMockTestCase::test3(void)
{
	t3 = calls ++;
}

/*******************  FUNCTION  *********************/
void UnitTestMockTestCase::testRegister(void)
{
	SVUT_REG_TEST_METHOD(UnitTestMockTestCase,test2);
}

/*******************  FUNCTION  *********************/
void UnitTestMockTestCase::testRunMeth(void)
{
	this->runTestMethod(*(tests.begin()));
}
