/*****************************************************
             PROJECT  : svUnitTest
             VERSION  : 0.0.2
             DATE     : 06/2010
             AUTHOR   : Valat Sébastien
             LICENSE  : CeCILL-C
*****************************************************/

/********************  HEADERS  *********************/
#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "svutStatusInfo.h"

using namespace std;
namespace svUnitTest
{

/********************  METHODE  *********************/
/**
 * Default constructor of the class.
 * @param message Define a message to describe the current status, mainly describe the source of error.
 * @param location Source code location of the assertion used to emit this status notification if
 * there is one.
**/
svutStatusInfo::svutStatusInfo(svUnitTest::svutStatus status, string message, const svUnitTest::svutCodeLocation& location)
	:location(location)
{
	this->message = message;
	this->status = status;
}

/********************  METHODE  *********************/
/**
 * @return Return the source location of the assertion which emit this status notification.
**/
svutCodeLocation svutStatusInfo::getLocation(void) const
{
	return this->location;
}

/********************  METHODE  *********************/
/**
 * @return Return the message which describe more precisely the current status.
**/
std::string svutStatusInfo::getMessage(void) const
{
	return this->message;
}

/********************  METHODE  *********************/
/**
 * @return Return the current status of the test.
**/
svutStatus svutStatusInfo::getStatus ( void ) const
{
	return this->status;
}

/********************  METHODE  *********************/
/**
 * Add a new entry into the parameters list related to the assetion.
  * @param name Define the parameter name.
 * @param value Define the parameter value.
 */
void svutStatusInfo::addEntry(std::string name,std::string value)
{
	this->entries.insert(pair<string,string>(name,value));
}

/********************  METHODE  *********************/
/**
 * @return Return the list of parameters related to the current status.
**/
std::map<std::string,std::string> svutStatusInfo::getEntries(void) const
{
	return entries;
}

/********************  METHODE  *********************/
/**
 * Format the current status information and place it in the given stream.
 * @param out Define the output stream to use.
 * @param prefix Define the string th place before each parameter name.
 * @param separator Define the string to place between the parameter name and the value.
 * @param postfix Define the string to place after the parameter value.
 */
void svutStatusInfo::formatEntries(std::ostream & out,std::string prefix,std::string separator,std::string postfix) const
{
	for (map<string,string>::const_iterator it=entries.begin() ; it != entries.end(); it++ )
		out << prefix << it->first << separator << it->second << postfix;
}

};
