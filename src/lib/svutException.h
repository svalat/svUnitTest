/*****************************************************
             PROJECT  : svUnitTest
             VERSION  : 0.0.2
             DATE     : 06/2010
             AUTHOR   : Valat Sébastien
             LICENSE  : CeCILL-C
*****************************************************/


#ifndef SVUT_EXCEPTION_HEADER
#define SVUT_EXCEPTION_HEADER


/********************  HEADERS  *********************/
#include <exception>
#include <string>

namespace svUnitTest
{

/********************  CLASSE  **********************/
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

};

#endif