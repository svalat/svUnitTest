/*****************************************************
             PROJECT  : svUnitTest
             VERSION  : 0.0.2
             DATE     : 07/2010
             AUTHOR   : Valat Sébastien
             LICENSE  : CeCILL-C
*****************************************************/

/********************  HEADERS  *********************/
#include <cstring>
#include "svutAssert.h"

namespace svUnitTest
{

/********************  METHOD  **********************/
/**
 * Implementation of assert equal for c string. Without this implementation, the default
 * one will compare the adresse of the pointers, which is already done by SVUT_ASSERT_SAME.
 * @param expected Define the expected value.
 * @param actual Define the current value to compared to the expected one.
 * @param location Define the code location which call this test.
**/
void assertEqual(const char * expected,const char * actual,svutCodeLocation location) throw(svutExAssertFailEqual)
{
	if (strcmp(expected,actual) != 0)
	{
		throw svutExAssertFailEqual(true,expected,actual,location);
	}
}

/********************  METHOD  **********************/
/**
 * Implementation of assert equal for c string. Without this implementation, the default
 * one will compare the adresse of the pointers, which is already done by SVUT_ASSERT_NOT_SAME.
 * @param expected Define the expected value.
 * @param actual Define the current value to compared to the expected one.
 * @param location Define the code location which call this test.
**/
void assertNotEqual(const char * expected,const char * actual,svutCodeLocation location) throw(svutExAssertFailEqual)
{
	if (strcmp(expected,actual) == 0)
	{
		throw svutExAssertFailEqual(false,expected,actual,location);
	}
}

};
