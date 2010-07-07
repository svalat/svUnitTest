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
		svutExAssertFail(std::string name, svutStatus status, const svutCodeLocation& location, std::string message = "") throw();
		virtual ~svutExAssertFail(void) throw() {};
};

};

#endif