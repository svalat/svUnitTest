/*****************************************************
             PROJECT  : svUnitTest
             VERSION  : 0.4.0
             DATE     : 11/2012
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
/**
 * Temporary buffer to aggregate the XML output. At then end we can generate
 * the root XML element and print the body part stored in that buffer.
 * It solve the issue due to the fact that JUnit format write it's summary
 * counters in the open tag which is the first line to write...
**/
struct svutResultFormatterJUnitXmlBuffer
{
	svutResultFormatterJUnitXmlBuffer(void);
	/**
	 * Buffer to aggregate the core of XML file as open balis must contain the
	 * number of tests, failres and success. So need to execute, aggregate,
	 * then print.
	**/
	std::stringstream buffer;
	/** Count the number of tests. **/
	int tests;
	/** Count the number of errors. **/
	int errors;
	/** Count the number of failures. **/
	int failures;
	/** Store the start time (in seconds). **/
	double start;
};

/********************* CLASS ************************/
/**
 * Implementation of svutResultFormatter to export the results into the JUnit XML format compliant.
 * Thanks to google unit documentation : http://code.google.com/p/googletest/wiki/AdvancedGuide and for
 * the XSD : http://windyroad.org/dl/Open%20Source/JUnit.xsd.
 * @brief Class used to format the results into JUnit XML format.
 * @author Sébastien Valat
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
};

}

#endif //SVUT_RESULT_FORMATER_QT_XML_HEADER
