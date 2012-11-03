/*****************************************************
             PROJECT  : svUnitTest
             VERSION  : 0.5.0-dev
             DATE     : 11/2012
             AUTHOR   : Valat Sébastien
             LICENSE  : CeCILL-C
*****************************************************/

#ifndef SVUT_ASSERT_INFO_HEADER
#define SVUT_ASSERT_INFO_HEADER

/********************  HEADERS  *********************/
#include <map>
#include <ostream>
#include "svutCodeLocation.h"

/********************  NAMESPACE  *******************/
namespace svUnitTest
{

/********************  TYPES  ***********************/
/**
 * Define the list of authorized status of tests in the library.
 * @todo definir des opérateurs de cast vers et depuis std::string
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

/********************** TYPEDEF *********************/
/** Map of key,value pair to provide information on final status. **/
typedef std::map<std::string,std::string> svutStatusInfoMap;
/** A filter function for string conversion. **/
typedef std::string (*svutStringFilter)(const std::string & value);

/*********************  CLASS  **********************/
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
		void setContext(svutStatusInfoMap & context);
		void formatEntries(std::ostream & out,const std::string & prefix,const std::string & separator,const std::string & postfix,svutStringFilter filter = NULL) const;
		void formatEntries(std::ostream & out,const char * prefix,const char * separator,const char * postfix,svutStringFilter filter = NULL) const;
		void formatContext(std::ostream & out,const std::string & prefix,const std::string & separator,const std::string & postfix,svutStringFilter filter = NULL) const;
		void formatContext(std::ostream & out,const char * prefix,const char * separator,const char * postfix,svutStringFilter filter = NULL) const;
		void setOutput(const std::string & output);
		svutStatusInfoMap getEntries(void) const;
		unsigned int getNbEntries(void) const;
		svutStatusInfoMap getContext(void) const;
		unsigned int getNbContextEntries(void) const;
		std::string getEntry(std::string name) const;
		std::string getContextEntry(std::string name) const;
		std::string getStatusName(void) const;
		static std::string getStatusName(svutStatus status);
		const std::string& getOutput(void) const;
		double getDuration(void) const;
		void setDuration(double duration);
	protected:
		void formatList(const svutStatusInfoMap & list,std::ostream & out,const std::string & prefix,const std::string & separator,const std::string & postfix,svutStringFilter filter=NULL) const;
		/** Define the message related to the status of the test. **/
		std::string message;
		/** Extra parameters to describe the current status, mainly for errors debugging. **/
		svutStatusInfoMap entries;
		/** Keep the postition of failing assertion in the source code. **/
		svutCodeLocation location;
		/** Define the current status of the test.**/
		svutStatus status;
		/** Debugging context formed by an hash table of string. **/
		svutStatusInfoMap context;
		/** Store the debugging output, for now it's an emulation for capturing real stdout/stderr. **/
		std::string output;
		/** Measure the time it took to run, in seconds. **/
		double duration;
};

}

#endif
