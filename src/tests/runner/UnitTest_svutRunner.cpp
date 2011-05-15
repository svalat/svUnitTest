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
#include <svutRunner.h>
#include <svutListenerDirectOutputter.h>
#include <svutRunnerConfig.h>
#include "UnitTestExtra.h"
#include "UnitTestMockResultFormatter.h"
#include "UnitTestMockTestCase2.h"
#include <svutResultFormatterStdBW.h>

/**********************  USING  *********************/
using namespace svUnitTest;
using namespace std;
using namespace CPPUNIT_NS;

static const char * CST_STRING_OUTPUT_0 = "=======  UnitTestMockTestCase2                    ========\n\
 * testFailure                                  [ FAILED ]\n\
- - - - - - - - - - - - - - - - - - - - - - - - - - - - - -\n\
Failed on expected value.\n\
line 52 of file " TEST_SRC_BASE_PATH "/UnitTestMockTestCase2.cpp on methode testFailure()\n\
   - Actual : 3\n\
   - Expected : 2\n\
- - - - - - - - - - - - - - - - - - - - - - - - - - - - - -\n\
 * testTodo                                     [ TODO ]\n\
 * testIndev                                    [ INDEV ]\n\
 * testUnknown_1                                [ UNKNOWN ]\n\
- - - - - - - - - - - - - - - - - - - - - - - - - - - - - -\n\
Unexpected std exception : std::bad_exception\n\
line 144 of file " TEST_SRC_BASE_PATH "/UnitTestMockTestCase2.cpp on methode useTests()\n\
- - - - - - - - - - - - - - - - - - - - - - - - - - - - - -\n\
 * testUnknown_2                                [ UNKNOWN ]\n\
- - - - - - - - - - - - - - - - - - - - - - - - - - - - - -\n\
Unexpected exception.\n\
line 145 of file " TEST_SRC_BASE_PATH "/UnitTestMockTestCase2.cpp on methode useTests()\n\
- - - - - - - - - - - - - - - - - - - - - - - - - - - - - -\n\
 * testFailIsTodo_1                             [ TODO ]\n\
 * testFailIsTodo_2                             [ TODO ]\n\
 * testFailIsTodo_3                             [ TODO ]\n\
 * testSuccessIsIndev                           [ INDEV ]\n\
 * testDebugContext                             [ FAILED ]\n\
- - - - - - - - - - - - - - - - - - - - - - - - - - - - - -\n\
Failed on expected value.\n\
line 98 of file " TEST_SRC_BASE_PATH "/UnitTestMockTestCase2.cpp on methode testDebugContext()\n\
   - Actual : 3\n\
   - Expected : 2\n\
Context :\n\
   - test : value\n\
- - - - - - - - - - - - - - - - - - - - - - - - - - - - - -\n\
\n\
+---------------------------+\n\
|    SUMMARY                |\n\
+---------------------------+\n\
|  SUCCESS  :    1 (  9 %)  |\n\
|  INDEV    :    2 ( 18 %)  |\n\
|  TODO     :    4 ( 36 %)  |\n\
|  FAILED   :    2 ( 18 %)  |\n\
|  UNKNOWN  :    2 ( 18 %)  |\n\
+---------------------------+\n\
|  TOTAL    :   11          |\n\
|  STATUS   : UNKNOWN       |\n\
+---------------------------+\n";
static const char * CST_STRING_OUTPUT_1 = "openOutput(); openTestCase(UnitTestMockTestCase2); openT\
estMethod(UnitTestMockTestCase2, testSuccess); closeTestMethod(UnitTestMockTestCase2, testSuccess, \
SUCCESS); openTestMethod(UnitTestMockTestCase2, testFailure); closeTestMethod(UnitTestMockTestCase2\
, testFailure, FAILED); openTestMethod(UnitTestMockTestCase2, testTodo); closeTestMethod(UnitTestMo\
ckTestCase2, testTodo, TODO); openTestMethod(UnitTestMockTestCase2, testIndev); closeTestMethod(Uni\
tTestMockTestCase2, testIndev, INDEV); openTestMethod(UnitTestMockTestCase2, testUnknown_1); closeT\
estMethod(UnitTestMockTestCase2, testUnknown_1, UNKNOWN); openTestMethod(UnitTestMockTestCase2, tes\
tUnknown_2); closeTestMethod(UnitTestMockTestCase2, testUnknown_2, UNKNOWN); openTestMethod(UnitTes\
tMockTestCase2, testFailIsTodo_1); closeTestMethod(UnitTestMockTestCase2, testFailIsTodo_1, TODO); \
openTestMethod(UnitTestMockTestCase2, testFailIsTodo_2); closeTestMethod(UnitTestMockTestCase2, tes\
tFailIsTodo_2, TODO); openTestMethod(UnitTestMockTestCase2, testFailIsTodo_3); closeTestMethod(Unit\
TestMockTestCase2, testFailIsTodo_3, TODO); openTestMethod(UnitTestMockTestCase2, testSuccessIsInde\
v); closeTestMethod(UnitTestMockTestCase2, testSuccessIsIndev, INDEV); openTestMethod(UnitTestMockT\
estCase2, testDebugContext); closeTestMethod(UnitTestMockTestCase2, testDebugContext, FAILED); clos\
eTestCase(UnitTestMockTestCase2); success=1, failed=2, todo=4, indev=2, unknown=2, skiped=0; closeO\
utput(); ";
static const char * CST_STRING_OUTPUT_2 = "openOutput(); openTestCase(UnitTestMockTestCase2); openTestMethod(UnitTestMockTestCase2, testSuccess); closeTestMethod(UnitTestMockTestCase2, testSuccess, SUCCESS); closeTestCase(UnitTestMockTestCase2); success=1, failed=0, todo=0, indev=0, unknown=0, skiped=0; closeOutput(); ";
static const char * CST_STRING_OUTPUT_3 = "openOutput(); openTestCase(UnitTestMockTestCase2); openTestMethod(UnitTestMockTestCase2, testFailure); closeTestMethod(UnitTestMockTestCase2, testFailure, FAILED); closeTestCase(UnitTestMockTestCase2); success=0, failed=1, todo=0, indev=0, unknown=0, skiped=0; closeOutput(); ";
static const char * CST_STRING_OUTPUT_4 = "=======  UnitTestMockTestCase2                    ========\n\
 * testSuccess                                  [ SUCCESS ]\n\
 * testFailure                                  [ FAILED ]\n\
 * testTodo                                     [ TODO ]\n\
 * testIndev                                    [ INDEV ]\n\
 * testUnknown_1                                [ UNKNOWN ]\n\
 * testUnknown_2                                [ UNKNOWN ]\n\
 * testFailIsTodo_1                             [ TODO ]\n\
 * testFailIsTodo_2                             [ TODO ]\n\
 * testFailIsTodo_3                             [ TODO ]\n\
 * testSuccessIsIndev                           [ INDEV ]\n\
 * testDebugContext                             [ FAILED ]\n\
\n\
+---------------------------+\n\
|    SUMMARY                |\n\
+---------------------------+\n\
|  SUCCESS  :    1 (  9 %)  |\n\
|  INDEV    :    2 ( 18 %)  |\n\
|  TODO     :    4 ( 36 %)  |\n\
|  FAILED   :    2 ( 18 %)  |\n\
|  UNKNOWN  :    2 ( 18 %)  |\n\
+---------------------------+\n\
|  TOTAL    :   11          |\n\
|  STATUS   : UNKNOWN       |\n\
+---------------------------+\n";
static const char * CST_STRING_OUTPUT_5 = "openOutput(); openTestCase(UnitTestMockTestCase2); closeTestCase(UnitTestMockTestCase2); success=0, failed=0, todo=0, indev=0, unknown=0, skiped=0; closeOutput(); ";
static const char * CST_STRING_OUTPUT_6 = "testSuccess()\n\
testFailure()\n\
testTodo()\n\
testIndev()\n\
testUnknown_1()\n\
testUnknown_2()\n\
testFailIsTodo_1()\n\
testFailIsTodo_2()\n\
testFailIsTodo_3()\n\
testSuccessIsIndev()\n\
testDebugContext()\n";
static const char * CST_STRING_OUTPUT_7 = "testSuccess()\n\
testTodo()\n\
testIndev()\n";
static const char * CST_STRING_OUTPUT_8 = "openOutput(); openTestCase(UnitTestMockTestCase2); openTestMethod(UnitTestMockTestCase2, testSuccess); closeTestMethod(UnitTestMockTestCase2, testSuccess, SUCCESS); closeTestCase(UnitTestMockTestCase2); success=1, failed=0, todo=0, indev=0, unknown=0, skiped=0; closeOutput(); ";
static const char * CST_STRING_OUTPUT_9 = "openOutput(); openTestCase(MockTestUnload); closeTestCase(MockTestUnload); success=0, failed=0, todo=0, indev=0, unknown=0, skiped=0; closeOutput(); ";

/*********************  CLASS  **********************/
static bool UnitTest_svutRunner_MockStatus = false;
class UnitTestMockTestUnload : public svutTestCase
{
	public:
		UnitTestMockTestUnload();
		virtual ~UnitTestMockTestUnload();
		virtual void setUp(void ){}
		virtual void tearDown(void ){}
};

/*********************  CLASS  **********************/
class UnitTest_svutRunner : public TestCase
{
	CPPUNIT_TEST_SUITE(UnitTest_svutRunner);
	CPPUNIT_TEST(testConstructor_default);
	CPPUNIT_TEST(testConstructor_mode);
	CPPUNIT_TEST(testConstructor_mode_output);
	CPPUNIT_TEST(testConstructor_formatter);
	CPPUNIT_TEST(testConstructor_listener);
	CPPUNIT_TEST(testConstructor_config);
	CPPUNIT_TEST(testRun_1);
	CPPUNIT_TEST(testRun_2);
	CPPUNIT_TEST(testSetDisplay_1);
	CPPUNIT_TEST(testSetDisplay_2);
	CPPUNIT_TEST(testSetDisplay_3);
	CPPUNIT_TEST(testLoadAutoDetected_1);
	CPPUNIT_TEST(testLoadAutoDetected_2);
	CPPUNIT_TEST(testLoadAutoDetected_3);
	CPPUNIT_TEST(testUnloadAutoDetected);
	CPPUNIT_TEST(testRegisterTestCase);
	CPPUNIT_TEST(testListTests_1);
	CPPUNIT_TEST(testListTests_2);
	CPPUNIT_TEST(testSetFilter);
	CPPUNIT_TEST(testSetFilterNull);
	CPPUNIT_TEST(testConfigFilter);
	CPPUNIT_TEST(testFilterTestExecution);
	CPPUNIT_TEST_SUITE_END();

	public:
		void setUp(void);
		void tearDown(void);
	protected:
		void testConstructor_default(void);
		void testConstructor_mode(void);
		void testConstructor_mode_output(void);
		void testConstructor_formatter(void);
		void testConstructor_listener(void);
		void testConstructor_config(void);
		void testRun_1(void);
		void testRun_2(void);
		void testSetDisplay_1(void);
		void testSetDisplay_2(void);
		void testSetDisplay_3(void);
		void testLoadAutoDetected_1(void);
		void testLoadAutoDetected_2(void);
		void testLoadAutoDetected_3(void);
		void testUnloadAutoDetected(void);
		void testRegisterTestCase(void);
		void testListTests_1(void);
		void testListTests_2(void);
		void testSetFilter(void);
		void testSetFilterNull(void);
		void testConfigFilter(void);
		void testFilterTestExecution(void);

		svutRunner * runner;
		UnitTestMockResultFormater * formatter;
		UnitTestMockTestCase2 * mock;
};

/*******************  FUNCTION  *********************/
void UnitTest_svutRunner::setUp(void)
{
	this->formatter = new UnitTestMockResultFormater();
	this->runner = new svutRunner(*this->formatter);
	this->mock = new UnitTestMockTestCase2();
	clearTestCaseRegister();
}

/*******************  FUNCTION  *********************/
void UnitTest_svutRunner::tearDown(void)
{
	delete this->runner;
	delete this->formatter;
	delete this->mock;
	clearTestCaseRegister();
}

/*******************  FUNCTION  *********************/
void UnitTest_svutRunner::testConstructor_default(void)
{
	svutRunner localRunner;
}

/*******************  FUNCTION  *********************/
void UnitTest_svutRunner::testConstructor_mode(void)
{
	svutRunner localRunner(SVUT_OUT_STD_BW);
}

/*******************  FUNCTION  *********************/
void UnitTest_svutRunner::testConstructor_mode_output(void)
{
	stringstream ss;
	svutRunner localRunner(SVUT_OUT_STD_BW,ss);
	this->mock->useTests(UnitTestMockTestCase2::REGISTER_ALL);
	localRunner.registerTestCase(*mock);
	CPPUNIT_ASSERT_EQUAL(false,localRunner.run());
	CPPUNIT_ASSERT_EQUAL(CST_STRING_OUTPUT_0,ss.str());
}

/*******************  FUNCTION  *********************/
void UnitTest_svutRunner::testConstructor_formatter(void)
{
	stringstream ss;
	svutRunner localRunner(*formatter);
	this->mock->useTests(UnitTestMockTestCase2::REGISTER_ALL);
	localRunner.registerTestCase(*mock);
	CPPUNIT_ASSERT_EQUAL(false,localRunner.run());
	ss << *formatter;
	CPPUNIT_ASSERT_EQUAL(CST_STRING_OUTPUT_1,ss.str());
}

/*******************  FUNCTION  *********************/
void UnitTest_svutRunner::testConstructor_listener(void)
{
	stringstream ss;
	svutListenerDirectOutputter listener(*formatter);
	svutRunner localRunner(listener);
	this->mock->useTests(UnitTestMockTestCase2::REGISTER_ALL);
	localRunner.registerTestCase(*mock);
	CPPUNIT_ASSERT_EQUAL(false,localRunner.run());
	ss << *formatter;
	CPPUNIT_ASSERT_EQUAL(CST_STRING_OUTPUT_1,ss.str());
}

/*******************  FUNCTION  *********************/
void UnitTest_svutRunner::testConstructor_config(void)
{
	stringstream ss;
	svutRunnerConfig config;
	config.setOutput(ss);
	config.setMode(SVUT_OUT_STD_BW);
	this->mock->useTests(UnitTestMockTestCase2::REGISTER_ALL);
	svutRunner localRunner(config);
	localRunner.registerTestCase(*mock);
	CPPUNIT_ASSERT_EQUAL(false,localRunner.run());
	ss << *formatter;
	CPPUNIT_ASSERT_EQUAL(CST_STRING_OUTPUT_0,ss.str());
}

/*******************  FUNCTION  *********************/
void UnitTest_svutRunner::testRun_1(void)
{
	stringstream ss;
	svutRunner localRunner(*formatter);
	this->mock->useTests(UnitTestMockTestCase2::REGISTER_SUCCESS);
	localRunner.registerTestCase(*mock);
	CPPUNIT_ASSERT_EQUAL(true,localRunner.run());
	ss << *formatter;
	CPPUNIT_ASSERT_EQUAL(CST_STRING_OUTPUT_2,ss.str());
}

/*******************  FUNCTION  *********************/
void UnitTest_svutRunner::testRun_2(void)
{
	stringstream ss;
	svutRunner localRunner(*formatter);
	this->mock->useTests(UnitTestMockTestCase2::REGISTER_FAILURE);
	localRunner.registerTestCase(*mock);
	CPPUNIT_ASSERT_EQUAL(false,localRunner.run());
	ss << *formatter;
	CPPUNIT_ASSERT_EQUAL(CST_STRING_OUTPUT_3,ss.str());
}

/*******************  FUNCTION  *********************/
void UnitTest_svutRunner::testSetDisplay_1(void)
{
	stringstream ss;
	svutRunner localRunner(SVUT_OUT_STD_BW,ss);
	localRunner.setDisplay(false,true);
	this->mock->useTests(UnitTestMockTestCase2::REGISTER_ALL);
	localRunner.registerTestCase(*mock);
	CPPUNIT_ASSERT_EQUAL(false,localRunner.run());
	CPPUNIT_ASSERT_EQUAL(CST_STRING_OUTPUT_0,ss.str());
}

/*******************  FUNCTION  *********************/
void UnitTest_svutRunner::testSetDisplay_2(void)
{
	stringstream ss;
	svutRunner localRunner(SVUT_OUT_STD_BW,ss);
	localRunner.setDisplay(true,false);
	this->mock->useTests(UnitTestMockTestCase2::REGISTER_ALL);
	localRunner.registerTestCase(*mock);
	CPPUNIT_ASSERT_EQUAL(false,localRunner.run());
	CPPUNIT_ASSERT_EQUAL(CST_STRING_OUTPUT_4,ss.str());
}

/*******************  FUNCTION  *********************/
void UnitTest_svutRunner::testSetDisplay_3(void)
{
	stringstream ss;
	svutResultFormatterStdBW formatter(ss);
	svutRunner localRunner(formatter);
	localRunner.setDisplay(true,false);
	this->mock->useTests(UnitTestMockTestCase2::REGISTER_ALL);
	localRunner.registerTestCase(*mock);
	CPPUNIT_ASSERT_EQUAL(false,localRunner.run());
	CPPUNIT_ASSERT_EQUAL(CST_STRING_OUTPUT_4,ss.str());
}

/*******************  FUNCTION  *********************/
void UnitTest_svutRunner::testLoadAutoDetected_1(void)
{
	stringstream ss;
	svutRunner localRunner(*formatter);
	this->mock->useTests(UnitTestMockTestCase2::REGISTER_SUCCESS);
	svutTestCaseBuilderGeneric<UnitTestMockTestCase2> builder;
	registerTestCase(builder);
	localRunner.loadAutoDetected();
	CPPUNIT_ASSERT_EQUAL(true,localRunner.run());
	ss << *formatter;
	CPPUNIT_ASSERT_EQUAL(CST_STRING_OUTPUT_5,ss.str());
	localRunner.unloadAutoDetected();
	clearTestCaseRegister();
}

/*******************  FUNCTION  *********************/
void UnitTest_svutRunner::testLoadAutoDetected_2(void)
{
	stringstream ss;
	svutRunner localRunner(*formatter);
	this->mock->useTests(UnitTestMockTestCase2::REGISTER_SUCCESS);
	svutTestCaseBuilderGeneric<UnitTestMockTestCase2> builder;
	registerTestCase(builder);
	registerTestCase(builder);
	localRunner.loadAutoDetected();
	CPPUNIT_ASSERT_EQUAL(true,localRunner.run());
	ss << *formatter;
	CPPUNIT_ASSERT_EQUAL(CST_STRING_OUTPUT_5,ss.str());
	localRunner.unloadAutoDetected();
	clearTestCaseRegister();
}

/*******************  FUNCTION  *********************/
void UnitTest_svutRunner::testLoadAutoDetected_3(void)
{
	stringstream ss;
	svutRunner localRunner(*formatter);
	this->mock->useTests(UnitTestMockTestCase2::REGISTER_SUCCESS);
	svutTestCaseBuilderGeneric<UnitTestMockTestCase2> builder;
	svutTestCaseBuilderGeneric<UnitTestMockTestCase2> builder2;
	registerTestCase(builder);
	registerTestCase(builder2);
	localRunner.loadAutoDetected();
	CPPUNIT_ASSERT_EQUAL(true,localRunner.run());
	ss << *formatter;
	CPPUNIT_ASSERT_EQUAL(CST_STRING_OUTPUT_5,ss.str());
	localRunner.unloadAutoDetected();
	clearTestCaseRegister();
}

/*******************  FUNCTION  *********************/
UnitTestMockTestUnload::UnitTestMockTestUnload()
	:svutTestCase("MockTestUnload")
{
	UnitTest_svutRunner_MockStatus = true;
}

/*******************  FUNCTION  *********************/
UnitTestMockTestUnload::~UnitTestMockTestUnload()
{
	UnitTest_svutRunner_MockStatus = false;
}

/*******************  FUNCTION  *********************/
void UnitTest_svutRunner::testUnloadAutoDetected(void)
{
	stringstream ss;
	svutRunner localRunner(*formatter);
	this->mock->useTests(UnitTestMockTestCase2::REGISTER_SUCCESS);
	svutTestCaseBuilderGeneric<UnitTestMockTestUnload> builder;
	registerTestCase(builder);
	localRunner.loadAutoDetected();
	CPPUNIT_ASSERT_EQUAL(true,UnitTest_svutRunner_MockStatus);
	CPPUNIT_ASSERT_EQUAL(true,localRunner.run());
	ss << *formatter;
	CPPUNIT_ASSERT_EQUAL(CST_STRING_OUTPUT_9,ss.str());
	localRunner.unloadAutoDetected();
	CPPUNIT_ASSERT_EQUAL(false,UnitTest_svutRunner_MockStatus);
	clearTestCaseRegister();
}

/*******************  FUNCTION  *********************/
void UnitTest_svutRunner::testRegisterTestCase(void)
{
	stringstream ss;
	svutRunner localRunner(*formatter);

	ss << *formatter;
	CPPUNIT_ASSERT_EQUAL("",ss.str());
	ss.clear();
	
	this->mock->useTests(UnitTestMockTestCase2::REGISTER_FAILURE);
	localRunner.registerTestCase(*mock);
	CPPUNIT_ASSERT_EQUAL(false,localRunner.run());
	ss << *formatter;
	CPPUNIT_ASSERT_EQUAL(CST_STRING_OUTPUT_3,ss.str());
}

/*******************  FUNCTION  *********************/
void UnitTest_svutRunner::testListTests_1(void )
{
	//TODO change this test when use listener to export the list
	stringstream ss;
	svutRunnerConfig config;
	config.setOutput(ss);
	config.setMode(SVUT_OUT_STD_BW);
	config.setAction(SVUT_ACTION_LIST_TESTS);
	this->mock->useTests(UnitTestMockTestCase2::REGISTER_ALL);
	svutRunner localRunner(config);
	localRunner.registerTestCase(*mock);
	CPPUNIT_ASSERT_EQUAL(true,localRunner.run());
	ss << *formatter;
	CPPUNIT_ASSERT_EQUAL(CST_STRING_OUTPUT_6,ss.str());
}

/*******************  FUNCTION  *********************/
void UnitTest_svutRunner::testListTests_2(void )
{
	//TODO change this test when use listener to export the list
	stringstream ss;
	svutRunnerConfig config;
	config.setOutput(ss);
	config.setMode(SVUT_OUT_STD_BW);
	this->mock->useTests(UnitTestMockTestCase2::REGISTER_ALL);
	svutRunner localRunner(config);
	localRunner.registerTestCase(*mock);
	CPPUNIT_ASSERT_EQUAL(true,localRunner.run(SVUT_ACTION_LIST_TESTS));
	ss << *formatter;
	CPPUNIT_ASSERT_EQUAL(CST_STRING_OUTPUT_6,ss.str());
}

/*******************  FUNCTION  *********************/
void UnitTest_svutRunner::testSetFilter(void)
{
	svutTestFilterBasic filter;
	filter.addAccepted("UnitTestMockTestCase2","testTodo");
	filter.addAccepted("UnitTestMockTestCase2","testIndev");
	filter.addAccepted("UnitTestMockTestCase2","testSuccess");
	CPPUNIT_ASSERT(filter.accept("UnitTestMockTestCase2","testTodo"));
	CPPUNIT_ASSERT(!filter.accept("UnitTestMockTestCase2","testFailure"));
	//TODO change this test when use listener to export the list
	stringstream ss;
	svutRunnerConfig config;
	config.setOutput(ss);
	config.setMode(SVUT_OUT_STD_BW);
	this->mock->useTests(UnitTestMockTestCase2::REGISTER_ALL);
	svutRunner localRunner(config);
	localRunner.registerTestCase(*mock);
	localRunner.setFilter(&filter);
	CPPUNIT_ASSERT_EQUAL(true,localRunner.run(SVUT_ACTION_LIST_TESTS));
	ss << *formatter;
	CPPUNIT_ASSERT_EQUAL(CST_STRING_OUTPUT_7,ss.str());
}

/*******************  FUNCTION  *********************/
void UnitTest_svutRunner::testConfigFilter(void)
{
	//TODO change this test when use listener to export the list
	stringstream ss;
	svutRunnerConfig config;
	config.setOutput(ss);
	config.setMode(SVUT_OUT_STD_BW);
	config.addBasicAccept("UnitTestMockTestCase2","testTodo");
	config.addBasicAccept("UnitTestMockTestCase2","testIndev");
	config.addBasicAccept("UnitTestMockTestCase2","testSuccess");
	this->mock->useTests(UnitTestMockTestCase2::REGISTER_ALL);
	svutRunner localRunner(config);
	localRunner.registerTestCase(*mock);
	CPPUNIT_ASSERT_EQUAL(true,localRunner.run(SVUT_ACTION_LIST_TESTS));
	ss << *formatter;
	CPPUNIT_ASSERT_EQUAL(CST_STRING_OUTPUT_7,ss.str());
}

/*******************  FUNCTION  *********************/
void UnitTest_svutRunner::testSetFilterNull(void)
{
	//TODO change this test when use listener to export the list
	stringstream ss;
	svutRunnerConfig config;
	config.setOutput(ss);
	config.setMode(SVUT_OUT_STD_BW);
	config.addBasicAccept("UnitTestMockTestCase2","testTodo");
	config.addBasicAccept("UnitTestMockTestCase2","testIndev");
	config.addBasicAccept("UnitTestMockTestCase2","testSuccess");
	this->mock->useTests(UnitTestMockTestCase2::REGISTER_ALL);
	svutRunner localRunner(config);
	localRunner.registerTestCase(*mock);
	localRunner.setFilter(NULL);
	CPPUNIT_ASSERT_EQUAL(true,localRunner.run(SVUT_ACTION_LIST_TESTS));
	ss << *formatter;
	CPPUNIT_ASSERT_EQUAL(CST_STRING_OUTPUT_6,ss.str());
}

/*******************  FUNCTION  *********************/
void UnitTest_svutRunner::testFilterTestExecution(void)
{
	svutTestFilterBasic filter;
	filter.addAccepted("UnitTestMockTestCase2","testSuccess");
	stringstream ss;
	svutRunner localRunner(*formatter);
	this->mock->useTests(UnitTestMockTestCase2::REGISTER_ALL);
	localRunner.registerTestCase(*mock);
	localRunner.setFilter(&filter);
	CPPUNIT_ASSERT_EQUAL(true,localRunner.run());
	ss << *formatter;
	CPPUNIT_ASSERT_EQUAL(CST_STRING_OUTPUT_8,ss.str());
}

CPPUNIT_TEST_SUITE_REGISTRATION(UnitTest_svutRunner);
