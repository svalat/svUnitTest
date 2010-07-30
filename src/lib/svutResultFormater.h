/*****************************************************
             PROJECT  : svUnitTest
             VERSION  : 0.0.2
             DATE     : 07/2010
             AUTHOR   : Valat Sébastien
             LICENSE  : CeCILL-C
*****************************************************/

#ifndef SVUT_RESULT_FORMATER_HEADER
#define SVUT_RESULT_FORMATER_HEADER

/********************  HEADERS  *********************/
#include "svutTestCase.h"
#include "svutListenerSummary.h"

namespace svUnitTest
{

/********************* CLASS ************************/
/**
 * Abstract class used to define the bases of output formatting. All formater shared the same
 * interface to be pluged in the runner without distinction. You can implement your own one
 * quicly by this way to support new output format for compatbility as example.
 * @brief Abstract definition of result output formatting.
 * @author Sébastien Valat
 * @version 0.0.2
**/
class svutResultFormater
{
	public:
		/** Default constructor of the class, done nothing here. **/
		svutResultFormater(void) {};
		/** Destructor of the class, defined for inheritance support. **/
		virtual ~svutResultFormater(void) {};
		/**
		 * Method called when starting to output things. It's called when starting to run the
		 * test to build the output header if needed.
		**/
		virtual void openOutput(void) = 0;
		/**
		 * Method called when ending to output things. It's called when all the tests have been
		 * runned to print the output footer if needed.
		**/
		virtual void closeOutput(void) = 0;
		/**
		 * Method called before starting outputing results of test method which are part of the
		 * given testCase. All the method are called before the call of closeTestCase(). This may
		 * be used to print header informations related to the test case.
		 * @param testCase Define the testCase which start.
		**/
		virtual void openTestCase(const svutTestCase & testCase) = 0;
		/**
		 * Method called after outputing all results of a particular test case. This may be used to
		 * print footer informations related to the test case.
		 * @param testCase Define the testCase which end.
		**/ 
		virtual void closeTestCase(const svutTestCase & testCase) = 0;
		/**
		 * Methode called when running a particular test method to print header informations if
		 * needed.
		 * @param testCase Define the current test case which is running.
		 * @param meth Define the current method in the test case which is running.
		**/
		virtual void openTestMethod(const svutTestCase & testCase,const svutTestMethod & meth) = 0;
		/**
		 * Methode called when finish running a particular test method to print final status
		 * if needed.
		 * @param testCase Define the current test case which is running.
		 * @param meth Define the current method in the test case which is running.
		 * @param status Define the final status of the test method.
		**/
		virtual void closeTestMethod(const svutTestCase & testCase,const svutTestMethod & meth,const svutStatusInfo & status) = 0;
		/**
		 * Print a global summary of wall test. It's call just before closeOutput() at the end of
		 * the run.
		 * @param summary Define the global summary to print if needed.
		**/
		virtual void printSummary(svutResultSummary summary) = 0;
};

}

#endif //SVUT_RESULT_FORMATER_HEADER
