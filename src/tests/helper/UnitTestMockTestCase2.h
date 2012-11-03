/*****************************************************
             PROJECT  : svUnitTest
             VERSION  : 0.5.0-dev
             DATE     : 11/2012
             AUTHOR   : Valat Sébastien
             LICENSE  : CeCILL-C
*****************************************************/

#ifndef UNIT_TEST_CASE_MOCK_TEST_CASE_HEADER
#define UNIT_TEST_CASE_MOCK_TEST_CASE_HEADER

/********************  HEADERS  *********************/
#include <svutTestCase.h>
#include <svutAssert.h>

/*********************  CLASS  **********************/
class UnitTestMockTestCase2 : public svUnitTest::svutTestCase
{
	public:
		enum UnitTestMockFlags
		{
			REGISTER_SUCCESS,
			REGISTER_FAILURE,
			REGISTER_TODO,
			REGISTER_INDEV,
			REGISTER_UNKNOWN_1,
			REGISTER_UNKNOWN_2,
			REGISTER_FAIL_IS_TODO_1,
			REGISTER_FAIL_IS_TODO_2,
			REGISTER_FAIL_IS_TODO_3,
			REGISTER_SUCCESS_IS_INDEV,
			REGISTER_DEBUG_CONTEXT,
			REGISTER_ALL
		};
		
		UnitTestMockTestCase2(void);
		virtual void setUp(void);
		virtual void tearDown(void);

		void testSuccess(void);
		void testFailure(void);
		void testTodo(void);
		void testIndev(void);
		void testUnknown_1(void);
		void testUnknown_2(void);
		void testFailIsTodo_1(void);
		void testFailIsTodo_2(void);
		void testFailIsTodo_3(void);
		void testSuccessIsIndev(void);
		void testDebugContext(void);

		void useTests(UnitTestMockFlags flags);
};

#endif
