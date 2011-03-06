/*****************************************************
             PROJECT  : svUnitTest
             VERSION  : 0.3.0-dev
             DATE     : 03/2011
             AUTHOR   : Valat Sébastien
             LICENSE  : CeCILL-C
*****************************************************/

/********************  HEADERS  *********************/
#include <ios>
#include <sstream>
#include <cstring>
#include <cassert>
#include <iostream>
#include <cstdlib>
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
static const char SVUT_USAGE_KEY = (char)(255);
/** Define the default term size. **/
static const int SVUT_DEFAULT_COLUMNS = 80;

/*******************  FUNCTION  *********************/
/**
 * Default constructor, it defines the default arguments (help and usage).
 * @param autoExit If true, the parse() function will call abort() on arguement parsing error
 * after displaying error message.
**/
svutArgp::svutArgp(bool autoExit)
{
	this->setupDefaultOptions();
	this->autoExit = autoExit;
}

/*******************  FUNCTION  *********************/
/** Default virtual destructor. **/
svutArgp::~svutArgp(void )
{
}

/*******************  FUNCTION  *********************/
/**
 * Change the autoExit status.
 * @param autoExit If true, the parse() function will call abort() on arguement parsing error
 * after displaying error message.
**/
void svutArgp::setAutoExit ( bool autoExit )
{
	this->autoExit = autoExit;
}

/*******************  FUNCTION  *********************/
/**
 * Define the project name to use while generating the help string.
 * @param projectName Define the project name to use.
**/
void svutArgp::setProjectName(std::string projectName)
{
	this->projectName = projectName;
}

/*******************  FUNCTION  *********************/
/**
 * Define the project version to use while generating the help string.
 * @param projectVersion Define the project version to use.
**/
void svutArgp::setProjectVersion(std::string projectVersion)
{
	this->projectVersion = projectVersion;
}

/*******************  FUNCTION  *********************/
/**
 * Define a short description of the project to use while generating the help string.
 * @param projectDescr Short description of the project.
**/
void svutArgp::setProjectDescr(std::string projectDescr)
{
	this->projectDescr = projectDescr;
}

/*******************  FUNCTION  *********************/
/**
 * Define the email address to which report bugs.
 * @param projectBugAddress Define the selected mail address.
**/
void svutArgp::setProjectBugAddress(std::string projectBugAddress)
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
 * @throw svutExArgpDuplicateKey The given key already exist and can't be added.
**/
void svutArgp::decalareOption(char key, std::string name, std::string valueType, std::string descr) throw (svutExArgpDuplicateKey)
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
 * @return Return the number of columns available in current terminal.
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
void svutArgp::showHelp(std::ostream & out) const
{
	out << getHelp();
}

/*******************  FUNCTION  *********************/
/**
 * Function used to generate the string help.
 * @param columns Define the limit to use to split lines. Use -1 to none.
 * @return Return the help string directly formatted for the output.
**/
string svutArgp::getHelp(int columns) const
{
	stringstream str;
	int cols = this->getTermColumns();

	str << "Usage: " << this->projectName << " " << this->argUsage << endl;
	str << this->projectName << " -- " << this->projectDescr << endl << endl;

	//standard helps
	for (svutArgpOptionMap::const_iterator it = options.begin() ; it != options.end() ; ++it)
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
bool svutArgp::hasLongName(std::string name) const
{
	for (svutArgpOptionMap::const_iterator it = options.begin() ; it != options.end() ; ++it)
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
	res << arg.descr;

	//cut lines on columns and return
	return breakLines(res.str(),columns,SVUT_HELP_PADDING);
}

/*******************  FUNCTION  *********************/
/**
 * Function used to break lines at selected columns.
 * @param value Define the string line to cut.
 * @param columns Define the number of columns to consider.
 * @param pad Define the string used to pad new lines.
 * @return Return the string formatted to fit with given number of column.
**/
string svutArgp::breakLines ( std::string value, unsigned int columns , std::string pad) const
{
	bool firstLine = true;
	stringstream res;
	int pos;

	//check collums
	assert(columns > 0);
	
	//description
	while (value.size() > 0)
	{
		//pad
		if (!firstLine)
			res << endl << pad;
		if (value.size() < columns)
		{
			res << value;
			value.clear();
		} else {
			//cut the line on spaces
			pos = value.find_last_of(" ",columns);
			res << value.substr(0,pos);
			value = value.substr(pos,value.size());
		}
		firstLine = false;
	}

	return res.str();
}

/*******************  FUNCTION  *********************/
/**
 * Call the parseOption function, but before, intercept local parameters (--help and --usage).
 * @param key Define the key of arguement (the short name, eg. -v)
 * @param arg Define the given arguement in string format (-a or --all). For default value,
 *            it will be equal to value.
 * @param value Define the value given with the arguement if available.
 * @throw svutExArgpError Exception used to notify arguement error.
**/
void svutArgp::callParseOption ( char key, std::string arg, std::string value )  throw (svutExArgpError)
{
	switch (key)
	{
		case '?':
			this->showHelp();
			exit(0);
			break;
		case SVUT_USAGE_KEY:
			this->showUsage();
			exit(0);
			break;
		default:
			parseOption(key,arg,value);
	}
}

/*******************  FUNCTION  *********************/
/**
 * Generate string [--mode=MODE] or [-m MODE] from the given arguements.
 * The string will be preceded by a space.
 * @param arg Define the arguement to convert.
 * @param useShort Define if consider short arguement or long.
 * @return Return the usage string formatted as requested.
**/
std::string svutArgp::genUsageParam(const svutArgDef & arg,bool useShort) const
{
	stringstream res;

	if (useShort ==true && isValidKey(arg.key))
	{
		if (arg.valueType == "NONE")
			res << " [-" << arg.key << "]";
		else
			res << " [-" << arg.key << " " << arg.valueType << "]";
	} else if (useShort == false) {
		if (arg.valueType == "NONE")
			res << " [--" << arg.name << "]";
		else
			res << " [--" << arg.key << "=" << arg.valueType << "]";
	}

	return res.str();
}

/*******************  FUNCTION  *********************/
/**
 * Generate the help usage string, it will print all available options.
 * @param columns Define the number of columns to consider to cut lines.
 * @return Return the usage line as a string.
**/
string svutArgp::getUsage ( int columns ) const
{
	stringstream res;
	string shortNotArgGrouped;
	
	//show program name.
	res << "Usage: " << this->projectName;
	

	//usage for grouped short options
	for (svutArgpOptionMap::const_iterator it = options.begin() ; it != options.end() ; ++it)
		if (this->isValidKey(it->second.key) && it->second.valueType == "NONE")
			shortNotArgGrouped += it->second.key;
	if ( ! shortNotArgGrouped.empty() )
		res << " [-" << shortNotArgGrouped << "]";

	//usage for short option with values
	for (svutArgpOptionMap::const_iterator it = options.begin() ; it != options.end() ; ++it)
		if (this->isValidKey(it->second.key) && it->second.valueType != "NONE")
			res << genUsageParam(it->second,true);

	//usage for long option without values
	for (svutArgpOptionMap::const_iterator it = options.begin() ; it != options.end() ; ++it)
		if (it->second.valueType == "NONE")
			res << genUsageParam(it->second,false);

	//usage for long option with values
	for (svutArgpOptionMap::const_iterator it = options.begin() ; it != options.end() ; ++it)
		if (it->second.valueType != "NONE")
			res << genUsageParam(it->second,false);

	//usage for short option without values
	for (svutArgpOptionMap::const_iterator it = options.begin() ; it != options.end() ; ++it)
		if (this->isValidKey(it->second.key) && it->second.valueType == "NONE")
			res << genUsageParam(it->second,true);

	return breakLines(res.str(),columns,"           ");
}

/*******************  FUNCTION  *********************/
/**
 * Generate the usage string and print it into the given output stream (cout by default).
 * @param out Define the output stream to use.
**/
void svutArgp::showUsage ( std::ostream& out ) const
{
	out << getUsage(this->getTermColumns()) << endl;
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
 * @return True in case of success, false otherwise. This is not revelant when activating autoExit
 *            as the program will automatically exit on error.
**/
bool svutArgp::parse(int argc, const char* argv[],std::ostream & err)
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
				this->callParseOption(SVUT_ARG_DEFAULT,argv[i],argv[i]);
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

	//autoexit
	if (status == false && autoExit)
	{
		this->showHelp(err);
		exit(EXIT_FAILURE);
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
int svutArgp::scanLongOption(std::string name, int argc, const char* argv[]) throw (svutExArgpError)
{
	size_t cut = name.find_first_of("=");
	svutArgpOptionMap::const_iterator it = options.begin();
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
			this->callParseOption(it->second.key,"--"+name,"");
		} else if (cut != string::npos && it->second.valueType == "NONE") {
			stringstream message;
			message << "Argument error, --" << tmp << " may not to be followed by a value '" << it->second.valueType << "'";
			throw svutExArgpError(message.str());
		} else if (cut == string::npos && it->second.valueType != "NONE") {
			stringstream message;
			message << "Argument error, --" << tmp << " had to be followed by a value '" << it->second.valueType << "'";
			throw svutExArgpError(message.str());
		} else {
			this->callParseOption(it->second.key,"--"+name,name.substr(cut+1,name.size()));
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
 * @param list Define the short option (without -), optionnaly grouped (-XYZ equivalent to -X -Y -Z).
 * @param argc Define the number of remaining arguments (starting ont the -k one)
 * @param argv Define the remaining arguments (starting ont the -k one)
 * @return Return number of steps to increment for moving into arguments. One for trigger, two if
 *         the arguement use a value.
 * @throw svutExArgpError Transmet error caming from parseOption or multiple arguments with values.
**/
int svutArgp::scanShortOptions(std::string list, int argc, const char* argv[]) throw (svutExArgpError)
{
	int res = 1;
	svutArgpOptionMap::const_iterator it;

	//scan all options
	for ( size_t i = 0 ; i < list.size() ; ++i )
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
 * @return Return 2 if use the next arguement to read related value, 1 otherwise.
**/
int svutArgp::scanCheckedOption(const svutArgDef& option, int shortKey, int argc, const char* argv[])  throw (svutExArgpError)
{
	char arg[] = {'-',option.key,'\0'};
	if (option.valueType == "NONE") {
		this->callParseOption(option.key,arg,"");
		return 1;
	} else if (argc <= 1) {
		stringstream message;
		if (shortKey)
			message << "Argument error, -" << option.key << " had to be followed by a value '" << option.valueType << "'";
		else
			message << "Argument error, --" << option.name << " had to be followed by a value '" << option.valueType << "'";
		throw svutExArgpError(message.str());
	} else {
		this->callParseOption(option.key,arg,argv[1]);
		return 2;
	}
}

/*******************  FUNCTION  *********************/
/**
 * Give a simple example of arguement usage to display into the help, prefered fit into ne line.
 * As example : "[OPTION...] [-m MODE] [-v] [-s] [-?]"
 * @param argUsage Define the argument usage string.
**/
void svutArgp::setProjectArgUsage(std::string argUsage)
{
	this->argUsage = argUsage;
}

/*******************  FUNCTION  *********************/
/**
 * Constructor of exception class for duplicated key error.
 * @param key Define the key responsible of the error.
**/
svutExArgpDuplicateKey::svutExArgpDuplicateKey(char key)
{
	this->key = key;
}

/*******************  FUNCTION  *********************/
/**
 * Constructor of exception class for duplicated arguement error.
 * @param name Define the arguement long name responsible of the error.
**/
svutExArgpDuplicateKey::svutExArgpDuplicateKey(std::string name)
{
	this->name = name;
	this->key = '\0';
}

/*******************  FUNCTION  *********************/
/**
 * @return Return the message related to the exception.
**/
std::string svutExArgpDuplicateKey::getMessage(void ) const
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
