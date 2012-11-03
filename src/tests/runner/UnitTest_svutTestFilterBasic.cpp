/*****************************************************
             PROJECT  : svUnitTest
             VERSION  : 0.5.0-dev
             DATE     : 11/2012
             AUTHOR   : Valat Sébastien
             LICENSE  : CeCILL-C
*****************************************************/

/********************  HEADERS  *********************/
#include <svutTestFilterBasic.h>
#include "UnitTestExtra.h"

/**********************  USING  *********************/
using namespace CPPUNIT_NS;
using namespace svUnitTest;

/*********************  CLASS  **********************/
class UnitTest_svutTestFilterBasic : public TestCase
{
	CPPUNIT_TEST_SUITE(UnitTest_svutTestFilterBasic);
	CPPUNIT_TEST(testAccept_StringString);
	CPPUNIT_TEST(testAccept_String);
	CPPUNIT_TEST(testAddAccepted);
	CPPUNIT_TEST(testClear);
	CPPUNIT_TEST_SUITE_END();

	public:
		void setUp(void);
		void tearDown(void);

	protected:
		void testAccept_StringString(void);
		void testAccept_String(void);
		void testAddAccepted(void);
		void testClear(void);

		svutTestFilterBasic * obj;
};

/*******************  FUNCTION  *********************/
void UnitTest_svutTestFilterBasic::setUp(void)
{
	this->obj = new svUnitTest::svutTestFilterBasic();
	this->obj->addAccepted("case1","function1");
	this->obj->addAccepted("case2","");
	this->obj->addAccepted("","function3");
}

/*******************  FUNCTION  *********************/
void UnitTest_svutTestFilterBasic::tearDown(void)
{
	delete this->obj;
}

/*******************  FUNCTION  *********************/
void UnitTest_svutTestFilterBasic::testAccept_StringString(void)
{
	CPPUNIT_ASSERT(obj->accept("case1","function1"));
	CPPUNIT_ASSERT(!obj->accept("case1","function11"));
	CPPUNIT_ASSERT(obj->accept("case2","function12"));
	CPPUNIT_ASSERT(obj->accept("case3","function3"));
	CPPUNIT_ASSERT(obj->accept("case1","function3"));
}

/*******************  FUNCTION  *********************/
void UnitTest_svutTestFilterBasic::testAccept_String(void)
{
	svutTestFilterBasic filter;
	filter.addAccepted("case1","");
	filter.addAccepted("case2","");
	CPPUNIT_ASSERT(filter.accept("case1"));
	CPPUNIT_ASSERT(filter.accept("case2"));
	CPPUNIT_ASSERT(!filter.accept("case3"));
}

/*******************  FUNCTION  *********************/
void UnitTest_svutTestFilterBasic::testAddAccepted(void)
{
	CPPUNIT_ASSERT(!obj->accept("case4","function4"));
	obj->addAccepted("case4","function4");
	CPPUNIT_ASSERT(obj->accept("case4","function4"));
}

/*******************  FUNCTION  *********************/
void UnitTest_svutTestFilterBasic::testClear(void )
{
	CPPUNIT_ASSERT(!obj->accept("case4","function4"));
	obj->clear();
	CPPUNIT_ASSERT(obj->accept("case4","function4"));
}

CPPUNIT_TEST_SUITE_REGISTRATION(UnitTest_svutTestFilterBasic);
