/*****************************************************
             PROJECT  : svUnitTest
             VERSION  : 0.5.0-dev
             DATE     : 11/2012
             AUTHOR   : Valat Sébastien
             LICENSE  : CeCILL-C
*****************************************************/

/********************  HEADERS  *********************/
#include "UnitTestExtra.h"
#include <svutAssert.h>

/**********************  USING  *********************/
using namespace std;
using namespace svUnitTest;
using namespace CPPUNIT_NS;

/*********************  CLASS  **********************/
class UnitTest_svutAssert : public TestCase
{
	CPPUNIT_TEST_SUITE(UnitTest_svutAssert);
	CPPUNIT_TEST(testMacroAssertTrue_good);
	CPPUNIT_TEST(testMacroAssertTrue_bad);
	CPPUNIT_TEST(testMacroAssertFalse_good);
	CPPUNIT_TEST(testMacroAssertFalse_bad);
	CPPUNIT_TEST(testMacroAssertNull_good);
	CPPUNIT_TEST(testMacroAssertNull_bad);
	CPPUNIT_TEST(testMacroAssertNotNull_good);
	CPPUNIT_TEST(testMacroAssertNotNull_bad);
	CPPUNIT_TEST(testMacroAssertEqual_int_good);
	CPPUNIT_TEST(testMacroAssertEqual_int_bad);
	CPPUNIT_TEST(testMacroAssertEqual_cstr_good);
	CPPUNIT_TEST(testMacroAssertEqual_cstr_bad);
	CPPUNIT_TEST(testMacroAssertEqual_custotype_good);
	CPPUNIT_TEST(testMacroAssertEqual_custotype_bad);
	CPPUNIT_TEST(testMacroAssertNotEqual_int_good);
	CPPUNIT_TEST(testMacroAssertNotEqual_int_bad);
	CPPUNIT_TEST(testMacroAssertNotEqual_cstr_good);
	CPPUNIT_TEST(testMacroAssertNotEqual_cstr_bad);
	CPPUNIT_TEST(testMacroAssertNotEqual_custotype_good);
	CPPUNIT_TEST(testMacroAssertNotEqual_custotype_bad);
	CPPUNIT_TEST(testMacroAssertEqualStrict_int_good);
	CPPUNIT_TEST(testMacroAssertNotEqualStrict_int_good);
	CPPUNIT_TEST(testMacroAssertEqualStrict_cstr_good);
	CPPUNIT_TEST(testMacroAssertNotEqualStrict_cstr_good);
	CPPUNIT_TEST(testMacroAssertSame_good);
	CPPUNIT_TEST(testMacroAssertSame_bad);
	CPPUNIT_TEST(testMacroAssertNotSame_good);
	CPPUNIT_TEST(testMacroAssertNotSame_bad);
	CPPUNIT_TEST(testMacroAssertFailCustom);
	CPPUNIT_TEST(testMacroAssertTodo);
	CPPUNIT_TEST(testMacroAssertIndev);
	CPPUNIT_TEST(testMacroAssertNotExec);
	CPPUNIT_TEST(testMacroAssertThrow_good);
	CPPUNIT_TEST(testMacroAssertThrow_another);
	CPPUNIT_TEST(testMacroAssertThrow_notthrow);
	CPPUNIT_TEST(testMacroAssertThrowSomething_good);
	CPPUNIT_TEST(testMacroAssertThrowSomething_bad);
	CPPUNIT_TEST(testMacroAssertNotThrow_good);
	CPPUNIT_TEST(testMacroAssertNotThrow_bad);
	CPPUNIT_TEST(testMacroAssertNotThrow_others);
	CPPUNIT_TEST(testMacroAssertMayNotThrow_good);
	CPPUNIT_TEST(testMacroAssertMayNotThrow_bad);
	CPPUNIT_TEST(testMacroAssertGT_int_good);
	CPPUNIT_TEST(testMacroAssertGT_int_bad);
	CPPUNIT_TEST(testMacroAssertGT_int_limit);
	CPPUNIT_TEST(testMacroAssertGE_int_good);
	CPPUNIT_TEST(testMacroAssertGE_int_bad);
	CPPUNIT_TEST(testMacroAssertGE_int_limit);
	CPPUNIT_TEST(testMacroAssertLT_int_good);
	CPPUNIT_TEST(testMacroAssertLT_int_bad);
	CPPUNIT_TEST(testMacroAssertLT_int_limit);
	CPPUNIT_TEST(testMacroAssertLE_int_good);
	CPPUNIT_TEST(testMacroAssertLE_int_bad);
	CPPUNIT_TEST(testMacroAssertLE_int_limit);
	CPPUNIT_TEST(testMacroAssertGT_cstr_good);
	CPPUNIT_TEST(testMacroAssertGT_cstr_bad);
	CPPUNIT_TEST(testMacroAssertGT_cstr_limit);
	CPPUNIT_TEST(testMacroAssertGE_cstr_good);
	CPPUNIT_TEST(testMacroAssertGE_cstr_bad);
	CPPUNIT_TEST(testMacroAssertGE_cstr_limit);
	CPPUNIT_TEST(testMacroAssertLT_cstr_good);
	CPPUNIT_TEST(testMacroAssertLT_cstr_bad);
	CPPUNIT_TEST(testMacroAssertLT_cstr_limit);
	CPPUNIT_TEST(testMacroAssertLE_cstr_good);
	CPPUNIT_TEST(testMacroAssertLE_cstr_bad);
	CPPUNIT_TEST(testMacroAssertLE_cstr_limit);
	CPPUNIT_TEST(testMacroAssertGT_custotype_bad);
	CPPUNIT_TEST(testMacroAssertGT_custotype_limit);
	CPPUNIT_TEST(testMacroAssertGE_custotype_good);
	CPPUNIT_TEST(testMacroAssertGE_custotype_bad);
	CPPUNIT_TEST(testMacroAssertGE_custotype_limit);
	CPPUNIT_TEST(testMacroAssertLT_custotype_good);
	CPPUNIT_TEST(testMacroAssertLT_custotype_bad);
	CPPUNIT_TEST(testMacroAssertLT_custotype_limit);
	CPPUNIT_TEST(testMacroAssertLE_custotype_good);
	CPPUNIT_TEST(testMacroAssertLE_custotype_bad);
	CPPUNIT_TEST(testMacroAssertLE_custotype_limit);
	CPPUNIT_TEST(testMacroAssertZero_good);
	CPPUNIT_TEST(testMacroAssertZero_bad);
	CPPUNIT_TEST(testMacroAssertZeros_good);
	CPPUNIT_TEST(testMacroAssertZeros_bad_1);
	CPPUNIT_TEST(testMacroAssertZeros_bad_2);
	CPPUNIT_TEST_SUITE_END();

	public:
		void setUp(void);
		void tearDown(void);

	protected:
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
bool asserterOperatorGE(const UnitTestCustoType & v1,const UnitTestCustoType & v2)
{
	return (v1.value1 >= v2.value1 && v1.value2 >= v2.value2);
}

/*******************  FUNCTION  *********************/
bool asserterOperatorGT(const UnitTestCustoType & v1,const UnitTestCustoType & v2)
{
	return (v1.value1 > v2.value1 && v1.value2 > v2.value2);
}

/*******************  FUNCTION  *********************/
bool asserterOperatorLE(const UnitTestCustoType & v1,const UnitTestCustoType & v2)
{
	return (v1.value1 <= v2.value1 && v1.value2 <= v2.value2);
}

/*******************  FUNCTION  *********************/
bool asserterOperatorLT(const UnitTestCustoType & v1,const UnitTestCustoType & v2)
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
void UnitTest_svutAssert::setUp(void)
{
}

/*******************  FUNCTION  *********************/
void UnitTest_svutAssert::tearDown(void)
{
}

/*******************  FUNCTION  *********************/
void UnitTest_svutAssert::testMacroAssertTrue_good(void )
{
	try {
		SVUT_ASSERT_TRUE(true);
	} catch (svutExAssertFailBool &) {
		CPPUNIT_FAIL("Thow unexpected svutExAssertFailBool exception.");
	} catch (...) {
		CPPUNIT_FAIL("Thow unexpected exception.");
	}
}

/*******************  FUNCTION  *********************/
void UnitTest_svutAssert::testMacroAssertTrue_bad(void )
{
	svutCodeLocation loc(__FILE__,__FUNCTION__,__LINE__ + 2);
	try {
		SVUT_ASSERT_TRUE(false);
		CPPUNIT_FAIL("Now Thow expected svutExAssertFailBool exception.");
	} catch (svutExAssertFailBool & e) {
		CPPUNIT_ASSERT_EQUAL(loc,e.getInfos().getLocation());
		CPPUNIT_ASSERT_EQUAL("TRUE",e.getInfos().getEntry("Expected"));
		CPPUNIT_ASSERT_EQUAL("FALSE",e.getInfos().getEntry("Actual"));
	} catch (...) {
		CPPUNIT_FAIL("Thow unexpected exception.");
	}
}

/*******************  FUNCTION  *********************/
void UnitTest_svutAssert::testMacroAssertFalse_good(void )
{
	try {
		SVUT_ASSERT_FALSE(false);
	} catch (svutExAssertFailBool &) {
		CPPUNIT_FAIL("Thow unexpected svutExAssertFailBool exception.");
	} catch (...) {
		CPPUNIT_FAIL("Thow unexpected exception.");
	}
}

/*******************  FUNCTION  *********************/
void UnitTest_svutAssert::testMacroAssertFalse_bad(void )
{
	svutCodeLocation loc(__FILE__,__FUNCTION__,__LINE__ + 2);
	try {
		SVUT_ASSERT_FALSE(true);
		CPPUNIT_FAIL("Now Thow expected svutExAssertFailBool exception.");
	} catch (svutExAssertFailBool & e) {
		CPPUNIT_ASSERT_EQUAL(loc,e.getInfos().getLocation());
		CPPUNIT_ASSERT_EQUAL("FALSE",e.getInfos().getEntry("Expected"));
		CPPUNIT_ASSERT_EQUAL("TRUE",e.getInfos().getEntry("Actual"));
	} catch (...) {
		CPPUNIT_FAIL("Thow unexpected exception.");
	}
}

/*******************  FUNCTION  *********************/
void UnitTest_svutAssert::testMacroAssertNull_good(void )
{
	try {
		SVUT_ASSERT_NULL(NULL);
	} catch (svutExAssertFailNullPointer &) {
		CPPUNIT_FAIL("Thow unexpected svutExAssertFailNullPointer exception.");
	} catch (...) {
		CPPUNIT_FAIL("Thow unexpected exception.");
	}
}

/*******************  FUNCTION  *********************/
void UnitTest_svutAssert::testMacroAssertNull_bad(void )
{
	svutCodeLocation loc(__FILE__,__FUNCTION__,__LINE__ + 2);
	try {
		SVUT_ASSERT_NULL(0x55);
		CPPUNIT_FAIL("Now Thow expected svutExAssertFailNullPointer exception.");
	} catch (svutExAssertFailNullPointer & e) {
		CPPUNIT_ASSERT_EQUAL(loc,e.getInfos().getLocation());
		CPPUNIT_ASSERT_EQUAL("NULL",e.getInfos().getEntry("Expected"));
		CPPUNIT_ASSERT_EQUAL("NOT NULL",e.getInfos().getEntry("Actual"));
	} catch (...) {
		CPPUNIT_FAIL("Thow unexpected exception.");
	}
}

/*******************  FUNCTION  *********************/
void UnitTest_svutAssert::testMacroAssertNotNull_good(void )
{
	try {
		SVUT_ASSERT_NOT_NULL(0x55);
	} catch (svutExAssertFailNullPointer &) {
		CPPUNIT_FAIL("Thow unexpected svutExAssertFailNullPointer exception.");
	} catch (...) {
		CPPUNIT_FAIL("Thow unexpected exception.");
	}
}

/*******************  FUNCTION  *********************/
void UnitTest_svutAssert::testMacroAssertNotNull_bad(void )
{
	svutCodeLocation loc(__FILE__,__FUNCTION__,__LINE__ + 2);
	try {
		SVUT_ASSERT_NOT_NULL(NULL);
		CPPUNIT_FAIL("Now Thow expected svutExAssertFailNullPointer exception.");
	} catch (svutExAssertFailNullPointer & e) {
		CPPUNIT_ASSERT_EQUAL(loc,e.getInfos().getLocation());
		CPPUNIT_ASSERT_EQUAL("NOT NULL",e.getInfos().getEntry("Expected"));
		CPPUNIT_ASSERT_EQUAL("NULL",e.getInfos().getEntry("Actual"));
	} catch (...) {
		CPPUNIT_FAIL("Thow unexpected exception.");
	}
}

/*******************  FUNCTION  *********************/
void UnitTest_svutAssert::testMacroAssertEqual_int_good(void)
{
	try {
		SVUT_ASSERT_EQUAL(10,10);
	} catch (svutExAssertFailEqual &) {
		CPPUNIT_FAIL("Thow unexpected svutExAssertFailEqual exception.");
	} catch (...) {
		CPPUNIT_FAIL("Thow unexpected exception.");
	}
}

/*******************  FUNCTION  *********************/
void UnitTest_svutAssert::testMacroAssertEqual_int_bad(void)
{
	svutCodeLocation loc(__FILE__,__FUNCTION__,__LINE__ + 2);
	try {
		SVUT_ASSERT_EQUAL(10,42);
		CPPUNIT_FAIL("Now Thow expected svutExAssertFailEqual exception.");
	} catch (svutExAssertFailEqual & e) {
		CPPUNIT_ASSERT_EQUAL(loc,e.getInfos().getLocation());
		CPPUNIT_ASSERT_EQUAL("10",e.getInfos().getEntry("Expected"));
		CPPUNIT_ASSERT_EQUAL("42",e.getInfos().getEntry("Actual"));
	} catch (...) {
		CPPUNIT_FAIL("Thow unexpected exception.");
	}
}

/*******************  FUNCTION  *********************/
void UnitTest_svutAssert::testMacroAssertEqual_cstr_good(void)
{
	try {
		SVUT_ASSERT_EQUAL("Hello World !!","Hello World !!");
	} catch (svutExAssertFailEqual &) {
		CPPUNIT_FAIL("Thow unexpected svutExAssertFailEqual exception.");
	} catch (...) {
		CPPUNIT_FAIL("Thow unexpected exception.");
	}
}

/*******************  FUNCTION  *********************/
void UnitTest_svutAssert::testMacroAssertEqual_cstr_bad(void)
{
	svutCodeLocation loc(__FILE__,__FUNCTION__,__LINE__ + 2);
	try {
		SVUT_ASSERT_EQUAL("Hello World!!","Hello Bob!!");
		CPPUNIT_FAIL("Now Thow expected svutExAssertFailEqual exception.");
	} catch (svutExAssertFailEqual & e) {
		CPPUNIT_ASSERT_EQUAL(loc,e.getInfos().getLocation());
		CPPUNIT_ASSERT_EQUAL("Hello World!!",e.getInfos().getEntry("Expected"));
		CPPUNIT_ASSERT_EQUAL("Hello Bob!!",e.getInfos().getEntry("Actual"));
	} catch (...) {
		CPPUNIT_FAIL("Thow unexpected exception.");
	}
}

/*******************  FUNCTION  *********************/
void UnitTest_svutAssert::testMacroAssertEqual_custotype_good(void)
{
	try {
		UnitTestCustoType v1 = {10,20};
		UnitTestCustoType v2 = {10,20};
		SVUT_ASSERT_EQUAL(v1,v2);
	} catch (svutExAssertFailEqual &) {
		CPPUNIT_FAIL("Thow unexpected svutExAssertFailEqual exception.");
	} catch (...) {
		CPPUNIT_FAIL("Thow unexpected exception.");
	}
}

/*******************  FUNCTION  *********************/
void UnitTest_svutAssert::testMacroAssertEqual_custotype_bad(void)
{
	svutCodeLocation loc(__FILE__,__FUNCTION__,__LINE__ + 4);
	try {
		UnitTestCustoType v1 = {10,20};
		UnitTestCustoType v2 = {10,40};
		SVUT_ASSERT_EQUAL(v1,v2);
		CPPUNIT_FAIL("Now Thow expected svutExAssertFailEqual exception.");
	} catch (svutExAssertFailEqual & e) {
		CPPUNIT_ASSERT_EQUAL(loc,e.getInfos().getLocation());
		CPPUNIT_ASSERT_EQUAL("10, 20",e.getInfos().getEntry("Expected"));
		CPPUNIT_ASSERT_EQUAL("10, 40",e.getInfos().getEntry("Actual"));
	} catch (...) {
		CPPUNIT_FAIL("Thow unexpected exception.");
	}
}

/*******************  FUNCTION  *********************/
void UnitTest_svutAssert::testMacroAssertNotEqual_int_good(void)
{
	try {
		SVUT_ASSERT_NOT_EQUAL(10,20);
	} catch (svutExAssertFailEqual &) {
		CPPUNIT_FAIL("Thow unexpected svutExAssertFailEqual exception.");
	} catch (...) {
		CPPUNIT_FAIL("Thow unexpected exception.");
	}
}

/*******************  FUNCTION  *********************/
void UnitTest_svutAssert::testMacroAssertNotEqual_int_bad(void)
{
	svutCodeLocation loc(__FILE__,__FUNCTION__,__LINE__ + 2);
	try {
		SVUT_ASSERT_NOT_EQUAL(10,10);
		CPPUNIT_FAIL("Now Thow expected svutExAssertFailEqual exception.");
	} catch (svutExAssertFailEqual & e) {
		CPPUNIT_ASSERT_EQUAL(loc,e.getInfos().getLocation());
		CPPUNIT_ASSERT_EQUAL("10",e.getInfos().getEntry("Not expected"));
		CPPUNIT_ASSERT_EQUAL("10",e.getInfos().getEntry("Actual"));
	} catch (...) {
		CPPUNIT_FAIL("Thow unexpected exception.");
	}
}

/*******************  FUNCTION  *********************/
void UnitTest_svutAssert::testMacroAssertNotEqual_cstr_good(void)
{
	try {
		SVUT_ASSERT_NOT_EQUAL("Hello World !!","Hello Bob !!");
	} catch (svutExAssertFailEqual &) {
		CPPUNIT_FAIL("Thow unexpected svutExAssertFailEqual exception.");
	} catch (...) {
		CPPUNIT_FAIL("Thow unexpected exception.");
	}
}

/*******************  FUNCTION  *********************/
void UnitTest_svutAssert::testMacroAssertNotEqual_cstr_bad(void)
{
	svutCodeLocation loc(__FILE__,__FUNCTION__,__LINE__ + 2);
	try {
		SVUT_ASSERT_NOT_EQUAL("Hello World!!","Hello World!!");
		CPPUNIT_FAIL("Now Thow expected svutExAssertFailEqual exception.");
	} catch (svutExAssertFailEqual & e) {
		CPPUNIT_ASSERT_EQUAL(loc,e.getInfos().getLocation());
		CPPUNIT_ASSERT_EQUAL("Hello World!!",e.getInfos().getEntry("Not expected"));
		CPPUNIT_ASSERT_EQUAL("Hello World!!",e.getInfos().getEntry("Actual"));
	} catch (...) {
		CPPUNIT_FAIL("Thow unexpected exception.");
	}
}

/*******************  FUNCTION  *********************/
void UnitTest_svutAssert::testMacroAssertNotEqual_custotype_good(void)
{
	try {
		UnitTestCustoType v1 = {10,20};
		UnitTestCustoType v2 = {10,30};
		SVUT_ASSERT_NOT_EQUAL(v1,v2);
	} catch (svutExAssertFailEqual &) {
		CPPUNIT_FAIL("Thow unexpected svutExAssertFailEqual exception.");
	} catch (...) {
		CPPUNIT_FAIL("Thow unexpected exception.");
	}
}

/*******************  FUNCTION  *********************/
void UnitTest_svutAssert::testMacroAssertNotEqual_custotype_bad(void)
{
	svutCodeLocation loc(__FILE__,__FUNCTION__,__LINE__ + 4);
	try {
		UnitTestCustoType v1 = {10,20};
		UnitTestCustoType v2 = {10,20};
		SVUT_ASSERT_NOT_EQUAL(v1,v2);
		CPPUNIT_FAIL("Now Thow expected svutExAssertFailEqual exception.");
	} catch (svutExAssertFailEqual & e) {
		CPPUNIT_ASSERT_EQUAL(loc,e.getInfos().getLocation());
		CPPUNIT_ASSERT_EQUAL("10, 20",e.getInfos().getEntry("Not expected"));
		CPPUNIT_ASSERT_EQUAL("10, 20",e.getInfos().getEntry("Actual"));
	} catch (...) {
		CPPUNIT_FAIL("Thow unexpected exception.");
	}
}

/*******************  FUNCTION  *********************/
void UnitTest_svutAssert::testMacroAssertEqualStrict_int_good(void)
{
	try {
		SVUT_ASSERT_EQUAL_STRICT(10,10);
	} catch (svutExAssertFailEqual &) {
		CPPUNIT_FAIL("Thow unexpected svutExAssertFailEqual exception.");
	} catch (...) {
		CPPUNIT_FAIL("Thow unexpected exception.");
	}
}

/*******************  FUNCTION  *********************/
void UnitTest_svutAssert::testMacroAssertNotEqualStrict_int_good(void)
{
	try {
		SVUT_ASSERT_NOT_EQUAL_STRICT(10,20);
	} catch (svutExAssertFailEqual &) {
		CPPUNIT_FAIL("Thow unexpected svutExAssertFailEqual exception.");
	} catch (...) {
		CPPUNIT_FAIL("Thow unexpected exception.");
	}
}

/*******************  FUNCTION  *********************/
void UnitTest_svutAssert::testMacroAssertEqualStrict_cstr_good(void)
{
	try {
		SVUT_ASSERT_EQUAL_STRICT("Hello World !!","Hello World !!");
	} catch (svutExAssertFailEqual &) {
		CPPUNIT_FAIL("Thow unexpected svutExAssertFailEqual exception.");
	} catch (...) {
		CPPUNIT_FAIL("Thow unexpected exception.");
	}
}

/*******************  FUNCTION  *********************/
void UnitTest_svutAssert::testMacroAssertNotEqualStrict_cstr_good(void)
{
	try {
		SVUT_ASSERT_NOT_EQUAL_STRICT("Hello World !!","Hello Bob !!");
	} catch (svutExAssertFailEqual &) {
		CPPUNIT_FAIL("Thow unexpected svutExAssertFailEqual exception.");
	} catch (...) {
		CPPUNIT_FAIL("Thow unexpected exception.");
	}
}

/*******************  FUNCTION  *********************/
void UnitTest_svutAssert::testMacroAssertZero_good(void )
{
	try {
		SVUT_ASSERT_ZERO(0ul);
	} catch (svutExAssertFailZero &) {
		CPPUNIT_FAIL("Thow unexpected svutExAssertFailZero exception.");
	} catch (...) {
		CPPUNIT_FAIL("Thow unexpected exception.");
	}
}

/*******************  FUNCTION  *********************/
void UnitTest_svutAssert::testMacroAssertZero_bad(void )
{
	svutCodeLocation loc(__FILE__,__FUNCTION__,__LINE__ + 2);
	try {
		SVUT_ASSERT_ZERO(10ul);
		CPPUNIT_FAIL("Now Thow expected svutExAssertFailZero exception.");
	} catch (svutExAssertFailZero & e) {
		CPPUNIT_ASSERT_EQUAL(loc,e.getInfos().getLocation());
		CPPUNIT_ASSERT_EQUAL(asserterToString("10"),e.getInfos().getEntry("Value"));
	} catch (...) {
		CPPUNIT_FAIL("Thow unexpected exception.");
	}
}

/*******************  FUNCTION  *********************/
void UnitTest_svutAssert::testMacroAssertZeros_good(void )
{
	float values[100];
	memset(values,0,sizeof(values));
	try {
		SVUT_ASSERT_ZEROS(values,100);
	} catch (svutExAssertFailZeros &) {
		CPPUNIT_FAIL("Thow unexpected svutExAssertFailZeros exception.");
	} catch (...) {
		CPPUNIT_FAIL("Thow unexpected exception.");
	}
}

/*******************  FUNCTION  *********************/
void UnitTest_svutAssert::testMacroAssertZeros_bad_1(void )
{
	float values[100];
	memset(values,0,sizeof(values));
	values[0] = 1.0;
	svutCodeLocation loc(__FILE__,__FUNCTION__,__LINE__ + 2);
	try {
		SVUT_ASSERT_ZEROS(values,100);
		CPPUNIT_FAIL("Now Thow expected svutExAssertFailZeros exception.");
	} catch (svutExAssertFailZeros & e) {
		CPPUNIT_ASSERT_EQUAL(loc,e.getInfos().getLocation());
	} catch (...) {
		CPPUNIT_FAIL("Thow unexpected exception.");
	}
}

/*******************  FUNCTION  *********************/
void UnitTest_svutAssert::testMacroAssertZeros_bad_2(void )
{
	float values[100];
	memset(values,0,sizeof(values));
	values[99] = 1.0;
	svutCodeLocation loc(__FILE__,__FUNCTION__,__LINE__ + 2);
	try {
		SVUT_ASSERT_ZEROS(values,100);
		CPPUNIT_FAIL("Now Thow expected svutExAssertFailZeros exception.");
	} catch (svutExAssertFailZeros & e) {
		CPPUNIT_ASSERT_EQUAL(loc,e.getInfos().getLocation());
	} catch (...) {
		CPPUNIT_FAIL("Thow unexpected exception.");
	}
}

/*******************  FUNCTION  *********************/
void UnitTest_svutAssert::testMacroAssertSame_good(void)
{
	try {
		int a = 66;
		SVUT_ASSERT_SAME(&a,&a);
	} catch (svutExAssertFailEqual &) {
		CPPUNIT_FAIL("Thow unexpected svutExAssertFailEqual exception.");
	} catch (...) {
		CPPUNIT_FAIL("Thow unexpected exception.");
	}
}

/*******************  FUNCTION  *********************/
void UnitTest_svutAssert::testMacroAssertSame_bad(void)
{
	svutCodeLocation loc(__FILE__,__FUNCTION__,__LINE__ + 4);
	int a = 66;
	int b = 66;
	try {
		SVUT_ASSERT_SAME(&a,&b);
		CPPUNIT_FAIL("Now Thow expected svutExAssertFailEqual exception.");
	} catch (svutExAssertFailEqual & e) {
		CPPUNIT_ASSERT_EQUAL(loc,e.getInfos().getLocation());
		CPPUNIT_ASSERT_EQUAL(asserterToString(&a),e.getInfos().getEntry("Expected"));
		CPPUNIT_ASSERT_EQUAL(asserterToString(&b),e.getInfos().getEntry("Actual"));
	} catch (...) {
		CPPUNIT_FAIL("Thow unexpected exception.");
	}
}

/*******************  FUNCTION  *********************/
void UnitTest_svutAssert::testMacroAssertNotSame_good(void)
{
	try {
		int a = 66;
		int b = 66;
		SVUT_ASSERT_NOT_SAME(&a,&b);
	} catch (svutExAssertFailEqual &) {
		CPPUNIT_FAIL("Thow unexpected svutExAssertFailEqual exception.");
	} catch (...) {
		CPPUNIT_FAIL("Thow unexpected exception.");
	}
}

/*******************  FUNCTION  *********************/
void UnitTest_svutAssert::testMacroAssertNotSame_bad(void)
{
	svutCodeLocation loc(__FILE__,__FUNCTION__,__LINE__ + 3);
	int a = 66;
	try {
		SVUT_ASSERT_NOT_SAME(&a,&a);
		CPPUNIT_FAIL("Now Thow expected svutExAssertFailEqual exception.");
	} catch (svutExAssertFailEqual & e) {
		CPPUNIT_ASSERT_EQUAL(loc,e.getInfos().getLocation());
		CPPUNIT_ASSERT_EQUAL(asserterToString(&a),e.getInfos().getEntry("Not expected"));
		CPPUNIT_ASSERT_EQUAL(asserterToString(&a),e.getInfos().getEntry("Actual"));
	} catch (...) {
		CPPUNIT_FAIL("Thow unexpected exception.");
	}
}

/*******************  FUNCTION  *********************/
void UnitTest_svutAssert::testMacroAssertFailCustom(void )
{
	svutCodeLocation loc(__FILE__,__FUNCTION__,__LINE__ + 2);
	try {
		SVUT_ASSERT_FAIL("test fail");
		CPPUNIT_FAIL("Now Thow expected svutExAssertFailCustom exception.");
	} catch (svutExAssertFailCustom & e) {
		CPPUNIT_ASSERT_EQUAL(loc,e.getInfos().getLocation());
		CPPUNIT_ASSERT_EQUAL("test fail",e.getMessage());
	} catch (...) {
		CPPUNIT_FAIL("Thow unexpected exception.");
	}
}

/*******************  FUNCTION  *********************/
void UnitTest_svutAssert::testMacroAssertTodo(void )
{
	svutCodeLocation loc(__FILE__,__FUNCTION__,__LINE__ + 2);
	try {
		SVUT_ASSERT_TODO("test todo");
		CPPUNIT_FAIL("Now Thow expected svutExNotifyTodo exception.");
	} catch (svutExNotifyTodo & e) {
		CPPUNIT_ASSERT_EQUAL(loc,e.getInfos().getLocation());
		CPPUNIT_ASSERT_EQUAL("test todo",e.getMessage());
	} catch (...) {
		CPPUNIT_FAIL("Thow unexpected exception.");
	}
}

/*******************  FUNCTION  *********************/
void UnitTest_svutAssert::testMacroAssertIndev(void )
{
	svutCodeLocation loc(__FILE__,__FUNCTION__,__LINE__ + 2);
	try {
		SVUT_ASSERT_INDEV("test indev");
		CPPUNIT_FAIL("Now Thow expected svutExNotifyIndev exception.");
	} catch (svutExNotifyIndev & e) {
		CPPUNIT_ASSERT_EQUAL(loc,e.getInfos().getLocation());
		CPPUNIT_ASSERT_EQUAL("test indev",e.getMessage());
	} catch (...) {
		CPPUNIT_FAIL("Thow unexpected exception.");
	}
}

/*******************  FUNCTION  *********************/
void UnitTest_svutAssert::testMacroAssertNotExec(void )
{
	svutCodeLocation loc(__FILE__,__FUNCTION__,__LINE__ + 2);
	try {
		SVUT_ASSERT_NOT_EXEC_THIS();
		CPPUNIT_FAIL("Now Thow expected svutExAssertFailNotExec exception.");
	} catch (svutExAssertFailNotExec & e) {
		CPPUNIT_ASSERT_EQUAL(loc,e.getInfos().getLocation());
	} catch (...) {
		CPPUNIT_FAIL("Thow unexpected exception.");
	}
}

/*******************  FUNCTION  *********************/
void UnitTest_svutAssert::testMacroAssertThrow_good(void)
{
	try {
		SVUT_ASSERT_THROW(int,throw 10);
	} catch (svutExAssertFailThrow &) {
		CPPUNIT_FAIL("Thow unexpected svutExAssertFailThrow exception.");
	} catch (...) {
		CPPUNIT_FAIL("Thow unexpected exception.");
	}
}

/*******************  FUNCTION  *********************/
void UnitTest_svutAssert::testMacroAssertThrow_another(void)
{
	svutCodeLocation loc(__FILE__,__FUNCTION__,__LINE__ + 2);
	try {
		SVUT_ASSERT_THROW(int,throw 10.0);
		CPPUNIT_FAIL("Now Thow expected svutExAssertFailThrow exception.");
	} catch (svutExAssertFailThrow & e) {
		CPPUNIT_ASSERT_EQUAL(loc,e.getInfos().getLocation());
		CPPUNIT_ASSERT_EQUAL("int",e.getInfos().getEntry("Expected"));
		CPPUNIT_ASSERT_EQUAL("UNKNOWN",e.getInfos().getEntry("Actual"));
	} catch (...) {
		CPPUNIT_FAIL("Thow unexpected exception.");
	}
}

/*******************  FUNCTION  *********************/
void UnitTest_svutAssert::testMacroAssertThrow_notthrow(void)
{
	svutCodeLocation loc(__FILE__,__FUNCTION__,__LINE__ + 2);
	try {
		SVUT_ASSERT_THROW(int,{});
		CPPUNIT_FAIL("Now Thow expected svutExAssertFailThrow exception.");
	} catch (svutExAssertFailThrow & e) {
		CPPUNIT_ASSERT_EQUAL(loc,e.getInfos().getLocation());
		CPPUNIT_ASSERT_EQUAL("int",e.getInfos().getEntry("Expected"));
		CPPUNIT_ASSERT_EQUAL("NONE",e.getInfos().getEntry("Actual"));
	} catch (...) {
		CPPUNIT_FAIL("Thow unexpected exception.");
	}
}

/*******************  FUNCTION  *********************/
void UnitTest_svutAssert::testMacroAssertThrowSomething_good(void)
{
	try {
		SVUT_ASSERT_THROW_SOMETHING(throw 10);
	} catch (svutExAssertFailThrow &) {
		CPPUNIT_FAIL("Thow unexpected svutExAssertFailThrow exception.");
	} catch (...) {
		CPPUNIT_FAIL("Thow unexpected exception.");
	}
}

/*******************  FUNCTION  *********************/
void UnitTest_svutAssert::testMacroAssertThrowSomething_bad(void)
{
	int a=10;
	svutCodeLocation loc(__FILE__,__FUNCTION__,__LINE__ + 2);
	try {
		SVUT_ASSERT_THROW_SOMETHING(a++);
		CPPUNIT_FAIL("Now Thow expected svutExAssertFailThrow exception.");
	} catch (svutExAssertFailThrow & e) {
		CPPUNIT_ASSERT_EQUAL(loc,e.getInfos().getLocation());
		CPPUNIT_ASSERT_EQUAL("...",e.getInfos().getEntry("Expected"));
		CPPUNIT_ASSERT_EQUAL("NONE",e.getInfos().getEntry("Actual"));
	} catch (...) {
		CPPUNIT_FAIL("Thow unexpected exception.");
	}
}

/*******************  FUNCTION  *********************/
void UnitTest_svutAssert::testMacroAssertNotThrow_good(void)
{
	try {
		SVUT_ASSERT_NOT_THROW(int,{});
	} catch (svutExAssertFailThrow &) {
		CPPUNIT_FAIL("Thow unexpected svutExAssertFailThrow exception.");
	} catch (...) {
		CPPUNIT_FAIL("Thow unexpected exception.");
	}
}

/*******************  FUNCTION  *********************/
void UnitTest_svutAssert::testMacroAssertNotThrow_bad(void)
{
	svutCodeLocation loc(__FILE__,__FUNCTION__,__LINE__ + 2);
	try {
		SVUT_ASSERT_NOT_THROW(int,throw 10);
		CPPUNIT_FAIL("Now Thow expected svutExAssertFailThrow exception.");
	} catch (svutExAssertFailThrow & e) {
		CPPUNIT_ASSERT_EQUAL(loc,e.getInfos().getLocation());
		CPPUNIT_ASSERT_EQUAL("NONE",e.getInfos().getEntry("Expected"));
		CPPUNIT_ASSERT_EQUAL("int",e.getInfos().getEntry("Actual"));
	} catch (...) {
		CPPUNIT_FAIL("Thow unexpected exception.");
	}
}

/*******************  FUNCTION  *********************/
void UnitTest_svutAssert::testMacroAssertNotThrow_others(void)
{
	try {
		SVUT_ASSERT_NOT_THROW(int,throw 1.0);
	} catch (svutExAssertFailThrow &) {
		CPPUNIT_FAIL("Thow unexpected svutExAssertFailThrow exception.");
	} catch (...) {
		CPPUNIT_FAIL("Thow unexpected exception.");
	}
}

/*******************  FUNCTION  *********************/
void UnitTest_svutAssert::testMacroAssertMayNotThrow_good(void)
{
	try {
		SVUT_ASSERT_MAY_NOT_THROW({});
	} catch (svutExAssertFailThrow &) {
		CPPUNIT_FAIL("Thow unexpected svutExAssertFailThrow exception.");
	} catch (...) {
		CPPUNIT_FAIL("Thow unexpected exception.");
	}
}

/*******************  FUNCTION  *********************/
void UnitTest_svutAssert::testMacroAssertMayNotThrow_bad(void)
{
	svutCodeLocation loc(__FILE__,__FUNCTION__,__LINE__ + 2);
	try {
		SVUT_ASSERT_MAY_NOT_THROW(throw 10);
		CPPUNIT_FAIL("Now Thow expected svutExAssertFailThrow exception.");
	} catch (svutExAssertFailThrow & e) {
		CPPUNIT_ASSERT_EQUAL(loc,e.getInfos().getLocation());
		CPPUNIT_ASSERT_EQUAL("NONE",e.getInfos().getEntry("Expected"));
		CPPUNIT_ASSERT_EQUAL("...",e.getInfos().getEntry("Actual"));
	} catch (...) {
		CPPUNIT_FAIL("Thow unexpected exception.");
	}
}

/*******************  FUNCTION  *********************/
void UnitTest_svutAssert::testMacroAssertGT_int_good(void )
{
	try {
		SVUT_ASSERT_GT(10,20);
	} catch (svutExAssertFailLimit &) {
		CPPUNIT_FAIL("Thow unexpected svutExAssertFailLimit exception.");
	} catch (...) {
		CPPUNIT_FAIL("Thow unexpected exception.");
	}
}

/*******************  FUNCTION  *********************/
void UnitTest_svutAssert::testMacroAssertGT_int_bad(void )
{
	svutCodeLocation loc(__FILE__,__FUNCTION__,__LINE__ + 2);
	try {
		SVUT_ASSERT_GT(10,2);
		CPPUNIT_FAIL("Now Thow expected svutExAssertFailLimit exception.");
	} catch (svutExAssertFailLimit & e) {
		CPPUNIT_ASSERT_EQUAL(loc,e.getInfos().getLocation());
		CPPUNIT_ASSERT_EQUAL("10",e.getInfos().getEntry("Expected limit"));
		CPPUNIT_ASSERT_EQUAL("2",e.getInfos().getEntry("Actual"));
		CPPUNIT_ASSERT_EQUAL("Greater than",e.getInfos().getEntry("Operator"));
	} catch (...) {
		CPPUNIT_FAIL("Thow unexpected exception.");
	}
}

/*******************  FUNCTION  *********************/
void UnitTest_svutAssert::testMacroAssertGT_int_limit(void )
{
	svutCodeLocation loc(__FILE__,__FUNCTION__,__LINE__ + 2);
	try {
		SVUT_ASSERT_GT(10,10);
		CPPUNIT_FAIL("Now Thow expected svutExAssertFailLimit exception.");
	} catch (svutExAssertFailLimit & e) {
		CPPUNIT_ASSERT_EQUAL(loc,e.getInfos().getLocation());
		CPPUNIT_ASSERT_EQUAL("10",e.getInfos().getEntry("Expected limit"));
		CPPUNIT_ASSERT_EQUAL("10",e.getInfos().getEntry("Actual"));
		CPPUNIT_ASSERT_EQUAL("Greater than",e.getInfos().getEntry("Operator"));
	} catch (...) {
		CPPUNIT_FAIL("Thow unexpected exception.");
	}
}

/*******************  FUNCTION  *********************/
void UnitTest_svutAssert::testMacroAssertGE_int_good(void )
{
	try {
		SVUT_ASSERT_GE(10,20);
	} catch (svutExAssertFailLimit &) {
		CPPUNIT_FAIL("Thow unexpected svutExAssertFailLimit exception.");
	} catch (...) {
		CPPUNIT_FAIL("Thow unexpected exception.");
	}
}

/*******************  FUNCTION  *********************/
void UnitTest_svutAssert::testMacroAssertGE_int_bad(void )
{
	svutCodeLocation loc(__FILE__,__FUNCTION__,__LINE__ + 2);
	try {
		SVUT_ASSERT_GE(10,2);
		CPPUNIT_FAIL("Now Thow expected svutExAssertFailLimit exception.");
	} catch (svutExAssertFailLimit & e) {
		CPPUNIT_ASSERT_EQUAL(loc,e.getInfos().getLocation());
		CPPUNIT_ASSERT_EQUAL("10",e.getInfos().getEntry("Expected limit"));
		CPPUNIT_ASSERT_EQUAL("2",e.getInfos().getEntry("Actual"));
		CPPUNIT_ASSERT_EQUAL("Greater or equal",e.getInfos().getEntry("Operator"));
	} catch (...) {
		CPPUNIT_FAIL("Thow unexpected exception.");
	}
}

/*******************  FUNCTION  *********************/
void UnitTest_svutAssert::testMacroAssertGE_int_limit(void )
{
	try {
		SVUT_ASSERT_GE(10,10);
	} catch (svutExAssertFailLimit &) {
		CPPUNIT_FAIL("Thow unexpected svutExAssertFailLimit exception.");
	} catch (...) {
		CPPUNIT_FAIL("Thow unexpected exception.");
	}
}

/*******************  FUNCTION  *********************/
void UnitTest_svutAssert::testMacroAssertLE_int_good(void )
{
	try {
		SVUT_ASSERT_LE(10,2);
	} catch (svutExAssertFailLimit &) {
		CPPUNIT_FAIL("Thow unexpected svutExAssertFailLimit exception.");
	} catch (...) {
		CPPUNIT_FAIL("Thow unexpected exception.");
	}
}

/*******************  FUNCTION  *********************/
void UnitTest_svutAssert::testMacroAssertLE_int_bad(void )
{
	svutCodeLocation loc(__FILE__,__FUNCTION__,__LINE__ + 2);
	try {
		SVUT_ASSERT_LE(10,20);
		CPPUNIT_FAIL("Now Thow expected svutExAssertFailLimit exception.");
	} catch (svutExAssertFailLimit & e) {
		CPPUNIT_ASSERT_EQUAL(loc,e.getInfos().getLocation());
		CPPUNIT_ASSERT_EQUAL("10",e.getInfos().getEntry("Expected limit"));
		CPPUNIT_ASSERT_EQUAL("20",e.getInfos().getEntry("Actual"));
		CPPUNIT_ASSERT_EQUAL("Less or equal",e.getInfos().getEntry("Operator"));
	} catch (...) {
		CPPUNIT_FAIL("Thow unexpected exception.");
	}
}

/*******************  FUNCTION  *********************/
void UnitTest_svutAssert::testMacroAssertLE_int_limit(void )
{
	try {
		SVUT_ASSERT_LE(10,10);
	} catch (svutExAssertFailLimit &) {
		CPPUNIT_FAIL("Thow unexpected svutExAssertFailLimit exception.");
	} catch (...) {
		CPPUNIT_FAIL("Thow unexpected exception.");
	}
}

/*******************  FUNCTION  *********************/
void UnitTest_svutAssert::testMacroAssertLT_int_good(void )
{
	try {
		SVUT_ASSERT_LT(10,2);
	} catch (svutExAssertFailLimit &) {
		CPPUNIT_FAIL("Thow unexpected svutExAssertFailLimit exception.");
	} catch (...) {
		CPPUNIT_FAIL("Thow unexpected exception.");
	}
}

/*******************  FUNCTION  *********************/
void UnitTest_svutAssert::testMacroAssertLT_int_bad(void )
{
	svutCodeLocation loc(__FILE__,__FUNCTION__,__LINE__ + 2);
	try {
		SVUT_ASSERT_LT(10,20);
		CPPUNIT_FAIL("Now Thow expected svutExAssertFailLimit exception.");
	} catch (svutExAssertFailLimit & e) {
		CPPUNIT_ASSERT_EQUAL(loc,e.getInfos().getLocation());
		CPPUNIT_ASSERT_EQUAL("10",e.getInfos().getEntry("Expected limit"));
		CPPUNIT_ASSERT_EQUAL("20",e.getInfos().getEntry("Actual"));
		CPPUNIT_ASSERT_EQUAL("Less than",e.getInfos().getEntry("Operator"));
	} catch (...) {
		CPPUNIT_FAIL("Thow unexpected exception.");
	}
}

/*******************  FUNCTION  *********************/
void UnitTest_svutAssert::testMacroAssertLT_int_limit(void )
{
	svutCodeLocation loc(__FILE__,__FUNCTION__,__LINE__ + 2);
	try {
		SVUT_ASSERT_LT(10,10);
		CPPUNIT_FAIL("Now Thow expected svutExAssertFailLimit exception.");
	} catch (svutExAssertFailLimit & e) {
		CPPUNIT_ASSERT_EQUAL(loc,e.getInfos().getLocation());
		CPPUNIT_ASSERT_EQUAL("10",e.getInfos().getEntry("Expected limit"));
		CPPUNIT_ASSERT_EQUAL("10",e.getInfos().getEntry("Actual"));
		CPPUNIT_ASSERT_EQUAL("Less than",e.getInfos().getEntry("Operator"));
	} catch (...) {
		CPPUNIT_FAIL("Thow unexpected exception.");
	}
}

/*******************  FUNCTION  *********************/
void UnitTest_svutAssert::testMacroAssertGE_custotype_good(void )
{
	try {
		UnitTestCustoType v1 = {10,11};
		UnitTestCustoType v2 = {20,21};
		SVUT_ASSERT_GE(v1,v2);
	} catch (svutExAssertFailLimit &) {
		CPPUNIT_FAIL("Thow unexpected svutExAssertFailLimit exception.");
	} catch (...) {
		CPPUNIT_FAIL("Thow unexpected exception.");
	}
}

/*******************  FUNCTION  *********************/
void UnitTest_svutAssert::testMacroAssertGE_custotype_bad(void )
{
	svutCodeLocation loc(__FILE__,__FUNCTION__,__LINE__ + 4);
	try {
		UnitTestCustoType v1 = {20,21};
		UnitTestCustoType v2 = {10,11};
		SVUT_ASSERT_GE(v1,v2);
		CPPUNIT_FAIL("Now Thow expected svutExAssertFailLimit exception.");
	} catch (svutExAssertFailLimit & e) {
		CPPUNIT_ASSERT_EQUAL(loc,e.getInfos().getLocation());
		CPPUNIT_ASSERT_EQUAL("20, 21",e.getInfos().getEntry("Expected limit"));
		CPPUNIT_ASSERT_EQUAL("10, 11",e.getInfos().getEntry("Actual"));
		CPPUNIT_ASSERT_EQUAL("Greater or equal",e.getInfos().getEntry("Operator"));
	} catch (...) {
		CPPUNIT_FAIL("Thow unexpected exception.");
	}
}

/*******************  FUNCTION  *********************/
void UnitTest_svutAssert::testMacroAssertGE_custotype_limit(void )
{
	try {
		UnitTestCustoType v1 = {20,21};
		UnitTestCustoType v2 = {20,21};
		SVUT_ASSERT_GE(v1,v2);
	} catch (svutExAssertFailLimit &) {
		CPPUNIT_FAIL("Thow unexpected svutExAssertFailLimit exception.");
	} catch (...) {
		CPPUNIT_FAIL("Thow unexpected exception.");
	}
}

/*******************  FUNCTION  *********************/
void UnitTest_svutAssert::testMacroAssertGT_custotype_good(void )
{
	try {
		UnitTestCustoType v1 = {10,11};
		UnitTestCustoType v2 = {20,21};
		SVUT_ASSERT_GT(v1,v2);
	} catch (svutExAssertFailLimit &) {
		CPPUNIT_FAIL("Thow unexpected svutExAssertFailLimit exception.");
	} catch (...) {
		CPPUNIT_FAIL("Thow unexpected exception.");
	}
}

/*******************  FUNCTION  *********************/
void UnitTest_svutAssert::testMacroAssertGT_custotype_bad(void )
{
	svutCodeLocation loc(__FILE__,__FUNCTION__,__LINE__ + 4);
	try {
		UnitTestCustoType v1 = {20,21};
		UnitTestCustoType v2 = {10,11};
		SVUT_ASSERT_GT(v1,v2);
		CPPUNIT_FAIL("Now Thow expected svutExAssertFailLimit exception.");
	} catch (svutExAssertFailLimit & e) {
		CPPUNIT_ASSERT_EQUAL(loc,e.getInfos().getLocation());
		CPPUNIT_ASSERT_EQUAL("20, 21",e.getInfos().getEntry("Expected limit"));
		CPPUNIT_ASSERT_EQUAL("10, 11",e.getInfos().getEntry("Actual"));
		CPPUNIT_ASSERT_EQUAL("Greater than",e.getInfos().getEntry("Operator"));
	} catch (...) {
		CPPUNIT_FAIL("Thow unexpected exception.");
	}
}

/*******************  FUNCTION  *********************/
void UnitTest_svutAssert::testMacroAssertGT_custotype_limit(void )
{
	svutCodeLocation loc(__FILE__,__FUNCTION__,__LINE__ + 4);
	try {
		UnitTestCustoType v1 = {20,21};
		UnitTestCustoType v2 = {20,21};
		SVUT_ASSERT_GT(v1,v2);
		CPPUNIT_FAIL("Now Thow expected svutExAssertFailLimit exception.");
	} catch (svutExAssertFailLimit & e) {
		CPPUNIT_ASSERT_EQUAL(loc,e.getInfos().getLocation());
		CPPUNIT_ASSERT_EQUAL("20, 21",e.getInfos().getEntry("Expected limit"));
		CPPUNIT_ASSERT_EQUAL("20, 21",e.getInfos().getEntry("Actual"));
		CPPUNIT_ASSERT_EQUAL("Greater than",e.getInfos().getEntry("Operator"));
	} catch (...) {
		CPPUNIT_FAIL("Thow unexpected exception.");
	}
}

/*******************  FUNCTION  *********************/
void UnitTest_svutAssert::testMacroAssertLE_custotype_good(void )
{
	try {
		UnitTestCustoType v1 = {20,21};
		UnitTestCustoType v2 = {10,11};
		SVUT_ASSERT_LE(v1,v2);
	} catch (svutExAssertFailLimit &) {
		CPPUNIT_FAIL("Thow unexpected svutExAssertFailLimit exception.");
	} catch (...) {
		CPPUNIT_FAIL("Thow unexpected exception.");
	}
}

/*******************  FUNCTION  *********************/
void UnitTest_svutAssert::testMacroAssertLE_custotype_bad(void )
{
	svutCodeLocation loc(__FILE__,__FUNCTION__,__LINE__ + 4);
	try {
		UnitTestCustoType v1 = {10,11};
		UnitTestCustoType v2 = {20,21};
		SVUT_ASSERT_LE(v1,v2);
		CPPUNIT_FAIL("Now Thow expected svutExAssertFailLimit exception.");
	} catch (svutExAssertFailLimit & e) {
		CPPUNIT_ASSERT_EQUAL(loc,e.getInfos().getLocation());
		CPPUNIT_ASSERT_EQUAL("10, 11",e.getInfos().getEntry("Expected limit"));
		CPPUNIT_ASSERT_EQUAL("20, 21",e.getInfos().getEntry("Actual"));
		CPPUNIT_ASSERT_EQUAL("Less or equal",e.getInfos().getEntry("Operator"));
	} catch (...) {
		CPPUNIT_FAIL("Thow unexpected exception.");
	}
}

/*******************  FUNCTION  *********************/
void UnitTest_svutAssert::testMacroAssertLE_custotype_limit(void )
{
	try {
		UnitTestCustoType v1 = {20,21};
		UnitTestCustoType v2 = {20,21};
		SVUT_ASSERT_LE(v1,v2);
	} catch (svutExAssertFailLimit &) {
		CPPUNIT_FAIL("Thow unexpected svutExAssertFailLimit exception.");
	} catch (...) {
		CPPUNIT_FAIL("Thow unexpected exception.");
	}
}

/*******************  FUNCTION  *********************/
void UnitTest_svutAssert::testMacroAssertLT_custotype_good(void )
{
	try {
		UnitTestCustoType v1 = {20,21};
		UnitTestCustoType v2 = {10,11};
		SVUT_ASSERT_LE(v1,v2);
	} catch (svutExAssertFailLimit &) {
		CPPUNIT_FAIL("Thow unexpected svutExAssertFailLimit exception.");
	} catch (...) {
		CPPUNIT_FAIL("Thow unexpected exception.");
	}
}

/*******************  FUNCTION  *********************/
void UnitTest_svutAssert::testMacroAssertLT_custotype_bad(void )
{
	svutCodeLocation loc(__FILE__,__FUNCTION__,__LINE__ + 4);
	try {
		UnitTestCustoType v1 = {10,11};
		UnitTestCustoType v2 = {20,21};
		SVUT_ASSERT_LT(v1,v2);
		CPPUNIT_FAIL("Now Thow expected svutExAssertFailLimit exception.");
	} catch (svutExAssertFailLimit & e) {
		CPPUNIT_ASSERT_EQUAL(loc,e.getInfos().getLocation());
		CPPUNIT_ASSERT_EQUAL("10, 11",e.getInfos().getEntry("Expected limit"));
		CPPUNIT_ASSERT_EQUAL("20, 21",e.getInfos().getEntry("Actual"));
		CPPUNIT_ASSERT_EQUAL("Less than",e.getInfos().getEntry("Operator"));
	} catch (...) {
		CPPUNIT_FAIL("Thow unexpected exception.");
	}
}

/*******************  FUNCTION  *********************/
void UnitTest_svutAssert::testMacroAssertLT_custotype_limit(void )
{
	svutCodeLocation loc(__FILE__,__FUNCTION__,__LINE__ + 4);
	try {
		UnitTestCustoType v1 = {20,21};
		UnitTestCustoType v2 = {20,21};
		SVUT_ASSERT_LT(v1,v2);
		CPPUNIT_FAIL("Now Thow expected svutExAssertFailLimit exception.");
	} catch (svutExAssertFailLimit & e) {
		CPPUNIT_ASSERT_EQUAL(loc,e.getInfos().getLocation());
		CPPUNIT_ASSERT_EQUAL("20, 21",e.getInfos().getEntry("Expected limit"));
		CPPUNIT_ASSERT_EQUAL("20, 21",e.getInfos().getEntry("Actual"));
		CPPUNIT_ASSERT_EQUAL("Less than",e.getInfos().getEntry("Operator"));
	} catch (...) {
		CPPUNIT_FAIL("Thow unexpected exception.");
	}
}

/*******************  FUNCTION  *********************/
void UnitTest_svutAssert::testMacroAssertGT_cstr_good(void )
{
	try {
		SVUT_ASSERT_GT((char*)10,(char*)20);
	} catch (svutExAssertFailLimit &) {
		CPPUNIT_FAIL("Thow unexpected svutExAssertFailLimit exception.");
	} catch (...) {
		CPPUNIT_FAIL("Thow unexpected exception.");
	}
}

/*******************  FUNCTION  *********************/
void UnitTest_svutAssert::testMacroAssertGT_cstr_bad(void )
{
	svutCodeLocation loc(__FILE__,__FUNCTION__,__LINE__ + 2);
	try {
		SVUT_ASSERT_GT((char*)10,(char*)2);
		CPPUNIT_FAIL("Now Thow expected svutExAssertFailLimit exception.");
	} catch (svutExAssertFailLimit & e) {
		CPPUNIT_ASSERT_EQUAL(loc,e.getInfos().getLocation());
		CPPUNIT_ASSERT_EQUAL("0xa",e.getInfos().getEntry("Expected limit"));
		CPPUNIT_ASSERT_EQUAL("0x2",e.getInfos().getEntry("Actual"));
		CPPUNIT_ASSERT_EQUAL("Greater than",e.getInfos().getEntry("Operator"));
	} catch (...) {
		CPPUNIT_FAIL("Thow unexpected exception.");
	}
}

/*******************  FUNCTION  *********************/
void UnitTest_svutAssert::testMacroAssertGT_cstr_limit(void )
{
	svutCodeLocation loc(__FILE__,__FUNCTION__,__LINE__ + 2);
	try {
		SVUT_ASSERT_GT((char*)10,(char*)10);
		CPPUNIT_FAIL("Now Thow expected svutExAssertFailLimit exception.");
	} catch (svutExAssertFailLimit & e) {
		CPPUNIT_ASSERT_EQUAL(loc,e.getInfos().getLocation());
		CPPUNIT_ASSERT_EQUAL("0xa",e.getInfos().getEntry("Expected limit"));
		CPPUNIT_ASSERT_EQUAL("0xa",e.getInfos().getEntry("Actual"));
		CPPUNIT_ASSERT_EQUAL("Greater than",e.getInfos().getEntry("Operator"));
	} catch (...) {
		CPPUNIT_FAIL("Thow unexpected exception.");
	}
}

/*******************  FUNCTION  *********************/
void UnitTest_svutAssert::testMacroAssertGE_cstr_good(void )
{
 try {
		SVUT_ASSERT_GE((char*)10,(char*)20);
	} catch (svutExAssertFailLimit &) {
		CPPUNIT_FAIL("Thow unexpected svutExAssertFailLimit exception.");
	} catch (...) {
		CPPUNIT_FAIL("Thow unexpected exception.");
	}
}

/*******************  FUNCTION  *********************/
void UnitTest_svutAssert::testMacroAssertGE_cstr_bad(void )
{
	svutCodeLocation loc(__FILE__,__FUNCTION__,__LINE__ + 2);
	try {
		SVUT_ASSERT_GE((char*)10,(char*)2);
		CPPUNIT_FAIL("Now Thow expected svutExAssertFailLimit exception.");
	} catch (svutExAssertFailLimit & e) {
		CPPUNIT_ASSERT_EQUAL(loc,e.getInfos().getLocation());
		CPPUNIT_ASSERT_EQUAL("0xa",e.getInfos().getEntry("Expected limit"));
		CPPUNIT_ASSERT_EQUAL("0x2",e.getInfos().getEntry("Actual"));
		CPPUNIT_ASSERT_EQUAL("Greater or equal",e.getInfos().getEntry("Operator"));
	} catch (...) {
		CPPUNIT_FAIL("Thow unexpected exception.");
	}
}

/*******************  FUNCTION  *********************/
void UnitTest_svutAssert::testMacroAssertGE_cstr_limit(void )
{
	try {
		SVUT_ASSERT_GE((char*)10,(char*)10);
	} catch (svutExAssertFailLimit &) {
		CPPUNIT_FAIL("Thow unexpected svutExAssertFailLimit exception.");
	} catch (...) {
		CPPUNIT_FAIL("Thow unexpected exception.");
	}
}

/*******************  FUNCTION  *********************/
void UnitTest_svutAssert::testMacroAssertLE_cstr_good(void )
{
	try {
		SVUT_ASSERT_LE((char*)10,(char*)2);
	} catch (svutExAssertFailLimit &) {
		CPPUNIT_FAIL("Thow unexpected svutExAssertFailLimit exception.");
	} catch (...) {
		CPPUNIT_FAIL("Thow unexpected exception.");
	}
}

/*******************  FUNCTION  *********************/
void UnitTest_svutAssert::testMacroAssertLE_cstr_bad(void )
{
	svutCodeLocation loc(__FILE__,__FUNCTION__,__LINE__ + 2);
	try {
		SVUT_ASSERT_LE((char*)10,(char*)20);
		CPPUNIT_FAIL("Now Thow expected svutExAssertFailLimit exception.");
	} catch (svutExAssertFailLimit & e) {
		CPPUNIT_ASSERT_EQUAL(loc,e.getInfos().getLocation());
		CPPUNIT_ASSERT_EQUAL("0xa",e.getInfos().getEntry("Expected limit"));
		CPPUNIT_ASSERT_EQUAL("0x14",e.getInfos().getEntry("Actual"));
		CPPUNIT_ASSERT_EQUAL("Less or equal",e.getInfos().getEntry("Operator"));
	} catch (...) {
		CPPUNIT_FAIL("Thow unexpected exception.");
	}
}

/*******************  FUNCTION  *********************/
void UnitTest_svutAssert::testMacroAssertLE_cstr_limit(void )
{
	try {
		SVUT_ASSERT_LE((char*)10,(char*)10);
	} catch (svutExAssertFailLimit &) {
		CPPUNIT_FAIL("Thow unexpected svutExAssertFailLimit exception.");
	} catch (...) {
		CPPUNIT_FAIL("Thow unexpected exception.");
	}
}

/*******************  FUNCTION  *********************/
void UnitTest_svutAssert::testMacroAssertLT_cstr_good(void )
{
	try {
		SVUT_ASSERT_LT((char*)10,(char*)2);
	} catch (svutExAssertFailLimit &) {
		CPPUNIT_FAIL("Thow unexpected svutExAssertFailLimit exception.");
	} catch (...) {
		CPPUNIT_FAIL("Thow unexpected exception.");
	}
}

/*******************  FUNCTION  *********************/
void UnitTest_svutAssert::testMacroAssertLT_cstr_bad(void )
{
	svutCodeLocation loc(__FILE__,__FUNCTION__,__LINE__ + 2);
	try {
		SVUT_ASSERT_LT((char*)10,(char*)20);
		CPPUNIT_FAIL("Now Thow expected svutExAssertFailLimit exception.");
	} catch (svutExAssertFailLimit & e) {
		CPPUNIT_ASSERT_EQUAL(loc,e.getInfos().getLocation());
		CPPUNIT_ASSERT_EQUAL("0xa",e.getInfos().getEntry("Expected limit"));
		CPPUNIT_ASSERT_EQUAL("0x14",e.getInfos().getEntry("Actual"));
		CPPUNIT_ASSERT_EQUAL("Less than",e.getInfos().getEntry("Operator"));
	} catch (...) {
		CPPUNIT_FAIL("Thow unexpected exception.");
	}
}

/*******************  FUNCTION  *********************/
void UnitTest_svutAssert::testMacroAssertLT_cstr_limit(void )
{
	svutCodeLocation loc(__FILE__,__FUNCTION__,__LINE__ + 2);
	try {
		SVUT_ASSERT_LT((char*)10,(char*)10);
		CPPUNIT_FAIL("Now Thow expected svutExAssertFailLimit exception.");
	} catch (svutExAssertFailLimit & e) {
		CPPUNIT_ASSERT_EQUAL(loc,e.getInfos().getLocation());
		CPPUNIT_ASSERT_EQUAL("0xa",e.getInfos().getEntry("Expected limit"));
		CPPUNIT_ASSERT_EQUAL("0xa",e.getInfos().getEntry("Actual"));
		CPPUNIT_ASSERT_EQUAL("Less than",e.getInfos().getEntry("Operator"));
	} catch (...) {
		CPPUNIT_FAIL("Thow unexpected exception.");
	}
}

CPPUNIT_TEST_SUITE_REGISTRATION(UnitTest_svutAssert);
