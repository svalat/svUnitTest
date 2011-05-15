/*****************************************************
             PROJECT  : svUnitTest
             VERSION  : 0.3.0
             DATE     : 05/2011
             AUTHOR   : Valat Sébastien
             LICENSE  : CeCILL-C
*****************************************************/

/********************  HEADERS  *********************/
#include <iostream>
#include <cppunit/TestCase.h>
#include <cppunit/extensions/TestFactoryRegistry.h>
#include <cppunit/extensions/HelperMacros.h>
#include <svutAutoRegister.h>
#include <svutTestCaseBuilder.h>
#include "UnitTestExtra.h"
#include "UnitTestMockTestCase2.h"

/**********************  USING  *********************/
using namespace CPPUNIT_NS;
using namespace svUnitTest;

/********************  CLASSE  **********************/
class UnitTest_svutAutoRegister : public TestCase
{
	CPPUNIT_TEST_SUITE(UnitTest_svutAutoRegister);
	CPPUNIT_TEST(testRegister);
	CPPUNIT_TEST(testRegister_multiple_1);
	CPPUNIT_TEST(testRegister_multiple_2);
	CPPUNIT_TEST(testGetList);
	CPPUNIT_TEST(testClear);
	CPPUNIT_TEST_SUITE_END();

	public:
		void setUp(void);
		void tearDown(void);

	protected:
		void testRegister(void);
		void testRegister_multiple_1(void);
		void testRegister_multiple_2(void);
		void testGetList(void);
		void testClear(void);
};

/********************  METHODE  *********************/
void UnitTest_svutAutoRegister::setUp(void)
{
}

/********************  METHODE  *********************/
void UnitTest_svutAutoRegister::tearDown(void)
{
	clearTestCaseRegister();
}

/********************  METHODE  *********************/
void UnitTest_svutAutoRegister::testGetList(void )
{
	svutTestCaseBuilderGeneric<UnitTestMockTestCase2> test;
	CPPUNIT_ASSERT_EQUAL(0u,getRegistredTestCase().size());
	registerTestCase(test);
	CPPUNIT_ASSERT_EQUAL(1u,getRegistredTestCase().size());

	const std::set<svUnitTest::svutTestCaseBuilder *> lst = getRegistredTestCase();
	CPPUNIT_ASSERT(&test == *lst.begin());
}

/********************  METHODE  *********************/
void UnitTest_svutAutoRegister::testRegister(void )
{
	svutTestCaseBuilderGeneric<UnitTestMockTestCase2>  test;
	CPPUNIT_ASSERT_EQUAL(0u,getRegistredTestCase().size());
	registerTestCase(test);
	CPPUNIT_ASSERT_EQUAL(1u,getRegistredTestCase().size());
}

/********************  METHODE  *********************/
void UnitTest_svutAutoRegister::testRegister_multiple_1(void )
{
	svutTestCaseBuilderGeneric<UnitTestMockTestCase2>  test;
	CPPUNIT_ASSERT_EQUAL(0u,getRegistredTestCase().size());
	registerTestCase(test);
	registerTestCase(test);
	CPPUNIT_ASSERT_EQUAL(1u,getRegistredTestCase().size());
}

/********************  METHODE  *********************/
void UnitTest_svutAutoRegister::testRegister_multiple_2(void )
{
	svutTestCaseBuilderGeneric<UnitTestMockTestCase2>  test;
	svutTestCaseBuilderGeneric<UnitTestMockTestCase2>  test2;
	CPPUNIT_ASSERT_EQUAL(0u,getRegistredTestCase().size());
	registerTestCase(test);
	registerTestCase(test2);
	CPPUNIT_ASSERT_EQUAL(2u,getRegistredTestCase().size());
}

/********************  METHODE  *********************/
void UnitTest_svutAutoRegister::testClear(void )
{
	svutTestCaseBuilderGeneric<UnitTestMockTestCase2>  test;
	CPPUNIT_ASSERT_EQUAL(0u,getRegistredTestCase().size());
	registerTestCase(test);
	CPPUNIT_ASSERT_EQUAL(1u,getRegistredTestCase().size());
	clearTestCaseRegister();
	CPPUNIT_ASSERT_EQUAL(0u,getRegistredTestCase().size());
}


CPPUNIT_TEST_SUITE_REGISTRATION(UnitTest_svutAutoRegister);
