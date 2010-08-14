/*****************************************************
             PROJECT  : svUnitTest
             VERSION  : 0.0.2
             DATE     : 07/2010
             AUTHOR   : Valat Sébastien
             LICENSE  : CeCILL-C
*****************************************************/

/********************  HEADERS  *********************/
#include "svutListenerDirectOutputter.h"

namespace svUnitTest
{

/********************  METHOD  **********************/
/**
 * Constructor of the class, it only init the formatter pointer inside the listener.
 * @param formatter Define the formatter to use for displaying.
**/
svutListenerDirectOutputter::svutListenerDirectOutputter(svutResultFormatter& formatter)
	:svutListenerSummary()
{
	this->formatter = &formatter;
}


/********************  METHOD  **********************/
void svutListenerDirectOutputter::onGlobalStart(void )
{
	svutListenerSummary::onGlobalStart();
	formatter->openOutput();
}

/********************  METHOD  **********************/
void svutListenerDirectOutputter::onGlobalEnd(void )
{
	svutListenerSummary::onGlobalEnd();
	formatter->printSummary(svutListenerSummary::getSummary());
	formatter->closeOutput();
}

/********************  METHOD  **********************/
void svutListenerDirectOutputter::onTestCaseStart(const svUnitTest::svutTestCase& testCase)
{
	svutListenerSummary::onTestCaseStart(testCase);
	formatter->openTestCase(testCase);
}

/********************  METHOD  **********************/
void svutListenerDirectOutputter::onTestCaseEnd(const svUnitTest::svutTestCase& testCase)
{
	svutListenerSummary::onTestCaseEnd(testCase);
	formatter->closeTestCase(testCase);
}

/********************  METHOD  **********************/
void svutListenerDirectOutputter::onTestMethodStart(const svutTestCase & testCase,const svUnitTest::svutTestMethod& method)
{
	svutListenerSummary::onTestMethodStart(testCase,method);
	formatter->openTestMethod(testCase,method);
}

/********************  METHOD  **********************/
void svutListenerDirectOutputter::onTestMethodEnd(const svutTestCase & testCase,const svUnitTest::svutTestMethod& method, svutStatusInfo status)
{
	svutListenerSummary::onTestMethodEnd(testCase,method,status);
	formatter->closeTestMethod(testCase,method,status);
}

}
