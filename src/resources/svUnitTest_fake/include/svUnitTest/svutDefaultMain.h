/*****************************************************
             PROJECT  : svUnitTest
             VERSION  : 0.3.0
             DATE     : 05/2011
             AUTHOR   : Valat Sébastien
             LICENSE  : CeCILL-C
*****************************************************/

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
extern std::vector<svutTestCaseBuilder *> __fake_svut_test_cases_register__;

/*******************  FUNCTION  *********************/
static int defaultMain(int argc,char * argv[])
{
	bool final = true;
	for (std::vector<svutTestCaseBuilder *>::iterator it = __fake_svut_test_cases_register__.begin(); it != __fake_svut_test_cases_register__.end() ; ++it)
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

	if (final)
		return EXIT_SUCCESS;
	else
		return EXIT_FAILURE;
}

/*******************  FUNCTION  *********************/
static int uniqueStandeloneMain(int argc,char * argv[],svutTestCaseBuilder & builder)
{
	__fake_svut_test_cases_register__.push_back(&builder);
	return defaultMain(argc,argv);
}

}
