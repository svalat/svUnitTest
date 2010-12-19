/*****************************************************
             PROJECT  : svUnitTest
             VERSION  : 0.0.2
             DATE     : 12/2010
             AUTHOR   : Valat Sébastien
             LICENSE  : CeCILL-C
*****************************************************/

#ifndef SVUT_AUTO_REGISTER_HEADER
#define SVUT_AUTO_REGISTER_HEADER

/********************  HEADERS  *********************/
#include <list>
#include "svutTestCaseBuilder.h"

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
	static int ___SVUT_res_case_registration_of##name##__ = autoRegisterTestCase(___SVUT_case_##name##___);

/********************  GLOBALS  **********************/
int registerTestCase(svutTestCaseBuilder & builder);
const std::list<class svutTestCaseBuilder *> & getRegistredTestCase(void);

}

#endif // SVUTAUTOREGISTER_H