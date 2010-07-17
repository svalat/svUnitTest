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
#include <svutException.h>

using namespace svUnitTest;
using namespace CPPUNIT_NS;

/********************  CLASSE  **********************/
class UnitTest_svutException : public TestCase
{
	CPPUNIT_TEST_SUITE(UnitTest_svutException);
	CPPUNIT_TEST(testConstructor);
	CPPUNIT_TEST(testConstructor_str);
	CPPUNIT_TEST(testWhat);
	CPPUNIT_TEST(testGetMessage);
	CPPUNIT_TEST(testExInternalError);
	CPPUNIT_TEST_SUITE_END();

	public:
		void setUp(void);
		void tearDown(void);

	protected:
		void testConstructor(void);
		void testConstructor_str(void);
		void testWhat(void);
		void testGetMessage(void);
		void testExInternalError(void);
		
		svutException * exc;
};

/********************  METHODE  *********************/
void UnitTest_svutException::setUp(void)
{
	exc = new svutException("message");
}

/********************  METHODE  *********************/
void UnitTest_svutException::tearDown(void)
{
	delete exc;
}

/********************  METHODE  *********************/
void UnitTest_svutException::testConstructor(void)
{
	svutException obj;
	CPPUNIT_ASSERT_EQUAL("",obj.getMessage());
}

/********************  METHODE  *********************/
void UnitTest_svutException::testConstructor_str(void)
{
	svutException obj("message");
	CPPUNIT_ASSERT_EQUAL("message",obj.getMessage());
}

/********************  METHODE  *********************/
void UnitTest_svutException::testWhat(void)
{
	CPPUNIT_ASSERT(exc->what() != NULL);
	CPPUNIT_ASSERT(strcmp("message",exc->what()) == 0);
}

/********************  METHODE  *********************/
void UnitTest_svutException::testGetMessage(void)
{
	CPPUNIT_ASSERT_EQUAL("message",exc->getMessage());
}

/********************  METHODE  *********************/
void UnitTest_svutException::testExInternalError(void )
{
	svutExInternalError error("test");
	CPPUNIT_ASSERT_EQUAL("test",error.getMessage());
}


CPPUNIT_TEST_SUITE_REGISTRATION(UnitTest_svutException);
