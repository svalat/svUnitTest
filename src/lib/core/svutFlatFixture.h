/*****************************************************
             PROJECT  : svUnitTest
             VERSION  : 0.5.0-dev
             DATE     : 08/2013
             AUTHOR   : Valat Sébastien
             LICENSE  : CeCILL-C 2.1
*****************************************************/

#ifndef SVUT_FLAT_FIXTURE_HEADER
#define SVUT_FLAT_FIXTURE_HEADER

/********************  HEADERS  *********************/
#include "svutTestCase.h"

/********************  MACROS  **********************/
/**
 * Internal macro to do the trick for automatic registration, for more detail, see
 * documentation of similar macro SVUT_REGISTER_FLAT_TEST_INTERNAL.
 * @param testCaseName Define the test case name.
 * @param testName Define the name of the current test.
 * @param fixtureClassName Name of the fixture class to register and to instantiante.
**/
#define SVUT_REGISTER_FLAT_TEST_INTERNAL_F(testCaseName,testName,fixtureClassName)\
	static bool ___SVUT_res_flat_case_method_registration_of_##testCaseName##_##testName##__ = \
		svUnitTest::registerFlatTestCaseMethod(SVUT_DECLARE_FLAT_TEST_STR(testCaseName),\
			SVUT_DECLARE_FLAT_TEST_STR(testName),new fixtureClassName,SVUT_CODE_LOCATION_STATIC)

/**
 * Macro to profive feature support with similar interface than google test, thanks to them for this great inerface idea.
 * The function automatically inherit from class named by "testCaseName" so get access to all internal public and protected members.
 * The runner object will clall setUp and tearDown on this class before and after the run function.
 * The test will be registered as for SVUT_DECLARE_FLAT_TEST with the same grouping semantic.
 * @param testCaseName Define the test case name.
 * @param testName Define the name of the current test.
**/
#define SVUT_DECLARE_FLAT_TEST_F(testCaseName,testName) \
	class SVUT_FIXTURE_##testCaseName##_##testName : public testCaseName\
	{\
		virtual void run(void);\
	};\
	SVUT_REGISTER_FLAT_TEST_INTERNAL_F(testCaseName,testName,SVUT_FIXTURE_##testCaseName##_##testName);\
	void SVUT_FIXTURE_##testCaseName##_##testName::run(void)

/********************  NAMESPACE  *******************/
namespace svUnitTest
{

/*********************  CLASS  **********************/
/**
 * Base class for fixture mode. It only define an interface with commun setUp / run / tearDown function.
 * The user can overrwide setUp and tearDown for his own use. The run() function will be automatically
 * setup by SVUT_DECLARE_FLAT_TEST_F macro.
 * @brief Base class for flat fixtures.
**/
class svutFlatFixture
{
	public:
		/** Virtual destructor to ensure call. **/
		virtual ~svutFlatFixture(void){};
		/** Function to call before the test. **/
		virtual void setUp(void){};
		/** Function to call after the test. **/
		virtual void tearDown(void){};
		/** Function to run the test, this one might be defined by the SVUT_DECLARE_FLAT_TEST_F macro. **/
		virtual void run(void) = 0;
};

}

#endif //SVUT_FLAT_FIXTURE_HEADER
