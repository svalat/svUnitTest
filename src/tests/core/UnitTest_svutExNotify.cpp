/*****************************************************
             PROJECT  : svUnitTest
             VERSION  : 0.5.0-dev
             DATE     : 11/2012
             AUTHOR   : Valat Sébastien
             LICENSE  : CeCILL-C
*****************************************************/

/********************  HEADERS  *********************/
#include "UnitTestExtra.h"
#include <svutExNotify.h>

/**********************  USING  *********************/
using namespace std;
using namespace svUnitTest;
using namespace CPPUNIT_NS;

/*********************  CLASS  **********************/
class UnitTest_svutExNotify : public TestCase
{
	CPPUNIT_TEST_SUITE(UnitTest_svutExNotify);
	CPPUNIT_TEST(testExNotify_1);
	CPPUNIT_TEST(testExNotify_2);
	CPPUNIT_TEST(testExNotifyTodo);
	CPPUNIT_TEST(testExNotifyIndev);
	CPPUNIT_TEST_SUITE_END();

	public:
		UnitTest_svutExNotify(void);
		void setUp(void);
		void tearDown(void);

	protected:
		void testExNotify_1(void);
		void testExNotify_2(void);
		void testExNotifyTodo(void);
		void testExNotifyIndev(void);

		svutCodeLocation location;
		svutStatusInfo info;
};

/*******************  FUNCTION  *********************/
UnitTest_svutExNotify::UnitTest_svutExNotify(void )
	:location("test.cpp","test",42),
	info(SVUT_STATUS_INDEV,"this is a test",location)
	
{
	info.addEntry("expected","v1");
	info.addEntry("actual","v2");
}

/*******************  FUNCTION  *********************/
void UnitTest_svutExNotify::setUp(void)
{
}

/*******************  FUNCTION  *********************/
void UnitTest_svutExNotify::tearDown(void)
{
}

/*******************  FUNCTION  *********************/
void UnitTest_svutExNotify::testExNotify_1(void )
{
	//same test than svutExTestStatus
	svutExNotify obj("TEST",info);

	CPPUNIT_ASSERT_EQUAL("Notify:TEST",obj.getExceptionName());
	CPPUNIT_ASSERT_EQUAL(SVUT_STATUS_INDEV,obj.getInfos().getStatus());
	CPPUNIT_ASSERT_EQUAL("this is a test",obj.getInfos().getMessage());
	CPPUNIT_ASSERT_EQUAL(location,obj.getInfos().getLocation());
	CPPUNIT_ASSERT_EQUAL(2u,obj.getInfos().getNbEntries());
	CPPUNIT_ASSERT_EQUAL("v1",obj.getInfos().getEntry("expected"));
	CPPUNIT_ASSERT_EQUAL("v2",obj.getInfos().getEntry("actual"));
	CPPUNIT_ASSERT_EQUAL("this is a test",obj.getMessage());
	CPPUNIT_ASSERT_EQUAL(SVUT_STATUS_INDEV,obj.getStatus());
}

/*******************  FUNCTION  *********************/
void UnitTest_svutExNotify::testExNotify_2(void )
{
	//same test than svutExTestStatus
	svutExNotify obj("TEST",SVUT_STATUS_INDEV,location,"this is a test");

	CPPUNIT_ASSERT_EQUAL("Notify:TEST",obj.getExceptionName());
	CPPUNIT_ASSERT_EQUAL(SVUT_STATUS_INDEV,obj.getInfos().getStatus());
	CPPUNIT_ASSERT_EQUAL("this is a test",obj.getInfos().getMessage());
	CPPUNIT_ASSERT_EQUAL(location,obj.getInfos().getLocation());
	CPPUNIT_ASSERT_EQUAL(0u,obj.getInfos().getNbEntries());
	CPPUNIT_ASSERT_EQUAL("this is a test",obj.getMessage());
	CPPUNIT_ASSERT_EQUAL(SVUT_STATUS_INDEV,obj.getStatus());
}

/*******************  FUNCTION  *********************/
void UnitTest_svutExNotify::testExNotifyTodo(void)
{
	svutExNotifyTodo obj("this is a todo",location);

	CPPUNIT_ASSERT_EQUAL("Notify:Todo",obj.getExceptionName());
	CPPUNIT_ASSERT_EQUAL(SVUT_STATUS_TODO,obj.getInfos().getStatus());
	CPPUNIT_ASSERT_EQUAL("this is a todo",obj.getInfos().getMessage());
	CPPUNIT_ASSERT_EQUAL(location,obj.getInfos().getLocation());
	CPPUNIT_ASSERT_EQUAL(0u,obj.getInfos().getNbEntries());
	CPPUNIT_ASSERT_EQUAL("this is a todo",obj.getMessage());
	CPPUNIT_ASSERT_EQUAL(SVUT_STATUS_TODO,obj.getStatus());
}

/*******************  FUNCTION  *********************/
void UnitTest_svutExNotify::testExNotifyIndev(void )
{
	svutExNotifyIndev obj("this is indev",location);

	CPPUNIT_ASSERT_EQUAL("Notify:Indev",obj.getExceptionName());
	CPPUNIT_ASSERT_EQUAL(SVUT_STATUS_INDEV,obj.getInfos().getStatus());
	CPPUNIT_ASSERT_EQUAL("this is indev",obj.getInfos().getMessage());
	CPPUNIT_ASSERT_EQUAL(location,obj.getInfos().getLocation());
	CPPUNIT_ASSERT_EQUAL(0u,obj.getInfos().getNbEntries());
	CPPUNIT_ASSERT_EQUAL("this is indev",obj.getMessage());
	CPPUNIT_ASSERT_EQUAL(SVUT_STATUS_INDEV,obj.getStatus());
}


CPPUNIT_TEST_SUITE_REGISTRATION(UnitTest_svutExNotify);
