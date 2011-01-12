/*****************************************************
             PROJECT  : svUnitTest
             VERSION  : 0.1.0
             DATE     : 01/2011
             AUTHOR   : Valat Sébastien
             LICENSE  : CeCILL-C
*****************************************************/

#ifndef SVUT_RESULT_FORMATTER_STD_H
#define SVUT_RESULT_FORMATTER_STD_H

/********************  HEADERS  *********************/
#include "svutResultFormatter.h"
#include <ostream>

/********************  NAMESPACE  *******************/
namespace svUnitTest
{

/********************* CLASS ************************/
/**
 * Base class to support result output formatting for standard output. It may diverged to black and
 * white output and colored output. It provide all the common mechanisms.
 * @brief Abstract class to format results for std output.
 * @author Valat Sébastien
**/
class svutResultFormatterStd : public svutResultFormatter
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
	protected:
		/**
		 * Print the global status of the test at the end of summary display.
		 * it's supposed to use format like : "|  STATUS   : %-12s  |\n"
		 * @param out Define the output stream to use.
		 * @param status Define the final status to display.
		**/
		virtual void printSummaryFinalStatus(std::ostream & out,svutStatus status)=0;
		/**
		 * Print the summary stat for a given status. It display the name of the status, number and
		 * percentage of occurences. It may use format like "|  %-9s: %4d (%3d %%)  |\n"
		 * @param out Define the output stream to use.
		 * @param status Define the status for which the numbers are given.
		 * @param nb Define the number of occurences.
		 * @param tot Define the total number of tests executed.
		**/
		virtual void printSummaryStat(std::ostream & out,svutStatus status,unsigned int nb,unsigned int tot)=0;
		/**
		 * Print the final status of a test method. It displat de name of the method and to status.
		 * It's supposed to use format like : " * %-40s     [ %s ]\n"->
		 * @param out Define the output stream to use.
		 * @param name Define the name of the method.
		 * @param status Define the final status of the method.
		**/
		virtual void printMethodAndStatus(std::ostream & out,std::string name,svutStatus status)=0;
		
		virtual void printFailedInfo(const svutTestCase & testCase,const svutTestMethod & meth,const svutStatusInfo & status);
		virtual void printUnknownInfo(const svutTestCase & testCase,const svutTestMethod & meth,const svutStatusInfo & status);
	private:
		
		/** Store the pointer tout output stream. **/
		std::ostream * out;
};

}

#endif // SVUT_RESULT_FORMATTER_STD_H
