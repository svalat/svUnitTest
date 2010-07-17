/*****************************************************
             PROJECT  : svUnitTest
             VERSION  : 0.0.2
             DATE     : 07/2010
             AUTHOR   : Valat Sébastien
             LICENSE  : CeCILL-C
*****************************************************/

/********************  HEADERS  *********************/
#include "svutExNotify.h"

using namespace std;
namespace svUnitTest
{

/********************  METHOD  **********************/
/**
 * @copydoc svutExTestStatus::svutExTestStatus
**/
svutExNotify::svutExNotify(std::string name, const svutStatusInfo & info) throw()
	: svutExTestStatus("Notify:"+name, info)
{
}

/********************  METHOD  **********************/
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

/********************  METHOD  **********************/
/**
 * @copydoc svutExTestStatus::~svutExTestStatus
**/
svutExNotify::~svutExNotify(void ) throw()
{
}

/********************  METHOD  **********************/
/**
 * Class constructor.
 * @param message Define a message to describe what need to be done in the test.
 * @param location Define the location from which is emit this notification.
**/
svutExNotifyTodo::svutExNotifyTodo(std::string message, const svutCodeLocation & location) throw()
	:svutExNotify("Todo",SVUT_STATUS_TODO,location,message)
{
}

/********************  METHOD  **********************/
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
