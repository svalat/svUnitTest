/*****************************************************
             PROJECT  : svUnitTest
             VERSION  : 0.3.0-dev
             DATE     : 03/2011
             AUTHOR   : Valat Sébastien
             LICENSE  : CeCILL-C
*****************************************************/

/********************  HEADERS  *********************/
#include <vector>
#include <cstdlib>
#include <iostream>
#include "../include/svUnitTest/svutTestCase.h"

/**********************  USING  *********************/
using namespace std;

/********************  NAMESPACE  *******************/
namespace svUnitTest
{

/********************  GLOBALS  **********************/
std::vector<svutTestCaseBuilder *> __fake_svut_test_cases_register__;

/*******************  FUNCTION  *********************/
svutTestCase::svutTestCase(std::string name)
{
	this->caseName = name;
}

/*******************  FUNCTION  *********************/
svutTestCase::svutTestCase(const svutTestCase & testCase)
{
	cerr << "Can't made a copy of svutTestCase, it was forbidden." << endl;
	abort();
}

/*******************  FUNCTION  *********************/
svutTestCase::~svutTestCase(void)
{
}

/*******************  FUNCTION  *********************/
bool svutTestCase::runTestCase(void)
{
	this->finalRes = true;
	this->testMethodsRegistration();
	return finalRes;
}

/*******************  FUNCTION  *********************/
void svutTestCase::markStatus(void)
{
	cout << '[' << status.status << ']' << endl;
	if (status.status != "SUCCESS" && status.message.empty() == false)
	{
		cout << "- - - - - - - - - - - - - - - - - - - - - - - - - - - - -" << endl;
		cout << status.location << endl;
		cout << status.message << endl;
		cout << "- - - - - - - - - - - - - - - - - - - - - - - - - - - - -" << endl;
	}
	if (status.status != "SUCCESS")
		finalRes = false;
}

/*******************  FUNCTION  *********************/
void svutTestCase::markStartTest(std::string name)
{
	cout.fill('.');
	cout.width(49);
	cout << name;
	status.status = "SUCCESS";
}

/*******************  FUNCTION  *********************/
void svutTestCase::testMethodsRegistration(void)
{
}

/*******************  FUNCTION  *********************/
void svutTestCase::setTestCaseName(std::string name)
{
	this->caseName = name;
}

/*******************  FUNCTION  *********************/
void svutTestCase::MARK_AS_KNOWN_ERROR(std::string message)
{
}

/*******************  FUNCTION  *********************/
void svutTestCase::setErrorMessage(svutExAssertFake & e)
{
	this->status = e;
}

/*******************  FUNCTION  *********************/
std::string svutTestCase::getName(void) const
{
	return caseName;
}

/*******************  FUNCTION  *********************/
svutTestCaseBuilder::~svutTestCaseBuilder(void)
{
}

/*******************  FUNCTION  *********************/
void fakeRegisterTestCase(svUnitTest::svutTestCaseBuilder & builder)
{
	__fake_svut_test_cases_register__.push_back(&builder);
}

}
