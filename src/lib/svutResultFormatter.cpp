/*****************************************************
             PROJECT  : svUnitTest
             VERSION  : 0.0.2
             DATE     : 01/2011
             AUTHOR   : Valat Sébastien
             LICENSE  : CeCILL-C
*****************************************************/

/********************  HEADERS  *********************/
#include "svutResultFormatter.h"

using namespace std;
using namespace svUnitTest;

/********************  METHOD  **********************/
svutResultFormatter::svutResultFormatter(void )
{
	this->displayDetails = true;
	this->displayFullName = false;
	this->displaySuccess = false;
}


/********************  METHOD  **********************/
/**
 * Activate of desactivate the display of error details.
 * @param state True to activate, false otherwise.
**/
void svutResultFormatter::setDisplayDetails(bool state)
{
	this->displayDetails = state;
}

/********************  METHOD  **********************/
/**
 * Activate of desactivate the display of fulle name (testCaseName::methodName). Or display only
 * the method name.
 * @param state True to activate, false otherwise.
**/
void svutResultFormatter::setDisplayFullName(bool state)
{
	this->displayFullName = state;
}

/********************  METHOD  **********************/
/**
 * Activate of desactivate the display of success.
 * @param state True to activate, false otherwise.
**/
void svutResultFormatter::setDisplaySuccess(bool state)
{
	this->displaySuccess = state;
}