/*****************************************************
             PROJECT  : svUnitTest
             VERSION  : 0.1.0
             DATE     : 01/2011
             AUTHOR   : Valat Sébastien
             LICENSE  : CeCILL-C
*****************************************************/

/********************  HEADERS  *********************/
#include <cstdlib>
#include "svutAutoRegister.h"

/********************  NAMESPACE  *******************/
namespace svUnitTest
{

/*********************  CLASS  **********************/
/**
 * List used to store the test case builder for the usage of auto registration. It was used to
 * be fetched from svutRunner.
**/
static std::set<class svutTestCaseBuilder *> * __SVUT_autoFoundTests__ = NULL;

/*******************  FUNCTION  *********************/
/** Free register memory at exit. **/
static void freeTestCaseRegisterMemoryAtExit(void)
{
	if (__SVUT_autoFoundTests__ != NULL)
		delete __SVUT_autoFoundTests__;
}

/*******************  FUNCTION  *********************/
/**
 * Methode used on first access on __SVUT_autoFoundTests__ to create it if required.
 * This dynmaique creation instead of static is required to fix buggy behavior on
 * Windows with VCC.
**/
static void firstTouchRegister(void)
{
	//if first access, we need to create it.
	if (__SVUT_autoFoundTests__ == NULL)
	{
		__SVUT_autoFoundTests__ = new std::set<class svutTestCaseBuilder *>();
		atexit(freeTestCaseRegisterMemoryAtExit);
	}
}

/*******************  FUNCTION  *********************/
/**
 * Methode used to register the test case to the global list loaded by svutRunner at boot time.
 * Please, do not call this methode directly, insteed, use the SVUT_REGISTER_TEST_CASE() macro.
 * This macro create an instance of the test case builder associated to the requested test and
 * register it into the list. As it was declared as global object, they will be called at load time
 * before entring into the main function and be ready while svutRunner start to work.
 * If the builder is registred more than one time, it will generate more than one instance of the
 * test case. But the svutRunner::loadAutoDetected() method will detect if by checking test case
 * names and remove the copies.
 * @param builder Define the test case builder to register. As it simply require the build of a test
 * case builder which done nothing, we may not fall in trouble if the tested library require
 * pré-initialisation at load time.
 **/
int registerTestCase(svutTestCaseBuilder & builder)
{
	firstTouchRegister();
	__SVUT_autoFoundTests__->insert(&builder);
	return 0;
}

/*******************  FUNCTION  *********************/
/**
 * Return the list of registred test cases. This function may be use in svutRunner to fetch the list
 * of runner insteed of directly touch __SVUT_autoFoundTests__.
**/
const std::set<class svutTestCaseBuilder *> & getRegistredTestCase(void)
{
	firstTouchRegister();
	return *__SVUT_autoFoundTests__;
}

/*******************  FUNCTION  *********************/
/** Clearn the test case list. **/
void clearTestCaseRegister(void)
{
	if (__SVUT_autoFoundTests__ != NULL)
		__SVUT_autoFoundTests__->clear();
}

}
