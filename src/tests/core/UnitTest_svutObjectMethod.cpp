/*****************************************************
             PROJECT  : svUnitTest
             VERSION  : 0.5.0-dev
             DATE     : 11/2012
             AUTHOR   : Valat Sébastien
             LICENSE  : CeCILL-C 2.1
*****************************************************/

/********************  HEADERS  *********************/
#include <iostream>
#include "UnitTestExtra.h"
#include <svutObjectMethod.h>

/**********************  USING  *********************/
using namespace CPPUNIT_NS;
using namespace svUnitTest;

/*********************  CLASS  **********************/
class SimpleObject
{
	public:
		SimpleObject(int value = 20) {this->value = value;}
		virtual ~SimpleObject(void) {};
		virtual void clear(void) {this->value = 0;}
		int getValue(void) {return this->value; }
	protected:
		int value;
};

/*********************  CLASS  **********************/
class SimpleObjectV2 : public SimpleObject
{
	public:
		virtual void clear(void) {this->value = 1;}
};

/*********************  CLASS  **********************/
class UnitTest_svutObjectMethod : public TestCase
{
	CPPUNIT_TEST_SUITE(UnitTest_svutObjectMethod);
	CPPUNIT_TEST(testConstructor);
	CPPUNIT_TEST(testCall);
	CPPUNIT_TEST_SUITE_END();

	public:
		void setUp(void);
		void tearDown(void);

	protected:
		void testConstructor(void);
		void testCall(void);
		void testCallOverride(void);
		svutObjectMethodGeneric<SimpleObject> * caller;
		SimpleObject obj;
};

/*******************  FUNCTION  *********************/
void UnitTest_svutObjectMethod::setUp(void)
{
	caller = new svutObjectMethodGeneric<SimpleObject>(&obj,&SimpleObject::clear);
}

/*******************  FUNCTION  *********************/
void UnitTest_svutObjectMethod::tearDown(void)
{
	delete caller;
}

/*******************  FUNCTION  *********************/
void UnitTest_svutObjectMethod::testConstructor(void)
{
}

/*******************  FUNCTION  *********************/
void UnitTest_svutObjectMethod::testCall(void)
{
	CPPUNIT_ASSERT_EQUAL(20,obj.getValue());
	caller->call();
	CPPUNIT_ASSERT_EQUAL(0,obj.getValue());
}

/*******************  FUNCTION  *********************/
void UnitTest_svutObjectMethod::testCallOverride(void )
{
	SimpleObjectV2 obj2;
	svutObjectMethodGeneric<SimpleObject> caller2(&obj2,&SimpleObject::clear);
	
	CPPUNIT_ASSERT_EQUAL(20,obj.getValue());
	caller2.call();
	CPPUNIT_ASSERT_EQUAL(1,obj.getValue());
}

CPPUNIT_TEST_SUITE_REGISTRATION(UnitTest_svutObjectMethod);

