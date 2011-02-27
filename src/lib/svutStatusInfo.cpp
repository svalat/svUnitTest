/*****************************************************
             PROJECT  : svUnitTest
             VERSION  : 0.2.0
             DATE     : 02/2011
             AUTHOR   : Valat Sébastien
             LICENSE  : CeCILL-C
*****************************************************/

/********************  HEADERS  *********************/
#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "svutStatusInfo.h"
#include "svutException.h"

/**********************  USING  *********************/
using namespace std;

/********************  NAMESPACE  *******************/
namespace svUnitTest
{

/*******************  FUNCTION  *********************/
/**
 * Default constructor of the class.
 * @param message Define a message to describe the current status, mainly describe the source of error.
 * @param location Source code location of the assertion used to emit this status notification if
 * there is one.
 * @param status Define the related status.
**/
svutStatusInfo::svutStatusInfo(svUnitTest::svutStatus status, std::string message, const svUnitTest::svutCodeLocation& location)
	:location(location)
{
	this->message = message;
	this->status = status;
}

/*******************  FUNCTION  *********************/
/**
 * @return Return the source location of the assertion which emit this status notification.
**/
svutCodeLocation svutStatusInfo::getLocation(void) const
{
	return this->location;
}

/*******************  FUNCTION  *********************/
/**
 * @return Return the message which describe more precisely the current status.
**/
std::string svutStatusInfo::getMessage(void) const
{
	return this->message;
}

/*******************  FUNCTION  *********************/
/**
 * @return Return the current status of the test.
**/
svutStatus svutStatusInfo::getStatus ( void ) const
{
	return this->status;
}

/*******************  FUNCTION  *********************/
/**
 * Add a new entry into the parameters list related to the assetion.
 * @param name Define the parameter name.
 * @param value Define the parameter value.
 */
void svutStatusInfo::addEntry(const std::string & name,std::string const & value)
{
	this->entries.insert(pair<string,string>(name,value));
}

/*******************  FUNCTION  *********************/
/**
 * Add a new entry into the parameters list related to the assetion.
 * The main goal of this override is to remove remark #981 from icc when calling this method
 * with constant c string.
 * @param name Define the parameter name.
 * @param value Define the parameter value.
 */
void svutStatusInfo::addEntry ( const char* name, const char* value )
{
	std::string n = name;
	std::string v = value;
	this->addEntry(n,v);
}

/*******************  FUNCTION  *********************/
/**
 * Add a new entry into the parameters list related to the assetion.
 * The main goal of this override is to remove remark #981 from icc when calling this method
 * with constant c string.
 * @param name Define the parameter name.
 * @param value Define the parameter value.
 */
void svutStatusInfo::addEntry ( const char* name, const std::string& value )
{
	std::string n = name;
	this->addEntry(n,value);
}


/*******************  FUNCTION  *********************/
/**
 * @return Return the list of parameters related to the current status.
**/
std::map<std::string,std::string> svutStatusInfo::getEntries(void) const
{
	return entries;
}

/*******************  FUNCTION  *********************/
/**
 * Format the current status information and place it in the given stream.
 * @param out Define the output stream to use.
 * @param prefix Define the string th place before each parameter name.
 * @param separator Define the string to place between the parameter name and the value.
 * @param postfix Define the string to place after the parameter value.
 */
void svutStatusInfo::formatEntries(std::ostream& out, const std::string& prefix, const std::string& separator, const std::string& postfix) const
{
	for (map<string,string>::const_iterator it=entries.begin() ; it != entries.end(); it++ )
	{
		out << prefix;
		out << it->first << separator;
		out << it->second << postfix;
	}
}

/*******************  FUNCTION  *********************/
/**
 * Format the current status information and place it in the given stream.
 * The main goal of this override is to avoir remark #981 of icc.
 * @param out Define the output stream to use.
 * @param prefix Define the string th place before each parameter name.
 * @param separator Define the string to place between the parameter name and the value.
 * @param postfix Define the string to place after the parameter value.
 */
void svutStatusInfo::formatEntries ( std::ostream& out, const char* prefix, const char* separator, const char* postfix ) const
{
	std::string pre(prefix);
	std::string  sep(separator);
	std::string post(postfix);
	formatEntries(out,pre,sep,post);
}


/*******************  FUNCTION  *********************/
/**
 * @return Return the number of entries in the status informations.
**/
unsigned int svutStatusInfo::getNbEntries(void ) const
{
	return this->entries.size();
}

/*******************  FUNCTION  *********************/
/**
 * @return Return a specific entry, empty if non existant.
 * @param name Define the name of the requested entry.
**/
std::string svutStatusInfo::getEntry(std::string name) const
{
	for (map<string,string>::const_iterator it=entries.begin() ; it != entries.end(); it++ )
		if (it->first == name)
			return it->second;
	return "";
}

/*******************  FUNCTION  *********************/
/**
 * @return Return the name of the current status as a C++ string. The returned names are :
 *      - SUCCESS
 *      - FAILED
 *      - TODO
 *      - INDEV
 *      - UNKNOWN
 *      - SKIPED
**/
std::string svutStatusInfo::getStatusName(void ) const
{
	return getStatusName(this->status);
}

/*******************  FUNCTION  *********************/
/**
 * Permit to use the equal operator on svutStatusInfo objects.
 * @param orig Define the original object to copy on the current one.
 * @return Return a regrence to the destinatino object.
**/
svutStatusInfo& svUnitTest::svutStatusInfo::operator=(const svUnitTest::svutStatusInfo& orig)
{
	this->message = orig.message;
	this->entries = orig.entries;
	this->location = orig.location;
	this->status = orig.status;
	return *this;
}

/*******************  FUNCTION  *********************/
/**
 * @param status Define the status to convert to string.
 * @return Return the name of the given status as a C++ string. The returned names are :
 *      - SUCCESS
 *      - FAILED
 *      - TODO
 *      - INDEV
 *      - UNKNOWN
 *      - SKIPED
**/
string svutStatusInfo::getStatusName(svutStatus status)
{
	switch(status)
	{
		case SVUT_STATUS_SUCCESS:
			return "SUCCESS";
		case SVUT_STATUS_FAILED:
			return "FAILED";
		case SVUT_STATUS_TODO:
			return "TODO";
		case SVUT_STATUS_INDEV:
			return "INDEV";
		case SVUT_STATUS_UNKNOWN:
			return "UNKNOWN";
		case SVUT_STATUS_SKIPED:
			return "SKIPED";
	}
	throw svutExInternalError("Unknown status value in svutStatusInfo::getStatusName()");
}

}
