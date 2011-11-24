/*****************************************************
             PROJECT  : svUnitTest
             VERSION  : 0.3.0
             DATE     : 05/2011
             AUTHOR   : Valat Sébastien
             LICENSE  : CeCILL-C
*****************************************************/

#ifndef FAKE_SVUNITTEST_HEADER
#define FAKE_SVUNITTEST_HEADER

/********************  MACRO  ***********************/
/** Define the library version. **/
#define SVUT_LIBARY_VERSION "0.3.0"
/** Define that we are using the implementation of the library. **/
#define SVUT_FAKE_LIBRARY

/********************  MACRO  ***********************/
/** Define all global variables (must be called one time only). **/
#define SVUT_FAKE_DECLARE_GLOBAL_VARS\
	std::vector<svutTestCaseBuilder *> svUnitTest::__fake_svut_test_cases_register__;

/********************  HEADERS  *********************/
#include "svutTestCase.h"
#include "svutAssert.h"
#include "svutDefaultMain.h"

#endif
