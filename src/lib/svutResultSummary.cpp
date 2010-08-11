/*****************************************************
             PROJECT  : svUnitTest
             VERSION  : 0.0.2
             DATE     : 07/2010
             AUTHOR   : Valat Sébastien
             LICENSE  : CeCILL-C
*****************************************************/


/********************  HEADERS  *********************/
#include "svutResultSummary.h"

namespace svUnitTest
{

/********************  METHOD  **********************/
svutResultSummary::svutResultSummary(void )
{

}

/********************  METHOD  **********************/
unsigned int svutResultSummary::getCount(svutStatus status)
{
	return -1;
}

/********************  METHOD  **********************/
unsigned int svutResultSummary::getPercentage(svutStatus status)
{
	return -1;
}

/********************  METHOD  **********************/
unsigned int svutResultSummary::getTotal(void ) const
{
	return -1;
}

/********************  METHOD  **********************/
void svutResultSummary::increment(svutStatus status, unsigned int nb)
{
}

/********************  METHOD  **********************/
void svutResultSummary::set(svutStatus status, unsigned int nb)
{
}

/********************  METHOD  **********************/
void svutResultSummary::reset(void )
{
}

/********************  METHOD  **********************/
svutStatus svutResultSummary::getStatus(void ) const
{
	return SVUT_STATUS_UNKNOWN;
}


/*
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
	*/
}
