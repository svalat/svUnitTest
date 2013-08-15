/*****************************************************
             PROJECT  : svUnitTest
             VERSION  : 0.5.0-dev
             DATE     : 11/2012
             AUTHOR   : Valat Sébastien
             LICENSE  : CeCILL-C 2.1
*****************************************************/

#ifndef UNIT_TEST_SVUNITTEST_FAKE_HEADER
#define UNIT_TEST_SVUNITTEST_FAKE_HEADER

/********************  HEADERS  *********************/
#include "../resources/svUnitTest_fake/include/svUnitTest/svUnitTest.h"
#include <cstring>

/**********************  USING  *********************/
using namespace svUnitTest;

/*********************  CLASS  **********************/
class UnitTest_svUnitTestFake2 : public svUnitTest::svutTestCase
{
	public:
		UnitTest_svUnitTestFake2(void);
		virtual void testMethodsRegistration(void );
		virtual void setUp(void);
		virtual void tearDown(void);
		
		void testSimpleCall(void);

		void testMacroAssertTrue_good(void);
		void testMacroAssertTrue_bad(void);
		void testMacroAssertFalse_good(void);
		void testMacroAssertFalse_bad(void);
};

/*******************  FUNCTION  *********************/
UnitTest_svUnitTestFake2::UnitTest_svUnitTestFake2(void ): svutTestCase("svUnitTestFake2")
{
}

/*******************  FUNCTION  *********************/
void UnitTest_svUnitTestFake2::testMethodsRegistration(void )
{
	SVUT_REG_TEST_METHOD(testSimpleCall);
	SVUT_REG_TEST_METHOD(testMacroAssertTrue_good);
	SVUT_REG_TEST_METHOD(testMacroAssertTrue_bad);
	SVUT_REG_TEST_METHOD(testMacroAssertFalse_good);
	SVUT_REG_TEST_METHOD(testMacroAssertFalse_bad);
}

/*******************  FUNCTION  *********************/
void UnitTest_svUnitTestFake2::setUp(void )
{

}

/*******************  FUNCTION  *********************/
void UnitTest_svUnitTestFake2::tearDown(void )
{

}

/*******************  FUNCTION  *********************/
void UnitTest_svUnitTestFake2::testSimpleCall(void )
{

}

/*******************  FUNCTION  *********************/
void UnitTest_svUnitTestFake2::testMacroAssertTrue_good(void )
{
	try {
		SVUT_ASSERT_TRUE(true);
	} catch (svutExAssertFake) {
		SVUT_ASSERT_FAIL("Thow unexpected svutExAssertFake exception.");
	} catch (...) {
		SVUT_ASSERT_FAIL("Thow unexpected exception.");
	}
}

/*******************  FUNCTION  *********************/
void UnitTest_svUnitTestFake2::testMacroAssertTrue_bad(void )
{
	try {
		SVUT_ASSERT_TRUE(false);
		SVUT_ASSERT_FAIL("Not throw expected svutExAssertFake exception.");
	} catch (svutExAssertFake) {
	} catch (...) {
		SVUT_ASSERT_FAIL("Thow unexpected exception.");
	}
}

/*******************  FUNCTION  *********************/
void UnitTest_svUnitTestFake2::testMacroAssertFalse_good(void )
{
	try {
		SVUT_ASSERT_FALSE(false);
	} catch (svutExAssertFake) {
		SVUT_ASSERT_FAIL("Thow unexpected svutExAssertFake exception.");
	} catch (...) {
		SVUT_ASSERT_FAIL("Thow unexpected exception.");
	}
}

/*******************  FUNCTION  *********************/
void UnitTest_svUnitTestFake2::testMacroAssertFalse_bad(void )
{
	try {
		SVUT_ASSERT_FALSE(true);
		SVUT_ASSERT_FAIL("Not throw expected svutExAssertFake exception.");
	} catch (svutExAssertFake) {
	} catch (...) {
		SVUT_ASSERT_FAIL("Thow unexpected exception.");
	}
}

SVUT_REGISTER_TEST_CASE(UnitTest_svUnitTestFake2);

#endif
