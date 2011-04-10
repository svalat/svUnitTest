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
#include <svutStatusInfo.h>
#include <sstream>

/**********************  USING  *********************/
using namespace svUnitTest;
using namespace std;
using namespace CPPUNIT_NS;

/********************  MACROS  **********************/
#define TEST_FILENAME "test.h"
#define TEST_LINE 77
#define TEST_METHODE "void test(void)"
#define TEST_MESSAGE "this is a test"

/*********************  CLASS  **********************/
class UnitTest_svutStatusInfo : public TestCase
{
	CPPUNIT_TEST_SUITE(UnitTest_svutStatusInfo);
	CPPUNIT_TEST(testConstructor_1);
	CPPUNIT_TEST(testConstructor_2);
	CPPUNIT_TEST(testAddEntry);
	CPPUNIT_TEST(testFormatEntries);
	CPPUNIT_TEST(testGetLocation);
	CPPUNIT_TEST(testGetMessage);
	CPPUNIT_TEST(testGetStatus);
	CPPUNIT_TEST(testGetNbEntries);
	CPPUNIT_TEST(testGetEntry);
	CPPUNIT_TEST(testOperatorEqual);
	CPPUNIT_TEST(testGetStatusName_1);
	CPPUNIT_TEST(testGetStatusName_2);
	CPPUNIT_TEST(testGetStatusName_3);
	CPPUNIT_TEST(testGetStatusName_4);
	CPPUNIT_TEST(testGetStatusName_5);
	CPPUNIT_TEST(testGetStatusName_6);
	CPPUNIT_TEST(testGetStatusName_static);
	CPPUNIT_TEST(textSetDebugContext);
	CPPUNIT_TEST_SUITE_END();

	public:
		void setUp(void);
		void tearDown(void);

	protected:
		void testConstructor_1(void);
		void testConstructor_2(void);
		void testAddEntry(void);
		void testFormatEntries(void);
		void testGetLocation(void);
		void testGetMessage(void);
		void testGetStatus(void);
		void testGetNbEntries(void);
		void testGetEntry(void);
		void testOperatorEqual(void);
		void testGetStatusName_1(void);
		void testGetStatusName_2(void);
		void testGetStatusName_3(void);
		void testGetStatusName_4(void);
		void testGetStatusName_5(void);
		void testGetStatusName_6(void);
		void testGetStatusName_static(void);
		void textSetDebugContext(void);
		

		svutStatusInfo * info;
};

/*******************  FUNCTION  *********************/
void UnitTest_svutStatusInfo::setUp(void)
{
	svutCodeLocation loc(TEST_FILENAME,TEST_METHODE,TEST_LINE);
	this->info = new svutStatusInfo(SVUT_STATUS_FAILED, TEST_MESSAGE,loc);
}

/*******************  FUNCTION  *********************/
void UnitTest_svutStatusInfo::tearDown(void)
{
	delete this->info;
}

/*******************  FUNCTION  *********************/
void UnitTest_svutStatusInfo::testConstructor_1(void )
{
	svutStatusInfo empty;
	CPPUNIT_ASSERT_EQUAL(SVUT_NO_LOCATION,empty.getLocation());
	CPPUNIT_ASSERT_EQUAL("",empty.getMessage());
	CPPUNIT_ASSERT_EQUAL(SVUT_STATUS_SKIPED,empty.getStatus());
	CPPUNIT_ASSERT_EQUAL(0u,empty.getNbEntries());
}

/*******************  FUNCTION  *********************/
void UnitTest_svutStatusInfo::testConstructor_2(void )
{
	svutCodeLocation loc(TEST_FILENAME,TEST_METHODE,TEST_LINE);
	svutStatusInfo copy(SVUT_STATUS_SUCCESS,TEST_MESSAGE,loc);
	CPPUNIT_ASSERT_EQUAL(loc,copy.getLocation());
	CPPUNIT_ASSERT_EQUAL(TEST_MESSAGE,copy.getMessage());
	CPPUNIT_ASSERT_EQUAL(SVUT_STATUS_SUCCESS,copy.getStatus());
	CPPUNIT_ASSERT_EQUAL(0u,copy.getNbEntries());
}

/*******************  FUNCTION  *********************/
void UnitTest_svutStatusInfo::testAddEntry ( void )
{
	CPPUNIT_ASSERT_EQUAL(0U,info->getEntries().size());
	info->addEntry("name","value");
	CPPUNIT_ASSERT_EQUAL(1U,info->getEntries().size());
	CPPUNIT_ASSERT_EQUAL("name",info->getEntries().begin()->first);
	CPPUNIT_ASSERT_EQUAL("value",info->getEntries().begin()->second);
}

/*******************  FUNCTION  *********************/
void UnitTest_svutStatusInfo::testFormatEntries ( void )
{
	stringstream str;
	CPPUNIT_ASSERT_EQUAL(0U,info->getEntries().size());
	info->addEntry("name_test","value_test");
	info->addEntry("name_test2","value_test2");
	info->formatEntries(str,"<",",",">");
	CPPUNIT_ASSERT_EQUAL("<name_test,value_test><name_test2,value_test2>",str.str());
}

/*******************  FUNCTION  *********************/
void UnitTest_svutStatusInfo::testGetLocation ( void )
{
	svutCodeLocation loc(TEST_FILENAME,TEST_METHODE,TEST_LINE);
	CPPUNIT_ASSERT_EQUAL(loc,info->getLocation());
}

/*******************  FUNCTION  *********************/
void UnitTest_svutStatusInfo::testGetMessage ( void )
{
	CPPUNIT_ASSERT_EQUAL(TEST_MESSAGE,info->getMessage());
}

/*******************  FUNCTION  *********************/
void UnitTest_svutStatusInfo::testGetStatus ( void )
{
	CPPUNIT_ASSERT_EQUAL(SVUT_STATUS_FAILED,info->getStatus());
}

/*******************  FUNCTION  *********************/
void UnitTest_svutStatusInfo::testGetEntry(void )
{
	info->addEntry("name_test","value_test");
	CPPUNIT_ASSERT_EQUAL(1u,info->getNbEntries());
	CPPUNIT_ASSERT_EQUAL("value_test",info->getEntry("name_test"));
	CPPUNIT_ASSERT_EQUAL("",info->getEntry("unknown"));
}

/*******************  FUNCTION  *********************/
void UnitTest_svutStatusInfo::textSetDebugContext(void )
{
	svutStatusInfoMap lst;
	lst.insert(pair<string,string>("name1","value1"));
	lst.insert(pair<string,string>("name2","value2"));
	lst.insert(pair<string,string>("name3","value3"));

	CPPUNIT_ASSERT_EQUAL(0u,info->getNbEntries());

	info->setContext(lst);

	CPPUNIT_ASSERT_EQUAL(0u,info->getNbEntries());
	CPPUNIT_ASSERT_EQUAL(3u,info->getNbContextEntries());
	CPPUNIT_ASSERT_EQUAL("value1",info->getContextEntry("name1"));
	CPPUNIT_ASSERT_EQUAL("value2",info->getContextEntry("name2"));
	CPPUNIT_ASSERT_EQUAL("value3",info->getContextEntry("name3"));
	CPPUNIT_ASSERT_EQUAL("",info->getContextEntry("unknown"));
	CPPUNIT_ASSERT_EQUAL(3u,lst.size());
}

/*******************  FUNCTION  *********************/
void UnitTest_svutStatusInfo::testGetNbEntries(void )
{
	CPPUNIT_ASSERT_EQUAL(0u,info->getNbEntries());
}

/*******************  FUNCTION  *********************/
void UnitTest_svutStatusInfo::testOperatorEqual(void )
{
	svutStatusInfoMap context;
	context.insert(pair<string,string>("test","value"));
	svutCodeLocation loc(TEST_FILENAME,TEST_METHODE,TEST_LINE);
	this->info->setContext(context);
	svutStatusInfo copy = *this->info;
	CPPUNIT_ASSERT_EQUAL(loc,copy.getLocation());
	CPPUNIT_ASSERT_EQUAL(TEST_MESSAGE,copy.getMessage());
	CPPUNIT_ASSERT_EQUAL(SVUT_STATUS_FAILED,copy.getStatus());
	CPPUNIT_ASSERT_EQUAL(0u,copy.getNbEntries());
	CPPUNIT_ASSERT_EQUAL(1u,copy.getNbContextEntries());
}

/*******************  FUNCTION  *********************/
void UnitTest_svutStatusInfo::testGetStatusName_1(void )
{
	svutStatusInfo info(SVUT_STATUS_SUCCESS,"",SVUT_NO_LOCATION);
	CPPUNIT_ASSERT_EQUAL("SUCCESS",info.getStatusName());
}

/*******************  FUNCTION  *********************/
void UnitTest_svutStatusInfo::testGetStatusName_2(void )
{
	svutStatusInfo info(SVUT_STATUS_FAILED,"",SVUT_NO_LOCATION);
	CPPUNIT_ASSERT_EQUAL("FAILED",info.getStatusName());
}

/*******************  FUNCTION  *********************/
void UnitTest_svutStatusInfo::testGetStatusName_3(void )
{
	svutStatusInfo info(SVUT_STATUS_TODO,"",SVUT_NO_LOCATION);
	CPPUNIT_ASSERT_EQUAL("TODO",info.getStatusName());
}

/*******************  FUNCTION  *********************/
void UnitTest_svutStatusInfo::testGetStatusName_4(void )
{
	svutStatusInfo info(SVUT_STATUS_INDEV,"",SVUT_NO_LOCATION);
	CPPUNIT_ASSERT_EQUAL("INDEV",info.getStatusName());
}

/*******************  FUNCTION  *********************/
void UnitTest_svutStatusInfo::testGetStatusName_5(void )
{
	svutStatusInfo info(SVUT_STATUS_UNKNOWN,"",SVUT_NO_LOCATION);
	CPPUNIT_ASSERT_EQUAL("UNKNOWN",info.getStatusName());
}

/*******************  FUNCTION  *********************/
void UnitTest_svutStatusInfo::testGetStatusName_6(void )
{
	svutStatusInfo info(SVUT_STATUS_SKIPED,"",SVUT_NO_LOCATION);
	CPPUNIT_ASSERT_EQUAL("SKIPED",info.getStatusName());
}

/*******************  FUNCTION  *********************/
void UnitTest_svutStatusInfo::testGetStatusName_static(void )
{
	CPPUNIT_ASSERT_EQUAL("SUCCESS",svutStatusInfo::getStatusName(SVUT_STATUS_SUCCESS));
	CPPUNIT_ASSERT_EQUAL("FAILED",svutStatusInfo::getStatusName(SVUT_STATUS_FAILED));
	CPPUNIT_ASSERT_EQUAL("TODO",svutStatusInfo::getStatusName(SVUT_STATUS_TODO));
	CPPUNIT_ASSERT_EQUAL("INDEV",svutStatusInfo::getStatusName(SVUT_STATUS_INDEV));
	CPPUNIT_ASSERT_EQUAL("UNKNOWN",svutStatusInfo::getStatusName(SVUT_STATUS_UNKNOWN));
	CPPUNIT_ASSERT_EQUAL("SKIPED",svutStatusInfo::getStatusName(SVUT_STATUS_SKIPED));
}

CPPUNIT_TEST_SUITE_REGISTRATION(UnitTest_svutStatusInfo);
