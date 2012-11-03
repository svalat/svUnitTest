/*****************************************************
             PROJECT  : svUnitTest
             VERSION  : 0.5.0-dev
             DATE     : 11/2012
             AUTHOR   : Valat Sébastien
             LICENSE  : CeCILL-C
*****************************************************/

#ifndef SVUT_RESULT_FORMATER_BOOST_XML_HEADER
#define SVUT_RESULT_FORMATER_BOOST_XML_HEADER

/********************  HEADERS  *********************/
#include <ostream>
#include "svutResultFormatter.h"

/********************  NAMESPACE  *******************/
namespace svUnitTest
{

/********************* CLASS ************************/
/**
 * Implementation of svutResultFormatter to export the results into the native svUnitTest XML format.
 * @brief Class used to format the results into XML format.
 * @author Sébastien Valat
**/
class svutResultFormatterBoostXml : public svutResultFormatter
{
	public:
		svutResultFormatterBoostXml(std::ostream & out);
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
		void setDate(std::string date);
	protected:
		/** Pointer to the output stream to use. **/
		std::ostream * out;
		void printAssertInfo(const svUnitTest::svutStatusInfo & status);
		void printLocation(const svUnitTest::svutCodeLocation & location);
		void printEnv(void);
		/**
		 * Store the current date for the XML output. This  storage is only
		 * required to simplify the unit  tests of this class by forcing a
		 * constant date to check output generation.
		**/
		std::string date;
		/** Remember the last test case done to detect test case changing. **/
		const svutTestCase * lastTestCase;
};

}

#endif //SVUT_RESULT_FORMATER_BOOST_XML_HEADER
