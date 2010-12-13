/*****************************************************
             PROJECT  : svmath
             VERSION  : 0.0.1
             DATE     : 10/2009
             AUTHOR   : Valat Sébastien
             LICENSE  : CeCILL-C
*****************************************************/

/********************  HEADERS  *********************/
#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include <cstdlib>
#include <argp.h>
#include <cstring>
#include <iostream>
#include <fstream>
#include "svutRunnerConfig.h"

/**********************  USING  *********************/
using namespace std;

/********************  NAMESPACE  *******************/
namespace svUnitTest
{

/*********************  GLOBALS  ********************/
/** Define the program version. **/
static char program_version[128];
/** Pointer to the chain containing the version of library. **/
const char *argp_program_version = NULL;
/** Define address of developper to join in case of bug. **/
const char *argp_program_bug_address = "<sebastien.valat.dev@orange.fr>";
/** Descrive the program. **/
const char SVUT_ARGP_DOC[] ="svUnitTest -- Unit test library for C/C++ language.";
/** Command line argument format. **/
static const char SVUT_ARGS_DOC[] = "[-m MODE] [-v] [-s] [-?]";

/** Définit l'aide des arguments proposé par le programme. **/
static struct argp_option RS_OPTIONS[] = {
	{"mode",       'm',    "MODE",      0,  "Define the render mode to use : xml, qt_xml, std,"
	                                        "color (color is defaut).",NULL },
	{"verbose",    'v',      NULL,      0,  "Display all the test results, event the success."
	                                        ,NULL},
	{"silent",     's',      NULL,      0,  "Don't display extra information on test failure",NULL },
	{"functions",  'f',      NULL,      0,  "List all the accessible tests methods.",NULL},
	{"qtxml",      'q',      NULL,      0,  "Equivalent to -m qt_xml.",NULL},
	{"output",     'o',    "FILE",      0,  "Define the output file to use. Use - for stdout.",NULL},
	{"accept",     'a',    "NAME",      0,  "Accept only methods add with -a. in format testCase::function.",NULL},
	{ 0,0,0,0,0,0 }
};

/********************  METHODE  *********************/
/**
 * Method used to parse arguements and setup related value. This Glibc will call this metho for
 * each parameter encoutered with the given values.
 
 * @param key Define the key of current parsed arguement (the short name).
 * @param arg Define the chain passed with the arguement if available (-a {arg}).
 * @param state Define the status of parser. This structure mainly contain our svutRunnerConfig
 * object to know were to place the values.
**/
static error_t parse_opt(int key, char *arg, struct argp_state *state)
{
	/* Get the input argument from argp_parse, which we
	know is a pointer to our arguments structure. */
	svutRunnerConfig &config = *(svutRunnerConfig*)state->input;

	switch (key)
	{
		case 'm'://progress bar
			if (strncmp("xml",arg,3) == 0) {
				config.setMode(SVUT_OUT_XML);
			} else if (strncmp("qt_xml",arg,6) == 0) {
				config.setMode(SVUT_OUT_QT_XML);
			} else if (strncmp("std",arg,3) == 0) {
				config.setMode(SVUT_OUT_STD_BW);
			} else if (strncmp("color",arg,3) == 0) {
				config.setMode(SVUT_OUT_STD_COLOR);
			}else {
				cerr << "Unknown render mode : " << arg << endl;
				cerr << "Supported modes are xml, qt_xml, std and color." << endl;
				return ARGP_ERR_UNKNOWN;
			}
			break;
		case 'a'://accept
			if (config.addBasicAccept(arg) == false)
			{
				cerr << "Bad format for the filter : " << arg << endl;
				return ARGP_ERR_UNKNOWN;
			}
			break;
		case 'q'://mode xml compatible QT
			config.setMode(SVUT_OUT_QT_XML);
			break;
		case 'v'://verbose mode
			config.setDisplaySuccess(true);
			break;
		case 's'://silent error
			config.setDisplayDetails(false);
			break;
		case 'f':
			config.setAction(SVUT_ACTION_LIST_TESTS);
			break;
		case 'o':
			config.setOutput(arg);
			break;
		default://unknown arg
			return ARGP_ERR_UNKNOWN;
	}
	return 0;
}

/********************  METHODE  *********************/
/**
 * Default constructeur of the config class.
**/
svutRunnerConfig::svutRunnerConfig(void)
{
	this->init();
}

/********************  METHODE  *********************/
/**
 * Close all the inner data of the class at destroy time. Mainly the output stream if
 * one is defined.
**/
svutRunnerConfig::~svutRunnerConfig(void)
{
	this->closeFile();
}

/********************  METHODE  *********************/
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

/********************  METHODE  *********************/
/**
 * Constructor accepting main arguments to autmatically setup the values from programe arguments.
 * @param argc Define the number of parameters passed to the program.
 * @param argv Define the parameter list passed to the program.
**/
svutRunnerConfig::svutRunnerConfig(int argc,  const char * argv[])
{
	this->init();
	this->loadParams(argc,argv);
}

/********************  METHODE  *********************/
/**
 * Methode used to call the glibc parser to extract values from program calling arguments.
 * @param argc Define the number of parameters passed to the program.
 * @param argv Define the parameter list passed to the program.
**/
void svutRunnerConfig::loadParams(int argc, const char * argv[])
{
	if (argp_program_version == NULL)
	{
		argp_program_version = svUnitTest::program_version;
		sprintf(svUnitTest::program_version,"svUnitTest %s",VERSION);
	}
	const argp opts = { RS_OPTIONS, parse_opt, SVUT_ARGS_DOC, SVUT_ARGP_DOC ,NULL,NULL,NULL};
	char ** localArgv = cloneArgv(argc,argv);
	qtCompat(argc,localArgv);
	argp_parse (&opts, argc, localArgv, 0, 0, this);
	freeClonedArgv(argc,localArgv);
}

/********************  METHODE  *********************/
/**
 *  @return Return the display mode to use.
**/
svutOutputMode svutRunnerConfig::getMode(void) const
{
	return mode;
}

/********************  METHODE  *********************/
/**
 * @return Return true if need to display success tests or not.
**/
bool svutRunnerConfig::hasDisplaySuccess(void) const
{
	return displaySuccess;
}

/********************  METHODE  *********************/
/**
 * @return Return true if the details need to be displayed on test failure.
**/
bool svutRunnerConfig::hasDisplayDetails(void) const
{
	return displayDetails;
}

/********************  METHODE  *********************/
/**
 * Initiate options with their default values.
**/
void svutRunnerConfig::init(void)
{
	mode = SVUT_OUT_STD_COLOR;
	displaySuccess = false;
	displayDetails = true;
	action = SVUT_ACTION_RUN_TESTS;
	filename = "";
	outputStream = NULL;
	externalOutputStream = NULL;
}

/********************  METHODE  *********************/
/**
 * Enable or disable the display of details in case of test failure.
 * @param state True to display, false to not.
**/
void svutRunnerConfig::setDisplayDetails(bool state)
{
	displayDetails = state;
}

/********************  METHODE  *********************/
/**
 * Enable or disable the display of success tests.
 * @param state True to display, false to hide.
**/
void svutRunnerConfig::setDisplaySuccess(bool state)
{
	displaySuccess = state;
}

/********************  METHODE  *********************/
/**
 * Setup the display output mode to use.
 * @param mode Define the selected output mode.
**/
void svutRunnerConfig::setMode(svutOutputMode mode)
{
	this->mode = mode;
}

/********************  METHODE  *********************/
/**
 * @return Return the action to execute.
**/
svutRunnerAction svutRunnerConfig::getAction(void) const
{
	return this->action;
}

/********************  METHODE  *********************/
/**
 * Setup the action to execut when running the test suite.
 * @param action Define the action which may be done by the test runner.
**/
void svutRunnerConfig::setAction(svutRunnerAction action)
{
	this->action = action;
}

/********************  METHODE  *********************/
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

/********************  METHODE  *********************/
/**
 * Define the output file to use. If not defined, use the standard output (default value).
 * @param filename Define the output file to use.
**/
void svutRunnerConfig::setOutput(std::string filename)
{
	this->closeFile();
	this->filename = filename;
	this->externalOutputStream = NULL;
}

/********************  METHODE  *********************/
/**
 * Define an external output stream totaly managed by the use.
 * @param stream Define the output stream to use.
**/
void svutRunnerConfig::setOutput(ostream & stream)
{
	this->closeFile();
	this->filename = "";
	this->externalOutputStream = &stream;
}


/********************  METHODE  *********************/
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

/********************  METHODE  *********************/
/**
 * Add an entry to the basic test fileter.
 * @param caseName Define the test case to accept ; empty to say 'all'.
 * @param function Define the function name to accept ; empty to say 'all'.
**/
void svutRunnerConfig::addBasicAccept(std::string caseName,std::string function)
{
// 	filter.addAccepted(caseName,function);
}

/********************  METHODE  *********************/
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

/********************  METHODE  *********************/
/**
 * @return Return the test filter to use.
**/
// svutTestFilter & svutRunnerConfig::getFilter(void)
// {
// 	return filter;
// }

/********************  METHODE  *********************/
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

/********************  METHODE  *********************/
/**
 * Methode used to clone the given argument of program for internal use. This is to avoid issues
 * if apply changes int the argument list, so we done chanes only on our internal copy.
 * @param argc Define the number of arguements given to the program.
 * @param argv Define the list of arguments given to the program.
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

/********************  METHODE  *********************/
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


};