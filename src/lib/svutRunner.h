/*****************************************************
             PROJECT  : svUnitTest
             VERSION  : 0.0.2
             DATE     : 12/2010
             AUTHOR   : Valat Sébastien
             LICENSE  : CeCILL-C
*****************************************************/

#ifndef SVUT_RUNNNER_HEADER
#define SVUT_RUNNNER_HEADER

/********************  HEADERS  *********************/
#include <list>
#include <iostream>
#include "svutTestCase.h"
#include "svutListener.h"
#include "svutRunnerConfig.h"
#include "svutResultFormatter.h"
#include "svutListenerSummary.h"
#include "svutListenerMultiplexer.h"

namespace svUnitTest
{

/********************  CLASSE  **********************/
/**
 * Class used to run the tests. It must be instanciate in main function to run all registrerd unit
 * tests.
 * @brief Exection class for the whole tests.
 * @author Valat Sébastien
 * @version 0.0.1
**/
class svutRunner
{
	public:
		svutRunner(svutOutputMode mode = SVUT_OUT_STD_BW,std::ostream & out = std::cout);
		svutRunner(svutListener & listener);
		svutRunner(svutResultFormatter & formatter);
		svutRunner(svutRunnerConfig & config);
		virtual ~svutRunner(void);
		bool run(void);
		void setDisplay(bool success,bool details);
		void loadAutoDetected(void);
		void unloadAutoDetected(void);
		void registerTestCase(svutTestCase & tcase);
	protected:
		bool run_tests(void);
		bool run_list_tests(void);
	private:
		void init(void);
		void init(svutOutputMode mode,std::ostream & out);
		void init(svutResultFormatter & formatter);
		void init(svutListener & listener);
		bool hasMultipleTestCase(void);
		/** Pointer to the listener object to use to reports the results.**/
		svutListenerMultiplexer listener;
		/** Pointer to the summary listener (require to get the final state). **/
		svutListenerSummary * summary;
		/** Pointer the formatter. **/
		svutResultFormatter * formatter;
		/** Define if the formatter was created by the current class of not. **/
		bool ownTheFormatter;
		/** Define the list of tests to execute. **/
		std::list<svutTestCase *> suites;
		/** Keep an hant to the config object. **/
		svutRunnerConfig * config;
};

};

#endif
