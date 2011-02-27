/*****************************************************
             PROJECT  : svUnitTest
             VERSION  : 0.2.0
             DATE     : 02/2011
             AUTHOR   : Valat Sébastien
             LICENSE  : CeCILL-C
*****************************************************/

/********************  HEADERS  *********************/
#include "UnitTestExtra.h"
#include <iostream>
#include <cppunit/TestCase.h>
#include <cppunit/extensions/TestFactoryRegistry.h>
#include <cppunit/extensions/HelperMacros.h>
#include <svutResultFormatterQtXml.h>
#include "UnitTestMockTestCase.h"
#include <sys/stat.h>

/**********************  USING  *********************/
using namespace std;
using namespace svUnitTest;
using namespace CPPUNIT_NS;

/********************  CONSTS  ***********************/
static const char * CST_STRING_SUMMARY_0 = "";
static const char * CST_STRING_UNKNOWN_1 = "\t\t<Incident type='fail' file='unknown' line='0'>\n\
\t\t\t<Description><![CDATA[]]></Description>\n\
\t\t</Incident>\n\
\t</TestFunction>\n";
static const char * CST_STRING_UNKNOWN_3 = "\t\t<Incident type='fail' file='file.cpp' line='33'>\n\
\t\t\t<Description><![CDATA[message for unknown status]]></Description>\n\
\t\t</Incident>\n\
\t</TestFunction>\n";
static const char * CST_STRING_SUCCESS_1 = "\t\t<Incident type='pass' file='unknown' line='0'></Incident>\n\t</TestFunction>\n";
static const char * CST_STRING_TODO      = "\t\t<Incident type='warn' file='unknown' line='0'></Incident>\n\t</TestFunction>\n";
static const char * CST_STRING_INDEV     = "\t\t<Incident type='warn' file='unknown' line='0'></Incident>\n\t</TestFunction>\n";
static const char * CST_STRING_SKIPED    = "\t\t<Incident type='warn' file='unknown' line='0'></Incident>\n\t</TestFunction>\n";
static const char * CST_STRING_TEST_CASE = "";
static const char * CST_STRING_FAILED_1  = "\t\t<Incident type='fail' file='file.cpp' line='33'>\n\
\t\t\t<Description><![CDATA[message for failed status\n\
   - actual : duck\n\
   - expected : toto\n\
]]></Description>\n\
\t\t</Incident>\n\
\t</TestFunction>\n";
static const char * CST_STRING_SEQ_1    = "<?xml version='1.0' encoding='UTF-8'?>\n\
<TestCase name='svUnitTest'>\n\
	<Environment>\n\
		<svUnitTestVersion>0.2.0</svUnitTestVersion>\n\
	</Environment>\n\
	<TestFunction name='MyTest::testMethod'>\n\
		<Incident type='pass' file='unknown' line='0'></Incident>\n\
	</TestFunction>\n\
	<TestFunction name='MyTest::testMethod'>\n\
		<Incident type='warn' file='unknown' line='0'></Incident>\n\
	</TestFunction>\n\
	<TestFunction name='MyTest::testMethod'>\n\
		<Incident type='pass' file='unknown' line='0'></Incident>\n\
	</TestFunction>\n\
	<TestFunction name='MyTest::testMethod'>\n\
		<Incident type='warn' file='unknown' line='0'></Incident>\n\
	</TestFunction>\n\
	<TestFunction name='MyTest::testMethod'>\n\
		<Incident type='warn' file='unknown' line='0'></Incident>\n\
	</TestFunction>\n\
	<TestFunction name='MyTest::testMethod'>\n\
		<Incident type='pass' file='unknown' line='0'></Incident>\n\
	</TestFunction>\n\
	<TestFunction name='MyTest::testMethod'>\n\
		<Incident type='fail' file='file.cpp' line='33'>\n\
			<Description><![CDATA[message for unknown status\n\
   - actual : duck\n\
   - expected : toto\n\
]]></Description>\n\
		</Incident>\n\
	</TestFunction>\n\
		<Incident type='fail' file='file.cpp' line='33'>\n\
			<Description><![CDATA[message for unknown status]]></Description>\n\
		</Incident>\n\
	</TestFunction>\n\
</TestCase>\n";
static const char * CST_STRING_SEQ_2    = "<?xml version='1.0' encoding='UTF-8'?>\n\
<TestCase name='svUnitTest'>\n\
	<Environment>\n\
		<svUnitTestVersion>0.2.0</svUnitTestVersion>\n\
	</Environment>\n\
	<TestFunction name='testMethod'>\n\
		<Incident type='pass' file='unknown' line='0'></Incident>\n\
	</TestFunction>\n\
	<TestFunction name='testMethod'>\n\
		<Incident type='warn' file='unknown' line='0'></Incident>\n\
	</TestFunction>\n\
	<TestFunction name='testMethod'>\n\
		<Incident type='pass' file='unknown' line='0'></Incident>\n\
	</TestFunction>\n\
	<TestFunction name='testMethod'>\n\
		<Incident type='warn' file='unknown' line='0'></Incident>\n\
	</TestFunction>\n\
	<TestFunction name='testMethod'>\n\
		<Incident type='warn' file='unknown' line='0'></Incident>\n\
	</TestFunction>\n\
	<TestFunction name='testMethod'>\n\
		<Incident type='pass' file='unknown' line='0'></Incident>\n\
	</TestFunction>\n\
	<TestFunction name='testMethod'>\n\
		<Incident type='fail' file='file.cpp' line='33'>\n\
			<Description><![CDATA[message for unknown status\n\
   - actual : duck\n\
   - expected : toto\n\
]]></Description>\n\
		</Incident>\n\
	</TestFunction>\n\
		<Incident type='fail' file='file.cpp' line='33'>\n\
			<Description><![CDATA[message for unknown status]]></Description>\n\
		</Incident>\n\
	</TestFunction>\n\
</TestCase>\n";
static const char * CST_STRING_OPEN = "<?xml version='1.0' encoding='UTF-8'?>\n\
<TestCase name='svUnitTest'>\n\
	<Environment>\n\
		<svUnitTestVersion>0.2.0</svUnitTestVersion>\n\
	</Environment>\n";
static const char * CST_STRING_CLOSE = "</TestCase>\n";
static const char * CST_STRING_CLOSE_TC = "";
static const char * CST_STRING_OPEN_METH_1 = "\t<TestFunction name='testMethod'>\n";
static const char * CST_STRING_OPEN_METH_2 = "\t<TestFunction name='MyTest::testMethod'>\n";

/********************  CLASS  **********************/
class UnitTest_svutResultFormatterQtXml : public TestCase
{
	CPPUNIT_TEST_SUITE(UnitTest_svutResultFormatterQtXml);
	CPPUNIT_TEST(testOpenOutput);
	CPPUNIT_TEST(testCloseOutput);
	CPPUNIT_TEST(testOpenTestCase);
	CPPUNIT_TEST(testCloseTestCase);
	CPPUNIT_TEST(testOpenTestMethod_1);
	CPPUNIT_TEST(testOpenTestMethod_2);
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
	CPPUNIT_TEST(testGlobal_3);
	CPPUNIT_TEST_SUITE_END();

	public:
		void setUp(void);
		void tearDown(void);

		void testOpenOutput(void);
		void testCloseOutput(void);
		void testOpenTestCase(void);
		void testCloseTestCase(void);
		void testOpenTestMethod_1(void);
		void testOpenTestMethod_2(void);
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
		void testGlobal_3(void);
	protected:
		void runTotalSequence(void);
		svutResultFormatterQtXml * formatter;
		stringstream * out;
};

/*******************  FUNCTION  *********************/
void UnitTest_svutResultFormatterQtXml::setUp(void)
{
	out = new stringstream;
	formatter = new svutResultFormatterQtXml(*out);
}

/*******************  FUNCTION  *********************/
void UnitTest_svutResultFormatterQtXml::tearDown(void)
{
	delete formatter;
	delete out;
}

/*******************  FUNCTION  *********************/
void UnitTest_svutResultFormatterQtXml::testCloseOutput(void )
{
	formatter->closeOutput();
	CPPUNIT_ASSERT_EQUAL(CST_STRING_CLOSE,out->str());
}

/*******************  FUNCTION  *********************/
void UnitTest_svutResultFormatterQtXml::testCloseTestCase(void )
{
	UnitTestMockTestCase testCase;
	formatter->closeTestCase(testCase);
	CPPUNIT_ASSERT_EQUAL(CST_STRING_CLOSE_TC,out->str());
}

/*******************  FUNCTION  *********************/
void UnitTest_svutResultFormatterQtXml::testCloseTestMethod_success_1(void )
{
	UnitTestMockTestCase testCase;
	svutTestMethod meth("testMethod",NULL,SVUT_NO_LOCATION);
	formatter->closeTestMethod(testCase,meth,SVUT_STATUS_SUCCESS);
	CPPUNIT_ASSERT_EQUAL(CST_STRING_SUCCESS_1,out->str());
}

/*******************  FUNCTION  *********************/
void UnitTest_svutResultFormatterQtXml::testCloseTestMethod_success_2(void )
{
	UnitTestMockTestCase testCase;
	svutTestMethod meth("testMethod",NULL,SVUT_NO_LOCATION);
	formatter->setDisplaySuccess(true);
	formatter->closeTestMethod(testCase,meth,SVUT_STATUS_SUCCESS);
	CPPUNIT_ASSERT_EQUAL(CST_STRING_SUCCESS_1,out->str());
}

/*******************  FUNCTION  *********************/
void UnitTest_svutResultFormatterQtXml::testCloseTestMethod_fullname(void )
{
	UnitTestMockTestCase testCase;
	svutTestMethod meth("testMethod",NULL,SVUT_NO_LOCATION);
	formatter->setDisplaySuccess(true);
	formatter->setDisplayFullName(true);
	formatter->closeTestMethod(testCase,meth,SVUT_STATUS_SUCCESS);
	CPPUNIT_ASSERT_EQUAL(CST_STRING_SUCCESS_1,out->str());
}

/*******************  FUNCTION  *********************/
void UnitTest_svutResultFormatterQtXml::testCloseTestMethod_todo(void )
{
	UnitTestMockTestCase testCase;
	svutTestMethod meth("testMethod",NULL,SVUT_NO_LOCATION);
	formatter->closeTestMethod(testCase,meth,SVUT_STATUS_TODO);
	CPPUNIT_ASSERT_EQUAL(CST_STRING_TODO,out->str());
}

/*******************  FUNCTION  *********************/
void UnitTest_svutResultFormatterQtXml::testCloseTestMethod_indev(void )
{
	UnitTestMockTestCase testCase;
	svutTestMethod meth("testMethod",NULL,SVUT_NO_LOCATION);
	formatter->closeTestMethod(testCase,meth,SVUT_STATUS_INDEV);
	CPPUNIT_ASSERT_EQUAL(CST_STRING_INDEV,out->str());
}

/*******************  FUNCTION  *********************/
void UnitTest_svutResultFormatterQtXml::testCloseTestMethod_skiped(void )
{
	UnitTestMockTestCase testCase;
	svutTestMethod meth("testMethod",NULL,SVUT_NO_LOCATION);
	formatter->closeTestMethod(testCase,meth,SVUT_STATUS_SKIPED);
	CPPUNIT_ASSERT_EQUAL(CST_STRING_SKIPED,out->str());
}

/*******************  FUNCTION  *********************/
void UnitTest_svutResultFormatterQtXml::testCloseTestMethod_unknown_1(void )
{
	UnitTestMockTestCase testCase;
	svutTestMethod meth("testMethod",NULL,SVUT_NO_LOCATION);
	formatter->closeTestMethod(testCase,meth,SVUT_STATUS_UNKNOWN);
	CPPUNIT_ASSERT_EQUAL(CST_STRING_UNKNOWN_1,out->str());
}

/*******************  FUNCTION  *********************/
void UnitTest_svutResultFormatterQtXml::testCloseTestMethod_unknown_2(void )
{
	UnitTestMockTestCase testCase;
	svutTestMethod meth("testMethod",NULL,SVUT_NO_LOCATION);
	formatter->setDisplayDetails(false);
	formatter->closeTestMethod(testCase,meth,SVUT_STATUS_UNKNOWN);
	CPPUNIT_ASSERT_EQUAL(CST_STRING_UNKNOWN_1,out->str());
}

/*******************  FUNCTION  *********************/
void UnitTest_svutResultFormatterQtXml::testCloseTestMethod_unknown_3(void )
{
	UnitTestMockTestCase testCase;
	svutTestMethod meth("testMethod",NULL,SVUT_NO_LOCATION);
	svutCodeLocation location("file.cpp","methode",33);
	svutStatusInfo info(SVUT_STATUS_UNKNOWN,"message for unknown status",location);
	formatter->closeTestMethod(testCase,meth,info);
	CPPUNIT_ASSERT_EQUAL(CST_STRING_UNKNOWN_3,out->str());
}

/*******************  FUNCTION  *********************/
void UnitTest_svutResultFormatterQtXml::testCloseTestMethod_failed_1(void )
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
void UnitTest_svutResultFormatterQtXml::testCloseTestMethod_failed_2(void )
{
	UnitTestMockTestCase testCase;
	svutTestMethod meth("testMethod",NULL,SVUT_NO_LOCATION);
	svutCodeLocation location("file.cpp","methode",33);
	svutStatusInfo info(SVUT_STATUS_FAILED,"message for failed status",location);
	info.addEntry("expected","toto");
	info.addEntry("actual","duck");
	formatter->setDisplayDetails(false);
	formatter->closeTestMethod(testCase,meth,info);
	CPPUNIT_ASSERT_EQUAL(CST_STRING_FAILED_1,out->str());
}

/*******************  FUNCTION  *********************/
void UnitTest_svutResultFormatterQtXml::runTotalSequence(void )
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
void UnitTest_svutResultFormatterQtXml::testGlobal_1(void )
{
	this->runTotalSequence();
	CPPUNIT_ASSERT_EQUAL(CST_STRING_SEQ_2,out->str());
}

/*******************  FUNCTION  *********************/
void UnitTest_svutResultFormatterQtXml::testGlobal_2(void )
{
	formatter->setDisplaySuccess(true);
	formatter->setDisplayDetails(false);
	this->runTotalSequence();
	CPPUNIT_ASSERT_EQUAL(CST_STRING_SEQ_2,out->str());
}

/*******************  FUNCTION  *********************/
void UnitTest_svutResultFormatterQtXml::testGlobal_3(void )
{
	formatter->setDisplayFullName(true);
	this->runTotalSequence();
	CPPUNIT_ASSERT_EQUAL(CST_STRING_SEQ_1,out->str());
}

/*******************  FUNCTION  *********************/
void UnitTest_svutResultFormatterQtXml::testOpenOutput(void )
{
	formatter->openOutput();
	CPPUNIT_ASSERT_EQUAL(CST_STRING_OPEN,out->str());
}

/*******************  FUNCTION  *********************/
void UnitTest_svutResultFormatterQtXml::testOpenTestCase(void )
{
	UnitTestMockTestCase testCase;
	formatter->openTestCase(testCase);
	CPPUNIT_ASSERT_EQUAL(CST_STRING_TEST_CASE,out->str());
}

/*******************  FUNCTION  *********************/
void UnitTest_svutResultFormatterQtXml::testOpenTestMethod_1(void )
{
	UnitTestMockTestCase testCase;
	svutTestMethod meth("testMethod",NULL,SVUT_CODE_LOCATION);
	formatter->openTestMethod(testCase,meth);
	CPPUNIT_ASSERT_EQUAL(CST_STRING_OPEN_METH_1,out->str());
}

/*******************  FUNCTION  *********************/
void UnitTest_svutResultFormatterQtXml::testOpenTestMethod_2(void )
{
	UnitTestMockTestCase testCase;
	svutTestMethod meth("testMethod",NULL,SVUT_CODE_LOCATION);
	formatter->setDisplayFullName(true);
	formatter->openTestMethod(testCase,meth);
	CPPUNIT_ASSERT_EQUAL(CST_STRING_OPEN_METH_2,out->str());
}


/*******************  FUNCTION  *********************/
void UnitTest_svutResultFormatterQtXml::testPrintSummary(void )
{
	svutResultSummary summary;
	formatter->printSummary(summary);
	CPPUNIT_ASSERT_EQUAL(CST_STRING_SUMMARY_0,out->str());
}

CPPUNIT_TEST_SUITE_REGISTRATION(UnitTest_svutResultFormatterQtXml);
