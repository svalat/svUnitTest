/*****************************************************
             PROJECT  : svUnitTest
             VERSION  : 0.5.0-dev
             DATE     : 11/2012
             AUTHOR   : Valat Sébastien
             LICENSE  : CeCILL-C 2.1
*****************************************************/

#ifndef SVUT_TEST_METHOD_HEADER
#define SVUT_TEST_METHOD_HEADER

/********************  HEADERS  *********************/
#include <string>
#include "svutCodeLocation.h"

/********************  NAMESPACE  *******************/
namespace svUnitTest
{

/*********************  CLASS  **********************/
class svutObjectMethod;

/*********************  CLASS  **********************/
/**
 * Class which describe a function into test case. Each function represent a test. This class
 * is mainly use to attach the function, his unmangle name and the require to call it into the
 * test case to call it when running the tests. Object from this class may be created by
 * SVUT_REG_TEST_FUNCTION from svutTestCase.h.
 * @brief Define a test method.
 * @author Valat Sébastien.
**/
class svutTestMethod
{
	public:
		svutTestMethod(std::string name,svutCodeLocation location,svutObjectMethod * testMethod,svutObjectMethod * setupMeth = NULL,svutObjectMethod * tearDownMeth = NULL);
		virtual ~svutTestMethod();
		std::string getName(void) const;
		void callSetup(void);
		void callTest(void);
		void callTearDown(void);
		svutCodeLocation getLocation(void) const;
	protected:
		/**
		 * Define the name of the test. Basicly we may use the name of the methode here.
		 * This name was setted by SVUT_REG_TEST_FUNCTION macro from svutTestCase.h.
		**/
		std::string name;
		/**
		 * Pointer to svutObjectMethode object wich permit to dynamicly call the function on the
		 * test case object.
		**/
		svutObjectMethod * testMethod;
		/**
		 * Pointer to svutObjectMethod to run the setup step.
		**/
		svutObjectMethod * setupMethod;
		/**
		 * Pointer to svutObjectMethod to run the tearDown step.
		**/
		svutObjectMethod * tearDownMethod;
		/**
		 * Define the source location of the methode. For moment, the position correspond the the
		 * declaration line with SVUT_REG_TEST_FUNCTION macro which is not the implementation
		 * location. This location is used in case of unknown errors which didn't provide correct
		 * location informations.
		**/
		svutCodeLocation location;
	private:
		/** Copy is forbidden. **/
		svutTestMethod(const svutTestMethod & orig);
		/** Copy is forbidden. **/
		svutTestMethod & operator = (const svutObjectMethod & orig);
};

}

#endif
