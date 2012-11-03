/*****************************************************
             PROJECT  : svUnitTest
             VERSION  : 0.5.0-dev
             DATE     : 11/2012
             AUTHOR   : Valat Sébastien
             LICENSE  : CeCILL-C
*****************************************************/

#ifndef SVUT_EX_NOTIFY_HEADER
#define SVUT_EX_NOTIFY_HEADER

/********************  HEADERS  *********************/
#include "svutExTestStatus.h"

/********************  NAMESPACE  *******************/
namespace svUnitTest
{

/********************* CLASS ************************/
/**
 * Base class for exceptions used as special notification in unit tests.
 * @brief Base class for exceptions used as special notification in unit tests.
 * @author Valat Sébastien.
**/
class svutExNotify : public svutExTestStatus
{
	public:
		svutExNotify(std::string name, const svutStatusInfo& info) throw();
		svutExNotify(std::string name, svutStatus status, const svutCodeLocation& location, std::string message = "") throw();
		virtual ~svutExNotify(void) throw();
};

/*********************  CLASS  **********************/
/**
 * Class used to notify tests where there is some things to do. Mainly it may be used when declaring
 * the test to notice that it must be implemented. It may also be used to mark test waiting some
 * changes.
 * @brief Notify class for tests marked as TODO.
 * @author Valat Sébastien.
 * @version 0.0.1
**/
class svutExNotifyTodo : public svutExNotify
{
	public:
		svutExNotifyTodo(std::string message, const svutCodeLocation& location) throw();
		virtual ~svutExNotifyTodo(void) throw() {}
};

/*********************  CLASS  **********************/
/**
 * Class used to notify that the current test is in developement, the result may not be revelent.
 * It's also a mean to clearly identify what we are doing by quicly find the tests we are modifying
 * in the results.
 * @brief Class to notify tests that are in developements.
 * @author Valat Sébastien.
 **/
class svutExNotifyIndev : public svutExNotify
{
	public:
		svutExNotifyIndev(std::string message,svutCodeLocation  location) throw();
		virtual ~svutExNotifyIndev(void) throw() {}
};

}

#endif
