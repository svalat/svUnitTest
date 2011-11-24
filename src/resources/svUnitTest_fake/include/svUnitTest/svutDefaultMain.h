/*****************************************************
             PROJECT  : svUnitTest
             VERSION  : 0.3.0
             DATE     : 05/2011
             AUTHOR   : Valat Sébastien
             LICENSE  : CeCILL-C
*****************************************************/

#ifndef SVUT_DEFAULT_MAIN_HEADER
#define SVUT_DEFAULT_MAIN_HEADER

/********************  HEADERS  *********************/
#include <vector>
#include <cstdlib>
#include <iostream>
#include <ios>
#include "svutTestCase.h"

namespace svUnitTest
{

/********************  MACROS  **********************/
#define SVUT_REGISTER_STANDELONE(className) \
	SVUT_FAKE_DECLARE_GLOBAL_VARS\
	int main(int argc,char * argv[]) { \
		svUnitTest::svutTestCaseBuilderGeneric<className> builder;\
		return uniqueStandeloneMain(argc,argv,builder);\
	}

/********************  MACROS  **********************/
#define SVUT_USE_DEFAULT_MAIN \
	SVUT_FAKE_DECLARE_GLOBAL_VARS\
	int main(int argc,char * argv[]) { \
		return defaultMain(argc,argv); \
	}
	
/********************  GLOBALS  **********************/
extern std::vector<svutTestCaseBuilder *> * __fake_svut_test_cases_register__;

/*******************  FUNCTION  *********************/
static int defaultMain(int argc,char * argv[])
{
	bool final = true;
	if (__fake_svut_test_cases_register__ == NULL)
		__fake_svut_test_cases_register__ = new std::vector<svutTestCaseBuilder *>;
	for (std::vector<svutTestCaseBuilder *>::iterator it = svUnitTest::__fake_svut_test_cases_register__->begin(); it != svUnitTest::__fake_svut_test_cases_register__->end() ; ++it)
	{
		svutTestCase * test = (*it)->build();
		std::cout << "--------------";
		std::cout.width(30);
		std::cout.setf(std::ios::left);
		std::cout.fill('-');
		std::cout << test->getName();
		std::cout << "-------------- " << std::endl;
		if (test->runTestCase() == false)
			final = false;
		delete test;
	}

	if (__fake_svut_test_cases_register__ != NULL)
		delete __fake_svut_test_cases_register__;

	if (final)
		return EXIT_SUCCESS;
	else
		return EXIT_FAILURE;
}

/*******************  FUNCTION  *********************/
static int uniqueStandeloneMain(int argc,char * argv[],svutTestCaseBuilder & builder)
{
	if (__fake_svut_test_cases_register__ == NULL)
		__fake_svut_test_cases_register__ = new std::vector<svutTestCaseBuilder *>;
	svUnitTest::__fake_svut_test_cases_register__->push_back(&builder);
	return defaultMain(argc,argv);
}

}

#endif //SVUT_DEFAULT_MAIN_HEADER
