/*****************************************************
             PROJECT  : svUnitTest
             VERSION  : 0.3.0
             DATE     : 05/2011
             AUTHOR   : Valat Sébastien
             LICENSE  : CeCILL-C
*****************************************************/

/********************  HEADERS  *********************/
#include "UnitTestExtra.h"
#include <svutTestMethod.h>
#include <svutTestCase.h>

/**********************  USING  *********************/
using namespace std;
using namespace svUnitTest;
using namespace CPPUNIT_NS;

/*********************  CLASS  **********************/
class UnitTest_svutTestMethod : public TestCase
{
	CPPUNIT_TEST_SUITE(UnitTest_svutTestMethod);
	CPPUNIT_TEST(testGetName);
	CPPUNIT_TEST(testGetLocation);
	CPPUNIT_TEST(testCall);
	CPPUNIT_TEST(testUsageOfTypeof);
	CPPUNIT_TEST_SUITE_END();

	public:
		UnitTest_svutTestMethod(void);
		void setUp(void);
		void tearDown(void);

	protected:
		void testGetName(void);
		void testGetLocation(void);
		void testCall(void);
		void testUsageOfTypeof(void);

		void methToCall(void);
		svutTestMethod * meth;
		bool called;
		svutCodeLocation loc;
};

/*******************  FUNCTION  *********************/
UnitTest_svutTestMethod::UnitTest_svutTestMethod()
	:loc("test.c","testMeth",33)
{
	called = false;
	meth = NULL;
}

/*******************  FUNCTION  *********************/
void UnitTest_svutTestMethod::setUp(void)
{
	called = false;
	meth = new svutTestMethod("theTest",
		new svutObjectMethodGeneric<UnitTest_svutTestMethod>(this,&UnitTest_svutTestMethod::methToCall),
		loc);
}

/*******************  FUNCTION  *********************/
void UnitTest_svutTestMethod::tearDown(void)
{
	delete meth;
}

/*******************  FUNCTION  *********************/
void UnitTest_svutTestMethod::testGetName(void )
{
	CPPUNIT_ASSERT_EQUAL("theTest",meth->getName());
}

/*******************  FUNCTION  *********************/
void UnitTest_svutTestMethod::testGetLocation(void )
{
	CPPUNIT_ASSERT_EQUAL(loc,meth->getLocation());
}

/*******************  FUNCTION  *********************/
void UnitTest_svutTestMethod::testCall(void )
{
	CPPUNIT_ASSERT_EQUAL(false,called);
	meth->call();
	CPPUNIT_ASSERT_EQUAL(true,called);
}

/*******************  FUNCTION  *********************/
void UnitTest_svutTestMethod::methToCall(void )
{
	called = true;
}

/*******************  FUNCTION  *********************/
void UnitTest_svutTestMethod::testUsageOfTypeof(void )
{
	svutTestMethod * obj;
	typedef SVUT_TYPEOF(this) CURRENT_CLASS;
	obj = new svutTestMethod("theTest",
		new svutObjectMethodGeneric<UnitTest_svutTestMethod>(this,&CURRENT_CLASS::methToCall),
		loc);
	CPPUNIT_ASSERT_EQUAL(false,called);
	obj->call();
	CPPUNIT_ASSERT_EQUAL(true,called);
	delete obj;
}

CPPUNIT_TEST_SUITE_REGISTRATION(UnitTest_svutTestMethod);
