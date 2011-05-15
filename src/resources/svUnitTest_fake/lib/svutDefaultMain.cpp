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
#include "../include/svUnitTest/svutTestCase.h"

/**********************  USING  *********************/
using namespace std;

/********************  NAMESPACE  *******************/
namespace svUnitTest
{

/********************  GLOBALS  **********************/
extern std::vector<svutTestCaseBuilder *> __fake_svut_test_cases_register__;

/*******************  FUNCTION  *********************/
int defaultMain(int argc,char * argv[])
{
	bool final = true;
	for (std::vector<svutTestCaseBuilder *>::iterator it = __fake_svut_test_cases_register__.begin(); it != __fake_svut_test_cases_register__.end() ; ++it)
	{
		svutTestCase * test = (*it)->build();
		cout << "--------------";
		cout.width(30);
		cout.setf(ios::left);
		cout.fill('-');
		cout << test->getName();
		cout << "-------------- " << endl;
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
int uniqueStandeloneMain(int argc,char * argv[],svutTestCaseBuilder & builder)
{
	__fake_svut_test_cases_register__.push_back(&builder);
	return defaultMain(argc,argv);
}

}
