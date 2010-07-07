/*****************************************************
             PROJECT  : svUnitTest
             VERSION  : 0.0.2
             DATE     : 07/2010
             AUTHOR   : Valat Sébastien
             LICENSE  : CeCILL-C
*****************************************************/

/********************  HEADERS  *********************/
#include "svutExAssert.h"

using namespace std;
namespace svUnitTest
{

/********************  METHOD  **********************/
/**
 * @todo Check that the code is took from base class
**/
svutExAssertFail::svutExAssertFail(string name, const svutStatusInfo & info) throw()
	: svutExTestStatus("AssertFail:"+name, info)
{
}

/********************  METHOD  **********************/
/**
 * @todo Check that the code is took from base class
**/
svutExAssertFail::svutExAssertFail(string name, svutStatus status, const svutCodeLocation & location, string message) throw()
	: svutExTestStatus("AssertFail:"+name, status, location, message)
{
}

};
