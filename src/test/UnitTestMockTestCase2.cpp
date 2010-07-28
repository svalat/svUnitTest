/*****************************************************
             PROJECT  : svUnitTest
             VERSION  : 0.0.2
             DATE     : 06/2010
             AUTHOR   : Valat Sébastien
             LICENSE  : CeCILL-C
*****************************************************/

/********************  HEADERS  *********************/
#include "UnitTestMockTestCase2.h"

using namespace svUnitTest;

/********************  METHODE  *********************/
UnitTestMockTestCase2::UnitTestMockTestCase2(void ):
	svutTestCase("UnitTestMockTestCase2")
{

}

/********************  METHODE  *********************/
void UnitTestMockTestCase2::setUp(void)
{
}

/********************  METHODE  *********************/
void UnitTestMockTestCase2::tearDown(void)
{
}

/********************  METHODE  *********************/
void UnitTestMockTestCase2::testSuccess(void )
{
}

/********************  METHODE  *********************/
void UnitTestMockTestCase2::testIndev(void )
{
	SVUT_ASSERT_INDEV("for the test");
}

/********************  METHODE  *********************/
void UnitTestMockTestCase2::testTodo(void )
{
	SVUT_ASSERT_TODO("for the test");
}

/********************  METHODE  *********************/
void UnitTestMockTestCase2::testFailure(void )
{
	SVUT_ASSERT_EQUAL(2,3);
}

/********************  METHODE  *********************/
void UnitTestMockTestCase2::testUnknown_1(void )
{
	throw std::bad_exception();
}

/********************  METHODE  *********************/
void UnitTestMockTestCase2::testUnknown_2(void )
{
	throw 42;
}

/********************  METHODE  *********************/
void UnitTestMockTestCase2::testFailIsTodo_1(void )
{
	this->failIsTodo("this is a test");
	SVUT_ASSERT_EQUAL(2,3);
}

/********************  METHODE  *********************/
void UnitTestMockTestCase2::testFailIsTodo_2(void )
{
	this->failIsTodo("this is a test");
	throw std::bad_exception();
}

/********************  METHODE  *********************/
void UnitTestMockTestCase2::testFailIsTodo_3(void )
{
	this->failIsTodo("this is a test");
	throw 42;
}

/********************  METHODE  *********************/
void UnitTestMockTestCase2::testSuccessIsIndev(void )
{
	this->failIsTodo("this is a test");
}

/********************  METHODE  *********************/
void UnitTestMockTestCase2::useTests(UnitTestMockTestCase2::UnitTestMockFlags flags)
{
	switch(flags)
	{
		case REGISTER_SUCCESS:
			SVUT_REG_TEST_METHOD(UnitTestMockTestCase2,testSuccess);
			break;
		case REGISTER_FAILURE:
			SVUT_REG_TEST_METHOD(UnitTestMockTestCase2,testFailure);
			break;
		case REGISTER_TODO:
			SVUT_REG_TEST_METHOD(UnitTestMockTestCase2,testTodo);
			break;
		case REGISTER_INDEV:
			SVUT_REG_TEST_METHOD(UnitTestMockTestCase2,testIndev);
			break;
		case REGISTER_UNKNOWN_1:
			SVUT_REG_TEST_METHOD(UnitTestMockTestCase2,testUnknown_1);
			break;
		case REGISTER_UNKNOWN_2:
			SVUT_REG_TEST_METHOD(UnitTestMockTestCase2,testUnknown_2);
			break;
		case REGISTER_FAIL_IS_TODO_1:
			SVUT_REG_TEST_METHOD(UnitTestMockTestCase2,testFailIsTodo_1);
			break;
		case REGISTER_FAIL_IS_TODO_2:
			SVUT_REG_TEST_METHOD(UnitTestMockTestCase2,testFailIsTodo_2);
			break;
		case REGISTER_FAIL_IS_TODO_3:
			SVUT_REG_TEST_METHOD(UnitTestMockTestCase2,testFailIsTodo_3);
			break;
		case REGISTER_SUCCESS_IS_INDEV:
			SVUT_REG_TEST_METHOD(UnitTestMockTestCase2,testSuccessIsIndev);
			break;
		case REGISTER_ALL:
			SVUT_REG_TEST_METHOD(UnitTestMockTestCase2,testSuccess);
			SVUT_REG_TEST_METHOD(UnitTestMockTestCase2,testFailure);
			SVUT_REG_TEST_METHOD(UnitTestMockTestCase2,testTodo);
			SVUT_REG_TEST_METHOD(UnitTestMockTestCase2,testIndev);
			SVUT_REG_TEST_METHOD(UnitTestMockTestCase2,testUnknown_1);
			SVUT_REG_TEST_METHOD(UnitTestMockTestCase2,testUnknown_2);
			SVUT_REG_TEST_METHOD(UnitTestMockTestCase2,testFailIsTodo_1);
			SVUT_REG_TEST_METHOD(UnitTestMockTestCase2,testFailIsTodo_2);
			SVUT_REG_TEST_METHOD(UnitTestMockTestCase2,testFailIsTodo_3);
			SVUT_REG_TEST_METHOD(UnitTestMockTestCase2,testSuccessIsIndev);
			break;
		default:
			throw svutExInternalError("Unknown flag");
	}
}
