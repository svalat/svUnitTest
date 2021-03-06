/*****************************************************
             PROJECT  : svUnitTest
             VERSION  : 0.5.0-dev
             DATE     : 11/2012
             AUTHOR   : Valat Sébastien
             LICENSE  : CeCILL-C 2.1
*****************************************************/

/********************  HEADERS  *********************/
#include "svutResultFormatterQtXml.h"
#include "svUnitTest.h"
#include "svutResultFormatterHelper.h"
#include "svutTestMethod.h"
#include <sstream>

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
svUnitTest::svutResultFormatterQtXml::svutResultFormatterQtXml(std::ostream& out)
{
	this->out = & out;
}

/*******************  FUNCTION  *********************/
/**
 * Display the header of the XML output file.
**/
void svUnitTest::svutResultFormatterQtXml::openOutput(void )
{
	*out << "<?xml version='1.0' encoding='UTF-8'?>" << endl;
	*out << "<TestCase name='svUnitTest'>" << endl;
	*out << "\t<Environment>" << endl;
	*out << "\t\t<QtVersion>4.8.2</QtVersion>" << endl;
	*out << "\t\t<QTestVersion>4.8.2</QTestVersion>" << endl;
	*out << "\t\t<!--<svUnitTestVersion>" SVUT_LIBARY_VERSION "</svUnitTestVersion>-->" << endl;
	*out << "\t</Environment>" << endl;
}

/*******************  FUNCTION  *********************/
/**
 * Close the XML root elements to end the XML output file.
**/
void svutResultFormatterQtXml::closeOutput(void )
{
	*out << "</TestCase>" << endl;
}

/*******************  FUNCTION  *********************/
void svutResultFormatterQtXml::openTestCase(const svUnitTest::svutTestCase& /*testCase*/)
{
}

/*******************  FUNCTION  *********************/
void svutResultFormatterQtXml::closeTestCase(const svUnitTest::svutTestCase& /*testCase*/)
{
}

/*******************  FUNCTION  *********************/
void svutResultFormatterQtXml::openTestMethod(const svUnitTest::svutTestCase& testCase, const svUnitTest::svutTestMethod& meth)
{
	if (displayFullName)
		*out << "\t<TestFunction name='" << escapeXmlCharsInString(testCase.getName()) << "::" << escapeXmlCharsInString(meth.getName()) << "'>" << endl;
	else
		*out << "\t<TestFunction name='" << escapeXmlCharsInString(meth.getName()) << "'>" << endl;
}

/*******************  FUNCTION  *********************/
void svutResultFormatterQtXml::closeTestMethod(const svUnitTest::svutTestCase& /*testCase*/, const svUnitTest::svutTestMethod& /*meth*/, const svUnitTest::svutStatusInfo& status)
{
	this->printAssertInfo(status);
	*out << "\t</TestFunction>" << endl;
}

/*******************  FUNCTION  *********************/
void svUnitTest::svutResultFormatterQtXml::printSummary(svutResultSummary /*summary*/)
{
}

/*******************  FUNCTION  *********************/
/**
 * Helper function to format the status assert informations into QT XML format.
 * The final reste will be added to the output stream.
 * @param status Define the current status into which take the assert informations.
**/
void svUnitTest::svutResultFormatterQtXml::printAssertInfo(const svUnitTest::svutStatusInfo& status)
{
	int line = status.getLocation().getLine();
	if (line == -1) line = 0;
	*out << "\t\t<Incident type='"<< getQtStatusName(status.getStatus())
		<< "' file='" << escapeXmlCharsInString(status.getLocation().getFilename())
		<< "' line='" << line
		<< "'>";
	if (status.getStatus() == SVUT_STATUS_FAILED || status.getStatus() == SVUT_STATUS_UNKNOWN)
	{
		*out << endl << "\t\t\t<Description><![CDATA[";
		if (!status.getMessage().empty())
		{
			*out << escapeXmlCharsInString(status.getMessage());
			if (status.getNbEntries() > 0)
				*out << endl;
		}
		status.formatEntries(*out,"   - "," : ","\n",escapeXmlCharsInString);
		if (status.getNbContextEntries() > 0)
		{
			*out << "Context :" << endl;
			status.formatContext(*out,"   - "," : ","\n",escapeXmlCharsInString);
		}
		if (!status.getOutput().empty())
			*out << "Output :" << endl << paddOutput("   ",escapeXmlCharsInString(status.getOutput()));
		*out << "]]></Description>" << endl << "\t\t";
	}
	*out << "</Incident>" << endl;
}

/*******************  FUNCTION  *********************/
/**
 * Return the QT status string related to the given status.
 * @param status Define the status to convert into QT unit test status.
 * @return Return the QT status name as a string.
**/
string svUnitTest::svutResultFormatterQtXml::getQtStatusName(svutStatus status)
{
	switch(status)
	{
		case SVUT_STATUS_SUCCESS:
			return "pass";
		case SVUT_STATUS_FAILED:
			return "fail";
		case SVUT_STATUS_TODO:
			return "warn";
		case SVUT_STATUS_INDEV:
			return "warn";
		case SVUT_STATUS_UNKNOWN:
			return "fail";
		case SVUT_STATUS_SKIPED:
			return "warn";
		default:
			throw svutExInternalError("Unknown status value in svutResultFormatterQtXml::getQtStatusName()");
	}
}

/*******************  FUNCTION  *********************/
void svutResultFormatterQtXml::onListingStart(void )
{
	//nothing to do for std mode
}

/*******************  FUNCTION  *********************/
void svutResultFormatterQtXml::onListingEnd(void )
{
	//nohting to do for std mode
}

/*******************  FUNCTION  *********************/
void svutResultFormatterQtXml::onListMethod(const svUnitTest::svutTestCase& testCase, const svUnitTest::svutTestMethod& method)
{
	if (displayFullName)
		*out << escapeXmlCharsInString(testCase.getName()) << "::" << escapeXmlCharsInString(method.getName()) << "()\n";
	else
		*out << escapeXmlCharsInString(method.getName()) << "()\n";
}

}
