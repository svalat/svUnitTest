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
#include <svutExAssert.h>

using namespace std;
using namespace svUnitTest;
using namespace CPPUNIT_NS;

/********************  CLASSE  **********************/
class UnitTest_svutExAssert : public TestCase
{
	CPPUNIT_TEST_SUITE(UnitTest_svutExAssert);
	CPPUNIT_TEST(testExAssertFail_1);
	CPPUNIT_TEST(testExAssertFail_2);
	CPPUNIT_TEST_SUITE_END();

	public:
		UnitTest_svutExAssert(void);
		void setUp(void);
		void tearDown(void);

	protected:
		void testExAssertFail_1(void);
		void testExAssertFail_2(void);

		svutCodeLocation location;
		svutStatusInfo info;
};

/********************  METHODE  *********************/
UnitTest_svutExAssert::UnitTest_svutExAssert(void )
	:location("test.cpp","test",42),
	info(SVUT_STATUS_FAILED,"this is a test",location)

{
	info.addEntry("expected","v1");
	info.addEntry("actual","v2");
}

/********************  METHODE  *********************/
void UnitTest_svutExAssert::setUp(void)
{
}

/********************  METHODE  *********************/
void UnitTest_svutExAssert::tearDown(void)
{
}

/********************  METHODE  *********************/
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

/********************  METHODE  *********************/
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


CPPUNIT_TEST_SUITE_REGISTRATION(UnitTest_svutExAssert);
