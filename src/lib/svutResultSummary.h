/*****************************************************
             PROJECT  : svUnitTest
             VERSION  : 0.0.2
             DATE     : 07/2010
             AUTHOR   : Valat Sébastien
             LICENSE  : CeCILL-C
*****************************************************/

#ifndef SVUT_RESULT_SUMMARY_H
#define SVUT_RESULT_SUMMARY_H

/********************  HEADERS  *********************/
#include "svutStatusInfo.h"

namespace svUnitTest
{

/*********************  TYPES  **********************/
/**
 * Class used to aggregate global summary of tests.
 * @brief Class used to aggregate global summary of tests.
 * @author Valat Sébastien
 * @version 0.0.2
 * @todo IMPLEMENT AND UNITTEST
**/
class svutResultSummary
{
	public:
		svutResultSummary(void);
		unsigned int getTotal(void) const;
		unsigned int getCount(svutStatus status);
		unsigned int getPercentage(svutStatus status);
		void increment(svutStatus status,unsigned int nb=1);
		void set(svutStatus status,unsigned int nb);
		void reset(void);
		svutStatus getStatus(void) const;
	protected:
		/** Count the number of success occured during the tests.**/
		unsigned int success;
		/** Count the number of todo occured during the tests.**/
		unsigned int todo;
		/** Count the number of failed occured during the tests.**/
		unsigned int failed;
		/** Count the number of unknown occured during the tests.**/
		unsigned int unknown;
		/** Count the number of skiped occured during the tests.**/
		unsigned int skiped;
		/** Count the number of indev occured during the tests.**/
		unsigned int indev;
};

}

#endif // SVUTRESULTSUMMARY_H
