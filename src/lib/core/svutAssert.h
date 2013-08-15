/*****************************************************
             PROJECT  : svUnitTest
             VERSION  : 0.5.0-dev
             DATE     : 11/2012
             AUTHOR   : Valat Sébastien
             LICENSE  : CeCILL-C 2.1
*****************************************************/

#ifndef SVUT_ASSERT_HEADER
#define SVUT_ASSERT_HEADER

/********************  HEADERS  *********************/
#include <sstream>
#include "svutExAssert.h"
#include "svutExNotify.h"
#include "svutAsserter.h"

/********************  NAMESPACE  *******************/
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
	do { if (((bool)(value)) ==  false) throw svUnitTest::svutExAssertFailBool(true,SVUT_CODE_LOCATION); } while(0)


/********************  MACRO  ***********************/
/**
 * Macro used to define an assertion on boolean value as value FALSE.
 * If not, it throw an exception of type svutExAssertFailBool. This macro was build to be used
 * in tests cases.
 * @param value Define the current boolean value to test.
**/
#define SVUT_ASSERT_FALSE(value) \
	do { if (((bool)(value)) ==  true) throw svUnitTest::svutExAssertFailBool(false,SVUT_CODE_LOCATION); }  while(0)

/********************  MACRO  ***********************/
/**
 * Macro used to assert NULL pointer status.
 * In case of failure, an exception of type svutExAssertFailNull was throwed. This macro was built
 * to be used in unit test cases.
 * @param value Define the pointer value.
**/
#define SVUT_ASSERT_NULL(value) \
	do { if (((void*)(value)) != NULL) \
		throw svUnitTest::svutExAssertFailNullPointer(true,SVUT_CODE_LOCATION); } while(0)

/********************  MACRO  ***********************/
/**
 * Macro used to assert ZERO values of every types (pointers, float, int, double, long...).
 * In cas of failure, an exception of type svutExAssertFailZero was throwed. This macro was build
 * to be used int unit test cases.
 * @param value Define the value to test.
**/
#define SVUT_ASSERT_ZERO(value) \
	svUnitTest::assertZero((value),SVUT_CODE_LOCATION);

/********************  MACRO  ***********************/
/**
 * Macro used to assert if every entries of an array is setup to 0 depending on the array type.
 * In cas of failure, an exception of type svutExAssertFailZeros was throwed. This macro was build
 * to be used int unit test cases.
 * @param value Define a pointer to the array to test.
 * @param size Define the number of entries to test.
**/
#define SVUT_ASSERT_ZEROS(value,size)\
	svUnitTest::assertZeros((value),(size),SVUT_CODE_LOCATION);

/********************  MACRO  ***********************/
/**
 * Macro used to assert NONE NULL pointer status.
 * In case of failure, an exception of type svutExAssertFailNull was throwed. This macro was built
 * to be used in unit test cases.
 * @param value Define the pointer value.
**/
#define SVUT_ASSERT_NOT_NULL(value) \
	do { if (((void*)(value)) == NULL) \
		throw svUnitTest::svutExAssertFailNullPointer(false,SVUT_CODE_LOCATION); } while (0)

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
 * Macro used to assert inferieor limit of members in term of values. By default it's based on operator
 * >. If this operator wasn't supported by you type, you can redefine the template function
 * asserterOperatorGreater() to override it with precise type. For string conversion to test failure
 * information, you can override the function asserterToString().
 * In case of failure, an exception of type svutExAssertFailLimit was throwed. This macro was built
 * to be used in unit test cases.
 * @param expectedLimit Define the wanted value.
 * @param actual Define the current value to test.
**/
#define SVUT_ASSERT_GT(expectedLimit,actual)\
	svUnitTest::assertGT((expectedLimit),(actual),SVUT_CODE_LOCATION)

/********************  MACRO  ***********************/
/**
 * Macro used to assert inferieor limit of members in term of values. By default it's based on operator
 * >=. If this operator wasn't supported by you type, you can redefine the template function
 * asserterOperatorGreaterOrEqual() to override it with precise type. For string conversion to test failure
 * information, you can override the function asserterToString().
 * In case of failure, an exception of type svutExAssertFailLimit was throwed. This macro was built
 * to be used in unit test cases.
 * @param expectedLimit Define the wanted value.
 * @param actual Define the current value to test.
**/
#define SVUT_ASSERT_GE(expectedLimit,actual)\
	svUnitTest::assertGE((expectedLimit),(actual),SVUT_CODE_LOCATION)


/********************  MACRO  ***********************/
/**
 * Macro used to assert superior limit of members in term of values. By default it's based on operator
 * <. If this operator wasn't supported by you type, you can redefine the template function
 * asserterOperatorLess() to override it with precise type. For string conversion to test failure
 * information, you can override the function asserterToString().
 * In case of failure, an exception of type svutExAssertFailLimit was throwed. This macro was built
 * to be used in unit test cases.
 * @param expectedLimit Define the wanted value.
 * @param actual Define the current value to test.
**/
#define SVUT_ASSERT_LT(expectedLimit,actual)\
	svUnitTest::assertLT((expectedLimit),(actual),SVUT_CODE_LOCATION)

/********************  MACRO  ***********************/
/**
 * Macro used to assert superior limit of members in term of values. By default it's based on operator
 * <=. If this operator wasn't supported by you type, you can redefine the template function
 * asserterOperatorGreaterOrEqual() to override it with precise type. For string conversion to test failure
 * information, you can override the function asserterToString().
 * In case of failure, an exception of type svutExAssertFailEqual was throwed. This macro was built
 * to be used in unit test cases.
 * @param expectedLimit Define the wanted value.
 * @param actual Define the current value to test.
**/
#define SVUT_ASSERT_LE(expectedLimit,actual)\
	svUnitTest::assertLE((expectedLimit),(actual),SVUT_CODE_LOCATION)

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
#define SVUT_ASSERT_EQUAL_STRICT(expected,actual) \
	svUnitTest::assertEqualStrict((expected),(actual),SVUT_CODE_LOCATION)

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
#define SVUT_ASSERT_NOT_EQUAL_STRICT(expected,actual) \
	svUnitTest::assertNotEqualStrict((expected),(actual),SVUT_CODE_LOCATION)

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
	svUnitTest::assertSame((expected),(actual),SVUT_CODE_LOCATION)

/********************  MACRO  ***********************/
/**
 * Macro used to assert that two variables pointer to the same object, here it simply compare the
 * addresses of the pointer. This is more for readibility of the test than a requirement as
 * SVUT_ASSERT_NOT_EQUAL can made the job except for char * as it support a special override to use
 * it as c string and not simple pointers.
 *
 * In case of failure, an exception of type svutExAssertFailEqual was throwed. This macro was built
 * to be used in unit test cases.
 * @param expected Définit un pointeur vers la valeur attendue.
 * @param actual Définit un pointeut vers la valeur obtenue.
**/
#define SVUT_ASSERT_NOT_SAME(expected,actual) \
	svUnitTest::assertNotSame((expected),(actual),SVUT_CODE_LOCATION)

/********************  MACRO  ***********************/
/**
 * Macro used to throw custom error descibed by a message. This assertion always throw exception of
 * type svutExAssertFailCustom. This macro was built to be used in unit test cases.
 * @param message Define a message to describe why wy emit status failure.
**/
#define SVUT_ASSERT_FAIL(message) \
	throw svUnitTest::svutExAssertFailCustom((message),SVUT_CODE_LOCATION)

/********************  MACRO  ***********************/
/**
 * Macro used to mark the current test as 'TODO', this is to notice that it must be implemented
 * or some changes are waited on it.
 * For now it was based one excption throwing, but the implementation of this macro may change in
 * the future to avoid skipping the current writed tests. It throw svutExNotifyTodo exception.
 * This macro was built to be used in unit test cases.
 * @param message Message used to describe what to do in this test.
**/
#define SVUT_ASSERT_TODO(message) \
	throw svUnitTest::svutExNotifyTodo((message),SVUT_CODE_LOCATION)

/********************  MACRO  ***********************/
/**
 * Macro used to mark the current test as 'INDEV', this is to notice that it is changing. It may
 * also help to quicliy foudn the test we are writing in the restul list.
 * For now it was based one excption throwing, but the implementation of this macro may change in
 * the future to avoid skipping the current writed tests. It throw svutExNotifyIndev exception.
 * This macro was built to be used in unit test cases.
 * @param message Message used to describe what append in this test.
**/
#define SVUT_ASSERT_INDEV(message) \
	throw svUnitTest::svutExNotifyIndev((message),SVUT_CODE_LOCATION)

/********************  MACRO  ***********************/
/**
 * Macro used to check that a piece of code wasn't execute. Il always fail with
 * svutExAssertFailNotExec exception.
 * In practice it's quite the same than SVUT_ASSERT_FAIL without message.
 * This macro was built to be used in unit test cases.
**/
#define SVUT_ASSERT_NOT_EXEC_THIS() \
	throw svUnitTest::svutExAssertFailNotExec(SVUT_CODE_LOCATION)

/********************  MACRO  ***********************/
/**
 * Check that a piece of code thow a specific exception.
 * @param name Define the type of required exception.
 * @param what Define the piece of code to run and on which to catch the exception.
**/
#define SVUT_ASSERT_THROW(name,what) \
	try {\
		what;\
		throw svUnitTest::svutExAssertFailThrow(#name,"NONE",SVUT_CODE_LOCATION);\
	} catch(name) {\
	}  catch(svUnitTest::svutExAssertFailThrow &) { \
		throw; \
	} catch(...) {\
		throw svUnitTest::svutExAssertFailThrow(#name,"UNKNOWN",SVUT_CODE_LOCATION);\
	}

/********************  MACRO  ***********************/
/**
 * Check that the given piece of code throw exception without filtering the type.
 * @param what Define the piece of code to run and on which to catch the exception.
**/
#define SVUT_ASSERT_THROW_SOMETHING(what) \
	try {\
		what;\
		throw svUnitTest::svutExAssertFailThrow("...","NONE",SVUT_CODE_LOCATION);\
	}  catch(svUnitTest::svutExAssertFailThrow &) { \
		throw; \
	} catch(...) {\
	}

/********************  MACRO  ***********************/
/**
 * Check that the given piece of code didn't throw the given exception. Caution, others exceptions
 * are catched but didn't produce a failure. To avoid all exceptions, use SVUT_ASSERT_MAY_NOT_THROW.
 * @param name Define the type of the non wanted exception.
 * @param what Define the piece of code to run and on which to catch the exception.
 **/
#define SVUT_ASSERT_NOT_THROW(name,what) \
	try {\
		what;\
	} catch(name) {\
		throw svUnitTest::svutExAssertFailThrow("NONE",#name,SVUT_CODE_LOCATION);\
	} catch(...) {\
	}

/********************  MACRO  ***********************/
/**
 * Check the the given piece of code didn't thow exception. It catch all exception without filtering
 * types.
 * @param what Define the piece of code to run and on which to catch the exception.
 **/
#define SVUT_ASSERT_MAY_NOT_THROW(what) \
	try {\
		what;\
	} catch(...) {\
		throw svUnitTest::svutExAssertFailThrow("NONE","...",SVUT_CODE_LOCATION);\
	}

}

#endif
