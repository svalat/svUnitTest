/*****************************************************
             PROJECT  : svUnitTest
             VERSION  : 0.3.0-dev
             DATE     : 03/2011
             AUTHOR   : Valat Sébastien
             LICENSE  : CeCILL-C
*****************************************************/

#ifndef SVUT_RESULT_FORMATER_XML_HEADER
#define SVUT_RESULT_FORMATER_XML_HEADER

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
class svutResultFormatterXml : public svutResultFormatter
{
	public:
		svutResultFormatterXml(std::ostream & out);
		virtual void openOutput(void);
		virtual void closeOutput(void);
		virtual void openTestCase(const svutTestCase & testCase);
		virtual void closeTestCase(const svutTestCase & testCase);
		virtual void openTestMethod(const svutTestCase & testCase,const svutTestMethod & meth);
		virtual void closeTestMethod(const svutTestCase & testCase,const svutTestMethod & meth,const svutStatusInfo & status);
		virtual void printSummary(svutResultSummary summary);
		void setDate(std::string date);
	protected:
		/** Pointer to the output stream to use. **/
		std::ostream * out;
		void printAssertInfo(const svUnitTest::svutStatusInfo & status);
		void printLocation(const svUnitTest::svutCodeLocation & location);
		void printEnv(void);
		std::string date;
};

}

#endif //SVUT_RESULT_FORMATER_XML_HEADER
