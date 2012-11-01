/*****************************************************
             PROJECT  : svUnitTest
             VERSION  : 0.4.0
             DATE     : 11/2012
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
 * @param expected Define the expected value in string format.
 * @param actual Define the current value in string format.
 * @param location Define the location from which the exception is emitted. 
**/
svutExAssertFailEqual::svutExAssertFailEqual(bool expectTestRes, std::string expected, std::string actual, svutCodeLocation location) throw()
	: svutExAssertFail("AssertEqual",SVUT_STATUS_FAILED,location,"Failed on expected value.")
{
	if (expectTestRes)
	{
		info.addEntry("Expected",expected);
	} else {
		info.addEntry("Not expected",expected);
	}
	info.addEntry("Actual",actual);
}

/*******************  FUNCTION  *********************/
/**
 * Class constructor for value limit failure.
 * @param operatorName Define the operator name which has conduct to the erreur (>=, >, < or <=).
 *        This is to provide information on the limit which was overpassed.
 * @param expectedLimit Define the expected limit which was used and overpassed.
 * @param actual Define the actual value which overpassed the expected limit.
 * @param location Define the test location which produce the failure.
**/
svutExAssertFailLimit::svutExAssertFailLimit(std::string operatorName, std::string expectedLimit, std::string actual, svutCodeLocation location) throw()
	: svutExAssertFail("AssertLimit", SVUT_STATUS_FAILED, location, "Failed on expected limit on value.")
{
	info.addEntry("Expected limit",expectedLimit);
	info.addEntry("Actual",actual);
	info.addEntry("Operator",operatorName);
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

/*******************  FUNCTION  *********************/
/**
 * Class constructor for exception assertion.
 * @param value Define the value which was expected to be 0.
 * @param location Define the location of the assertion. 
**/
svutExAssertFailZero::svutExAssertFailZero(string value, svutCodeLocation location) throw ()
	: svutExAssertFail("AssertZero",SVUT_STATUS_FAILED,location,"Failed on waiting 0 value.")
{
	info.addEntry("Value",value);
}

/*******************  FUNCTION  *********************/
/**
 * Class constructor for exception assertion.
 * @param location Define the location of the assertion.
**/
svutExAssertFailZeros::svutExAssertFailZeros(svutCodeLocation location) throw()
	: svutExAssertFail("AssertZeros",SVUT_STATUS_FAILED,location,"Failed on waiting 0 values in array.")
{
}

}
