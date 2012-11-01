/*****************************************************
             PROJECT  : svUnitTest
             VERSION  : 0.4.0
             DATE     : 11/2012
             AUTHOR   : Valat Sébastien
             LICENSE  : CeCILL-C
*****************************************************/

#ifndef SVUT_CODE_LOCATION_HEADER
#define SVUT_CODE_LOCATION_HEADER

/********************  HEADERS  *********************/
#include <string>
#include <ostream>

/********************  NAMESPACE  *******************/
namespace svUnitTest
{

/********************  MACROS  **********************/
/**
 * Macro used to quicly create an instance of svutCodeLocation pointed to the current source
 * This is recommended to use this macro to create instances of svutCodeLocation.
 * It permit to use compiler macro to fill arguments (file, method and line).
**/
#define SVUT_CODE_LOCATION svUnitTest::svutCodeLocation(__FILE__,__FUNCTION__,__LINE__)

/********************  MACROS  **********************/
/**
 * Same than SVUT_CODE_LOCATION, but for static location out of functions, otherwise we got a
 * a warning from clang.
**/
#define SVUT_CODE_LOCATION_STATIC svUnitTest::svutCodeLocation(__FILE__,"[none]",__LINE__)

/*********************  CLASS  **********************/
/**
 * Class used to manage locations in sources of the application. It permet to transport location
 * of an error in unit tests. Instances of this class are normaly create via the macro
 * SVUT_CODE_LOCATION which automaticaly define the current location with the compiler macros.
 * The locatino is define by filename, function name and line.
 * @brief Class used to locate things in the original source code.
 * @author Valat Sébastien
 * @version 0.0.1
**/
class svutCodeLocation
{
	public:
		svutCodeLocation(void);
		svutCodeLocation(const svutCodeLocation & location);
		svutCodeLocation(std::string file,std::string methode,int line);
		std::string getFilename(void) const;
		std::string getMethodeName(void) const;
		int getLine(void) const;
		bool hasLocation(void) const;

		friend std::ostream & operator << (std::ostream & out,const svutCodeLocation & location);
		friend bool operator == (const svutCodeLocation & loc1,const svutCodeLocation & loc2);
	protected:
		/** Define the source filename. **/
		std::string file;
		/** Define the method name. **/
		std::string methode;
		/** Define the line in the file. **/
		int line;
		/**
		 * Define if a location is attached to the current instance or not.
		**/
		bool located;
};

/********************  CONSTS  **********************/
/**
 * Constant used to define non located objets..
**/
extern const svutCodeLocation SVUT_NO_LOCATION;

}

#endif
