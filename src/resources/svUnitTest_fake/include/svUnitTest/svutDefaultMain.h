/*****************************************************
             PROJECT  : svUnitTest
             VERSION  : 0.3.0
             DATE     : 05/2011
             AUTHOR   : Valat Sébastien
             LICENSE  : CeCILL-C
*****************************************************/

/********************  HEADERS  *********************/
#include "svutTestCase.h"

namespace svUnitTest
{

/********************  MACROS  **********************/
#define SVUT_REGISTER_STANDELONE(className) \
	int main(int argc,char * argv[]) { \
		svUnitTest::svutTestCaseBuilderGeneric<className> builder;\
		return uniqueStandeloneMain(argc,argv,builder);\
	}

/*******************  FUNCTION  *********************/
int defaultMain(int argc,char * argv[]);
int uniqueStandeloneMain(int argc,char * argv[],svutTestCaseBuilder & builder);

}
