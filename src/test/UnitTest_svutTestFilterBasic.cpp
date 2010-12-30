/*****************************************************
             PROJECT  : svUnitTest
             VERSION  : 0.0.2
             DATE     : 12/2010
             AUTHOR   : Valat Sébastien
             LICENSE  : CeCILL-C
*****************************************************/

/********************  HEADERS  *********************/
#include <iostream>
#include <cppunit/TestCase.h>
#include <cppunit/extensions/TestFactoryRegistry.h>
#include <cppunit/extensions/HelperMacros.h>
#include <svutTestFilterBasic.h>
#include "UnitTestExtra.h"

using namespace CPPUNIT_NS;
using namespace svUnitTest;

/********************  CLASSE  **********************/
class UnitTest_svutTestFilterBasic : public TestCase
{
	CPPUNIT_TEST_SUITE(UnitTest_svutTestFilterBasic);
	CPPUNIT_TEST(accept_StringString);
	CPPUNIT_TEST(accept_String);
	CPPUNIT_TEST(addAccepted);
	CPPUNIT_TEST(testClear);
	CPPUNIT_TEST_SUITE_END();

	public:
		void setUp(void);
		void tearDown(void);

	protected:
		void accept_StringString(void);
		void accept_String(void);
		void addAccepted(void);
		void testClear(void);

		svutTestFilterBasic * obj;
};

/*********************  METHODE  ********************/
void UnitTest_svutTestFilterBasic::setUp(void)
{
	this->obj = new svUnitTest::svutTestFilterBasic();
	this->obj->addAccepted("case1","function1");
	this->obj->addAccepted("case2","");
	this->obj->addAccepted("","function3");
}

/*********************  METHODE  ********************/
void UnitTest_svutTestFilterBasic::tearDown(void)
{
	delete this->obj;
}

/*********************  METHODE  ********************/
void UnitTest_svutTestFilterBasic::accept_StringString(void)
{
	CPPUNIT_ASSERT(obj->accept("case1","function1"));
	CPPUNIT_ASSERT(!obj->accept("case1","function11"));
	CPPUNIT_ASSERT(obj->accept("case2","function12"));
	CPPUNIT_ASSERT(obj->accept("case3","function3"));
	CPPUNIT_ASSERT(obj->accept("case1","function3"));
}

/*********************  METHODE  ********************/
void UnitTest_svutTestFilterBasic::accept_String(void)
{
	svutTestFilterBasic filter;
	filter.addAccepted("case1","");
	filter.addAccepted("case2","");
	CPPUNIT_ASSERT(filter.accept("case1"));
	CPPUNIT_ASSERT(filter.accept("case2"));
	CPPUNIT_ASSERT(!filter.accept("case3"));
}

/*********************  METHODE  ********************/
void UnitTest_svutTestFilterBasic::addAccepted(void)
{
	CPPUNIT_ASSERT(!obj->accept("case4","function4"));
	obj->addAccepted("case4","function4");
	CPPUNIT_ASSERT(obj->accept("case4","function4"));
}

/*********************  METHODE  ********************/
void UnitTest_svutTestFilterBasic::testClear(void )
{
	CPPUNIT_ASSERT(!obj->accept("case4","function4"));
	obj->clear();
	CPPUNIT_ASSERT(obj->accept("case4","function4"));
}

CPPUNIT_TEST_SUITE_REGISTRATION(UnitTest_svutTestFilterBasic);
