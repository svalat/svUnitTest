/*****************************************************
             PROJECT  : svUnitTest
             VERSION  : 0.0.2
             DATE     : 06/2010
             AUTHOR   : Valat Sébastien
             LICENSE  : CeCILL-C
*****************************************************/

#ifndef SVUT_OBJECT_METHODE_GENERIC_IMPL_HEADER
#define SVUT_OBJECT_METHODE_GENERIC_IMPL_HEADER


/********************  HEADERS  *********************/
#include "svutObjectMethode.h"

namespace svUnitTest
{

/********************  METHODE  *********************/
/**
 * Constructeur de la classe.
 * @param object Définit l'objet à utiliser pour appeler la méthode.
 * @param methode Définit la méthode à appeler sur l'objet. Attention il ne peux pas s'agir d'une
 * méthode virtuelle.
**/
template<class T>
svutObjectMethodeGeneric<T>::svutObjectMethodeGeneric(T * object,void (T::*methode)(void))
{
	this->object = object;
	this->methode = methode;
}

/********************  METHODE  *********************/
template<class T>
void svutObjectMethodeGeneric<T>::call(void)
{
	(object->*methode)();
}

};

#endif