/*****************************************************
             PROJECT  : svUnitTest
             VERSION  : 0.3.0-dev
             DATE     : 03/2011
             AUTHOR   : Valat Sébastien
             LICENSE  : CeCILL-C
*****************************************************/

/********************  HEADERS  *********************/
#include "UnitTestExtra.h"
#include <iostream>
#include <cppunit/TestCase.h>
#include <cppunit/extensions/TestFactoryRegistry.h>
#include <cppunit/extensions/HelperMacros.h>
#include <svutExAssert.h>

/**********************  USING  *********************/
using namespace std;
using namespace svUnitTest;
using namespace CPPUNIT_NS;

/*********************  CLASS  **********************/
class UnitTest_svutExAssert : public TestCase
{
	CPPUNIT_TEST_SUITE(UnitTest_svutExAssert);
	CPPUNIT_TEST(testExAssertFail_1);
	CPPUNIT_TEST(testExAssertFail_2);
	CPPUNIT_TEST(testExAssertFailBool_1);
	CPPUNIT_TEST(testExAssertFailBool_2);
	CPPUNIT_TEST(testExAssertFailNull_1);
	CPPUNIT_TEST(testExAssertFailNull_2);
	CPPUNIT_TEST(testExAssertFailEqual_1);
	CPPUNIT_TEST(testExAssertFailEqual_2);
	CPPUNIT_TEST(testExAssertFailCustom);
	CPPUNIT_TEST(testExAssertFailNotExec);
	CPPUNIT_TEST(testExAssertFailThrow);
	CPPUNIT_TEST_SUITE_END();

	public:
		UnitTest_svutExAssert(void);
		void setUp(void);
		void tearDown(void);

	protected:
		void testExAssertFail_1(void);
		void testExAssertFail_2(void);
		void testExAssertFailBool_1(void);
		void testExAssertFailBool_2(void);
		void testExAssertFailNull_1(void);
		void testExAssertFailNull_2(void);
		void testExAssertFailEqual_1(void);
		void testExAssertFailEqual_2(void);
		void testExAssertFailCustom(void);
		void testExAssertFailNotExec(void);
		void testExAssertFailThrow(void);

		svutCodeLocation location;
		svutStatusInfo info;
};

/*******************  FUNCTION  *********************/
UnitTest_svutExAssert::UnitTest_svutExAssert(void )
	:location("test.cpp","test",42),
	info(SVUT_STATUS_FAILED,"this is a test",location)

{
	info.addEntry("expected","v1");
	info.addEntry("actual","v2");
}

/*******************  FUNCTION  *********************/
void UnitTest_svutExAssert::setUp(void)
{
}

/*******************  FUNCTION  *********************/
void UnitTest_svutExAssert::tearDown(void)
{
}

/*******************  FUNCTION  *********************/
void UnitTest_svutExAssert::testExAssertFail_1(void )
{
	//same test than svutExTestStatus
	svutExAssertFail obj("TEST",info);

	CPPUNIT_ASSERT_EQUAL("AssertFail:TEST",obj.getExceptionName());
	CPPUNIT_ASSERT_EQUAL(SVUT_STATUS_FAILED,obj.getInfos().getStatus());
	CPPUNIT_ASSERT_EQUAL("this is a test",obj.getInfos().getMessage());
	CPPUNIT_ASSERT_EQUAL(location,obj.getInfos().getLocation());
	CPPUNIT_ASSERT_EQUAL(2,obj.getInfos().getNbEntries());
	CPPUNIT_ASSERT_EQUAL("v1",obj.getInfos().getEntry("expected"));
	CPPUNIT_ASSERT_EQUAL("v2",obj.getInfos().getEntry("actual"));
	CPPUNIT_ASSERT_EQUAL("this is a test",obj.getMessage());
	CPPUNIT_ASSERT_EQUAL(SVUT_STATUS_FAILED,obj.getStatus());
}

/*******************  FUNCTION  *********************/
void UnitTest_svutExAssert::testExAssertFail_2(void )
{
	//same test than svutExTestStatus
	svutExAssertFail obj("TEST",SVUT_STATUS_FAILED,location,"this is a test");

	CPPUNIT_ASSERT_EQUAL("AssertFail:TEST",obj.getExceptionName());
	CPPUNIT_ASSERT_EQUAL(SVUT_STATUS_FAILED,obj.getInfos().getStatus());
	CPPUNIT_ASSERT_EQUAL("this is a test",obj.getInfos().getMessage());
	CPPUNIT_ASSERT_EQUAL(location,obj.getInfos().getLocation());
	CPPUNIT_ASSERT_EQUAL(0,obj.getInfos().getNbEntries());
	CPPUNIT_ASSERT_EQUAL("this is a test",obj.getMessage());
	CPPUNIT_ASSERT_EQUAL(SVUT_STATUS_FAILED,obj.getStatus());
}

/*******************  FUNCTION  *********************/
void UnitTest_svutExAssert::testExAssertFailBool_1(void )
{
	//same test than svutExTestStatus
	svutExAssertFailBool obj(true,location);

	CPPUNIT_ASSERT_EQUAL("AssertFail:AssertBool",obj.getExceptionName());
	CPPUNIT_ASSERT_EQUAL(SVUT_STATUS_FAILED,obj.getInfos().getStatus());
	CPPUNIT_ASSERT_EQUAL("Failed on BOOLEAN test.",obj.getInfos().getMessage());
	CPPUNIT_ASSERT_EQUAL(location,obj.getInfos().getLocation());
	CPPUNIT_ASSERT_EQUAL(2,obj.getInfos().getNbEntries());
	CPPUNIT_ASSERT_EQUAL("TRUE",obj.getInfos().getEntry("Expected"));
	CPPUNIT_ASSERT_EQUAL("FALSE",obj.getInfos().getEntry("Actual"));
	CPPUNIT_ASSERT_EQUAL("Failed on BOOLEAN test.",obj.getMessage());
	CPPUNIT_ASSERT_EQUAL(SVUT_STATUS_FAILED,obj.getStatus());
}

/*******************  FUNCTION  *********************/
void UnitTest_svutExAssert::testExAssertFailBool_2(void )
{
	//same test than svutExTestStatus
	svutExAssertFailBool obj(false,location);

	CPPUNIT_ASSERT_EQUAL("AssertFail:AssertBool",obj.getExceptionName());
	CPPUNIT_ASSERT_EQUAL(SVUT_STATUS_FAILED,obj.getInfos().getStatus());
	CPPUNIT_ASSERT_EQUAL("Failed on BOOLEAN test.",obj.getInfos().getMessage());
	CPPUNIT_ASSERT_EQUAL(location,obj.getInfos().getLocation());
	CPPUNIT_ASSERT_EQUAL(2,obj.getInfos().getNbEntries());
	CPPUNIT_ASSERT_EQUAL("FALSE",obj.getInfos().getEntry("Expected"));
	CPPUNIT_ASSERT_EQUAL("TRUE",obj.getInfos().getEntry("Actual"));
	CPPUNIT_ASSERT_EQUAL("Failed on BOOLEAN test.",obj.getMessage());
	CPPUNIT_ASSERT_EQUAL(SVUT_STATUS_FAILED,obj.getStatus());
}

/*******************  FUNCTION  *********************/
void UnitTest_svutExAssert::testExAssertFailNull_1(void )
{
	//same test than svutExTestStatus
	svutExAssertFailNullPointer obj(true,location);

	CPPUNIT_ASSERT_EQUAL("AssertFail:AssertNull",obj.getExceptionName());
	CPPUNIT_ASSERT_EQUAL(SVUT_STATUS_FAILED,obj.getInfos().getStatus());
	CPPUNIT_ASSERT_EQUAL("Failed on NULL pointer test.",obj.getInfos().getMessage());
	CPPUNIT_ASSERT_EQUAL(location,obj.getInfos().getLocation());
	CPPUNIT_ASSERT_EQUAL(2,obj.getInfos().getNbEntries());
	CPPUNIT_ASSERT_EQUAL("NULL",obj.getInfos().getEntry("Expected"));
	CPPUNIT_ASSERT_EQUAL("NOT NULL",obj.getInfos().getEntry("Actual"));
	CPPUNIT_ASSERT_EQUAL("Failed on NULL pointer test.",obj.getMessage());
	CPPUNIT_ASSERT_EQUAL(SVUT_STATUS_FAILED,obj.getStatus());
}

/*******************  FUNCTION  *********************/
void UnitTest_svutExAssert::testExAssertFailNull_2(void )
{
	//same test than svutExTestStatus
	svutExAssertFailNullPointer obj(false,location);

	CPPUNIT_ASSERT_EQUAL("AssertFail:AssertNull",obj.getExceptionName());
	CPPUNIT_ASSERT_EQUAL(SVUT_STATUS_FAILED,obj.getInfos().getStatus());
	CPPUNIT_ASSERT_EQUAL("Failed on NULL pointer test.",obj.getInfos().getMessage());
	CPPUNIT_ASSERT_EQUAL(location,obj.getInfos().getLocation());
	CPPUNIT_ASSERT_EQUAL(2,obj.getInfos().getNbEntries());
	CPPUNIT_ASSERT_EQUAL("NOT NULL",obj.getInfos().getEntry("Expected"));
	CPPUNIT_ASSERT_EQUAL("NULL",obj.getInfos().getEntry("Actual"));
	CPPUNIT_ASSERT_EQUAL("Failed on NULL pointer test.",obj.getMessage());
	CPPUNIT_ASSERT_EQUAL(SVUT_STATUS_FAILED,obj.getStatus());
}

/*******************  FUNCTION  *********************/
void UnitTest_svutExAssert::testExAssertFailEqual_1(void )
{
	//same test than svutExTestStatus
	svutExAssertFailEqual obj(true,"test","TEST",location);

	CPPUNIT_ASSERT_EQUAL("AssertFail:AssertEqual",obj.getExceptionName());
	CPPUNIT_ASSERT_EQUAL(SVUT_STATUS_FAILED,obj.getInfos().getStatus());
	CPPUNIT_ASSERT_EQUAL("Failed on expected value.",obj.getInfos().getMessage());
	CPPUNIT_ASSERT_EQUAL(location,obj.getInfos().getLocation());
	CPPUNIT_ASSERT_EQUAL(2,obj.getInfos().getNbEntries());
	CPPUNIT_ASSERT_EQUAL("test",obj.getInfos().getEntry("Expected"));
	CPPUNIT_ASSERT_EQUAL("TEST",obj.getInfos().getEntry("Actual"));
	CPPUNIT_ASSERT_EQUAL("Failed on expected value.",obj.getMessage());
	CPPUNIT_ASSERT_EQUAL(SVUT_STATUS_FAILED,obj.getStatus());
}

/*******************  FUNCTION  *********************/
void UnitTest_svutExAssert::testExAssertFailEqual_2(void )
{
	//same test than svutExTestStatus
	svutExAssertFailEqual obj(false,"test","TEST",location);

	CPPUNIT_ASSERT_EQUAL("AssertFail:AssertEqual",obj.getExceptionName());
	CPPUNIT_ASSERT_EQUAL(SVUT_STATUS_FAILED,obj.getInfos().getStatus());
	CPPUNIT_ASSERT_EQUAL("Failed on expected value.",obj.getInfos().getMessage());
	CPPUNIT_ASSERT_EQUAL(location,obj.getInfos().getLocation());
	CPPUNIT_ASSERT_EQUAL(2,obj.getInfos().getNbEntries());
	CPPUNIT_ASSERT_EQUAL("test",obj.getInfos().getEntry("Not expected"));
	CPPUNIT_ASSERT_EQUAL("TEST",obj.getInfos().getEntry("Actual"));
	CPPUNIT_ASSERT_EQUAL("Failed on expected value.",obj.getMessage());
	CPPUNIT_ASSERT_EQUAL(SVUT_STATUS_FAILED,obj.getStatus());
}

/*******************  FUNCTION  *********************/
void UnitTest_svutExAssert::testExAssertFailCustom(void )
{
	//same test than svutExTestStatus
	svutExAssertFailCustom obj("Custom test message",location);

	CPPUNIT_ASSERT_EQUAL("AssertFail:AssertCustom",obj.getExceptionName());
	CPPUNIT_ASSERT_EQUAL(SVUT_STATUS_FAILED,obj.getInfos().getStatus());
	CPPUNIT_ASSERT_EQUAL("Custom test message",obj.getInfos().getMessage());
	CPPUNIT_ASSERT_EQUAL(location,obj.getInfos().getLocation());
	CPPUNIT_ASSERT_EQUAL(0,obj.getInfos().getNbEntries());
	CPPUNIT_ASSERT_EQUAL("Custom test message",obj.getMessage());
	CPPUNIT_ASSERT_EQUAL(SVUT_STATUS_FAILED,obj.getStatus());
}

/*******************  FUNCTION  *********************/
void UnitTest_svutExAssert::testExAssertFailNotExec(void )
{
	//same test than svutExTestStatus
	svutExAssertFailNotExec obj(location);

	CPPUNIT_ASSERT_EQUAL("AssertFail:AssertNotExec",obj.getExceptionName());
	CPPUNIT_ASSERT_EQUAL(SVUT_STATUS_FAILED,obj.getInfos().getStatus());
	CPPUNIT_ASSERT_EQUAL("Failed on execution of forbidden bloc.",obj.getInfos().getMessage());
	CPPUNIT_ASSERT_EQUAL(location,obj.getInfos().getLocation());
	CPPUNIT_ASSERT_EQUAL(0,obj.getInfos().getNbEntries());
	CPPUNIT_ASSERT_EQUAL("Failed on execution of forbidden bloc.",obj.getMessage());
	CPPUNIT_ASSERT_EQUAL(SVUT_STATUS_FAILED,obj.getStatus());
}

/*******************  FUNCTION  *********************/
void UnitTest_svutExAssert::testExAssertFailThrow(void )
{
	//same test than svutExTestStatus
	svutExAssertFailThrow obj("wantThis","getThis",location);

	CPPUNIT_ASSERT_EQUAL("AssertFail:AssertThrow",obj.getExceptionName());
	CPPUNIT_ASSERT_EQUAL(SVUT_STATUS_FAILED,obj.getInfos().getStatus());
	CPPUNIT_ASSERT_EQUAL("Failed on waiting exception.",obj.getInfos().getMessage());
	CPPUNIT_ASSERT_EQUAL(location,obj.getInfos().getLocation());
	CPPUNIT_ASSERT_EQUAL(2,obj.getInfos().getNbEntries());
	CPPUNIT_ASSERT_EQUAL("wantThis",obj.getInfos().getEntry("Expected"));
	CPPUNIT_ASSERT_EQUAL("getThis",obj.getInfos().getEntry("Actual"));
	CPPUNIT_ASSERT_EQUAL("Failed on waiting exception.",obj.getMessage());
	CPPUNIT_ASSERT_EQUAL(SVUT_STATUS_FAILED,obj.getStatus());
}

CPPUNIT_TEST_SUITE_REGISTRATION(UnitTest_svutExAssert);
