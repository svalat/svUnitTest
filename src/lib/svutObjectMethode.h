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
 * Base class used to build a C++ function pointer on class member.
 * This is an abstract class which must be override to form a geneic class to support each required
 * classes.
 * @brief Base class to define member method pointer on C++ objects.
 * @author Valat Sébastien
 * @version 0.0.1
**/
class svutObjectMethode
{
	public:
		svutObjectMethode() {};
		virtual ~svutObjectMethode() {};
		/**
		 * Method used ta call the function.
		**/
		virtual void call(void) = 0;
};

/********************  CLASSE  **********************/
/**
 * Generic implementation of svutObjectMethode to manage all class types. Caution, this implementation
 * didn't work with virtual members.
 * @brief Genric implementation of C++ function pointer.
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
		/** Pointer to the objet on which call the method. **/
		T * object;
		/** Adress of the method to call. **/
		void (T::*methode)(void);
};

};

/*****************  GENERIC IMPLE  ******************/
#include "svutObjectMethodeGenericImpl.h"

#endif
