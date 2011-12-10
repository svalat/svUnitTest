/*****************************************************
             PROJECT  : svUnitTest
             VERSION  : 0.3.0
             DATE     : 05/2011
             AUTHOR   : Valat Sébastien
             LICENSE  : CeCILL-C
*****************************************************/

/********************  HEADERS  *********************/
#include "svutResultFormatterStd.h"
#include "svutResultFormatterHelper.h"
#include "svutTestCase.h"
#include <stdlib.h>

/**********************  USING  *********************/
using namespace std;

/********************  NAMESPACE  *******************/
namespace svUnitTest
{

/*******************  FUNCTION  *********************/
/**
 * Constructor of the class.
 * @param out Define the output stream to use.
**/
svutResultFormatterStd::svutResultFormatterStd(std::ostream& out)
{
	this->out = & out;
}

/*******************  FUNCTION  *********************/
void svutResultFormatterStd::openOutput(void)
{
	//nothing to do for std mode
}

/*******************  FUNCTION  *********************/
void svutResultFormatterStd::openTestCase(const svUnitTest::svutTestCase& testCase)
{
	//apply format :
	//"=======  %-40s  ========\n"
	*out << "=======  ";
	out->width(40);
	*out << left <<  testCase.getName();
	*out << " ========" << endl;
}

/*******************  FUNCTION  *********************/
void svutResultFormatterStd::closeTestCase(const svUnitTest::svutTestCase& /*testCase*/)
{
	//nothing to do for std mode
}

/*******************  FUNCTION  *********************/
void svutResultFormatterStd::openTestMethod(const svUnitTest::svutTestCase& /*testCase*/, const svUnitTest::svutTestMethod& /*meth*/)
{
	//nothing to do for std mode
}

/*******************  FUNCTION  *********************/
void svutResultFormatterStd::closeTestMethod(const svUnitTest::svutTestCase& testCase, const svUnitTest::svutTestMethod& meth, const svUnitTest::svutStatusInfo& status)
{
	std::string name;

	//calc the name
	if (displayFullName)
		name = testCase.getName() + ":" + meth.getName();
	else
		name = meth.getName();

	//display the status if need
	if (status.getStatus() != SVUT_STATUS_SUCCESS || displaySuccess)
		printMethodAndStatus(*out,name,status.getStatus());
	
	//apply the good display.
	switch(status.getStatus())
	{
		case SVUT_STATUS_FAILED:
			this->printFailedInfo(testCase,meth,status);
			break;
		case SVUT_STATUS_UNKNOWN:
			this->printUnknownInfo(testCase,meth,status);
			break;
		default:
			break;
	}
}

/*******************  FUNCTION  *********************/
/**
 * Methode used to format failure status informations and to print them in ostream system. It done nothing
 * if displayDetails is set to false.
 * @param testCase Define the test case which contain the method.
 * @param meth Define the method which failed.
 * @param status Define the status informations related to the failure.
**/
void svutResultFormatterStd::printFailedInfo(const svUnitTest::svutTestCase& /*testCase*/, const svUnitTest::svutTestMethod& /*meth*/, const svUnitTest::svutStatusInfo& status)
{
	if (this->displayDetails)
	{
		*out << "- - - - - - - - - - - - - - - - - - - - - - - - - - - - - -" << endl;
		*out << status.getMessage() << endl;
		*out << status.getLocation() << endl;
		status.formatEntries(*out,"   - "," : ","\n");
		if (status.getNbContextEntries() > 0)
		{
			*out << "Context :" << endl;
			status.formatContext(*out,"   - "," : ","\n");
		}
		if (status.getOutput().empty() == false)
		{
			*out << "Output :" << endl;
			*out << paddOutput("   ",status.getOutput());
		}
		*out << "- - - - - - - - - - - - - - - - - - - - - - - - - - - - - -" << endl;
	}
}

/*******************  FUNCTION  *********************/
/**
 * Methode used to format unknown status informations and to print them in ostream system. It done nothing
 * if displayDetails is set to false.
 * @param testCase Define the test case which contain the method.
 * @param meth Define the method which failed.
 * @param status Define the status informations related to the unknown failure.
**/
void svutResultFormatterStd::printUnknownInfo(const svUnitTest::svutTestCase& /*testCase*/, const svUnitTest::svutTestMethod& /*meth*/, const svUnitTest::svutStatusInfo& status)
{
	if (this->displayDetails && status.getMessage() != "UNKNOWN")
	{
		*out << "- - - - - - - - - - - - - - - - - - - - - - - - - - - - - -" << endl;
		*out << status.getMessage() << endl;
		*out << status.getLocation() << endl;
		if (status.getNbContextEntries() > 0)
		{
			*out << "Context :" << endl;
			status.formatContext(*out,"   - "," : ","\n");
		}
		*out << "- - - - - - - - - - - - - - - - - - - - - - - - - - - - - -" << endl;
	}
}

/*******************  FUNCTION  *********************/
void svutResultFormatterStd::printSummary(svutResultSummary summary)
{
	*out << endl << "+---------------------------+" << endl;
	*out         << "|    SUMMARY                |" << endl;
	*out         << "+---------------------------+" << endl;
	printSummaryStat(*out,SVUT_STATUS_SUCCESS,summary.getCount(SVUT_STATUS_SUCCESS),summary.getTotal());
	printSummaryStat(*out,SVUT_STATUS_INDEV,summary.getCount(SVUT_STATUS_INDEV),summary.getTotal());
	printSummaryStat(*out,SVUT_STATUS_TODO,summary.getCount(SVUT_STATUS_TODO),summary.getTotal());
	printSummaryStat(*out,SVUT_STATUS_FAILED,summary.getCount(SVUT_STATUS_FAILED),summary.getTotal());
	printSummaryStat(*out,SVUT_STATUS_UNKNOWN,summary.getCount(SVUT_STATUS_UNKNOWN),summary.getTotal());
	*out         << "+---------------------------+" << endl;
	//"|  TOTAL    : %4d          |\n"
	*out         << "|  TOTAL    : ";
	out->width(4);
	*out                        << summary.getTotal() << "          |" << endl;
	this->printSummaryFinalStatus(*out,summary.getStatus());
	*out         << "+---------------------------+" << endl;
}

/*******************  FUNCTION  *********************/
void svutResultFormatterStd::closeOutput(void )
{
	//nothing to do for std mode
}

/*******************  FUNCTION  *********************/
void svutResultFormatterStd::onListingStart(void )
{
	//nothing to do for std mode
}

/*******************  FUNCTION  *********************/
void svutResultFormatterStd::onListingEnd(void )
{
	//nohting to do for std mode
}

/*******************  FUNCTION  *********************/
void svutResultFormatterStd::onListMethod(const svUnitTest::svutTestCase& testCase, const svUnitTest::svutTestMethod& method)
{
	if (displayFullName)
		*out << testCase.getName() << "::" << method.getName() << "()\n";
	else
		*out << method.getName() << "()\n";
}

}
