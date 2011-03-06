/*****************************************************
             PROJECT  : svUnitTest
             VERSION  : 0.3.0-dev
             DATE     : 03/2011
             AUTHOR   : Valat Sébastien
             LICENSE  : CeCILL-C
*****************************************************/

/********************  HEADERS  *********************/
#include "svutExNotify.h"

/**********************  USING  *********************/
using namespace std;

/********************  NAMESPACE  *******************/
namespace svUnitTest
{

/*******************  FUNCTION  *********************/
/**
 * @copydoc svutExTestStatus::svutExTestStatus
**/
svutExNotify::svutExNotify(std::string name, const svutStatusInfo & info) throw()
	: svutExTestStatus("Notify:"+name, info)
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
svutExNotify::svutExNotify(std::string name, svutStatus status, const svutCodeLocation & location, std::string message) throw()
	: svutExTestStatus("Notify:"+name, status, location, message)
{
}

/*******************  FUNCTION  *********************/
/**
 * @copydoc svutExTestStatus::~svutExTestStatus
**/
svutExNotify::~svutExNotify(void ) throw()
{
}

/*******************  FUNCTION  *********************/
/**
 * Class constructor.
 * @param message Define a message to describe what need to be done in the test.
 * @param location Define the location from which is emit this notification.
**/
svutExNotifyTodo::svutExNotifyTodo(std::string message, const svutCodeLocation & location) throw()
	:svutExNotify("Todo",SVUT_STATUS_TODO,location,message)
{
}

/*******************  FUNCTION  *********************/
/**
 * Class constructor.
 * @param message Define a message to describe what we are doing in the test.
 * @param location Define the location from which is emit this notification.
**/
svutExNotifyIndev::svutExNotifyIndev(std::string message, svutCodeLocation location) throw()
	:svutExNotify("Indev",SVUT_STATUS_INDEV,location,message)
{
}

}
