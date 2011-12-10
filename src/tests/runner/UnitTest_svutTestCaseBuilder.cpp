/*****************************************************
             PROJECT  : svUnitTest
             VERSION  : 0.3.0
             DATE     : 05/2011
             AUTHOR   : Valat Sébastien
             LICENSE  : CeCILL-C
*****************************************************/

/********************  HEADERS  *********************/
#include <svutTestCaseBuilder.h>
#include "UnitTestMockTestCase2.h"
#include "UnitTestExtra.h"

/**********************  USING  *********************/
using namespace CPPUNIT_NS;
using namespace svUnitTest;

/*********************  CLASS  **********************/
class UnitTest_svutTestCaseBuilder : public TestCase
{
	CPPUNIT_TEST_SUITE(UnitTest_svutTestCaseBuilder);
	CPPUNIT_TEST(testBuild);
	CPPUNIT_TEST_SUITE_END();

	public:
		void setUp(void);
		void tearDown(void);

	protected:
		void testBuild(void);
		svutTestCaseBuilder * builder;
};

/*******************  FUNCTION  *********************/
void UnitTest_svutTestCaseBuilder::setUp(void)
{
	builder = new svutTestCaseBuilderGeneric<UnitTestMockTestCase2>();
}

/*******************  FUNCTION  *********************/
void UnitTest_svutTestCaseBuilder::tearDown(void)
{
	delete builder;
}

/*******************  FUNCTION  *********************/
void UnitTest_svutTestCaseBuilder::testBuild(void )
{
	svutTestCase * test = builder->build();
	CPPUNIT_ASSERT(test!=NULL);
	CPPUNIT_ASSERT_EQUAL("UnitTestMockTestCase2",test->getName());
	delete test;
}

CPPUNIT_TEST_SUITE_REGISTRATION(UnitTest_svutTestCaseBuilder);
