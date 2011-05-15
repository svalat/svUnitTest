/*****************************************************
             PROJECT  : svUnitTest
             VERSION  : 0.3.0
             DATE     : 05/2011
             AUTHOR   : Valat Sébastien
             LICENSE  : CeCILL-C
*****************************************************/

#ifndef IUNIT_TEST_RESULT_FORMATTER
#define IUNIT_TEST_RESULT_FORMATTER

/*********************  CLASS  **********************/
class IUnitTest_ResultFormatter
{
	public:
		virtual void testOpenOutput(void) = 0;
		virtual void testCloseOutput(void) = 0;
		virtual void testOpenTestCase(void) = 0;
		virtual void testCloseTestCase(void) = 0;
		virtual void testOpenTestMethod(void) = 0;
		virtual void testCloseTestMethod_success_1(void) = 0;
		virtual void testCloseTestMethod_success_2(void) = 0;
		virtual void testCloseTestMethod_fullname(void) = 0;
		virtual void testCloseTestMethod_todo(void) = 0;
		virtual void testCloseTestMethod_indev(void) = 0;
		virtual void testCloseTestMethod_skiped(void) = 0;
		virtual void testCloseTestMethod_unknown_1(void) = 0;
		virtual void testCloseTestMethod_unknown_2(void) = 0;
		virtual void testCloseTestMethod_unknown_3(void) = 0;
		virtual void testCloseTestMethod_failed_1(void) = 0;
		virtual void testCloseTestMethod_failed_2(void) = 0;
		virtual void testListingStart(void) = 0;
		virtual void testListingEnd(void) = 0;
		virtual void testListMethod_1(void) = 0;
		virtual void testListMethod_2(void) = 0;
		virtual void testPrintSummary(void) = 0;
};

#endif
