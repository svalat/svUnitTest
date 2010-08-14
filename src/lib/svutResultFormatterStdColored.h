/*****************************************************
             PROJECT  : svUnitTest
             VERSION  : 0.0.2
             DATE     : 07/2010
             AUTHOR   : Valat Sébastien
             LICENSE  : CeCILL-C
*****************************************************/

#ifndef SVUT_RESULT_FORMATTER_STD_COLORED_H
#define SVUT_RESULT_FORMATTER_STD_COLORED_H

/********************  HEADERS  *********************/
#include "svutResultFormatterStd.h"

namespace svUnitTest
{

/********************* CLASS ************************/
/**
 * Classe used to implement the support of colored standard output. It was mainly based and
 * implemented by subclass svutResultFormatterStd. Here we simply provide somme override to support
 * colored output.
 * @brief Implement support of STD colored output formatting.
 * @version 0.0.2
 * @author Valat Sébastien
**/
class svutResultFormatterStdColored : public svutResultFormatterStd
{
	public:
		svutResultFormatterStdColored(std::ostream & out);
	protected:
		virtual void printSummaryFinalStatus(std::ostream & out,svutStatus status);
		virtual void printSummaryStat(std::ostream & out,svutStatus status,unsigned int nb,unsigned int tot);
		virtual void printMethodAndStatus(std::ostream & out,std::string name,svutStatus status);
		virtual int getStatusColor(svutStatus status) const;
		std::string setColor(int color) const;
		std::string setStatusColor(svutStatus status) const;
		std::string unsetColor(void) const;
};

}

#endif // SVUT_RESULT_FORMATTER_STD_COLORED_H