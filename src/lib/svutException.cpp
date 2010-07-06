/*****************************************************
             PROJECT  : svUnitTest
             VERSION  : 0.0.2
             DATE     : 06/2010
             AUTHOR   : Valat Sébastien
             LICENSE  : CeCILL-C
*****************************************************/

/********************  HEADERS  *********************/
#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "svutException.h"

namespace svUnitTest
{

/********************  METHODE  *********************/
/**
 * Default constructor the the class.
**/
svutException::svutException(void) throw()
{
}

/********************  METHODE  *********************/
/**
 * Constructor of the classe.
 * @param message Define a message to describe the exception.
**/
svutException::svutException(std::string message) throw()
{
	this->message = message;
}

/********************  METHODE  *********************/
/**
 * Destructor of the class. Done nothing, but defined to ensure inheritance.
**/
svutException::~svutException(void) throw()
{
}

/********************  METHODE  *********************/
/**
 * Implement method required by std::exception.
 * @return Return the message stored in the ecxeption as a C string.
**/
const char* svutException::what() const  throw()
{
	return message.c_str();
}

/********************  METHODE  *********************/
/**
 * @return Return the message stored in the exception as a std::string.
**/
std::string svutException::getMessage(void) const
{
	return message;
}

};
