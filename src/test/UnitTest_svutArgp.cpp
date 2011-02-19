/*****************************************************
             PROJECT  : svUnitTest
             VERSION  : 0.1.0
             DATE     : 02/2011
             AUTHOR   : Valat Sébastien
             LICENSE  : CeCILL-C
*****************************************************/

/********************  HEADERS  *********************/
#include <iostream>
#include <cppunit/TestCase.h>
#include <cppunit/extensions/TestFactoryRegistry.h>
#include <cppunit/extensions/HelperMacros.h>
#include "UnitTestExtra.h"
#include <svutArgp.h>
#include <string>
#include <sstream>

/********************  CONSTS  ***********************/
static const char * CST_STRING_HELP_0 = "Usage: myApp [OPTION...] [-m MODE] [-v] [-s] [-?]\n\
myApp -- This is a test application\n\
\n\
  -a, --accept               Accept things\n\
  -m, --mode=MODE            Define the render mode to use : xml, qt_xml, std,\n\
                             color (color is defaut)\n\
  -o, --output=FILE          Define the output file to use. Use - for stdout\n\
  -?, --help                 Give this help list\n\
      --usage                Give a short usage message\n\
\n\
Mandatory or optional arguments to long options are also mandatory or optional\n\
for any corresponding short options.\n";
static const char * CST_STRING_HELP_1 = "Usage: myProjectV2 [OPTION...] [-m MODE] [-v] [-s] [-?]\n\
myProjectV2 -- This is a test application\n\
\n\
  -a, --accept               Accept things\n\
  -m, --mode=MODE            Define the render mode to use : xml, qt_xml, std,\n\
                             color (color is defaut)\n\
  -o, --output=FILE          Define the output file to use. Use - for stdout\n\
  -?, --help                 Give this help list\n\
      --usage                Give a short usage message\n\
\n\
Mandatory or optional arguments to long options are also mandatory or optional\n\
for any corresponding short options.\n";
static const char * CST_STRING_HELP_2 = "Usage: myApp [OPTION...] [-m MODE] [-v] [-s] [-?]\n\
myApp -- This is a test application\n\
\n\
  -a, --accept               Accept things\n\
  -m, --mode=MODE            Define the render mode to use : xml, qt_xml, std,\n\
                             color (color is defaut)\n\
  -o, --output=FILE          Define the output file to use. Use - for stdout\n\
  -v, --verbose              Display more messages\n\
  -?, --help                 Give this help list\n\
      --usage                Give a short usage message\n\
\n\
Mandatory or optional arguments to long options are also mandatory or optional\n\
for any corresponding short options.\n";
static const char * CST_STRING_HELP_3 = "Usage: myApp [OPTION...] [-m MODE] [-v] [-s] [-?]\n\
myApp -- This is a test application\n\
\n\
  -?, --help                 Give this help list\n\
      --usage                Give a short usage message\n\
\n\
Mandatory or optional arguments to long options are also mandatory or optional\n\
for any corresponding short options.\n";
static const char * CST_STRING_HELP_4 = "Usage: myApp [OPTION...] [-m MODE] [-v] [-s] [-?]\n\
myApp -- New description\n\
\n\
  -a, --accept               Accept things\n\
  -m, --mode=MODE            Define the render mode to use : xml, qt_xml, std,\n\
                             color (color is defaut)\n\
  -o, --output=FILE          Define the output file to use. Use - for stdout\n\
  -?, --help                 Give this help list\n\
      --usage                Give a short usage message\n\
\n\
Mandatory or optional arguments to long options are also mandatory or optional\n\
for any corresponding short options.\n";
static const char * CST_STRING_HELP_5 = "Usage: myApp [FILE...]\n\
myApp -- This is a test application\n\
\n\
  -a, --accept               Accept things\n\
  -m, --mode=MODE            Define the render mode to use : xml, qt_xml, std,\n\
                             color (color is defaut)\n\
  -o, --output=FILE          Define the output file to use. Use - for stdout\n\
  -?, --help                 Give this help list\n\
      --usage                Give a short usage message\n\
\n\
Mandatory or optional arguments to long options are also mandatory or optional\n\
for any corresponding short options.\n";
static const char * CST_STRING_USAGE_1 = "Usage: myApp [-?a] [-m MODE] [-o FILE] \
[--usage] [--help] [--accept] [--m=MODE]\n            [--o=FILE] [-?] [-a]";
static const char * CST_STRING_USAGE_2 = "Usage: myApp [-?a] [-m MODE] [-o FILE] \
[--usage] [--help] [--accept] [--m=MODE]\n            [--o=FILE] [-?] [-a]\n";

/**********************  USING  *********************/
using namespace svUnitTest;
using namespace CPPUNIT_NS;
using namespace std;

/*********************  CLASS  **********************/
class UnitTest_MyArgp : public svutArgp
{
	public:
		UnitTest_MyArgp(void);
		void resetMock(void);
		virtual void parseInit(void) throw (svutExArgpError);
		virtual void parseOption(char key,std::string arg,std::string value) throw (svutExArgpError);
		virtual void parseTerminate(void) throw (svutExArgpError);
		bool hasDoneParseInit;
		bool hasDoneParseTerminate;
		std::string parsedOptions;
};

/*********************  CLASS  **********************/
class UnitTest_svutArgp : public TestCase
{
	CPPUNIT_TEST_SUITE(UnitTest_svutArgp);
	CPPUNIT_TEST(testSetProjectName);
	CPPUNIT_TEST(testSetProjectVersion);
	CPPUNIT_TEST(testSetProjectBugAddress);
	CPPUNIT_TEST(testSetProjectDescr);
	CPPUNIT_TEST(testSetProjectArgumentUsage);
	CPPUNIT_TEST(testParse_ok);
	CPPUNIT_TEST(testParse_groupShort);
	CPPUNIT_TEST(testParse_groupShortError);
	CPPUNIT_TEST(testParse_unknownArgument);
	CPPUNIT_TEST(testParse_parsingError);
	CPPUNIT_TEST(testParse_argvNULL);
	CPPUNIT_TEST(testParse_argcZero);
	CPPUNIT_TEST(testParse_argNoValueShort);
	CPPUNIT_TEST(testParse_argNoValueLong);
	CPPUNIT_TEST(testDeclareOption_ok);
	CPPUNIT_TEST(testDeclareOption_dupKey);
	CPPUNIT_TEST(testDeclareOption_dupName);
	CPPUNIT_TEST(testClearOptions);
	CPPUNIT_TEST(testGetHelp);
	CPPUNIT_TEST(testShowHelp);
	CPPUNIT_TEST(testGetUsage);
	CPPUNIT_TEST(testShowUsage);
	CPPUNIT_TEST_SUITE_END();

	public:
		void setUp(void);
		void tearDown(void);

	protected:
		void testSetProjectName(void);
		void testSetProjectVersion(void);
		void testSetProjectBugAddress(void);
		void testSetProjectDescr(void);
		void testSetProjectArgumentUsage(void);
		void testParse_ok(void);
		void testParse_groupShort(void);
		void testParse_groupShortError(void);
		void testParse_unknownArgument(void);
		void testParse_parsingError(void);
		void testParse_argvNULL(void);
		void testParse_argcZero(void);
		void testParse_argNoValueShort(void);
		void testParse_argNoValueLong(void);
		void testDeclareOption_ok(void);
		void testDeclareOption_dupKey(void);
		void testDeclareOption_dupName(void);
		void testClearOptions(void);
		void testGetHelp(void);
		void testShowHelp(void);
		void testGetUsage(void);
		void testShowUsage(void);

		UnitTest_MyArgp * obj;
};

/*******************  FUNCTION  *********************/
void UnitTest_svutArgp::setUp(void)
{
	obj = new UnitTest_MyArgp();
	obj->setProjectName("myApp");
	obj->setProjectVersion("0.0.0");
	obj->setProjectDescr("This is a test application");
	obj->setProjectArgUsage("[OPTION...] [-m MODE] [-v] [-s] [-?]");
	obj->decalareOption('a',"accept","NONE","Accept things");
	obj->decalareOption('m',"mode","MODE","Define the render mode to use : xml, qt_xml, std, color (color is defaut)");
	obj->decalareOption('o',"output","FILE","Define the output file to use. Use - for stdout");
}

/*******************  FUNCTION  *********************/
void UnitTest_svutArgp::tearDown(void)
{
	delete obj;
}

/*******************  FUNCTION  *********************/
void UnitTest_svutArgp::testSetProjectName(void)
{
	obj->setProjectName("myProjectV2");
	CPPUNIT_ASSERT_EQUAL(CST_STRING_HELP_1,obj->getHelp());
}

/*******************  FUNCTION  *********************/
void UnitTest_svutArgp::testClearOptions(void )
{
	obj->clearOptions();
	CPPUNIT_ASSERT_EQUAL(CST_STRING_HELP_3,obj->getHelp());
}

/*******************  FUNCTION  *********************/
void UnitTest_svutArgp::testDeclareOption_ok(void )
{
	obj->decalareOption('v',"verbose","NONE","Display more messages");
	CPPUNIT_ASSERT_EQUAL(CST_STRING_HELP_2,obj->getHelp());
}

/*******************  FUNCTION  *********************/
void UnitTest_svutArgp::testDeclareOption_dupKey(void )
{
	obj->decalareOption('v',"verbose","NONE","Display more messages");
	try{
		obj->decalareOption('v',"verbose","NONE","Display more messages");
		CPPUNIT_FAIL("Expect to get svutExArgpDuplicateKey exception but nothing append.");
	} catch (svutExArgpDuplicateKey & e) {
		
	}
}

/*******************  FUNCTION  *********************/
void UnitTest_svutArgp::testDeclareOption_dupName(void )
{
	obj->decalareOption('z',"verbose","NONE","Display more messages");
	try{
		obj->decalareOption('v',"verbose","NONE","Display more messages");
		CPPUNIT_FAIL("Expect to get svutExArgpDuplicateKey exception but nothing append.");
	} catch (svutExArgpDuplicateKey & e) {

	}
}

/*******************  FUNCTION  *********************/
void UnitTest_svutArgp::testGetHelp(void )
{
	CPPUNIT_ASSERT_EQUAL(CST_STRING_HELP_0 , obj->getHelp());
}

/*******************  FUNCTION  *********************/
void UnitTest_svutArgp::testParse_ok(void )
{
	stringstream err;
	int argc = 5;
	const char * argv[] = {
		"program",
		"-a",
		"-m","test",
		"--output=testout"
	};

	CPPUNIT_ASSERT(obj->parse(argc,argv,err));
	CPPUNIT_ASSERT(obj->hasDoneParseInit);
	CPPUNIT_ASSERT(obj->hasDoneParseTerminate);
	CPPUNIT_ASSERT_EQUAL("a:-a ; m:-m:test ; o:--output=testout:testout",obj->parsedOptions);
	CPPUNIT_ASSERT(err.str().empty());
}

/*******************  FUNCTION  *********************/
void UnitTest_svutArgp::testParse_groupShort(void )
{
	stringstream err;
	int argc = 3;
	const char * argv[] = {
		"program",
		"-am",
		"test",
	};

	CPPUNIT_ASSERT(obj->parse(argc,argv,err));
	CPPUNIT_ASSERT(obj->hasDoneParseInit);
	CPPUNIT_ASSERT(obj->hasDoneParseTerminate);
	CPPUNIT_ASSERT_EQUAL("a:-a ; m:-m:test",obj->parsedOptions);
	CPPUNIT_ASSERT(err.str().empty());
}

/*******************  FUNCTION  *********************/
void UnitTest_svutArgp::testParse_groupShortError(void )
{
	stringstream err;
	int argc = 4;
	const char * argv[] = {
		"program",
		"-amo",
		"test",
		"testoutput",
	};

	CPPUNIT_ASSERT(obj->parse(argc,argv,err) == false);
	CPPUNIT_ASSERT(obj->hasDoneParseInit);
	CPPUNIT_ASSERT(obj->hasDoneParseTerminate == false);
	CPPUNIT_ASSERT_EQUAL("a:-a ; m:-m:test",obj->parsedOptions);
	CPPUNIT_ASSERT_EQUAL("You can't group multiple short arguments waiting values : -amo\n",err.str());
}

/*******************  FUNCTION  *********************/
void UnitTest_svutArgp::testParse_unknownArgument(void )
{
	stringstream err;
	int argc = 3;
	const char * argv[] = {
		"program",
		"-f",
		"test",
	};

	CPPUNIT_ASSERT(obj->parse(argc,argv,err) == false);
	CPPUNIT_ASSERT(obj->hasDoneParseInit);
	CPPUNIT_ASSERT(obj->hasDoneParseTerminate == false);
	CPPUNIT_ASSERT_EQUAL("",obj->parsedOptions);
	CPPUNIT_ASSERT_EQUAL("Unknown option -f\n",err.str());
}

/*******************  FUNCTION  *********************/
void UnitTest_svutArgp::testParse_parsingError(void )
{
	stringstream err;
	int argc = 3;
	const char * argv[] = {
		"program",
		"-e",
	};

	obj->decalareOption('e',"--expert","NONE","This is a stange option which crash.");
	CPPUNIT_ASSERT(obj->parse(argc,argv,err) == false);
	CPPUNIT_ASSERT(obj->hasDoneParseInit);
	CPPUNIT_ASSERT(obj->hasDoneParseTerminate == false);
	CPPUNIT_ASSERT_EQUAL("e:-e",obj->parsedOptions);
	CPPUNIT_ASSERT_EQUAL("This is an error in parsing of argument -e.\n",err.str());
}

/*******************  FUNCTION  *********************/
void UnitTest_svutArgp::testParse_argvNULL(void )
{
	stringstream err;
	int argc = 3;

	CPPUNIT_ASSERT(obj->parse(argc,NULL,err) == false);
	CPPUNIT_ASSERT(obj->hasDoneParseInit == false);
	CPPUNIT_ASSERT(obj->hasDoneParseTerminate == false);
	CPPUNIT_ASSERT_EQUAL("",obj->parsedOptions);
	CPPUNIT_ASSERT_EQUAL("Invalid parameter, argc must be >= 1 and argv != NULL\n",err.str());
}

/*******************  FUNCTION  *********************/
void UnitTest_svutArgp::testParse_argcZero(void )
{
	stringstream err;
	int argc = 0;
	const char * argv[] = {
		"program",
		"-e",
	};

	CPPUNIT_ASSERT(obj->parse(argc,argv,err) == false);
	CPPUNIT_ASSERT(obj->hasDoneParseInit == false);
	CPPUNIT_ASSERT(obj->hasDoneParseTerminate == false);
	CPPUNIT_ASSERT_EQUAL("",obj->parsedOptions);
	CPPUNIT_ASSERT_EQUAL("Invalid parameter, argc must be >= 1 and argv != NULL\n",err.str());
}

/*******************  FUNCTION  *********************/
void UnitTest_svutArgp::testParse_argNoValueLong(void )
{
	stringstream err;
	int argc = 2;
	const char * argv[] = {
		"program",
		"-m",
	};

	CPPUNIT_ASSERT(obj->parse(argc,argv,err) == false);
	CPPUNIT_ASSERT(obj->hasDoneParseInit == true);
	CPPUNIT_ASSERT(obj->hasDoneParseTerminate == false);
	CPPUNIT_ASSERT_EQUAL("",obj->parsedOptions);
	CPPUNIT_ASSERT_EQUAL("Argument error, -m had to be followed by a value 'MODE'\n",err.str());
}

/*******************  FUNCTION  *********************/
void UnitTest_svutArgp::testParse_argNoValueShort(void )
{
	stringstream err;
	int argc = 2;
	const char * argv[] = {
		"program",
		"--mode",
	};

	CPPUNIT_ASSERT(obj->parse(argc,argv,err) == false);
	CPPUNIT_ASSERT(obj->hasDoneParseInit == true);
	CPPUNIT_ASSERT(obj->hasDoneParseTerminate == false);
	CPPUNIT_ASSERT_EQUAL("",obj->parsedOptions);
	CPPUNIT_ASSERT_EQUAL("Argument error, --mode had to be followed by a value 'MODE'\n",err.str());
}

/*******************  FUNCTION  *********************/
void UnitTest_svutArgp::testSetProjectBugAddress(void )
{
	obj->setProjectBugAddress("sebastien.valat.dev@orange.fr");
	CPPUNIT_ASSERT_EQUAL(CST_STRING_HELP_0,obj->getHelp());
}

/*******************  FUNCTION  *********************/
void UnitTest_svutArgp::testSetProjectDescr(void )
{
	obj->setProjectDescr("New description");
	CPPUNIT_ASSERT_EQUAL(CST_STRING_HELP_4,obj->getHelp());
}

/*******************  FUNCTION  *********************/
void UnitTest_svutArgp::testSetProjectVersion(void )
{
	obj->setProjectVersion("1.0.0");
	CPPUNIT_ASSERT_EQUAL(CST_STRING_HELP_0,obj->getHelp());
}

/*******************  FUNCTION  *********************/
void UnitTest_svutArgp::testSetProjectArgumentUsage(void )
{
	obj->setProjectArgUsage("[FILE...]");
	CPPUNIT_ASSERT_EQUAL(CST_STRING_HELP_5,obj->getHelp());
}

/*******************  FUNCTION  *********************/
void UnitTest_svutArgp::testShowHelp(void )
{
	stringstream buffer;
	obj->showHelp(buffer);
	CPPUNIT_ASSERT_EQUAL(CST_STRING_HELP_0,obj->getHelp());
}

/*******************  FUNCTION  *********************/
void UnitTest_svutArgp::testGetUsage ( void )
{
	CPPUNIT_ASSERT_EQUAL(CST_STRING_USAGE_1,obj->getUsage());
}

/*******************  FUNCTION  *********************/
void UnitTest_svutArgp::testShowUsage ( void )
{
	stringstream out;
	obj->showUsage(out);
	CPPUNIT_ASSERT_EQUAL(CST_STRING_USAGE_2,out.str());
}

/*******************  FUNCTION  *********************/
UnitTest_MyArgp::UnitTest_MyArgp(void ): svutArgp()
{
	this->resetMock();
}

/*******************  FUNCTION  *********************/
void UnitTest_MyArgp::parseInit(void )  throw (svutExArgpError)
{
	this->hasDoneParseInit = true;
}

/*******************  FUNCTION  *********************/
void UnitTest_MyArgp::parseOption( char key, string arg, string value) throw (svutExArgpError)
{
	if ( ! this->parsedOptions.empty() )
		this->parsedOptions += " ; ";
	
	this->parsedOptions += key;
	this->parsedOptions += ':';
	this->parsedOptions += arg;
	if (!value.empty())
	{
		this->parsedOptions += ':';
		this->parsedOptions += value;
	}

	if (key == 'e')
		throw svutExArgpError("This is an error in parsing of argument -e.");
}

/*******************  FUNCTION  *********************/
void UnitTest_MyArgp::parseTerminate(void )  throw (svutExArgpError)
{
	this->hasDoneParseTerminate = true;
}

/*******************  FUNCTION  *********************/
void UnitTest_MyArgp::resetMock(void )
{
	this->hasDoneParseInit = false;
	this->hasDoneParseTerminate = false;
	this->parsedOptions.clear();
}


CPPUNIT_TEST_SUITE_REGISTRATION(UnitTest_svutArgp);
