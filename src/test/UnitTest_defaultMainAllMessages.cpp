/*****************************************************
             PROJECT  : svUnitTest
             VERSION  : 0.1.0
             DATE     : 01/2011
             AUTHOR   : Valat Sébastien
             LICENSE  : CeCILL-C
*****************************************************/

/********************  HEADERS  *********************/
#include <svutTestCase.h>
#include <svutAssert.h>
#include <svutDefaultMain.h>
#include <iostream>
#include "UnitTestMockTestCase2.h"

/**********************  USING  *********************/
using namespace std;
using namespace svUnitTest;

/********************* CLASS ************************/
class UnitTest_MyTestFull : public UnitTestMockTestCase2
{
	public:
		UnitTest_MyTestFull(void);
};

/*******************  FUNCTION  *********************/
UnitTest_MyTestFull::UnitTest_MyTestFull(void )
{
	this->useTests(REGISTER_ALL);
}

SVUT_REGISTER_TEST_CASE(UnitTest_MyTestFull);

/*******************  FUNCTION  *********************/
int main(int argc, char * argv[])
{
	return svUnitTest::defaultMain(argc,argv);
}
