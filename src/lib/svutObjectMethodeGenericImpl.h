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
 * Default class constructor.
 * @param object Define the object on which to call the method.
 * @param methode Define the metho to call on the selected object. Caution, it can't be a virtual
 * function.
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