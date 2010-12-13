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
#include <svutRunner.h>
#include <svutListenerDirectOutputter.h>
#include <svutRunnerConfig.h>
#include "UnitTestMockResultFormatter.h"
#include "UnitTestMockTestCase2.h"
#include <svutResultFormatterStdBW.h>

using namespace svUnitTest;
using namespace std;
using namespace CPPUNIT_NS;

static const char * CST_STRING_OUTPUT_0 = "=======  UnitTestMockTestCase2                    ========\n\
 * testFailure                                  [ FAILED ]\n\
- - - - - - - - - - - - - - - - - - - - - - - - - - - - - -\n\
Failed on expected value.\n\
line 51 of file /home/sebv/projects/svUnitTest/svUnitTest/src/test/UnitTestMockTestCase2.cpp on methode testFailure()\n\
   - Actual : 3\n\
   - Expected : 2\n\
- - - - - - - - - - - - - - - - - - - - - - - - - - - - - -\n\
 * testTodo                                     [ TODO ]\n\
 * testIndev                                    [ INDEV ]\n\
 * testUnknown_1                                [ UNKNOWN ]\n\
- - - - - - - - - - - - - - - - - - - - - - - - - - - - - -\n\
Unexpected std exception : std::bad_exception\n\
line 133 of file /home/sebv/projects/svUnitTest/svUnitTest/src/test/UnitTestMockTestCase2.cpp on methode useTests()\n\
- - - - - - - - - - - - - - - - - - - - - - - - - - - - - -\n\
 * testUnknown_2                                [ UNKNOWN ]\n\
- - - - - - - - - - - - - - - - - - - - - - - - - - - - - -\n\
Unexpected exception.\n\
line 134 of file /home/sebv/projects/svUnitTest/svUnitTest/src/test/UnitTestMockTestCase2.cpp on methode useTests()\n\
- - - - - - - - - - - - - - - - - - - - - - - - - - - - - -\n\
 * testFailIsTodo_1                             [ TODO ]\n\
 * testFailIsTodo_2                             [ TODO ]\n\
 * testFailIsTodo_3                             [ TODO ]\n\
 * testSuccessIsIndev                           [ INDEV ]\n\
\n\
+---------------------------+\n\
|    SUMMARY                |\n\
+---------------------------+\n\
|  SUCCESS  :    1 ( 10 %)  |\n\
|  INDEV    :    1 ( 10 %)  |\n\
|  TODO     :    1 ( 10 %)  |\n\
|  FAILED   :    1 ( 10 %)  |\n\
|  UNKNOWN  :    1 ( 10 %)  |\n\
+---------------------------+\n\
|  TOTAL    :   10          |\n\
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
v); closeTestMethod(UnitTestMockTestCase2, testSuccessIsIndev, INDEV); closeTestCase(UnitTestMockTe\
stCase2); success=1, failed=1, todo=4, indev=2, unknown=2, skiped=0; closeOutput(); ";
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
\n\
+---------------------------+\n\
|    SUMMARY                |\n\
+---------------------------+\n\
|  SUCCESS  :    1 ( 10 %)  |\n\
|  INDEV    :    1 ( 10 %)  |\n\
|  TODO     :    1 ( 10 %)  |\n\
|  FAILED   :    1 ( 10 %)  |\n\
|  UNKNOWN  :    1 ( 10 %)  |\n\
+---------------------------+\n\
|  TOTAL    :   10          |\n\
|  STATUS   : UNKNOWN       |\n\
+---------------------------+\n";

/********************  CLASSE  **********************/
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
		void testConstructor_mode_output(void);
		void testConstructor_formatter(void);
		void testConstructor_listener(void);
		void testConstructor_config(void);
		void testRun_1(void);
		void testRun_2(void);
		void testSetDisplay_1(void);
		void testSetDisplay_2(void);
		void testSetDisplay_3(void);
		void testLoadAutoDetected(void);
		void testUnloadAutoDetected(void);
		void testRegisterTestCase(void);

		svutRunner * runner;
		UnitTestMockResultFormater * formatter;
		UnitTestMockTestCase2 * mock;
};

/********************  METHODE  *********************/
void UnitTest_svutRunner::setUp(void)
{
	this->formatter = new UnitTestMockResultFormater();
	this->runner = new svutRunner(*this->formatter);
	this->mock = new UnitTestMockTestCase2();
}

/********************  METHODE  *********************/
void UnitTest_svutRunner::tearDown(void)
{
	delete this->runner;
	delete this->formatter;
	delete this->mock;
}

/********************  METHODE  *********************/
void UnitTest_svutRunner::testConstructor_default(void)
{
	svutRunner localRunner;
}

/********************  METHODE  *********************/
void UnitTest_svutRunner::testConstructor_mode(void)
{
	svutRunner localRunner(SVUT_OUT_STD_BW);
}

/********************  METHODE  *********************/
void UnitTest_svutRunner::testConstructor_mode_output(void)
{
	stringstream ss;
	svutRunner localRunner(SVUT_OUT_STD_BW,ss);
	this->mock->useTests(UnitTestMockTestCase2::REGISTER_ALL);
	localRunner.registerTestCase(*mock);
	CPPUNIT_ASSERT_EQUAL(false,localRunner.run());
	SVUT_ASSERT_EQUAL(CST_STRING_OUTPUT_0,ss.str());
}

/********************  METHODE  *********************/
void UnitTest_svutRunner::testConstructor_formatter(void)
{
	stringstream ss;
	svutRunner localRunner(*formatter);
	this->mock->useTests(UnitTestMockTestCase2::REGISTER_ALL);
	localRunner.registerTestCase(*mock);
	CPPUNIT_ASSERT_EQUAL(false,localRunner.run());
	ss << *formatter;
	SVUT_ASSERT_EQUAL(CST_STRING_OUTPUT_1,ss.str());
}

/********************  METHODE  *********************/
void UnitTest_svutRunner::testConstructor_listener(void)
{
	stringstream ss;
	svutListenerDirectOutputter listener(*formatter);
	svutRunner localRunner(listener);
	this->mock->useTests(UnitTestMockTestCase2::REGISTER_ALL);
	localRunner.registerTestCase(*mock);
	CPPUNIT_ASSERT_EQUAL(false,localRunner.run());
	ss << *formatter;
	SVUT_ASSERT_EQUAL(CST_STRING_OUTPUT_1,ss.str());
}

/********************  METHODE  *********************/
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
	SVUT_ASSERT_EQUAL(CST_STRING_OUTPUT_0,ss.str());
}

/********************  METHODE  *********************/
void UnitTest_svutRunner::testRun_1(void)
{
	stringstream ss;
	svutRunner localRunner(*formatter);
	this->mock->useTests(UnitTestMockTestCase2::REGISTER_SUCCESS);
	localRunner.registerTestCase(*mock);
	CPPUNIT_ASSERT_EQUAL(true,localRunner.run());
	ss << *formatter;
	SVUT_ASSERT_EQUAL(CST_STRING_OUTPUT_2,ss.str());
}

/********************  METHODE  *********************/
void UnitTest_svutRunner::testRun_2(void)
{
	stringstream ss;
	svutRunner localRunner(*formatter);
	this->mock->useTests(UnitTestMockTestCase2::REGISTER_FAILURE);
	localRunner.registerTestCase(*mock);
	CPPUNIT_ASSERT_EQUAL(false,localRunner.run());
	ss << *formatter;
	SVUT_ASSERT_EQUAL(CST_STRING_OUTPUT_3,ss.str());
}

/********************  METHODE  *********************/
void UnitTest_svutRunner::testSetDisplay_1(void)
{
	stringstream ss;
	svutRunner localRunner(SVUT_OUT_STD_BW,ss);
	localRunner.setDisplay(false,true);
	this->mock->useTests(UnitTestMockTestCase2::REGISTER_ALL);
	localRunner.registerTestCase(*mock);
	CPPUNIT_ASSERT_EQUAL(false,localRunner.run());
	SVUT_ASSERT_EQUAL(CST_STRING_OUTPUT_0,ss.str());
}

/********************  METHODE  *********************/
void UnitTest_svutRunner::testSetDisplay_2(void)
{
	stringstream ss;
	svutRunner localRunner(SVUT_OUT_STD_BW,ss);
	localRunner.setDisplay(true,false);
	this->mock->useTests(UnitTestMockTestCase2::REGISTER_ALL);
	localRunner.registerTestCase(*mock);
	CPPUNIT_ASSERT_EQUAL(false,localRunner.run());
	SVUT_ASSERT_EQUAL(CST_STRING_OUTPUT_4,ss.str());
}

/********************  METHODE  *********************/
void UnitTest_svutRunner::testSetDisplay_3(void)
{
	stringstream ss;
	svutResultFormatterStdBW formatter(ss);
	svutRunner localRunner(formatter);
	localRunner.setDisplay(true,false);
	this->mock->useTests(UnitTestMockTestCase2::REGISTER_ALL);
	localRunner.registerTestCase(*mock);
	CPPUNIT_ASSERT_EQUAL(false,localRunner.run());
	SVUT_ASSERT_EQUAL(CST_STRING_OUTPUT_0,ss.str());
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
	stringstream ss;
	svutRunner localRunner(*formatter);

	ss << *formatter;
	SVUT_ASSERT_EQUAL("",ss.str());
	ss.clear();
	
	this->mock->useTests(UnitTestMockTestCase2::REGISTER_FAILURE);
	localRunner.registerTestCase(*mock);
	CPPUNIT_ASSERT_EQUAL(false,localRunner.run());
	ss << *formatter;
	SVUT_ASSERT_EQUAL(CST_STRING_OUTPUT_3,ss.str());
}

CPPUNIT_TEST_SUITE_REGISTRATION(UnitTest_svutRunner);
