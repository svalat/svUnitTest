/*****************************************************
             PROJECT  : svUnitTest
             VERSION  : 0.5.0-dev
             DATE     : 11/2012
             AUTHOR   : Valat Sébastien
             LICENSE  : CeCILL-C 2.1
*****************************************************/

/********************  HEADERS  *********************/
#include "UnitTestExtra.h"
#include <svutResultFormatterStdColored.h>
#include "UnitTestMockTestCase.h"
#include <sys/stat.h>
#include "IUnitTest_ResultFormatter.h"

/**********************  USING  *********************/
using namespace std;
using namespace svUnitTest;
using namespace CPPUNIT_NS;

/********************  CONSTS  ***********************/
static const char * CST_STRING_SUMMARY_0 = "\n\
+---------------------------+\n\
|    SUMMARY                |\n\
+---------------------------+\n\
|  \033[32mSUCCESS  :    0 (  0 %)\033[0m  |\n\
|  \033[34mINDEV    :    0 (  0 %)\033[0m  |\n\
|  \033[33mTODO     :    0 (  0 %)\033[0m  |\n\
|  \033[31mFAILED   :    0 (  0 %)\033[0m  |\n\
|  \033[31mUNKNOWN  :    0 (  0 %)\033[0m  |\n\
+---------------------------+\n\
|  TOTAL    :    0          |\n\
|  STATUS   : \033[32mSUCCESS     \033[0m  |\n\
+---------------------------+\n";
static const char * CST_STRING_UNKNOWN_1 =
"\033[32m * \033[0mtestMethod                                   [ \033[31mUNKNOWN\033[0m ]\n\
- - - - - - - - - - - - - - - - - - - - - - - - - - - - - -\n\
\n\
unknown location\n\
- - - - - - - - - - - - - - - - - - - - - - - - - - - - - -\n";
static const char * CST_STRING_UNKNOWN_3 = "\033[32m * \033[0mtestMethod                                   [ \033[31mUNKNOWN\033[0m ]\n\
- - - - - - - - - - - - - - - - - - - - - - - - - - - - - -\n\
message for unknown status\n\
line 33 of file file.cpp on methode methode()\n\
- - - - - - - - - - - - - - - - - - - - - - - - - - - - - -\n";
static const char * CST_STRING_UNKNOWN_2 = "\033[32m * \033[0mtestMethod                                   [ \033[31mUNKNOWN\033[0m ]\n";
static const char * CST_STRING_SUCCESS_1 = "\033[32m * \033[0mtestMethod                                   [ \033[32mSUCCESS\033[0m ]\n";
static const char * CST_STRING_SUCCESS_2 = "\033[32m * \033[0mMyTest:testMethod                            [ \033[32mSUCCESS\033[0m ]\n";
static const char * CST_STRING_TODO      = "\033[32m * \033[0mtestMethod                                   [ \033[33mTODO\033[0m ]\n";
static const char * CST_STRING_INDEV     = "\033[32m * \033[0mtestMethod                                   [ \033[34mINDEV\033[0m ]\n";
static const char * CST_STRING_SKIPED    = "\033[32m * \033[0mtestMethod                                   [ \033[33mSKIPED\033[0m ]\n";
static const char * CST_STRING_TEST_CASE = "=======  MyTest                                   ========\n";
static const char * CST_STRING_FAILED_2  = "\033[32m * \033[0mtestMethod                                   [ \033[31mFAILED\033[0m ]\n";
static const char * CST_STRING_FAILED_1  = "\033[32m * \033[0mtestMethod                                   [ \033[31mFAILED\033[0m ]\n\
- - - - - - - - - - - - - - - - - - - - - - - - - - - - - -\n\
message for failed status\n\
line 33 of file file.cpp on methode methode()\n\
   - actual : duck\n\
   - expected : toto\n\
- - - - - - - - - - - - - - - - - - - - - - - - - - - - - -\n";
static const char * CST_STRING_CONTEXT  = "\033[32m * \033[0mtestMethod                                   [ \033[31mFAILED\033[0m ]\n\
- - - - - - - - - - - - - - - - - - - - - - - - - - - - - -\n\
message for failed status\n\
line 33 of file file.cpp on methode methode()\n\
   - actual : duck\n\
   - expected : toto\n\
Context :\n\
   - name : value\n\
   - name2 : value2\n\
- - - - - - - - - - - - - - - - - - - - - - - - - - - - - -\n";
static const char * CST_STRING_SEQ_1    = "=======  MyTest                                   ========\n\
\033[32m * \033[0mtestMethod                                   [ \033[33mTODO\033[0m ]\n\
\033[32m * \033[0mtestMethod                                   [ \033[34mINDEV\033[0m ]\n\
=======  MyTest                                   ========\n\
\033[32m * \033[0mtestMethod                                   [ \033[33mSKIPED\033[0m ]\n\
\033[32m * \033[0mtestMethod                                   [ \033[31mFAILED\033[0m ]\n\
- - - - - - - - - - - - - - - - - - - - - - - - - - - - - -\n\
message for unknown status\n\
line 33 of file file.cpp on methode methode()\n\
   - actual : duck\n\
   - expected : toto\n\
- - - - - - - - - - - - - - - - - - - - - - - - - - - - - -\n\
=======  MyTest                                   ========\n\
\033[32m * \033[0mtestMethod                                   [ \033[31mUNKNOWN\033[0m ]\n\
- - - - - - - - - - - - - - - - - - - - - - - - - - - - - -\n\
message for unknown status\n\
line 33 of file file.cpp on methode methode()\n\
- - - - - - - - - - - - - - - - - - - - - - - - - - - - - -\n\n\
+---------------------------+\n\
|    SUMMARY                |\n\
+---------------------------+\n\
|  \033[32mSUCCESS  :    0 (  0 %)\033[0m  |\n\
|  \033[34mINDEV    :    0 (  0 %)\033[0m  |\n\
|  \033[33mTODO     :    0 (  0 %)\033[0m  |\n\
|  \033[31mFAILED   :    0 (  0 %)\033[0m  |\n\
|  \033[31mUNKNOWN  :    0 (  0 %)\033[0m  |\n\
+---------------------------+\n\
|  TOTAL    :    0          |\n\
|  STATUS   : \033[32mSUCCESS     \033[0m  |\n\
+---------------------------+\n";
static const char * CST_STRING_SEQ_2    = "=======  MyTest                                   ========\n\
\033[32m * \033[0mtestMethod                                   [ \033[32mSUCCESS\033[0m ]\n\
\033[32m * \033[0mtestMethod                                   [ \033[33mTODO\033[0m ]\n\
\033[32m * \033[0mtestMethod                                   [ \033[32mSUCCESS\033[0m ]\n\
\033[32m * \033[0mtestMethod                                   [ \033[34mINDEV\033[0m ]\n\
=======  MyTest                                   ========\n\
\033[32m * \033[0mtestMethod                                   [ \033[33mSKIPED\033[0m ]\n\
\033[32m * \033[0mtestMethod                                   [ \033[32mSUCCESS\033[0m ]\n\
\033[32m * \033[0mtestMethod                                   [ \033[31mFAILED\033[0m ]\n\
=======  MyTest                                   ========\n\
\033[32m * \033[0mtestMethod                                   [ \033[31mUNKNOWN\033[0m ]\n\n\
+---------------------------+\n\
|    SUMMARY                |\n\
+---------------------------+\n\
|  \033[32mSUCCESS  :    0 (  0 %)\033[0m  |\n\
|  \033[34mINDEV    :    0 (  0 %)\033[0m  |\n\
|  \033[33mTODO     :    0 (  0 %)\033[0m  |\n\
|  \033[31mFAILED   :    0 (  0 %)\033[0m  |\n\
|  \033[31mUNKNOWN  :    0 (  0 %)\033[0m  |\n\
+---------------------------+\n\
|  TOTAL    :    0          |\n\
|  STATUS   : \033[32mSUCCESS     \033[0m  |\n\
+---------------------------+\n";

/********************  CLASS  **********************/
class UnitTest_svutResultFormatterStdColored : public TestCase,IUnitTest_ResultFormatter
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
	CPPUNIT_TEST(testListingStart);
	CPPUNIT_TEST(testListingEnd);
	CPPUNIT_TEST(testListMethod_1);
	CPPUNIT_TEST(testListMethod_2);
	CPPUNIT_TEST(testPrintSummary);
	CPPUNIT_TEST(testGlobal_1);
	CPPUNIT_TEST(testGlobal_2);
	CPPUNIT_TEST(testCloseTestMethod_debugContext);
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
		void testListingStart(void);
		void testListingEnd(void);
		void testListMethod_1(void);
		void testListMethod_2(void);
		void testPrintSummary(void);
		void testGlobal_1(void);
		void testGlobal_2(void);
		void testCloseTestMethod_debugContext(void);
	protected:
		void runTotalSequence(void);
		svutResultFormatterStdColored * formatter;
		stringstream * out;
};

/*******************  FUNCTION  *********************/
void UnitTest_svutResultFormatterStdColored::setUp(void)
{
	out = new stringstream;
	formatter = new svutResultFormatterStdColored(*out);
}

/*******************  FUNCTION  *********************/
void UnitTest_svutResultFormatterStdColored::tearDown(void)
{
	delete formatter;
	delete out;
}

/*******************  FUNCTION  *********************/
void UnitTest_svutResultFormatterStdColored::testCloseOutput(void )
{
	formatter->closeOutput();
	CPPUNIT_ASSERT_EQUAL("",out->str());
}

/*******************  FUNCTION  *********************/
void UnitTest_svutResultFormatterStdColored::testCloseTestCase(void )
{
	UnitTestMockTestCase testCase;
	formatter->closeTestCase(testCase);
	CPPUNIT_ASSERT_EQUAL("",out->str());
}

/*******************  FUNCTION  *********************/
void UnitTest_svutResultFormatterStdColored::testCloseTestMethod_success_1(void )
{
	UnitTestMockTestCase testCase;
	svutTestMethod meth("testMethod",SVUT_NO_LOCATION,NULL);
	formatter->closeTestMethod(testCase,meth,SVUT_STATUS_SUCCESS);
	CPPUNIT_ASSERT_EQUAL("",out->str());
}

/*******************  FUNCTION  *********************/
void UnitTest_svutResultFormatterStdColored::testCloseTestMethod_success_2(void )
{
	UnitTestMockTestCase testCase;
	svutTestMethod meth("testMethod",SVUT_NO_LOCATION,NULL);
	formatter->setDisplaySuccess(true);
	formatter->closeTestMethod(testCase,meth,SVUT_STATUS_SUCCESS);
	CPPUNIT_ASSERT_EQUAL(CST_STRING_SUCCESS_1,out->str());
}

/*******************  FUNCTION  *********************/
void UnitTest_svutResultFormatterStdColored::testCloseTestMethod_fullname(void )
{
	UnitTestMockTestCase testCase;
	svutTestMethod meth("testMethod",SVUT_NO_LOCATION,NULL);
	formatter->setDisplaySuccess(true);
	formatter->setDisplayFullName(true);
	formatter->closeTestMethod(testCase,meth,SVUT_STATUS_SUCCESS);
	CPPUNIT_ASSERT_EQUAL(CST_STRING_SUCCESS_2,out->str());
}

/*******************  FUNCTION  *********************/
void UnitTest_svutResultFormatterStdColored::testCloseTestMethod_todo(void )
{
	UnitTestMockTestCase testCase;
	svutTestMethod meth("testMethod",SVUT_NO_LOCATION,NULL);
	formatter->closeTestMethod(testCase,meth,SVUT_STATUS_TODO);
	CPPUNIT_ASSERT_EQUAL(CST_STRING_TODO,out->str());
}

/*******************  FUNCTION  *********************/
void UnitTest_svutResultFormatterStdColored::testCloseTestMethod_indev(void )
{
	UnitTestMockTestCase testCase;
	svutTestMethod meth("testMethod",SVUT_NO_LOCATION,NULL);
	formatter->closeTestMethod(testCase,meth,SVUT_STATUS_INDEV);
	CPPUNIT_ASSERT_EQUAL(CST_STRING_INDEV,out->str());
}

/*******************  FUNCTION  *********************/
void UnitTest_svutResultFormatterStdColored::testCloseTestMethod_skiped(void )
{
	UnitTestMockTestCase testCase;
	svutTestMethod meth("testMethod",SVUT_NO_LOCATION,NULL);
	formatter->closeTestMethod(testCase,meth,SVUT_STATUS_SKIPED);
	CPPUNIT_ASSERT_EQUAL(CST_STRING_SKIPED,out->str());
}

/*******************  FUNCTION  *********************/
void UnitTest_svutResultFormatterStdColored::testCloseTestMethod_unknown_1(void )
{
	UnitTestMockTestCase testCase;
	svutTestMethod meth("testMethod",SVUT_NO_LOCATION,NULL);
	formatter->closeTestMethod(testCase,meth,SVUT_STATUS_UNKNOWN);
	CPPUNIT_ASSERT_EQUAL(CST_STRING_UNKNOWN_1,out->str());
}

/*******************  FUNCTION  *********************/
void UnitTest_svutResultFormatterStdColored::testCloseTestMethod_unknown_2(void )
{
	UnitTestMockTestCase testCase;
	svutTestMethod meth("testMethod",SVUT_NO_LOCATION,NULL);
	formatter->setDisplayDetails(false);
	formatter->closeTestMethod(testCase,meth,SVUT_STATUS_UNKNOWN);
	CPPUNIT_ASSERT_EQUAL(CST_STRING_UNKNOWN_2,out->str());
}

/*******************  FUNCTION  *********************/
void UnitTest_svutResultFormatterStdColored::testCloseTestMethod_unknown_3(void )
{
	UnitTestMockTestCase testCase;
	svutTestMethod meth("testMethod",SVUT_NO_LOCATION,NULL);
	svutCodeLocation location("file.cpp","methode",33);
	svutStatusInfo info(SVUT_STATUS_UNKNOWN,"message for unknown status",location);
	formatter->closeTestMethod(testCase,meth,info);
	CPPUNIT_ASSERT_EQUAL(CST_STRING_UNKNOWN_3,out->str());
}

/*******************  FUNCTION  *********************/
void UnitTest_svutResultFormatterStdColored::testCloseTestMethod_failed_1(void )
{
	UnitTestMockTestCase testCase;
	svutTestMethod meth("testMethod",SVUT_NO_LOCATION,NULL);
	svutCodeLocation location("file.cpp","methode",33);
	svutStatusInfo info(SVUT_STATUS_FAILED,"message for failed status",location);
	info.addEntry("expected","toto");
	info.addEntry("actual","duck");
	formatter->closeTestMethod(testCase,meth,info);
	CPPUNIT_ASSERT_EQUAL(CST_STRING_FAILED_1,out->str());
}

/*******************  FUNCTION  *********************/
void UnitTest_svutResultFormatterStdColored::testCloseTestMethod_failed_2(void )
{
	UnitTestMockTestCase testCase;
	svutTestMethod meth("testMethod",SVUT_NO_LOCATION,NULL);
	svutCodeLocation location("file.cpp","methode",33);
	svutStatusInfo info(SVUT_STATUS_FAILED,"message for failed status",location);
	info.addEntry("expected","toto");
	info.addEntry("actual","duck");
	formatter->setDisplayDetails(false);
	formatter->closeTestMethod(testCase,meth,info);
	CPPUNIT_ASSERT_EQUAL(CST_STRING_FAILED_2,out->str());
}

/*******************  FUNCTION  *********************/
void UnitTest_svutResultFormatterStdColored::runTotalSequence(void )
{
	UnitTestMockTestCase testCase;
	svutCodeLocation location("file.cpp","methode",33);
	svutTestMethod meth("testMethod",location,NULL);
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
void UnitTest_svutResultFormatterStdColored::testGlobal_1(void )
{
	this->runTotalSequence();
	CPPUNIT_ASSERT_EQUAL(CST_STRING_SEQ_1,out->str());
}

/*******************  FUNCTION  *********************/
void UnitTest_svutResultFormatterStdColored::testGlobal_2(void )
{
	formatter->setDisplaySuccess(true);
	formatter->setDisplayDetails(false);
	this->runTotalSequence();
	CPPUNIT_ASSERT_EQUAL(CST_STRING_SEQ_2,out->str());
}

/*******************  FUNCTION  *********************/
void UnitTest_svutResultFormatterStdColored::testOpenOutput(void )
{
	formatter->openOutput();
	CPPUNIT_ASSERT_EQUAL("",out->str());
}

/*******************  FUNCTION  *********************/
void UnitTest_svutResultFormatterStdColored::testOpenTestCase(void )
{
	UnitTestMockTestCase testCase;
	formatter->openTestCase(testCase);
	CPPUNIT_ASSERT_EQUAL(CST_STRING_TEST_CASE,out->str());
}

/*******************  FUNCTION  *********************/
void UnitTest_svutResultFormatterStdColored::testOpenTestMethod(void )
{
	UnitTestMockTestCase testCase;
	svutTestMethod meth("testMethod",SVUT_CODE_LOCATION,NULL);
	formatter->openTestMethod(testCase,meth);
	CPPUNIT_ASSERT_EQUAL("",out->str());
}

/*******************  FUNCTION  *********************/
void UnitTest_svutResultFormatterStdColored::testPrintSummary(void )
{
	svutResultSummary summary;
	formatter->printSummary(summary);
	CPPUNIT_ASSERT_EQUAL(CST_STRING_SUMMARY_0,out->str());
}

/*******************  FUNCTION  *********************/
void UnitTest_svutResultFormatterStdColored::testListingEnd(void )
{
	formatter->onListingEnd();
	CPPUNIT_ASSERT_EQUAL("",out->str());
}

/*******************  FUNCTION  *********************/
void UnitTest_svutResultFormatterStdColored::testListingStart(void )
{
	formatter->onListingStart();
	CPPUNIT_ASSERT_EQUAL("",out->str());
}

/*******************  FUNCTION  *********************/
void UnitTest_svutResultFormatterStdColored::testListMethod_1(void )
{
	UnitTestMockTestCase testCase;
	svutTestMethod meth("testMethod",SVUT_NO_LOCATION,NULL);
	formatter->onListMethod(testCase,meth);
	CPPUNIT_ASSERT_EQUAL("testMethod()\n",out->str());
}

/*******************  FUNCTION  *********************/
void UnitTest_svutResultFormatterStdColored::testListMethod_2(void )
{
	UnitTestMockTestCase testCase;
	svutTestMethod meth("testMethod",SVUT_NO_LOCATION,NULL);
	formatter->setDisplayFullName(true);
	formatter->onListMethod(testCase,meth);
	CPPUNIT_ASSERT_EQUAL("MyTest::testMethod()\n",out->str());
}

/*******************  FUNCTION  *********************/
void UnitTest_svutResultFormatterStdColored::testCloseTestMethod_debugContext(void )
{
	svutStatusInfoMap debug;
	debug.insert(pair<string,string>("name","value"));
	debug.insert(pair<string,string>("name2","value2"));

	UnitTestMockTestCase testCase;
	svutTestMethod meth("testMethod",SVUT_NO_LOCATION,NULL);
	svutCodeLocation location("file.cpp","methode",33);
	svutStatusInfo info(SVUT_STATUS_FAILED,"message for failed status",location);
	info.addEntry("expected","toto");
	info.addEntry("actual","duck");
	info.setContext(debug);
	formatter->closeTestMethod(testCase,meth,info);
	CPPUNIT_ASSERT_EQUAL(CST_STRING_CONTEXT,out->str());
}

CPPUNIT_TEST_SUITE_REGISTRATION(UnitTest_svutResultFormatterStdColored);
