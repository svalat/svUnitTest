/*****************************************************
             PROJECT  : svUnitTest
             VERSION  : 0.3.0-dev
             DATE     : 03/2011
             AUTHOR   : Valat Sébastien
             LICENSE  : CeCILL-C
*****************************************************/

#ifndef FAKE_SVUT_ASSERTER_HEADER
#define FAKE_SVUT_ASSERTER_HEADER

/********************  HEADERS  *********************/
#include <sstream>
#include "svutExAssert.h"

/********************  NAMESPACE  *******************/
namespace svUnitTest
{

/*******************  FUNCTION  *********************/
template <class T1,class T2>
bool asserterOperatorEqual(const T1 & v1,const T2 & v2)
{
	return (v1 == v2);
}

/*******************  FUNCTION  *********************/
template <class T1,class T2>
bool asserterOperatorNotEqual(const T1 & v1,const T2 & v2)
{
	return (v1 != v2);
}

/*******************  FUNCTION  *********************/
template <class T>
std::string asserterToString(const T & value)
{
	std::stringstream res;
	res << value;
	return res.str();
}

/*******************  FUNCTION  *********************/
template <class T>
bool asserterOperatorEqualStrict(const T & expected,const T & actual)
{
	return asserterOperatorEqual(expected,actual);
}

/*******************  FUNCTION  *********************/
template <class T>
bool asserterOperatorNotEqualStrict(const T & expected,const T & actual)
{
	return asserterOperatorNotEqual(expected,actual);
}

/*******************  FUNCTION  *********************/
// template <class T>
// static void assertNotEqualStrict(const T & expected,const T & actual,svutCodeLocation location) throw(svutExAssertFailEqual)
// {
// 	assertNotEqual(expected,actual,location);
// }

/*******************  FUNCTION  *********************/
bool asserterOperatorEqual(const char * expected,const char * actual);
bool asserterOperatorNotEqual(const char * expected,const char * actual);
bool asserterOperatorEqualStrict(const char * expected,const char * actual);
bool asserterOperatorNotEqualStrict(const char * expected,const char * actual);
}

#endif
