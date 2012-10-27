/*****************************************************
             PROJECT  : svUnitTest
             VERSION  : 0.3.0
             DATE     : 05/2011
             AUTHOR   : Valat Sébastien
             LICENSE  : CeCILL-C
*****************************************************/

#ifndef SVUT_FLAT_TEST_CASE_HEADER
#define SVUT_FLAT_TEST_CASE_HEADER

/********************  HEADERS  *********************/
#include "svutTestCase.h"
#include "svutTestCaseBuilder.h"
#include <set>

/********************  NAMESPACE  *******************/
namespace svUnitTest
{

/********************  MACROS  **********************/
/**
 * Convert the given name to string.
 * @param value Define the value to convert to string.
 * @version 0.4.0
**/
#define SVUT_DECLARE_FLAT_TEST_STR(value) #value

/********************  MACROS  **********************/
/**
 * Register a flat test function.
 * @param testCaseName Define the name of virtual test case on which to link the flat test.
 * @param testName Define the name of your test (the name of function to declare).
 * @version 0.4.0
**/
#define SVUT_REGISTER_FLAT_TEST_INTERNAL(testCaseName,testName,method) \
	static bool ___SVUT_res_flat_case_method_registration_of_##testCaseName##_##testName##__ = \
		svUnitTest::registerFlatTestCaseMethod(SVUT_DECLARE_FLAT_TEST_STR(testCaseName),\
			SVUT_DECLARE_FLAT_TEST_STR(testName),method,SVUT_CODE_LOCATION_STATIC)

/********************  MACROS  **********************/
/**
 * Register a flat test function.
 * @param testCaseName Define the name of virtual test case on which to link the flat test.
 * @param testName Define the name of your test (the name of function to declare).
 * @version 0.4.0
**/
#define SVUT_REGISTER_FLAT_TEST(testCaseName,testName) SVUT_REGISTER_FLAT_TEST_INTERNAL(testCaseName,testName,testName)

/********************  MACROS  **********************/
/**
 * Declare a flat test function. It will declare a function of type "void name(void)", so place the test
 * body directly after this line. It will automatically declare it and call SVUT_REGISTER_FLAT_TEST
 * @param testCaseName Define the name of virtual test case on which to link the flat test.
 * @param testName Define the name of your test (the name of function to declare).
 * @version 0.4.0
**/
#define SVUT_DECLARE_FLAT_TEST(testCaseName,testName) \
	void testCaseName##_##testName(void);\
	SVUT_REGISTER_FLAT_TEST_INTERNAL(testCaseName,testName,testCaseName##_##testName);\
	void testCaseName##_##testName(void)

/********************  MACROS  **********************/
/**
 * Same than SVUT_REGISTER_FLAT_TEST, but to register the special setUp() function.
**/
#define SVUT_REGISTER_FLAT_SETUP(testCaseName,fctName) \
	SVUT_REGISTER_FLAT_TEST_INTERNAL(testCaseName,__SVUT_SPECIAL_TEST_CASE_SETUP__,fctName)

/********************  MACROS  **********************/
/**
 * Same than SVUT_DECLARE_FLAT_TEST, but to declare the special setUp() function.
**/
#define SVUT_DECLARE_FLAT_SETUP(testCaseName) \
	void testCaseName##_##setUp(void);\
	SVUT_REGISTER_FLAT_TEST_INTERNAL(testCaseName,__SVUT_SPECIAL_TEST_CASE_SETUP__,testCaseName##_##setUp);\
	void testCaseName##_##setUp(void)

/********************  MACROS  **********************/
/**
 * Same than SVUT_REGISTER_FLAT_TEST, but to register the special tearDown() function.
**/
#define SVUT_REGISTER_FLAT_TEAR_DOWN(testCaseName,fctName) \
	SVUT_REGISTER_FLAT_TEST_INTERNAL(testCaseName,__SVUT_SPECIAL_TEST_CASE_TEAR_DOWN__,fctName)

/********************  MACROS  **********************/
/**
 * Same than SVUT_DECLARE_FLAT_TEST, but to declare the special tearDown() function.
**/
#define SVUT_DECLARE_FLAT_TEAR_DOWN(testCaseName) \
	void testCaseName##_##tearDown(void);\
	SVUT_REGISTER_FLAT_TEST_INTERNAL(testCaseName,__SVUT_SPECIAL_TEST_CASE_TEAR_DOWN__,testCaseName##_##tearDown);\
	void testCaseName##_##tearDown(void)

/*********************  STRUCT  *********************/
/**
 * Struct to define registry entry introduced by registerFlatTestCaseMethod() method.
 * @brief Simple structure of stage for flat test case global registry.
 * @version 0.4.0
**/
struct svutFlatRegistryEntry
{
	std::string testCaseName;
	std::string testName;
	svutCodeLocation location;
	svutTestMethodPtr methodPtr;
};

/*********************  CLASS  **********************/
/**
 * Builder to manage the creation of flat test cases by svutRunner if autoloading classes is enabled.
 * @brief Builder for flat test case.
 * @author Valat Sébastien
 * @version 0.4.0
**/
class svutFlatTestCaseBuilder : public svutTestCaseBuilder
{
	public:
	    svutFlatTestCaseBuilder(std::string testCaseName);
	    virtual svutTestCase* build(void ) const;
	protected:
		/** Name of flat test case to construct. **/
		std::string testCaseName;
};

/*********************  CLASS  **********************/
/**
 * Special test case used to automatically construct object test case from flat C functions.
 * @brief Test case made of static C functions.
 * @author Valat Sébastien
 * @version 0.4.0
**/
class svutFlatTestCase : public svutTestCase
{
	public:
	    svutFlatTestCase(std::string name = "Undefined");
	    virtual void testMethodsRegistration(void );
		void registerFlatTestMethod(std::string name,svutTestMethodPtr methodPtr,const svutCodeLocation & location);
	protected:
		virtual void setUp(void );
		virtual void tearDown(void );
	private:
		svutTestMethodPtr setUpPtr;
		svutTestMethodPtr tearDownPtr;
};

/*******************  FUNCTION  *********************/
bool registerFlatTestCaseMethod(const char* testCaseName, const char* functionName, svUnitTest::svutTestMethodPtr methodPtr, const svUnitTest::svutCodeLocation& location);
const std::set<class svutTestCaseBuilder *> getRegistredFlatTestCases(void);
svutTestCase & getCurrentSvutTestCase(void);

}

#endif // SVUTFLATTESTCASE_H
