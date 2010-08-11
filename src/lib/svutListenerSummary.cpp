/*****************************************************
             PROJECT  : svUnitTest
             VERSION  : 0.0.2
             DATE     : 07/2010
             AUTHOR   : Valat Sébastien
             LICENSE  : CeCILL-C
*****************************************************/

/********************  HEADERS  *********************/
#include "svutListenerSummary.h"

namespace svUnitTest
{

/********************  METHOD  **********************/
svutListenerSummary::svutListenerSummary(void )
{
}

/********************  METHOD  **********************/
/**
 * @return Return the current global summary.
**/
svutResultSummary svutListenerSummary::getSummary(void ) const
{
	return this->summary;
}

/********************  METHOD  **********************/
void svutListenerSummary::onGlobalStart(void )
{

}

/********************  METHOD  **********************/
void svutListenerSummary::onGlobalEnd(void )
{

}

/********************  METHOD  **********************/
void svutListenerSummary::onTestCaseStart(const svUnitTest::svutTestCase& /*testCase*/)
{

}

/********************  METHOD  **********************/
void svutListenerSummary::onTestCaseEnd(const svUnitTest::svutTestCase& /*testCase*/)
{

}

/********************  METHOD  **********************/
void svutListenerSummary::onTestMethodStart(const svUnitTest::svutTestCase & /*testCase*/,const svUnitTest::svutTestMethod& /*method*/)
{
}

/********************  METHOD  **********************/
void svutListenerSummary::onTestMethodEnd(const svUnitTest::svutTestCase & /*testCase*/,const svUnitTest::svutTestMethod& /*method*/, svutStatusInfo status)
{
	summary.increment(status.getStatus());
}

}
