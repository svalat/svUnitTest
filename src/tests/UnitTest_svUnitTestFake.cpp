/*****************************************************
             PROJECT  : svUnitTest
             VERSION  : 0.5.0-dev
             DATE     : 11/2012
             AUTHOR   : Valat Sébastien
             LICENSE  : CeCILL-C
*****************************************************/

#ifndef UNIT_TEST_SVUNITTEST_FAKE_HEADER
#define UNIT_TEST_SVUNITTEST_FAKE_HEADER

/********************  HEADERS  *********************/
#include "../resources/svUnitTest_fake/include/svUnitTest/svUnitTest.h"
#include <cstring>

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

		void testSetupIsCalled(void);
		void testMacroAssertTrue_good(void);
		void testMacroAssertTrue_bad(void);
		void testMacroAssertFalse_good(void);
		void testMacroAssertFalse_bad(void);
		void testMacroAssertNull_good(void);
		void testMacroAssertNull_bad(void);
		void testMacroAssertNotNull_good(void);
		void testMacroAssertNotNull_bad(void);
		void testMacroAssertEqual_int_good(void);
		void testMacroAssertEqual_int_bad(void);
		void testMacroAssertEqual_cstr_good(void);
		void testMacroAssertEqual_cstr_bad(void);
		void testMacroAssertEqual_custotype_good(void);
		void testMacroAssertEqual_custotype_bad(void);
		void testMacroAssertNotEqual_int_good(void);
		void testMacroAssertNotEqual_int_bad(void);
		void testMacroAssertNotEqual_cstr_good(void);
		void testMacroAssertNotEqual_cstr_bad(void);
		void testMacroAssertNotEqual_custotype_good(void);
		void testMacroAssertNotEqual_custotype_bad(void);
		void testMacroAssertEqualStrict_int_good(void);
		void testMacroAssertNotEqualStrict_int_good(void);
		void testMacroAssertEqualStrict_cstr_good(void);
		void testMacroAssertNotEqualStrict_cstr_good(void);
		void testMacroAssertSame_good(void);
		void testMacroAssertSame_bad(void);
		void testMacroAssertNotSame_good(void);
		void testMacroAssertNotSame_bad(void);
		void testMacroAssertFailCustom(void);
		void testMacroAssertTodo(void);
		void testMacroAssertIndev(void);
		void testMacroAssertNotExec(void);
		void testMacroAssertThrow_good(void);
		void testMacroAssertThrow_another(void);
		void testMacroAssertThrow_notthrow(void);
		void testMacroAssertThrowSomething_good(void);
		void testMacroAssertThrowSomething_bad(void);
		void testMacroAssertNotThrow_good(void);
		void testMacroAssertNotThrow_bad(void);
		void testMacroAssertNotThrow_others(void);
		void testMacroAssertMayNotThrow_good(void);
		void testMacroAssertMayNotThrow_bad(void);
		void testMacroAssertGT_int_good(void);
		void testMacroAssertGT_int_bad(void);
		void testMacroAssertGT_int_limit(void);
		void testMacroAssertGE_int_good(void);
		void testMacroAssertGE_int_bad(void);
		void testMacroAssertGE_int_limit(void);
		void testMacroAssertLT_int_good(void);
		void testMacroAssertLT_int_bad(void);
		void testMacroAssertLT_int_limit(void);
		void testMacroAssertLE_int_good(void);
		void testMacroAssertLE_int_bad(void);
		void testMacroAssertLE_int_limit(void);
		void testMacroAssertGT_cstr_good(void);
		void testMacroAssertGT_cstr_bad(void);
		void testMacroAssertGT_cstr_limit(void);
		void testMacroAssertGE_cstr_good(void);
		void testMacroAssertGE_cstr_bad(void);
		void testMacroAssertGE_cstr_limit(void);
		void testMacroAssertLT_cstr_good(void);
		void testMacroAssertLT_cstr_bad(void);
		void testMacroAssertLT_cstr_limit(void);
		void testMacroAssertLE_cstr_good(void);
		void testMacroAssertLE_cstr_bad(void);
		void testMacroAssertLE_cstr_limit(void);
		void testMacroAssertGT_custotype_good(void);
		void testMacroAssertGT_custotype_bad(void);
		void testMacroAssertGT_custotype_limit(void);
		void testMacroAssertGE_custotype_good(void);
		void testMacroAssertGE_custotype_bad(void);
		void testMacroAssertGE_custotype_limit(void);
		void testMacroAssertLT_custotype_good(void);
		void testMacroAssertLT_custotype_bad(void);
		void testMacroAssertLT_custotype_limit(void);
		void testMacroAssertLE_custotype_good(void);
		void testMacroAssertLE_custotype_bad(void);
		void testMacroAssertLE_custotype_limit(void);
		void testMacroAssertZero_good(void);
		void testMacroAssertZero_bad(void);
		void testMacroAssertZeros_good(void);
		void testMacroAssertZeros_bad_1(void);
		void testMacroAssertZeros_bad_2(void);

		bool checkSetup;
};

/********************  STRUCT  **********************/
struct UnitTestCustoType
{
	int value1;
	int value2;
};

/*******************  FUNCTION  *********************/
bool asserterOperatorEqual(const UnitTestCustoType & v1,const UnitTestCustoType & v2)
{
	return (v1.value1 == v2.value1 && v1.value2 == v2.value2);
}

/*******************  FUNCTION  *********************/
bool asserterOperatorNotEqual(const UnitTestCustoType & v1,const UnitTestCustoType & v2)
{
	return (v1.value1 != v2.value1 || v1.value2 != v2.value2);
}

/*******************  FUNCTION  *********************/
static bool asserterOperatorGE(const UnitTestCustoType & v1,const UnitTestCustoType & v2)
{
	return (v1.value1 >= v2.value1 && v1.value2 >= v2.value2);
}

/*******************  FUNCTION  *********************/
static bool asserterOperatorGT(const UnitTestCustoType & v1,const UnitTestCustoType & v2)
{
	return (v1.value1 > v2.value1 && v1.value2 > v2.value2);
}

/*******************  FUNCTION  *********************/
static bool asserterOperatorLE(const UnitTestCustoType & v1,const UnitTestCustoType & v2)
{
	return (v1.value1 <= v2.value1 && v1.value2 <= v2.value2);
}

/*******************  FUNCTION  *********************/
static bool asserterOperatorLT(const UnitTestCustoType & v1,const UnitTestCustoType & v2)
{
	return (v1.value1 < v2.value1 && v1.value2 < v2.value2);
}

/*******************  FUNCTION  *********************/
std::string asserterToString(const UnitTestCustoType & value)
{
	std::stringstream res;
	res << value.value1 << ", " << value.value2;
	return res.str();
}

/*******************  FUNCTION  *********************/
UnitTest_svUnitTestFake::UnitTest_svUnitTestFake(void ): svutTestCase("svUnitTestFake")
{
	checkSetup = false;
}

/*******************  FUNCTION  *********************/
void UnitTest_svUnitTestFake::testMethodsRegistration(void )
{
	SVUT_REG_TEST_METHOD(testSetupIsCalled);
	SVUT_REG_TEST_METHOD(testSimpleCall);
	SVUT_REG_TEST_METHOD(testMacroAssertTrue_good);
	SVUT_REG_TEST_METHOD(testMacroAssertTrue_bad);
	SVUT_REG_TEST_METHOD(testMacroAssertFalse_good);
	SVUT_REG_TEST_METHOD(testMacroAssertFalse_bad);
	SVUT_REG_TEST_METHOD(testMacroAssertNull_good);
	SVUT_REG_TEST_METHOD(testMacroAssertNull_bad);
	SVUT_REG_TEST_METHOD(testMacroAssertNotNull_good);
	SVUT_REG_TEST_METHOD(testMacroAssertNotNull_bad);
	SVUT_REG_TEST_METHOD(testMacroAssertEqual_int_good);
	SVUT_REG_TEST_METHOD(testMacroAssertEqual_int_bad);
	SVUT_REG_TEST_METHOD(testMacroAssertEqual_cstr_good);
	SVUT_REG_TEST_METHOD(testMacroAssertEqual_cstr_bad);
	SVUT_REG_TEST_METHOD(testMacroAssertEqual_custotype_good);
	SVUT_REG_TEST_METHOD(testMacroAssertEqual_custotype_bad);
	SVUT_REG_TEST_METHOD(testMacroAssertNotEqual_int_good);
	SVUT_REG_TEST_METHOD(testMacroAssertNotEqual_int_bad);
	SVUT_REG_TEST_METHOD(testMacroAssertNotEqual_cstr_good);
	SVUT_REG_TEST_METHOD(testMacroAssertNotEqual_cstr_bad);
	SVUT_REG_TEST_METHOD(testMacroAssertNotEqual_custotype_good);
	SVUT_REG_TEST_METHOD(testMacroAssertNotEqual_custotype_bad);
	SVUT_REG_TEST_METHOD(testMacroAssertEqualStrict_int_good);
	SVUT_REG_TEST_METHOD(testMacroAssertNotEqualStrict_int_good);
	SVUT_REG_TEST_METHOD(testMacroAssertEqualStrict_cstr_good);
	SVUT_REG_TEST_METHOD(testMacroAssertNotEqualStrict_cstr_good);
	SVUT_REG_TEST_METHOD(testMacroAssertSame_good);
	SVUT_REG_TEST_METHOD(testMacroAssertSame_bad);
	SVUT_REG_TEST_METHOD(testMacroAssertNotSame_good);
	SVUT_REG_TEST_METHOD(testMacroAssertNotSame_bad);
	SVUT_REG_TEST_METHOD(testMacroAssertFailCustom);
	SVUT_REG_TEST_METHOD(testMacroAssertTodo);
	SVUT_REG_TEST_METHOD(testMacroAssertIndev);
	SVUT_REG_TEST_METHOD(testMacroAssertNotExec);
	SVUT_REG_TEST_METHOD(testMacroAssertThrow_good);
	SVUT_REG_TEST_METHOD(testMacroAssertThrow_another);
	SVUT_REG_TEST_METHOD(testMacroAssertThrow_notthrow);
	SVUT_REG_TEST_METHOD(testMacroAssertThrowSomething_good);
	SVUT_REG_TEST_METHOD(testMacroAssertThrowSomething_bad);
	SVUT_REG_TEST_METHOD(testMacroAssertNotThrow_good);
	SVUT_REG_TEST_METHOD(testMacroAssertNotThrow_bad);
	SVUT_REG_TEST_METHOD(testMacroAssertNotThrow_others);
	SVUT_REG_TEST_METHOD(testMacroAssertMayNotThrow_good);
	SVUT_REG_TEST_METHOD(testMacroAssertMayNotThrow_bad);
	SVUT_REG_TEST_METHOD(testMacroAssertGT_int_good);
	SVUT_REG_TEST_METHOD(testMacroAssertGT_int_bad);
	SVUT_REG_TEST_METHOD(testMacroAssertGT_int_limit);
	SVUT_REG_TEST_METHOD(testMacroAssertGE_int_good);
	SVUT_REG_TEST_METHOD(testMacroAssertGE_int_bad);
	SVUT_REG_TEST_METHOD(testMacroAssertGE_int_limit);
	SVUT_REG_TEST_METHOD(testMacroAssertLT_int_good);
	SVUT_REG_TEST_METHOD(testMacroAssertLT_int_bad);
	SVUT_REG_TEST_METHOD(testMacroAssertLT_int_limit);
	SVUT_REG_TEST_METHOD(testMacroAssertLE_int_good);
	SVUT_REG_TEST_METHOD(testMacroAssertLE_int_bad);
	SVUT_REG_TEST_METHOD(testMacroAssertLE_int_limit);
	SVUT_REG_TEST_METHOD(testMacroAssertGT_cstr_good);
	SVUT_REG_TEST_METHOD(testMacroAssertGT_cstr_bad);
	SVUT_REG_TEST_METHOD(testMacroAssertGT_cstr_limit);
	SVUT_REG_TEST_METHOD(testMacroAssertGE_cstr_good);
	SVUT_REG_TEST_METHOD(testMacroAssertGE_cstr_bad);
	SVUT_REG_TEST_METHOD(testMacroAssertGE_cstr_limit);
	SVUT_REG_TEST_METHOD(testMacroAssertLT_cstr_good);
	SVUT_REG_TEST_METHOD(testMacroAssertLT_cstr_bad);
	SVUT_REG_TEST_METHOD(testMacroAssertLT_cstr_limit);
	SVUT_REG_TEST_METHOD(testMacroAssertLE_cstr_good);
	SVUT_REG_TEST_METHOD(testMacroAssertLE_cstr_bad);
	SVUT_REG_TEST_METHOD(testMacroAssertLE_cstr_limit);
	SVUT_REG_TEST_METHOD(testMacroAssertGT_custotype_bad);
	SVUT_REG_TEST_METHOD(testMacroAssertGT_custotype_limit);
	SVUT_REG_TEST_METHOD(testMacroAssertGE_custotype_good);
	SVUT_REG_TEST_METHOD(testMacroAssertGE_custotype_bad);
	SVUT_REG_TEST_METHOD(testMacroAssertGE_custotype_limit);
	SVUT_REG_TEST_METHOD(testMacroAssertLT_custotype_good);
	SVUT_REG_TEST_METHOD(testMacroAssertLT_custotype_bad);
	SVUT_REG_TEST_METHOD(testMacroAssertLT_custotype_limit);
	SVUT_REG_TEST_METHOD(testMacroAssertLE_custotype_good);
	SVUT_REG_TEST_METHOD(testMacroAssertLE_custotype_bad);
	SVUT_REG_TEST_METHOD(testMacroAssertLE_custotype_limit);
	SVUT_REG_TEST_METHOD(testMacroAssertZero_good);
	SVUT_REG_TEST_METHOD(testMacroAssertZero_bad);
	SVUT_REG_TEST_METHOD(testMacroAssertZeros_good);
	SVUT_REG_TEST_METHOD(testMacroAssertZeros_bad_1);
	SVUT_REG_TEST_METHOD(testMacroAssertZeros_bad_2);
}

/*******************  FUNCTION  *********************/
void UnitTest_svUnitTestFake::setUp(void )
{
	SVUT_ASSERT_FALSE(checkSetup);
	checkSetup = true;
}

/*******************  FUNCTION  *********************/
void UnitTest_svUnitTestFake::tearDown(void )
{
	SVUT_ASSERT_TRUE(checkSetup);
	checkSetup = false;
}

/*******************  FUNCTION  *********************/
void UnitTest_svUnitTestFake::testSetupIsCalled(void )
{
	SVUT_ASSERT_TRUE(checkSetup);
}

/*******************  FUNCTION  *********************/
void UnitTest_svUnitTestFake::testSimpleCall(void )
{

}

/*******************  FUNCTION  *********************/
void UnitTest_svUnitTestFake::testMacroAssertTrue_good(void )
{
	try {
		SVUT_ASSERT_TRUE(true);
	} catch (svutExAssertFake &) {
		SVUT_ASSERT_FAIL("Thow unexpected svutExAssertFake exception.");
	} catch (...) {
		SVUT_ASSERT_FAIL("Thow unexpected exception.");
	}
}

/*******************  FUNCTION  *********************/
void UnitTest_svUnitTestFake::testMacroAssertTrue_bad(void )
{
	try {
		SVUT_ASSERT_TRUE(false);
		SVUT_ASSERT_FAIL("Not throw expected svutExAssertFake exception.");
	} catch (svutExAssertFake &) {
	} catch (...) {
		SVUT_ASSERT_FAIL("Thow unexpected exception.");
	}
}

/*******************  FUNCTION  *********************/
void UnitTest_svUnitTestFake::testMacroAssertFalse_good(void )
{
	try {
		SVUT_ASSERT_FALSE(false);
	} catch (svutExAssertFake &) {
		SVUT_ASSERT_FAIL("Thow unexpected svutExAssertFake exception.");
	} catch (...) {
		SVUT_ASSERT_FAIL("Thow unexpected exception.");
	}
}

/*******************  FUNCTION  *********************/
void UnitTest_svUnitTestFake::testMacroAssertFalse_bad(void )
{
	try {
		SVUT_ASSERT_FALSE(true);
		SVUT_ASSERT_FAIL("Not throw expected svutExAssertFake exception.");
	} catch (svutExAssertFake &) {
	} catch (...) {
		SVUT_ASSERT_FAIL("Thow unexpected exception.");
	}
}

/*******************  FUNCTION  *********************/
void UnitTest_svUnitTestFake::testMacroAssertNull_good(void )
{
	try {
		SVUT_ASSERT_NULL(NULL);
	} catch (svutExAssertFake &) {
		SVUT_ASSERT_FAIL("Thow unexpected svutExAssertFake exception.");
	} catch (...) {
		SVUT_ASSERT_FAIL("Thow unexpected exception.");
	}
}

/*******************  FUNCTION  *********************/
void UnitTest_svUnitTestFake::testMacroAssertNull_bad(void )
{
	try {
		SVUT_ASSERT_NULL(0x55);
		SVUT_ASSERT_FAIL("Not throw expected svutExAssertFake exception.");
	} catch (svutExAssertFake &) {
	} catch (...) {
		SVUT_ASSERT_FAIL("Thow unexpected exception.");
	}
}

/*******************  FUNCTION  *********************/
void UnitTest_svUnitTestFake::testMacroAssertNotNull_good(void )
{
	try {
		SVUT_ASSERT_NOT_NULL(0x55);
	} catch (svutExAssertFake &) {
		SVUT_ASSERT_FAIL("Thow unexpected svutExAssertFake exception.");
	} catch (...) {
		SVUT_ASSERT_FAIL("Thow unexpected exception.");
	}
}

/*******************  FUNCTION  *********************/
void UnitTest_svUnitTestFake::testMacroAssertNotNull_bad(void )
{
	try {
		SVUT_ASSERT_NOT_NULL(NULL);
		SVUT_ASSERT_FAIL("Not throw expected svutExAssertFake exception.");
	} catch (svutExAssertFake &) {
	} catch (...) {
		SVUT_ASSERT_FAIL("Thow unexpected exception.");
	}
}

/*******************  FUNCTION  *********************/
void UnitTest_svUnitTestFake::testMacroAssertEqual_int_good(void)
{
	try {
		SVUT_ASSERT_EQUAL(10,10);
	} catch (svutExAssertFake &) {
		SVUT_ASSERT_FAIL("Thow unexpected svutExAssertFake exception.");
	} catch (...) {
		SVUT_ASSERT_FAIL("Thow unexpected exception.");
	}
}

/*******************  FUNCTION  *********************/
void UnitTest_svUnitTestFake::testMacroAssertEqual_int_bad(void)
{
	try {
		SVUT_ASSERT_EQUAL(10,42);
		SVUT_ASSERT_FAIL("Not throw expected svutExAssertFake exception.");
	} catch (svutExAssertFake &) {
	} catch (...) {
		SVUT_ASSERT_FAIL("Thow unexpected exception.");
	}
}

/*******************  FUNCTION  *********************/
void UnitTest_svUnitTestFake::testMacroAssertEqual_cstr_good(void)
{
	try {
		SVUT_ASSERT_EQUAL("Hello World !!","Hello World !!");
	} catch (svutExAssertFake &) {
		SVUT_ASSERT_FAIL("Thow unexpected svutExAssertFake exception.");
	} catch (...) {
		SVUT_ASSERT_FAIL("Thow unexpected exception.");
	}
}

/*******************  FUNCTION  *********************/
void UnitTest_svUnitTestFake::testMacroAssertEqual_cstr_bad(void)
{
	try {
		SVUT_ASSERT_EQUAL("Hello World!!","Hello Bob!!");
		SVUT_ASSERT_FAIL("Not throw expected svutExAssertFake exception.");
	} catch (svutExAssertFake &) {
	} catch (...) {
		SVUT_ASSERT_FAIL("Thow unexpected exception.");
	}
}

/*******************  FUNCTION  *********************/
void UnitTest_svUnitTestFake::testMacroAssertEqual_custotype_good(void)
{
	try {
		UnitTestCustoType v1 = {10,20};
		UnitTestCustoType v2 = {10,20};
		SVUT_ASSERT_EQUAL(v1,v2);
	} catch (svutExAssertFake &) {
		SVUT_ASSERT_FAIL("Thow unexpected svutExAssertFake exception.");
	} catch (...) {
		SVUT_ASSERT_FAIL("Thow unexpected exception.");
	}
}

/*******************  FUNCTION  *********************/
void UnitTest_svUnitTestFake::testMacroAssertEqual_custotype_bad(void)
{
	try {
		UnitTestCustoType v1 = {10,20};
		UnitTestCustoType v2 = {10,40};
		SVUT_ASSERT_EQUAL(v1,v2);		SVUT_ASSERT_FAIL("Not throw expected svutExAssertFake exception.");
	} catch (svutExAssertFake &) {
	} catch (...) {
		SVUT_ASSERT_FAIL("Thow unexpected exception.");
	}
}

/*******************  FUNCTION  *********************/
void UnitTest_svUnitTestFake::testMacroAssertNotEqual_int_good(void)
{
	try {
		SVUT_ASSERT_NOT_EQUAL(10,20);
	} catch (svutExAssertFake &) {
		SVUT_ASSERT_FAIL("Thow unexpected svutExAssertFake exception.");
	} catch (...) {
		SVUT_ASSERT_FAIL("Thow unexpected exception.");
	}
}

/*******************  FUNCTION  *********************/
void UnitTest_svUnitTestFake::testMacroAssertNotEqual_int_bad(void)
{
	try {
		SVUT_ASSERT_NOT_EQUAL(10,10);
		SVUT_ASSERT_FAIL("Not throw expected svutExAssertFake exception.");
	} catch (svutExAssertFake &) {
	} catch (...) {
		SVUT_ASSERT_FAIL("Thow unexpected exception.");
	}
}

/*******************  FUNCTION  *********************/
void UnitTest_svUnitTestFake::testMacroAssertNotEqual_cstr_good(void)
{
	try {
		SVUT_ASSERT_NOT_EQUAL("Hello World !!","Hello Bob !!");
	} catch (svutExAssertFake &) {
		SVUT_ASSERT_FAIL("Thow unexpected svutExAssertFake exception.");
	} catch (...) {
		SVUT_ASSERT_FAIL("Thow unexpected exception.");
	}
}

/*******************  FUNCTION  *********************/
void UnitTest_svUnitTestFake::testMacroAssertNotEqual_cstr_bad(void)
{
	try {
		SVUT_ASSERT_NOT_EQUAL("Hello World!!","Hello World!!");
		SVUT_ASSERT_FAIL("Not throw expected svutExAssertFake exception.");
	} catch (svutExAssertFake &) {
	} catch (...) {
		SVUT_ASSERT_FAIL("Thow unexpected exception.");
	}
}

/*******************  FUNCTION  *********************/
void UnitTest_svUnitTestFake::testMacroAssertNotEqual_custotype_good(void)
{
	try {
		UnitTestCustoType v1 = {10,20};
		UnitTestCustoType v2 = {10,30};
		SVUT_ASSERT_NOT_EQUAL(v1,v2);
	} catch (svutExAssertFake &) {
		SVUT_ASSERT_FAIL("Thow unexpected svutExAssertFake exception.");
	} catch (...) {
		SVUT_ASSERT_FAIL("Thow unexpected exception.");
	}
}

/*******************  FUNCTION  *********************/
void UnitTest_svUnitTestFake::testMacroAssertNotEqual_custotype_bad(void)
{
	try {
		UnitTestCustoType v1 = {10,20};
		UnitTestCustoType v2 = {10,20};
		SVUT_ASSERT_NOT_EQUAL(v1,v2);
		SVUT_ASSERT_FAIL("Not throw expected svutExAssertFake exception.");
	} catch (svutExAssertFake &) {
	} catch (...) {
		SVUT_ASSERT_FAIL("Thow unexpected exception.");
	}
}

/*******************  FUNCTION  *********************/
void UnitTest_svUnitTestFake::testMacroAssertEqualStrict_int_good(void)
{
	try {
		SVUT_ASSERT_EQUAL_STRICT(10,10);
	} catch (svutExAssertFake &) {
		SVUT_ASSERT_FAIL("Thow unexpected svutExAssertFake exception.");
	} catch (...) {
		SVUT_ASSERT_FAIL("Thow unexpected exception.");
	}
}

/*******************  FUNCTION  *********************/
void UnitTest_svUnitTestFake::testMacroAssertNotEqualStrict_int_good(void)
{
	try {
		SVUT_ASSERT_NOT_EQUAL_STRICT(10,20);
	} catch (svutExAssertFake &) {
		SVUT_ASSERT_FAIL("Thow unexpected svutExAssertFake exception.");
	} catch (...) {
		SVUT_ASSERT_FAIL("Thow unexpected exception.");
	}
}

/*******************  FUNCTION  *********************/
void UnitTest_svUnitTestFake::testMacroAssertEqualStrict_cstr_good(void)
{
	try {
		SVUT_ASSERT_EQUAL_STRICT("Hello World !!","Hello World !!");
	} catch (svutExAssertFake &) {
		SVUT_ASSERT_FAIL("Thow unexpected svutExAssertFake exception.");
	} catch (...) {
		SVUT_ASSERT_FAIL("Thow unexpected exception.");
	}
}

/*******************  FUNCTION  *********************/
void UnitTest_svUnitTestFake::testMacroAssertNotEqualStrict_cstr_good(void)
{
	try {
		SVUT_ASSERT_NOT_EQUAL_STRICT("Hello World !!","Hello Bob !!");
	} catch (svutExAssertFake &) {
		SVUT_ASSERT_FAIL("Thow unexpected svutExAssertFake exception.");
	} catch (...) {
		SVUT_ASSERT_FAIL("Thow unexpected exception.");
	}
}

/*******************  FUNCTION  *********************/
void UnitTest_svUnitTestFake::testMacroAssertSame_good(void)
{
	try {
		int a = 66;
		SVUT_ASSERT_SAME(&a,&a);
	} catch (svutExAssertFake &) {
		SVUT_ASSERT_FAIL("Thow unexpected svutExAssertFake exception.");
	} catch (...) {
		SVUT_ASSERT_FAIL("Thow unexpected exception.");
	}
}

/*******************  FUNCTION  *********************/
void UnitTest_svUnitTestFake::testMacroAssertSame_bad(void)
{
	int a = 66;
	int b = 66;
	try {
		SVUT_ASSERT_SAME(&a,&b);
		SVUT_ASSERT_FAIL("Not throw expected svutExAssertFake exception.");
	} catch (svutExAssertFake &) {
	} catch (...) {
		SVUT_ASSERT_FAIL("Thow unexpected exception.");
	}
}

/*******************  FUNCTION  *********************/
void UnitTest_svUnitTestFake::testMacroAssertNotSame_good(void)
{
	try {
		int a = 66;
		int b = 66;
		SVUT_ASSERT_NOT_SAME(&a,&b);
	} catch (svutExAssertFake &) {
		SVUT_ASSERT_FAIL("Thow unexpected svutExAssertFake exception.");
	} catch (...) {
		SVUT_ASSERT_FAIL("Thow unexpected exception.");
	}
}

/*******************  FUNCTION  *********************/
void UnitTest_svUnitTestFake::testMacroAssertNotSame_bad(void)
{
	int a = 66;
	try {
		SVUT_ASSERT_NOT_SAME(&a,&a);
		SVUT_ASSERT_FAIL("Not throw expected svutExAssertFake exception.");
	} catch (svutExAssertFake &) {
	} catch (...) {
		SVUT_ASSERT_FAIL("Thow unexpected exception.");
	}
}

/*******************  FUNCTION  *********************/
void UnitTest_svUnitTestFake::testMacroAssertFailCustom(void )
{
	try {
		SVUT_ASSERT_FAIL("test fail");
		SVUT_ASSERT_FAIL("Not throw expected svutExAssertFake exception.");
	} catch (svutExAssertFake &) {
	} catch (...) {
		SVUT_ASSERT_FAIL("Thow unexpected exception.");
	}
}

/*******************  FUNCTION  *********************/
void UnitTest_svUnitTestFake::testMacroAssertTodo(void )
{
	try {
		SVUT_ASSERT_TODO("test todo");
		SVUT_ASSERT_FAIL("Not throw expected svutExAssertFake exception.");
	} catch (svutExAssertFake &) {
	} catch (...) {
		SVUT_ASSERT_FAIL("Thow unexpected exception.");
	}
}

/*******************  FUNCTION  *********************/
void UnitTest_svUnitTestFake::testMacroAssertIndev(void )
{
	try {
		SVUT_ASSERT_INDEV("test indev");
		SVUT_ASSERT_FAIL("Not throw expected svutExAssertFake exception.");
	} catch (svutExAssertFake &) {
	} catch (...) {
		SVUT_ASSERT_FAIL("Thow unexpected exception.");
	}
}

/*******************  FUNCTION  *********************/
void UnitTest_svUnitTestFake::testMacroAssertNotExec(void )
{
	try {
		SVUT_ASSERT_NOT_EXEC_THIS();
		SVUT_ASSERT_FAIL("Not throw expected svutExAssertFake exception.");
	} catch (svutExAssertFake &) {
	} catch (...) {
		SVUT_ASSERT_FAIL("Thow unexpected exception.");
	}
}

/*******************  FUNCTION  *********************/
void UnitTest_svUnitTestFake::testMacroAssertThrow_good(void)
{
	try {
		SVUT_ASSERT_THROW(int,throw 10);
	} catch (svutExAssertFake &) {
		SVUT_ASSERT_FAIL("Thow unexpected svutExAssertFake exception.");
	} catch (...) {
		SVUT_ASSERT_FAIL("Thow unexpected exception.");
	}
}

/*******************  FUNCTION  *********************/
void UnitTest_svUnitTestFake::testMacroAssertThrow_another(void)
{
	try {
		SVUT_ASSERT_THROW(int,throw 10.0);
		SVUT_ASSERT_FAIL("Not throw expected svutExAssertFake exception.");
	} catch (svutExAssertFake &) {
	} catch (...) {
		SVUT_ASSERT_FAIL("Thow unexpected exception.");
	}
}

/*******************  FUNCTION  *********************/
void UnitTest_svUnitTestFake::testMacroAssertThrow_notthrow(void)
{
	try {
		SVUT_ASSERT_THROW(int,{});
		SVUT_ASSERT_FAIL("Not throw expected svutExAssertFake exception.");
	} catch (svutExAssertFake &) {
	} catch (...) {
		SVUT_ASSERT_FAIL("Thow unexpected exception.");
	}
}

/*******************  FUNCTION  *********************/
void UnitTest_svUnitTestFake::testMacroAssertThrowSomething_good(void)
{
	try {
		SVUT_ASSERT_THROW_SOMETHING(throw 10);
	} catch (svutExAssertFake &) {
		SVUT_ASSERT_FAIL("Thow unexpected svutExAssertFake exception.");
	} catch (...) {
		SVUT_ASSERT_FAIL("Thow unexpected exception.");
	}
}

/*******************  FUNCTION  *********************/
void UnitTest_svUnitTestFake::testMacroAssertThrowSomething_bad(void)
{
	int a=10;
	try {
		SVUT_ASSERT_THROW_SOMETHING(a++);
		SVUT_ASSERT_FAIL("Not throw expected svutExAssertFake exception.");
	} catch (svutExAssertFake &) {
	} catch (...) {
		SVUT_ASSERT_FAIL("Thow unexpected exception.");
	}
}

/*******************  FUNCTION  *********************/
void UnitTest_svUnitTestFake::testMacroAssertNotThrow_good(void)
{
	try {
		SVUT_ASSERT_NOT_THROW(int,{});
	} catch (svutExAssertFake &) {
		SVUT_ASSERT_FAIL("Thow unexpected svutExAssertFake exception.");
	} catch (...) {
		SVUT_ASSERT_FAIL("Thow unexpected exception.");
	}
}

/*******************  FUNCTION  *********************/
void UnitTest_svUnitTestFake::testMacroAssertNotThrow_bad(void)
{
	try {
		SVUT_ASSERT_NOT_THROW(int,throw 10);
		SVUT_ASSERT_FAIL("Not throw expected svutExAssertFake exception.");
	} catch (svutExAssertFake &) {
	} catch (...) {
		SVUT_ASSERT_FAIL("Thow unexpected exception.");
	}
}

/*******************  FUNCTION  *********************/
void UnitTest_svUnitTestFake::testMacroAssertNotThrow_others(void)
{
	try {
		SVUT_ASSERT_NOT_THROW(int,throw 1.0);
	} catch (svutExAssertFake &) {
		SVUT_ASSERT_FAIL("Thow unexpected svutExAssertFake exception.");
	} catch (...) {
		SVUT_ASSERT_FAIL("Thow unexpected exception.");
	}
}

/*******************  FUNCTION  *********************/
void UnitTest_svUnitTestFake::testMacroAssertMayNotThrow_good(void)
{
	try {
		SVUT_ASSERT_MAY_NOT_THROW({});
	} catch (svutExAssertFake &) {
		SVUT_ASSERT_FAIL("Thow unexpected svutExAssertFake exception.");
	} catch (...) {
		SVUT_ASSERT_FAIL("Thow unexpected exception.");
	}
}

/*******************  FUNCTION  *********************/
void UnitTest_svUnitTestFake::testMacroAssertMayNotThrow_bad(void)
{
	try {
		SVUT_ASSERT_MAY_NOT_THROW(throw 10);
		SVUT_ASSERT_FAIL("Not throw expected svutExAssertFake exception.");
	} catch (svutExAssertFake &) {
	} catch (...) {
		SVUT_ASSERT_FAIL("Thow unexpected exception.");
	}
}

/*******************  FUNCTION  *********************/
void UnitTest_svUnitTestFake::testMacroAssertGT_int_good(void )
{
	try {
		SVUT_ASSERT_GT(10,20);
	} catch (svutExAssertFake &) {
		SVUT_ASSERT_FAIL("Thow unexpected svutExAssertFake exception.");
	} catch (...) {
		SVUT_ASSERT_FAIL("Thow unexpected exception.");
	}
}

/*******************  FUNCTION  *********************/
void UnitTest_svUnitTestFake::testMacroAssertGT_int_bad(void )
{
	try {
		SVUT_ASSERT_GT(10,2);
		SVUT_ASSERT_FAIL("Not throw expected svutExAssertFake exception.");
	} catch (svutExAssertFake &) {
	} catch (...) {
		SVUT_ASSERT_FAIL("Thow unexpected exception.");
	}
}

/*******************  FUNCTION  *********************/
void UnitTest_svUnitTestFake::testMacroAssertGT_int_limit(void )
{
	try {
		SVUT_ASSERT_GT(10,10);
		SVUT_ASSERT_FAIL("Not throw expected svutExAssertFake exception.");
	} catch (svutExAssertFake &) {
	} catch (...) {
		SVUT_ASSERT_FAIL("Thow unexpected exception.");
	}
}

/*******************  FUNCTION  *********************/
void UnitTest_svUnitTestFake::testMacroAssertGE_int_good(void )
{
	try {
		SVUT_ASSERT_GE(10,20);
	} catch (svutExAssertFake &) {
		SVUT_ASSERT_FAIL("Thow unexpected svutExAssertFake exception.");
	} catch (...) {
		SVUT_ASSERT_FAIL("Thow unexpected exception.");
	}
}

/*******************  FUNCTION  *********************/
void UnitTest_svUnitTestFake::testMacroAssertGE_int_bad(void )
{
	try {
		SVUT_ASSERT_GE(10,2);
		SVUT_ASSERT_FAIL("Not throw expected svutExAssertFake exception.");
	} catch (svutExAssertFake &) {
	} catch (...) {
		SVUT_ASSERT_FAIL("Thow unexpected exception.");
	}
}

/*******************  FUNCTION  *********************/
void UnitTest_svUnitTestFake::testMacroAssertGE_int_limit(void )
{
	try {
		SVUT_ASSERT_GE(10,10);
	} catch (svutExAssertFake &) {
		SVUT_ASSERT_FAIL("Thow unexpected svutExAssertFake exception.");
	} catch (...) {
		SVUT_ASSERT_FAIL("Thow unexpected exception.");
	}
}

/*******************  FUNCTION  *********************/
void UnitTest_svUnitTestFake::testMacroAssertLE_int_good(void )
{
	try {
		SVUT_ASSERT_LE(10,2);
	} catch (svutExAssertFake &) {
		SVUT_ASSERT_FAIL("Thow unexpected svutExAssertFake exception.");
	} catch (...) {
		SVUT_ASSERT_FAIL("Thow unexpected exception.");
	}
}

/*******************  FUNCTION  *********************/
void UnitTest_svUnitTestFake::testMacroAssertLE_int_bad(void )
{
	try {
		SVUT_ASSERT_LE(10,20);
		SVUT_ASSERT_FAIL("Not throw expected svutExAssertFake exception.");
	} catch (svutExAssertFake &) {
	} catch (...) {
		SVUT_ASSERT_FAIL("Thow unexpected exception.");
	}
}

/*******************  FUNCTION  *********************/
void UnitTest_svUnitTestFake::testMacroAssertLE_int_limit(void )
{
	try {
		SVUT_ASSERT_LE(10,10);
	} catch (svutExAssertFake &) {
		SVUT_ASSERT_FAIL("Thow unexpected svutExAssertFake exception.");
	} catch (...) {
		SVUT_ASSERT_FAIL("Thow unexpected exception.");
	}
}

/*******************  FUNCTION  *********************/
void UnitTest_svUnitTestFake::testMacroAssertLT_int_good(void )
{
	try {
		SVUT_ASSERT_LT(10,2);
	} catch (svutExAssertFake &) {
		SVUT_ASSERT_FAIL("Thow unexpected svutExAssertFake exception.");
	} catch (...) {
		SVUT_ASSERT_FAIL("Thow unexpected exception.");
	}
}

/*******************  FUNCTION  *********************/
void UnitTest_svUnitTestFake::testMacroAssertLT_int_bad(void )
{
	try {
		SVUT_ASSERT_LT(10,20);
		SVUT_ASSERT_FAIL("Not throw expected svutExAssertFake exception.");
	} catch (svutExAssertFake &) {
	} catch (...) {
		SVUT_ASSERT_FAIL("Thow unexpected exception.");
	}
}

/*******************  FUNCTION  *********************/
void UnitTest_svUnitTestFake::testMacroAssertLT_int_limit(void )
{
	try {
		SVUT_ASSERT_LT(10,10);
		SVUT_ASSERT_FAIL("Not throw expected svutExAssertFake exception.");
	} catch (svutExAssertFake &) {
	} catch (...) {
		SVUT_ASSERT_FAIL("Thow unexpected exception.");
	}
}

/*******************  FUNCTION  *********************/
void UnitTest_svUnitTestFake::testMacroAssertGE_custotype_good(void )
{
	try {
		UnitTestCustoType v1 = {10,11};
		UnitTestCustoType v2 = {20,21};
		SVUT_ASSERT_GE(v1,v2);
	} catch (svutExAssertFake &) {
		SVUT_ASSERT_FAIL("Thow unexpected svutExAssertFake exception.");
	} catch (...) {
		SVUT_ASSERT_FAIL("Thow unexpected exception.");
	}
}

/*******************  FUNCTION  *********************/
void UnitTest_svUnitTestFake::testMacroAssertGE_custotype_bad(void )
{
	try {
		UnitTestCustoType v1 = {20,21};
		UnitTestCustoType v2 = {10,11};
		SVUT_ASSERT_GE(v1,v2);
		SVUT_ASSERT_FAIL("Not throw expected svutExAssertFake exception.");
	} catch (svutExAssertFake &) {
	} catch (...) {
		SVUT_ASSERT_FAIL("Thow unexpected exception.");
	}
}

/*******************  FUNCTION  *********************/
void UnitTest_svUnitTestFake::testMacroAssertGE_custotype_limit(void )
{
	try {
		UnitTestCustoType v1 = {20,21};
		UnitTestCustoType v2 = {20,21};
		SVUT_ASSERT_GE(v1,v2);
	} catch (svutExAssertFake &) {
		SVUT_ASSERT_FAIL("Thow unexpected svutExAssertFake exception.");
	} catch (...) {
		SVUT_ASSERT_FAIL("Thow unexpected exception.");
	}
}

/*******************  FUNCTION  *********************/
void UnitTest_svUnitTestFake::testMacroAssertGT_custotype_good(void )
{
	try {
		UnitTestCustoType v1 = {10,11};
		UnitTestCustoType v2 = {20,21};
		SVUT_ASSERT_GT(v1,v2);
	} catch (svutExAssertFake &) {
		SVUT_ASSERT_FAIL("Thow unexpected svutExAssertFake exception.");
	} catch (...) {
		SVUT_ASSERT_FAIL("Thow unexpected exception.");
	}
}

/*******************  FUNCTION  *********************/
void UnitTest_svUnitTestFake::testMacroAssertGT_custotype_bad(void )
{
	try {
		UnitTestCustoType v1 = {20,21};
		UnitTestCustoType v2 = {10,11};
		SVUT_ASSERT_GT(v1,v2);
		SVUT_ASSERT_FAIL("Not throw expected svutExAssertFake exception.");
	} catch (svutExAssertFake &) {
	} catch (...) {
		SVUT_ASSERT_FAIL("Thow unexpected exception.");
	}
}

/*******************  FUNCTION  *********************/
void UnitTest_svUnitTestFake::testMacroAssertGT_custotype_limit(void )
{
	try {
		UnitTestCustoType v1 = {20,21};
		UnitTestCustoType v2 = {20,21};
		SVUT_ASSERT_GT(v1,v2);
		SVUT_ASSERT_FAIL("Not throw expected svutExAssertFake exception.");
	} catch (svutExAssertFake &) {
	} catch (...) {
		SVUT_ASSERT_FAIL("Thow unexpected exception.");
	}
}

/*******************  FUNCTION  *********************/
void UnitTest_svUnitTestFake::testMacroAssertLE_custotype_good(void )
{
	try {
		UnitTestCustoType v1 = {20,21};
		UnitTestCustoType v2 = {10,11};
		SVUT_ASSERT_LE(v1,v2);
	} catch (svutExAssertFake &) {
		SVUT_ASSERT_FAIL("Thow unexpected svutExAssertFake exception.");
	} catch (...) {
		SVUT_ASSERT_FAIL("Thow unexpected exception.");
	}
}

/*******************  FUNCTION  *********************/
void UnitTest_svUnitTestFake::testMacroAssertLE_custotype_bad(void )
{
	try {
		UnitTestCustoType v1 = {10,11};
		UnitTestCustoType v2 = {20,21};
		SVUT_ASSERT_LE(v1,v2);
		SVUT_ASSERT_FAIL("Not throw expected svutExAssertFake exception.");
	} catch (svutExAssertFake &) {
	} catch (...) {
		SVUT_ASSERT_FAIL("Thow unexpected exception.");
	}
}

/*******************  FUNCTION  *********************/
void UnitTest_svUnitTestFake::testMacroAssertLE_custotype_limit(void )
{
	try {
		UnitTestCustoType v1 = {20,21};
		UnitTestCustoType v2 = {20,21};
		SVUT_ASSERT_LE(v1,v2);
	} catch (svutExAssertFake &) {
		SVUT_ASSERT_FAIL("Thow unexpected svutExAssertFake exception.");
	} catch (...) {
		SVUT_ASSERT_FAIL("Thow unexpected exception.");
	}
}

/*******************  FUNCTION  *********************/
void UnitTest_svUnitTestFake::testMacroAssertLT_custotype_good(void )
{
	try {
		UnitTestCustoType v1 = {20,21};
		UnitTestCustoType v2 = {10,11};
		SVUT_ASSERT_LE(v1,v2);
	} catch (svutExAssertFake &) {
		SVUT_ASSERT_FAIL("Thow unexpected svutExAssertFake exception.");
	} catch (...) {
		SVUT_ASSERT_FAIL("Thow unexpected exception.");
	}
}

/*******************  FUNCTION  *********************/
void UnitTest_svUnitTestFake::testMacroAssertLT_custotype_bad(void )
{
	try {
		UnitTestCustoType v1 = {10,11};
		UnitTestCustoType v2 = {20,21};
		SVUT_ASSERT_LT(v1,v2);
		SVUT_ASSERT_FAIL("Not throw expected svutExAssertFake exception.");
	} catch (svutExAssertFake &) {
	} catch (...) {
		SVUT_ASSERT_FAIL("Thow unexpected exception.");
	}
}

/*******************  FUNCTION  *********************/
void UnitTest_svUnitTestFake::testMacroAssertLT_custotype_limit(void )
{
	try {
		UnitTestCustoType v1 = {20,21};
		UnitTestCustoType v2 = {20,21};
		SVUT_ASSERT_LT(v1,v2);
		SVUT_ASSERT_FAIL("Not throw expected svutExAssertFake exception.");
	} catch (svutExAssertFake &) {
	} catch (...) {
		SVUT_ASSERT_FAIL("Thow unexpected exception.");
	}
}

/*******************  FUNCTION  *********************/
void UnitTest_svUnitTestFake::testMacroAssertGT_cstr_good(void )
{
	try {
		SVUT_ASSERT_GT((char*)10,(char*)20);
	} catch (svutExAssertFake &) {
		SVUT_ASSERT_FAIL("Thow unexpected svutExAssertFake exception.");
	} catch (...) {
		SVUT_ASSERT_FAIL("Thow unexpected exception.");
	}
}

/*******************  FUNCTION  *********************/
void UnitTest_svUnitTestFake::testMacroAssertGT_cstr_bad(void )
{
	try {
		SVUT_ASSERT_GT((char*)10,(char*)2);
		SVUT_ASSERT_FAIL("Not throw expected svutExAssertFake exception.");
	} catch (svutExAssertFake &) {
	} catch (...) {
		SVUT_ASSERT_FAIL("Thow unexpected exception.");
	}
}

/*******************  FUNCTION  *********************/
void UnitTest_svUnitTestFake::testMacroAssertGT_cstr_limit(void )
{
	try {
		SVUT_ASSERT_GT((char*)10,(char*)10);
		SVUT_ASSERT_FAIL("Not throw expected svutExAssertFake exception.");
	} catch (svutExAssertFake &) {
	} catch (...) {
		SVUT_ASSERT_FAIL("Thow unexpected exception.");
	}
}

/*******************  FUNCTION  *********************/
void UnitTest_svUnitTestFake::testMacroAssertGE_cstr_good(void )
{
	try {
		SVUT_ASSERT_GE((char*)10,(char*)20);
	} catch (svutExAssertFake &) {
		SVUT_ASSERT_FAIL("Thow unexpected svutExAssertFake exception.");
	} catch (...) {
		SVUT_ASSERT_FAIL("Thow unexpected exception.");
	}
}

/*******************  FUNCTION  *********************/
void UnitTest_svUnitTestFake::testMacroAssertGE_cstr_bad(void )
{
	try {
		SVUT_ASSERT_GE((char*)10,(char*)2);
		SVUT_ASSERT_FAIL("Not throw expected svutExAssertFake exception.");
	} catch (svutExAssertFake &) {
	} catch (...) {
		SVUT_ASSERT_FAIL("Thow unexpected exception.");
	}
}

/*******************  FUNCTION  *********************/
void UnitTest_svUnitTestFake::testMacroAssertGE_cstr_limit(void )
{
	try {
		SVUT_ASSERT_GE((char*)10,(char*)10);
	} catch (svutExAssertFake &) {
		SVUT_ASSERT_FAIL("Thow unexpected svutExAssertFake exception.");
	} catch (...) {
		SVUT_ASSERT_FAIL("Thow unexpected exception.");
	}
}

/*******************  FUNCTION  *********************/
void UnitTest_svUnitTestFake::testMacroAssertLE_cstr_good(void )
{
	try {
		SVUT_ASSERT_LE((char*)10,(char*)2);
	} catch (svutExAssertFake &) {
		SVUT_ASSERT_FAIL("Thow unexpected svutExAssertFake exception.");
	} catch (...) {
		SVUT_ASSERT_FAIL("Thow unexpected exception.");
	}
}

/*******************  FUNCTION  *********************/
void UnitTest_svUnitTestFake::testMacroAssertLE_cstr_bad(void )
{
	try {
		SVUT_ASSERT_LE((char*)10,(char*)20);
		SVUT_ASSERT_FAIL("Not throw expected svutExAssertFake exception.");
	} catch (svutExAssertFake &) {
	} catch (...) {
		SVUT_ASSERT_FAIL("Thow unexpected exception.");
	}
}

/*******************  FUNCTION  *********************/
void UnitTest_svUnitTestFake::testMacroAssertLE_cstr_limit(void )
{
	try {
		SVUT_ASSERT_LE((char*)10,(char*)10);
	} catch (svutExAssertFake &) {
		SVUT_ASSERT_FAIL("Thow unexpected svutExAssertFake exception.");
	} catch (...) {
		SVUT_ASSERT_FAIL("Thow unexpected exception.");
	}
}

/*******************  FUNCTION  *********************/
void UnitTest_svUnitTestFake::testMacroAssertLT_cstr_good(void )
{
	try {
		SVUT_ASSERT_LT((char*)10,(char*)2);
	} catch (svutExAssertFake &) {
		SVUT_ASSERT_FAIL("Thow unexpected svutExAssertFake exception.");
	} catch (...) {
		SVUT_ASSERT_FAIL("Thow unexpected exception.");
	}
}

/*******************  FUNCTION  *********************/
void UnitTest_svUnitTestFake::testMacroAssertLT_cstr_bad(void )
{
	try {
		SVUT_ASSERT_LT((char*)10,(char*)20);
		SVUT_ASSERT_FAIL("Not throw expected svutExAssertFake exception.");
	} catch (svutExAssertFake &) {
	} catch (...) {
		SVUT_ASSERT_FAIL("Thow unexpected exception.");
	}
}

/*******************  FUNCTION  *********************/
void UnitTest_svUnitTestFake::testMacroAssertLT_cstr_limit(void )
{
	try {
		SVUT_ASSERT_LT((char*)10,(char*)10);
		SVUT_ASSERT_FAIL("Not throw expected svutExAssertFake exception.");
	} catch (svutExAssertFake &) {
	} catch (...) {
		SVUT_ASSERT_FAIL("Thow unexpected exception.");
	}
}

/*******************  FUNCTION  *********************/
void UnitTest_svUnitTestFake::testMacroAssertZero_good(void )
{
	try {
		SVUT_ASSERT_ZERO(0ul);
	} catch (svutExAssertFake &) {
		SVUT_ASSERT_FAIL("Thow unexpected svutExAssertFailZero exception.");
	} catch (...) {
		SVUT_ASSERT_FAIL("Thow unexpected exception.");
	}
}

/*******************  FUNCTION  *********************/
void UnitTest_svUnitTestFake::testMacroAssertZero_bad(void )
{
	try {
		SVUT_ASSERT_ZERO(10ul);
		SVUT_ASSERT_FAIL("Now Thow expected svutExAssertFailZero exception.");
	} catch (svutExAssertFake &) {
	} catch (...) {
		SVUT_ASSERT_FAIL("Thow unexpected exception.");
	}
}

/*******************  FUNCTION  *********************/
void UnitTest_svUnitTestFake::testMacroAssertZeros_good(void )
{
	float values[100];
	memset(values,0,sizeof(values));
	try {
		SVUT_ASSERT_ZEROS(values,100);
	} catch (svutExAssertFake &) {
		SVUT_ASSERT_FAIL("Thow unexpected svutExAssertFailZeros exception.");
	} catch (...) {
		SVUT_ASSERT_FAIL("Thow unexpected exception.");
	}
}

/*******************  FUNCTION  *********************/
void UnitTest_svUnitTestFake::testMacroAssertZeros_bad_1(void )
{
	float values[100];
	memset(values,0,sizeof(values));
	values[0] = 1.0;
	try {
		SVUT_ASSERT_ZEROS(values,100);
		SVUT_ASSERT_FAIL("Now Thow expected svutExAssertFailZeros exception.");
	} catch (svutExAssertFake &) {
	} catch (...) {
		SVUT_ASSERT_FAIL("Thow unexpected exception.");
	}
}

/*******************  FUNCTION  *********************/
void UnitTest_svUnitTestFake::testMacroAssertZeros_bad_2(void )
{
	float values[100];
	memset(values,0,sizeof(values));
	values[99] = 1.0;
	try {
		SVUT_ASSERT_ZEROS(values,100);
		SVUT_ASSERT_FAIL("Now Thow expected svutExAssertFailZeros exception.");
	} catch (svutExAssertFake &) {
	} catch (...) {
		SVUT_ASSERT_FAIL("Thow unexpected exception.");
	}
}

SVUT_REGISTER_STANDALONE(UnitTest_svUnitTestFake)

#endif
