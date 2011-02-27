/*****************************************************
             PROJECT  : svUnitTest
             VERSION  : 0.2.0
             DATE     : 02/2011
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

/**********************  USING  *********************/
using namespace svUnitTest;
using namespace CPPUNIT_NS;

/*********************  CLASS  **********************/
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

/*******************  FUNCTION  *********************/
void UnitTest_svutException::setUp(void)
{
	exc = new svutException("message");
}

/*******************  FUNCTION  *********************/
void UnitTest_svutException::tearDown(void)
{
	delete exc;
}

/*******************  FUNCTION  *********************/
void UnitTest_svutException::testConstructor(void)
{
	svutException obj;
	CPPUNIT_ASSERT_EQUAL("",obj.getMessage());
}

/*******************  FUNCTION  *********************/
void UnitTest_svutException::testConstructor_str(void)
{
	svutException obj("message");
	CPPUNIT_ASSERT_EQUAL("message",obj.getMessage());
}

/*******************  FUNCTION  *********************/
void UnitTest_svutException::testWhat(void)
{
	CPPUNIT_ASSERT(exc->what() != NULL);
	CPPUNIT_ASSERT(strcmp("message",exc->what()) == 0);
}

/*******************  FUNCTION  *********************/
void UnitTest_svutException::testGetMessage(void)
{
	CPPUNIT_ASSERT_EQUAL("message",exc->getMessage());
}

/*******************  FUNCTION  *********************/
void UnitTest_svutException::testExInternalError(void )
{
	svutExInternalError error("test");
	CPPUNIT_ASSERT_EQUAL("test",error.getMessage());
}


CPPUNIT_TEST_SUITE_REGISTRATION(UnitTest_svutException);
