/*****************************************************
             PROJECT  : svUnitTest
             VERSION  : 0.3.0
             DATE     : 05/2011
             AUTHOR   : Valat Sébastien
             LICENSE  : CeCILL-C
*****************************************************/

#ifndef SVUT_DEFAULT_MAIN_HEADER
#define SVUT_DEFAULT_MAIN_HEADER

/*********************  CLASS  **********************/
class svutTestCaseBuilder;

/********************  NAMESPACE  *******************/
namespace svUnitTest
{

/*******************  FUNCTION  *********************/
int defaultMain(int argc,char * argv[]);
int uniqueStandeloneMain(int argc,char * argv[],svutTestCaseBuilder & builder);

/**
 * Call this macro to declare a standelone executable tests. This is used to call the corresponding
 * main function with the required arguments.
 * Caution, you can't call this macro more than one time into an executable as it create the main
 * function. It was deseigned to produce an executable for a unique test case.
 * @param className Define the name of the test case to bind into the executable.
**/
#define SVUT_REGISTER_STANDELONE(className) \
	int main(int argc,char * argv[]) { \
		svUnitTest::svutTestCaseBuilderGeneric<className> builder;\
		return uniqueStandeloneMain(argc,argv,builder);\
	}
}

/**
 * Simple macro to quicly define your main methode base on the default one from svUnitTest.
 * It simply implement the main method by calling defaultMain() function of library.
**/
#define SVUT_USE_DEFAULT_MAIN \
	int main(int argc,char * argv[]) { \
		return defaultMain(argc,argv); \
	}

#endif
