/*****************************************************
             PROJECT  : svUnitTest
             VERSION  : 0.1.0
             DATE     : 01/2011
             AUTHOR   : Valat Sébastien
             LICENSE  : CeCILL-C
*****************************************************/

/********************  HEADERS  *********************/
#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include <cstdlib>
#include <cstring>
#include <iostream>
#include <fstream>
#include <sstream>
#include "svutRunnerConfig.h"

//optional include
#ifdef HAVE_UNISTD_H
#include <unistd.h>
#endif

/**********************  USING  *********************/
using namespace std;

/********************  NAMESPACE  *******************/
namespace svUnitTest
{

/*********************  GLOBALS  ********************/
/** Used to averpass terminal detection to force output color mode in unit tests. **/
bool __svut_bypass_color_mode__ = false;

/*******************  FUNCTION  *********************/
/**
 * Constructor of svutRunnerConfigArgp, it setup svutArgp to be ready to parse svUnitTest arguements.
 * @param config Define the configuration object into which to store values fetched from arguements.
**/
svutRunnerConfigArgp::svutRunnerConfigArgp ( svutRunnerConfig& config )
                     : svutArgp(true)
{
	this->config = &config;

	//setup arg parsor
	setProjectName      ( "svUnitTest"                            );
	setProjectVersion   ( VERSION                                 );
	setProjectBugAddress( "sebastien.valat.dev@orange.fr"             );
	setProjectDescr     ( "Unit test library for C/C++ language." );
	setProjectArgUsage  ( "[-m MODE] [-v] [-s] [-?]"              );

	//declare options
	decalareOption('m', "mode"    , "MODE",  "Define the render mode to use : xml, qt_xml, std, "
	                                         "color (color is defaut)."                         );
	decalareOption('v', "verbose" , "NONE",  "Display all the test results, event the success." );
	decalareOption('s', "silent"  , "NONE",  "Don't display extra information on test failure." );
	decalareOption('f', "function", "NONE",  "List all the accessible tests methods."           );
	decalareOption('q', "qtxml"   , "NONE",  "Equivalent to -m qt_xml."                         );
	decalareOption('o', "output"  , "FILE",  "Define the output file to use. Use - for stdout." );
	decalareOption('a', "accept"  , "NAME",  "Accept only methods add with -a. in format "
	                                         "'testCase::method'. 'testCase::' will accept all "
	                                         "methods of testCase. '::method' will accept all "
	                                         "methods named method without checking the test "
	                                         "case name."                                       );
}

/*******************  FUNCTION  *********************/
void svutRunnerConfigArgp::parseInit ( void ) throw (svutExArgpError)
{
}

/*******************  FUNCTION  *********************/
/**
 * Method used to parse arguements and setup related value. This Glibc will call this metho for
 * each parameter encoutered with the given values.

 * @param key Define the key of current parsed arguement (the short name).
 * @param arg Define the chain passed as arguement if available (-a).
 * @param value Define the related value if available (eg : --name={value} or -n {value}).
 * @throw svutExArgpError On error, throw such exception to notify the arguement paror.
 * It will redirecte the related message to error output, please don't use cerr direclty here.
**/
void svutRunnerConfigArgp::parseOption ( char key, std::string arg, std::string value ) throw (svutExArgpError)
{
	stringstream err;
	switch (key)
	{
		case 'm'://progress bar
			if ( value == "xml" ) {
				config->setMode(SVUT_OUT_XML);
			} else if ( value == "qt_xml") {
				config->setMode(SVUT_OUT_QT_XML);
			} else if (value == "std" ) {
				config->setMode(SVUT_OUT_STD_BW);
			} else if (value == "color" ) {
				config->setMode(SVUT_OUT_STD_COLOR);
			}else {
				err << "Unknown render mode : " << value << endl;
				err << "Supported modes are xml, qt_xml, std and color." << endl;
				throw svutExArgpError(err.str());
			}
			break;
		case 'a'://accept
			if (config->addBasicAccept(value) == false)
			{
				err << "Bad format for the filter : " << value << endl;
				throw svutExArgpError(err.str());
			}
			break;
		case 'q'://mode xml compatible QT
			config->setMode(SVUT_OUT_QT_XML);
			break;
		case 'v'://verbose mode
			config->setDisplaySuccess(true);
			break;
		case 's'://silent error
			config->setDisplayDetails(false);
			break;
		case 'f':
			config->setAction(SVUT_ACTION_LIST_TESTS);
			break;
		case 'o':
			config->setOutput(arg);
			break;
		default://unknown arg
			err << "Unknown arguement : " << arg << endl;
			throw svutExArgpError(err.str());
	}
}

/*******************  FUNCTION  *********************/
void svutRunnerConfigArgp::parseTerminate ( void ) throw (svutExArgpError)
{
}

/*******************  FUNCTION  *********************/
/**
 * Default constructeur of the config class.
**/
svutRunnerConfig::svutRunnerConfig(void)
                 : argParsor(*this)
{
	this->init();
}

/*******************  FUNCTION  *********************/
/**
 * Close all the inner data of the class at destroy time. Mainly the output stream if
 * one is defined.
**/
svutRunnerConfig::~svutRunnerConfig(void)
{
	this->closeFile();
}

/*******************  FUNCTION  *********************/
/**
 * Close all the inner data of the class at destroy time. Mainly the output stream if
 * one is defined.
**/
void svutRunnerConfig::closeFile(void )
{
	if (this->outputStream != NULL)
	{
		this->outputStream->close();
		delete this->outputStream;
		this->outputStream = NULL;
	}
}

/*******************  FUNCTION  *********************/
/**
 * Constructor accepting main arguments to autmatically setup the values from programe arguments.
 * @param argc Define the number of parameters passed to the program.
 * @param argv Define the parameter list passed to the program.
**/
svutRunnerConfig::svutRunnerConfig(int argc,  const char * argv[])
                 : argParsor(*this)
{
	this->init();
	this->loadParams(argc,argv);
}

/*******************  FUNCTION  *********************/
/**
 * Methode used to call the glibc parser to extract values from program calling arguments.
 * @param argc Define the number of parameters passed to the program.
 * @param argv Define the parameter list passed to the program.
**/
void svutRunnerConfig::loadParams(int argc, const char * argv[])
{
	//apply QT compatilibty
	char ** localArgv = cloneArgv(argc,argv);
	qtCompat(argc,localArgv);

	//call the parsor
	argParsor.parse(argc,(const char **)localArgv);

	//free temporary arguement clone
	freeClonedArgv(argc,localArgv);
}

/*******************  FUNCTION  *********************/
/**
 *  @return Return the display mode to use.
**/
svutOutputMode svutRunnerConfig::getMode(void) const
{
	return mode;
}

/*******************  FUNCTION  *********************/
/**
 * @return Return true if need to display success tests or not.
**/
bool svutRunnerConfig::hasDisplaySuccess(void) const
{
	return displaySuccess;
}

/*******************  FUNCTION  *********************/
/**
 * @return Return true if the details need to be displayed on test failure.
**/
bool svutRunnerConfig::hasDisplayDetails(void) const
{
	return displayDetails;
}

/*******************  FUNCTION  *********************/
/**
 * Initiate options with their default values.
**/
void svutRunnerConfig::init(void)
{
	if (this->checkColorUsability())
		mode = SVUT_OUT_STD_COLOR;
	else
		mode = SVUT_OUT_STD_BW;
	displaySuccess = false;
	displayDetails = true;
	action = SVUT_ACTION_RUN_TESTS;
	filename = "";
	outputStream = NULL;
	externalOutputStream = NULL;
}

/*******************  FUNCTION  *********************/
/**
 * Enable or disable the display of details in case of test failure.
 * @param state True to display, false to not.
**/
void svutRunnerConfig::setDisplayDetails(bool state)
{
	displayDetails = state;
}

/*******************  FUNCTION  *********************/
/**
 * Enable or disable the display of success tests.
 * @param state True to display, false to hide.
**/
void svutRunnerConfig::setDisplaySuccess(bool state)
{
	displaySuccess = state;
}

/*******************  FUNCTION  *********************/
/**
 * Setup the display output mode to use.
 * @param mode Define the selected output mode.
**/
void svutRunnerConfig::setMode(svutOutputMode mode)
{
	this->mode = mode;
}

/*******************  FUNCTION  *********************/
/**
 * @return Return the action to execute.
**/
svutRunnerAction svutRunnerConfig::getAction(void) const
{
	return this->action;
}

/*******************  FUNCTION  *********************/
/**
 * Setup the action to execut when running the test suite.
 * @param action Define the action which may be done by the test runner.
**/
void svutRunnerConfig::setAction(svutRunnerAction action)
{
	this->action = action;
}

/*******************  FUNCTION  *********************/
/**
 * Change some values in arguement list to be fully compatible with QT unit tests (in order to
 * support simple integration in KDevelop test interface).
 * For moment we just replace -functions arguement by -f and -xml by -q.
 * @param argc Define the number of parameters passed to the program.
 * @param argv Define the parameter list passed to the program.
**/
void svutRunnerConfig::qtCompat(int argc, char * argv[])
{
	for (int i = 1;i<argc;i++)
	{
		if (strncmp("-functions",argv[i],10) == 0) {
			argv[i][2] = '\0';
		} else if (strncmp("-xml",argv[i],4) == 0) {
			argv[i][1] = 'q';
			argv[i][2] = '\0';
		}
	}
}

/*******************  FUNCTION  *********************/
/**
 * Define the output file to use. If not defined, use the standard output (default value).
 * @param filename Define the output file to use.
**/
void svutRunnerConfig::setOutput(std::string filename)
{
	this->closeFile();
	this->filename = filename;
	this->externalOutputStream = NULL;
	if (this->mode == SVUT_OUT_STD_COLOR)
		this->mode = SVUT_OUT_STD_BW;
}

/*******************  FUNCTION  *********************/
/**
 * Define an external output stream totaly managed by the use.
 * @param stream Define the output stream to use.
**/
void svutRunnerConfig::setOutput(std::ostream & stream)
{
	this->closeFile();
	this->filename = "";
	this->externalOutputStream = &stream;
	if (this->mode == SVUT_OUT_STD_COLOR)
		this->mode = SVUT_OUT_STD_BW;
}


/*******************  FUNCTION  *********************/
/**
 * Method used to get the output stream to use when running the tests. This permit to redirect
 * the output stream where we want, mainly to a file.
 * @return Return a reference to the output stream to use.
**/
std::ostream & svutRunnerConfig::getOutput(void)
{
	if (this->externalOutputStream == NULL)
	{
		if (this->filename == "") {
			return cout;
		} else {
			if (outputStream == NULL)
			{
				outputStream = new ofstream(filename.c_str());
				if (outputStream == NULL)
				{
					cerr << "Can't write into file : " << filename << endl;
					exit(1);
				}
			}
			return *outputStream;
		}
	} else {
		return *this->externalOutputStream;
	}
}

/*******************  FUNCTION  *********************/
/**
 * Add an entry to the basic test fileter.
 * @param caseName Define the test case to accept ; empty to say 'all'.
 * @param function Define the function name to accept ; empty to say 'all'.
**/
void svutRunnerConfig::addBasicAccept(std::string caseName,std::string function)
{
	filter.addAccepted(caseName,function);
}

/*******************  FUNCTION  *********************/
/**
 * Add an entry to the basic test fileter.
 * @param value Define the name of the tests to accept following the format caseName::function.
 * The test case name of function name can be empty to say 'all'. If function is empty, you can
 * avoid the usage of '::'.
 * @return True if the format is valid, false otherwise.
**/
bool svutRunnerConfig::addBasicAccept(std::string value)
{
	//definition
	string caseName,function;
	int sep = 0;
	//read
	for (unsigned int i=0;i<value.size();++i)
	{
		if (value[i] == ':')
			sep++;
		else if (sep == 0)
			caseName += value[i];
		else if (sep == 2)
			function += value[i];
		else
			return false;
	}
	//cout << "DEBUG :  " << caseName << "__" << function << endl;
	addBasicAccept(caseName,function);
	return true;
}

/*******************  FUNCTION  *********************/
/**
 * @return Return the test filter to use.
**/
svutTestFilter & svutRunnerConfig::getFilter(void)
{
	return filter;
}

/*******************  FUNCTION  *********************/
/**
 * Send the configuration object to output stream. This is mainly to help for debugging.
 * @param out Define the output stream to use.
 * @param config Define the current object to display.
 * @return Return a reference to the output stream used.
**/
std::ostream & operator <<(std::ostream & out,const svutRunnerConfig & config)
{
	const char * strMode[4]={"STD_COLOR","STD_BW","XML","QT_XML"};
	const char * strAction[2]={"RUN_TESTS","LIST_TESTS"};
	out << "==============================" << endl;
	out << "Mode            =  " << strMode[config.mode] << endl;
	out << "Action          =  " << strAction[config.action] << endl;
	out << "Display_Success =  " << config.displaySuccess << endl;
	out << "Display_Details =  " << config.displayDetails << endl;
	out << "Output_filename =  " << config.filename << endl;
	out << "==============================" << endl;
	return out;
}

/*******************  FUNCTION  *********************/
/**
 * Methode used to clone the given argument of program for internal use. This is to avoid issues
 * if apply changes int the argument list, so we done chanes only on our internal copy.
 * @param argc Define the number of arguements given to the program.
 * @param argv Define the list of arguments given to the program.
 * @return Return the cloned array.
**/
char** svutRunnerConfig::cloneArgv(int argc, const char * argv[]) const
{
	char ** res = new char*[argc+1];
	int size;

	//nothing to do
	if (argv == NULL) return NULL;
	
	for (int i = 0 ; i < argc ; ++i)
	{
		size = strlen(argv[i]) + 1;
		res[i] = new char[size];
		strncpy(res[i],argv[i],size);
	}
	res[argc] = new char[1];
	*res[argc] = '\0';
	return res;
}

/*******************  FUNCTION  *********************/
/**
 * Methode used to free athe cloned arguments allocated by cloneArgv().
 * @param argc Define the number of arguements given to the program.
 * @param argv Define the list of arguments given to the program.
**/
void svutRunnerConfig::freeClonedArgv(int argc, char * argv[]) const
{
	//nothing to do
	if (argv == NULL) return;
	
	for (int i = 0 ; i < argc + 1 ; ++i)
	{
		if (argv[i] != NULL)
			delete argv[i];
	}
	delete argv;
}

/*******************  FUNCTION  *********************/
/**
 * Check if the current terminal support color mode.
 * @return true If color may be supported, false otherwise.
**/
bool svutRunnerConfig::checkColorUsability(void ) const
{
	//by pass only for unit test mode.
	if (__svut_bypass_color_mode__)
	{
		return true;
	} else {
		#ifdef HAVE_UNISTD_H
		return isatty(STDOUT_FILENO) == 1;
		#else
		return false;
		#endif
	}
}


}
