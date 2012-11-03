/*****************************************************
             PROJECT  : svUnitTest
             VERSION  : 0.5.0-dev
             DATE     : 11/2012
             AUTHOR   : Valat Sébastien
             LICENSE  : CeCILL-C
*****************************************************/

/********************  HEADERS  *********************/
#include "svutResultFormatterJUnitXml.h"
#include "svUnitTest.h"
#include "svutResultFormatterHelper.h"
#include "svutTestMethod.h"
#include <sstream>
#include <cassert>
#include <cstdio>

/**********************  USING  *********************/
using namespace std;

/********************  NAMESPACE  *******************/
namespace svUnitTest
{

/*******************  FUNCTION  *********************/
/**
 * Constructor of temporary buffer for JUnit XML output as we need to compute the number of
 * elements (tests, failure, error) in balis properties.
**/
svutResultFormatterJUnitXmlBuffer::svutResultFormatterJUnitXmlBuffer(void )
{
	this->tests = 0;
	this->errors = 0;
	this->failures = 0;
	this->start = getCurrentTime();
}

/*******************  FUNCTION  *********************/
/**
 * Default constructor of the class.
 * @param out Define the output system into which to send the results.
**/
svUnitTest::svutResultFormatterJUnitXml::svutResultFormatterJUnitXml(std::ostream& out)
{
	this->out = & out;
	this->all = NULL;
	this->suite = NULL;
}

/*******************  FUNCTION  *********************/
/**
 * Display the header of the XML output file.
**/
void svUnitTest::svutResultFormatterJUnitXml::openOutput(void )
{
	//errors
	assert(this->all == NULL);
	assert(this->suite == NULL);

	//start output
	*out << "<?xml version='1.0' encoding='UTF-8'?>" << endl;

	//setup tmp buffer
	this->all = new svutResultFormatterJUnitXmlBuffer;
// 	*out << "<TestCase name='svUnitTest'>" << endl;
// 	*out << "\t<Environment>" << endl;
// 	*out << "\t\t<svUnitTestVersion>" << SVUT_LIBARY_VERSION << "</svUnitTestVersion>" << endl;
// 	*out << "\t</Environment>" << endl;
}

/*******************  FUNCTION  *********************/
/**
 * Close the XML root elements to end the XML output file.
**/
void svutResultFormatterJUnitXml::closeOutput(void )
{
	//vars
	double t = getCurrentTime() - this->all->start;
	char tmp[128];

	//errors
	assert(this->all != NULL);
	assert(this->suite == NULL);

	//display
	sprintf(tmp,"%0.3f",t);
	*out << "<testsuites tests='" << this->all->tests
	     << "' failures='" << this->all->failures
	     << "' errors='" << this->all->errors
	     << "' time='" << tmp
	     << "' name='AllTests'>" << endl;
	*out << this->all->buffer.str();
	*out << "</testsuites>" << endl;

	//cleanup
	delete this->all;
	this->all = NULL;
}

/*******************  FUNCTION  *********************/
void svutResultFormatterJUnitXml::openTestCase(const svUnitTest::svutTestCase& /*testCase*/)
{
	//errors
	assert(this->all != NULL);
	assert(this->suite == NULL);

	//setup suite buffer
	this->suite = new svutResultFormatterJUnitXmlBuffer;
}

/*******************  FUNCTION  *********************/
/** @TODO factorize with previous method. **/
void svutResultFormatterJUnitXml::closeTestCase(const svUnitTest::svutTestCase& testCase)
{
	//vars
	char tmp[128];

	//errors
	assert(this->all != NULL);
	assert(this->suite != NULL);

	//print
	//display
	sprintf(tmp,"%0.3f",testCase.getTestTotalCaseDuration());
	this->all->buffer << "\t<testsuite tests='" << this->suite->tests
	     << "' failures='" << this->suite->failures
	     << "' errors='" << this->suite->errors
	     << "' time='" << tmp
	     << "' name='" << escapeXmlCharsInString(testCase.getName()) << "'>" << endl;
	//this->all->buffer << "\t\t<properties>" << endl;
	//this->all->buffer << "\t\t\t<property name='runtime.name'>svUnitTest</property>" << endl;
	//this->all->buffer << "\t\t\t<property name='runtime.version'>" << SVUT_LIBARY_VERSION << "</property>" << endl;
	//this->all->buffer << "\t\t</properties>" << endl;
	this->all->buffer << this->suite->buffer.str();
	this->all->buffer << "\t</testsuite>" << endl;

	//increment on all
	this->all->tests += this->suite->tests;
	this->all->errors += this->suite->errors;
	this->all->failures += this->suite->failures;

	//cleanup
	delete this->suite;
	this->suite = NULL;
}

/*******************  FUNCTION  *********************/
void svutResultFormatterJUnitXml::openTestMethod(const svUnitTest::svutTestCase& testCase, const svUnitTest::svutTestMethod& meth)
{
	//errors
	assert(this->all != NULL);
	assert(this->suite != NULL);
}

/*******************  FUNCTION  *********************/
void svutResultFormatterJUnitXml::closeTestMethod(const svUnitTest::svutTestCase& testCase, const svUnitTest::svutTestMethod& meth, const svUnitTest::svutStatusInfo& status)
{
	//vars
	char tmp[128];

	//errors
	assert(this->all != NULL);
	assert(this->suite != NULL);

	//open balis
	sprintf(tmp,"%0.3f",status.getDuration());
	this->suite->buffer << "\t\t<testcase name='" << escapeXmlCharsInString(meth.getName())
		<< "' status='run' time='" << tmp
		<< "' classname='" << escapeXmlCharsInString(testCase.getName()) << "'>" << endl;
	this->printAssertInfo(status);
	this->suite->buffer << "\t\t</testcase>" << endl;

	//update test suite status
	this->suite->tests++;
	switch (status.getStatus())
	{
		case SVUT_STATUS_SUCCESS:
			break;
		case SVUT_STATUS_FAILED:
			this->suite->failures++;
			break;
		case SVUT_STATUS_TODO:
			break;
		case SVUT_STATUS_INDEV:
			break;
		case SVUT_STATUS_UNKNOWN:
			this->suite->errors++;
			break;
		case SVUT_STATUS_SKIPED:
			break;
		default:
			throw svutExInternalError("Unknown status value in svutResultFormatterJUnitXml::getQtStatusName()");
	}
}

/*******************  FUNCTION  *********************/
void svUnitTest::svutResultFormatterJUnitXml::printSummary(svutResultSummary /*summary*/)
{
}

/*******************  FUNCTION  *********************/
/**
 * Helper function to format the status assert informations into QT XML format.
 * The final reste will be added to the output stream.
 * @param status Define the current status into which take the assert informations.
**/
void svUnitTest::svutResultFormatterJUnitXml::printAssertInfo(const svUnitTest::svutStatusInfo& status)
{
	string statusName;
	int line = status.getLocation().getLine();
	if (line == -1) line = 0;

	if (status.getStatus() == SVUT_STATUS_UNKNOWN)
		statusName = "error";
	else if (status.getStatus() == SVUT_STATUS_FAILED)
		statusName = "failure";

	if (status.getStatus() == SVUT_STATUS_FAILED || status.getStatus() == SVUT_STATUS_UNKNOWN)
	{
		this->suite->buffer << "\t\t\t<" << statusName << " type='' "
			<< "message=\"" << escapeXmlCharsInString(status.getMessage()) << "\"><![CDATA[";

		if (!status.getMessage().empty())
		{
			this->suite->buffer << "At file=" << escapeXmlCharsInString(status.getLocation().getFilename())
			                    << " line=" << line;
			if (status.getNbEntries() > 0)
				this->suite->buffer << endl;
		}
		status.formatEntries(this->suite->buffer,"   - "," : ","\n",escapeXmlCharsInString);
		if (status.getNbContextEntries() > 0)
		{
			this->suite->buffer << "Context :" << endl;
			status.formatContext(this->suite->buffer,"   - "," : ","\n",escapeXmlCharsInString);
		}
		this->suite->buffer << "]]></" << statusName << ">" << endl;
		if (!status.getOutput().empty())
			this->suite->buffer << "\t\t\t<system-out>" << escapeXmlCharsInString(status.getOutput()) << "</system-out>" << endl;
	}
	
}

/*******************  FUNCTION  *********************/
/**
 * Return the QT status string related to the given status.
 * @param status Define the status to convert into QT unit test status.
 * @return Return the QT status name as a string.
**/
string svUnitTest::svutResultFormatterJUnitXml::getQtStatusName(svutStatus status)
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
			throw svutExInternalError("Unknown status value in svutResultFormatterJUnitXml::getQtStatusName()");
	}
}

/*******************  FUNCTION  *********************/
void svutResultFormatterJUnitXml::onListingStart(void )
{
	//nothing to do for std mode
}

/*******************  FUNCTION  *********************/
void svutResultFormatterJUnitXml::onListingEnd(void )
{
	//nohting to do for std mode
}

/*******************  FUNCTION  *********************/
void svutResultFormatterJUnitXml::onListMethod(const svUnitTest::svutTestCase& testCase, const svUnitTest::svutTestMethod& method)
{
	if (displayFullName)
		*out << escapeXmlCharsInString(testCase.getName()) << "::" << escapeXmlCharsInString(method.getName()) << "()\n";
	else
		*out << escapeXmlCharsInString(method.getName()) << "()\n";
}

}
