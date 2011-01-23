/*****************************************************
             PROJECT  : svUnitTest
             VERSION  : 0.1.0
             DATE     : 01/2011
             AUTHOR   : Valat Sébastien
             LICENSE  : CeCILL-C
*****************************************************/

/********************  HEADERS  *********************/
#include "UnitTestExtra.h"
#include <iostream>
#include <cppunit/TestCase.h>
#include <cppunit/extensions/TestFactoryRegistry.h>
#include <cppunit/extensions/HelperMacros.h>
#include <svutAssert.h>
#include <svutExNotify.h>

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
};

/********************  STRUCT  **********************/
struct UnitTestCustoType
{
	int value1;
	int value2;
};

/*******************  FUNCTION  *********************/
static bool asserterOperatorEqual(const UnitTestCustoType & v1,const UnitTestCustoType & v2)
{
	return (v1.value1 == v2.value1 && v1.value2 == v2.value2);
}

/*******************  FUNCTION  *********************/
static bool asserterOperatorNotEqual(const UnitTestCustoType & v1,const UnitTestCustoType & v2)
{
	return (v1.value1 != v2.value1 || v1.value2 != v2.value2);
}

/*******************  FUNCTION  *********************/
static std::string asserterToString(const UnitTestCustoType & value)
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
	} catch (svutExAssertFailBool) {
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
	} catch (svutExAssertFailBool e) {
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
	} catch (svutExAssertFailBool) {
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
	} catch (svutExAssertFailBool e) {
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
	} catch (svutExAssertFailNullPointer) {
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
	} catch (svutExAssertFailNullPointer e) {
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
	} catch (svutExAssertFailNullPointer) {
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
	} catch (svutExAssertFailNullPointer e) {
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
	} catch (svutExAssertFailEqual) {
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
	} catch (svutExAssertFailEqual e) {
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
	} catch (svutExAssertFailEqual) {
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
	} catch (svutExAssertFailEqual e) {
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
	} catch (svutExAssertFailEqual) {
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
	} catch (svutExAssertFailEqual e) {
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
	} catch (svutExAssertFailEqual) {
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
	} catch (svutExAssertFailEqual e) {
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
	} catch (svutExAssertFailEqual) {
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
	} catch (svutExAssertFailEqual e) {
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
	} catch (svutExAssertFailEqual) {
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
	} catch (svutExAssertFailEqual e) {
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
	} catch (svutExAssertFailEqual) {
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
	} catch (svutExAssertFailEqual) {
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
	} catch (svutExAssertFailEqual) {
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
	} catch (svutExAssertFailEqual) {
		CPPUNIT_FAIL("Thow unexpected svutExAssertFailEqual exception.");
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
	} catch (svutExAssertFailEqual) {
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
	} catch (svutExAssertFailEqual e) {
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
	} catch (svutExAssertFailEqual) {
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
	} catch (svutExAssertFailEqual e) {
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
	} catch (svutExAssertFailCustom e) {
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
	} catch (svutExNotifyTodo e) {
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
	} catch (svutExNotifyIndev e) {
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
	} catch (svutExAssertFailNotExec e) {
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
	} catch (svutExAssertFailThrow) {
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
	} catch (svutExAssertFailThrow e) {
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
	} catch (svutExAssertFailThrow e) {
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
	} catch (svutExAssertFailThrow) {
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
	} catch (svutExAssertFailThrow e) {
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
	} catch (svutExAssertFailThrow) {
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
	} catch (svutExAssertFailThrow) {
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
	} catch (svutExAssertFailThrow) {
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
	} catch (svutExAssertFailThrow e) {
		CPPUNIT_ASSERT_EQUAL(loc,e.getInfos().getLocation());
		CPPUNIT_ASSERT_EQUAL("NONE",e.getInfos().getEntry("Expected"));
		CPPUNIT_ASSERT_EQUAL("...",e.getInfos().getEntry("Actual"));
	} catch (...) {
		CPPUNIT_FAIL("Thow unexpected exception.");
	}
}

CPPUNIT_TEST_SUITE_REGISTRATION(UnitTest_svutAssert);
