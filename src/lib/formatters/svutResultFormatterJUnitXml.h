/*****************************************************
             PROJECT  : svUnitTest
             VERSION  : 0.3.0
             DATE     : 05/2011
             AUTHOR   : Valat Sébastien
             LICENSE  : CeCILL-C
*****************************************************/

#ifndef SVUT_RESULT_FORMATER_JUNIT_XML_HEADER
#define SVUT_RESULT_FORMATER_JUNIT_XML_HEADER

/********************  HEADERS  *********************/
#include <ostream>
#include <sstream>
#include "svutResultFormatter.h"

/********************  NAMESPACE  *******************/
namespace svUnitTest
{

/********************* STRUCT ***********************/
struct svutResultFormatterJUnitXmlBuffer
{
	svutResultFormatterJUnitXmlBuffer(void);
	std::stringstream buffer;
	int tests;
	int errors;
	int failures;
	double start;
};

/********************* CLASS ************************/
/**
 * Implementation of svutResultFormatter to export the results into the JUnit XML format compliant.
 * Thanks to google unit documentation : http://code.google.com/p/googletest/wiki/AdvancedGuide and for
 * the XSD : http://windyroad.org/dl/Open%20Source/JUnit.xsd.
 * @brief Class used to format the results into JUnit XML format.
 * @author Sébastien Valat
 * @TODO Test the class.
**/
class svutResultFormatterJUnitXml : public svutResultFormatter
{
	public:
		svutResultFormatterJUnitXml(std::ostream & out);
		virtual void openOutput(void);
		virtual void closeOutput(void);
		virtual void openTestCase(const svutTestCase & testCase);
		virtual void closeTestCase(const svutTestCase & testCase);
		virtual void openTestMethod(const svutTestCase & testCase,const svutTestMethod & meth);
		virtual void closeTestMethod(const svutTestCase & testCase,const svutTestMethod & meth,const svutStatusInfo & status);
		virtual void printSummary(svutResultSummary summary);
		virtual void onListingStart(void );
		virtual void onListMethod(const svUnitTest::svutTestCase& testCase, const svUnitTest::svutTestMethod& method);
		virtual void onListingEnd(void );
		static double getCurrentTime(void);
	protected:
		/** Pointer to the output stream to use. **/
		std::ostream * out;
		void printAssertInfo(const svUnitTest::svutStatusInfo & status);
		std::string getQtStatusName(svutStatus status);
	private:
		/** Aggregate all test suites for testsuites balise. **/
		svutResultFormatterJUnitXmlBuffer * all;
		/** Aggregate all test cases of test suite for testsuite balise. **/
		svutResultFormatterJUnitXmlBuffer * suite;
		/** Remember the start time of current method. **/
		double testMethodStartTime;
};

}

#endif //SVUT_RESULT_FORMATER_QT_XML_HEADER
