/*****************************************************
             PROJECT  : svUnitTest
             VERSION  : 0.0.2
             DATE     : 07/2010
             AUTHOR   : Valat Sébastien
             LICENSE  : CeCILL-C
*****************************************************/

#ifndef SVUT_RESULT_FORMATER_QT_XML_HEADER
#define SVUT_RESULT_FORMATER_QT_XML_HEADER

/********************  HEADERS  *********************/
#include <ostream>
#include "svutResultFormatter.h"

namespace svUnitTest
{

/********************* CLASS ************************/
/**
 * Implementation of svutResultFormatter to export the results into the QT XML format.
 * @brief Class used to format the results into QT XML format.
 * @author Sébastien Valat
 * @version 0.0.2
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
	protected:
		std::ostream * out;
		void printAssertInfo(const svUnitTest::svutStatusInfo & status);
		std::string getQtStatusName(svutStatus status);
};

}

#endif //SVUT_RESULT_FORMATER_QT_XML_HEADER
