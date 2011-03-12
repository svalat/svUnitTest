/*****************************************************
             PROJECT  : svUnitTest
             VERSION  : 0.3.0-dev
             DATE     : 03/2011
             AUTHOR   : Valat Sébastien
             LICENSE  : CeCILL-C
*****************************************************/

#ifndef UNIT_TEST_SVUNITTEST_FAKE_HEADER
#define UNIT_TEST_SVUNITTEST_FAKE_HEADER

/********************  HEADERS  *********************/
#include "../resources/svUnitTest_fake/include/svUnitTest/svUnitTest.h"

/**********************  USING  *********************/
using namespace svUnitTest;

/*********************  CLASS  **********************/
class UnitTest_svUnitTestFake : public svUnitTest::svutTestCase
{
	public:
		UnitTest_svUnitTestFake(void);
		virtual void testMethodsRegistration(void );
		virtual void setUp(void);
		virtual void tearDown(void);
		void testSimpleCall(void);
		void testAssertTrue(void);
		void testAssertFalse(void);
		void testAssertNull(void);
		void testAssertNotNull(void);
		void testAssertEqual(void);
		void testAssertNotEqual(void);
		void testAssertEqualStric(void);
		void testAssertNotEqualStric(void);
		void testAssertSame(void);
		void testAssertNotSame(void);
		void testAssertFail(void);
		void testAssertTodo(void);
		void testAssertIndev(void);
		void testAssertNotExecThis(void);
		void testAssertThrow(void);
		void testAssertThrowSomething(void);
		void testAssertNotThrow(void);
		void testMayNotThrow(void);
};

/*******************  FUNCTION  *********************/
UnitTest_svUnitTestFake::UnitTest_svUnitTestFake(void ): svutTestCase("svUnitTestFake")
{
}

/*******************  FUNCTION  *********************/
void UnitTest_svUnitTestFake::testMethodsRegistration(void )
{
	SVUT_REG_TEST_METHOD(testSimpleCall);
	SVUT_REG_TEST_METHOD(testAssertTrue);
	SVUT_REG_TEST_METHOD(testAssertFalse);
	SVUT_REG_TEST_METHOD(testAssertNull);
	SVUT_REG_TEST_METHOD(testAssertNotNull);
	SVUT_REG_TEST_METHOD(testAssertEqual);
	SVUT_REG_TEST_METHOD(testAssertNotEqual);
	SVUT_REG_TEST_METHOD(testAssertEqualStric);
	SVUT_REG_TEST_METHOD(testAssertNotEqualStric);
	SVUT_REG_TEST_METHOD(testAssertSame);
	SVUT_REG_TEST_METHOD(testAssertNotSame);
	SVUT_REG_TEST_METHOD(testAssertFail);
	SVUT_REG_TEST_METHOD(testAssertTodo);
	SVUT_REG_TEST_METHOD(testAssertIndev);
	SVUT_REG_TEST_METHOD(testAssertNotExecThis);
	SVUT_REG_TEST_METHOD(testAssertThrow);
	SVUT_REG_TEST_METHOD(testAssertThrowSomething);
	SVUT_REG_TEST_METHOD(testAssertNotThrow);
	SVUT_REG_TEST_METHOD(testMayNotThrow);
}

/*******************  FUNCTION  *********************/
void UnitTest_svUnitTestFake::setUp(void )
{

}

/*******************  FUNCTION  *********************/
void UnitTest_svUnitTestFake::tearDown(void )
{

}

/*******************  FUNCTION  *********************/
void UnitTest_svUnitTestFake::testSimpleCall(void )
{
}

/*******************  FUNCTION  *********************/
void UnitTest_svUnitTestFake::testAssertEqual(void )
{
}

/*******************  FUNCTION  *********************/
void UnitTest_svUnitTestFake::testAssertEqualStric(void )
{

}

/*******************  FUNCTION  *********************/
void UnitTest_svUnitTestFake::testAssertFail(void )
{

}

/*******************  FUNCTION  *********************/
void UnitTest_svUnitTestFake::testAssertFalse(void )
{

}

/*******************  FUNCTION  *********************/
void UnitTest_svUnitTestFake::testAssertIndev(void )
{

}

/*******************  FUNCTION  *********************/
void UnitTest_svUnitTestFake::testAssertNotEqual(void )
{

}

/*******************  FUNCTION  *********************/
void UnitTest_svUnitTestFake::testAssertNotEqualStric(void )
{

}

/*******************  FUNCTION  *********************/
void UnitTest_svUnitTestFake::testAssertNotExecThis(void )
{

}

/*******************  FUNCTION  *********************/
void UnitTest_svUnitTestFake::testAssertNotNull(void )
{

}

/*******************  FUNCTION  *********************/
void UnitTest_svUnitTestFake::testAssertNotSame(void )
{

}

/*******************  FUNCTION  *********************/
void UnitTest_svUnitTestFake::testAssertNotThrow(void )
{

}

/*******************  FUNCTION  *********************/
void UnitTest_svUnitTestFake::testAssertNull(void )
{

}

/*******************  FUNCTION  *********************/
void UnitTest_svUnitTestFake::testAssertSame(void )
{

}

/*******************  FUNCTION  *********************/
void UnitTest_svUnitTestFake::testAssertThrow(void )
{

}

/*******************  FUNCTION  *********************/
void UnitTest_svUnitTestFake::testAssertThrowSomething(void )
{

}

/*******************  FUNCTION  *********************/
void UnitTest_svUnitTestFake::testAssertTodo(void )
{

}

/*******************  FUNCTION  *********************/
void UnitTest_svUnitTestFake::testAssertTrue(void )
{
	SVUT_ASSERT_TRUE(false);
}

/*******************  FUNCTION  *********************/
void UnitTest_svUnitTestFake::testMayNotThrow(void )
{

}

SVUT_REGISTER_STANDELONE(UnitTest_svUnitTestFake);

#endif
