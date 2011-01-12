/*****************************************************
             PROJECT  : svUnitTest
             VERSION  : 0.1.0
             DATE     : 01/2011
             AUTHOR   : Valat Sébastien
             LICENSE  : CeCILL-C
*****************************************************/

#ifndef SVUT_EX_TEST_STATUS_HEADER
#define SVUT_EX_TEST_STATUS_HEADER

/********************  HEADERS  *********************/
#include "svutException.h"
#include "svutStatusInfo.h"

/********************  NAMESPACE  *******************/
namespace svUnitTest
{

/********************* CLASS ************************/
/**
 * Base class used to build assertions and notification on unit test library. It was used to
 * return non success status to the test runner.
 * @brief Base class for notification and assertions in unit tests.
 * @author Sébastien Valat.
**/
class svutExTestStatus : public svutException
{
	public:
		svutExTestStatus(std::string name, const svUnitTest::svutStatusInfo& info) throw();
		svutExTestStatus(std::string name,svutStatus status,svutCodeLocation  location=SVUT_CODE_LOCATION,std::string message="") throw();
		virtual ~svutExTestStatus(void) throw();
		std::string getExceptionName(void) const;
		const svutStatusInfo & getInfos(void) const;
		svutStatusInfo & getInfos(void);
		svutStatus getStatus(void) const;
		virtual const char* what() const  throw();
		virtual std::string getMessage(void) const;
	protected:
		/** Define the current status informations. **/
		svutStatusInfo info;
	private:
		/** Define the name of the current exception. **/
		std::string name;
};

}

#endif
