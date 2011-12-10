/*****************************************************
             PROJECT  : svUnitTest
             VERSION  : 0.3.0
             DATE     : 05/2011
             AUTHOR   : Valat Sébastien
             LICENSE  : CeCILL-C
*****************************************************/

/********************  HEADERS  *********************/
#include "svutRunner.h"
#include "svutTestCase.h"
#include "svutDefaultMain.h"
#include "svutTestCaseBuilder.h"

/********************  NAMESPACE  *******************/
namespace svUnitTest
{

/*******************  FUNCTION  *********************/
/**
 * A simple default implementation of the main methode required to execute the tests. By default
 * the tests are searched as auto-registrer tests.
 * To be used, you just need to call this function in your own main function, this permit to
 * avoid to re-implement each time this non changing part of test execution.
 * @param argc Define the number of parameters given to the program.
 * @param argv Define the list of parameters given to the program.
**/
int defaultMain(int argc,char * argv[])
{
	svutRunnerConfig config(argc,(const char**)argv);
	//cout << config << endl;
	svutRunner runner(config);
	runner.loadAutoDetected();
	int res = runner.run() ? 0 : 1;
	runner.unloadAutoDetected();
	return res;
}

/*******************  FUNCTION  *********************/
/**
 * Basic main function used to build a standalone executable for a uniq test. Please, use the
 * macro SVUT_REGISTER_STANDELONE instead of directly call this method.
 * It permit to build a standelone test directly in a unique cpp file without implementing manually
 * a main method.
 * This was mainly implemented for a compatibility with the QT Unit appraoch which use an executable
 * for each test case implemented.
 * @param argc Define the number of parameter given to the program.
 * @param argv Define the list of parameters given to the program.
 * @param builder Define the class builder to use to instanciate the test case.
 * We didn't direclty instanciate the class in the macro to simplify the debugging and to keep the
 * same semantics than the automatic detection case.
**/
int uniqueStandeloneMain(int argc,char * argv[],svutTestCaseBuilder & builder)
{
	svutRunnerConfig config(argc,(const char**)argv);
	//cout << config << endl;
	svutRunner runner(config);
	svutTestCase * test = builder.build();
	runner.registerTestCase(*test);
	int res = runner.run() ? 0 : 1;
	delete test;
	return res;
}

}
