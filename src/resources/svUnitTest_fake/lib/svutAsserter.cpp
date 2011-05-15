/*****************************************************
             PROJECT  : svUnitTest
             VERSION  : 0.3.0
             DATE     : 05/2011
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

/*******************  FUNCTION  *********************/
bool asserterOperatorGE(const char * v1,const char * v2)
{
	return v1 >= v2;
}

/*******************  FUNCTION  *********************/
bool asserterOperatorGT(const char * v1,const char * v2)
{
	return v1 > v2;
}

/*******************  FUNCTION  *********************/
bool asserterOperatorLE(const char * v1,const char * v2)
{
	return v1 <= v2;
}

/*******************  FUNCTION  *********************/
bool asserterOperatorLT(const char * v1,const char * v2)
{
	return v1 < v2;
}

/*******************  FUNCTION  *********************/
bool asserterOperatorGE(char * v1,char * v2)
{
	return v1 >= v2;
}

/*******************  FUNCTION  *********************/
bool asserterOperatorGT(char * v1,char * v2)
{
	return v1 > v2;
}

/*******************  FUNCTION  *********************/
bool asserterOperatorLE(char * v1,char * v2)
{
	return v1 <= v2;
}

/*******************  FUNCTION  *********************/
bool asserterOperatorLT(char * v1,char * v2)
{
	return v1 < v2;
}

}
