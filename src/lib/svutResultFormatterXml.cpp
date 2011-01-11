/*****************************************************
             PROJECT  : svUnitTest
             VERSION  : 0.0.2
             DATE     : 07/2010
             AUTHOR   : Valat Sébastien
             LICENSE  : CeCILL-C
*****************************************************/

/********************  HEADERS  *********************/
#include "svutResultFormatterXml.h"

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
	*out << "\t\t<name>" << testCase.getName() << "</name>" << endl;
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
	*out << "\t\t\t<name>" << meth.getName() << "</name>" << endl;
}

/*******************  FUNCTION  *********************/
void svutResultFormatterXml::closeTestMethod(const svUnitTest::svutTestCase& /*testCase*/, const svUnitTest::svutTestMethod& /*meth*/, const svUnitTest::svutStatusInfo& status)
{
	*out << "\t\t\t<status>" << status.getStatusName() << "</status>" << endl;
	if (status.getStatus() == SVUT_STATUS_FAILED || status.getStatus() == SVUT_STATUS_UNKNOWN)
		this->printAssertInfo(status);
	*out << "\t\t</TestFunction>" << endl;
}

/*******************  FUNCTION  *********************/
void svUnitTest::svutResultFormatterXml::printSummary(svutResultSummary summary)
{
	int tot = summary.getTotal();
	*out << "\t<GlobalResults>" << endl;
	*out << "\t\t<result type='success'>" << summary.getCount(SVUT_STATUS_SUCCESS) << "</result>" << endl;
	*out << "\t\t<result type='indev'>" << summary.getCount(SVUT_STATUS_INDEV) << "</result>" << endl;
	*out << "\t\t<result type='todo'>" << summary.getCount(SVUT_STATUS_TODO) << "</result>" << endl;
	*out << "\t\t<result type='failed'>" << summary.getCount(SVUT_STATUS_FAILED) << "</result>" << endl;
	*out << "\t\t<result type='unknown'>" << summary.getCount(SVUT_STATUS_UNKNOWN) << "</result>" << endl;
	*out << "\t\t<total>" << tot << "</total>" << endl;
	*out << "\t\t<status>" << svutStatusInfo::getStatusName(summary.getStatus()) << "</status>" << endl;
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
	*out << "\t\t\t\t<message>" << status.getMessage() << "</message>" << endl;
	*out << "\t\t\t\t<entries>" << endl;
	status.formatEntries(*out,"\t\t\t\t\t<entry name='","'>","</entry>\n");
	*out << "\t\t\t\t</entries>" << endl;
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
		*out << "\t\t\t\t\t<file>" << location.getFilename() <<  "</file>" << endl;
		*out << "\t\t\t\t\t<methode>" << location.getMethodeName() <<  "</methode>" << endl;
		*out << "\t\t\t\t\t<line>" << location.getLine() <<  "</line>" << endl;
	} else {
		*out << "\t\t\t\t\t<unknown></unknown>" << endl;
	}
	*out << "\t\t\t\t</location>" << endl;
}

}
