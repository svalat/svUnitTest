/*****************************************************
             PROJECT  : svUnitTest
             VERSION  : 0.0.2
             DATE     : 06/2010
             AUTHOR   : Valat Sébastien
             LICENSE  : CeCILL-C
*****************************************************/

/********************  HEADERS  *********************/
#include <iostream>
#include <cppunit/TestCase.h>
#include <cppunit/extensions/TestFactoryRegistry.h>
#include <cppunit/extensions/HelperMacros.h>

using namespace CPPUNIT_NS;

/********************  CLASSE  **********************/
class UnitTest_svutRunner : public TestCase
{
	CPPUNIT_TEST_SUITE(UnitTest_svutRunner);
	CPPUNIT_TEST(testConstructor_default);
	CPPUNIT_TEST(testConstructor_mode);
	CPPUNIT_TEST(testConstructor_formatter);
	CPPUNIT_TEST(testConstructor_listener);
	CPPUNIT_TEST(testConstructor_config);
	CPPUNIT_TEST(testRun);
	CPPUNIT_TEST(testSetDisplay);
	CPPUNIT_TEST(testLoadAutoDetected);
	CPPUNIT_TEST(testUnloadAutoDetected);
	CPPUNIT_TEST(testRegisterTestCase);
	CPPUNIT_TEST_SUITE_END();

	public:
		void setUp(void);
		void tearDown(void);
	protected:
		void testConstructor_default(void);
		void testConstructor_mode(void);
		void testConstructor_formatter(void);
		void testConstructor_listener(void);
		void testConstructor_config(void);
		void testRun(void);
		void testSetDisplay(void);
		void testLoadAutoDetected(void);
		void testUnloadAutoDetected(void);
		void testRegisterTestCase(void);
};

/********************  METHODE  *********************/
void UnitTest_svutRunner::setUp(void)
{
}

/********************  METHODE  *********************/
void UnitTest_svutRunner::tearDown(void)
{
}

/********************  METHODE  *********************/
void UnitTest_svutRunner::testConstructor_default(void)
{
	CPPUNIT_FAIL("todo");
}

/********************  METHODE  *********************/
void UnitTest_svutRunner::testConstructor_mode(void)
{
	CPPUNIT_FAIL("todo");
}

/********************  METHODE  *********************/
void UnitTest_svutRunner::testConstructor_formatter(void)
{
	CPPUNIT_FAIL("todo");
}

/********************  METHODE  *********************/
void UnitTest_svutRunner::testConstructor_listener(void)
{
	CPPUNIT_FAIL("todo");
}

/********************  METHODE  *********************/
void UnitTest_svutRunner::testConstructor_config(void)
{
	CPPUNIT_FAIL("todo");
}

/********************  METHODE  *********************/
void UnitTest_svutRunner::testRun(void)
{
	CPPUNIT_FAIL("todo");
}

/********************  METHODE  *********************/
void UnitTest_svutRunner::testSetDisplay(void)
{
	CPPUNIT_FAIL("todo");
}

/********************  METHODE  *********************/
void UnitTest_svutRunner::testLoadAutoDetected(void)
{
	CPPUNIT_FAIL("todo");
}

/********************  METHODE  *********************/
void UnitTest_svutRunner::testUnloadAutoDetected(void)
{
	CPPUNIT_FAIL("todo");
}

/********************  METHODE  *********************/
void UnitTest_svutRunner::testRegisterTestCase(void)
{
	CPPUNIT_FAIL("todo");
}

CPPUNIT_TEST_SUITE_REGISTRATION(UnitTest_svutRunner);
