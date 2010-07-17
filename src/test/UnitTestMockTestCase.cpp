/*****************************************************
             PROJECT  : svUnitTest
             VERSION  : 0.0.2
             DATE     : 06/2010
             AUTHOR   : Valat Sébastien
             LICENSE  : CeCILL-C
*****************************************************/

/********************  HEADERS  *********************/
#include "UnitTestMockTestCase.h"


/********************  METHODE  *********************/
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

/********************  METHODE  *********************/
void UnitTestMockTestCase::setUp(void)
{
	setup = calls++;
}

/********************  METHODE  *********************/
void UnitTestMockTestCase::tearDown(void)
{
	teardown = calls++;
}

/********************  METHODE  *********************/
void UnitTestMockTestCase::test1(void )
{
	t1 = calls ++;
}

/********************  METHODE  *********************/
void UnitTestMockTestCase::test2(void )
{
	t2 = calls ++;
}

/********************  METHODE  *********************/
void UnitTestMockTestCase::test3(void)
{
	t3 = calls ++;
}

/********************  METHODE  *********************/
void UnitTestMockTestCase::testRegister(void)
{
	SVUT_REG_TEST_METHOD(UnitTestMockTestCase,test2);
}

/********************  METHODE  *********************/
void UnitTestMockTestCase::testRunMeth(void)
{
	this->runTestMethod(*(tests.begin()));
}
