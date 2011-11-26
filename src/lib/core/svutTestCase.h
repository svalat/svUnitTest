/*****************************************************
             PROJECT  : svUnitTest
             VERSION  : 0.3.0
             DATE     : 05/2011
             AUTHOR   : Valat Sébastien
             LICENSE  : CeCILL-C
*****************************************************/

#ifndef SVUT_TEST_CASE_HEADER
#define SVUT_TEST_CASE_HEADER

/********************  HEADERS  *********************/
#include <string>
#include <list>
#include <sstream>
#include "svutTestMethod.h"
#include "svutExAssert.h"
#include "svutExNotify.h"
#include "svutAutoRegister.h"
#include "svutTestFilter.h"
#include "svutAssert.h"

/********************  NAMESPACE  *******************/
namespace svUnitTest
{

/********************  MACROS  **********************/
/**
 * Support type determination at compile time by using typeof C++ extention (not ISO).
 * For C++0x we can use the replacement ISO keyword decltype. Currently due to definition embiguity
 * we use a trick to remove the reference from the class type by using the svut_get_class_type()
 * fake function.
 * @param x Define a pointer of the class type we want to extract (typically we will use 'this').
**/
#ifdef __GXX_EXPERIMENTAL_CXX0X__
#define SVUT_TYPEOF(x) decltype(svut_get_class_type(x))
#elif defined(_MSC_VER)
#define SVUT_TYPEOF(x) decltype(svut_get_class_type(x))
#else
#define SVUT_TYPEOF(x) typeof(*x)
#endif

/********************  MACROS  **********************/
/**
 * This macro must be used when developping tests to declare all the functions related to the test
 * case. It must be called in the constructor of the test case.
 * @param func Define the name of the test method to register.
**/
#define SVUT_REG_TEST_METHOD(func) do{\
	typedef SVUT_TYPEOF(this) __SVUT_CURRENT_CLASS__;\
	svUnitTest::svutObjectMethod * __svut__meth__ = new svUnitTest::svutObjectMethodGeneric<__SVUT_CURRENT_CLASS__>(this,&__SVUT_CURRENT_CLASS__::func);\
	svUnitTest::svutTestMethod * __svut__testMeth__ = new svUnitTest::svutTestMethod(#func,__svut__meth__,SVUT_CODE_LOCATION); \
	this->registerTestMethod(__svut__testMeth__);\
} while(0)

/********************  MACROS  **********************/
/**
 * Prefer to use this macro instead of directly call setContextEntry on the svutTestCase class.
 * This permit to clearly identify test related section of your code.
 * @param name Define the name of the entry.
 * @param value Define the related value, it will be convertied in string format by asserterToString
 * function.
**/
#define SVUT_SET_CONTEXT(name,value) this->setContextEntry((name),(value))

/********************  MACROS  **********************/
/**
 * Prefer to use this macro instead of directly call clearContexEntry on the svutTestCase class.
 * This permit to remove some old context entries while exiting loops for exemple.
 * @param name Define the name of the entry.
**/
#define SVUT_UNSET_CONTEXT(name) this->clearContexEntry((name))

/********************  MACROS  **********************/
/**
 * Prefer to use this macro instead of directly call clearContexEntry on the svutTestCase class.
 * This permit to remove all context entries for exemple while exiting loops for exemple.
**/
#define SVUT_RESET_CONTEXT() this->resetContexEntries()

/********************  MACROS  **********************/
/**
 * A macro to access to unit test printf method.
**/
#define SVUT_PRINTF this->printf

/********************  MACROS  **********************/
/**
 * A macro to access  to unit test cout object.
**/
#define SVUT_COUT this->cout

/********************** TYPEDEF *********************/
/** List of pointers to test methods. **/
typedef std::list<svutTestMethod *> svutTestMethodPtrList;
/** List of names of test methods. **/
typedef std::list<std::string> svutTestMethodNameList;

/*********************  CLASS  **********************/
class svutListener;

/*********************  CLASS  **********************/
/**
 * Define a test case. A test case is composed of multiple test methode which tests propoerties
 * and interactions of an object. Each test method is registered via svutTestFunction.
 * All the tests are wrote as functions of a class which inherit from svutTestCase.
 * Définit un cas de test. Un cas de test est composé d'un ensemble de functions de tests,
 * chaque fonction de test correspondant à un objet de type svutTestFunction which is the basis
 * of tests building.
 * @brief Base class for test cases implementation.
 * @author Valat Sébastien
**/
class svutTestCase
{
	public:
		svutTestCase(std::string name="Undefined");
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
		void runTestCase(svutListener * listener,svutTestFilter * filter = NULL);
		std::string getName(void) const;
		svutTestMethodNameList getTestMethods(bool prefix) const;
		void listTestMethods(svutListener & listener,svutTestFilter * filter = NULL) const;
		unsigned int getNbTests(void) const;
		void setAutodetected(void);
		bool isAutodetected(void) const;
		void callTestMethodsRegistration(void);
		/** Used to capture output done in tests. **/
		std::stringstream cout;
		int printf(const char * format,...);
	protected:
		virtual void testMethodsRegistration(void);
		void setTestCaseName(std::string name) throw (svutExInternalError);
		void registerTestMethod(svutTestMethod * test);
		void setContextEntry(std::string name,std::string value);
		void resetContexEntries(void);
		void clearContexEntry(std::string name);
		template <class T> void setContextEntry(std::string name,const T & value);
		svutStatusInfo runTestMethod(svutTestMethod * test);
		void MARK_AS_KNOWN_ERROR(std::string message);
		/** Define the list of tests methods in the current test case. **/
		svutTestMethodPtrList tests;
	private:
		/** Define the name of the current test case, this may be the classe name. **/
		std::string caseName;
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
		 * Permit to know if the test suite can be renamed of not. This is locked after first
		 * call of getName();
		**/
		mutable bool nameLocked;
		/** Permit to know if testMethodsRegistration() was already called. **/
		bool registrationDone;
		/** String map to store context entries. **/
		svutStatusInfoMap context;
};

/*******************  FUNCTION  *********************/
/**
 * Insert an entry to the bug context description which will be added to assertion informations
 * in case of failure.
 * @param name Define the name of the entry
 * @param value Define the related value, it will be convertied in string format by asserterToString
 * function.
**/
template <class T>
void svutTestCase::setContextEntry(std::string name, const T & value)
{
	setContextEntry(name,asserterToString(value));
}

/*******************  FUNCTION  *********************/
#if defined(__GXX_EXPERIMENTAL_CXX0X__) || defined(_MSC_VER)
/**
 * In C++0x we can use the ISO keyword decltype to get the type of an object at compile type and
 * use it in delcarations. But buy default, decltyp(*this) return a reference type (MyClass&) and not
 * strict class name (MyClass). This lead to failure while interacting with ORP operator ::.
 * To bypass that issue, we simply use this method to convert the pointer type to simple class type
 * which can be used in decltype to get what we want. This method isn't executed an only serve for
 * type determination at compile time.
 * @param obj Define a pointer to the class type to cast, typically we will use 'this'.
**/
template <class T>
T svut_get_class_type(T * obj)
{
	abort();
	return *obj;
}
#endif

//int registerTestCase(svutTestCaseBuilder & builder);
}

#endif
