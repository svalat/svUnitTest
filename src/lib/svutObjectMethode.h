/*****************************************************
             PROJECT  : svUnitTest
             VERSION  : 0.0.2
             DATE     : 06/2010
             AUTHOR   : Valat Sébastien
             LICENSE  : CeCILL-C
*****************************************************/

#ifndef SVUT_OBJECT_METHODE_HEADER
#define SVUT_OBJECT_METHODE_HEADER

namespace svUnitTest
{

/********************  CLASSE  **********************/
/**
 * Classe de base utilisé pour créer une forme de pointeur de fonction pour les membres de classe.
 * Cette classe de base doit être surchargée par une forme généric pour pouvoir prendre en charge
 * tous les types de classes possible.
 * @brief Classe de base définissant une forme de pointeur de fonction membre.
 * @author Valat Sébastien
 * @version 0.0.1
**/
class svutObjectMethode
{
	public:
		svutObjectMethode() {};
		virtual ~svutObjectMethode() {};
		/**
		 * Méthode permettant de lancer l'appel.
		**/
		virtual void call(void) = 0;
};

/********************  CLASSE  **********************/
/**
 * Implémentation générique  de svutObjectMethode afin de prendre en charge tous les types d'objets
 * utilisés. Attention, l'implémentation de fonctionne pas pour les membres virtuels.
 * @brief Implémentation générique de la classe pointeur de fonction.
 * @author Valat Sébastien
 * @version 0.0.1
**/
template <class T>
class svutObjectMethodeGeneric : public svutObjectMethode
{
	public:
		svutObjectMethodeGeneric(T * object,void (T::*methode)(void));
		virtual void call(void);
	protected:
		/** Pointeur vers l'objet à utiliser pour appeler la méthode membre. **/
		T * object;
		/** Adresse de la méthode membre. **/
		void (T::*methode)(void);
};

};

/*****************  GENERIC IMPLE  ******************/
#include "svutObjectMethodeGenericImpl.h"

#endif
