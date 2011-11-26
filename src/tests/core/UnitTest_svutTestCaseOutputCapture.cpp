/*****************************************************
             PROJECT  : svUnitTest
             VERSION  : 0.3.0
             DATE     : 05/2011
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
#include <svutListenerDirectOutputter.h>

/**********************  USING  *********************/
using namespace std;
using namespace svUnitTest;
using namespace CPPUNIT_NS;

/********************  CONSTS  ***********************/
static const char * CST_STRING_OUTPUT_0 = "=======  MockTestCaseForCapture                   ========\n\
 * testCout                                     [ FAILED ]\n\
- - - - - - - - - - - - - - - - - - - - - - - - - - - - - -\n\
Forced error\n\
line 157 of file " __FILE__ " on methode testCout()\n\
Output :\n\
   Call cout with 1 == 1\n\
   Call cout with 2 == 2\n\
- - - - - - - - - - - - - - - - - - - - - - - - - - - - - -\n";
static const char * CST_STRING_OUTPUT_1 = "=======  MockTestCaseForCapture                   ========\n";
static const char * CST_STRING_OUTPUT_2 = "=======  MockTestCaseForCapture                   ========\n\
 * testPrintf                                   [ FAILED ]\n\
- - - - - - - - - - - - - - - - - - - - - - - - - - - - - -\n\
Forced error\n\
line 165 of file " __FILE__ " on methode testPrintf()\n\
Output :\n\
   Call printf with 1 == 1\n\
   Call printf with 1 == 2\n\
- - - - - - - - - - - - - - - - - - - - - - - - - - - - - -\n";
static const char * CST_STRING_OUTPUT_3 = "=======  MockTestCaseForCapture                   ========\n\
 * testSVUT_COUT                                [ FAILED ]\n\
- - - - - - - - - - - - - - - - - - - - - - - - - - - - - -\n\
Forced error\n\
line 141 of file " __FILE__ " on methode testSVUT_COUT()\n\
Output :\n\
   Call SVUT_COUNT with 1 == 1\n\
   Call SVUT_COUNT with 2 == 2\n\
- - - - - - - - - - - - - - - - - - - - - - - - - - - - - -\n";
static const char * CST_STRING_OUTPUT_4 = "=======  MockTestCaseForCapture                   ========\n\
 * testSVUT_PRINTF                              [ FAILED ]\n\
- - - - - - - - - - - - - - - - - - - - - - - - - - - - - -\n\
Forced error\n\
line 149 of file " __FILE__ " on methode testSVUT_PRINTF()\n\
Output :\n\
   Call SVUT_PRINTF with 1 == 1\n\
   Call SVUT_PRINTF with 1 == 2\n\
- - - - - - - - - - - - - - - - - - - - - - - - - - - - - -\n";

/********************  CLASS  **********************/
class MockTestCaseForCapture : public svutTestCase
{
	public:
		enum UnitTestMockFlags
		{
			REGISTER_HIDE_IF_NO_ERROR,
			REGISTER_PRINTF,
			REGISTER_COUT,
			REGISTER_SVUT_PRINTF,
			REGISTER_SVUT_COUT,
			REGISTER_ALL
		};
	public:
		MockTestCaseForCapture();
		virtual void setUp(void );
		virtual void tearDown(void );

		void testHideIfNoError(void);
		void testPrintf(void);
		void testCout(void);
		void testSVUT_PRINTF(void);
		void testSVUT_COUT(void);

		void useTests(UnitTestMockFlags flags = REGISTER_ALL);
};

/********************  CLASS  **********************/
class UnitTest_svutTestCaseOutputCapture : public TestCase
{
	CPPUNIT_TEST_SUITE(UnitTest_svutTestCaseOutputCapture);
	CPPUNIT_TEST(testCaptureHideIfNoError);
	CPPUNIT_TEST(testCapturePrintf);
	CPPUNIT_TEST(testCaptureCout);
	CPPUNIT_TEST(testCaptureSVUT_PRINTF);
	CPPUNIT_TEST(testCaptureSVUT_COUT);
	CPPUNIT_TEST_SUITE_END();

	public:
		void setUp(void);
		void tearDown(void);

		void testCaptureHideIfNoError(void);
		void testCapturePrintf(void);
		void testCaptureCout(void);
		void testCaptureSVUT_PRINTF(void);
		void testCaptureSVUT_COUT(void);

	protected:
		svutListener * listener;
		MockTestCaseForCapture * obj;
		svutResultFormatterStdBW * formatter;
		stringstream * out;
};

/********************  CLASS  **********************/
MockTestCaseForCapture::MockTestCaseForCapture()
	:svutTestCase("MockTestCaseForCapture")
{

}

/*******************  FUNCTION  *********************/
void MockTestCaseForCapture::setUp(void )
{

}

/*******************  FUNCTION  *********************/
void MockTestCaseForCapture::tearDown(void )
{

}

/*******************  FUNCTION  *********************/
void MockTestCaseForCapture::testSVUT_COUT(void )
{
	SVUT_COUT << "Call SVUT_COUNT with 1 == " << 1 << endl;
	SVUT_COUT << "Call SVUT_COUNT with 2 == " << 2 << endl;
	SVUT_ASSERT_FAIL("Forced error");
}

/*******************  FUNCTION  *********************/
void MockTestCaseForCapture::testSVUT_PRINTF(void )
{
	SVUT_PRINTF("Call SVUT_PRINTF with 1 == %d\n",1);
	SVUT_PRINTF("Call SVUT_PRINTF with 1 == %d\n",2);
	SVUT_ASSERT_FAIL("Forced error");
}

/*******************  FUNCTION  *********************/
void MockTestCaseForCapture::testCout(void )
{
	cout << "Call cout with 1 == " << 1 << endl;
	cout << "Call cout with 2 == " << 2 << endl;
	SVUT_ASSERT_FAIL("Forced error");
}

/*******************  FUNCTION  *********************/
void MockTestCaseForCapture::testPrintf(void )
{
	printf("Call printf with 1 == %d\n",1);
	printf("Call printf with 1 == %d\n",2);
	SVUT_ASSERT_FAIL("Forced error");
}

/*******************  FUNCTION  *********************/
void MockTestCaseForCapture::testHideIfNoError(void )
{
	SVUT_COUT << "Call SVUT_COUNT with 1 == " << 1 << endl;
	SVUT_PRINTF("Call SVUT_PRINTF with 1 == %d\n",2);
	cout << "Call cout with 2 == " << 2 << endl;
	printf("Call printf with 1 == %d\n",1);
}

/*******************  FUNCTION  *********************/
void MockTestCaseForCapture::useTests(MockTestCaseForCapture::UnitTestMockFlags flags)
{
	switch (flags)
	{
		case REGISTER_HIDE_IF_NO_ERROR: SVUT_REG_TEST_METHOD(testHideIfNoError); break;
		case REGISTER_PRINTF : SVUT_REG_TEST_METHOD(testPrintf); break;
		case REGISTER_COUT : SVUT_REG_TEST_METHOD(testCout); break;
		case REGISTER_SVUT_PRINTF : SVUT_REG_TEST_METHOD(testSVUT_PRINTF); break;
		case REGISTER_SVUT_COUT : SVUT_REG_TEST_METHOD(testSVUT_COUT); break;
		case REGISTER_ALL:
			SVUT_REG_TEST_METHOD(testHideIfNoError);
			SVUT_REG_TEST_METHOD(testPrintf);
			SVUT_REG_TEST_METHOD(testCout);
			SVUT_REG_TEST_METHOD(testSVUT_PRINTF);
			SVUT_REG_TEST_METHOD(testSVUT_COUT);
			break;
		default:
			assert(false);
	}
}

/*******************  FUNCTION  *********************/
void UnitTest_svutTestCaseOutputCapture::setUp(void )
{
	obj = new MockTestCaseForCapture;
	out = new stringstream;
	formatter = new svutResultFormatterStdBW(*out);
	listener = new svutListenerDirectOutputter(*formatter);
}

/*******************  FUNCTION  *********************/
void UnitTest_svutTestCaseOutputCapture::tearDown(void )
{
	if (formatter != NULL)
		delete formatter;
	if (out != NULL)
		delete out;
	if (listener != NULL)
		delete listener;
	if (obj != NULL)
		delete obj;
	formatter = NULL;
	out = NULL;
	listener = NULL;
	obj = NULL;
}

/********************  CLASS  **********************/
void UnitTest_svutTestCaseOutputCapture::testCaptureCout(void )
{
	obj->useTests(MockTestCaseForCapture::REGISTER_COUT);
	obj->runTestCase(listener);
	//cout << endl << out->str() << endl;
	CPPUNIT_ASSERT_EQUAL(CST_STRING_OUTPUT_0,out->str());
}

/********************  CLASS  **********************/
void UnitTest_svutTestCaseOutputCapture::testCaptureHideIfNoError(void )
{
	obj->useTests(MockTestCaseForCapture::REGISTER_HIDE_IF_NO_ERROR);
	obj->runTestCase(listener);
	//cout << endl << out->str() << endl;
	CPPUNIT_ASSERT_EQUAL(CST_STRING_OUTPUT_1,out->str());
}

/********************  CLASS  **********************/
void UnitTest_svutTestCaseOutputCapture::testCapturePrintf(void )
{
	obj->useTests(MockTestCaseForCapture::REGISTER_PRINTF);
	obj->runTestCase(listener);
	//cout << endl << out->str() << endl;
	CPPUNIT_ASSERT_EQUAL(CST_STRING_OUTPUT_2,out->str());
}

/********************  CLASS  **********************/
void UnitTest_svutTestCaseOutputCapture::testCaptureSVUT_COUT(void )
{
	obj->useTests(MockTestCaseForCapture::REGISTER_SVUT_COUT);
	obj->runTestCase(listener);
	//cout << endl << out->str() << endl;
	CPPUNIT_ASSERT_EQUAL(CST_STRING_OUTPUT_3,out->str());
}

/********************  CLASS  **********************/
void UnitTest_svutTestCaseOutputCapture::testCaptureSVUT_PRINTF(void )
{
	obj->useTests(MockTestCaseForCapture::REGISTER_SVUT_PRINTF);
	obj->runTestCase(listener);
	//cout << endl << out->str() << endl;
	CPPUNIT_ASSERT_EQUAL(CST_STRING_OUTPUT_4,out->str());
}

CPPUNIT_TEST_SUITE_REGISTRATION(UnitTest_svutTestCaseOutputCapture);

