/*****************************************************
             PROJECT  : svUnitTest
             VERSION  : 0.0.2
             DATE     : 07/2010
             AUTHOR   : Valat Sébastien
             LICENSE  : CeCILL-C
*****************************************************/

#ifndef SVUT_ASSERTER_HEADER
#define SVUT_ASSERTER_HEADER

/********************  HEADERS  *********************/
#include <sstream>
#include "svutExAssert.h"

/********************  NAMESPACE  *******************/
namespace svUnitTest
{

/*******************  FUNCTION  *********************/
/**
 * Template implementaion of a function which call the == operator between two values.
 * It permit to override this operator just for the unit test without affecting the original
 * objects. It may be impotant if this operator as no real sens for those objects in general case,
 * but may help here to wrote tests quicly.
 * @param v1 Define the first value to compare.
 * @param v2 Define the second value to compare.
 * @return Return true is the values are equals.
**/
template <class T1,class T2>
static bool asserterOperatorEqual(const T1 & v1,const T2 & v2)
{
	return (v1 == v2);
}

/*******************  FUNCTION  *********************/
/**
 * Template implementaion of a function which call the != operator between two values.
 * It permit to override this operator just for the unit test without affecting the original
 * objects. It may be impotant if this operator as no real sens for those objects in general case,
 * but may help here to wrote tests quicly.
 * @param v1 Define the first value to compare.
 * @param v2 Define the second value to compare.
 * @return Return false is the values are equals.
**/
template <class T1,class T2>
static bool asserterOperatorNotEqual(const T1 & v1,const T2 & v2)
{
	return (v1 != v2);
}

/*******************  FUNCTION  *********************/
/**
 * Template implementaion of a mean to convert types to string. By default this methode simply
 * based on ostream operator <<. But it can be override to provide more synthetic view just for
 * the unit tests.
 * This methode is used to generate standard information on assertion failure.
 * @param value Define the value to convert.
 * @return Return the value represented in string format.
**/
template <class T>
static std::string asserterToString(const T & value)
{
	std::stringstream res;
	res << value;
	return res.str();
}

/*******************  FUNCTION  *********************/
/**
 * Methode used to implement equality assertion in macro SVUT_ASSERT_EQUAL. It is declared as
 * template methode so it could be overritten to implement support of non compatible types.
 * The template version suppose the presence of properties between the two types :
 *    - asserterOperatorEqual(), the template default version suppose operator ==.
 *    - asserterToString(), which is template and by default suppose stream operator <<.
 * It may be better to override the two previous function are they are less specialized.
 * It will throw svutExAssertFailEqual if the values are not equals.
 * @param expected Define the expected value.
 * @param actual Define the current value to compared to the expected one.
 * @param location Define the code location which call this test.
**/
template <class T1,class T2>
static void assertEqual(const T1 & expected,const T2 & actual,svutCodeLocation location) throw(svutExAssertFailEqual)
{
	if (asserterOperatorEqual(expected,actual) == false)
	{
		throw svutExAssertFailEqual(true,asserterToString(expected),asserterToString(actual),location);
	}
}

/*******************  FUNCTION  *********************/
/**
 * Methode used to implement equality assertion in macro SVUT_ASSERT_NOT_EQUAL. It is declared as
 * template methode so it could be overritten to implement support of non compatible types.
 * The template version suppose the presence of properties between the two types :
 *    - asserterOperatorNotEqual(), the template default version suppose operator !=.
 *    - asserterToString(), which is template and by default suppose stream operator <<.
 * It may be better to override the two previous function are they are less specialized.
 * It will throw svutExAssertFailEqual if the values are not equals.
 * @param expected Define the expected value.
 * @param actual Define the current value to compared to the expected one.
 * @param location Define the code location which call this test.
**/
template <class T1,class T2>
static void assertNotEqual(const T1 & expected,const T2 & actual,svutCodeLocation location) throw(svutExAssertFailEqual)
{
	if (asserterOperatorNotEqual(expected,actual) == false)
	{
		throw svutExAssertFailEqual(false,asserterToString(expected),asserterToString(actual),location);
	}
}

/*******************  FUNCTION  *********************/
/**
 * Implementation used bu macro SVUT_ASSERT_EQUAL_TYPE. This methode only rely on assertEqual() by
 * pre-filtering the types. For type filtering it rely on compiler error by using a restrict
 * prototype, this the main goal of this metho is to made crash the compiler when types are not
 * the same.
 *
 * You don't have to override this methode.
 *
 * @param expected Define the expected value.
 * @param actual Define the current value to compared to the expected one.
 * @param location Define the code location which call this test.
**/
template <class T>
static void assertEqualType(const T & expected,const T & actual,svutCodeLocation location) throw(svutExAssertFailEqual)
{
	assertEqual(expected,actual,location);
}

/*******************  FUNCTION  *********************/
/**
 * Implementation used bu macro SVUT_ASSERT_NOT_EQUAL_TYPE. This methode only rely on assertEqual() by
 * pre-filtering the types. For type filtering it rely on compiler error by using a restrict
 * prototype, this the main goal of this metho is to made crash the compiler when types are not
 * the same.
 *
 * You don't have to override this methode.
 *
 * @param expected Define the expected value.
 * @param actual Define the current value to compared to the expected one.
 * @param location Define the code location which call this test.
**/
template <class T>
static void assertNotEqualType(const T & expected,const T & actual,svutCodeLocation location) throw(svutExAssertFailEqual)
{
	assertNotEqual(expected,actual,location);
}

/*******************  FUNCTION  *********************/
void assertEqual(const char * expected,const char * actual,svutCodeLocation location) throw(svutExAssertFailEqual);
void assertNotEqual(const char * expected,const char * actual,svutCodeLocation location) throw(svutExAssertFailEqual);
void assertEqualType(const char * expected,const char * actual,svutCodeLocation location) throw(svutExAssertFailEqual);
void assertNotEqualType(const char * expected,const char * actual,svutCodeLocation location) throw(svutExAssertFailEqual);
void assertSame(const void * expected,const void * actual,svutCodeLocation location) throw(svutExAssertFailEqual);
void assertNotSame(const void * expected,const void * actual,svutCodeLocation location) throw(svutExAssertFailEqual);

}

#endif
