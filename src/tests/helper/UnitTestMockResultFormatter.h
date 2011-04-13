/*****************************************************
             PROJECT  : svUnitTest
             VERSION  : 0.3.0-dev
             DATE     : 03/2011
             AUTHOR   : Valat Sébastien
             LICENSE  : CeCILL-C
*****************************************************/

#ifndef UNIT_TEST_MOCK_RESULT_FORMATER_HEADER
#define UNIT_TEST_MOCK_RESULT_FORMATER_HEADER

/********************  HEADERS  *********************/
#include <svutResultFormatter.h>
#include <ostream>
#include <list>
#include <string>

/********************* CLASS ************************/
class UnitTestMockResultFormater : public svUnitTest::svutResultFormatter
{
	public:
		virtual void openOutput(void);
		virtual void closeOutput(void);
		virtual void openTestCase(const svUnitTest::svutTestCase & testCase);
		virtual void closeTestCase(const svUnitTest::svutTestCase & testCase);
		virtual void openTestMethod(const svUnitTest::svutTestCase & testCase,const svUnitTest::svutTestMethod & meth);
		virtual void closeTestMethod(const svUnitTest::svutTestCase & testCase,const svUnitTest::svutTestMethod & meth,const svUnitTest::svutStatusInfo & status);
		virtual void onListingStart(void );
		virtual void onListMethod(const svUnitTest::svutTestCase& testCase, const svUnitTest::svutTestMethod& method);
		virtual void onListingEnd(void );
		virtual void printSummary(svUnitTest::svutResultSummary summary);
		friend bool operator == (const UnitTestMockResultFormater & formater1,const UnitTestMockResultFormater & formater2);
		friend bool operator != (const UnitTestMockResultFormater & formater1,const UnitTestMockResultFormater & formater2);
		friend bool operator == (const std::string & str,const UnitTestMockResultFormater & formater);
		friend bool operator != (const std::string & str,const UnitTestMockResultFormater & formater);
		friend bool operator == (const UnitTestMockResultFormater & formater,const std::string & str) { return str == formater; };
		friend bool operator != (const UnitTestMockResultFormater & formater,const std::string & str) { return str != formater; };
		friend std::ostream & operator << (std::ostream & out,const UnitTestMockResultFormater & formater);
		bool isEmpty(void) const;
		void reset(void);

		std::list<std::string> event;
};

#endif // UNIT_TEST_MOCK_RESULT_FORMATER_HEADER
