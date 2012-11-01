/*****************************************************
             PROJECT  : svUnitTest
             VERSION  : 0.4.0
             DATE     : 11/2012
             AUTHOR   : Valat Sébastien
             LICENSE  : CeCILL-C
*****************************************************/

/********************  HEADERS  *********************/
#include "UnitTestExtra.h"
#include <svutExTestStatus.h>

/**********************  USING  *********************/
using namespace svUnitTest;
using namespace std;
using namespace CPPUNIT_NS;

/*********************  CLASS  **********************/
class UnitTest_svutExTestStatus : public TestCase
{
	CPPUNIT_TEST_SUITE(UnitTest_svutExTestStatus);
	CPPUNIT_TEST(testConstructor_1);
	CPPUNIT_TEST(teesConsturctor_2);
	CPPUNIT_TEST(testGetExceptionName);
	CPPUNIT_TEST(testGetInfos);
	CPPUNIT_TEST(testGetInfos_const);
	CPPUNIT_TEST(testGetStatus);
	CPPUNIT_TEST(testWhat);
	CPPUNIT_TEST(testGetMessage);
	CPPUNIT_TEST_SUITE_END();

	public:
		void setUp(void);
		void tearDown(void);

	protected:
		void testConstructor_1(void);
		void teesConsturctor_2(void);
		void testGetExceptionName(void);
		void testGetInfos(void);
		void testGetInfos_const(void);
		void testGetStatus(void);
		void testWhat(void);
		void testGetMessage(void);

		svutExTestStatus * status;
		const svutExTestStatus * cstStatus;
};

/*******************  FUNCTION  *********************/
void UnitTest_svutExTestStatus::setUp(void)
{
	svutStatusInfo info(SVUT_STATUS_INDEV,"this is a test",svutCodeLocation("file.cpp","test()",42));
	info.addEntry("expected","v1");
	info.addEntry("actual","v2");
	this->status = new svutExTestStatus("TEST",info);
	this->cstStatus = status;
}

/*******************  FUNCTION  *********************/
void UnitTest_svutExTestStatus::tearDown(void)
{
	delete this->status;
}

/*******************  FUNCTION  *********************/
void UnitTest_svutExTestStatus::testConstructor_1(void )
{
	svutStatusInfo info(SVUT_STATUS_INDEV,"this is a test",svutCodeLocation("file.cpp","test()",42));
	info.addEntry("expected","v1");
	info.addEntry("actual","v2");
	svutExTestStatus obj("TEST",info);

	CPPUNIT_ASSERT_EQUAL("TEST",obj.getExceptionName());
	CPPUNIT_ASSERT_EQUAL(SVUT_STATUS_INDEV,obj.getInfos().getStatus());
	CPPUNIT_ASSERT_EQUAL("this is a test",obj.getInfos().getMessage());
	CPPUNIT_ASSERT_EQUAL(svutCodeLocation("file.cpp","test()",42),obj.getInfos().getLocation());
	CPPUNIT_ASSERT_EQUAL(2u,obj.getInfos().getNbEntries());
	CPPUNIT_ASSERT_EQUAL("v1",obj.getInfos().getEntry("expected"));
	CPPUNIT_ASSERT_EQUAL("v2",obj.getInfos().getEntry("actual"));
	CPPUNIT_ASSERT_EQUAL("this is a test",obj.getMessage());
	CPPUNIT_ASSERT_EQUAL(SVUT_STATUS_INDEV,obj.getStatus());
}

/*******************  FUNCTION  *********************/
void UnitTest_svutExTestStatus::teesConsturctor_2(void )
{
	svutExTestStatus obj("TEST",SVUT_STATUS_INDEV,svutCodeLocation("file.cpp","test()",42),"this is a test");

	CPPUNIT_ASSERT_EQUAL("TEST",obj.getExceptionName());
	CPPUNIT_ASSERT_EQUAL(SVUT_STATUS_INDEV,obj.getInfos().getStatus());
	CPPUNIT_ASSERT_EQUAL("this is a test",obj.getInfos().getMessage());
	CPPUNIT_ASSERT_EQUAL(svutCodeLocation("file.cpp","test()",42),obj.getInfos().getLocation());
	CPPUNIT_ASSERT_EQUAL(0u,obj.getInfos().getNbEntries());
	CPPUNIT_ASSERT_EQUAL("this is a test",obj.getMessage());
	CPPUNIT_ASSERT_EQUAL(SVUT_STATUS_INDEV,obj.getStatus());
}

/*******************  FUNCTION  *********************/
void UnitTest_svutExTestStatus::testGetExceptionName(void )
{
	CPPUNIT_ASSERT_EQUAL("TEST",status->getExceptionName());
}

/*******************  FUNCTION  *********************/
void UnitTest_svutExTestStatus::testGetInfos(void )
{
	CPPUNIT_ASSERT_EQUAL(SVUT_STATUS_INDEV,status->getInfos().getStatus());
	CPPUNIT_ASSERT_EQUAL("this is a test",status->getInfos().getMessage());
	CPPUNIT_ASSERT_EQUAL(svutCodeLocation("file.cpp","test()",42),status->getInfos().getLocation());
	CPPUNIT_ASSERT_EQUAL(2u,status->getInfos().getNbEntries());
	CPPUNIT_ASSERT_EQUAL("v1",status->getInfos().getEntry("expected"));
	CPPUNIT_ASSERT_EQUAL("v2",status->getInfos().getEntry("actual"));
	
	status->getInfos().addEntry("test","test");
	CPPUNIT_ASSERT_EQUAL(3u,status->getInfos().getNbEntries());
	CPPUNIT_ASSERT_EQUAL("test",status->getInfos().getEntry("test"));
}

/*******************  FUNCTION  *********************/
void UnitTest_svutExTestStatus::testGetInfos_const(void )
{
	CPPUNIT_ASSERT_EQUAL(SVUT_STATUS_INDEV,cstStatus->getInfos().getStatus());
	CPPUNIT_ASSERT_EQUAL("this is a test",cstStatus->getInfos().getMessage());
	CPPUNIT_ASSERT_EQUAL(svutCodeLocation("file.cpp","test()",42),cstStatus->getInfos().getLocation());
	CPPUNIT_ASSERT_EQUAL(2u,cstStatus->getInfos().getNbEntries());
	CPPUNIT_ASSERT_EQUAL("v1",cstStatus->getInfos().getEntry("expected"));
	CPPUNIT_ASSERT_EQUAL("v2",cstStatus->getInfos().getEntry("actual"));
}

/*******************  FUNCTION  *********************/
void UnitTest_svutExTestStatus::testGetMessage(void )
{
	CPPUNIT_ASSERT_EQUAL("this is a test",status->getMessage());
}

/*******************  FUNCTION  *********************/
void UnitTest_svutExTestStatus::testGetStatus(void )
{
	CPPUNIT_ASSERT_EQUAL(SVUT_STATUS_INDEV,status->getStatus());
}

/*******************  FUNCTION  *********************/
void UnitTest_svutExTestStatus::testWhat(void )
{
	string tmp = "TEST : this is a test : \n  - actual : v2\n  - expected : v1\n";
	const char * what = status->what();
	CPPUNIT_ASSERT_EQUAL(tmp,what);
	delete [] what;
}

CPPUNIT_TEST_SUITE_REGISTRATION(UnitTest_svutExTestStatus);
