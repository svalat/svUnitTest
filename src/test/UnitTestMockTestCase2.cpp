/*****************************************************
             PROJECT  : svUnitTest
             VERSION  : 0.3.0-dev
             DATE     : 03/2011
             AUTHOR   : Valat Sébastien
             LICENSE  : CeCILL-C
*****************************************************/

/********************  HEADERS  *********************/
#include "UnitTestMockTestCase2.h"

/**********************  USING  *********************/
using namespace svUnitTest;

/*******************  FUNCTION  *********************/
UnitTestMockTestCase2::UnitTestMockTestCase2(void ):
	svutTestCase("UnitTestMockTestCase2")
{

}

/*******************  FUNCTION  *********************/
void UnitTestMockTestCase2::setUp(void)
{
}

/*******************  FUNCTION  *********************/
void UnitTestMockTestCase2::tearDown(void)
{
}

/*******************  FUNCTION  *********************/
void UnitTestMockTestCase2::testSuccess(void )
{
}

/*******************  FUNCTION  *********************/
void UnitTestMockTestCase2::testIndev(void )
{
	SVUT_ASSERT_INDEV("for the test");
}

/*******************  FUNCTION  *********************/
void UnitTestMockTestCase2::testTodo(void )
{
	SVUT_ASSERT_TODO("for the test");
}

/*******************  FUNCTION  *********************/
void UnitTestMockTestCase2::testFailure(void )
{
	SVUT_ASSERT_EQUAL(2,3);
}

/*******************  FUNCTION  *********************/
void UnitTestMockTestCase2::testUnknown_1(void )
{
	throw std::bad_exception();
}

/*******************  FUNCTION  *********************/
void UnitTestMockTestCase2::testUnknown_2(void )
{
	throw 42;
}

/*******************  FUNCTION  *********************/
void UnitTestMockTestCase2::testFailIsTodo_1(void )
{
	MARK_AS_KNOWN_ERROR("this is a test");
	SVUT_ASSERT_EQUAL(2,3);
}

/*******************  FUNCTION  *********************/
void UnitTestMockTestCase2::testFailIsTodo_2(void )
{
	MARK_AS_KNOWN_ERROR("this is a test");
	throw std::bad_exception();
}

/*******************  FUNCTION  *********************/
void UnitTestMockTestCase2::testFailIsTodo_3(void )
{
	MARK_AS_KNOWN_ERROR("this is a test");
	throw 42;
}

/*******************  FUNCTION  *********************/
void UnitTestMockTestCase2::testSuccessIsIndev(void )
{
	MARK_AS_KNOWN_ERROR("this is a test");
}

/*******************  FUNCTION  *********************/
void UnitTestMockTestCase2::useTests(UnitTestMockTestCase2::UnitTestMockFlags flags)
{
	switch(flags)
	{
		case REGISTER_SUCCESS:
			SVUT_REG_TEST_METHOD(testSuccess);
			break;
		case REGISTER_FAILURE:
			SVUT_REG_TEST_METHOD(testFailure);
			break;
		case REGISTER_TODO:
			SVUT_REG_TEST_METHOD(testTodo);
			break;
		case REGISTER_INDEV:
			SVUT_REG_TEST_METHOD(testIndev);
			break;
		case REGISTER_UNKNOWN_1:
			SVUT_REG_TEST_METHOD(testUnknown_1);
			break;
		case REGISTER_UNKNOWN_2:
			SVUT_REG_TEST_METHOD(testUnknown_2);
			break;
		case REGISTER_FAIL_IS_TODO_1:
			SVUT_REG_TEST_METHOD(testFailIsTodo_1);
			break;
		case REGISTER_FAIL_IS_TODO_2:
			SVUT_REG_TEST_METHOD(testFailIsTodo_2);
			break;
		case REGISTER_FAIL_IS_TODO_3:
			SVUT_REG_TEST_METHOD(testFailIsTodo_3);
			break;
		case REGISTER_SUCCESS_IS_INDEV:
			SVUT_REG_TEST_METHOD(testSuccessIsIndev);
			break;
		case REGISTER_ALL:
			SVUT_REG_TEST_METHOD(testSuccess);
			SVUT_REG_TEST_METHOD(testFailure);
			SVUT_REG_TEST_METHOD(testTodo);
			SVUT_REG_TEST_METHOD(testIndev);
			SVUT_REG_TEST_METHOD(testUnknown_1);
			SVUT_REG_TEST_METHOD(testUnknown_2);
			SVUT_REG_TEST_METHOD(testFailIsTodo_1);
			SVUT_REG_TEST_METHOD(testFailIsTodo_2);
			SVUT_REG_TEST_METHOD(testFailIsTodo_3);
			SVUT_REG_TEST_METHOD(testSuccessIsIndev);
			break;
		default:
			throw svutExInternalError("Unknown flag");
	}
}
