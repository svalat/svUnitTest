/*****************************************************
             PROJECT  : svUnitTest
             VERSION  : 0.5.0-dev
             DATE     : 11/2012
             AUTHOR   : Valat Sébastien
             LICENSE  : CeCILL-C 2.1
*****************************************************/

/********************  HEADERS  *********************/
#include "UnitTestExtra.h"
#include <ctime>
#include <svutResultFormatterXml.h>
#include "UnitTestMockTestCase.h"
#include <sys/stat.h>
#include <svUnitTest.h>
#include "IUnitTest_ResultFormatter.h"

/**********************  USING  *********************/
using namespace std;
using namespace svUnitTest;
using namespace CPPUNIT_NS;

/********************  CONSTS  ***********************/
static const char * CST_STRING_SUMMARY_0 = "\t<GlobalResults>\n\
\t\t<result type='success'>0</result>\n\
\t\t<result type='indev'>0</result>\n\
\t\t<result type='todo'>0</result>\n\
\t\t<result type='failed'>0</result>\n\
\t\t<result type='unknown'>0</result>\n\
\t\t<total>0</total>\n\
\t\t<status>success</status>\n\
\t</GlobalResults>\n";
static const char * CST_STRING_UNKNOWN_1 = "\t\t\t<status>unknown</status>\n\t\t\t<time>0</time>\n\
\t\t\t<AssertInfo>\n\t\t\t\t<location>\n\t\t\t\t\t<unknown></unknown>\n\
\t\t\t\t</location>\n\t\t\t</AssertInfo>\n\t\t</TestFunction>\n";
static const char * CST_STRING_UNKNOWN_3 = "\t\t\t<status>unknown</status>\n\t\t\t<time>0</time>\n\
\t\t\t<AssertInfo>\n\t\t\t\t<location>\n\t\t\t\t\t<file>file.cpp</file>\n\
\t\t\t\t\t<methode>methode</methode>\n\t\t\t\t\t<line>33</line>\n\
\t\t\t\t</location>\n\t\t\t\t<message>message for unknown status</message>\n\t\t\t</AssertInfo>\n\t\t</TestFunction>\n";
static const char * CST_STRING_SUCCESS_1 = "\t\t\t<status>success</status>\n\t\t\t<time>0</time>\n\t\t</TestFunction>\n";
static const char * CST_STRING_TODO      = "\t\t\t<status>todo</status>\n\t\t\t<time>0</time>\n\t\t\t<AssertInfo>\n\
\t\t\t\t<location>\n\t\t\t\t\t<unknown></unknown>\n\t\t\t\t</location>\n\t\t\t</AssertInfo>\n\t\t</TestFunction>\n";
static const char * CST_STRING_INDEV     = "\t\t\t<status>indev</status>\n\t\t\t<time>0</time>\n\t\t\t<AssertInfo>\n\
\t\t\t\t<location>\n\t\t\t\t\t<unknown></unknown>\n\t\t\t\t</location>\n\t\t\t</AssertInfo>\n\t\t</TestFunction>\n";
static const char * CST_STRING_SKIPED    = "\t\t\t<status>skiped</status>\n\t\t\t<time>0</time>\n\t\t</TestFunction>\n";
static const char * CST_STRING_TEST_CASE = "\t<TestCase>\n\t\t<name>MyTest</name>\n";
static const char * CST_STRING_FAILED_1  = "\t\t\t<status>failed</status>\n\t\t\t<time>0</time>\n\
\t\t\t<AssertInfo>\n\t\t\t\t<location>\n\t\t\t\t\t<file>file.cpp</file>\n\
\t\t\t\t\t<methode>methode</methode>\n\t\t\t\t\t<line>33</line>\n\t\t\t\t</location>\n\
\t\t\t\t<message>message for failed status</message>\n\t\t\t\t<entries>\n\
\t\t\t\t\t<entry name='actual'>duck</entry>\n\t\t\t\t\t<entry name='expected'>toto</entry>\n\
\t\t\t\t</entries>\n\t\t\t</AssertInfo>\n\t\t</TestFunction>\n";
static const char * CST_STRING_CONTEXT  ="\t\t\t<status>failed</status>\n\t\t\t<time>0</time>\n\
\t\t\t<AssertInfo>\n\t\t\t\t<location>\n\t\t\t\t\t<file>file.cpp</file>\n\
\t\t\t\t\t<methode>methode</methode>\n\t\t\t\t\t<line>33</line>\n\t\t\t\t</location>\n\
\t\t\t\t<message>message for failed status</message>\n\t\t\t\t<entries>\n\
\t\t\t\t\t<entry name='actual'>duck</entry>\n\t\t\t\t\t<entry name='expected'>toto</entry>\n\
\t\t\t\t</entries>\n\t\t\t\t<context>\n\t\t\t\t\t<entry name='name'>value</entry>\n\t\t\t\t\t<entry name='name2'>value2</entry>\n\t\t\t\t</context>\n\t\t\t</AssertInfo>\n\t\t</TestFunction>\n";
static const char * CST_STRING_SEQ_1    = "<?xml version='1.0' encoding='UTF-8'?>\n\
<!DOCTYPE UnitTest SYSTEM 'svUnitTest_html/svUnitTest.dtd'>\n\
<?xml-stylesheet type='text/xsl' href='svUnitTest_html/svUnitTest.xsl'?>\n\
<UnitTest>\n\
	<TestEnv>\n\
		<LibVersion>" SVUT_LIBARY_VERSION "</LibVersion>\n\
		<TestDate>__DATE__</TestDate>\n\
	</TestEnv>\n\
	<TestCase>\n\
		<name>MyTest</name>\n\
		<TestFunction>\n\
			<name>testMethod</name>\n\
			<status>success</status>\n\
			<time>0</time>\n\
		</TestFunction>\n\
		<TestFunction>\n\
			<name>testMethod</name>\n\
			<status>todo</status>\n\
			<time>0</time>\n\
			<AssertInfo>\n\
				<location>\n\
					<unknown></unknown>\n\
				</location>\n\
			</AssertInfo>\n\
		</TestFunction>\n\
		<TestFunction>\n\
			<name>testMethod</name>\n\
			<status>success</status>\n\
			<time>0</time>\n\
		</TestFunction>\n\
		<TestFunction>\n\
			<name>testMethod</name>\n\
			<status>indev</status>\n\
			<time>0</time>\n\
			<AssertInfo>\n\
				<location>\n\
					<unknown></unknown>\n\
				</location>\n\
			</AssertInfo>\n\
		</TestFunction>\n\
	</TestCase>\n\
	<TestCase>\n\
		<name>MyTest</name>\n\
		<TestFunction>\n\
			<name>testMethod</name>\n\
			<status>skiped</status>\n\
			<time>0</time>\n\
		</TestFunction>\n\
		<TestFunction>\n\
			<name>testMethod</name>\n\
			<status>success</status>\n\
			<time>0</time>\n\
		</TestFunction>\n\
		<TestFunction>\n\
			<name>testMethod</name>\n\
			<status>failed</status>\n\
			<time>0</time>\n\
			<AssertInfo>\n\
				<location>\n\
					<file>file.cpp</file>\n\
					<methode>methode</methode>\n\
					<line>33</line>\n\
				</location>\n\
				<message>message for unknown status</message>\n\
				<entries>\n\
					<entry name='actual'>duck</entry>\n\
					<entry name='expected'>toto</entry>\n\
				</entries>\n\
			</AssertInfo>\n\
		</TestFunction>\n\
	<TestCase>\n\
		<name>MyTest</name>\n\
			<status>unknown</status>\n\
			<time>0</time>\n\
			<AssertInfo>\n\
				<location>\n\
					<file>file.cpp</file>\n\
					<methode>methode</methode>\n\
					<line>33</line>\n\
				</location>\n\
				<message>message for unknown status</message>\n\
			</AssertInfo>\n\
		</TestFunction>\n\
	</TestCase>\n\
	<GlobalResults>\n\
		<result type='success'>0</result>\n\
		<result type='indev'>0</result>\n\
		<result type='todo'>0</result>\n\
		<result type='failed'>0</result>\n\
		<result type='unknown'>0</result>\n\
		<total>0</total>\n\
		<status>success</status>\n\
	</GlobalResults>\n\
</UnitTest>\n";
static const char * CST_STRING_OPEN = "<?xml version='1.0' encoding='UTF-8'?>\n\
<!DOCTYPE UnitTest SYSTEM 'svUnitTest_html/svUnitTest.dtd'>\n\
<?xml-stylesheet type='text/xsl' href='svUnitTest_html/svUnitTest.xsl'?>\n\
<UnitTest>\n\
	<TestEnv>\n\
		<LibVersion>" SVUT_LIBARY_VERSION "</LibVersion>\n\
		<TestDate>__DATE__</TestDate>\n\
	</TestEnv>\n";
static const char * CST_STRING_CLOSE = "</UnitTest>\n";
static const char * CST_STRING_CLOSE_TC = "\t</TestCase>\n";
static const char * CST_STRING_OPEN_METH = "\t\t<TestFunction>\n\t\t\t<name>testMethod</name>\n";
static const char * CST_STRING_LISTING_START = "<?xml version='1.0' encoding='UTF-8'?>\n<UnitTestList>\n";
static const char * CST_STRING_LISTING_END = "</UnitTestList>\n";
static const char * CST_STRING_LIST_METHOD = "\t<TestCase name='MyTest'>\n\t\t<TestMethod name='testMethod'/>\n";

/*********************  CLASS  **********************/
class UnitTest_svutResultFormatterXml : public TestCase, IUnitTest_ResultFormatter
{
	CPPUNIT_TEST_SUITE(UnitTest_svutResultFormatterXml);
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
		svutResultFormatterXml * formatter;
		stringstream * out;
};

/*******************  FUNCTION  *********************/
/**
 * Override to avoid time changes
**/
double getCurrentTime(void )
{
	return 0.0;
}

/*******************  FUNCTION  *********************/
void UnitTest_svutResultFormatterXml::setUp(void)
{
	out = new stringstream;
	formatter = new svutResultFormatterXml(*out);
}

/*******************  FUNCTION  *********************/
void UnitTest_svutResultFormatterXml::tearDown(void)
{
	delete formatter;
	delete out;
}

/*******************  FUNCTION  *********************/
void UnitTest_svutResultFormatterXml::testCloseOutput(void )
{
	formatter->closeOutput();
	CPPUNIT_ASSERT_EQUAL(CST_STRING_CLOSE,out->str());
}

/*******************  FUNCTION  *********************/
void UnitTest_svutResultFormatterXml::testCloseTestCase(void )
{
	UnitTestMockTestCase testCase;
	formatter->closeTestCase(testCase);
	CPPUNIT_ASSERT_EQUAL(CST_STRING_CLOSE_TC,out->str());
}

/*******************  FUNCTION  *********************/
void UnitTest_svutResultFormatterXml::testCloseTestMethod_success_1(void )
{
	UnitTestMockTestCase testCase;
	svutTestMethod meth("testMethod",SVUT_NO_LOCATION,NULL);
	formatter->closeTestMethod(testCase,meth,SVUT_STATUS_SUCCESS);
	CPPUNIT_ASSERT_EQUAL(CST_STRING_SUCCESS_1,out->str());
}

/*******************  FUNCTION  *********************/
void UnitTest_svutResultFormatterXml::testCloseTestMethod_success_2(void )
{
	UnitTestMockTestCase testCase;
	svutTestMethod meth("testMethod",SVUT_NO_LOCATION,NULL);
	formatter->setDisplaySuccess(true);
	formatter->closeTestMethod(testCase,meth,SVUT_STATUS_SUCCESS);
	CPPUNIT_ASSERT_EQUAL(CST_STRING_SUCCESS_1,out->str());
}

/*******************  FUNCTION  *********************/
void UnitTest_svutResultFormatterXml::testCloseTestMethod_fullname(void )
{
	UnitTestMockTestCase testCase;
	svutTestMethod meth("testMethod",SVUT_NO_LOCATION,NULL);
	formatter->setDisplaySuccess(true);
	formatter->setDisplayFullName(true);
	formatter->closeTestMethod(testCase,meth,SVUT_STATUS_SUCCESS);
	CPPUNIT_ASSERT_EQUAL(CST_STRING_SUCCESS_1,out->str());
}

/*******************  FUNCTION  *********************/
void UnitTest_svutResultFormatterXml::testCloseTestMethod_todo(void )
{
	UnitTestMockTestCase testCase;
	svutTestMethod meth("testMethod",SVUT_NO_LOCATION,NULL);
	formatter->closeTestMethod(testCase,meth,SVUT_STATUS_TODO);
	CPPUNIT_ASSERT_EQUAL(CST_STRING_TODO,out->str());
}

/*******************  FUNCTION  *********************/
void UnitTest_svutResultFormatterXml::testCloseTestMethod_indev(void )
{
	UnitTestMockTestCase testCase;
	svutTestMethod meth("testMethod",SVUT_NO_LOCATION,NULL);
	formatter->closeTestMethod(testCase,meth,SVUT_STATUS_INDEV);
	CPPUNIT_ASSERT_EQUAL(CST_STRING_INDEV,out->str());
}

/*******************  FUNCTION  *********************/
void UnitTest_svutResultFormatterXml::testCloseTestMethod_skiped(void )
{
	UnitTestMockTestCase testCase;
	svutTestMethod meth("testMethod",SVUT_NO_LOCATION,NULL);
	formatter->closeTestMethod(testCase,meth,SVUT_STATUS_SKIPED);
	CPPUNIT_ASSERT_EQUAL(CST_STRING_SKIPED,out->str());
}

/*******************  FUNCTION  *********************/
void UnitTest_svutResultFormatterXml::testCloseTestMethod_unknown_1(void )
{
	UnitTestMockTestCase testCase;
	svutTestMethod meth("testMethod",SVUT_NO_LOCATION,NULL);
	formatter->closeTestMethod(testCase,meth,SVUT_STATUS_UNKNOWN);
	CPPUNIT_ASSERT_EQUAL(CST_STRING_UNKNOWN_1,out->str());
}

/*******************  FUNCTION  *********************/
void UnitTest_svutResultFormatterXml::testCloseTestMethod_unknown_2(void )
{
	UnitTestMockTestCase testCase;
	svutTestMethod meth("testMethod",SVUT_NO_LOCATION,NULL);
	formatter->setDisplayDetails(false);
	formatter->closeTestMethod(testCase,meth,SVUT_STATUS_UNKNOWN);
	CPPUNIT_ASSERT_EQUAL(CST_STRING_UNKNOWN_1,out->str());
}

/*******************  FUNCTION  *********************/
void UnitTest_svutResultFormatterXml::testCloseTestMethod_unknown_3(void )
{
	UnitTestMockTestCase testCase;
	svutTestMethod meth("testMethod",SVUT_NO_LOCATION,NULL);
	svutCodeLocation location("file.cpp","methode",33);
	svutStatusInfo info(SVUT_STATUS_UNKNOWN,"message for unknown status",location);
	formatter->closeTestMethod(testCase,meth,info);
	CPPUNIT_ASSERT_EQUAL(CST_STRING_UNKNOWN_3,out->str());
}

/*******************  FUNCTION  *********************/
void UnitTest_svutResultFormatterXml::testCloseTestMethod_failed_1(void )
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
void UnitTest_svutResultFormatterXml::testCloseTestMethod_failed_2(void )
{
	UnitTestMockTestCase testCase;
	svutTestMethod meth("testMethod",SVUT_NO_LOCATION,NULL);
	svutCodeLocation location("file.cpp","methode",33);
	svutStatusInfo info(SVUT_STATUS_FAILED,"message for failed status",location);
	info.addEntry("expected","toto");
	info.addEntry("actual","duck");
	formatter->setDisplayDetails(false);
	formatter->closeTestMethod(testCase,meth,info);
	CPPUNIT_ASSERT_EQUAL(CST_STRING_FAILED_1,out->str());
}

/*******************  FUNCTION  *********************/
void UnitTest_svutResultFormatterXml::runTotalSequence(void )
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
void UnitTest_svutResultFormatterXml::testGlobal_1(void )
{
	//FUCK THE STL, std::string.replace sucks.
	this->formatter->setDate("__DATE__");
	this->runTotalSequence();
	CPPUNIT_ASSERT_EQUAL(CST_STRING_SEQ_1,out->str());
}

/*******************  FUNCTION  *********************/
void UnitTest_svutResultFormatterXml::testGlobal_2(void )
{
	//FUCK THE STL, std::string.replace sucks.
	this->formatter->setDate("__DATE__");
	formatter->setDisplaySuccess(true);
	formatter->setDisplayDetails(false);
	this->runTotalSequence();
	CPPUNIT_ASSERT_EQUAL(CST_STRING_SEQ_1,out->str());
}

/*******************  FUNCTION  *********************/
void UnitTest_svutResultFormatterXml::testOpenOutput(void )
{
	this->formatter->setDate("__DATE__");
	formatter->openOutput();
	CPPUNIT_ASSERT_EQUAL(CST_STRING_OPEN,out->str());
}

/*******************  FUNCTION  *********************/
void UnitTest_svutResultFormatterXml::testOpenTestCase(void )
{
	UnitTestMockTestCase testCase;
	formatter->openTestCase(testCase);
	CPPUNIT_ASSERT_EQUAL(CST_STRING_TEST_CASE,out->str());
}

/*******************  FUNCTION  *********************/
void UnitTest_svutResultFormatterXml::testOpenTestMethod(void )
{
	UnitTestMockTestCase testCase;
	svutTestMethod meth("testMethod",SVUT_CODE_LOCATION,NULL);
	formatter->openTestMethod(testCase,meth);
	CPPUNIT_ASSERT_EQUAL(CST_STRING_OPEN_METH,out->str());
}

/*******************  FUNCTION  *********************/
void UnitTest_svutResultFormatterXml::testPrintSummary(void )
{
	svutResultSummary summary;
	formatter->printSummary(summary);
	CPPUNIT_ASSERT_EQUAL(CST_STRING_SUMMARY_0,out->str());
}

/*******************  FUNCTION  *********************/
void UnitTest_svutResultFormatterXml::testListingEnd(void )
{
	formatter->onListingEnd();
	CPPUNIT_ASSERT_EQUAL(CST_STRING_LISTING_END,out->str());
}

/*******************  FUNCTION  *********************/
void UnitTest_svutResultFormatterXml::testListingStart(void )
{
	formatter->onListingStart();
	CPPUNIT_ASSERT_EQUAL(CST_STRING_LISTING_START,out->str());
}

/*******************  FUNCTION  *********************/
void UnitTest_svutResultFormatterXml::testListMethod_1(void )
{
	UnitTestMockTestCase testCase;
	svutTestMethod meth("testMethod",SVUT_NO_LOCATION,NULL);
	formatter->onListMethod(testCase,meth);
	CPPUNIT_ASSERT_EQUAL(CST_STRING_LIST_METHOD,out->str());
}

/*******************  FUNCTION  *********************/
void UnitTest_svutResultFormatterXml::testListMethod_2(void )
{
	UnitTestMockTestCase testCase;
	svutTestMethod meth("testMethod",SVUT_NO_LOCATION,NULL);
	formatter->setDisplayFullName(true);
	formatter->onListMethod(testCase,meth);
	CPPUNIT_ASSERT_EQUAL(CST_STRING_LIST_METHOD,out->str());
}

/*******************  FUNCTION  *********************/
void UnitTest_svutResultFormatterXml::testCloseTestMethod_debugContext(void )
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

CPPUNIT_TEST_SUITE_REGISTRATION(UnitTest_svutResultFormatterXml);
