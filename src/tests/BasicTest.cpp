/*****************************************************
             PROJECT  : svUnitTest
             VERSION  : 0.5.0-dev
             DATE     : 11/2012
             AUTHOR   : Valat Sébastien
             LICENSE  : CeCILL-C
*****************************************************/

/********************  HEADERS  *********************/
#include <iostream>
#include <cppunit/TestCase.h>
#include <cppunit/extensions/TestFactoryRegistry.h>
#include <cppunit/extensions/HelperMacros.h>

/**********************  USING  *********************/
using namespace CPPUNIT_NS;

/*********************  CLASS  **********************/
class BasicTest : public TestCase
{
	CPPUNIT_TEST_SUITE(BasicTest);
	CPPUNIT_TEST(testHelloWorld);
	CPPUNIT_TEST_SUITE_END();

	public:
		void setUp(void);
		void tearDown(void);

	protected:
		void testHelloWorld(void);
};

/*******************  FUNCTION  *********************/
void BasicTest::setUp(void)
{
}

/*******************  FUNCTION  *********************/
void BasicTest::tearDown(void)
{
}

/*******************  FUNCTION  *********************/
void BasicTest::testHelloWorld(void)
{
}

CPPUNIT_TEST_SUITE_REGISTRATION(BasicTest);
