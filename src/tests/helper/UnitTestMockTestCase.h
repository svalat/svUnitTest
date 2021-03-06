/*****************************************************
             PROJECT  : svUnitTest
             VERSION  : 0.5.0-dev
             DATE     : 11/2012
             AUTHOR   : Valat Sébastien
             LICENSE  : CeCILL-C 2.1
*****************************************************/

#ifndef UNIT_TEST_CASE_MOCK_TEST_CASE_HEADER
#define UNIT_TEST_CASE_MOCK_TEST_CASE_HEADER

/********************  HEADERS  *********************/
#include <svutTestCase.h>

/*********************  CLASS  **********************/
class UnitTestMockTestCase : public svUnitTest::svutTestCase
{
	public:
		UnitTestMockTestCase(void);
		virtual void setUp(void);
		virtual void tearDown(void);
		void test1(void);
		void test2(void);
		void test3(void);
		void testRegister(void);
		void testRunMeth(void);

		int calls;
		int setup;
		int teardown;
		int t1;
		int t2;
		int t3;
};

#endif
