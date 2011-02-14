/*****************************************************
             PROJECT  : svUnitTest
             VERSION  : 0.1.0
             DATE     : 02/2011
             AUTHOR   : Valat Sébastien
             LICENSE  : CeCILL-C
*****************************************************/

/********************  HEADERS  *********************/
#include "svutArgp.h"

/**********************  USING  *********************/
using namespace std;

/********************  NAMESPACE  *******************/
namespace svUnitTest
{

/*******************  FUNCTION  *********************/
/** Default virtual destructor. **/
svutArgp::~svutArgp(void )
{
}

/*******************  FUNCTION  *********************/
/**
 * Define the project name to use while generating the help string.
 * @param projectName Define the project name to use.
**/
void svutArgp::setProjectName(string projectName)
{

}

/*******************  FUNCTION  *********************/
/**
 * Define the project version to use while generating the help string.
 * @param projectVersion Define the project version to use.
**/
void svutArgp::setProjectVersion(string projectVersion)
{

}

/*******************  FUNCTION  *********************/
/**
 * Define a short description of the project to use while generating the help string.
 * @param projectDescr Short description of the project.
**/
void svutArgp::setProjectDescr(string projectDescr)
{

}

/*******************  FUNCTION  *********************/
/**
 * Define the email address to which report bugs.
 * @param projectBugAddress Define the selected mail address.
**/
void svutArgp::setProjectBugAddress(string projectBugAddress)
{

}

/*******************  FUNCTION  *********************/
/**
 * Decalre a new option to accept in the parsor.
 * @param key Define the short trigger for the option (eg. -a).
 * @param name Define the long name for the option (eg. --help). Caution, the -- will be added
 *             automatically.
 * @param valueType Define the type of the value, use NONE for simple triggers. Otherwise, you can
 *             use FILE, STRING ...., please use upper caption.
 * @param descr Define a short description for the new option.
**/
void svutArgp::decalareOption(char key, string name, string valueType, string descr)
{

}

/*******************  FUNCTION  *********************/
/**
 * Try to obtain the size of the xterm to known where to cut lines. Default will be 80 columns.
**/
int svutArgp::getTermColumns(void) const
{

}

/*******************  FUNCTION  *********************/
/** Function used to generate the help string and print it onto the standard output. **/
void svutArgp::showHelp(void)
{

}

/*******************  FUNCTION  *********************/
/**
 * Function used to generate the string help.
 * @param columns Define the limit to use to split lines. Use -1 to none.
 * @return Return the help string directly formatted for the output.
**/
string svutArgp::getHelp(int columns)
{

}

/*******************  FUNCTION  *********************/
/**
 * Clear all defined options.
**/
void svutArgp::clearOptions(void )
{

}

/*******************  FUNCTION  *********************/
/**
 * Function to call to parse the program arguements. It will :
 *  - call parseInit
 *  - call parseOption for each arguement after small checkings.
 *  - call parseTerminate
**/
bool svutArgp::parse(int argc, char* argv[])
{

}

}
