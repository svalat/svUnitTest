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
	summary.failed  = 0;
	summary.indev   = 0;
	summary.skiped  = 0;
	summary.success = 0;
	summary.todo    = 0;
	summary.unknown = 0;
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
	switch (status.getStatus())
	{
		case SVUT_STATUS_SUCCESS:
			summary.success++;
			break;
		case SVUT_STATUS_FAILED:
			summary.failed++;
			break;
		case SVUT_STATUS_UNKNOWN:
			summary.unknown++;
			break;
		case SVUT_STATUS_TODO:
			summary.todo++;
			break;
		case SVUT_STATUS_INDEV:
			summary.indev++;
			break;
		case SVUT_STATUS_SKIPED:
			summary.skiped++;
			break;
		default:
			throw svutExInternalError("Unknown status value in svutListenerSummary::onTestMethodEnd.");
	}
}

}
