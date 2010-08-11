/*****************************************************
             PROJECT  : svUnitTest
             VERSION  : 0.0.2
             DATE     : 07/2010
             AUTHOR   : Valat Sébastien
             LICENSE  : CeCILL-C
*****************************************************/

#ifndef SVUT_RESULT_FORMATTER_STD_H
#define SVUT_RESULT_FORMATTER_STD_H

/********************  HEADERS  *********************/
#include "svutResultFormatter.h"
#include <ostream>

namespace svUnitTest
{

/********************* CLASS ************************/
/**
 * Base class to support result output formatting for standard output. It may diverged to black and
 * white output and colored output. It provide all the common mechanisms.
 * @brief Abstract class to format results for std output.
 * @author Valat Sébastien
 * @version 0.0.2
**/
class svutResultFormatterStd
{
	public:
		svutResultFormatterStd(std::ostream & out);
		virtual void openOutput(void);
		virtual void closeOutput(void);
		virtual void openTestCase(const svutTestCase & testCase);
		virtual void closeTestCase(const svutTestCase & testCase);
		virtual void openTestMethod(const svutTestCase & testCase,const svutTestMethod & meth);
		virtual void closeTestMethod(const svutTestCase & testCase,const svutTestMethod & meth,const svutStatusInfo & status);
		virtual void printSummary(svutResultSummary summary);

		void setDisplaySuccess(bool state);
		void setDisplayDetails(bool state);
		void setDisplayFullName(bool state);
	protected:
		virtual void printSummaryFinalStatus(std::ostream & out,svutStatus status)=0;
		virtual void printSummaryStat(std::ostream & out,svutStatus status,int nb,int tot)=0;
		virtual void printMethodAndStatus(std::ostream & out,std::string name,svutStatus status)=0;
		
		virtual void printFailedInfo(const svutTestCase & testCase,const svutTestMethod & meth,const svutStatusInfo & status);
		virtual void printUnknownInfo(const svutTestCase & testCase,const svutTestMethod & meth,const svutStatusInfo & status);

		/** Define if success must be displayed ot not. **/
		bool displaySuccess;
		/** Define if error details must ne displayed or not. **/
		bool displayDetails;
		/** Define if need to display full test name or only the method name. **/
		bool displayFullName;
	private:
		
		/** Store the pointer tout output stream. **/
		std::ostream * out;
};

}

#endif // SVUT_RESULT_FORMATTER_STD_H
