/*****************************************************
             PROJECT  : svUnitTest
             VERSION  : 0.3.0
             DATE     : 05/2011
             AUTHOR   : Valat Sébastien
             LICENSE  : CeCILL-C
*****************************************************/

/********************  HEADERS  *********************/
#include "svutTestMethod.h"

/********************  NAMESPACE  *******************/
namespace svUnitTest
{

/*******************  FUNCTION  *********************/
/**
 * Class constructor of the test.
 * @param name Define the name of the test (which the name of the function by convention).
 * @param methode Define the caller used to call the test on the test cas object as it's C++ function.
 * the pointer given here will be destroy by the svutTestMethod objet.
 * @param location Define the source location the the test.
**/
svutTestMethod::svutTestMethod(std::string name,svutObjectMethod * methode,svutCodeLocation location)
	:location(location)
{
	this->name = name;
	this->methode = methode;
}

/*******************  FUNCTION  *********************/
/**
 * Class destroyer, clear the inner memory.
**/
svutTestMethod::~svutTestMethod()
{
	if (this->methode!=NULL)
		delete this->methode;
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
void svutTestMethod::call(void)
{
	this->methode->call();
}

/*******************  FUNCTION  *********************/
/**
 * @return Return the source location of the test.
**/
svutCodeLocation svutTestMethod::getLocation(void) const
{
	return location;
}

}
