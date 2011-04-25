/*****************************************************
             PROJECT  : svUnitTest
             VERSION  : 0.3.0-dev
             DATE     : 03/2011
             AUTHOR   : Valat Sébastien
             LICENSE  : CeCILL-C
*****************************************************/

#ifndef FAKE_SVUT_TEST_CASE_HEADER
#define FAKE_SVUT_TEST_CASE_HEADER

/********************  HEADERS  *********************/
#include <string>
#include "svutAssert.h"

/********************  NAMESPACE  *******************/
namespace svUnitTest
{
	
/********************  MACROS  **********************/
#define SVUT_REG_TEST_METHOD(x) markStartTest(#x); setUp(); SVUT_CAPTURE_ASSERT_EXCEPTIONS(x()); tearDown(); markStatus()
#define SVUT_REGISTER_TEST_CASE(name)\
	static svUnitTest::svutTestCaseBuilderGeneric<name> ___FAKE_SVUNITTEST_case_##name##___;\
	static int ___FAKE_SVUNITTEST_res_case_registration_of##name##__ = svUnitTest::fakeRegisterTestCase(___FAKE_SVUNITTEST_case_##name##___)

/********************  MACROS  **********************/
#define SVUT_SET_CONTEXT(name,value) //this->setContextEntry((name),(value))

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

/*********************  CLASS  **********************/
template <class T>
class svutTestCaseBuilderGeneric : public svutTestCaseBuilder
{
	public:
		virtual svutTestCase * build(void) { return new T();}
};

/*******************  FUNCTION **********************/
void fakeRegisterTestCase(svUnitTest::svutTestCaseBuilder & builder);

}


#endif
