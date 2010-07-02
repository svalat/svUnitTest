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
 * Classe de base pour les exception utilisée au sein de la bibliothèque de test unitaire.
 * Cette classe surcharge simplement std::exception pour s'intérer dans le flux normal d'erreur
 * de la librairie standard.
 * @brief Classe de base pour les exceptions de la bibliothèque de tests unitaires.
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
		std::string getMessage(void) const;
	private:
		/** Attache un message de description de l'erreur. **/
		std::string message;
};

};

#endif