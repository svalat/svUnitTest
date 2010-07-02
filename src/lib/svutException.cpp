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
 * Constructeur de la classe.
**/
svutException::svutException(void) throw()
{
}

/********************  METHODE  *********************/
/**
 * surcharge du constructeur par défaut.
 * @param message Définit un message à associer à l'erreur.
**/
svutException::svutException(std::string message) throw()
{
	this->message = message;
}

/********************  METHODE  *********************/
/**
 * Destructeur de la classe. Utilisée principalement pour l'héritage.
 */
svutException::~svutException(void) throw()
{
}

/********************  METHODE  *********************/
/**
 * Surcharge de la méthode requise par std::exception.
 * @return Renvoie le message contenu dans l'exception sous a forme d'une chaine de caractère C.
 */
const char* svutException::what() const  throw()
{
	return message.c_str();
}

/********************  METHODE  *********************/
/**
 * @return Renvoie le message associé à l'exception sous la forme d'un string.
 */
std::string svutException::getMessage(void) const
{
	return message;
}

};