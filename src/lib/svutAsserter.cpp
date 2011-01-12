/*****************************************************
             PROJECT  : svUnitTest
             VERSION  : 0.1.0
             DATE     : 01/2011
             AUTHOR   : Valat Sébastien
             LICENSE  : CeCILL-C
*****************************************************/

/********************  HEADERS  *********************/
#include <cstring>
#include "svutAsserter.h"

/********************  NAMESPACE  *******************/
namespace svUnitTest
{

/*******************  FUNCTION  *********************/
/**
 * Implementation of assert equal for c string. Without this implementation, the default
 * one will compare the adresse of the pointers, which is already done by SVUT_ASSERT_SAME.
 * @param expected Define the expected value.
 * @param actual Define the current value to compared to the expected one.
 * @param location Define the code location which call this test.
**/
void assertEqual(const char * expected,const char * actual,svutCodeLocation location)
	throw(svutExAssertFailEqual)
{
	if (strcmp(expected,actual) != 0)
	{
		throw svutExAssertFailEqual(true,expected,actual,location);
	}
}

/*******************  FUNCTION  *********************/
/**
 * Implementation of assert equal for c string. Without this implementation, the default
 * one will compare the adresse of the pointers, which is already done by SVUT_ASSERT_NOT_SAME.
 * @param expected Define the expected value.
 * @param actual Define the current value to compared to the expected one.
 * @param location Define the code location which call this test.
**/
void assertNotEqual(const char * expected,const char * actual,svutCodeLocation location)
	throw(svutExAssertFailEqual)
{
	if (strcmp(expected,actual) == 0)
	{
		throw svutExAssertFailEqual(false,expected,actual,location);
	}
}

/*******************  FUNCTION  *********************/
/**
 * Specific implementation for c string.
 * @param expected Define the expected value.
 * @param actual Define the current value to compared to the expected one.
 * @param location Define the code location which call this test.
**/
void assertEqualType(const char * expected,const char * actual,svutCodeLocation location)
	throw(svutExAssertFailEqual)
{
	assertEqual(expected, actual, location);
}

/*******************  FUNCTION  *********************/
/**
 * Specific implementation for c string.
 * @param expected Define the expected value.
 * @param actual Define the current value to compared to the expected one.
 * @param location Define the code location which call this test.
**/
void assertNotEqualType(const char * expected,const char * actual,svutCodeLocation location)
	throw(svutExAssertFailEqual)
{
	assertNotEqual(expected, actual, location);
}

/*******************  FUNCTION  *********************/
/**
 * Methode used to implement assertion macro SVUT_ASSERT_SAME. Here we simply compare the pointer
 * and throw svutExAssertFailEqual if not equal.
 * @param expected Define the expected value.
 * @param actual Define the current value to compared to the expected one.
 * @param location Define the code location which call this test.
**/
void assertSame(const void * expected,const void * actual,svutCodeLocation  location)
	throw(svutExAssertFailEqual)
{
	if ((expected == actual) == false)
	{
		std::string str1 = asserterToString(expected);
		std::string str2 = asserterToString(actual);
		throw svutExAssertFailEqual(true,str1,str2,location);
	}
}

/*******************  FUNCTION  *********************/
/**
 * Methode used to implement assertion macro SVUT_ASSERT_NOT_SAME. Here we simply compare the pointer
 * and throw svutExAssertFailEqual if equal.
 * @param expected Define the expected value.
 * @param actual Define the current value to compared to the expected one.
 * @param location Define the code location which call this test.
**/
void assertNotSame(const void * expected,const void * actual,svutCodeLocation  location)
	throw(svutExAssertFailEqual)
{
	if ((expected != actual) == false)
	{
		std::string str1 = asserterToString(expected);
		std::string str2 = asserterToString(actual);
		throw svutExAssertFailEqual(false,str1,str2,location);
	}
}

}
