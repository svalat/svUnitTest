/*****************************************************
             PROJECT  : svUnitTest
             VERSION  : 0.1.0
             DATE     : 02/2011
             AUTHOR   : Valat Sébastien
             LICENSE  : CeCILL-C
*****************************************************/

/********************  HEADERS  *********************/
#include <ios>
#include <sstream>
#include <cstring>
#include <cassert>
#include <iostream>
#include "svutArgp.h"

/**********************  USING  *********************/
using namespace std;

/********************  NAMESPACE  *******************/
namespace svUnitTest
{

/********************  CONSTS  ***********************/
/** Define the string used to pad base help line. **/
static const char * SVUT_HELP_BASE_PADDING = "  ";
/** Define the string used to pad help breaked lines. **/
static const char * SVUT_HELP_PADDING = "                            ";
/** Define the key for --usage **/
static const char SVUT_USAGE_KEY = 255;
/** Define the default term size. **/
static const int SVUT_DEFAULT_COLUMNS = 80;

/*******************  FUNCTION  *********************/
/** Default constructor, it defines the default arguments (help and usage). **/
svutArgp::svutArgp(void )
{
	this->setupDefaultOptions();
}

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
	this->projectName = projectName;
}

/*******************  FUNCTION  *********************/
/**
 * Define the project version to use while generating the help string.
 * @param projectVersion Define the project version to use.
**/
void svutArgp::setProjectVersion(string projectVersion)
{
	this->projectVersion = projectVersion;
}

/*******************  FUNCTION  *********************/
/**
 * Define a short description of the project to use while generating the help string.
 * @param projectDescr Short description of the project.
**/
void svutArgp::setProjectDescr(string projectDescr)
{
	this->projectDescr = projectDescr;
}

/*******************  FUNCTION  *********************/
/**
 * Define the email address to which report bugs.
 * @param projectBugAddress Define the selected mail address.
**/
void svutArgp::setProjectBugAddress(string projectBugAddress)
{
	this->projectBugAddress = projectBugAddress;
}

/*******************  FUNCTION  *********************/
/**
 * Decalre a new option to accept in the parsor.
 * @param key Define the short trigger for the option (eg. -a). Non alphanumerique keys will not
 *             be used, you can use such keys to declare long name only options.
 * @param name Define the long name for the option (eg. --help). Caution, the -- will be added
 *             automatically. It can be empty for non long name.
 * @param valueType Define the type of the value, use NONE for simple triggers. Otherwise, you can
 *             use FILE, STRING ...., please use upper caption.
 * @param descr Define a short description for the new option.
 * @throw 
**/
void svutArgp::decalareOption(char key, string name, string valueType, string descr) throw (svutExArgpDuplicateKey)
{
	svutArgDef arg;
	arg.key = key;
	arg.name = name;
	arg.descr = descr;
	arg.valueType = valueType;

	if (options.find(key) != options.end() || key == SVUT_ARG_DEFAULT)
		throw svutExArgpDuplicateKey(key);
	if (hasLongName(name))
		throw svutExArgpDuplicateKey(name);
	options[arg.key] = arg;
}

/*******************  FUNCTION  *********************/
/**
 * Try to obtain the size of the xterm to known where to cut lines. Default will be SVUT_DEFAULT_COLUMNS columns.
**/
int svutArgp::getTermColumns(void) const
{
	return SVUT_DEFAULT_COLUMNS;
}

/*******************  FUNCTION  *********************/
/**
 * Function used to generate the help string and print it onto the standard output.
 * @param out Define the output stream to use.
**/
void svutArgp::showHelp(std::ostream & out)
{
	out << getHelp();
}

/*******************  FUNCTION  *********************/
/**
 * Function used to generate the string help.
 * @param columns Define the limit to use to split lines. Use -1 to none.
 * @return Return the help string directly formatted for the output.
**/
string svutArgp::getHelp(int columns)
{
	stringstream str;
	int cols = this->getTermColumns();

	str << "Usage: " << this->projectName << " " << this->argUsage << endl;
	str << this->projectName << " -- " << this->projectDescr << endl << endl;

	//standard helps
	for (map<char,svutArgDef>::const_iterator it = options.begin() ; it != options.end() ; ++it)
		if (it->first != '?' && it->first != SVUT_USAGE_KEY)
			str << formatArgumentHelp(it->second,cols) << endl;

	//special helps
	str << formatArgumentHelp(options.find('?')->second,cols) << endl;
	str << formatArgumentHelp(options.find(SVUT_USAGE_KEY)->second,cols) << endl;

	str << endl;
	str << "Mandatory or optional arguments to long options are also mandatory or optional" << endl;
	str << "for any corresponding short options." << endl;

	return str.str();
}

/*******************  FUNCTION  *********************/
/**
 * Check is the given long option name is defined.
 * @param name Define the name to search.
 * @return Return true if defined, false otherwise.
**/
bool svutArgp::hasLongName(string name) const
{
	for (map<char,svutArgDef>::const_iterator it = options.begin() ; it != options.end() ; ++it)
		if (it->second.name == name)
			return true;
	return false;
}

/*******************  FUNCTION  *********************/
/**
 * Check if the given key was valid or not for a display into --help.
 * @param key Define the key to test.
 * @return True if it was valid, false otherwise.
**/
bool svutArgp::isValidKey(char key) const
{
	return (  (key >= 'a' && key <= 'z')
	       || (key >= 'A' && key <= 'Z')
	       || (key >= '0' && key <= '9')
	       || (key == '?' ));
}


/*******************  FUNCTION  *********************/
/**
 * Generate and return the help string for the given arguement.
 * @param arg Define the arguement for wich to generate the help line.
 * @param columns Define the term width to consider for line splitting.
 * @return Return the generated string.
**/
string svutArgp::formatArgumentHelp(svutArgDef arg,int columns) const
{
	stringstream res;
	stringstream tmp;
	int pos = 0;
	bool firstLine = true;

	//check collums
	assert(columns > 0);
	columns -= strlen(SVUT_HELP_PADDING);

	//setup keys mode
	bool hasShort = isValidKey(arg.key);
	bool hasLong = ! arg.name.empty();

	//base padding
	res << SVUT_HELP_BASE_PADDING;

	//short arg
	if (hasShort)
		res << '-' << arg.key;
	else
		res << "  ";

	//separator
	if (hasShort && hasLong)
		res << ", --";
	else
		res << "  --";

	//long name
	res.width(21);
	res.fill(' ');
	res.setf(ios::left);
	tmp << arg.name;
	if (arg.valueType != "NONE")
		tmp << '=' << arg.valueType;
	res << tmp.str();

	//description
	while (arg.descr.size() > 0)
	{
		//pad
		if (!firstLine)
			res << endl << SVUT_HELP_PADDING;
		if (arg.descr.size() < columns)
		{
			res << arg.descr;
			arg.descr.clear();
		} else {
			//cut the line on spaces
			pos = arg.descr.find_last_of(" ",columns);
			res << arg.descr.substr(0,pos);
			arg.descr = arg.descr.substr(pos,arg.descr.size());
		}
		firstLine = false;
	}

	return res.str();
}

/*******************  FUNCTION  *********************/
/**
 * Clear all defined options.
**/
void svutArgp::clearOptions(void )
{
	this->options.clear();
	this->setupDefaultOptions();
}

/*******************  FUNCTION  *********************/
/**
 * Function to call to parse the program arguments. It will :
 *  - call parseInit
 *  - call parseOption for each arguement after small checkings.
 *  - call parseTerminate
 * The parsor will not keep references to those arguments.
 * @param argc Number of arguments given to the program (the ones from main)
 * @param argv List of arguement given to the program (the ones from main)
 * @param err Define the error stream to use to notify the user, std::cerr by default. This is mode
 *            for unit testing svutArgp.
**/
bool svutArgp::parse(int argc, const char* argv[],ostream & err)
{
	//vars
	bool status = false;
	int i = 1;

	//errors
	if (argc < 1 || argv == NULL)
	{
		err << "Invalid parameter, argc must be >= 1 and argv != NULL" << endl;
		return false;
	}

	try {
		//init
		this->parseInit();

		//parse
		while( i < argc )
		{
			if (argv[i][0] != '-')
			{
				//this is not a -X or --XLong
				this->parseOption(SVUT_ARG_DEFAULT,argv[i]);
				++i;
			} else if (argv[i][1]=='-') {
				i += this->scanLongOption(argv[i]+2,argc-i,argv+i);
			} else {
				i += this->scanShortOptions(argv[i]+1,argc-i,argv+i);
			}
		}

		//end
		this->parseTerminate();

		status = true;
	} catch (svutExArgpError & e) {
		err << e.getMessage() << endl;
		status = false;
	}

	//return
	return status;
}

/*******************  FUNCTION  *********************/
/**
 * Function used to scan long options. It will search the option in the option list to check if
 * exist. Check related values and send it to parseOption is valid.
 * @param name Define the option name (without --)
 * @param argc Define the number of remaining arguments (starting ont the --name one)
 * @param argv Define the remaining arguments (starting ont the --name one)
 * @return Return number of steps to increment for moving into arguments. One for trigger, two if
 *         the arguement use a value.
 * @throw svutExArgpError Transmet error caming from parseOption.
**/
int svutArgp::scanLongOption(string name, int argc, const char* argv[]) throw (svutExArgpError)
{
	int cut = name.find_first_of("=");
	std::map<char,svutArgDef>::const_iterator it = options.begin();
	string tmp = name.substr(0,cut);
	
	//search option
 	while( it != options.end() && it->second.name != tmp)
 		++it;

	if (it == options.end())
	{
		stringstream message;
		message << "Uknown option --" << tmp;
		throw svutExArgpError(message.str());
	} else {
		if (cut == string::npos && it->second.valueType == "NONE")
		{
			this->parseOption(it->second.key,"");
		} else if (cut != string::npos && it->second.valueType == "NONE") {
			stringstream message;
			message << "Argument error, --" << tmp << " may not to be followed by a value '" << it->second.valueType << "'";
			throw svutExArgpError(message.str());
		} else if (cut == string::npos && it->second.valueType != "NONE") {
			stringstream message;
			message << "Argument error, --" << tmp << " had to be followed by a value '" << it->second.valueType << "'";
			throw svutExArgpError(message.str());
		} else {
			this->parseOption(it->second.key,name.substr(cut+1,name.size()));
		}
	}
	return 1;
}

/*******************  FUNCTION  *********************/
/**
 * Function used to scan short options. It will search the option in the option list to check if
 * exist. Check related values and send it to parseOption is valid. Short options can be agregated
 * on the form -XYZ which is equivalent to -X -Y -Z. It can manage only one arguement requiering a
 * value per groupe otherwise it will report an error.
 * @param name Define the option name (without -)
 * @param argc Define the number of remaining arguments (starting ont the -k one)
 * @param argv Define the remaining arguments (starting ont the -k one)
 * @return Return number of steps to increment for moving into arguments. One for trigger, two if
 *         the arguement use a value.
 * @throw svutExArgpError Transmet error caming from parseOption or multiple arguments with values.
**/
int svutArgp::scanShortOptions(string list, int argc, const char* argv[]) throw (svutExArgpError)
{
	int res = 1;
	int tmp = 0;
	std::map<char,svutArgDef>::const_iterator it;

	//scan all options
	for ( int i = 0 ; i < list.size() ; ++i )
	{
		it = options.find(list[i]);
		if (it == options.end())
		{
			stringstream message;
			message << "Unknown option -" << list[i];
			throw svutExArgpError(message.str());
		} else if (res == 2 && it->second.valueType != "NONE" ) {
			stringstream message;
			message << "You can't group multiple short arguments waiting values : -" << list;
			throw svutExArgpError(message.str());
		} else {
			res = this->scanCheckedOption(it->second,true,argc,argv);
		}
	}

	return res;
}

/*******************  FUNCTION  *********************/
/**
 * Methode used to finally fetch the related value if needed and call parseOption.
 * @param option Define the option to call.
 * @param shortKey Define if we got the short key of long name for eventual error message formatting.
 * @param argc Define the number of remaining arguments (starting ont the -k or --name one)
 * @param argv Define the remaining arguments (starting ont the -k or --name one)
 * @throw svutExArgpError Transmet error caming from parseOption
**/
int svutArgp::scanCheckedOption(const svutArgDef& option, int shortKey, int argc, const char* argv[])  throw (svutExArgpError)
{
	if (option.valueType == "NONE") {
		this->parseOption(option.key,"");
		return 1;
	} else if (argc <= 1) {
		stringstream message;
		if (shortKey)
			message << "Argument error, -" << option.key << " had to be followed by a value '" << option.valueType << "'";
		else
			message << "Argument error, --" << option.name << " had to be followed by a value '" << option.valueType << "'";
		throw svutExArgpError(message.str());
	} else {
		this->parseOption(option.key,argv[1]);
		return 2;
	}
}

/*******************  FUNCTION  *********************/
/**
 * Give a simple example of arguement usage to display into the help, prefered fit into ne line.
 * As example : "[OPTION...] [-m MODE] [-v] [-s] [-?]"
 * @param argUsage Define the argument usage string.
**/
void svutArgp::setProjectArgUsage(string argUsage)
{
	this->argUsage = argUsage;
}

/*******************  FUNCTION  *********************/
/**
 * Constructor of exception class for duplicated key error.
**/
svutExArgpDuplicateKey::svutExArgpDuplicateKey(char key)
{
	this->key = key;
}

/*******************  FUNCTION  *********************/
svutExArgpDuplicateKey::svutExArgpDuplicateKey(string name)
{
	this->name = name;
	this->key = '\0';
}

/*******************  FUNCTION  *********************/
/**
 * Return the message related to the exception.
**/
string svutExArgpDuplicateKey::getMessage(void ) const
{
	stringstream message;
	if ( key == '\0' )
		message << "Option '" << name << "' already defined, please use another one.";
	else
		message << "Key '" << key << "' already defined, please use another one.";
	return message.str();
}

/*******************  FUNCTION  *********************/
/**
 * Initialized the default options into the parseur.
**/
void svutArgp::setupDefaultOptions(void )
{
	this->decalareOption('?',"help","NONE","Give this help list");
	this->decalareOption(SVUT_USAGE_KEY,"usage","NONE","Give a short usage message");
}

}
