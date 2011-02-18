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
		virtual void parseOption(char key,std::string value) throw (svutExArgpError);
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
	CPPUNIT_TEST(testParse_1);
	CPPUNIT_TEST(testParse_2);
	CPPUNIT_TEST(testParse_3);
	CPPUNIT_TEST(testDeclareOption_ok);
	CPPUNIT_TEST(testDeclareOption_dupKey);
	CPPUNIT_TEST(testDeclareOption_dupName);
	CPPUNIT_TEST(testClearOptions);
	CPPUNIT_TEST(testGetHelp);
	CPPUNIT_TEST(testShowHelp);
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
		void testParse_1(void);
		void testParse_2(void);
		void testParse_3(void);
		void testDeclareOption_ok(void);
		void testDeclareOption_dupKey(void);
		void testDeclareOption_dupName(void);
		void testClearOptions(void);
		void testGetHelp(void);
		void testShowHelp(void);

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
void UnitTest_svutArgp::testParse_1(void )
{
	CPPUNIT_FAIL("todo");
}

/*******************  FUNCTION  *********************/
void UnitTest_svutArgp::testParse_2(void )
{
	CPPUNIT_FAIL("todo");
}

/*******************  FUNCTION  *********************/
void UnitTest_svutArgp::testParse_3(void )
{
	CPPUNIT_FAIL("todo");
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
void UnitTest_MyArgp::parseOption(char key, string value) throw (svutExArgpError)
{
	if ( ! this->parsedOptions.empty() )
		this->parsedOptions += " ; ";
	
	this->parsedOptions += key;
	this->parsedOptions += ':';
	this->parsedOptions += value;

	if (key == 'e')
		throw svutExArgpError("This is an error in parsing of arguement -e.");
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
