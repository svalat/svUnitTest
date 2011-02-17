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
#include <map>
#include <string>
#include <iostream>
#include "svutException.h"

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
 * Exception class for duplicated key error while defining available arguements.
 * @brief Exception class for arguement definition error.
**/
class svutExArgpDuplicateKey : public svutException
{
	public:
		svutExArgpDuplicateKey(char key);
		svutExArgpDuplicateKey(std::string name);
		virtual ~svutExArgpDuplicateKey() throw() {};
		virtual std::string getMessage(void) const;
	private:
		/** Define the conflicting key. **/
		char key;
		/** Define the conflicting name. **/
		std::string name;
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
		svutArgp(void);
		virtual ~svutArgp(void);
		bool parse(int argc, char * argv[]);
		void decalareOption(char key,std::string name,std::string valueType,std::string descr) throw (svutExArgpDuplicateKey);
		void clearOptions(void);
		void showHelp(std::ostream & out = std::cout);
		std::string getHelp(int columns = 80);
		void setProjectName(std::string projectName);
		void setProjectVersion(std::string projectVersion);
		void setProjectBugAddress(std::string projectBugAddress);
		void setProjectDescr(std::string projectDescr);
		void setProjectArgUsage(std::string argUsage);
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
		std::string formatArgumentHelp(svutArgDef arg,int columns) const;
		bool isValidKey(char key) const;
		void setupDefaultOptions(void);
		bool hasLongName(std::string name) const;
		
		/** Store the list of available options. **/
		std::map<char,svutArgDef> options;
		/** Name of the project. **/
		std::string projectName;
		/** Version of the project. **/
		std::string projectVersion;
		/** Mail address to which submit bugs. **/
		std::string projectBugAddress;
		/** Project short description. **/
		std::string projectDescr;
		/** Short pattern of argument usage. **/
		std::string argUsage;
};

}

#endif // SVUTARGP_H
