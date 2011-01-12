/*****************************************************
             PROJECT  : svUnitTest
             VERSION  : 0.1.0
             DATE     : 01/2011
             AUTHOR   : Valat Sébastien
             LICENSE  : CeCILL-C
*****************************************************/

/********************  HEADERS  *********************/
#include "svutResultFormatter.h"

/**********************  USING  *********************/
using namespace std;

/********************  NAMESPACE  *******************/
namespace svUnitTest
{

/*******************  FUNCTION  *********************/
svutResultFormatter::svutResultFormatter(void )
{
	this->displayDetails = true;
	this->displayFullName = false;
	this->displaySuccess = false;
}


/*******************  FUNCTION  *********************/
/**
 * Activate of desactivate the display of error details.
 * @param state True to activate, false otherwise.
**/
void svutResultFormatter::setDisplayDetails(bool state)
{
	this->displayDetails = state;
}

/*******************  FUNCTION  *********************/
/**
 * Activate of desactivate the display of fulle name (testCaseName::methodName). Or display only
 * the method name.
 * @param state True to activate, false otherwise.
**/
void svutResultFormatter::setDisplayFullName(bool state)
{
	this->displayFullName = state;
}

/*******************  FUNCTION  *********************/
/**
 * Activate of desactivate the display of success.
 * @param state True to activate, false otherwise.
**/
void svutResultFormatter::setDisplaySuccess(bool state)
{
	this->displaySuccess = state;
}

}
