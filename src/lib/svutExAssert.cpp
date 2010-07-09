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

/********************  METHOD  **********************/
/**
 * Class constructor for boolean failure.
 * @param expected Define the expected value.
 * @param location Define the location from which the exception is emitted.
**/
svutExAssertFailBool::svutExAssertFailBool(bool expected, const svutCodeLocation & location) throw()
	: svutExAssertFail("AssertBool",SVUT_STATUS_FAILED,location,"Failed on BOOLEAN test.")
{
	if (expected)
	{
		info.addEntry("Expected","TRUE");
		info.addEntry("Actual","FALSE");
	} else {
		info.addEntry("Expected","FALSE");
		info.addEntry("Actual","TRUE");
	}
}

/********************  METHOD  **********************/
/**
 * Class constructor for boolean failure.
 * @param expected Define the expected value, true for wating NULL, otherwise, false.
 * @param location Define the location from which the exception is emitted.
**/
svutExAssertFailNullPointer::svutExAssertFailNullPointer(bool expectNull, svutCodeLocation location) throw()
	: svutExAssertFail("AssertNull",SVUT_STATUS_FAILED,location,"Failed on NULL pointer test.")
{
	if (expectNull)
	{
		info.addEntry("Expected","NULL");
		info.addEntry("Actual","NOT NULL");
	} else {
		info.addEntry("Expected","NOT NULL");
		info.addEntry("Actual","NULL");
	}
}

/********************  METHOD  **********************/
/**
 * Class constructor for equality failure.
 * @param expectTestRes Define if it except equal (true) values or not (false).
 * @param excpected Define the expected value in string format.
 * @param actual Define the current value in string format.
 * @param location Define the location from which the exception is emitted. 
**/
svutExAssertFailEqual::svutExAssertFailEqual(bool expectTestRes, string exptected, string actual, svutCodeLocation location) throw()
	: svutExAssertFail("AssertEqual",SVUT_STATUS_FAILED,location,"Failed on expected value.")
{
	if (expectTestRes)
	{
		info.addEntry("Expected",exptected);
	} else {
		info.addEntry("Not expected",exptected);
	}
	info.addEntry("Actual",actual);
}

/********************  METHOD  **********************/
/**
 * Class constructor for custom exception failure.
 * @param message Define a message to describe the reason of failure.
 * @param location Define the location from which it was emitted.
**/
svutExAssertFailCustom::svutExAssertFailCustom(string message, svutCodeLocation& location) throw()
	: svutExAssertFail("AssertCustom",SVUT_STATUS_FAILED,location,message)
{
}

/********************  METHOD  **********************/
/**
 * Class constructor for non reachable code.
 * @param location Define the location from which it was emitted and which may not be reached by
 * excecution flow.
**/
svutExAssertFailNotExec::svutExAssertFailNotExec(svutCodeLocation location) throw()
	:svutExAssertFail("AssertNotExec",SVUT_STATUS_FAILED,location,"Failed on execution of forbidden bloc.")
{
}

/********************  METHOD  **********************/
/**
 * Class constructor for exception assertion.
 * @param excpected Define the name of the expected exception (use "NONE" if not except one).
 * @param actual Define the current exception throwed (use "NONE" is none).
 * @param location Define the location of the assertion.
**/
svutExAssertFailThrow::svutExAssertFailThrow(string expected, string actual, svutCodeLocation location) throw()
	: svutExAssertFail("AssertThrow",SVUT_STATUS_FAILED,location,"Failed on waiting exception.")
{
	info.addEntry("Expect",expected);
	info.addEntry("Actual",actual);
}

};
