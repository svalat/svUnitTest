/*****************************************************
             PROJECT  : svUnitTest
             VERSION  : 0.0.2
             DATE     : 06/2010
             AUTHOR   : Valat Sébastien
             LICENSE  : CeCILL-C
*****************************************************/

#ifndef SVUT_CODE_LOCATION_HEADER
#define SVUT_CODE_LOCATION_HEADER

/********************  HEADERS  *********************/
#include <string>
#include <ostream>

namespace svUnitTest
{

/********************  MACROS  **********************/
/**
 * Macro à utiliser pour créer les instances de svutCodeLocation. Elle permet d'utiliser
 * automatiquement les macros du compilateur pour renseigner les arguements fichier, méthode et
 * ligne.
**/
#define SVUT_CODE_LOCATION svUnitTest::svutCodeLocation(__FILE__,__FUNCTION__,__LINE__)

/********************  CLASSE  **********************/
/**
 * Classe de localisation dans le code de l'application. Elle permet de transporter l'information
 * lié à une erreur d'assertion dans les tests. Les instances de cette classes sont normalement
 * créé à l'aide de la macro SVUT_CODE_LOCATION afin de définir automatiquement les informations
 * de la classe en utilisant les macros du compilateur.
 * La localisation se fait sous la forme, fichier, fonction, ligne.
 * @brief Classe de localisation des assertions dans le code source.
 * @author Valat Sébastien
 * @version 0.0.1
**/
class svutCodeLocation
{
	public:
		svutCodeLocation(void);
		svutCodeLocation(std::string file,std::string methode,int line);
		std::string getFilename(void) const;
		std::string getMethodeName(void) const;
		int getLine(void) const;
		bool hasLocation(void) const;

		friend std::ostream & operator << (std::ostream & out,const svutCodeLocation & location);
		friend bool operator == (const svutCodeLocation & loc1,const svutCodeLocation & loc2);
	protected:
		/** Définie le fichier source. **/
		std::string file;
		/** Définie la méthode **/
		std::string methode;
		/** Définie la ligne dans le fichier source. **/
		int line;
		/**
		 * Permet de savoir si les informations sont renseignées ou bien s'il s'agit d'une non
		 * localisation.
		**/
		bool located;
};

/********************  CONSTS  **********************/
/**
 * Constrante permettant disposer d'une instance non localisé de la classe svutCodeLocation sous
 * la forme d'une constante utilisable partout.
**/
extern const svutCodeLocation SVUT_NO_LOCATION;

};

#endif
