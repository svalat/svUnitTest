/*****************************************************
             PROJECT  : svUnitTest
             VERSION  : 0.3.0
             DATE     : 05/2011
             AUTHOR   : Valat Sébastien
             LICENSE  : CeCILL-C
*****************************************************/

/********************  HEADERS  *********************/
#include "svutFlatTestCase.h"
#include "svutAutoRegister.h"
#include <cassert>
#include <vector>

/**********************  USING  *********************/
using namespace std;

/********************  NAMESPACE  *******************/
namespace svUnitTest
{

/********************  GLOBALS  *********************/
/**
 * Glocal registry used to remember all function defined via SVUT_DECLARE_FLAT_TEST macro
 * Only accessible localy. It must be used only by svutFlatTestCase class and registerFlatTestCaseMethod.
**/
static std::vector<svutFlatRegistryEntry> globalFlatTestRegistry;
/**
 * Global pointer to get current svutTestCase in execution. This is used by getCurrentSvutTestCase() which
 * serve in SVUT_PRINTF/SVUT_COUT/SVUT_*CONTEXT functions to get the current svutTestCase.
 * To support parallel execution of test cases, we must transform this into TLS variable (not done up to now).
**/
static svutTestCase * globalCurrentFlatTestCase = NULL;

/*******************  FUNCTION  *********************/
/**
 * Function used to register a new methe by link time trick.
 * @param testCaseName Define the name of test case to create.
 * @param functionName Define the name of the function to use as test case.
 * @param methodPtr Define the pointer of C method to call.
 * @param location Define the location of the method.
 * @return Return always true, this is the trick to call the method at init time without depending
 * on compilers/linker keywords, see SVUT_REGISTER_FLAT_TEST macro.
**/
bool registerFlatTestCaseMethod(const char* testCaseName, const char* functionName, svutTestMethodPtr methodPtr,const svutCodeLocation & location)
{
	svutFlatRegistryEntry entry;
	entry.testCaseName = testCaseName;
	entry.testName = functionName;
	entry.methodPtr = methodPtr;
	entry.location = location;
	globalFlatTestRegistry.push_back(entry);
	return true;
}

/*******************  FUNCTION  *********************/
/**
 * Constructor of flat test case.
 * @param name Simply define the name of the flat test case. This name will be used by
 * testMethodsRegistration() to find the related tests.
**/
svutFlatTestCase::svutFlatTestCase(string name)
	: svutTestCase(name)
{
	setUpPtr = NULL;
	tearDownPtr = NULL;
}

/*******************  FUNCTION  *********************/
/**
 * Register a new test method to the current flat test case.
 * @param name Define the name of the test.
 * @param methodPtr Define the test function to use.
 * @param location Define the location of the function in source code.
**/
void svutFlatTestCase::registerFlatTestMethod(string name, svutTestMethodPtr methodPtr, const svUnitTest::svutCodeLocation& location)
{
	if (name == "__SVUT_SPECIAL_TEST_CASE_SETUP__")
	{
		this->setUpPtr = methodPtr;
	} else if (name == "__SVUT_SPECIAL_TEST_CASE_TEAR_DOWN__") {
		this->tearDownPtr = methodPtr;
	} else {
		svutObjectMethod * meth = new svutFlatObjectMethod(methodPtr);
		svutTestMethod * test = new svutTestMethod(name,meth,location);
		this->registerTestMethod(test);
	}
}

/*******************  FUNCTION  *********************/
/**
 * Search all corresponding tests by checking testCaseName and create entries in current test case.
**/
void svutFlatTestCase::testMethodsRegistration(void )
{
	for (std::vector<svutFlatRegistryEntry>::const_iterator it = globalFlatTestRegistry.begin() ; it != globalFlatTestRegistry.end() ; ++it)
		if (it->testCaseName == getName())
			registerFlatTestMethod(it->testName,it->methodPtr,it->location);
}

/*******************  FUNCTION  *********************/
/**
 * Call related tearDown method.
**/
void svutFlatTestCase::tearDown(void )
{
	//unmark current
	//assert(globalCurrentFlatTestCase == this);
	globalCurrentFlatTestCase = NULL;

	//call registred C function
	if (tearDownPtr != NULL)
		tearDownPtr();
}

/*******************  FUNCTION  *********************/
/**
 * Call related setup method.
**/
void svutFlatTestCase::setUp(void )
{
	//mark current
	//assert(globalCurrentFlatTestCase == NULL);
	globalCurrentFlatTestCase = this;

	//call registred C function
	if (setUpPtr != NULL)
		setUpPtr();
}

/*******************  FUNCTION  *********************/
/**
 * Return the list of test case builder corresponding to all flat test case registred by
 * SVUT_REGISTER_FLAT_TEST macro.
**/
const std::set< svutTestCaseBuilder* > getRegistredFlatTestCases(void )
{
	std::set< svutTestCaseBuilder* > res;
	std::map<std::string,bool> filter;

	for (std::vector<svutFlatRegistryEntry>::const_iterator it = globalFlatTestRegistry.begin() ; it != globalFlatTestRegistry.end() ; ++it)
	{
		if (filter.find(it->testCaseName) == filter.end())
		{
			filter[it->testCaseName] = true;
			res.insert(new svutFlatTestCaseBuilder(it->testCaseName));
		}
	}

	return res;
}

/*******************  FUNCTION  *********************/
svutFlatTestCaseBuilder::svutFlatTestCaseBuilder(string testCaseName)
{
	this->testCaseName = testCaseName;
}

/*******************  FUNCTION  *********************/
svutTestCase* svutFlatTestCaseBuilder::build(void ) const
{
	return new svutFlatTestCase(testCaseName);
}

/*******************  FUNCTION  *********************/
svutTestCase& getCurrentSvutTestCase(void )
{
	assert(globalCurrentFlatTestCase != NULL);
	return *globalCurrentFlatTestCase;
}

};
