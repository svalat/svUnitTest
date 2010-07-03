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

#include "svutStatusInfo.h"

using namespace std;
namespace svUnitTest
{

/********************  METHODE  *********************/
/**
 * Constructeur par défaut.
 * @param message Définit le message d'information associé aux informations.
 * @param location Position de l'assertion dans le code source.
**/
svutStatusInfo::svutStatusInfo(svUnitTest::svutStatus status, string message, const svUnitTest::svutCodeLocation& location)
	:location(location)
{
	this->message = message;
	this->status = status;
}

/********************  METHODE  *********************/
/**
 * @return Renvoie la position dans le code source associée à l'assertion.
**/
svutCodeLocation svutStatusInfo::getLocation(void) const
{
	return this->location;
}

/********************  METHODE  *********************/
/**
 * @return Renvoie le message de l'assertion.
**/
std::string svutStatusInfo::getMessage(void) const
{
	return this->message;
}

/********************  METHODE  *********************/
/**
 * @return Renvoie le status actuellement associé au test.
**/
svutStatus svutStatusInfo::getStatus ( void ) const
{
	return this->status;
}

/********************  METHODE  *********************/
/**
 * Ajoute une entré dans la listes des paramêtres de l'assertion.
 * @param name Définit le nom du champ.
 * @param value Définit la valeur associée.
 */
void svutStatusInfo::addEntry(std::string name,std::string value)
{
	this->entries.insert(pair<string,string>(name,value));
}

/********************  METHODE  *********************/
/**
 * @return Renvoie la liste des entrée d'information.
**/
std::map<std::string,std::string> svutStatusInfo::getEntries(void) const
{
	return entries;
}

/********************  METHODE  *********************/
/**
 * Met en forme les informations et les affiche dans le flux passé en paramètre.
 * @param out Définit le flux de sortie à utiliser.
 * @param prefix Définit la chaine à placer avant chaque nom de champ.
 * @param separator Définit la chaine à placer entre le nom du champ et la valeur.
 * @param postfix Définit la chaine à placer après la valeur.
 */
void svutStatusInfo::formatEntries(std::ostream & out,std::string prefix,std::string separator,std::string postfix) const
{
	for (map<string,string>::const_iterator it=entries.begin() ; it != entries.end(); it++ )
		out << prefix << it->first << separator << it->second << postfix;
}

};
