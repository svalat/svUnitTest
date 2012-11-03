/*****************************************************
             PROJECT  : svUnitTest
             VERSION  : 0.5.0-dev
             DATE     : 11/2012
             AUTHOR   : Valat Sébastien
             LICENSE  : CeCILL-C
*****************************************************/

/********************  HEADERS  *********************/
#include <algorithm>
#include <iomanip>
#include <ctime>
#include "svutResultFormatterBoostXml.h"
#include "svUnitTest.h"
#include "svutResultFormatterHelper.h"

/**********************  USING  *********************/
using namespace std;

/********************  NAMESPACE  *******************/
namespace svUnitTest
{

/*******************  FUNCTION  *********************/
/**
 * Default constructor of the class.
 * @param out Define the output system into which to send the results.
**/
svUnitTest::svutResultFormatterBoostXml::svutResultFormatterBoostXml(std::ostream& out)
{
	this->out = & out;
	this->lastTestCase = NULL;
}

/*******************  FUNCTION  *********************/
/**
 * Display the header of the XML output file.
**/
void svUnitTest::svutResultFormatterBoostXml::openOutput(void )
{
	*out << "<?xml version='1.0' encoding='UTF-8'?>" << endl;
	//*out << "<!DOCTYPE UnitTest SYSTEM 'svUnitTest_html/svUnitTest.dtd'>" << endl;
	//*out << "<?xml-stylesheet type='text/xsl' href='svUnitTest_html/svUnitTest.xsl'?>" << endl;
	*out << "<TestLog>" << endl;
	printEnv();
	*out << "\t<TestSuite name='svUnitTest'>" << endl;
}

/*******************  FUNCTION  *********************/
/**
 * This is more for testing purpose to replace the real date by a fake one when testing.
 * It force a static date which made simpler to write output correcness test in the test suite.
 * @param date Define the date in string format to use instead of reading the current date.
**/
void svutResultFormatterBoostXml::setDate(std::string date)
{
	this->date = date;
}

/*******************  FUNCTION  *********************/
/**
 * Generate the test environnement description, mostly :
 *   - svUnitTest version.
 *   - execution date.
**/
void svutResultFormatterBoostXml::printEnv(void)
{
	*out << "\t<!--<TestEnv>" << endl;
	*out << "\t\t<LibVersion>" << SVUT_LIBARY_VERSION << "</LibVersion>" << endl;
	if (this->date.empty())
	{
		char buffer[64];
		time_t t;

		time(&t);
		#ifdef _MSC_VER
		struct tm timeinfo;
		localtime_s ( &timeinfo,&t );
		strftime(buffer, 64, "%Y-%m-%d %H:%M:%S %Z",&timeinfo);
		#else
		struct tm * timeinfo;
		timeinfo = localtime(&t);
		strftime(buffer, 64, "%Y-%m-%d %H:%M:%S %Z",timeinfo);
		#endif
		*out << "\t\t<TestDate>" << buffer << "</TestDate>" << endl;
	} else {
		*out << "\t\t<TestDate>" << this->date << "</TestDate>" << endl;
	}
	*out << "\t</TestEnv>-->" << endl;
}

/*******************  FUNCTION  *********************/
/**
 * Close the XML root elements to end the XML output file.
**/
void svutResultFormatterBoostXml::closeOutput(void )
{
	*out << "\t</TestSuite>" << endl;
	*out << "</TestLog>" << endl;
}

/*******************  FUNCTION  *********************/
void svutResultFormatterBoostXml::openTestCase(const svUnitTest::svutTestCase& testCase)
{
	*out << "\t<TestSuite name=\"" << escapeXmlCharsInString(testCase.getName()) << "\">" << endl;
}

/*******************  FUNCTION  *********************/
void svutResultFormatterBoostXml::closeTestCase(const svUnitTest::svutTestCase& /*testCase*/)
{
	*out << "\t</TestSuite>" << endl;
}

/*******************  FUNCTION  *********************/
void svutResultFormatterBoostXml::openTestMethod(const svUnitTest::svutTestCase& /*testCase*/, const svUnitTest::svutTestMethod& meth)
{
	*out << "\t\t<TestCase name=\"" << escapeXmlCharsInString(meth.getName()) << "\">" << endl;
}

/*******************  FUNCTION  *********************/
void svutResultFormatterBoostXml::closeTestMethod(const svUnitTest::svutTestCase& /*testCase*/, const svUnitTest::svutTestMethod& /*meth*/, const svUnitTest::svutStatusInfo& status)
{
	string statusLower = status.getStatusName();
	std::transform(statusLower.begin(), statusLower.end(), statusLower.begin(), ::tolower);
	*out << "\t\t\t<!--<status>" << statusLower << "</status>-->" << endl;
	if (status.getStatus() != SVUT_STATUS_SUCCESS && status.getStatus() != SVUT_STATUS_SKIPED)
		this->printAssertInfo(status);
	*out << "\t\t\t<TestingTime>" << setprecision(2) << (unsigned long)(status.getDuration() * 1000000.0) << "</TestingTime>" << endl;
	*out << "\t\t</TestCase>" << endl;
}

/*******************  FUNCTION  *********************/
void svUnitTest::svutResultFormatterBoostXml::printSummary(svutResultSummary summary)
{
	//no summary in boost format
}

/*******************  FUNCTION  *********************/
/**
 * Helper function to format the status assert informations into svUnitTest native XML format.
 * The final reste will be added to the output stream.
 * @param status Define the current status into which take the assert informations.
**/
void svUnitTest::svutResultFormatterBoostXml::printAssertInfo(const svUnitTest::svutStatusInfo& status)
{
	string statusName;
	int line = status.getLocation().getLine();
	if (line == -1) line = 0;

	if (status.getStatus() == SVUT_STATUS_UNKNOWN)
		statusName = "Error";
	else if (status.getStatus() == SVUT_STATUS_FAILED)
		statusName = "Error";

	if (status.getStatus() == SVUT_STATUS_FAILED || status.getStatus() == SVUT_STATUS_UNKNOWN)
	{
		*out << "\t\t\t<" << statusName;
		if (!status.getMessage().empty())
		{
			*out << " file=\"" << escapeXmlCharsInString(status.getLocation().getFilename())
			                    << "\" line=\"" << line << "\"";
		}
		*out << "><![CDATA[";
		*out << escapeXmlCharsInString(status.getMessage());

		status.formatEntries(*out,"   - "," : ","\n",escapeXmlCharsInString);
		if (status.getNbContextEntries() > 0)
		{
			*out << "Context :" << endl;
			status.formatContext(*out,"   - "," : ","\n",escapeXmlCharsInString);
		}

		if (!status.getOutput().empty())
			*out << "\t\t\tSystem-out:" << escapeXmlCharsInString(status.getOutput()) << endl;
		*out << "]]></" << statusName << ">" << endl;
	}
}

/*******************  FUNCTION  *********************/
/**
 * Helper function to format the location into svUnitTest native XML format.
 * The final reste will be added to the output stream.
 * @param location Define the location to format.
**/
void svutResultFormatterBoostXml::printLocation(const svUnitTest::svutCodeLocation& location)
{
	*out << "\t\t\t\t<location>" << endl;
	if (location.hasLocation())
	{
		*out << "\t\t\t\t\t<file>" << escapeXmlCharsInString(location.getFilename()) <<  "</file>" << endl;
		*out << "\t\t\t\t\t<methode>" << escapeXmlCharsInString(location.getMethodeName()) <<  "</methode>" << endl;
		*out << "\t\t\t\t\t<line>" << location.getLine() <<  "</line>" << endl;
	} else {
		*out << "\t\t\t\t\t<unknown></unknown>" << endl;
	}
	*out << "\t\t\t\t</location>" << endl;
}

/*******************  FUNCTION  *********************/
void svutResultFormatterBoostXml::onListingStart(void )
{
	*out << "<?xml version='1.0' encoding='UTF-8'?>" << endl;
	*out << "<UnitTestList>" << endl;
	lastTestCase = NULL;
}

/*******************  FUNCTION  *********************/
void svutResultFormatterBoostXml::onListMethod(const svUnitTest::svutTestCase& testCase, const svUnitTest::svutTestMethod& method)
{
	bool changeTestCase = (lastTestCase != &testCase);

	if (changeTestCase && lastTestCase != NULL)
		*out << "\t</TestCase>" << endl;
	if (changeTestCase)
		*out << "\t<TestCase name='"<< escapeXmlCharsInString(testCase.getName()) << "'>" << endl;

	*out << "\t\t<TestMethod name='" << escapeXmlCharsInString(method.getName()) << "'/>" << endl;

	if (changeTestCase)
		lastTestCase = &testCase;
}

/*******************  FUNCTION  *********************/
void svutResultFormatterBoostXml::onListingEnd(void )
{
	if (lastTestCase != NULL)
		*out << "\t</TestCase>" << endl;

	*out << "</UnitTestList>" << endl;
}

}
