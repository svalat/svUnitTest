/*****************************************************
             PROJECT  : svUnitTest
             VERSION  : 0.3.0
             DATE     : 05/2011
             AUTHOR   : Valat Sébastien
             LICENSE  : CeCILL-C
*****************************************************/

#ifndef FAKE_SVUT_TEST_CASE_HEADER
#define FAKE_SVUT_TEST_CASE_HEADER

/********************  HEADERS  *********************/
#include <string>
#include <vector>
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include "svutAssert.h"

/********************  NAMESPACE  *******************/
namespace svUnitTest
{
	
/********************  MACROS  **********************/
#define SVUT_REG_TEST_METHOD(x) markStartTest(#x); SVUT_CAPTURE_ASSERT_EXCEPTIONS(setUp();x();tearDown();); markStatus()
#define SVUT_REGISTER_TEST_CASE(name)\
	static svUnitTest::svutTestCaseBuilderGeneric<name> ___FAKE_SVUNITTEST_case_##name##___;\
	static int ___FAKE_SVUNITTEST_res_case_registration_of##name##__ = svUnitTest::fakeRegisterTestCase(___FAKE_SVUNITTEST_case_##name##___)

/********************  MACROS  **********************/
#define SVUT_SET_CONTEXT(name,value) /*this->setContextEntry((name),(value))*/

/********************  MACROS  **********************/

#define SVUT_UNSET_CONTEXT(name) /*this->clearContexEntry((name))*/

/********************  MACROS  **********************/
#define SVUT_RESET_CONTEXT() /*this->resetContexEntries()*/

/********************  MACROS  **********************/
//printf
#define SVUT_PRINTF 

/********************  MACROS  **********************/
#define SVUT_COUT std::cout

/********************  MACROS  **********************/
#define SVUT_PUTS(x) /* puts((x)) */

/*********************  CLASS  **********************/
/**
 * This is just a light implementation to fake the full library implementation. This may
 * permit to run a test suite bases on svUnitTest in degraded mode even if the library wasn't
 * present. It will directly use assertion so crash on first error and didn't provide any nice
 * output presentation.
**/
class svutTestCase
{
	public:
		svutTestCase(std::string name="Undefined");
		svutTestCase(const svutTestCase & testCase);
		virtual ~svutTestCase(void);
		bool runTestCase(void);
		std::string getName(void) const;
		void setErrorMessage(svutExAssertFake & e);
	protected:
		void markStatus(void);
		void markStartTest(std::string name);
		virtual void testMethodsRegistration(void);
		void setTestCaseName(std::string name);
		void MARK_AS_KNOWN_ERROR(std::string message);
	private:
		std::string caseName;
		svutExAssertFake status;
		bool finalRes;
};

/*********************  CLASS  **********************/
class svutTestCaseBuilder
{
	public:
		virtual ~svutTestCaseBuilder(void);
		virtual svutTestCase * build(void) = 0;
};

/********************  GLOBALS  **********************/
extern std::vector<svutTestCaseBuilder *> * __fake_svut_test_cases_registry__;

/*********************  CLASS  **********************/
template <class T>
class svutTestCaseBuilderGeneric : public svutTestCaseBuilder
{
	public:
		virtual svutTestCase * build(void) { return new T();}
};

/*******************  FUNCTION  *********************/
svutTestCase::svutTestCase(std::string name)
{
	this->caseName = name;
}

/*******************  FUNCTION  *********************/
svutTestCase::svutTestCase(const svutTestCase & testCase)
{
	std::cerr << "Can't made a copy of svutTestCase, it was forbidden." << std::endl;
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
	std::cout << '[' << status.status << ']' << std::endl;
	if (status.status != "SUCCESS" && status.message.empty() == false)
	{
		std::cout << "- - - - - - - - - - - - - - - - - - - - - - - - - - - - -" << std::endl;
		std::cout << status.location << std::endl;
		std::cout << status.message << std::endl;
		std::cout << "- - - - - - - - - - - - - - - - - - - - - - - - - - - - -" << std::endl;
	}
	if (status.status != "SUCCESS" && status.status != "TODO")
		finalRes = false;
}

/*******************  FUNCTION  *********************/
void svutTestCase::markStartTest(std::string name)
{
	std::cout.fill('.');
	std::cout.width(49);
	std::cout << name;
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
static int fakeRegisterTestCase(svUnitTest::svutTestCaseBuilder & builder)
{
	if (__fake_svut_test_cases_registry__ == NULL)
		__fake_svut_test_cases_registry__ = new std::vector<svutTestCaseBuilder *>;
	svUnitTest::__fake_svut_test_cases_registry__->push_back(&builder);
	return 0;
}

};

#endif
