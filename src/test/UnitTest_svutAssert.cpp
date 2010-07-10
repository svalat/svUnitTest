/*****************************************************
             PROJECT  : svUnitTest
             VERSION  : 0.0.2
             DATE     : 06/2010
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

using namespace std;
using namespace svUnitTest;
using namespace CPPUNIT_NS;

/********************  CLASSE  **********************/
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
	CPPUNIT_TEST(testMacroAssertEqualType_int_good);
	CPPUNIT_TEST(testMacroAssertNotEqualType_int_good);
	CPPUNIT_TEST(testMacroAssertEqualType_cstr_good);
	CPPUNIT_TEST(testMacroAssertNotEqualType_cstr_good);
	CPPUNIT_TEST(testMacroAssertSame_good);
	CPPUNIT_TEST(testMacroAssertSame_bad);
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
		void testMacroAssertEqualType_int_good(void);
		void testMacroAssertNotEqualType_int_good(void);
		void testMacroAssertEqualType_cstr_good(void);
		void testMacroAssertNotEqualType_cstr_good(void);
		void testMacroAssertSame_good(void);
		void testMacroAssertSame_bad(void);
};

/********************  STRUCT  **********************/
struct UnitTestCustoType
{
	int value1;
	int value2;
};

/********************  METHODE  *********************/
bool asserterOperatorEqual(const UnitTestCustoType & v1,const UnitTestCustoType & v2)
{
	return (v1.value1 == v2.value1 && v1.value2 == v2.value2);
}

/********************  METHODE  *********************/
bool asserterOperatorNotEqual(const UnitTestCustoType & v1,const UnitTestCustoType & v2)
{
	return (v1.value1 != v2.value1 || v1.value2 != v2.value2);
}

/********************  METHODE  *********************/
std::string asserterToString(const UnitTestCustoType & value)
{
	std::stringstream res;
	res << value.value1 << ", " << value.value2;
	return res.str();
}

/********************  METHODE  *********************/
void UnitTest_svutAssert::setUp(void)
{
}

/********************  METHODE  *********************/
void UnitTest_svutAssert::tearDown(void)
{
}

/********************  METHODE  *********************/
void UnitTest_svutAssert::testMacroAssertTrue_good(void )
{
	try {
		SVUT_ASSERT_TRUE(true);
	} catch (svutExAssertFailBool e) {
		CPPUNIT_FAIL("Thow unexpected svutExAssertFailBool exception.");
	} catch (...) {
		CPPUNIT_FAIL("Thow unexpected exception.");
	}
}

/********************  METHODE  *********************/
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

/********************  METHODE  *********************/
void UnitTest_svutAssert::testMacroAssertFalse_good(void )
{
	try {
		SVUT_ASSERT_FALSE(false);
	} catch (svutExAssertFailBool e) {
		CPPUNIT_FAIL("Thow unexpected svutExAssertFailBool exception.");
	} catch (...) {
		CPPUNIT_FAIL("Thow unexpected exception.");
	}
}

/********************  METHODE  *********************/
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

/********************  METHODE  *********************/
void UnitTest_svutAssert::testMacroAssertNull_good(void )
{
	try {
		SVUT_ASSERT_NULL(NULL);
	} catch (svutExAssertFailNullPointer e) {
		CPPUNIT_FAIL("Thow unexpected svutExAssertFailNullPointer exception.");
	} catch (...) {
		CPPUNIT_FAIL("Thow unexpected exception.");
	}
}

/********************  METHODE  *********************/
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

/********************  METHODE  *********************/
void UnitTest_svutAssert::testMacroAssertNotNull_good(void )
{
	try {
		SVUT_ASSERT_NOT_NULL(0x55);
	} catch (svutExAssertFailNullPointer e) {
		CPPUNIT_FAIL("Thow unexpected svutExAssertFailNullPointer exception.");
	} catch (...) {
		CPPUNIT_FAIL("Thow unexpected exception.");
	}
}

/********************  METHODE  *********************/
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

/********************  METHODE  *********************/
void UnitTest_svutAssert::testMacroAssertEqual_int_good(void)
{
	try {
		SVUT_ASSERT_EQUAL(10,10);
	} catch (svutExAssertFailEqual e) {
		CPPUNIT_FAIL("Thow unexpected svutExAssertFailEqual exception.");
	} catch (...) {
		CPPUNIT_FAIL("Thow unexpected exception.");
	}
}

/********************  METHODE  *********************/
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

/********************  METHODE  *********************/
void UnitTest_svutAssert::testMacroAssertEqual_cstr_good(void)
{
	try {
		SVUT_ASSERT_EQUAL("Hello World !!","Hello World !!");
	} catch (svutExAssertFailEqual e) {
		CPPUNIT_FAIL("Thow unexpected svutExAssertFailEqual exception.");
	} catch (...) {
		CPPUNIT_FAIL("Thow unexpected exception.");
	}
}

/********************  METHODE  *********************/
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

/********************  METHODE  *********************/
void UnitTest_svutAssert::testMacroAssertEqual_custotype_good(void)
{
	try {
		UnitTestCustoType v1 = {10,20};
		UnitTestCustoType v2 = {10,20};
		SVUT_ASSERT_EQUAL(v1,v2);
	} catch (svutExAssertFailEqual e) {
		CPPUNIT_FAIL("Thow unexpected svutExAssertFailEqual exception.");
	} catch (...) {
		CPPUNIT_FAIL("Thow unexpected exception.");
	}
}

/********************  METHODE  *********************/
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

/********************  METHODE  *********************/
void UnitTest_svutAssert::testMacroAssertNotEqual_int_good(void)
{
	try {
		SVUT_ASSERT_NOT_EQUAL(10,20);
	} catch (svutExAssertFailEqual e) {
		CPPUNIT_FAIL("Thow unexpected svutExAssertFailEqual exception.");
	} catch (...) {
		CPPUNIT_FAIL("Thow unexpected exception.");
	}
}

/********************  METHODE  *********************/
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

/********************  METHODE  *********************/
void UnitTest_svutAssert::testMacroAssertNotEqual_cstr_good(void)
{
	try {
		SVUT_ASSERT_NOT_EQUAL("Hello World !!","Hello Bob !!");
	} catch (svutExAssertFailEqual e) {
		CPPUNIT_FAIL("Thow unexpected svutExAssertFailEqual exception.");
	} catch (...) {
		CPPUNIT_FAIL("Thow unexpected exception.");
	}
}

/********************  METHODE  *********************/
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

/********************  METHODE  *********************/
void UnitTest_svutAssert::testMacroAssertNotEqual_custotype_good(void)
{
	try {
		UnitTestCustoType v1 = {10,20};
		UnitTestCustoType v2 = {10,30};
		SVUT_ASSERT_NOT_EQUAL(v1,v2);
	} catch (svutExAssertFailEqual e) {
		CPPUNIT_FAIL("Thow unexpected svutExAssertFailEqual exception.");
	} catch (...) {
		CPPUNIT_FAIL("Thow unexpected exception.");
	}
}

/********************  METHODE  *********************/
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

/********************  METHODE  *********************/
void UnitTest_svutAssert::testMacroAssertEqualType_int_good(void)
{
	try {
		SVUT_ASSERT_EQUAL_TYPE(10,10);
	} catch (svutExAssertFailEqual e) {
		CPPUNIT_FAIL("Thow unexpected svutExAssertFailEqual exception.");
	} catch (...) {
		CPPUNIT_FAIL("Thow unexpected exception.");
	}
}

/********************  METHODE  *********************/
void UnitTest_svutAssert::testMacroAssertNotEqualType_int_good(void)
{
	try {
		SVUT_ASSERT_NOT_EQUAL_TYPE(10,20);
	} catch (svutExAssertFailEqual e) {
		CPPUNIT_FAIL("Thow unexpected svutExAssertFailEqual exception.");
	} catch (...) {
		CPPUNIT_FAIL("Thow unexpected exception.");
	}
}

/********************  METHODE  *********************/
void UnitTest_svutAssert::testMacroAssertEqualType_cstr_good(void)
{
	try {
		SVUT_ASSERT_EQUAL_TYPE("Hello World !!","Hello World !!");
	} catch (svutExAssertFailEqual e) {
		CPPUNIT_FAIL("Thow unexpected svutExAssertFailEqual exception.");
	} catch (...) {
		CPPUNIT_FAIL("Thow unexpected exception.");
	}
}

/********************  METHODE  *********************/
void UnitTest_svutAssert::testMacroAssertNotEqualType_cstr_good(void)
{
	try {
		SVUT_ASSERT_NOT_EQUAL_TYPE("Hello World !!","Hello Bob !!");
	} catch (svutExAssertFailEqual e) {
		CPPUNIT_FAIL("Thow unexpected svutExAssertFailEqual exception.");
	} catch (...) {
		CPPUNIT_FAIL("Thow unexpected exception.");
	}
}

/********************  METHODE  *********************/
void UnitTest_svutAssert::testMacroAssertSame_good(void)
{
	try {
		int a = 66;
		SVUT_ASSERT_SAME(&a,&a);
	} catch (svutExAssertFailEqual e) {
		CPPUNIT_FAIL("Thow unexpected svutExAssertFailEqual exception.");
	} catch (...) {
		CPPUNIT_FAIL("Thow unexpected exception.");
	}
}

/********************  METHODE  *********************/
void UnitTest_svutAssert::testMacroAssertSame_bad(void)
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

CPPUNIT_TEST_SUITE_REGISTRATION(UnitTest_svutAssert);
