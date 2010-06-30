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

using namespace CPPUNIT_NS;

/********************  CLASSE  **********************/
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

/********************  METHODE  *********************/
void BasicTest::setUp(void)
{
}

/********************  METHODE  *********************/
void BasicTest::tearDown(void)
{
}

/********************  METHODE  *********************/
void BasicTest::testHelloWorld(void)
{
}

CPPUNIT_TEST_SUITE_REGISTRATION(BasicTest);
