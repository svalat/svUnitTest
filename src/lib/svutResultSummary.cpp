/*****************************************************
             PROJECT  : svUnitTest
             VERSION  : 0.0.2
             DATE     : 07/2010
             AUTHOR   : Valat Sébastien
             LICENSE  : CeCILL-C
*****************************************************/


/********************  HEADERS  *********************/
#include "svutResultSummary.h"
#include "svutException.h"

namespace svUnitTest
{

/********************  METHOD  **********************/
/**
 * Constructor of the class. It only reset all the counters.
**/
svutResultSummary::svutResultSummary(void )
{
	this->reset();
}

/********************  METHOD  **********************/
/**
 * Return the current number of occurences of requested status.
 * @param status Define the status for which to get the count.
**/
unsigned int svutResultSummary::getCount(svutStatus status) const
{
	switch(status)
	{
		case SVUT_STATUS_SUCCESS:
			return this->success;
		case SVUT_STATUS_INDEV:
			return this->indev;
		case SVUT_STATUS_TODO:
			return this->todo;
		case SVUT_STATUS_FAILED:
			return this->failed;
		case SVUT_STATUS_UNKNOWN:
			return this->unknown;
		case SVUT_STATUS_SKIPED:
			return this->skiped;
		default:
			throw svutExInternalError("Unknown status in svutResultSummary::getCount().");
	}
}

/********************  METHOD  **********************/
/**
 * Return the current percentage of occurences of requested status.
 * @param status Define the status for which to get the count.
 * @return Return the value or throw svutExInternalError if there is no tests.
**/
unsigned int svutResultSummary::getPercentage(svutStatus status) const
{
	unsigned int tot = getTotal();
	if (tot == 0)
	{
		throw svutExInternalError("Can't calculate a percentage without test runned.");
	} else {
		return (100*getCount(status))/getTotal();
	}
}

/********************  METHOD  **********************/
/**
 * @return Return the total number of tests passed.
**/
unsigned int svutResultSummary::getTotal(void ) const
{
	return success+failed+unknown+todo+indev+skiped;
}

/********************  METHOD  **********************/
/**
 * Add some occurence count to selected status.
 * @param status Define the status for which to increment the counter.
 * @param nb Define the number of occurence to add.
 * @return Return the new value.
**/
unsigned int svutResultSummary::increment(svutStatus status, unsigned int nb)
{
	switch(status)
	{
		case SVUT_STATUS_SUCCESS:
			return this->success += nb;
		case SVUT_STATUS_INDEV:
			return this->indev   += nb;
		case SVUT_STATUS_TODO:
			return this->todo    += nb;
		case SVUT_STATUS_FAILED:
			return this->failed  += nb;
		case SVUT_STATUS_UNKNOWN:
			return this->unknown += nb;
		case SVUT_STATUS_SKIPED:
			return this->skiped  += nb;
		default:
			throw svutExInternalError("Unknown status in svutResultSummary::getCount().");
	}
}

/********************  METHOD  **********************/
/**
 * Set the selected counter to given value.
 * @param status Define the status to change.
 * @param nb Define the new value of status counter.
 * @return Return the given value.
**/
unsigned int svutResultSummary::set(svutStatus status, unsigned int nb)
{
	switch(status)
	{
		case SVUT_STATUS_SUCCESS:
			return this->success = nb;
		case SVUT_STATUS_INDEV:
			return this->indev   = nb;
		case SVUT_STATUS_TODO:
			return this->todo    = nb;
		case SVUT_STATUS_FAILED:
			return this->failed  = nb;
		case SVUT_STATUS_UNKNOWN:
			return this->unknown = nb;
		case SVUT_STATUS_SKIPED:
			return this->skiped  = nb;
		default:
			throw svutExInternalError("Unknown status in svutResultSummary::getCount().");
	}
}

/********************  METHOD  **********************/
/**
 * Reset all counters to 0.
**/
void svutResultSummary::reset(void )
{
	this->success = 0;
	this->failed  = 0;
	this->todo    = 0;
	this->indev   = 0;
	this->unknown = 0;
	this->skiped  = 0;
}

/********************  METHOD  **********************/
/**
 * Return the global status. It may in order :
 *      - UNKNOWN if there is at least one unknown,
 *      - FAILED if there is at least one failed,
 *      - TODO if there is at least one todo,
 *      - INDEV if there is at least on indev,
 *      - SUCCESS is all are SKIPED or SUCCESS.
**/
svutStatus svutResultSummary::getStatus(void ) const
{
	if (this->unknown > 0)
		return SVUT_STATUS_UNKNOWN;
	else if (this->failed > 0)
		return SVUT_STATUS_FAILED;
	else if (this->todo > 0)
		return SVUT_STATUS_TODO;
	else if (this->indev > 0)
		return SVUT_STATUS_INDEV;
	else
		return SVUT_STATUS_SUCCESS;
}

}
