/*****************************************************
             PROJECT  : svUnitTest
             VERSION  : 0.1.0
             DATE     : 01/2011
             AUTHOR   : Valat Sébastien
             LICENSE  : CeCILL-C
*****************************************************/

#ifndef SVUT_AUTO_REGISTER_HEADER
#define SVUT_AUTO_REGISTER_HEADER

/********************  HEADERS  *********************/
#include <set>
#include "svutTestCaseBuilder.h"

/********************  NAMESPACE  *******************/
namespace svUnitTest
{

/********************  MACROS  **********************/
/**
 * This macro must be colled into the source file of the test case to register to the global list
 * which is automatically find by svutRunner. You can define multiple tests into a unique file without risks.
 * @param name Define the classe name of the test to register.
**/
#define SVUT_REGISTER_TEST_CASE(name) \
	static svUnitTest::svutTestCaseBuilderGeneric<name> ___SVUT_case_##name##___;\
	static int ___SVUT_res_case_registration_of##name##__ = registerTestCase(___SVUT_case_##name##___)

/********************  GLOBALS  **********************/
int registerTestCase(svutTestCaseBuilder & builder);
const std::set<class svutTestCaseBuilder *> & getRegistredTestCase(void);
void clearTestCaseRegister(void);

}

#endif // SVUTAUTOREGISTER_H
