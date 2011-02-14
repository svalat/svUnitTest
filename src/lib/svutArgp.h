/*****************************************************
             PROJECT  : svUnitTest
             VERSION  : 0.1.0
             DATE     : 02/2011
             AUTHOR   : Valat Sébastien
             LICENSE  : CeCILL-C
*****************************************************/

#ifndef SVUTARGP_H
#define SVUTARGP_H

/********************  HEADERS  *********************/
#include <vector>
#include <string>

/********************  NAMESPACE  *******************/
namespace svUnitTest
{

/*********************  ENUM  ************************/
/**
 * Define the parsing status.
 * @brief Parsing status.
**/
enum svutArgParsingStatus
{
	/** Parsing success. **/
	SVUT_ARGP_SUCCESS,
	/** Invalid arguement. **/
	SVUT_ARGP_ERR_ARG,
	/** Invalid value. **/
	SVUT_ARGP_ERR_VALUE,
	/** Unknown error. **/
	SVUT_ARGP_ERR_UNKNOWN
};

/********************  STRUCT  **********************/
/**
 * Structure used to store informations about arguments.
 * @brief Argument definition.
**/
struct svutArgDef
{
	/** Define the long name of the option (eg. "silent"" will give --silent) **/
	std::string name;
	/** Define the short name for the option (eg. "s" will give -s for alias to --silent). **/
	char key;
	/** Short description of the option, used to build --help. **/
	std::string descr;
	/** Define the type of the related value to provide, use NONE to disable and define a trigger.**/
	std::string valueType;
};

/*********************  CLASS  **********************/
/**
 * Provide our own implementation of argument parsing as argp.h wasn't multiplatforme.
 * Our arguemnt pattern is quite simple so we choosed to reimplement our own parser
 * avoiding bringing external dependencies.
 * @author Sébastien Valat
 * @brief Program arguement parser base class.
**/
class svutArgp
{
	public:
		virtual ~svutArgp(void);
		bool parse(int argc, char * argv[]);
		void decalareOption(char key,std::string name,std::string valueType,std::string descr);
		void clearOptions(void);
		void showHelp(void);
		std::string getHelp(int columns = 80);
		void setProjectName(std::string projectName);
		void setProjectVersion(std::string projectVersion);
		void setProjectBugAddress(std::string projectBugAddress);
		void setProjectDescr(std::string projectDescr);
	protected:
		/** Methode called while starting to parse arguements. **/
		virtual void parseInit(void) = 0;
		/**
		 * Methode called while reading each arguement.
		 * @param key Define the key of arguement (the short name, eg. -v)
		**/
		virtual void parseOption(char key,std::string value) = 0;
		/** Method called while ending to parse arguements. **/
		virtual void parseTerminate(void) = 0;
	private:
		int getTermColumns(void) const;
		
		/** Store the list of available options. **/
		std::vector<svutArgDef> options;
		/** Name of the project. **/
		std::string projectName;
		/** Version of the project. **/
		std::string projectVersion;
		/** Mail address to which submit bugs. **/
		std::string projectBugAddress;
		/** Project short description. **/
		std::string projectDescr;
};

}

#endif // SVUTARGP_H
