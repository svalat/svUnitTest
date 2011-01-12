/*****************************************************
             PROJECT  : svUnitTest
             VERSION  : 0.1.0
             DATE     : 01/2011
             AUTHOR   : Valat Sébastien
             LICENSE  : CeCILL-C
*****************************************************/

/********************  HEADERS  *********************/
#include "svutExAssert.h"

/**********************  USING  *********************/
using namespace std;

/********************  NAMESPACE  *******************/
namespace svUnitTest
{

/*******************  FUNCTION  *********************/
/**
 * @copydoc svutExTestStatus::svutExTestStatus
**/
svutExAssertFail::svutExAssertFail(std::string name, const svutStatusInfo & info) throw()
	: svutExTestStatus("AssertFail:"+name, info)
{
}

/*******************  FUNCTION  *********************/
/**
 * Class constructor with some manual information.
 * @param name Define the name of the current notification.
 * @param message Define a message de describe the notification.
 * @param location Define the location from which the assertion was emitted.
 * @param status Define the status related to this notification.
**/
svutExAssertFail::svutExAssertFail(std::string name, svutStatus status, const svutCodeLocation & location, std::string message) throw()
	: svutExTestStatus("AssertFail:"+name, status, location, message)
{
}

/*******************  FUNCTION  *********************/
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

/*******************  FUNCTION  *********************/
/**
 * Class constructor for boolean failure.
 * @param expectNull Define the expected value, true for wating NULL, otherwise, false.
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

/*******************  FUNCTION  *********************/
/**
 * Class constructor for equality failure.
 * @param expectTestRes Define if it except equal (true) values or not (false).
 * @param exptected Define the expected value in string format.
 * @param actual Define the current value in string format.
 * @param location Define the location from which the exception is emitted. 
**/
svutExAssertFailEqual::svutExAssertFailEqual(bool expectTestRes, std::string exptected, std::string actual, svutCodeLocation location) throw()
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

/*******************  FUNCTION  *********************/
/**
 * Class constructor for custom exception failure.
 * @param message Define a message to describe the reason of failure.
 * @param location Define the location from which it was emitted.
**/
svutExAssertFailCustom::svutExAssertFailCustom(std::string message, svutCodeLocation location) throw()
	: svutExAssertFail("AssertCustom",SVUT_STATUS_FAILED,location,message)
{
}

/*******************  FUNCTION  *********************/
/**
 * Class constructor for non reachable code.
 * @param location Define the location from which it was emitted and which may not be reached by
 * excecution flow.
**/
svutExAssertFailNotExec::svutExAssertFailNotExec(svutCodeLocation location) throw()
	:svutExAssertFail("AssertNotExec",SVUT_STATUS_FAILED,location,"Failed on execution of forbidden bloc.")
{
}

/*******************  FUNCTION  *********************/
/**
 * Class constructor for exception assertion.
 * @param expected Define the name of the expected exception (use "NONE" if not except one).
 * @param actual Define the current exception throwed (use "NONE" is none).
 * @param location Define the location of the assertion.
**/
svutExAssertFailThrow::svutExAssertFailThrow(std::string expected, std::string actual, svutCodeLocation location) throw()
	: svutExAssertFail("AssertThrow",SVUT_STATUS_FAILED,location,"Failed on waiting exception.")
{
	info.addEntry("Expected",expected);
	info.addEntry("Actual",actual);
}

}
