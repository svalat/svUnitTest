/*****************************************************
             PROJECT  : svUnitTest
             VERSION  : 0.0.2
             DATE     : 07/2010
             AUTHOR   : Valat Sébastien
             LICENSE  : CeCILL-C
*****************************************************/

#ifndef SVUT_EX_ASSERT_HEADER
#define SVUT_EX_ASSERT_HEADER

/********************  HEADERS  *********************/
#include "svutExTestStatus.h"

namespace svUnitTest
{

/********************  CLASSE  **********************/
/**
 * Base class for exception used to notify assertion failure. This is used to unit tests.
 * @brief Base class for assertion failure notification.
 * @author Valat Sébastien.
 * @version 0.0.2
**/
class svutExAssertFail : public svutExTestStatus
{
	public:
		svutExAssertFail(std::string name, const svutStatusInfo& info) throw();
		svutExAssertFail(std::string name, svutStatus status, const svutCodeLocation& location,
			std::string message = "") throw();
		virtual ~svutExAssertFail(void) throw() {};
};

/********************  CLASSE  **********************/
/**
 * Class used to throw exception on boolean value; We may prefer to use the SVUT_ASSERT_TRUE
 * or SVUT_ASSERT_FALSE macro to call this exception, it will construct the object for you
 * and setup svutCodeLocation.
 * @brief Exception class used on assertion failure on booleans.
**/
class svutExAssertFailBool : public svutExAssertFail
{
	public:
		svutExAssertFailBool(bool expected, const svutCodeLocation &  location) throw();
};


/********************  CLASSE  **********************/
/**
 * Class used to throw exception on NULL or non NULL pointer. We may prefer to use the
 * SVUT_ASSERT_NULL or SVUT_ASSERT_NOT_NULL macro to call this exception. It will construct
 * the object for you and setup svutCodeLocation.
 * @brief Exception class used on assertion failure on NULL or non NULL pointer.
 **/
class svutExAssertFailNullPointer : public svutExAssertFail
{
	public:
		svutExAssertFailNullPointer(bool expectNull, svutCodeLocation  location) throw();
};

/********************  CLASSE  **********************/
/**
 * Class used to throw exception on equality test. We may prefer to use the
 * SVUT_ASSERT_EQUAL or SVUT_ASSERT_NOT_EQUAL macro to call this exception. It will construct
 * the object for you and setup svutCodeLocation. Here it also support automatic conversion
 * of your values to string format when needed.
 * @brief Exception class used on assertion failure on equality test.
 **/
class svutExAssertFailEqual : public svutExAssertFail
{
	public:
		svutExAssertFailEqual(bool expectTestRes,std::string exptected,std::string actual,
			svutCodeLocation  location) throw();
};

/********************  CLASSE  **********************/
/**
 * Class used to throw exception on custum assertion, you just choose a message to describe
 * the problem. We may prefer to use the SVUT_ASSERT_FAIL macro to call this exception. It will
 * construct the object for you and setup svutCodeLocation.
 * @brief Exception class used to emit custom assertion failure.
 **/
class svutExAssertFailCustom : public svutExAssertFail
{
	public:
		svutExAssertFailCustom(std::string message, svutCodeLocation & location) throw();
};

/********************  CLASSE  **********************/
/**
 * Class used to throw exception when a non reachable portion of code is reached.
 * We may prefer to use the SVUT_ASSERT_NOT_EXEC_THIS macro to call this exception. It will
 * construct the object for you and setup svutCodeLocation.
* @brief Exception class used to emit excption for non reachable code.
 **/
class svutExAssertFailNotExec : public svutExAssertFail
{
	public:
		svutExAssertFailNotExec(svutCodeLocation  location) throw();
};

/********************  CLASSE  **********************/
/**
 * Class used to throw exception on exception asserting. We may prefer to use the SVUT_ASSERT_THROW
 * or SVUT_ASSERT_NOT_THROW macro to call this exception. It will construct the object for you and
* setup svutCodeLocation.
 * @brief Exception class used to emit on excpected or non expected exception.
 **/
class svutExAssertFailThrow : public svutExAssertFail
{
	public:
		svutExAssertFailThrow(std::string expected,std::string actual,
			svutCodeLocation  location) throw();
};


};

#endif