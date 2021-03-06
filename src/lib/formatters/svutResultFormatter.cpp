/*****************************************************
             PROJECT  : svUnitTest
             VERSION  : 0.5.0-dev
             DATE     : 11/2012
             AUTHOR   : Valat Sébastien
             LICENSE  : CeCILL-C 2.1
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
