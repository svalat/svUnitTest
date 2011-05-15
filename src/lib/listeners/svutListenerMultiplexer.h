/*****************************************************
             PROJECT  : svUnitTest
             VERSION  : 0.3.0
             DATE     : 05/2011
             AUTHOR   : Valat Sébastien
             LICENSE  : CeCILL-C
*****************************************************/

#ifndef SVUT_LISTENER_MULTIPLEXER_HEADER
#define SVUT_LISTENER_MULTIPLEXER_HEADER

/********************  HEADERS  *********************/
#include <list>
#include "svutListener.h"

/********************  NAMESPACE  *******************/
namespace svUnitTest
{

/********************** TYPEDEF *********************/
/** List of pointer to svutListener class. **/
typedef std::list<svutListener *> svutListenerPtrList;

/********************* CLASS ************************/
/**
 * This class base on svutEvent may be used to manage multi event dispatching. It handle multiple
 * svutEvent objets and tranmit event to each of them in the same order they'll be added.
 * @brief Dispatch event to multiple sub svutEvent instances.
 * @author Sébastien Valat
**/
class svutListenerMultiplexer : public svutListener
{
	public:
		virtual void onGlobalStart(void);
		virtual void onTestCaseStart(const svutTestCase & testCase);
		virtual void onTestCaseEnd(const svutTestCase & testCase);
		virtual void onTestMethodStart(const svUnitTest::svutTestCase & testCase,const svutTestMethod & method);
		virtual void onTestMethodEnd(const svUnitTest::svutTestCase & testCase,const svutTestMethod & method,svutStatusInfo status);
		virtual void onGlobalEnd(void);
		virtual void onListingStart(void );
		virtual void onListMethod(const svUnitTest::svutTestCase& testCase, const svUnitTest::svutTestMethod& method);
		virtual void onListingEnd(void );
		void addListener(svutListener * listener);
		void removeListener(svutListener * listener);
		unsigned int countListener(void) const;
	private:
		/** Define the list of listener on which to dipatch events. **/
		svutListenerPtrList listeners;
		
};

}

#endif
