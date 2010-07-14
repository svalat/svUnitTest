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
#include <svutTestMethod.h>

using namespace std;
using namespace svUnitTest;
using namespace CPPUNIT_NS;

/********************  CLASSE  **********************/
class UnitTest_svutTestMethod : public TestCase
{
	CPPUNIT_TEST_SUITE(UnitTest_svutTestMethod);
	CPPUNIT_TEST(testGetName);
	CPPUNIT_TEST(testGetLocation);
	CPPUNIT_TEST(testCall);
	CPPUNIT_TEST_SUITE_END();

	public:
		UnitTest_svutTestMethod(void);
		void setUp(void);
		void tearDown(void);

	protected:
		void testGetName(void);
		void testGetLocation(void);
		void testCall(void);

		void methToCall(void);
		svutTestMethod * meth;
		bool called;
		svutCodeLocation loc;
};

/********************  METHODE  *********************/
UnitTest_svutTestMethod::UnitTest_svutTestMethod()
	:loc("test.c","testMeth",33)
{
}

/********************  METHODE  *********************/
void UnitTest_svutTestMethod::setUp(void)
{
	called = false;
	meth = new svutTestMethod("theTest",
		new svutObjectMethodeGeneric<UnitTest_svutTestMethod>(this,&UnitTest_svutTestMethod::methToCall),
		loc);
}

/********************  METHODE  *********************/
void UnitTest_svutTestMethod::tearDown(void)
{
	delete meth;
}

/********************  METHODE  *********************/
void UnitTest_svutTestMethod::testGetName(void )
{
	CPPUNIT_ASSERT_EQUAL("theTest",meth->getName());
}

/********************  METHODE  *********************/
void UnitTest_svutTestMethod::testGetLocation(void )
{
	CPPUNIT_ASSERT_EQUAL(loc,meth->getLocation());
}

/********************  METHODE  *********************/
void UnitTest_svutTestMethod::testCall(void )
{
	CPPUNIT_ASSERT_EQUAL(false,called);
	meth->call();
	CPPUNIT_ASSERT_EQUAL(true,called);
}

/********************  METHODE  *********************/
void UnitTest_svutTestMethod::methToCall(void )
{
	called = true;
}



CPPUNIT_TEST_SUITE_REGISTRATION(UnitTest_svutTestMethod);