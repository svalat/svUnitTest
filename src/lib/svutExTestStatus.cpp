/*****************************************************
             PROJECT  : svUnitTest
             VERSION  : 0.0.2
             DATE     : 07/2010
             AUTHOR   : Valat Sébastien
             LICENSE  : CeCILL-C
*****************************************************/

/********************  HEADERS  *********************/
#include <sstream>
#include <cstring>
#include "svutExTestStatus.h"

using namespace std;
using namespace std;
namespace svUnitTest
{

/********************  METHOD  **********************/
/**
 * Class constructor.
 * @param name Define the name of the current notification.
 * @param info Define the related information (location, parameters...).
**/
svutExTestStatus::svutExTestStatus(std::string name, const svUnitTest::svutStatusInfo& info) throw()
	: svutException(""),info(info)
{
	this->name = name;
}

/********************  METHOD  **********************/
/**
 * Class constructor.
 * @param name Define the name of the current notification.
 * @param status Define the related status.
 * @param location Define the source location which emit this notification.
 * @param message Describe why this notification was emitted.
**/
svutExTestStatus::svutExTestStatus(std::string name, svutStatus status, svutCodeLocation location, std::string message) throw()
	:svutException(""),info(status,message,location)
{
	this->name = name;
}


/********************  METHOD  **********************/
/**
 * Class destructor.
**/
svutExTestStatus::~svutExTestStatus(void ) throw()
{
}

/********************  METHOD  **********************/
/**
 * @return Return the name of the notification (eg : ASSERT:FAILED, NOTIFY:INDEV).
**/
std::string svutExTestStatus::getExceptionName(void ) const
{
	return this->name;
}

/********************  METHOD  **********************/
/**
 * @return Return the global informations of the notification in a constant way.
**/
const svUnitTest::svutStatusInfo& svutExTestStatus::getInfos(void ) const
{
	return info;
}

/********************  METHOD  **********************/
/**
 * @return Return the global informations of the notification in a modifiable way.
**/
svutStatusInfo& svutExTestStatus::getInfos(void )
{
	return info;
}


/********************  METHOD  **********************/
/**
 * @return Return the status related to this notification.
**/
svutStatus svutExTestStatus::getStatus(void ) const
{
	return info.getStatus();
}

/********************  METHOD  **********************/
/**
 * @return To be compatible with std::exception, return al the information as a string.
**/
const char* svutExTestStatus::what() const throw()
{
	stringstream str;
	str << this->name << " : "<< info.getMessage() << " : " << endl;
	info.formatEntries(str,"  - "," : ","\n");
	string tmp = str.str();
	char * buffer = new char[tmp.size()+1];
	memcpy(buffer,tmp.c_str(),tmp.size()+1);
	return buffer;
}

/********************  METHOD  **********************/
/**
 * @return Return the inner message which describe the exception.
**/
std::string svutExTestStatus::getMessage(void ) const
{
    return info.getMessage();
}

};
