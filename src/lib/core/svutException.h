/*****************************************************
             PROJECT  : svUnitTest
             VERSION  : 0.3.0
             DATE     : 05/2011
             AUTHOR   : Valat Sébastien
             LICENSE  : CeCILL-C
*****************************************************/

#ifndef SVUT_EXCEPTION_HEADER
#define SVUT_EXCEPTION_HEADER

/********************  HEADERS  *********************/
#include <exception>
#include <string>

/*********************  MACROS  *********************/
#ifdef _MSC_VER
	//VCC doesn't support throw() specification in function prototype
	//we can safely disable the related warning to avoid spamming the
	//building output
	#pragma warning(disable: 4290)
	//VCC sucks with it's OS dependant warning for strncpy_s
	#pragma warning(disable: 4996)
	//hummm this one may be solve but not really easily.
	#pragma warning(disable: 4355)
#endif

/********************  NAMESPACE  *******************/
namespace svUnitTest
{

/*********************  CLASS  **********************/
/**
 * Base class for exception used by the unit test library.
 * This class is just an override of std::exception to base all library exception on the same
 * class.
 * @brief Base class for all exceptions used by the unit test library.
 * @author Valat Sébastien
 * @version 0.0.1
**/
class svutException : public std::exception
{
	public:
		svutException(void) throw();
		svutException(std::string message) throw();
		virtual ~svutException(void) throw();
		virtual const char* what() const  throw();
		virtual std::string getMessage(void) const;
	private:
		/** Message attached to the current exception to describe the error. **/
		std::string message;
};

/*********************  CLASS  **********************/
/**
 * Exception used for internal error in the library.
 * @brief Class used to throw exception on internal error.
 * @author Valat Sébastien
**/
class svutExInternalError : public svutException
{
	public:
		svutExInternalError(std::string message) throw();
		virtual ~svutExInternalError(void) throw();
};

}

#endif
