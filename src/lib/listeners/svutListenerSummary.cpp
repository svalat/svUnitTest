/*****************************************************
             PROJECT  : svUnitTest
             VERSION  : 0.3.0-dev
             DATE     : 03/2011
             AUTHOR   : Valat Sébastien
             LICENSE  : CeCILL-C
*****************************************************/

/********************  HEADERS  *********************/
#include "svutListenerSummary.h"

/********************  NAMESPACE  *******************/
namespace svUnitTest
{

/*******************  FUNCTION  *********************/
svutListenerSummary::svutListenerSummary(void )
{
}

/*******************  FUNCTION  *********************/
/**
 * @return Return the current global summary.
**/
svutResultSummary svutListenerSummary::getSummary(void ) const
{
	return this->summary;
}

/*******************  FUNCTION  *********************/
void svutListenerSummary::onGlobalStart(void )
{

}

/*******************  FUNCTION  *********************/
void svutListenerSummary::onGlobalEnd(void )
{

}

/*******************  FUNCTION  *********************/
void svutListenerSummary::onTestCaseStart(const svUnitTest::svutTestCase& /*testCase*/)
{

}

/*******************  FUNCTION  *********************/
void svutListenerSummary::onTestCaseEnd(const svUnitTest::svutTestCase& /*testCase*/)
{

}

/*******************  FUNCTION  *********************/
void svutListenerSummary::onTestMethodStart(const svUnitTest::svutTestCase & /*testCase*/,const svUnitTest::svutTestMethod& /*method*/)
{
}

/*******************  FUNCTION  *********************/
void svutListenerSummary::onTestMethodEnd(const svUnitTest::svutTestCase & /*testCase*/,const svUnitTest::svutTestMethod& /*method*/, svutStatusInfo status)
{
	summary.increment(status.getStatus());
}

/*******************  FUNCTION  *********************/
void svutListenerSummary::onListingStart(void )
{

}

/*******************  FUNCTION  *********************/
void svutListenerSummary::onListMethod(const svUnitTest::svutTestCase& testCase, const svUnitTest::svutTestMethod& method)
{

}

/*******************  FUNCTION  *********************/
void svutListenerSummary::onListingEnd(void )
{

}


}
