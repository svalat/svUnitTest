/*****************************************************
             PROJECT  : svUnitTest
             VERSION  : 0.0.2
             DATE     : 12/2010
             AUTHOR   : Valat Sébastien
             LICENSE  : CeCILL-C
*****************************************************/

/********************  HEADERS  *********************/
#include "svutAutoRegister.h"

namespace svUnitTest
{

/********************  CLASSE  **********************/
/**
 * List used to store the test case builder for the usage of auto registration. It was used to
 * be fetched from svutRunner.
**/
std::list<class svutTestCaseBuilder *> __SVUT_autoFoundTests__;

/********************  METHODE  *********************/
/**
 * Methode used to register the test case to the global list loaded by svutRunner at boot time.
 * Please, do not call this methode directly, insteed, use the SVUT_REGISTER_TEST_CASE() macro.
 * This macro create an instance of the test case builder associated to the requested test and register
 * it into the list. As it was declared as global object, they will be called at load time before
 * entring into the main function and be ready while svutRunner start to work.
 * @param builder Define the test case builder to register. As it simply require the build of a test
 * case builder which done nothing, we may not fall in trouble if the tested library require
 * pré-initialisation at load time.
 **/
int registerTestCase(svutTestCaseBuilder & builder)
{
	__SVUT_autoFoundTests__.push_back(&builder);
	return 0;
}

/********************  METHODE  *********************/
/**
 * Return the list of registred test cases. This function may be use in svutRunner to fetch the list
 * of runner insteed of directly touch __SVUT_autoFoundTests__.
**/
const std::list<class svutTestCaseBuilder *> & getRegistredTestCase(void)
{
	return __SVUT_autoFoundTests__;
}

/********************  METHODE  *********************/
/** Clearn the test case list. **/
void clearTestCaseRegister(void)
{
	__SVUT_autoFoundTests__.clear();
}

}
