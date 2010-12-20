/*****************************************************
             PROJECT  : svUnitTest
             VERSION  : 0.0.2
             DATE     : 12/2010
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

using namespace CPPUNIT_NS;
using namespace svUnitTest;

/********************  CLASSE  **********************/
class UnitTest_svutAutoRegister : public TestCase
{
	CPPUNIT_TEST_SUITE(UnitTest_svutAutoRegister);
	CPPUNIT_TEST(testRegister);
	CPPUNIT_TEST(testGetList);
	CPPUNIT_TEST(testClear);
	CPPUNIT_TEST_SUITE_END();

	public:
		void setUp(void);
		void tearDown(void);

	protected:
		void testRegister(void);
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
	CPPUNIT_ASSERT_EQUAL(0,getRegistredTestCase().size());
	registerTestCase(test);
	CPPUNIT_ASSERT_EQUAL(1,getRegistredTestCase().size());

	const std::list<svUnitTest::svutTestCaseBuilder *> lst = getRegistredTestCase();
	SVUT_ASSERT_EQUAL(&test,*lst.begin());
}

/********************  METHODE  *********************/
void UnitTest_svutAutoRegister::testRegister(void )
{
	svutTestCaseBuilderGeneric<UnitTestMockTestCase2>  test;
	CPPUNIT_ASSERT_EQUAL(0,getRegistredTestCase().size());
	registerTestCase(test);
	CPPUNIT_ASSERT_EQUAL(1,getRegistredTestCase().size());
}

/********************  METHODE  *********************/
void UnitTest_svutAutoRegister::testClear(void )
{
	svutTestCaseBuilderGeneric<UnitTestMockTestCase2>  test;
	CPPUNIT_ASSERT_EQUAL(0,getRegistredTestCase().size());
	registerTestCase(test);
	CPPUNIT_ASSERT_EQUAL(1,getRegistredTestCase().size());
	clearTestCaseRegister();
	CPPUNIT_ASSERT_EQUAL(0,getRegistredTestCase().size());
}


CPPUNIT_TEST_SUITE_REGISTRATION(UnitTest_svutAutoRegister);
