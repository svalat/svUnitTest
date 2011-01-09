/*****************************************************
             PROJECT  : svUnitTest
             VERSION  : 0.0.2
             DATE     : 07/2010
             AUTHOR   : Valat Sébastien
             LICENSE  : CeCILL-C
*****************************************************/

/********************  HEADERS  *********************/
#include "svutResultFormatterQtXml.h"

using namespace std;
using namespace svUnitTest;

/********************  METHODE  *********************/
/**
 * Default constructor of the class.
 * @param out Define the output system into which to send the results.
**/
svUnitTest::svutResultFormatterQtXml::svutResultFormatterQtXml(ostream& out)
{
	this->out = & out;
}

/********************  METHODE  *********************/
/**
 * Display the header of the XML output file.
**/
void svUnitTest::svutResultFormatterQtXml::openOutput(void )
{
	*out << "<?xml version='1.0' encoding='UTF-8'?>" << endl;
	*out << "<TestCase name='svUnitTest'>" << endl;
	*out << "\t<Environment>" << endl;
	*out << "\t\t<svUnitTestVersion>0.0.2</svUnitTestVersion>" << endl;
	*out << "\t</Environment>" << endl;
}

/********************  METHODE  *********************/
/**
 * Close the XML root elements to end the XML output file.
**/
void svutResultFormatterQtXml::closeOutput(void )
{
	*out << "</TestCase>" << endl;
}

/********************  METHODE  *********************/
void svutResultFormatterQtXml::openTestCase(const svUnitTest::svutTestCase& testCase)
{
}

/********************  METHODE  *********************/
void svutResultFormatterQtXml::closeTestCase(const svUnitTest::svutTestCase& testCase)
{
}

/********************  METHODE  *********************/
void svutResultFormatterQtXml::openTestMethod(const svUnitTest::svutTestCase& testCase, const svUnitTest::svutTestMethod& meth)
{
	if (displayFullName)
		*out << "\t<TestFunction name='" << testCase.getName() << "::" << meth.getName() << "'>" << endl;
	else
		*out << "\t<TestFunction name='" << meth.getName() << "'>" << endl;
}

/********************  METHODE  *********************/
void svutResultFormatterQtXml::closeTestMethod(const svUnitTest::svutTestCase& testCase, const svUnitTest::svutTestMethod& meth, const svUnitTest::svutStatusInfo& status)
{
	this->printAssertInfo(status);
	*out << "\t</TestFunction>" << endl;
}

/********************  METHODE  *********************/
void svUnitTest::svutResultFormatterQtXml::printSummary(svutResultSummary summary)
{
}

/********************  METHODE  *********************/
void svUnitTest::svutResultFormatterQtXml::printAssertInfo(const svUnitTest::svutStatusInfo& status)
{
	int line = status.getLocation().getLine();
	if (line == -1) line = 0;
	*out << "\t\t<Incident type='"<< getQtStatusName(status.getStatus())
		<< "' file='" << status.getLocation().getFilename()
		<< "' line='" << line
		<< "'>";
	if (status.getStatus() == SVUT_STATUS_FAILED || status.getStatus() == SVUT_STATUS_UNKNOWN)
	{
		*out << endl << "\t\t\t<Description><![CDATA[";
		if (!status.getMessage().empty())
		{
			*out << status.getMessage();
			if (status.getNbEntries() > 0)
				*out << endl;
		}
		status.formatEntries(*out,"   - "," : ","\n");
		*out << "]]></Description>" << endl << "\t\t";
	}
	*out << "</Incident>" << endl;
}

/********************  METHODE  *********************/
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
