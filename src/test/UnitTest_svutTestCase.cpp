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
#include <svutTestCase.h>
#include "UnitTestMockTestCase.h"

using namespace std;
using namespace svUnitTest;
using namespace CPPUNIT_NS;

/********************  CLASSE  **********************/
class UnitTest_svutTestCase : public TestCase
{
	CPPUNIT_TEST_SUITE(UnitTest_svutTestCase);
	CPPUNIT_TEST(testSetUp);
	CPPUNIT_TEST(testTearDown);
	CPPUNIT_TEST(testRegisterTestMethod);
	CPPUNIT_TEST(testGetName);
	CPPUNIT_TEST(testGetMethods_false);
	CPPUNIT_TEST(testGetMethods_true);
	CPPUNIT_TEST(testGetNbTests);
	CPPUNIT_TEST(testSetAutodetected);
	CPPUNIT_TEST(testIsAutodetected);
	CPPUNIT_TEST(testRunMethod);
	CPPUNIT_TEST(testFailIsTodo);
	CPPUNIT_TEST(testRunTestCase);
	CPPUNIT_TEST_SUITE_END();

	public:
		void setUp(void);
		void tearDown(void);

	protected:
		void testSetUp(void);
		void testTearDown(void);
		void testRegisterTestMethod(void);
		void testGetName(void);
		void testGetMethods_false(void);
		void testGetMethods_true(void);
		void testGetNbTests(void);
		void testSetAutodetected(void);
		void testIsAutodetected(void);
		void testRunMethod(void);
		void testFailIsTodo(void);
		void testRunTestCase(void);

		UnitTestMockTestCase * obj;
};

/********************  METHODE  *********************/
static std::ostream & operator << (std::ostream & out,const std::list<std::string> & lst)
{
	for (std::list<std::string>::const_iterator it = lst.begin() ; it != lst.end() ; ++it)
	{
		if (it != lst.begin())
			out << " ; ";
		out << *it;
	}
	return out;
}

/********************  METHODE  *********************/
void UnitTest_svutTestCase::setUp(void)
{
	obj = new UnitTestMockTestCase;
}

/********************  METHODE  *********************/
void UnitTest_svutTestCase::tearDown(void)
{
	delete obj;
}

/********************  METHODE  *********************/
void UnitTest_svutTestCase::testSetUp(void)
{
	CPPUNIT_ASSERT_EQUAL(0,obj->calls);
	CPPUNIT_ASSERT_EQUAL(-1,obj->setup);
	obj->setUp();
	CPPUNIT_ASSERT_EQUAL(1,obj->calls);
	CPPUNIT_ASSERT_EQUAL(0,obj->setup);
}

/********************  METHODE  *********************/
void UnitTest_svutTestCase::testTearDown(void)
{
	CPPUNIT_ASSERT_EQUAL(0,obj->calls);
	CPPUNIT_ASSERT_EQUAL(-1,obj->teardown);
	obj->tearDown();
	CPPUNIT_ASSERT_EQUAL(1,obj->calls);
	CPPUNIT_ASSERT_EQUAL(0,obj->teardown);
}

/********************  METHODE  *********************/
void UnitTest_svutTestCase::testRegisterTestMethod(void)
{
	CPPUNIT_ASSERT_EQUAL(2,obj->getNbTests());
	std::list<std::string> lst;
	lst.push_back("test1");
	lst.push_back("test3");
	CPPUNIT_ASSERT_EQUAL(lst,obj->getTestMethods(false));
	obj->testRegister();
	CPPUNIT_ASSERT_EQUAL(3,obj->getNbTests());
	std::list<std::string> lst2;
	lst2.push_back("test1");
	lst2.push_back("test3");
	lst2.push_back("test2");
	CPPUNIT_ASSERT_EQUAL(lst2,obj->getTestMethods(false));
}

/********************  METHODE  *********************/
void UnitTest_svutTestCase::testGetName(void)
{
	CPPUNIT_ASSERT_EQUAL("MyTest",obj->getName());
}

/********************  METHODE  *********************/
void UnitTest_svutTestCase::testGetMethods_false(void)
{
	std::list<std::string> lst;
	lst.push_back("test1");
	lst.push_back("test3");
	CPPUNIT_ASSERT_EQUAL(lst,obj->getTestMethods(false));
}

/********************  METHODE  *********************/
void UnitTest_svutTestCase::testGetMethods_true(void)
{
	std::list<std::string> lst;
	lst.push_back("MyTest::test1");
	lst.push_back("MyTest::test3");
	CPPUNIT_ASSERT_EQUAL(lst,obj->getTestMethods(true));
}

/********************  METHODE  *********************/
void UnitTest_svutTestCase::testGetNbTests(void)
{
	CPPUNIT_ASSERT_EQUAL(2,obj->getNbTests());
}

/********************  METHODE  *********************/
void UnitTest_svutTestCase::testSetAutodetected(void)
{
	CPPUNIT_ASSERT_EQUAL(false,obj->isAutodetected());
	obj->setAutodetected();
	CPPUNIT_ASSERT_EQUAL(true,obj->isAutodetected());
}

/********************  METHODE  *********************/
void UnitTest_svutTestCase::testIsAutodetected(void)
{
	CPPUNIT_ASSERT_EQUAL(false,obj->isAutodetected());
}

/********************  METHODE  *********************/
void UnitTest_svutTestCase::testRunMethod(void)
{
	CPPUNIT_ASSERT_EQUAL(0,obj->calls);
	CPPUNIT_ASSERT_EQUAL(-1,obj->setup);
	CPPUNIT_ASSERT_EQUAL(-1,obj->teardown);
	CPPUNIT_ASSERT_EQUAL(-1,obj->t1);
	obj->testRunMeth();
	CPPUNIT_ASSERT_EQUAL(3,obj->calls);
	CPPUNIT_ASSERT_EQUAL(0,obj->setup);
	CPPUNIT_ASSERT_EQUAL(2,obj->teardown);
	CPPUNIT_ASSERT_EQUAL(1,obj->t1);
}

/********************  METHODE  *********************/
void UnitTest_svutTestCase::testFailIsTodo(void)
{
	CPPUNIT_FAIL("todo");
}

/********************  METHODE  *********************/
void UnitTest_svutTestCase::testRunTestCase(void )
{
	CPPUNIT_FAIL("todo");
}


CPPUNIT_TEST_SUITE_REGISTRATION(UnitTest_svutTestCase);
