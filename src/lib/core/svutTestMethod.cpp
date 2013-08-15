/*****************************************************
             PROJECT  : svUnitTest
             VERSION  : 0.5.0-dev
             DATE     : 11/2012
             AUTHOR   : Valat Sébastien
             LICENSE  : CeCILL-C
*****************************************************/

/********************  HEADERS  *********************/
#include "svutTestMethod.h"
#include "svutException.h"
#include "svutObjectMethod.h"

/********************  NAMESPACE  *******************/
namespace svUnitTest
{

/*******************  FUNCTION  *********************/
/**
 * Class constructor of the test.
 * @param name Define the name of the test (which the name of the function by convention).
 * @param testMethod Define the caller used to call the test on the test cas object as it's C++ function.
 * the pointer given here will be destroy by the svutTestMethod objet.
 * @param setupMethod Define the setup method to call before running the test method.
 * @param teatDownMethod Define the tear down method to call befire running the test method.
 * @param location Define the source location the the test.
**/
svutTestMethod::svutTestMethod(std::string name,  svutCodeLocation location,svutObjectMethod* testMethod, svutObjectMethod* setupMethod, svutObjectMethod* tearDownMethod)
	:location(location)
{
	this->name = name;
	this->testMethod = testMethod;
	this->setupMethod = setupMethod;
	this->tearDownMethod = tearDownMethod;
}

/*******************  FUNCTION  *********************/
/**
 * Class destroyer, clear the inner memory.
**/
svutTestMethod::~svutTestMethod()
{
	if (this->testMethod!=NULL)
		delete this->testMethod;
	if (this->setupMethod != NULL)
		delete this->setupMethod;
	if (this->tearDownMethod != NULL)
		delete this->tearDownMethod;
}

/*******************  FUNCTION  *********************/
/**
 * @return Return the name of the test in C++ string format.
**/
std::string svutTestMethod::getName(void) const
{
	return this->name;
}

/*******************  FUNCTION  *********************/
/**
 * Call the test to made it run.
**/
void svutTestMethod::callTest(void)
{
	this->testMethod->call();
}

/*******************  FUNCTION  *********************/
/**
 * Call the setup method.
**/
void svutTestMethod::callSetup(void )
{
	if (setupMethod != NULL)
		setupMethod->call();
}

/*******************  FUNCTION  *********************/
/**
 * Call the tear down method.
**/
void svutTestMethod::callTearDown(void )
{
	if (tearDownMethod != NULL)
		tearDownMethod->call();
}

/*******************  FUNCTION  *********************/
/**
 * @return Return the source location of the test.
**/
svutCodeLocation svutTestMethod::getLocation(void) const
{
	return location;
}

/*******************  FUNCTION  *********************/
/**
 * Default constructor of flat object method.
 * @param method Define the address of "C" method to use.
**/
svutFlatObjectMethod::svutFlatObjectMethod(svutTestMethodPtr method)
{
	if (method == NULL)
		throw svutExInternalError("Can't register a method at address NULL.");
	else
		this->method = method;
}

/*******************  FUNCTION  *********************/
void svutFlatObjectMethod::call(void)
{
	method();
}

}
