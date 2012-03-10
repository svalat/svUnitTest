/*****************************************************
             PROJECT  : svUnitTest
             VERSION  : 0.3.0
             DATE     : 05/2011
             AUTHOR   : Valat Sébastien
             LICENSE  : CeCILL-C
*****************************************************/

/********************  HEADERS  *********************/
#include <algorithm>
#include <iomanip>
#include <ctime>
#include "svutResultFormatterXml.h"
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
svUnitTest::svutResultFormatterXml::svutResultFormatterXml(std::ostream& out)
{
	this->out = & out;
	this->lastTestCase = NULL;
}

/*******************  FUNCTION  *********************/
/**
 * Display the header of the XML output file.
**/
void svUnitTest::svutResultFormatterXml::openOutput(void )
{
	*out << "<?xml version='1.0' encoding='UTF-8'?>" << endl;
	*out << "<!DOCTYPE UnitTest SYSTEM 'svUnitTest_html/svUnitTest.dtd'>" << endl;
	*out << "<?xml-stylesheet type='text/xsl' href='svUnitTest_html/svUnitTest.xsl'?>" << endl;
	*out << "<UnitTest>" << endl;
	printEnv();
}

/*******************  FUNCTION  *********************/
/**
 * This is more for testing purpose to replace the real date by a fake one when testing.
 * It force a static date which made simpler to write output correcness test in the test suite.
 * @param date Define the date in string format to use instead of reading the current date.
**/
void svutResultFormatterXml::setDate(std::string date)
{
	this->date = date;
}

/*******************  FUNCTION  *********************/
/**
 * Generate the test environnement description, mostly :
 *   - svUnitTest version.
 *   - execution date.
**/
void svutResultFormatterXml::printEnv(void)
{
	*out << "\t<TestEnv>" << endl;
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
	*out << "\t</TestEnv>" << endl;
}

/*******************  FUNCTION  *********************/
/**
 * Close the XML root elements to end the XML output file.
**/
void svutResultFormatterXml::closeOutput(void )
{
	*out << "</UnitTest>" << endl;
}

/*******************  FUNCTION  *********************/
void svutResultFormatterXml::openTestCase(const svUnitTest::svutTestCase& testCase)
{
	*out << "\t<TestCase>" << endl;
	*out << "\t\t<name>" << escapeXmlCharsInString(testCase.getName()) << "</name>" << endl;
}

/*******************  FUNCTION  *********************/
void svutResultFormatterXml::closeTestCase(const svUnitTest::svutTestCase& /*testCase*/)
{
	*out << "\t</TestCase>" << endl;
}

/*******************  FUNCTION  *********************/
void svutResultFormatterXml::openTestMethod(const svUnitTest::svutTestCase& /*testCase*/, const svUnitTest::svutTestMethod& meth)
{
	*out << "\t\t<TestFunction>" << endl;
	*out << "\t\t\t<name>" << escapeXmlCharsInString(meth.getName()) << "</name>" << endl;
}

/*******************  FUNCTION  *********************/
void svutResultFormatterXml::closeTestMethod(const svUnitTest::svutTestCase& /*testCase*/, const svUnitTest::svutTestMethod& /*meth*/, const svUnitTest::svutStatusInfo& status)
{
	string statusLower = status.getStatusName();
	std::transform(statusLower.begin(), statusLower.end(), statusLower.begin(), ::tolower);
	*out << "\t\t\t<status>" << statusLower << "</status>" << endl;
	*out << "\t\t\t<time>" << setprecision(2) << status.getDuration() << "</time>" << endl;
	if (status.getStatus() != SVUT_STATUS_SUCCESS && status.getStatus() != SVUT_STATUS_SKIPED)
		this->printAssertInfo(status);
	*out << "\t\t</TestFunction>" << endl;
}

/*******************  FUNCTION  *********************/
void svUnitTest::svutResultFormatterXml::printSummary(svutResultSummary summary)
{
	string statusLower = svutStatusInfo::getStatusName(summary.getStatus());
	int tot = summary.getTotal();
	std::transform(statusLower.begin(), statusLower.end(), statusLower.begin(), ::tolower);
	*out << "\t<GlobalResults>" << endl;
	*out << "\t\t<result type='success'>" << summary.getCount(SVUT_STATUS_SUCCESS) << "</result>" << endl;
	*out << "\t\t<result type='indev'>" << summary.getCount(SVUT_STATUS_INDEV) << "</result>" << endl;
	*out << "\t\t<result type='todo'>" << summary.getCount(SVUT_STATUS_TODO) << "</result>" << endl;
	*out << "\t\t<result type='failed'>" << summary.getCount(SVUT_STATUS_FAILED) << "</result>" << endl;
	*out << "\t\t<result type='unknown'>" << summary.getCount(SVUT_STATUS_UNKNOWN) << "</result>" << endl;
	*out << "\t\t<total>" << tot << "</total>" << endl;
	*out << "\t\t<status>" << statusLower << "</status>" << endl;
	*out << "\t</GlobalResults>" << endl;
}

/*******************  FUNCTION  *********************/
/**
 * Helper function to format the status assert informations into svUnitTest native XML format.
 * The final reste will be added to the output stream.
 * @param status Define the current status into which take the assert informations.
**/
void svUnitTest::svutResultFormatterXml::printAssertInfo(const svUnitTest::svutStatusInfo& status)
{
	*out << "\t\t\t<AssertInfo>" << endl;
	printLocation(status.getLocation());
	if (!status.getMessage().empty())
		*out << "\t\t\t\t<message>" << escapeXmlCharsInString(status.getMessage()) << "</message>" << endl;
	if (status.getNbEntries() > 0)
	{
		*out << "\t\t\t\t<entries>" << endl;
		status.formatEntries(*out,"\t\t\t\t\t<entry name='","'>","</entry>\n",escapeXmlCharsInString);
		*out << "\t\t\t\t</entries>" << endl;
	}
	if (status.getNbContextEntries() > 0)
	{
		*out << "\t\t\t\t<context>" << endl;
		status.formatContext(*out,"\t\t\t\t\t<entry name='","'>","</entry>\n",escapeXmlCharsInString);
		*out << "\t\t\t\t</context>" << endl;
	}
	if (!status.getOutput().empty())
		*out << "\t\t\t\t<output>" << escapeXmlCharsInString(status.getOutput()) << "</output>" << endl;
	*out << "\t\t\t</AssertInfo>" << endl;
}

/*******************  FUNCTION  *********************/
/**
 * Helper function to format the location into svUnitTest native XML format.
 * The final reste will be added to the output stream.
 * @param location Define the location to format.
**/
void svutResultFormatterXml::printLocation(const svUnitTest::svutCodeLocation& location)
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
void svutResultFormatterXml::onListingStart(void )
{
	*out << "<?xml version='1.0' encoding='UTF-8'?>" << endl;
	*out << "<UnitTestList>" << endl;
	lastTestCase = NULL;
}

/*******************  FUNCTION  *********************/
void svutResultFormatterXml::onListMethod(const svUnitTest::svutTestCase& testCase, const svUnitTest::svutTestMethod& method)
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
void svutResultFormatterXml::onListingEnd(void )
{
	if (lastTestCase != NULL)
		*out << "\t</TestCase>" << endl;

	*out << "</UnitTestList>" << endl;
}

}
