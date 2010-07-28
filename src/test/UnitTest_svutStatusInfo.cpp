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
#include <svutStatusInfo.h>
#include <sstream>

using namespace svUnitTest;
using namespace std;
using namespace CPPUNIT_NS;

/********************  MACROS  **********************/
#define TEST_FILENAME "test.h"
#define TEST_LINE 77
#define TEST_METHODE "void test(void)"
#define TEST_MESSAGE "this is a test"

/********************  CLASSE  **********************/
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

		svutStatusInfo * info;
};

/********************  METHODE  *********************/
void UnitTest_svutStatusInfo::setUp(void)
{
	svutCodeLocation loc(TEST_FILENAME,TEST_METHODE,TEST_LINE);
	this->info = new svutStatusInfo(SVUT_STATUS_FAILED, TEST_MESSAGE,loc);
}

/********************  METHODE  *********************/
void UnitTest_svutStatusInfo::tearDown(void)
{
	delete this->info;
}

/********************  METHODE  *********************/
void UnitTest_svutStatusInfo::testConstructor_1(void )
{
	svutStatusInfo empty;
	CPPUNIT_ASSERT_EQUAL(SVUT_NO_LOCATION,empty.getLocation());
	CPPUNIT_ASSERT_EQUAL("",empty.getMessage());
	CPPUNIT_ASSERT_EQUAL(SVUT_STATUS_SKIPED,empty.getStatus());
	CPPUNIT_ASSERT_EQUAL(0,empty.getNbEntries());
}

/********************  METHODE  *********************/
void UnitTest_svutStatusInfo::testConstructor_2(void )
{
	svutCodeLocation loc(TEST_FILENAME,TEST_METHODE,TEST_LINE);
	svutStatusInfo copy(SVUT_STATUS_SUCCESS,TEST_MESSAGE,loc);
	CPPUNIT_ASSERT_EQUAL(loc,copy.getLocation());
	CPPUNIT_ASSERT_EQUAL(TEST_MESSAGE,copy.getMessage());
	CPPUNIT_ASSERT_EQUAL(SVUT_STATUS_SUCCESS,copy.getStatus());
	CPPUNIT_ASSERT_EQUAL(0,copy.getNbEntries());
}

/********************  METHODE  *********************/
void UnitTest_svutStatusInfo::testAddEntry ( void )
{
	CPPUNIT_ASSERT_EQUAL(0U,info->getEntries().size());
	info->addEntry("name","value");
	CPPUNIT_ASSERT_EQUAL(1U,info->getEntries().size());
	CPPUNIT_ASSERT_EQUAL("name",info->getEntries().begin()->first);
	CPPUNIT_ASSERT_EQUAL("value",info->getEntries().begin()->second);
}

/********************  METHODE  *********************/
void UnitTest_svutStatusInfo::testFormatEntries ( void )
{
	stringstream str;
	CPPUNIT_ASSERT_EQUAL(0U,info->getEntries().size());
	info->addEntry("name_test","value_test");
	info->addEntry("name_test2","value_test2");
	info->formatEntries(str,"<",",",">");
	CPPUNIT_ASSERT_EQUAL("<name_test,value_test><name_test2,value_test2>",str.str());
}

/********************  METHODE  *********************/
void UnitTest_svutStatusInfo::testGetLocation ( void )
{
	svutCodeLocation loc(TEST_FILENAME,TEST_METHODE,TEST_LINE);
	CPPUNIT_ASSERT_EQUAL(loc,info->getLocation());
}

/********************  METHODE  *********************/
void UnitTest_svutStatusInfo::testGetMessage ( void )
{
	CPPUNIT_ASSERT_EQUAL(TEST_MESSAGE,info->getMessage());
}

/********************  METHODE  *********************/
void UnitTest_svutStatusInfo::testGetStatus ( void )
{
	CPPUNIT_ASSERT_EQUAL(SVUT_STATUS_FAILED,info->getStatus());
}

/********************  METHODE  *********************/
void UnitTest_svutStatusInfo::testGetEntry(void )
{
	info->addEntry("name_test","value_test");
	CPPUNIT_ASSERT_EQUAL("value_test",info->getEntry("name_test"));
	CPPUNIT_ASSERT_EQUAL("",info->getEntry("unknown"));
}

/********************  METHODE  *********************/
void UnitTest_svutStatusInfo::testGetNbEntries(void )
{
	CPPUNIT_ASSERT_EQUAL(0,info->getNbEntries());
}

/********************  METHODE  *********************/
void UnitTest_svutStatusInfo::testOperatorEqual(void )
{
	svutCodeLocation loc(TEST_FILENAME,TEST_METHODE,TEST_LINE);
	svutStatusInfo copy = *this->info;
	CPPUNIT_ASSERT_EQUAL(loc,copy.getLocation());
	CPPUNIT_ASSERT_EQUAL(TEST_MESSAGE,copy.getMessage());
	CPPUNIT_ASSERT_EQUAL(SVUT_STATUS_FAILED,copy.getStatus());
	CPPUNIT_ASSERT_EQUAL(0,copy.getNbEntries());
}


CPPUNIT_TEST_SUITE_REGISTRATION(UnitTest_svutStatusInfo);
