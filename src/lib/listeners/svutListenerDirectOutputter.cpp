/*****************************************************
             PROJECT  : svUnitTest
             VERSION  : 0.5.0-dev
             DATE     : 11/2012
             AUTHOR   : Valat Sébastien
             LICENSE  : CeCILL-C 2.1
*****************************************************/

/********************  HEADERS  *********************/
#include "svutListenerDirectOutputter.h"
#include "svutResultFormatter.h"

/********************  NAMESPACE  *******************/
namespace svUnitTest
{

/*******************  FUNCTION  *********************/
/**
 * Constructor of the class, it only init the formatter pointer inside the listener.
 * @param formatter Define the formatter to use for displaying.
**/
svutListenerDirectOutputter::svutListenerDirectOutputter(svutResultFormatter& formatter)
	:svutListenerSummary()
{
	this->formatter = &formatter;
}


/*******************  FUNCTION  *********************/
void svutListenerDirectOutputter::onGlobalStart(void )
{
	svutListenerSummary::onGlobalStart();
	formatter->openOutput();
}

/*******************  FUNCTION  *********************/
void svutListenerDirectOutputter::onGlobalEnd(void )
{
	svutListenerSummary::onGlobalEnd();
	formatter->printSummary(svutListenerSummary::getSummary());
	formatter->closeOutput();
}

/*******************  FUNCTION  *********************/
void svutListenerDirectOutputter::onTestCaseStart(const svUnitTest::svutTestCase& testCase)
{
	svutListenerSummary::onTestCaseStart(testCase);
	formatter->openTestCase(testCase);
}

/*******************  FUNCTION  *********************/
void svutListenerDirectOutputter::onTestCaseEnd(const svUnitTest::svutTestCase& testCase)
{
	svutListenerSummary::onTestCaseEnd(testCase);
	formatter->closeTestCase(testCase);
}

/*******************  FUNCTION  *********************/
void svutListenerDirectOutputter::onTestMethodStart(const svutTestCase & testCase,const svUnitTest::svutTestMethod& method)
{
	svutListenerSummary::onTestMethodStart(testCase,method);
	formatter->openTestMethod(testCase,method);
}

/*******************  FUNCTION  *********************/
void svutListenerDirectOutputter::onTestMethodEnd(const svutTestCase & testCase,const svUnitTest::svutTestMethod& method, svutStatusInfo status)
{
	svutListenerSummary::onTestMethodEnd(testCase,method,status);
	formatter->closeTestMethod(testCase,method,status);
}

/*******************  FUNCTION  *********************/
void svutListenerDirectOutputter::onListingStart(void )
{
	formatter->onListingStart();
}

/*******************  FUNCTION  *********************/
void svutListenerDirectOutputter::onListMethod(const svUnitTest::svutTestCase& testCase, const svUnitTest::svutTestMethod& method)
{
	formatter->onListMethod(testCase,method);
}

/*******************  FUNCTION  *********************/
void svutListenerDirectOutputter::onListingEnd(void )
{
	formatter->onListingEnd();
}

}
