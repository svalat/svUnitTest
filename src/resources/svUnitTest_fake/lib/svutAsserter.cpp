/*****************************************************
             PROJECT  : svUnitTest
             VERSION  : 0.3.0-dev
             DATE     : 03/2011
             AUTHOR   : Valat Sébastien
             LICENSE  : CeCILL-C
*****************************************************/

/********************  HEADERS  *********************/
#include <cstring>
#include "../include/svUnitTest/svutAsserter.h"

/********************  NAMESPACE  *******************/
namespace svUnitTest
{

/*******************  FUNCTION  *********************/
bool asserterOperatorEqual(const char * expected,const char * actual)
{
	return strcmp(expected,actual) == 0;
}

/*******************  FUNCTION  *********************/
bool asserterOperatorNotEqual(const char * expected,const char * actual)
{
	return strcmp(expected,actual) != 0;
}

/*******************  FUNCTION  *********************/
bool asserterOperatorEqualStrict(const char * expected,const char * actual)
{
	return asserterOperatorEqual(expected,actual);
}

/*******************  FUNCTION  *********************/
bool asserterOperatorNotEqualStrict(const char * expected,const char * actual)
{
	return asserterOperatorNotEqual(expected,actual);
}

}
