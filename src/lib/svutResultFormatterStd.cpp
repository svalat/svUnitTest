/*****************************************************
             PROJECT  : svUnitTest
             VERSION  : 0.0.2
             DATE     : 07/2010
             AUTHOR   : Valat Sébastien
             LICENSE  : CeCILL-C
*****************************************************/

/********************  HEADERS  *********************/
#include "svutResultFormatterStd.h"
#include <stdlib.h>

using namespace std;

namespace svUnitTest
{

/********************  METHOD  **********************/
/**
 * Constructor of the class.
 * @param out Define the output stream to use.
**/
svutResultFormatterStd::svutResultFormatterStd(std::ostream& out)
{
	this->out = & out;
	this->displayDetails = true;
	this->displayFullName = false;
	this->displaySuccess = false;
}

/********************  METHOD  **********************/
void svutResultFormatterStd::openOutput(void)
{
	//nothing to do for std mode
}

/********************  METHOD  **********************/
void svutResultFormatterStd::openTestCase(const svUnitTest::svutTestCase& testCase)
{
	//apply format :
	//"=======  %-40s  ========\n"
	*out << "=======  ";
	out->width(40);
	*out << left <<  testCase.getName();
	*out << " ========" << endl;
}

/********************  METHOD  **********************/
void svutResultFormatterStd::closeTestCase(const svUnitTest::svutTestCase& testCase)
{
	//nothing to do for std mode
}

/********************  METHOD  **********************/
void svutResultFormatterStd::openTestMethod(const svUnitTest::svutTestCase& testCase, const svUnitTest::svutTestMethod& meth)
{
	//nothing to do for std mode
}

/********************  METHOD  **********************/
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

/********************  METHOD  **********************/
/**
 * Methode used to format failure status informations and to print them in ostream system. It done nothing
 * if displayDetails is set to false.
 * @param testCase Define the test case which contain the method.
 * @param meth Define the method which failed.
 * @param status Define the status informations related to the failure.
**/
void svutResultFormatterStd::printFailedInfo(const svUnitTest::svutTestCase& testCase, const svUnitTest::svutTestMethod& meth, const svUnitTest::svutStatusInfo& status)
{
	if (this->displayDetails)
	{
		*out << "- - - - - - - - - - - - - - - - - - - - - - - - - - - - - -" << endl;
		*out << status.getMessage() << endl;
		*out << status.getLocation() << endl;
		status.formatEntries(*out,"   - "," : ","\n");
		*out << "- - - - - - - - - - - - - - - - - - - - - - - - - - - - - -" << endl;
	}
}

/********************  METHOD  **********************/
/**
 * Methode used to format unknown status informations and to print them in ostream system. It done nothing
 * if displayDetails is set to false.
 * @param testCase Define the test case which contain the method.
 * @param meth Define the method which failed.
 * @param status Define the status informations related to the unknown failure.
**/
void svutResultFormatterStd::printUnknownInfo(const svUnitTest::svutTestCase& testCase, const svUnitTest::svutTestMethod& meth, const svUnitTest::svutStatusInfo& status)
{
	if (this->displayDetails && status.getMessage() != "UNKNOWN")
	{
		*out << "- - - - - - - - - - - - - - - - - - - - - - - - - - - - - -" << endl;
		*out << status.getMessage() << endl;
		*out << status.getLocation() << endl;
		*out << "- - - - - - - - - - - - - - - - - - - - - - - - - - - - - -" << endl;
	}
}

/********************  METHOD  **********************/
void svutResultFormatterStd::printSummary(svutResultSummary summary)
{
	*out << endl << "+---------------------------+" << endl;
	*out         << "|    SUMMARY                |" << endl;
	*out         << "+---------------------------+" << endl;
	printSummaryStat(*out,SVUT_STATUS_SUCCESS,summary.getCount(SVUT_STATUS_SUCCESS),summary.getTotal());
	printSummaryStat(*out,SVUT_STATUS_INDEV,summary.getCount(SVUT_STATUS_SUCCESS),summary.getTotal());
	printSummaryStat(*out,SVUT_STATUS_TODO,summary.getCount(SVUT_STATUS_SUCCESS),summary.getTotal());
	printSummaryStat(*out,SVUT_STATUS_FAILED,summary.getCount(SVUT_STATUS_SUCCESS),summary.getTotal());
	printSummaryStat(*out,SVUT_STATUS_UNKNOWN,summary.getCount(SVUT_STATUS_SUCCESS),summary.getTotal());
	*out         << "+---------------------------+" << endl;
	//"|  TOTAL    : %4d          |\n"
	*out         << "|  TOTAL    : ";
	out->width(4);
	*out                        << summary.getTotal() << "          |" << endl;
	this->printSummaryFinalStatus(*out,summary.getStatus());
	*out         << "+---------------------------+" << endl;
}

/********************  METHOD  **********************/
void svutResultFormatterStd::closeOutput(void )
{
	//nothing to do for std mode
}

}
