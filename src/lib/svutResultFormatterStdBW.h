/*****************************************************
             PROJECT  : svUnitTest
             VERSION  : 0.1.0
             DATE     : 01/2011
             AUTHOR   : Valat Sébastien
             LICENSE  : CeCILL-C
*****************************************************/

#ifndef SVUT_RESULT_FORMATTER_STD_BW_H
#define SVUT_RESULT_FORMATTER_STD_BW_H

/********************  HEADERS  *********************/
#include "svutResultFormatterStd.h"

/********************  NAMESPACE  *******************/
namespace svUnitTest
{

/********************* CLASS ************************/
/**
 * Classe used to implement the support of black and white standard output. It was mainly based and
 * implemented by subclass svutResultFormatterStd. Here we simply provide somme override to support
 * non colored output.
 * @brief Implement support of STD B&W output formatting.
 * @author Valat Sébastien
**/
class svutResultFormatterStdBW : public svutResultFormatterStd
{
	public:
		svutResultFormatterStdBW(std::ostream & out);
	protected:
		virtual void printSummaryFinalStatus(std::ostream & out,svutStatus status);
		virtual void printSummaryStat(std::ostream & out,svutStatus status,unsigned int nb,unsigned int tot);
		virtual void printMethodAndStatus(std::ostream & out,std::string name,svutStatus status);
};

}

#endif // SVUT_RESULT_FORMATTER_STD_BW_H
