/*****************************************************
             PROJECT  : svUnitTest
             VERSION  : 0.0.2
             DATE     : 06/2010
             AUTHOR   : Valat Sébastien
             LICENSE  : CeCILL-C
*****************************************************/

#ifndef SVUT_ASSERT_INFO_HEADER
#define SVUT_ASSERT_INFO_HEADER

/********************  HEADERS  *********************/
#include <map>
#include <ostream>
#include "svutCodeLocation.h"

namespace svUnitTest
{

/********************  TYPES  ***********************/
/**
 * Define the list of authorized status of tests in the library.
 * @brief Define authorized status of unit tests.
**/
enum svutStatus
{
	/** The test need to be implemented or re-implemented. **/
	SVUT_STATUS_TODO,
	/** The test is in writing mode. **/
	SVUT_STATUS_INDEV,
	/** The test wasn't called. **/
	SVUT_STATUS_SKIPED,
	/** The test was executed with success. **/
	SVUT_STATUS_SUCCESS,
	/** An error occurd while running the test. **/
	SVUT_STATUS_FAILED,
	/** An unknown error occured while running the test.**/
	SVUT_STATUS_UNKNOWN
};

/********************  CLASSE  **********************/
/**
 * This class store informations related to the exit status of a test. It provite a simple agregation
 * of data which is easy to format for output. It may bt typicaly returned via exception on
 * assertions failure.
 * @brief Class to agregate extra status informations.
 * @author Valat Sébastien.
 * @version 0.0.1
**/
class svutStatusInfo
{
	public:
		svutStatusInfo(svutStatus status=SVUT_STATUS_SKIPED,std::string message="",const svutCodeLocation & location=SVUT_NO_LOCATION);
		std::string getMessage(void) const;
		svutCodeLocation getLocation(void) const;
		svutStatus getStatus(void) const;
		void addEntry(const std::string & name,const std::string & value);
		void addEntry(const char * name,const char * value);
		void addEntry(const char * name,const std::string & value);
		void formatEntries(std::ostream & out,const std::string & prefix,const std::string & separator,const std::string & postfix) const;
		void formatEntries(std::ostream & out,const char * prefix,const char * separator,const char * postfix) const;
		std::map<std::string,std::string> getEntries(void) const;
		unsigned int getNbEntries(void) const;
		std::string getEntry(std::string name) const;
		svutStatusInfo & operator = (const svutStatusInfo & orig);
	protected:
		/** Define the message related to the status of the test. **/
		std::string message;
		/** Extra parameters to describe the current status, mainly for errors debugging. **/
		std::map<std::string,std::string> entries;
		/** Keep the postition of failing assertion in the source code. **/
		svutCodeLocation location;
		/** Define the current status of the test.**/
		svutStatus status;
};

}

#endif
