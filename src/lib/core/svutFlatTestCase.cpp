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
#include <set>
#include <iostream>

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
 * Search all corresponding tests by checking testCaseName and create entries in current test case.
**/
void svutFlatTestCase::testMethodsRegistration(void )
{
	for (std::vector<svutFlatRegistryEntry>::const_iterator it = globalFlatTestRegistry.begin() ; it != globalFlatTestRegistry.end() ; ++it)
	{
		if (it->testCaseName == getName())
		{
			if (it->testName == "__SVUT_SPECIAL_TEST_CASE_SETUP__")
			{
				this->setUpPtr = it->methodPtr;
			} else if (it->testName == "__SVUT_SPECIAL_TEST_CASE_TEAR_DOWN__") {
				this->tearDownPtr = it->methodPtr;
			} else {
				svutObjectMethod * meth = new svutFlatObjectMethod(it->methodPtr);
				svutTestMethod * test = new svutTestMethod(it->testName,meth,it->location);
				this->registerTestMethod(test);
			}
		}
	}
}

/*******************  FUNCTION  *********************/
/**
 * Call related tearDown method.
**/
void svutFlatTestCase::tearDown(void )
{
	if (tearDownPtr != NULL)
		tearDownPtr();
}

/*******************  FUNCTION  *********************/
/**
 * Call related setup method.
**/
void svutFlatTestCase::setUp(void )
{
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
		if (filter.find(it->testCaseName) == filter.end())
			res.insert(new svutFlatTestCaseBuilder(it->testCaseName));

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

};
