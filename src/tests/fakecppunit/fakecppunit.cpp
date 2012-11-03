/*****************************************************
             PROJECT  : svUnitTest
             VERSION  : 0.5.0-dev
             DATE     : 11/2012
             AUTHOR   : Valat Sébastien
             LICENSE  : CeCILL-C
*****************************************************/

/********************  HEADERS  *********************/
#include <iostream>
#include <cstdlib>
#include <vector>
#include <ios>
#include <string>
#include "fakecppunit.h"

/********************  NAMESPACE  *******************/
namespace CPPUNIT_NS
{
/********************  GLOBALS  **********************/
static std::vector<TestCaseBuilder *> __fake_cppunit_test_cases_register__;

/*******************  FUNCTION  *********************/
int fakeCppUnitRegisterTestCase(CPPUNIT_NS::TestCaseBuilder & builder)
{
	__fake_cppunit_test_cases_register__.push_back(&builder);
	return 0;
}

/*******************  FUNCTION  *********************/
TestCaseBuilder::~TestCaseBuilder(void )
{
}

/*******************  FUNCTION  *********************/
void TestCase::markAsPassed(void ) const
{
	std::cout << "[PASSED]" << std::endl;
}

/*******************  FUNCTION  *********************/
void TestCase::markStartTest(const char * name) const
{
	std::cout << "Test ";
	std::cout.width(40);
	std::cout.setf(std::ios::left);
	std::cout << name;
}

}

using namespace CPPUNIT_NS;

/*******************  FUNCTION  *********************/
int main(void)
{
	for (std::vector<TestCaseBuilder *>::iterator it = __fake_cppunit_test_cases_register__.begin(); it != __fake_cppunit_test_cases_register__.end() ; ++it)
	{
		TestCase * test = (*it)->build();
		test->run();
		delete test;
	}
		
	return EXIT_SUCCESS;
}
