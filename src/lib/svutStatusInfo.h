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
 * Définit la liste des status autorisés dans la librairie.
 * @brief Définit les status autorisés dans la librairie.
**/
enum svutStatus
{
	/** Le test est à rédiger ou modifier. **/
	SVUT_STATUS_TODO,
	/** Le test est en cours de rédaction ou modification. **/
	SVUT_STATUS_INDEV,
	/** Le test n'a pas été exécuté. **/
	SVUT_STATUS_SKIPED,
	/** Le test a été passé avec succès. **/
	SVUT_STATUS_SUCCESS,
	/** Une erreur est survenue lors du test. **/
	SVUT_STATUS_FAILED,
	/** Une erreur inconnue est survenue lors du test. **/
	SVUT_STATUS_UNKNOWN,
};

/********************  CLASSE  **********************/
/**
 * Classe permettant de stocker les informations des assertions renvoyées par les tests sous une
 * forme plus simple à utiliser par les formatters. Elle sera typiquement renvoyée via les
 * levée d'exception lorsqu'une assertion n'est pas vérifiée.
 * @brief Classe de mise en forme des informations de status.
 * @author Valat Sébastien.
 * @version 0.0.1
**/
class svutStatusInfo
{
	public:
		svutStatusInfo(svutStatus status,std::string message,const svutCodeLocation & location);
		std::string getMessage(void) const;
		svutCodeLocation getLocation(void) const;
		svutStatus getStatus(void) const;
		void addEntry(std::string name,std::string value);
		void formatEntries(std::ostream & out,std::string prefix,std::string separator,std::string postfix) const;
		std::map<std::string,std::string> getEntries(void) const;
	protected:
		/** Définit un message associé aux informations. **/
		std::string message;
		/** Liste les paramêtres donnant de l'information sur l'assertion. **/
		std::map<std::string,std::string> entries;
		/** Garde la position de l'assertion dans le code source. **/
		svutCodeLocation location;
		/** Définit le status courrant du test.**/
		svutStatus status;
};

};

#endif
