/*****************************************************
             PROJECT  : svUnitTest
             VERSION  : 0.5.0-dev
             DATE     : 11/2012
             AUTHOR   : Valat Sébastien
             LICENSE  : CeCILL-C 2.1
*****************************************************/

/********************  HEADERS  *********************/
#include <svUnitTest.h>
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
SVUT_USE_DEFAULT_MAIN
