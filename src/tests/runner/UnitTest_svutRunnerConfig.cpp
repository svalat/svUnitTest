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
#include <svutRunnerConfig.h>
#include <sstream>

/**********************  USING  *********************/
using namespace svUnitTest;
using namespace std;
using namespace CPPUNIT_NS;

/********************  CONSTS  *********************/
const char * CONFIG_STREAM_OUTPUT = "==============================\n\
Mode            =  STD_BW\n\
Action          =  RUN_TESTS\n\
Display_Success =  0\n\
Display_Details =  1\n\
Output_filename =  /dev/null\n\
==============================\n";

/*******************  GLOBALS  ********************/
namespace svUnitTest {
	extern bool __svut_bypass_color_mode__;
}

/*********************  CLASS  **********************/
class UnitTest_svutRunnerConfig : public TestCase
{
	CPPUNIT_TEST_SUITE(UnitTest_svutRunnerConfig);
	CPPUNIT_TEST(testConstructor_1);
	CPPUNIT_TEST(testConstructor_2);
	CPPUNIT_TEST(testLoadParameters_noargs);
	CPPUNIT_TEST(testLoadParameters_mode_std);
	CPPUNIT_TEST(testLoadParameters_mode_xml);
	CPPUNIT_TEST(testLoadParameters_mode_qtxml);
	CPPUNIT_TEST(testLoadParameters_mode_color);
	CPPUNIT_TEST(testLoadParameters_verbose_short);
	CPPUNIT_TEST(testLoadParameters_verbose_long);
	CPPUNIT_TEST(testLoadParameters_silent_short);
	CPPUNIT_TEST(testLoadParameters_silent_long);
	CPPUNIT_TEST(testLoadParameters_function_short);
	CPPUNIT_TEST(testLoadParameters_function_long);
	CPPUNIT_TEST(testLoadParameters_qtxml);
	CPPUNIT_TEST(testLoadParameters_output);
	CPPUNIT_TEST(testLoadParameters_accept);
	CPPUNIT_TEST(testGetMode);
	CPPUNIT_TEST(testSetMode);
	CPPUNIT_TEST(testHasDisplaySuccess);
	CPPUNIT_TEST(testSetDisplaySuccess);
	CPPUNIT_TEST(testHaddisplayDetails);
	CPPUNIT_TEST(testSetDisplayDetails);
	CPPUNIT_TEST(testGetAction);
	CPPUNIT_TEST(testSetAction);
	CPPUNIT_TEST(testSetOutput);
	CPPUNIT_TEST(testGetOutput);
	CPPUNIT_TEST(testSetOutput_stream_1);
	CPPUNIT_TEST(testSetOutput_stream_2);
	CPPUNIT_TEST(testAddBasicAccept_1);
	CPPUNIT_TEST(testAddBasicAccept_2);
	CPPUNIT_TEST(testAddBasicAccept_3);
	CPPUNIT_TEST(testAddBasicAccept_4);
	CPPUNIT_TEST(testOperator_ostream);
	CPPUNIT_TEST_SUITE_END();

	public:
		void setUp(void);
		void tearDown(void);

	protected:
		void testConstructor_1(void);
		void testConstructor_2(void);
		void testLoadParameters_noargs(void);
		void testLoadParameters_mode_xml(void);
		void testLoadParameters_mode_std(void);
		void testLoadParameters_mode_qtxml(void);
		void testLoadParameters_mode_color(void);
		void testLoadParameters_verbose_short(void);
		void testLoadParameters_verbose_long(void);
		void testLoadParameters_silent_short(void);
		void testLoadParameters_silent_long(void);
		void testLoadParameters_function_short(void);
		void testLoadParameters_function_long(void);
		void testLoadParameters_qtxml(void);
		void testLoadParameters_output(void);
		void testLoadParameters_accept(void);
		void testGetMode(void);
		void testSetMode(void);
		void testHasDisplaySuccess(void);
		void testSetDisplaySuccess(void);
		void testHaddisplayDetails(void);
		void testSetDisplayDetails(void);
		void testGetAction(void);
		void testSetAction(void);
		void testSetOutput(void);
		void testGetOutput(void);
		void testSetOutput_stream_1(void);
		void testSetOutput_stream_2(void);
		void testAddBasicAccept_1(void);
		void testAddBasicAccept_2(void);
		void testAddBasicAccept_3(void);
		void testAddBasicAccept_4(void);
		void testOperator_ostream(void);
		void testGetOutputFilename(void);

		svutRunnerConfig * config;
};

/*******************  FUNCTION  *********************/
void UnitTest_svutRunnerConfig::setUp(void)
{
	__svut_bypass_color_mode__ = true;
	config = new svutRunnerConfig();
}

/*******************  FUNCTION  *********************/
void UnitTest_svutRunnerConfig::tearDown(void)
{
	delete config;
	__svut_bypass_color_mode__ = false;
}

/*******************  FUNCTION  *********************/
void UnitTest_svutRunnerConfig::testConstructor_1(void)
{
	CPPUNIT_ASSERT_EQUAL(SVUT_ACTION_RUN_TESTS,config->getAction());
	CPPUNIT_ASSERT_EQUAL(SVUT_OUT_STD_COLOR,config->getMode());
	CPPUNIT_ASSERT_EQUAL(true,config->hasDisplayDetails());
	CPPUNIT_ASSERT_EQUAL(false,config->hasDisplaySuccess());
	CPPUNIT_ASSERT_EQUAL(&std::cout,&config->getOutput());
}

/*******************  FUNCTION  *********************/
void UnitTest_svutRunnerConfig::testConstructor_2(void)
{
	const char * args[] = {
		"progName",
		"-s",
		"-m",
		"xml",
		""
	};
	svutRunnerConfig cfg(4,args);
	
	CPPUNIT_ASSERT_EQUAL(SVUT_ACTION_RUN_TESTS,cfg.getAction());
	CPPUNIT_ASSERT_EQUAL(SVUT_OUT_XML,cfg.getMode());
	CPPUNIT_ASSERT_EQUAL(false,cfg.hasDisplayDetails());
	CPPUNIT_ASSERT_EQUAL(false,cfg.hasDisplaySuccess());
	CPPUNIT_ASSERT_EQUAL(&std::cout,&cfg.getOutput());
}

/*******************  FUNCTION  *********************/
void UnitTest_svutRunnerConfig::testLoadParameters_noargs(void)
{
	const char * args[] = {
		"progName",
		""
	};
	
	CPPUNIT_ASSERT_EQUAL(SVUT_ACTION_RUN_TESTS,config->getAction());
	CPPUNIT_ASSERT_EQUAL(SVUT_OUT_STD_COLOR,config->getMode());
	CPPUNIT_ASSERT_EQUAL(true,config->hasDisplayDetails());
	CPPUNIT_ASSERT_EQUAL(false,config->hasDisplaySuccess());
	CPPUNIT_ASSERT_EQUAL(&std::cout,&config->getOutput());

	config->loadParams(1,args);
	
	CPPUNIT_ASSERT_EQUAL(SVUT_ACTION_RUN_TESTS,config->getAction());
	CPPUNIT_ASSERT_EQUAL(SVUT_OUT_STD_COLOR,config->getMode());
	CPPUNIT_ASSERT_EQUAL(true,config->hasDisplayDetails());
	CPPUNIT_ASSERT_EQUAL(false,config->hasDisplaySuccess());
	CPPUNIT_ASSERT_EQUAL(&std::cout,&config->getOutput());
}

/*******************  FUNCTION  *********************/
void UnitTest_svutRunnerConfig::testLoadParameters_mode_xml(void)
{
	const char * args[] = {
		"progName",
		"-m",
		"xml"
		""
	};

	CPPUNIT_ASSERT_EQUAL(SVUT_ACTION_RUN_TESTS,config->getAction());
	CPPUNIT_ASSERT_EQUAL(SVUT_OUT_STD_COLOR,config->getMode());
	CPPUNIT_ASSERT_EQUAL(true,config->hasDisplayDetails());
	CPPUNIT_ASSERT_EQUAL(false,config->hasDisplaySuccess());
	CPPUNIT_ASSERT_EQUAL(&std::cout,&config->getOutput());

	config->loadParams(3,args);

	CPPUNIT_ASSERT_EQUAL(SVUT_ACTION_RUN_TESTS,config->getAction());
	CPPUNIT_ASSERT_EQUAL(SVUT_OUT_XML,config->getMode());
	CPPUNIT_ASSERT_EQUAL(true,config->hasDisplayDetails());
	CPPUNIT_ASSERT_EQUAL(false,config->hasDisplaySuccess());
	CPPUNIT_ASSERT_EQUAL(&std::cout,&config->getOutput());
}

/*******************  FUNCTION  *********************/
void UnitTest_svutRunnerConfig::testLoadParameters_mode_std(void)
{
	const char * args[] = {
		"progName",
		"-m",
		"std"
		""
	};

	CPPUNIT_ASSERT_EQUAL(SVUT_ACTION_RUN_TESTS,config->getAction());
	CPPUNIT_ASSERT_EQUAL(SVUT_OUT_STD_COLOR,config->getMode());
	CPPUNIT_ASSERT_EQUAL(true,config->hasDisplayDetails());
	CPPUNIT_ASSERT_EQUAL(false,config->hasDisplaySuccess());
	CPPUNIT_ASSERT_EQUAL(&std::cout,&config->getOutput());

	config->loadParams(3,args);

	CPPUNIT_ASSERT_EQUAL(SVUT_ACTION_RUN_TESTS,config->getAction());
	CPPUNIT_ASSERT_EQUAL(SVUT_OUT_STD_BW,config->getMode());
	CPPUNIT_ASSERT_EQUAL(true,config->hasDisplayDetails());
	CPPUNIT_ASSERT_EQUAL(false,config->hasDisplaySuccess());
	CPPUNIT_ASSERT_EQUAL(&std::cout,&config->getOutput());
}

/*******************  FUNCTION  *********************/
void UnitTest_svutRunnerConfig::testLoadParameters_mode_qtxml(void)
{
	const char * args[] = {
		"progName",
		"-m",
		"qt_xml"
		""
	};

	CPPUNIT_ASSERT_EQUAL(SVUT_ACTION_RUN_TESTS,config->getAction());
	CPPUNIT_ASSERT_EQUAL(SVUT_OUT_STD_COLOR,config->getMode());
	CPPUNIT_ASSERT_EQUAL(true,config->hasDisplayDetails());
	CPPUNIT_ASSERT_EQUAL(false,config->hasDisplaySuccess());
	CPPUNIT_ASSERT_EQUAL(&std::cout,&config->getOutput());

	config->loadParams(3,args);

	CPPUNIT_ASSERT_EQUAL(SVUT_ACTION_RUN_TESTS,config->getAction());
	CPPUNIT_ASSERT_EQUAL(SVUT_OUT_QT_XML,config->getMode());
	CPPUNIT_ASSERT_EQUAL(true,config->hasDisplayDetails());
	CPPUNIT_ASSERT_EQUAL(false,config->hasDisplaySuccess());
	CPPUNIT_ASSERT_EQUAL(&std::cout,&config->getOutput());
}

/*******************  FUNCTION  *********************/
void UnitTest_svutRunnerConfig::testLoadParameters_mode_color(void)
{
	const char * args[] = {
		"progName",
		"-m",
		"color"
		""
	};

	CPPUNIT_ASSERT_EQUAL(SVUT_ACTION_RUN_TESTS,config->getAction());
	CPPUNIT_ASSERT_EQUAL(SVUT_OUT_STD_COLOR,config->getMode());
	CPPUNIT_ASSERT_EQUAL(true,config->hasDisplayDetails());
	CPPUNIT_ASSERT_EQUAL(false,config->hasDisplaySuccess());
	CPPUNIT_ASSERT_EQUAL(&std::cout,&config->getOutput());

	config->loadParams(3,args);

	CPPUNIT_ASSERT_EQUAL(SVUT_ACTION_RUN_TESTS,config->getAction());
	CPPUNIT_ASSERT_EQUAL(SVUT_OUT_STD_COLOR,config->getMode());
	CPPUNIT_ASSERT_EQUAL(true,config->hasDisplayDetails());
	CPPUNIT_ASSERT_EQUAL(false,config->hasDisplaySuccess());
	CPPUNIT_ASSERT_EQUAL(&std::cout,&config->getOutput());
}

/*******************  FUNCTION  *********************/
void UnitTest_svutRunnerConfig::testLoadParameters_verbose_short(void)
{
	const char * args[] = {
		"progName",
		"-v"
		""
	};

	CPPUNIT_ASSERT_EQUAL(SVUT_ACTION_RUN_TESTS,config->getAction());
	CPPUNIT_ASSERT_EQUAL(SVUT_OUT_STD_COLOR,config->getMode());
	CPPUNIT_ASSERT_EQUAL(true,config->hasDisplayDetails());
	CPPUNIT_ASSERT_EQUAL(false,config->hasDisplaySuccess());
	CPPUNIT_ASSERT_EQUAL(&std::cout,&config->getOutput());

	config->loadParams(2,args);

	CPPUNIT_ASSERT_EQUAL(SVUT_ACTION_RUN_TESTS,config->getAction());
	CPPUNIT_ASSERT_EQUAL(SVUT_OUT_STD_COLOR,config->getMode());
	CPPUNIT_ASSERT_EQUAL(true,config->hasDisplayDetails());
	CPPUNIT_ASSERT_EQUAL(true,config->hasDisplaySuccess());
	CPPUNIT_ASSERT_EQUAL(&std::cout,&config->getOutput());
}

/*******************  FUNCTION  *********************/
void UnitTest_svutRunnerConfig::testLoadParameters_verbose_long(void)
{
	const char * args[] = {
		"progName",
		"--verbose"
		""
	};

	CPPUNIT_ASSERT_EQUAL(SVUT_ACTION_RUN_TESTS,config->getAction());
	CPPUNIT_ASSERT_EQUAL(SVUT_OUT_STD_COLOR,config->getMode());
	CPPUNIT_ASSERT_EQUAL(true,config->hasDisplayDetails());
	CPPUNIT_ASSERT_EQUAL(false,config->hasDisplaySuccess());
	CPPUNIT_ASSERT_EQUAL(&std::cout,&config->getOutput());

	config->loadParams(2,args);

	CPPUNIT_ASSERT_EQUAL(SVUT_ACTION_RUN_TESTS,config->getAction());
	CPPUNIT_ASSERT_EQUAL(SVUT_OUT_STD_COLOR,config->getMode());
	CPPUNIT_ASSERT_EQUAL(true,config->hasDisplayDetails());
	CPPUNIT_ASSERT_EQUAL(true,config->hasDisplaySuccess());
	CPPUNIT_ASSERT_EQUAL(&std::cout,&config->getOutput());
}

/*******************  FUNCTION  *********************/
void UnitTest_svutRunnerConfig::testLoadParameters_silent_short(void)
{
	const char * args[] = {
		"progName",
		"-s"
		""
	};

	CPPUNIT_ASSERT_EQUAL(SVUT_ACTION_RUN_TESTS,config->getAction());
	CPPUNIT_ASSERT_EQUAL(SVUT_OUT_STD_COLOR,config->getMode());
	CPPUNIT_ASSERT_EQUAL(true,config->hasDisplayDetails());
	CPPUNIT_ASSERT_EQUAL(false,config->hasDisplaySuccess());
	CPPUNIT_ASSERT_EQUAL(&std::cout,&config->getOutput());

	config->loadParams(2,args);

	CPPUNIT_ASSERT_EQUAL(SVUT_ACTION_RUN_TESTS,config->getAction());
	CPPUNIT_ASSERT_EQUAL(SVUT_OUT_STD_COLOR,config->getMode());
	CPPUNIT_ASSERT_EQUAL(false,config->hasDisplayDetails());
	CPPUNIT_ASSERT_EQUAL(false,config->hasDisplaySuccess());
	CPPUNIT_ASSERT_EQUAL(&std::cout,&config->getOutput());
}

/*******************  FUNCTION  *********************/
void UnitTest_svutRunnerConfig::testLoadParameters_silent_long(void)
{
	const char * args[] = {
		"progName",
		"--silent"
		""
	};

	CPPUNIT_ASSERT_EQUAL(SVUT_ACTION_RUN_TESTS,config->getAction());
	CPPUNIT_ASSERT_EQUAL(SVUT_OUT_STD_COLOR,config->getMode());
	CPPUNIT_ASSERT_EQUAL(true,config->hasDisplayDetails());
	CPPUNIT_ASSERT_EQUAL(false,config->hasDisplaySuccess());
	CPPUNIT_ASSERT_EQUAL(&std::cout,&config->getOutput());

	config->loadParams(2,args);

	CPPUNIT_ASSERT_EQUAL(SVUT_ACTION_RUN_TESTS,config->getAction());
	CPPUNIT_ASSERT_EQUAL(SVUT_OUT_STD_COLOR,config->getMode());
	CPPUNIT_ASSERT_EQUAL(false,config->hasDisplayDetails());
	CPPUNIT_ASSERT_EQUAL(false,config->hasDisplaySuccess());
	CPPUNIT_ASSERT_EQUAL(&std::cout,&config->getOutput());
}

/*******************  FUNCTION  *********************/
void UnitTest_svutRunnerConfig::testLoadParameters_function_short(void)
{
	const char * args[] = {
		"progName",
		"-f"
		""
	};

	CPPUNIT_ASSERT_EQUAL(SVUT_ACTION_RUN_TESTS,config->getAction());
	CPPUNIT_ASSERT_EQUAL(SVUT_OUT_STD_COLOR,config->getMode());
	CPPUNIT_ASSERT_EQUAL(true,config->hasDisplayDetails());
	CPPUNIT_ASSERT_EQUAL(false,config->hasDisplaySuccess());
	CPPUNIT_ASSERT_EQUAL(&std::cout,&config->getOutput());

	config->loadParams(2,args);

	CPPUNIT_ASSERT_EQUAL(SVUT_ACTION_LIST_TESTS,config->getAction());
	CPPUNIT_ASSERT_EQUAL(SVUT_OUT_STD_COLOR,config->getMode());
	CPPUNIT_ASSERT_EQUAL(true,config->hasDisplayDetails());
	CPPUNIT_ASSERT_EQUAL(false,config->hasDisplaySuccess());
	CPPUNIT_ASSERT_EQUAL(&std::cout,&config->getOutput());
}

/*******************  FUNCTION  *********************/
void UnitTest_svutRunnerConfig::testLoadParameters_function_long(void)
{
	const char * args[] = {
		"progName",
		"-functions"
		""
	};

	CPPUNIT_ASSERT_EQUAL(SVUT_ACTION_RUN_TESTS,config->getAction());
	CPPUNIT_ASSERT_EQUAL(SVUT_OUT_STD_COLOR,config->getMode());
	CPPUNIT_ASSERT_EQUAL(true,config->hasDisplayDetails());
	CPPUNIT_ASSERT_EQUAL(false,config->hasDisplaySuccess());
	CPPUNIT_ASSERT_EQUAL(&std::cout,&config->getOutput());

	config->loadParams(2,args);

	CPPUNIT_ASSERT_EQUAL(SVUT_ACTION_LIST_TESTS,config->getAction());
	CPPUNIT_ASSERT_EQUAL(SVUT_OUT_STD_COLOR,config->getMode());
	CPPUNIT_ASSERT_EQUAL(true,config->hasDisplayDetails());
	CPPUNIT_ASSERT_EQUAL(false,config->hasDisplaySuccess());
	CPPUNIT_ASSERT_EQUAL(&std::cout,&config->getOutput());
}


/*******************  FUNCTION  *********************/
void UnitTest_svutRunnerConfig::testLoadParameters_qtxml(void)
{
	const char * args[] = {
		"progName",
		"-q"
		""
	};

	CPPUNIT_ASSERT_EQUAL(SVUT_ACTION_RUN_TESTS,config->getAction());
	CPPUNIT_ASSERT_EQUAL(SVUT_OUT_STD_COLOR,config->getMode());
	CPPUNIT_ASSERT_EQUAL(true,config->hasDisplayDetails());
	CPPUNIT_ASSERT_EQUAL(false,config->hasDisplaySuccess());
	CPPUNIT_ASSERT_EQUAL(&std::cout,&config->getOutput());

	config->loadParams(2,args);

	CPPUNIT_ASSERT_EQUAL(SVUT_ACTION_RUN_TESTS,config->getAction());
	CPPUNIT_ASSERT_EQUAL(SVUT_OUT_QT_XML,config->getMode());
	CPPUNIT_ASSERT_EQUAL(true,config->hasDisplayDetails());
	CPPUNIT_ASSERT_EQUAL(false,config->hasDisplaySuccess());
	CPPUNIT_ASSERT_EQUAL(&std::cout,&config->getOutput());
}

/*******************  FUNCTION  *********************/
void UnitTest_svutRunnerConfig::testLoadParameters_output(void)
{
	const char * args[] = {
		"progName",
		"-o",
		"/dev/null",
		""
	};

	CPPUNIT_ASSERT_EQUAL(SVUT_ACTION_RUN_TESTS,config->getAction());
	CPPUNIT_ASSERT_EQUAL(SVUT_OUT_STD_COLOR,config->getMode());
	CPPUNIT_ASSERT_EQUAL(true,config->hasDisplayDetails());
	CPPUNIT_ASSERT_EQUAL(false,config->hasDisplaySuccess());
	CPPUNIT_ASSERT_EQUAL(&std::cout,&config->getOutput());
	CPPUNIT_ASSERT_EQUAL("",config->getOutputFilename());

	config->loadParams(3,args);

	CPPUNIT_ASSERT_EQUAL(SVUT_ACTION_RUN_TESTS,config->getAction());
	CPPUNIT_ASSERT_EQUAL(SVUT_OUT_STD_BW,config->getMode());
	CPPUNIT_ASSERT_EQUAL(true,config->hasDisplayDetails());
	CPPUNIT_ASSERT_EQUAL(false,config->hasDisplaySuccess());
	CPPUNIT_ASSERT_EQUAL("/dev/null",config->getOutputFilename());
	CPPUNIT_ASSERT(&std::cout != &config->getOutput());
}

/*******************  FUNCTION  *********************/
void UnitTest_svutRunnerConfig::testLoadParameters_accept(void)
{
	const char * args[] = {
		"progName",
		"-a",
		"testCase1::",
		""
	};
	svutRunnerConfig cfg(3,args);

	CPPUNIT_ASSERT(cfg.getFilter().accept("testCase1","method1"));
	CPPUNIT_ASSERT(cfg.getFilter().accept("testCase1","method2"));
	CPPUNIT_ASSERT(cfg.getFilter().accept("testCase1","method11"));
	CPPUNIT_ASSERT(!cfg.getFilter().accept("testCase2","method1"));
	CPPUNIT_ASSERT(!cfg.getFilter().accept("testCase2","method2"));
	CPPUNIT_ASSERT(!cfg.getFilter().accept("testCase2","method11"));
}

/*******************  FUNCTION  *********************/
void UnitTest_svutRunnerConfig::testGetMode(void)
{
	CPPUNIT_ASSERT_EQUAL(SVUT_OUT_STD_COLOR,config->getMode());
}

/*******************  FUNCTION  *********************/
void UnitTest_svutRunnerConfig::testSetMode(void)
{
	CPPUNIT_ASSERT_EQUAL(SVUT_OUT_STD_COLOR,config->getMode());
	config->setMode(SVUT_OUT_STD_BW);
	CPPUNIT_ASSERT_EQUAL(SVUT_OUT_STD_BW,config->getMode());
	
}

/*******************  FUNCTION  *********************/
void UnitTest_svutRunnerConfig::testHasDisplaySuccess(void)
{
	CPPUNIT_ASSERT_EQUAL(false,config->hasDisplaySuccess());
}

/*******************  FUNCTION  *********************/
void UnitTest_svutRunnerConfig::testSetDisplaySuccess(void)
{
	CPPUNIT_ASSERT_EQUAL(false,config->hasDisplaySuccess());
	config->setDisplaySuccess(true);
	CPPUNIT_ASSERT_EQUAL(true,config->hasDisplaySuccess());
}

/*******************  FUNCTION  *********************/
void UnitTest_svutRunnerConfig::testHaddisplayDetails(void)
{
	CPPUNIT_ASSERT_EQUAL(true,config->hasDisplayDetails());
}

/*******************  FUNCTION  *********************/
void UnitTest_svutRunnerConfig::testSetDisplayDetails(void)
{
	CPPUNIT_ASSERT_EQUAL(true,config->hasDisplayDetails());
	config->setDisplayDetails(false);
	CPPUNIT_ASSERT_EQUAL(false,config->hasDisplayDetails());
}

/*******************  FUNCTION  *********************/
void UnitTest_svutRunnerConfig::testGetAction(void)
{
	CPPUNIT_ASSERT_EQUAL(SVUT_ACTION_RUN_TESTS,config->getAction());
}

/*******************  FUNCTION  *********************/
void UnitTest_svutRunnerConfig::testSetAction(void)
{
	CPPUNIT_ASSERT_EQUAL(SVUT_ACTION_RUN_TESTS,config->getAction());
	config->setAction(SVUT_ACTION_LIST_TESTS);
	CPPUNIT_ASSERT_EQUAL(SVUT_ACTION_LIST_TESTS,config->getAction());
}

/*******************  FUNCTION  *********************/
void UnitTest_svutRunnerConfig::testSetOutput(void)
{
	CPPUNIT_ASSERT_EQUAL(&std::cout,&config->getOutput());
	CPPUNIT_ASSERT_EQUAL("",config->getOutputFilename());
	config->setOutput("/dev/null");
	CPPUNIT_ASSERT_EQUAL("/dev/null",config->getOutputFilename());
	CPPUNIT_ASSERT(&std::cout != &config->getOutput());
}

/*******************  FUNCTION  *********************/
void UnitTest_svutRunnerConfig::testGetOutput(void)
{
	CPPUNIT_ASSERT_EQUAL(&std::cout,&config->getOutput());
}

/*******************  FUNCTION  *********************/
void UnitTest_svutRunnerConfig::testSetOutput_stream_1(void )
{
	CPPUNIT_ASSERT_EQUAL(&std::cout,&config->getOutput());
	CPPUNIT_ASSERT_EQUAL("",config->getOutputFilename());
	config->setOutput(std::cerr);
	CPPUNIT_ASSERT_EQUAL("",config->getOutputFilename());
	CPPUNIT_ASSERT(&std::cerr == &config->getOutput());
}

/*******************  FUNCTION  *********************/
void UnitTest_svutRunnerConfig::testSetOutput_stream_2(void )
{
	CPPUNIT_ASSERT_EQUAL(&std::cout,&config->getOutput());
	CPPUNIT_ASSERT_EQUAL("",config->getOutputFilename());
	config->setOutput("/dev/null");
	CPPUNIT_ASSERT_EQUAL("/dev/null",config->getOutputFilename());
	CPPUNIT_ASSERT(&std::cout != &config->getOutput());
	config->setOutput(std::cerr);
	CPPUNIT_ASSERT_EQUAL("",config->getOutputFilename());
	CPPUNIT_ASSERT(&std::cerr == &config->getOutput());
}

/*******************  FUNCTION  *********************/
void UnitTest_svutRunnerConfig::testAddBasicAccept_1(void)
{
	config->addBasicAccept("testCase1::method1");
	CPPUNIT_ASSERT(config->getFilter().accept("testCase1","method1"));
	CPPUNIT_ASSERT(!config->getFilter().accept("testCase1","method2"));
	CPPUNIT_ASSERT(!config->getFilter().accept("testCase1","method11"));
	CPPUNIT_ASSERT(!config->getFilter().accept("testCase2","method1"));
	CPPUNIT_ASSERT(!config->getFilter().accept("testCase2","method2"));
	CPPUNIT_ASSERT(!config->getFilter().accept("testCase2","method11"));
}

/*******************  FUNCTION  *********************/
void UnitTest_svutRunnerConfig::testAddBasicAccept_2(void)
{
	config->addBasicAccept("testCase1::");
	CPPUNIT_ASSERT(config->getFilter().accept("testCase1","method1"));
	CPPUNIT_ASSERT(config->getFilter().accept("testCase1","method2"));
	CPPUNIT_ASSERT(config->getFilter().accept("testCase1","method11"));
	CPPUNIT_ASSERT(!config->getFilter().accept("testCase2","method1"));
	CPPUNIT_ASSERT(!config->getFilter().accept("testCase2","method2"));
	CPPUNIT_ASSERT(!config->getFilter().accept("testCase2","method11"));
}

/*******************  FUNCTION  *********************/
void UnitTest_svutRunnerConfig::testAddBasicAccept_3(void)
{
	config->addBasicAccept("::method1");
	CPPUNIT_ASSERT(config->getFilter().accept("testCase1","method1"));
	CPPUNIT_ASSERT(!config->getFilter().accept("testCase1","method2"));
	CPPUNIT_ASSERT(!config->getFilter().accept("testCase1","method11"));
	CPPUNIT_ASSERT(config->getFilter().accept("testCase2","method1"));
	CPPUNIT_ASSERT(!config->getFilter().accept("testCase2","method2"));
	CPPUNIT_ASSERT(!config->getFilter().accept("testCase2","method11"));
}

/*******************  FUNCTION  *********************/
void UnitTest_svutRunnerConfig::testAddBasicAccept_4(void)
{
	config->addBasicAccept("testCase1","method1");
	CPPUNIT_ASSERT(config->getFilter().accept("testCase1","method1"));
	CPPUNIT_ASSERT(!config->getFilter().accept("testCase1","method2"));
	CPPUNIT_ASSERT(!config->getFilter().accept("testCase1","method11"));
	CPPUNIT_ASSERT(!config->getFilter().accept("testCase2","method1"));
	CPPUNIT_ASSERT(!config->getFilter().accept("testCase2","method2"));
	CPPUNIT_ASSERT(!config->getFilter().accept("testCase2","method11"));
}

/*******************  FUNCTION  *********************/
void UnitTest_svutRunnerConfig::testOperator_ostream(void )
{
	stringstream str;
	config->setOutput("/dev/null");
	str << *config;
	CPPUNIT_ASSERT_EQUAL(CONFIG_STREAM_OUTPUT,str.str());
}

/*******************  FUNCTION  *********************/
void UnitTest_svutRunnerConfig::testGetOutputFilename(void )
{
	CPPUNIT_ASSERT_EQUAL("",config->getOutputFilename());
}


CPPUNIT_TEST_SUITE_REGISTRATION(UnitTest_svutRunnerConfig);
