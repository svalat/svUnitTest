/*****************************************************
             PROJECT  : svUnitTest
             VERSION  : 0.3.0
             DATE     : 05/2011
             AUTHOR   : Valat Sébastien
             LICENSE  : CeCILL-C
*****************************************************/

/********************  HEADERS  *********************/
#include "svutException.h"

/********************  NAMESPACE  *******************/
namespace svUnitTest
{

/*******************  FUNCTION  *********************/
/**
 * Default constructor the the class.
**/
svutException::svutException(void) throw()
{
}

/*******************  FUNCTION  *********************/
/**
 * Constructor of the classe.
 * @param message Define a message to describe the exception.
**/
svutException::svutException(std::string message) throw()
{
	this->message = message;
}

/*******************  FUNCTION  *********************/
/**
 * Destructor of the class. Done nothing, but defined to ensure inheritance.
**/
svutException::~svutException(void) throw()
{
}

/*******************  FUNCTION  *********************/
/**
 * Implement method required by std::exception.
 * @return Return the message stored in the ecxeption as a C string.
**/
const char* svutException::what() const  throw()
{
	return message.c_str();
}

/*******************  FUNCTION  *********************/
/**
 * @return Return the message stored in the exception as a std::string.
**/
std::string svutException::getMessage(void) const
{
	return message;
}

/*******************  FUNCTION  *********************/
/** @copydoc svutException::svutException(std::string) **/
svutExInternalError::svutExInternalError(std::string message) throw()
	:svutException(message)
{

}

/*******************  FUNCTION  *********************/
/** @copydoc svutException::~svutException() **/
svutExInternalError::~svutExInternalError(void ) throw()
{

}


}
