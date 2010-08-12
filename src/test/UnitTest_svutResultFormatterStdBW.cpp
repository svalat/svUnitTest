/*****************************************************
             PROJECT  : svUnitTest
             VERSION  : 0.0.2
             DATE     : 06/2010
             AUTHOR   : Valat Sébastien
             LICENSE  : CeCILL-C
*****************************************************/

/********************  HEADERS  *********************/
#include "UnitTestExtra.h"
#include <iostream>
#include <cppunit/TestCase.h>
#include <cppunit/extensions/TestFactoryRegistry.h>
#include <cppunit/extensions/HelperMacros.h>
#include <svutResultFormatterStdBW.h>
#include "UnitTestMockTestCase.h"

using namespace std;
using namespace svUnitTest;
using namespace CPPUNIT_NS;

/********************  CONSTS  ***********************/
static const char * SUMMARY_0 = "\n\
+---------------------------+\n\
|    SUMMARY                |\n\
+---------------------------+\n\
|  SUCCESS  :    0 (  0 %)  |\n\
|  INDEV    :    0 (  0 %)  |\n\
|  TODO     :    0 (  0 %)  |\n\
|  FAILED   :    0 (  0 %)  |\n\
|  UNKNOWN  :    0 (  0 %)  |\n\
+---------------------------+\n\
|  TOTAL    :    0          |\n\
|  STATUS   : SUCCESS       |\n\
+---------------------------+\n";

/********************  CLASSE  **********************/
class UnitTest_svutResultFormatterStdBW : public TestCase
{
	CPPUNIT_TEST_SUITE(UnitTest_svutResultFormatterStdBW);
	CPPUNIT_TEST(testOpenOutput);
	CPPUNIT_TEST(testCloseOutput);
	CPPUNIT_TEST(testOpenTestCase);
	CPPUNIT_TEST(testCloseTestCase);
	CPPUNIT_TEST(testOpenTestMethod);
	CPPUNIT_TEST(testCloseTestMethod_1);
	CPPUNIT_TEST(testCloseTestMethod_2);
	CPPUNIT_TEST(testCloseTestMethod_3);
	CPPUNIT_TEST(testCloseTestMethod_4);
	CPPUNIT_TEST(testCloseTestMethod_5);
	CPPUNIT_TEST(testCloseTestMethod_6);
	CPPUNIT_TEST(testCloseTestMethod_7);
	CPPUNIT_TEST(testPrintSummary);
	CPPUNIT_TEST(testGlobal_1);
	CPPUNIT_TEST(testGlobal_2);
	CPPUNIT_TEST_SUITE_END();

	public:
		void setUp(void);
		void tearDown(void);

		void testOpenOutput(void);
		void testCloseOutput(void);
		void testOpenTestCase(void);
		void testCloseTestCase(void);
		void testOpenTestMethod(void);
		void testCloseTestMethod_1(void);
		void testCloseTestMethod_2(void);
		void testCloseTestMethod_3(void);
		void testCloseTestMethod_4(void);
		void testCloseTestMethod_5(void);
		void testCloseTestMethod_6(void);
		void testCloseTestMethod_7(void);
		void testPrintSummary(void);
		void testGlobal_1(void);
		void testGlobal_2(void);
	protected:
		svutResultFormatterStdBW * formatter;
		stringstream * out;
};

/********************  METHODE  *********************/
void UnitTest_svutResultFormatterStdBW::setUp(void)
{
	out = new stringstream;
	formatter = new svutResultFormatterStdBW(*out);
}

/********************  METHODE  *********************/
void UnitTest_svutResultFormatterStdBW::tearDown(void)
{
	delete formatter;
	delete out;
}

/********************  METHODE  *********************/
void UnitTest_svutResultFormatterStdBW::testCloseOutput(void )
{
	formatter->closeOutput();
	CPPUNIT_ASSERT_EQUAL("",out->str());
}

/********************  METHODE  *********************/
void UnitTest_svutResultFormatterStdBW::testCloseTestCase(void )
{
	UnitTestMockTestCase testCase;
	formatter->closeTestCase(testCase);
	CPPUNIT_ASSERT_EQUAL("",out->str());
}

/********************  METHODE  *********************/
void UnitTest_svutResultFormatterStdBW::testCloseTestMethod_1(void )
{
	CPPUNIT_FAIL("todo");
}

/********************  METHODE  *********************/
void UnitTest_svutResultFormatterStdBW::testCloseTestMethod_2(void )
{
	CPPUNIT_FAIL("todo");
}

/********************  METHODE  *********************/
void UnitTest_svutResultFormatterStdBW::testCloseTestMethod_3(void )
{
	CPPUNIT_FAIL("todo");
}

/********************  METHODE  *********************/
void UnitTest_svutResultFormatterStdBW::testCloseTestMethod_4(void )
{
	CPPUNIT_FAIL("todo");
}

/********************  METHODE  *********************/
void UnitTest_svutResultFormatterStdBW::testCloseTestMethod_5(void )
{
	CPPUNIT_FAIL("todo");
}

/********************  METHODE  *********************/
void UnitTest_svutResultFormatterStdBW::testCloseTestMethod_6(void )
{
	CPPUNIT_FAIL("todo");
}

/********************  METHODE  *********************/
void UnitTest_svutResultFormatterStdBW::testCloseTestMethod_7(void )
{
	CPPUNIT_FAIL("todo");
}

/********************  METHODE  *********************/
void UnitTest_svutResultFormatterStdBW::testGlobal_1(void )
{
	CPPUNIT_FAIL("todo");
}

/********************  METHODE  *********************/
void UnitTest_svutResultFormatterStdBW::testGlobal_2(void )
{
	CPPUNIT_FAIL("todo");
}

/********************  METHODE  *********************/
void UnitTest_svutResultFormatterStdBW::testOpenOutput(void )
{
	formatter->openOutput();
	CPPUNIT_ASSERT_EQUAL("",out->str());
}

/********************  METHODE  *********************/
void UnitTest_svutResultFormatterStdBW::testOpenTestCase(void )
{
	UnitTestMockTestCase testCase;
	formatter->openTestCase(testCase);
	CPPUNIT_ASSERT_EQUAL("=======  MyTest                                   ========\n",out->str());
}

/********************  METHODE  *********************/
void UnitTest_svutResultFormatterStdBW::testOpenTestMethod(void )
{
	UnitTestMockTestCase testCase;
	svutTestMethod meth("testMethod",NULL,SVUT_CODE_LOCATION);
	formatter->openTestMethod(testCase,meth);
	CPPUNIT_ASSERT_EQUAL("",out->str());
}

/********************  METHODE  *********************/
void UnitTest_svutResultFormatterStdBW::testPrintSummary(void )
{
	svutResultSummary summary;
	formatter->printSummary(summary);
	CPPUNIT_ASSERT_EQUAL(SUMMARY_0,out->str());
}

CPPUNIT_TEST_SUITE_REGISTRATION(UnitTest_svutResultFormatterStdBW);
