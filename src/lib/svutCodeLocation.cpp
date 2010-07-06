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

#include "svutCodeLocation.h"

using namespace std;
namespace svUnitTest
{

/********************  CONSTS  **********************/
/**
 * Constant used to define non located objects.
 **/
const svutCodeLocation SVUT_NO_LOCATION;

/********************  METHODE  *********************/
/**
 * Default class constructor. It produce a non located instance.
**/
svutCodeLocation::svutCodeLocation(void)
{
	this->line = -1;
	this->located = false;
}

/********************  METHODE  *********************/
/**
 * Class constructor wich permit to setup a location. Normaly the fields are setup via
 * the macro SVUT_CODE_LOCATION which use compiler macros to fetch the current line, file and
 * function.
 * @param file Define the source filename.
 * @param methode Define the function name.
 * @param line Define the line in source file.
**/
svutCodeLocation::svutCodeLocation(std::string file,std::string methode,int line)
{
	this->file = file;
	this->methode = methode;
	this->line = line;
	this->located = true;
}

/********************  METHODE  *********************/
/**
 * @return Return the source filename or "unknown"
 */
std::string svutCodeLocation::getFilename(void) const
{
	if (located)
		return this->file;
	else
		return "unknown";
}

/********************  METHODE  *********************/
/**
 * @return  Return the method name or "unknown"
 */
std::string svutCodeLocation::getMethodeName(void) const
{
	if (located)
		return this->methode;
	else
		return "unknown";
}

/********************  METHODE  *********************/
/**
 * @return Return the line in source file or -1.
**/
int svutCodeLocation::getLine(void) const
{
	if (located)
		return this->line;
	else
		return -1;
}

/********************  METHODE  *********************/
/**
 * @return Return true if current instance define a location, of false if not
 * (equivalent to SVUT_NO_LOCATION).
**/
bool svutCodeLocation::hasLocation(void) const
{
	return located;
}

/********************  METHODE  *********************/
/**
 * Output stream operator used to format the location in a string format.
 * @param out Define the output stream to use.
 * @param location Define the location to format.
 * @return Return the output stream used.
 */
std::ostream & operator << (std::ostream & out,const svutCodeLocation & location)
{
	if (location.located)
		out << "line " << location.line
			<< " of file " << location.file
			<< " on methode " <<location. methode << "()";
	else
		out << "unknown location";
	return out;
}

/********************  METHODE  *********************/
/**
 * Operator used to compares two locations. Two locations are equals if they have the same
 * filename, function name and line ; or if the two are equivalent to SVUT_NO_LOCATION.
 * @param loc1 Define the first location.
 * @param loc2 Define the second location.
 * @return Return true if the two location are equals member per memner.
**/
bool operator == (const svutCodeLocation & loc1,const svutCodeLocation & loc2)
{
	return loc1.file == loc2.file && loc1.line == loc2.line && loc1.methode == loc2.methode;
}

};
