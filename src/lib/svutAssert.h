/*****************************************************
             PROJECT  : svUnitTest
             VERSION  : 0.0.2
             DATE     : 07/2010
             AUTHOR   : Valat Sébastien
             LICENSE  : CeCILL-C
*****************************************************/

#ifndef SVUT_ASSERT_HEADER
#define SVUT_ASSERT_HEADER

/********************  HEADERS  *********************/
#include <sstream>
#include "svutExAssert.h"

namespace svUnitTest
{

/********************  MACRO  ***********************/
/**
 * Macro used to define an assertion on boolean value as value TRUE.
 * If not, it throw an exception of type svutExAssertFailBool. This macro was build to be used
 * in tests cases.
 * @param value Define the current boolean value to test.
**/
#define SVUT_ASSERT_TRUE(value) \
	if (((bool)(value)) ==  false) throw svUnitTest::svutExAssertFailBool(true,SVUT_CODE_LOCATION)


/********************  MACRO  ***********************/
/**
 * Macro used to define an assertion on boolean value as value FALSE.
 * If not, it throw an exception of type svutExAssertFailBool. This macro was build to be used
 * in tests cases.
 * @param value Define the current boolean value to test.
**/
#define SVUT_ASSERT_FALSE(value) \
	if (((bool)(value)) ==  true) throw svUnitTest::svutExAssertFailBool(false,SVUT_CODE_LOCATION)

/********************  MACRO  ***********************/
/**
 * Macro used to assert NULL pointer status.
 * In case of failure, an exception of type svutExAssertFailNull was throwed. This macro was built
 * to be used in unit test cases.
 * @param value Define the pointer value.
**/
#define SVUT_ASSERT_NULL(value) \
	if (((void*)(value)) != NULL) throw svUnitTest::svutExAssertFailNullPointer(true,SVUT_CODE_LOCATION)


/********************  MACRO  ***********************/
/**
 * Macro used to assert NONE NULL pointer status.
 * In case of failure, an exception of type svutExAssertFailNull was throwed. This macro was built
 * to be used in unit test cases.
 * @param value Define the pointer value.
**/
#define SVUT_ASSERT_NOT_NULL(value) \
	if (((void*)(value)) == NULL) throw svUnitTest::svutExAssertFailNullPointer(false,SVUT_CODE_LOCATION)

/********************  MACRO  ***********************/
/**
 * Macro used to assert equality of members in term of values. By default it's based on operator
 * ==. If this operator wasn't supported by you type, you can redefine the template function
 * asserterOperatorEqual() to override it with precise type. For string conversion to test failure
 * information, you can override the function asserterToString().
 * In case of failure, an exception of type svutExAssertFailEqual was throwed. This macro was built
 * to be used in unit test cases.
 * @param expected Define the wanted value.
 * @param actual Define the current value to test.
**/
#define SVUT_ASSERT_EQUAL(expected,actual) \
	svUnitTest::assertEqual((expected),(actual),SVUT_CODE_LOCATION)

/********************  MACRO  ***********************/
/**
 * Macro used to assert equality of members in term of values. By default it's based on operator
 * !=. If this operator wasn't supported by you type, you can redefine the template function
 * asserterOperatorNoEqual() to override it with precise type. For string conversion to test failure
 * information, you can override the function asserterToString().
 * In case of failure, an exception of type svutExAssertFailEqual was throwed. This macro was built
 * to be used in unit test cases.
 * @param expected Define the wanted value.
 * @param actual Define the current value to test.
**/
#define SVUT_ASSERT_NOT_EQUAL(expected,actual) \
	svUnitTest::assertNotEqual((expected),(actual),SVUT_CODE_LOCATION)

/********************  MACRO  ***********************/
/**
 * Macro used to assert equality of members in term of values. In addition to SVUT_ASSERT_EQUAL,
 * it force the  variables to use the same type by relying on compiler error if not just by playing
 * with template declaration. In backend it simple redirect the filtered call to
 * asserterOperatorEqual. For more detail on it, jump to SVUT_ASSERT_EQUAL.
 *
 * In case of failure, an exception of type svutExAssertFailEqual was throwed. This macro was built
 * to be used in unit test cases.
 * @param expected Define the wanted value.
 * @param actual Define the current value to test.
**/
#define SVUT_ASSERT_EQUAL_TYPE(expected,actual) \
	assertEqualType((expected),(actual),SVUT_CODE_LOCATION)

/********************  MACRO  ***********************/
/**
 * Macro used to assert equality of members in term of values. In addition to SVUT_ASSERT_NOT_EQUAL,
 * it force the  variables to use the same type by relying on compiler error if not just by playing
 * with template declaration. In backend it simple redirect the filtered call to
 * asserterOperatorEqual. For more detail on it, jump to SVUT_ASSERT_NOT_EQUAL.
 *
 * In case of failure, an exception of type svutExAssertFailEqual was throwed. This macro was built
 * to be used in unit test cases.
 * @param expected Define the wanted value.
 * @param actual Define the current value to test.
**/
#define SVUT_ASSERT_NOT_EQUAL_TYPE(expected,actual) \
	assertNotEqualType((expected),(actual),SVUT_CODE_LOCATION)

/********************  MACRO  ***********************/
/**
 * Macro used to assert that two variables pointer to the same object, here it simply compare the
 * addresses of the pointer. This is more for readibility of the test than a requirement as
 * SVUT_ASSERT_EQUAL can made the job except for char * as it support a special override to use it
 * as c string and not simple pointers.
 *
 * In case of failure, an exception of type svutExAssertFailEqual was throwed. This macro was built
 * to be used in unit test cases.
 * @param expected Définit un pointeur vers la valeur attendue.
 * @param actual Définit un pointeut vers la valeur obtenue.
**/
#define SVUT_ASSERT_SAME(expected,actual) \
	assertSame((expected),(actual),SVUT_CODE_LOCATION)

/********************  MACRO  ***********************/
/**
 * Macro used to assert that two variables pointer to the same object, here it simply compare the
 * addresses of the pointer. This is more for readibility of the test than a requirement as
 * SVUT_ASSERT_NOT_EQUAL can made the job except for char * as it support a special override to use it
 * as c string and not simple pointers.
 *
 * In case of failure, an exception of type svutExAssertFailEqual was throwed. This macro was built
 * to be used in unit test cases.
 * @param expected Définit un pointeur vers la valeur attendue.
 * @param actual Définit un pointeut vers la valeur obtenue.
**/
#define SVUT_ASSERT_NOT_SAME(expected,actual) \
	assertNotSame((expected),(actual),SVUT_CODE_LOCATION)


/*******************  METHOD  **********************/
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
bool asserterOperatorEqual(const T1 & v1,const T2 & v2)
{
	return (v1 == v2);
}

/*******************  METHOD  **********************/
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
bool asserterOperatorNotEqual(const T1 & v1,const T2 & v2)
{
	return (v1 != v2);
}

/*******************  METHOD  **********************/
/**
 * Template implementaion of a mean to convert types to string. By default this methode simply
 * based on ostream operator <<. But it can be override to provide more synthetic view just for
 * the unit tests.
 * This methode is used to generate standard information on assertion failure.
 * @param value Define the value to convert.
 * @return Return the value represented in string format.
**/
template <class T>
std::string asserterToString(const T & value)
{
	std::stringstream res;
	res << value;
	return res.str();
}

/*******************  METHOD  **********************/
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
void assertEqual(const T1 & expected,const T2 & actual,svutCodeLocation location) throw(svutExAssertFailEqual)
{
	if (asserterOperatorEqual(expected,actual) == false)
	{
		throw svutExAssertFailEqual(true,asserterToString(expected),asserterToString(actual),location);
	}
}

/*******************  METHOD  **********************/
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
void assertNotEqual(const T1 & expected,const T2 & actual,svutCodeLocation location) throw(svutExAssertFailEqual)
{
	if (asserterOperatorNotEqual(expected,actual) == false)
	{
		throw svutExAssertFailEqual(false,asserterToString(expected),asserterToString(actual),location);
	}
}

/*******************  METHODE  *********************/
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
void assertEqualType(const T & expected,const T & actual,svutCodeLocation location) throw(svutExAssertFailEqual)
{
	assertEqual(expected,actual,location);
}

/*******************  METHODE  *********************/
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
void assertNotEqualType(const T & expected,const T & actual,svutCodeLocation location) throw(svutExAssertFailEqual)
{
	assertNotEqual(expected,actual,location);
}

/*******************  METHODE  *********************/
void assertEqual(const char * expected,const char * actual,svutCodeLocation location) throw(svutExAssertFailEqual);
void assertNotEqual(const char * expected,const char * actual,svutCodeLocation location) throw(svutExAssertFailEqual);
void assertEqualType(const char * expected,const char * actual,svutCodeLocation location) throw(svutExAssertFailEqual);
void assertNotEqualType(const char * expected,const char * actual,svutCodeLocation location) throw(svutExAssertFailEqual);
void assertSame(const void * expected,const void * actual,svutCodeLocation location) throw(svutExAssertFailEqual);
void assertNotSame(const void * expected,const void * actual,svutCodeLocation location) throw(svutExAssertFailEqual);

};

#endif
