/*****************************************************
             PROJECT  : svUnitTest
             VERSION  : 0.4.0
             DATE     : 11/2012
             AUTHOR   : Valat Sébastien
             LICENSE  : CeCILL-C
*****************************************************/

#ifndef SVUT_OBJECT_METHODE_HEADER
#define SVUT_OBJECT_METHODE_HEADER

/********************  NAMESPACE  *******************/
namespace svUnitTest
{

/*********************  CLASS  **********************/
/**
 * Base class used to build a C++ function pointer on class member.
 * This is an abstract class which must be override to form a geneic class to support each required
 * classes.
 * @brief Base class to define member method pointer on C++ objects.
 * @author Valat Sébastien
 * @version 0.0.1
**/
class svutObjectMethod
{
	public:
		svutObjectMethod() {}
		virtual ~svutObjectMethod() {}
		/**
		 * Method used ta call the function.
		**/
		virtual void call(void) = 0;
};

/*********************  CLASS  **********************/
/**
 * Generic implementation of svutObjectMethode to manage all class types. Caution, this implementation
 * didn't work with virtual members.
 * @brief Genric implementation of C++ function pointer.
 * @author Valat Sébastien
 * @version 0.0.1
**/
template <class T>
class svutObjectMethodGeneric : public svutObjectMethod
{
	public:
		svutObjectMethodGeneric(T * object,void (T::*methode)(void));
		virtual void call(void);
	protected:
		/** Pointer to the objet on which call the method. **/
		T * object;
		/** Adress of the method to call. **/
		void (T::*methode)(void);
};

/********************  TYPEDEF  *********************/
/**
 * Define the prototype of methodes for flat test mode (simple C functions).
 * @version 0.4.0
**/
typedef void (*svutTestMethodPtr)(void);

/*********************  CLASS  **********************/
/**
 * Class used to store pointer to a simple C function. It will be used to implement
 * the flat test way based on simple C functions.
 * @brief Pointer to simple C function for flat test mode.
 * @author Valat Sébastien
 * @version 0.4.0
**/
class svutFlatObjectMethod : public svutObjectMethod
{
	public:
		svutFlatObjectMethod(svutTestMethodPtr method);
	    virtual void call(void );
	protected:
		/** Pointer to the C method to call. **/
		svutTestMethodPtr method;
};

}

/******************  GENERIC IMPL  ******************/
#include "svutObjectMethodGenericImpl.h"

#endif
