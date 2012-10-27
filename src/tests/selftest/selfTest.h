/*****************************************************
             PROJECT  : svUnitTest
             VERSION  : 0.3.0
             DATE     : 05/2011
             AUTHOR   : Valat Sébastien
             LICENSE  : CeCILL-C
*****************************************************/

#ifndef SELF_TEST_HEADER
#define SELF_TEST_HEADER

/********************  HEADERS  *********************/
#include <svUnitTest.h>

/********************  NAMESPACE  *******************/
using namespace svUnitTest;
namespace CPPUNIT_NS
{

/********************  MACRO  ***********************/
#define __STR__(x) #x
#define CPPUNIT_ASSERT(x) SVUT_ASSERT_TRUE(x)
#define CPPUNIT_ASSERT_EQUAL(x,y) SVUT_ASSERT_EQUAL(x,y)
#define CPPUNIT_FAIL(x) SVUT_ASSERT_FAIL(x)
#define CPPUNIT_TEST_SUITE(x) virtual void testMethodsRegistration(void) { setTestCaseName(__STR__(x));
#define CPPUNIT_TEST_SUITE_END() }
#define CPPUNIT_TEST(x) SVUT_REG_TEST_METHOD(x)
#define CPPUNIT_TEST_SUITE_REGISTRATION(name) SVUT_USE_DEFAULT_MAIN SVUT_REGISTER_TEST_CASE(name)
#define FAKE_CPP_UNIT
#define SVUT_SELF_TEST

/*********************  CLASS  **********************/
typedef svutTestCase TestCase;

}

#endif
