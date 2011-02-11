/*****************************************************
             PROJECT  : svUnitTest
             VERSION  : 0.1.0
             DATE     : 01/2011
             AUTHOR   : Valat Sébastien
             LICENSE  : CeCILL-C
*****************************************************/

#ifndef SVUT_RUNNER_CONFIG_HEADER
#define SVUT_RUNNER_CONFIG_HEADER

/********************  HEADERS  *********************/
#include <iostream>
#include "svutTestFilterBasic.h"

/********************  NAMESPACE  *******************/
namespace svUnitTest
{

/*********************  ENUM  ************************/
/**
 * Enum used to select the output format to use when running tests.
**/
enum svutOutputMode
{
	/** Use colored text for standard output, it require to use a terminal which support that. **/
	SVUT_OUT_STD_COLOR,
	/** Use back and white text for standard output. **/
	SVUT_OUT_STD_BW,
	/** Format the output in XML. **/
	SVUT_OUT_XML,
	/** Format the output in XML QT format to emulate their system. **/
	SVUT_OUT_QT_XML
};

/*********************  ENUM  ************************/
/**
 * Enumaration which descrive the type of action to do when running the test suite.
**/
enum svutRunnerAction
{
	/** Execute the tests. **/
	SVUT_ACTION_RUN_TESTS,
	/**
	 * Only extract and display the test list. This option was used to emulate QT test suite
	 * for integration in kdevelop which require to list the tests before running them.
	**/
	SVUT_ACTION_LIST_TESTS
};

/********************  CLASSE  **********************/
/**
 * Class used to configure the unit test runner in a dynamic way via program arguments. This class
 * was used with svutRunner.
 * @brief Class to manage unit test run parameters.
 * @author Valat Sébastien.
**/
class svutRunnerConfig
{
	public:
		svutRunnerConfig(void);
		svutRunnerConfig(int argc, const char * argv[]);
		virtual ~svutRunnerConfig(void);
		void loadParams(int argc, const char * argv[]);
		svutOutputMode getMode(void) const;
		void setMode(svutOutputMode mode);
		bool hasDisplaySuccess(void) const;
		void setDisplaySuccess(bool state);
		bool hasDisplayDetails(void) const;
		void setDisplayDetails(bool state);
		svutRunnerAction getAction(void) const;
		void setAction(svutRunnerAction action);
		void setOutput(std::string filename);
		void setOutput(std::ostream & stream);
		std::ostream & getOutput(void);
		void addBasicAccept(std::string caseName,std::string function);
		bool addBasicAccept(std::string filter);
		svutTestFilter & getFilter(void);
	protected:
		/** Close the file at the end, or while changing the output mode. **/
		void closeFile(void);
		/** Define the output mode to use. **/
		svutOutputMode mode;
		/** Define is the success need to be displayed or not. **/
		bool displaySuccess;
		/** Define if details need to be displayed or not. **/
		bool displayDetails;
		/** Define what to do, run the test or simply list the methods. **/
		svutRunnerAction action;
		/** Define in which file to redirect the output. Use "-" for standard. **/
		std::string filename;
		/** Define the output stream to use. It we automaticaly closed at class destroy time. **/
		std::ofstream * outputStream;
		/** Define a specific output stram to use, it must be totaly managed by the user. **/
		std::ostream * externalOutputStream;
		/** Define a filter used to select which test we want to run if not want all. **/
		svutTestFilterBasic filter;
	private:
		void init(void);
		void qtCompat(int argc, char * argv[]);
		char ** cloneArgv(int argc, const char * argv[]) const;
		void freeClonedArgv(int argc,char * argv[]) const;
		bool checkColorUsability(void) const;

	friend std::ostream & operator <<(std::ostream & out,const svutRunnerConfig & config);
};

}

#endif
