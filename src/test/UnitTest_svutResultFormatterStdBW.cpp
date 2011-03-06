/*****************************************************
             PROJECT  : svUnitTest
             VERSION  : 0.3.0-dev
             DATE     : 03/2011
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
#include <sys/stat.h>

/**********************  USING  *********************/
using namespace std;
using namespace svUnitTest;
using namespace CPPUNIT_NS;

/********************  CONSTS  ***********************/
static const char * CST_STRING_SUMMARY_0 = "\n\
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
static const char * CST_STRING_UNKNOWN_1 =
" * testMethod                                   [ UNKNOWN ]\n\
- - - - - - - - - - - - - - - - - - - - - - - - - - - - - -\n\
\n\
unknown location\n\
- - - - - - - - - - - - - - - - - - - - - - - - - - - - - -\n";
static const char * CST_STRING_UNKNOWN_3 = " * testMethod                                   [ UNKNOWN ]\n\
- - - - - - - - - - - - - - - - - - - - - - - - - - - - - -\n\
message for unknown status\n\
line 33 of file file.cpp on methode methode()\n\
- - - - - - - - - - - - - - - - - - - - - - - - - - - - - -\n";
static const char * CST_STRING_UNKNOWN_2 = " * testMethod                                   [ UNKNOWN ]\n";
static const char * CST_STRING_SUCCESS_1 = " * testMethod                                   [ SUCCESS ]\n";
static const char * CST_STRING_SUCCESS_2 = " * MyTest:testMethod                            [ SUCCESS ]\n";
static const char * CST_STRING_TODO      = " * testMethod                                   [ TODO ]\n";
static const char * CST_STRING_INDEV     = " * testMethod                                   [ INDEV ]\n";
static const char * CST_STRING_SKIPED    = " * testMethod                                   [ SKIPED ]\n";
static const char * CST_STRING_TEST_CASE = "=======  MyTest                                   ========\n";
static const char * CST_STRING_FAILED_2  = " * testMethod                                   [ FAILED ]\n";
static const char * CST_STRING_FAILED_1  = " * testMethod                                   [ FAILED ]\n\
- - - - - - - - - - - - - - - - - - - - - - - - - - - - - -\n\
message for failed status\n\
line 33 of file file.cpp on methode methode()\n\
   - actual : duck\n\
   - expected : toto\n\
- - - - - - - - - - - - - - - - - - - - - - - - - - - - - -\n";
static const char * CST_STRING_SEQ_1    = "=======  MyTest                                   ========\n\
 * testMethod                                   [ TODO ]\n\
 * testMethod                                   [ INDEV ]\n\
=======  MyTest                                   ========\n\
 * testMethod                                   [ SKIPED ]\n\
 * testMethod                                   [ FAILED ]\n\
- - - - - - - - - - - - - - - - - - - - - - - - - - - - - -\n\
message for unknown status\n\
line 33 of file file.cpp on methode methode()\n\
   - actual : duck\n\
   - expected : toto\n\
- - - - - - - - - - - - - - - - - - - - - - - - - - - - - -\n\
=======  MyTest                                   ========\n\
 * testMethod                                   [ UNKNOWN ]\n\
- - - - - - - - - - - - - - - - - - - - - - - - - - - - - -\n\
message for unknown status\n\
line 33 of file file.cpp on methode methode()\n\
- - - - - - - - - - - - - - - - - - - - - - - - - - - - - -\n\n\
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
static const char * CST_STRING_SEQ_2    = "=======  MyTest                                   ========\n\
 * testMethod                                   [ SUCCESS ]\n\
 * testMethod                                   [ TODO ]\n\
 * testMethod                                   [ SUCCESS ]\n\
 * testMethod                                   [ INDEV ]\n\
=======  MyTest                                   ========\n\
 * testMethod                                   [ SKIPED ]\n\
 * testMethod                                   [ SUCCESS ]\n\
 * testMethod                                   [ FAILED ]\n\
=======  MyTest                                   ========\n\
 * testMethod                                   [ UNKNOWN ]\n\n\
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

/*********************  CLASS  **********************/
class UnitTest_svutResultFormatterStdBW : public TestCase
{
	CPPUNIT_TEST_SUITE(UnitTest_svutResultFormatterStdBW);
	CPPUNIT_TEST(testOpenOutput);
	CPPUNIT_TEST(testCloseOutput);
	CPPUNIT_TEST(testOpenTestCase);
	CPPUNIT_TEST(testCloseTestCase);
	CPPUNIT_TEST(testOpenTestMethod);
	CPPUNIT_TEST(testCloseTestMethod_success_1);
	CPPUNIT_TEST(testCloseTestMethod_success_2);
	CPPUNIT_TEST(testCloseTestMethod_fullname);
	CPPUNIT_TEST(testCloseTestMethod_todo);
	CPPUNIT_TEST(testCloseTestMethod_indev);
	CPPUNIT_TEST(testCloseTestMethod_skiped);
	CPPUNIT_TEST(testCloseTestMethod_unknown_1);
	CPPUNIT_TEST(testCloseTestMethod_unknown_2);
	CPPUNIT_TEST(testCloseTestMethod_unknown_3);
	CPPUNIT_TEST(testCloseTestMethod_failed_1);
	CPPUNIT_TEST(testCloseTestMethod_failed_2);
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
		void testCloseTestMethod_success_1(void);
		void testCloseTestMethod_success_2(void);
		void testCloseTestMethod_fullname(void);
		void testCloseTestMethod_todo(void);
		void testCloseTestMethod_indev(void);
		void testCloseTestMethod_skiped(void);
		void testCloseTestMethod_unknown_1(void);
		void testCloseTestMethod_unknown_2(void);
		void testCloseTestMethod_unknown_3(void);
		void testCloseTestMethod_failed_1(void);
		void testCloseTestMethod_failed_2(void);
		void testPrintSummary(void);
		void testGlobal_1(void);
		void testGlobal_2(void);
	protected:
		void runTotalSequence(void);
		svutResultFormatterStdBW * formatter;
		stringstream * out;
};

/*******************  FUNCTION  *********************/
void UnitTest_svutResultFormatterStdBW::setUp(void)
{
	out = new stringstream;
	formatter = new svutResultFormatterStdBW(*out);
}

/*******************  FUNCTION  *********************/
void UnitTest_svutResultFormatterStdBW::tearDown(void)
{
	delete formatter;
	delete out;
}

/*******************  FUNCTION  *********************/
void UnitTest_svutResultFormatterStdBW::testCloseOutput(void )
{
	formatter->closeOutput();
	CPPUNIT_ASSERT_EQUAL("",out->str());
}

/*******************  FUNCTION  *********************/
void UnitTest_svutResultFormatterStdBW::testCloseTestCase(void )
{
	UnitTestMockTestCase testCase;
	formatter->closeTestCase(testCase);
	CPPUNIT_ASSERT_EQUAL("",out->str());
}

/*******************  FUNCTION  *********************/
void UnitTest_svutResultFormatterStdBW::testCloseTestMethod_success_1(void )
{
	UnitTestMockTestCase testCase;
	svutTestMethod meth("testMethod",NULL,SVUT_NO_LOCATION);
	formatter->closeTestMethod(testCase,meth,SVUT_STATUS_SUCCESS);
	CPPUNIT_ASSERT_EQUAL("",out->str());
}

/*******************  FUNCTION  *********************/
void UnitTest_svutResultFormatterStdBW::testCloseTestMethod_success_2(void )
{
	UnitTestMockTestCase testCase;
	svutTestMethod meth("testMethod",NULL,SVUT_NO_LOCATION);
	formatter->setDisplaySuccess(true);
	formatter->closeTestMethod(testCase,meth,SVUT_STATUS_SUCCESS);
	CPPUNIT_ASSERT_EQUAL(CST_STRING_SUCCESS_1,out->str());
}

/*******************  FUNCTION  *********************/
void UnitTest_svutResultFormatterStdBW::testCloseTestMethod_fullname(void )
{
	UnitTestMockTestCase testCase;
	svutTestMethod meth("testMethod",NULL,SVUT_NO_LOCATION);
	formatter->setDisplaySuccess(true);
	formatter->setDisplayFullName(true);
	formatter->closeTestMethod(testCase,meth,SVUT_STATUS_SUCCESS);
	CPPUNIT_ASSERT_EQUAL(CST_STRING_SUCCESS_2,out->str());
}

/*******************  FUNCTION  *********************/
void UnitTest_svutResultFormatterStdBW::testCloseTestMethod_todo(void )
{
	UnitTestMockTestCase testCase;
	svutTestMethod meth("testMethod",NULL,SVUT_NO_LOCATION);
	formatter->closeTestMethod(testCase,meth,SVUT_STATUS_TODO);
	CPPUNIT_ASSERT_EQUAL(CST_STRING_TODO,out->str());
}

/*******************  FUNCTION  *********************/
void UnitTest_svutResultFormatterStdBW::testCloseTestMethod_indev(void )
{
	UnitTestMockTestCase testCase;
	svutTestMethod meth("testMethod",NULL,SVUT_NO_LOCATION);
	formatter->closeTestMethod(testCase,meth,SVUT_STATUS_INDEV);
	CPPUNIT_ASSERT_EQUAL(CST_STRING_INDEV,out->str());
}

/*******************  FUNCTION  *********************/
void UnitTest_svutResultFormatterStdBW::testCloseTestMethod_skiped(void )
{
	UnitTestMockTestCase testCase;
	svutTestMethod meth("testMethod",NULL,SVUT_NO_LOCATION);
	formatter->closeTestMethod(testCase,meth,SVUT_STATUS_SKIPED);
	CPPUNIT_ASSERT_EQUAL(CST_STRING_SKIPED,out->str());
}

/*******************  FUNCTION  *********************/
void UnitTest_svutResultFormatterStdBW::testCloseTestMethod_unknown_1(void )
{
	UnitTestMockTestCase testCase;
	svutTestMethod meth("testMethod",NULL,SVUT_NO_LOCATION);
	formatter->closeTestMethod(testCase,meth,SVUT_STATUS_UNKNOWN);
	CPPUNIT_ASSERT_EQUAL(CST_STRING_UNKNOWN_1,out->str());
}

/*******************  FUNCTION  *********************/
void UnitTest_svutResultFormatterStdBW::testCloseTestMethod_unknown_2(void )
{
	UnitTestMockTestCase testCase;
	svutTestMethod meth("testMethod",NULL,SVUT_NO_LOCATION);
	formatter->setDisplayDetails(false);
	formatter->closeTestMethod(testCase,meth,SVUT_STATUS_UNKNOWN);
	CPPUNIT_ASSERT_EQUAL(CST_STRING_UNKNOWN_2,out->str());
}

/*******************  FUNCTION  *********************/
void UnitTest_svutResultFormatterStdBW::testCloseTestMethod_unknown_3(void )
{
	UnitTestMockTestCase testCase;
	svutTestMethod meth("testMethod",NULL,SVUT_NO_LOCATION);
	svutCodeLocation location("file.cpp","methode",33);
	svutStatusInfo info(SVUT_STATUS_UNKNOWN,"message for unknown status",location);
	formatter->closeTestMethod(testCase,meth,info);
	CPPUNIT_ASSERT_EQUAL(CST_STRING_UNKNOWN_3,out->str());
}

/*******************  FUNCTION  *********************/
void UnitTest_svutResultFormatterStdBW::testCloseTestMethod_failed_1(void )
{
	UnitTestMockTestCase testCase;
	svutTestMethod meth("testMethod",NULL,SVUT_NO_LOCATION);
	svutCodeLocation location("file.cpp","methode",33);
	svutStatusInfo info(SVUT_STATUS_FAILED,"message for failed status",location);
	info.addEntry("expected","toto");
	info.addEntry("actual","duck");
	formatter->closeTestMethod(testCase,meth,info);
	CPPUNIT_ASSERT_EQUAL(CST_STRING_FAILED_1,out->str());
}

/*******************  FUNCTION  *********************/
void UnitTest_svutResultFormatterStdBW::testCloseTestMethod_failed_2(void )
{
	UnitTestMockTestCase testCase;
	svutTestMethod meth("testMethod",NULL,SVUT_NO_LOCATION);
	svutCodeLocation location("file.cpp","methode",33);
	svutStatusInfo info(SVUT_STATUS_FAILED,"message for failed status",location);
	info.addEntry("expected","toto");
	info.addEntry("actual","duck");
	formatter->setDisplayDetails(false);
	formatter->closeTestMethod(testCase,meth,info);
	CPPUNIT_ASSERT_EQUAL(CST_STRING_FAILED_2,out->str());
}

/*******************  FUNCTION  *********************/
void UnitTest_svutResultFormatterStdBW::runTotalSequence(void )
{
	UnitTestMockTestCase testCase;
	svutCodeLocation location("file.cpp","methode",33);
	svutTestMethod meth("testMethod",NULL,location);
	svutStatusInfo infoFailed(SVUT_STATUS_FAILED,"message for unknown status",location);
	infoFailed.addEntry("expected","toto");
	infoFailed.addEntry("actual","duck");
	svutStatusInfo infoUnknown(SVUT_STATUS_UNKNOWN,"message for unknown status",location);
	svutResultSummary summary;

	formatter->openOutput();

	formatter->openTestCase(testCase);

	formatter->openTestMethod(testCase,meth);
	formatter->closeTestMethod(testCase,meth,SVUT_STATUS_SUCCESS);

	formatter->openTestMethod(testCase,meth);
	formatter->closeTestMethod(testCase,meth,SVUT_STATUS_TODO);

	formatter->openTestMethod(testCase,meth);
	formatter->closeTestMethod(testCase,meth,SVUT_STATUS_SUCCESS);

	formatter->openTestMethod(testCase,meth);
	formatter->closeTestMethod(testCase,meth,SVUT_STATUS_INDEV);

	formatter->closeTestCase(testCase);

	formatter->openTestCase(testCase);

	formatter->openTestMethod(testCase,meth);
	formatter->closeTestMethod(testCase,meth,SVUT_STATUS_SKIPED);

	formatter->openTestMethod(testCase,meth);
	formatter->closeTestMethod(testCase,meth,SVUT_STATUS_SUCCESS);

	formatter->openTestMethod(testCase,meth);
	formatter->closeTestMethod(testCase,meth,infoFailed);

	formatter->openTestCase(testCase);
	formatter->closeTestMethod(testCase,meth,infoUnknown);

	formatter->closeTestCase(testCase);
	
	formatter->printSummary(summary);
	
	formatter->closeOutput();
}


/*******************  FUNCTION  *********************/
void UnitTest_svutResultFormatterStdBW::testGlobal_1(void )
{
	this->runTotalSequence();
	CPPUNIT_ASSERT_EQUAL(CST_STRING_SEQ_1,out->str());
}

/*******************  FUNCTION  *********************/
void UnitTest_svutResultFormatterStdBW::testGlobal_2(void )
{
	formatter->setDisplaySuccess(true);
	formatter->setDisplayDetails(false);
	this->runTotalSequence();
	CPPUNIT_ASSERT_EQUAL(CST_STRING_SEQ_2,out->str());
}

/*******************  FUNCTION  *********************/
void UnitTest_svutResultFormatterStdBW::testOpenOutput(void )
{
	formatter->openOutput();
	CPPUNIT_ASSERT_EQUAL("",out->str());
}

/*******************  FUNCTION  *********************/
void UnitTest_svutResultFormatterStdBW::testOpenTestCase(void )
{
	UnitTestMockTestCase testCase;
	formatter->openTestCase(testCase);
	CPPUNIT_ASSERT_EQUAL(CST_STRING_TEST_CASE,out->str());
}

/*******************  FUNCTION  *********************/
void UnitTest_svutResultFormatterStdBW::testOpenTestMethod(void )
{
	UnitTestMockTestCase testCase;
	svutTestMethod meth("testMethod",NULL,SVUT_CODE_LOCATION);
	formatter->openTestMethod(testCase,meth);
	CPPUNIT_ASSERT_EQUAL("",out->str());
}

/*******************  FUNCTION  *********************/
void UnitTest_svutResultFormatterStdBW::testPrintSummary(void )
{
	svutResultSummary summary;
	formatter->printSummary(summary);
	CPPUNIT_ASSERT_EQUAL(CST_STRING_SUMMARY_0,out->str());
}

CPPUNIT_TEST_SUITE_REGISTRATION(UnitTest_svutResultFormatterStdBW);
