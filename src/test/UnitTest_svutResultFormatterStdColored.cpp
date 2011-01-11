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
#include <svutResultFormatterStdColored.h>
#include "UnitTestMockTestCase.h"
#include <sys/stat.h>

using namespace std;
using namespace svUnitTest;
using namespace CPPUNIT_NS;

/********************  CONSTS  ***********************/
static const char * CST_STRING_SUMMARY_0 = "\n\
+---------------------------+\n\
|    SUMMARY                |\n\
+---------------------------+\n\
|  \e[32mSUCCESS  :    0 (  0 %)\e[0m  |\n\
|  \e[34mINDEV    :    0 (  0 %)\e[0m  |\n\
|  \e[33mTODO     :    0 (  0 %)\e[0m  |\n\
|  \e[31mFAILED   :    0 (  0 %)\e[0m  |\n\
|  \e[31mUNKNOWN  :    0 (  0 %)\e[0m  |\n\
+---------------------------+\n\
|  TOTAL    :    0          |\n\
|  STATUS   : \e[32mSUCCESS     \e[0m  |\n\
+---------------------------+\n";
static const char * CST_STRING_UNKNOWN_1 =
"\e[32m * \e[0mtestMethod                                   [ \e[31mUNKNOWN\e[0m ]\n\
- - - - - - - - - - - - - - - - - - - - - - - - - - - - - -\n\
\n\
unknown location\n\
- - - - - - - - - - - - - - - - - - - - - - - - - - - - - -\n";
static const char * CST_STRING_UNKNOWN_3 = "\e[32m * \e[0mtestMethod                                   [ \e[31mUNKNOWN\e[0m ]\n\
- - - - - - - - - - - - - - - - - - - - - - - - - - - - - -\n\
message for unknown status\n\
line 33 of file file.cpp on methode methode()\n\
- - - - - - - - - - - - - - - - - - - - - - - - - - - - - -\n";
static const char * CST_STRING_UNKNOWN_2 = "\e[32m * \e[0mtestMethod                                   [ \e[31mUNKNOWN\e[0m ]\n";
static const char * CST_STRING_SUCCESS_1 = "\e[32m * \e[0mtestMethod                                   [ \e[32mSUCCESS\e[0m ]\n";
static const char * CST_STRING_SUCCESS_2 = "\e[32m * \e[0mMyTest:testMethod                            [ \e[32mSUCCESS\e[0m ]\n";
static const char * CST_STRING_TODO      = "\e[32m * \e[0mtestMethod                                   [ \e[33mTODO\e[0m ]\n";
static const char * CST_STRING_INDEV     = "\e[32m * \e[0mtestMethod                                   [ \e[34mINDEV\e[0m ]\n";
static const char * CST_STRING_SKIPED    = "\e[32m * \e[0mtestMethod                                   [ \e[33mSKIPED\e[0m ]\n";
static const char * CST_STRING_TEST_CASE = "=======  MyTest                                   ========\n";
static const char * CST_STRING_FAILED_2  = "\e[32m * \e[0mtestMethod                                   [ \e[31mFAILED\e[0m ]\n";
static const char * CST_STRING_FAILED_1  = "\e[32m * \e[0mtestMethod                                   [ \e[31mFAILED\e[0m ]\n\
- - - - - - - - - - - - - - - - - - - - - - - - - - - - - -\n\
message for failed status\n\
line 33 of file file.cpp on methode methode()\n\
   - actual : duck\n\
   - expected : toto\n\
- - - - - - - - - - - - - - - - - - - - - - - - - - - - - -\n";
static const char * CST_STRING_SEQ_1    = "=======  MyTest                                   ========\n\
\e[32m * \e[0mtestMethod                                   [ \e[33mTODO\e[0m ]\n\
\e[32m * \e[0mtestMethod                                   [ \e[34mINDEV\e[0m ]\n\
=======  MyTest                                   ========\n\
\e[32m * \e[0mtestMethod                                   [ \e[33mSKIPED\e[0m ]\n\
\e[32m * \e[0mtestMethod                                   [ \e[31mFAILED\e[0m ]\n\
- - - - - - - - - - - - - - - - - - - - - - - - - - - - - -\n\
message for unknown status\n\
line 33 of file file.cpp on methode methode()\n\
   - actual : duck\n\
   - expected : toto\n\
- - - - - - - - - - - - - - - - - - - - - - - - - - - - - -\n\
=======  MyTest                                   ========\n\
\e[32m * \e[0mtestMethod                                   [ \e[31mUNKNOWN\e[0m ]\n\
- - - - - - - - - - - - - - - - - - - - - - - - - - - - - -\n\
message for unknown status\n\
line 33 of file file.cpp on methode methode()\n\
- - - - - - - - - - - - - - - - - - - - - - - - - - - - - -\n\n\
+---------------------------+\n\
|    SUMMARY                |\n\
+---------------------------+\n\
|  \e[32mSUCCESS  :    0 (  0 %)\e[0m  |\n\
|  \e[34mINDEV    :    0 (  0 %)\e[0m  |\n\
|  \e[33mTODO     :    0 (  0 %)\e[0m  |\n\
|  \e[31mFAILED   :    0 (  0 %)\e[0m  |\n\
|  \e[31mUNKNOWN  :    0 (  0 %)\e[0m  |\n\
+---------------------------+\n\
|  TOTAL    :    0          |\n\
|  STATUS   : \e[32mSUCCESS     \e[0m  |\n\
+---------------------------+\n";
static const char * CST_STRING_SEQ_2    = "=======  MyTest                                   ========\n\
\e[32m * \e[0mtestMethod                                   [ \e[32mSUCCESS\e[0m ]\n\
\e[32m * \e[0mtestMethod                                   [ \e[33mTODO\e[0m ]\n\
\e[32m * \e[0mtestMethod                                   [ \e[32mSUCCESS\e[0m ]\n\
\e[32m * \e[0mtestMethod                                   [ \e[34mINDEV\e[0m ]\n\
=======  MyTest                                   ========\n\
\e[32m * \e[0mtestMethod                                   [ \e[33mSKIPED\e[0m ]\n\
\e[32m * \e[0mtestMethod                                   [ \e[32mSUCCESS\e[0m ]\n\
\e[32m * \e[0mtestMethod                                   [ \e[31mFAILED\e[0m ]\n\
=======  MyTest                                   ========\n\
\e[32m * \e[0mtestMethod                                   [ \e[31mUNKNOWN\e[0m ]\n\n\
+---------------------------+\n\
|    SUMMARY                |\n\
+---------------------------+\n\
|  \e[32mSUCCESS  :    0 (  0 %)\e[0m  |\n\
|  \e[34mINDEV    :    0 (  0 %)\e[0m  |\n\
|  \e[33mTODO     :    0 (  0 %)\e[0m  |\n\
|  \e[31mFAILED   :    0 (  0 %)\e[0m  |\n\
|  \e[31mUNKNOWN  :    0 (  0 %)\e[0m  |\n\
+---------------------------+\n\
|  TOTAL    :    0          |\n\
|  STATUS   : \e[32mSUCCESS     \e[0m  |\n\
+---------------------------+\n";

/********************  CLASSE  **********************/
class UnitTest_svutResultFormatterStdColored : public TestCase
{
	CPPUNIT_TEST_SUITE(UnitTest_svutResultFormatterStdColored);
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
		svutResultFormatterStdColored * formatter;
		stringstream * out;
};

/********************  METHODE  *********************/
void UnitTest_svutResultFormatterStdColored::setUp(void)
{
	out = new stringstream;
	formatter = new svutResultFormatterStdColored(*out);
}

/********************  METHODE  *********************/
void UnitTest_svutResultFormatterStdColored::tearDown(void)
{
	delete formatter;
	delete out;
}

/********************  METHODE  *********************/
void UnitTest_svutResultFormatterStdColored::testCloseOutput(void )
{
	formatter->closeOutput();
	CPPUNIT_ASSERT_EQUAL("",out->str());
}

/********************  METHODE  *********************/
void UnitTest_svutResultFormatterStdColored::testCloseTestCase(void )
{
	UnitTestMockTestCase testCase;
	formatter->closeTestCase(testCase);
	CPPUNIT_ASSERT_EQUAL("",out->str());
}

/********************  METHODE  *********************/
void UnitTest_svutResultFormatterStdColored::testCloseTestMethod_success_1(void )
{
	UnitTestMockTestCase testCase;
	svutTestMethod meth("testMethod",NULL,SVUT_NO_LOCATION);
	formatter->closeTestMethod(testCase,meth,SVUT_STATUS_SUCCESS);
	CPPUNIT_ASSERT_EQUAL("",out->str());
}

/********************  METHODE  *********************/
void UnitTest_svutResultFormatterStdColored::testCloseTestMethod_success_2(void )
{
	UnitTestMockTestCase testCase;
	svutTestMethod meth("testMethod",NULL,SVUT_NO_LOCATION);
	formatter->setDisplaySuccess(true);
	formatter->closeTestMethod(testCase,meth,SVUT_STATUS_SUCCESS);
	CPPUNIT_ASSERT_EQUAL(CST_STRING_SUCCESS_1,out->str());
}

/********************  METHODE  *********************/
void UnitTest_svutResultFormatterStdColored::testCloseTestMethod_fullname(void )
{
	UnitTestMockTestCase testCase;
	svutTestMethod meth("testMethod",NULL,SVUT_NO_LOCATION);
	formatter->setDisplaySuccess(true);
	formatter->setDisplayFullName(true);
	formatter->closeTestMethod(testCase,meth,SVUT_STATUS_SUCCESS);
	CPPUNIT_ASSERT_EQUAL(CST_STRING_SUCCESS_2,out->str());
}

/********************  METHODE  *********************/
void UnitTest_svutResultFormatterStdColored::testCloseTestMethod_todo(void )
{
	UnitTestMockTestCase testCase;
	svutTestMethod meth("testMethod",NULL,SVUT_NO_LOCATION);
	formatter->closeTestMethod(testCase,meth,SVUT_STATUS_TODO);
	CPPUNIT_ASSERT_EQUAL(CST_STRING_TODO,out->str());
}

/********************  METHODE  *********************/
void UnitTest_svutResultFormatterStdColored::testCloseTestMethod_indev(void )
{
	UnitTestMockTestCase testCase;
	svutTestMethod meth("testMethod",NULL,SVUT_NO_LOCATION);
	formatter->closeTestMethod(testCase,meth,SVUT_STATUS_INDEV);
	CPPUNIT_ASSERT_EQUAL(CST_STRING_INDEV,out->str());
}

/********************  METHODE  *********************/
void UnitTest_svutResultFormatterStdColored::testCloseTestMethod_skiped(void )
{
	UnitTestMockTestCase testCase;
	svutTestMethod meth("testMethod",NULL,SVUT_NO_LOCATION);
	formatter->closeTestMethod(testCase,meth,SVUT_STATUS_SKIPED);
	CPPUNIT_ASSERT_EQUAL(CST_STRING_SKIPED,out->str());
}

/********************  METHODE  *********************/
void UnitTest_svutResultFormatterStdColored::testCloseTestMethod_unknown_1(void )
{
	UnitTestMockTestCase testCase;
	svutTestMethod meth("testMethod",NULL,SVUT_NO_LOCATION);
	formatter->closeTestMethod(testCase,meth,SVUT_STATUS_UNKNOWN);
	CPPUNIT_ASSERT_EQUAL(CST_STRING_UNKNOWN_1,out->str());
}

/********************  METHODE  *********************/
void UnitTest_svutResultFormatterStdColored::testCloseTestMethod_unknown_2(void )
{
	UnitTestMockTestCase testCase;
	svutTestMethod meth("testMethod",NULL,SVUT_NO_LOCATION);
	formatter->setDisplayDetails(false);
	formatter->closeTestMethod(testCase,meth,SVUT_STATUS_UNKNOWN);
	CPPUNIT_ASSERT_EQUAL(CST_STRING_UNKNOWN_2,out->str());
}

/********************  METHODE  *********************/
void UnitTest_svutResultFormatterStdColored::testCloseTestMethod_unknown_3(void )
{
	UnitTestMockTestCase testCase;
	svutTestMethod meth("testMethod",NULL,SVUT_NO_LOCATION);
	svutCodeLocation location("file.cpp","methode",33);
	svutStatusInfo info(SVUT_STATUS_UNKNOWN,"message for unknown status",location);
	formatter->closeTestMethod(testCase,meth,info);
	CPPUNIT_ASSERT_EQUAL(CST_STRING_UNKNOWN_3,out->str());
}

/********************  METHODE  *********************/
void UnitTest_svutResultFormatterStdColored::testCloseTestMethod_failed_1(void )
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

/********************  METHODE  *********************/
void UnitTest_svutResultFormatterStdColored::testCloseTestMethod_failed_2(void )
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

/********************  METHODE  *********************/
void UnitTest_svutResultFormatterStdColored::runTotalSequence(void )
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


/********************  METHODE  *********************/
void UnitTest_svutResultFormatterStdColored::testGlobal_1(void )
{
	this->runTotalSequence();
	CPPUNIT_ASSERT_EQUAL(CST_STRING_SEQ_1,out->str());
}

/********************  METHODE  *********************/
void UnitTest_svutResultFormatterStdColored::testGlobal_2(void )
{
	formatter->setDisplaySuccess(true);
	formatter->setDisplayDetails(false);
	this->runTotalSequence();
	CPPUNIT_ASSERT_EQUAL(CST_STRING_SEQ_2,out->str());
}

/********************  METHODE  *********************/
void UnitTest_svutResultFormatterStdColored::testOpenOutput(void )
{
	formatter->openOutput();
	CPPUNIT_ASSERT_EQUAL("",out->str());
}

/********************  METHODE  *********************/
void UnitTest_svutResultFormatterStdColored::testOpenTestCase(void )
{
	UnitTestMockTestCase testCase;
	formatter->openTestCase(testCase);
	CPPUNIT_ASSERT_EQUAL(CST_STRING_TEST_CASE,out->str());
}

/********************  METHODE  *********************/
void UnitTest_svutResultFormatterStdColored::testOpenTestMethod(void )
{
	UnitTestMockTestCase testCase;
	svutTestMethod meth("testMethod",NULL,SVUT_CODE_LOCATION);
	formatter->openTestMethod(testCase,meth);
	CPPUNIT_ASSERT_EQUAL("",out->str());
}

/********************  METHODE  *********************/
void UnitTest_svutResultFormatterStdColored::testPrintSummary(void )
{
	svutResultSummary summary;
	formatter->printSummary(summary);
	CPPUNIT_ASSERT_EQUAL(CST_STRING_SUMMARY_0,out->str());
}

CPPUNIT_TEST_SUITE_REGISTRATION(UnitTest_svutResultFormatterStdColored);
