/*****************************************************
             PROJECT  : svUnitTest
             VERSION  : 0.3.0-dev
             DATE     : 03/2011
             AUTHOR   : Valat Sébastien
             LICENSE  : CeCILL-C
*****************************************************/

#ifndef SVUT_RESULT_FORMATER_QT_XML_HEADER
#define SVUT_RESULT_FORMATER_QT_XML_HEADER

/********************  HEADERS  *********************/
#include <ostream>
#include "svutResultFormatter.h"

/********************  NAMESPACE  *******************/
namespace svUnitTest
{

/********************* CLASS ************************/
/**
 * Implementation of svutResultFormatter to export the results into the QT XML format.
 * @brief Class used to format the results into QT XML format.
 * @author Sébastien Valat
**/
class svutResultFormatterQtXml : public svutResultFormatter
{
	public:
		svutResultFormatterQtXml(std::ostream & out);
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
};

}

#endif //SVUT_RESULT_FORMATER_QT_XML_HEADER
