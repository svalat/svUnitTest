/*****************************************************
             PROJECT  : svUnitTest
             VERSION  : 0.0.2
             DATE     : 07/2010
             AUTHOR   : Valat Sébastien
             LICENSE  : CeCILL-C
*****************************************************/

#ifndef SVUT_TEST_CASE_HEADER
#define SVUT_TEST_CASE_HEADER

/********************  HEADERS  *********************/
#include <string>
#include <list>
//#include "svutTestFilter.h"
#include "svutTestMethod.h"
#include "svutExAssert.h"
#include "svutExNotify.h"
//#include "svutResultFormater.h"
//#include "svutAutoRegister.h"

namespace svUnitTest
{

/********************  MACROS  **********************/
/**
 * This macro must be used when developping tests to declare all the functions related to the test
 * case. It must be called in the constructor of the test case.
 * @param type Define the name of the test case class to build the good objet method pointer using
 * the generic class svutObjectMethodeGeneric.
 * @param func Define the name of the test method to register.
**/
#define SVUT_REG_TEST_METHOD(type,func) do{\
	svUnitTest::svutObjectMethod * __svut__meth__ = new svUnitTest::svutObjectMethodGeneric<type>(this,&type::func);\
	svUnitTest::svutTestMethod * __svut__testMeth__ = new svUnitTest::svutTestMethod(#func,__svut__meth__,SVUT_CODE_LOCATION); \
	this->registerTestMethod(__svut__testMeth__);\
} while(0)

/*
 * This macro must be used in the source file of all tests to register the test in the global
 * lists of test to run when svutRunner is called. We call this "automatic registration" as you
 * didn't need to build a list of the tests and give it to svutRunner. So it's simpler to add new
 * tests as all the needs can be filled in one file per test which can be move between projects
 * independently of the test runner.
 * You can register multiple test cas in the same file.
 * @param name Define the class name of the test case to register.
#define SVUT_REGISTER_TEST_CASE(name) \
	static svUnitTest::svutTestCaseBuilderGeneric<name> ___SVUT_case_##name##___;\
	static int ___SVUT_res_case_registration_of##name##__ = registerTestCase(___SVUT_case_##name##___);*/

/********************  GLOBALS  **********************/
//extern list<class svutTestCaseBuilder *> __SVUT_autoFoundTests__;

/********************  CLASSE  **********************/
class svutListener;

/********************  CLASSE  **********************/
/**
 * Define a test case. A test case is composed of multiple test methode which tests propoerties
 * and interactions of an object. Each test method is registered via svutTestFunction.
 * All the tests are wrote as functions of a class which inherit from svutTestCase.
 * Définit un cas de test. Un cas de test est composé d'un ensemble de functions de tests,
 * chaque fonction de test correspondant à un objet de type svutTestFunction which is the basis
 * of tests building.
 * @brief Base class for test cases implementation.
 * @author Valat Sébastien
 * @version 0.0.2
**/
class svutTestCase
{
	public:
		svutTestCase(std::string name);
		svutTestCase(const svutTestCase & testCase);
		virtual ~svutTestCase(void);
		/**
		 * The developer need to re-implement this method to initialized the tested objects.
		 * This methode is called before each tests defined in the test case.
		 *
		 * Mainly it's recommended to build your test object with the new operator, so you
		 * can delete it at the end of the test in tearDown() to get a fresh object for each test
		 * and ensuire that you didn't create dependances between your tests.
		**/
		virtual void setUp(void) = 0;
		/**
		 * The developer need to re-implement this method to clean up the tests objects build in the
		 * setUp() method. This method is called after each tests defined in the test case.
		 *
		 * Mainly we done "delete" call here to free memory allocated in setUp().
		**/
		virtual void tearDown(void) = 0;
		//void runTestCase2(svutResultFormater & formater,const svutTestFilter & filter);
		void runTestCase(void);
		std::string getName(void) const;
		std::list<std::string> getTestMethods(bool prefix) const;
		unsigned int getNbTests(void) const;
		void setAutodetected(void);
		bool isAutodetected(void) const;
		void setListener(svutListener * listener);
	protected:
		void registerTestMethod(svutTestMethod * test);
		svutStatusInfo runTestMethod(svutTestMethod * test);
		void failIsTodo(std::string message);
		/** Define the list of tests methods in the current test case. **/
		std::list<svutTestMethod *> tests;
		/** Define the name of the current test case, this may be the classe name. **/
		std::string caseName;
	private:
		/**
		 * Boolean used to replace FAILED stats by TODO status when failIsTodo() was invoqued in a
		 * test method. It permit to no display FAILURE on known break which poulte the output
		 * and may mask new breaking if there is too much. It also replace the
		 * SUCCESS status bug INDEV status.
		**/
		bool tmpFailIsTodo;
		/**
		 * Associate a message when replacing a fail by TODO, or SUCCESS by INDEV when failIsTodo()
		 * was invoqued in a test.
		**/
		std::string tmpFailMessage;
		/** Permit to now if the class was built by autodetection chain or not. **/
		bool autodtected;
		/**
		 * Define the base listener class to dipatch test events, this is used to agregate results,
		 * display current progression... Here we instanciate a svutListenerMultiplexer to dipatch
		 * events to multiple sub listener->
		**/
		svutListener * listener;
};

//int registerTestCase(svutTestCaseBuilder & builder);
}

#endif