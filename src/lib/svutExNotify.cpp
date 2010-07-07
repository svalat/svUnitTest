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
 * @todo Check that the code is took from base class
**/
svutExNotify::svutExNotify(string name, const svutStatusInfo & info) throw()
	: svutExTestStatus("Notify:"+name, info)
{
}

/********************  METHOD  **********************/
/**
 * @todo Check that the code is took from base class
**/
svutExNotify::svutExNotify(string name, svutStatus status, const svutCodeLocation & location, string message) throw()
	: svutExTestStatus("Notify:"+name, status, location, message)
{
}

/********************  METHOD  **********************/
/**
 * @todo Check that the code is took from base class
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
svutExNotifyTodo::svutExNotifyTodo(string message, const svutCodeLocation & location) throw()
	:svutExNotify("Todo",SVUT_STATUS_TODO,location,message)
{
}

/********************  METHOD  **********************/
/**
 * Class constructor.
 * @param message Define a message to describe what we are doing in the test.
 * @param location Define the location from which is emit this notification.
**/
svutExNotifyIndev::svutExNotifyIndev(string message, svutCodeLocation location) throw()
	:svutExNotify("Indev",SVUT_STATUS_INDEV,location,message)
{
}

};
