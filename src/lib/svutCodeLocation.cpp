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

#include "svutCodeLocation.h"

using namespace std;
namespace svUnitTest
{

/********************  CONSTS  **********************/
/**
 * Constrante permettant disposer d'une instance non localisé de la classe svutCodeLocation sous
 * la forme d'une constante utilisable partout.
 **/
const svutCodeLocation SVUT_NO_LOCATION;

/********************  METHODE  *********************/
/**
 * Constructeur de la classe pour créer une instance non localisée.
**/
svutCodeLocation::svutCodeLocation(void)
{
	this->line = -1;
	this->located = false;
}

/********************  METHODE  *********************/
/**
 * Constructeur de la classe permettant de définir les informations de coordonnées dans les sources.
 * Ce constructeur est normalement appelé via la macro SVUT_CODE_LOCATION afin de définir
 * automatiquement les informations de localisation en utilisant les macro du compilateur.
 * @param file Définie le ficier source.
 * @param methode Définie la méthode.
 * @param line Définie la ligne dans le fichier source.
**/
svutCodeLocation::svutCodeLocation(std::string file,std::string methode,int line)
{
	this->file = file;
	this->methode = methode;
	this->line = line;
	this->located = true;
}

/********************  METHODE  *********************/
/**
 * @return Renvoie le nom du fichier source ou "unknown"
 */
std::string svutCodeLocation::getFilename(void) const
{
	if (located)
		return this->file;
	else
		return "unknown";
}

/********************  METHODE  *********************/
/**
 * @return  Renvoie le nom de la méthode ou "unknown"
 */
std::string svutCodeLocation::getMethodeName(void) const
{
	if (located)
		return this->methode;
	else
		return "unknown";
}

/********************  METHODE  *********************/
/**
 * @return Renvoie la ligne dans le fichier source ou -1.
**/
int svutCodeLocation::getLine(void) const
{
	if (located)
		return this->line;
	else
		return -1;
}

/********************  METHODE  *********************/
/**
 * @return Renvoie true si l'insance contient une localisation ou false si elle ne définit aucune
 * localisation précise (cas de SVUT_NO_LOCATION).
**/
bool svutCodeLocation::hasLocation(void) const
{
	return located;
}

/********************  METHODE  *********************/
/**
 * Opérateur de flux sortant permettant de formater la localisation sous la forme d'une chaine
 * de caractère.
 * @param out Définie le flux à utiliser.
 * @param location Définie la localisation à formater.
 * @return Renvoie le flux de sortie utilisé.
 */
std::ostream & operator << (std::ostream & out,const svutCodeLocation & location)
{
	if (location.located)
		out << "line " << location.line
			<< " of file " << location.file
			<< " on methode " <<location. methode << "()";
	else
		out << "unknown location";
	return out;
}

/********************  METHODE  *********************/
/**
 * Définit l'opérateur de test d'égalité de deux localisation dans le code source.
 * @param loc1 Définit la première localisation
 * @param loc2 Définit la seconde localisation
 * @return Renvoie true si les deux localisation sont égales membres à membres.
**/
bool operator == (const svutCodeLocation & loc1,const svutCodeLocation & loc2)
{
	return loc1.file == loc2.file && loc1.line == loc2.line && loc1.methode == loc2.methode;
}

};
