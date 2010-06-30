/*****************************************************
             PROJECT  : svmath
             VERSION  : 0.0.1
             DATE     : 06/2010
             AUTHOR   : Valat Sébastien
             LICENSE  : CeCILL-C
*****************************************************/
#include <iostream>
#include <cppunit/TestCase.h>
#include <cppunit/extensions/TestFactoryRegistry.h>
#include <cppunit/extensions/HelperMacros.h>

using namespace CPPUNIT_NS;

class BasicTest : public TestCase
{
	CPPUNIT_TEST_SUITE(BasicTest);
	CPPUNIT_TEST(testHelloWorld);
	CPPUNIT_TEST_SUITE_END();

	public:
		void setUp(void) {}
		void tearDown(void) {} 

	protected:
		void testHelloWorld(void) { }
};

CPPUNIT_TEST_SUITE_REGISTRATION(BasicTest);
