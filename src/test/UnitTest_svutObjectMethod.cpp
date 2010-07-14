/*****************************************************
             PROJECT  : svUnitTest
             VERSION  : 0.0.2
             DATE     : 06/2010
             AUTHOR   : Valat Sébastien
             LICENSE  : CeCILL-C
*****************************************************/

/********************  HEADERS  *********************/
#include <iostream>
#include <cppunit/TestCase.h>
#include <cppunit/extensions/TestFactoryRegistry.h>
#include <cppunit/extensions/HelperMacros.h>
#include <svutObjectMethod.h>

using namespace CppUnit;
using namespace svUnitTest;

/********************  CLASSE  **********************/
class SimpleObject
{
	public:
		SimpleObject(int value = 20) {this->value = value;};
		void clear(void) {this->value = 0;};
		int getValue(void) {return this->value; };
	private:
		int value;
};

/********************  CLASSE  **********************/
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
		svutObjectMethodGeneric<SimpleObject> * caller;
		SimpleObject obj;
};

/********************  METHODE  *********************/
void UnitTest_svutObjectMethod::setUp(void)
{
	caller = new svutObjectMethodGeneric<SimpleObject>(&obj,&SimpleObject::clear);
}

/********************  METHODE  *********************/
void UnitTest_svutObjectMethod::tearDown(void)
{
	delete caller;
}

/********************  METHODE  *********************/
void UnitTest_svutObjectMethod::testConstructor(void)
{
}

/********************  METHODE  *********************/
void UnitTest_svutObjectMethod::testCall(void)
{
	CPPUNIT_ASSERT_EQUAL(20,obj.getValue());
	caller->call();
	CPPUNIT_ASSERT_EQUAL(0,obj.getValue());
}

CPPUNIT_TEST_SUITE_REGISTRATION(UnitTest_svutObjectMethod);

