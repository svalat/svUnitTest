/*****************************************************
             PROJECT  : svUnitTest
             VERSION  : 0.3.0
             DATE     : 05/2011
             AUTHOR   : Valat Sébastien
             LICENSE  : CeCILL-C
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
