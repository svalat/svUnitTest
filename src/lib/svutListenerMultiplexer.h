/*****************************************************
             PROJECT  : svUnitTest
             VERSION  : 0.0.2
             DATE     : 07/2010
             AUTHOR   : Valat Sébastien
             LICENSE  : CeCILL-C
*****************************************************/

#ifndef SVUT_LISTENER_MULTIPLEXER_HEADER
#define SVUT_LISTENER_MULTIPLEXER_HEADER

/********************  HEADERS  *********************/
#include <list>
#include "svutListener.h"

namespace svUnitTest
{

/********************* CLASS ************************/
/**
 * This class base on svutEvent may be used to manage multi event dispatching. It handle multiple
 * svutEvent objets and tranmit event to each of them in the same order they'll be added.
 * @brief Dispatch event to multiple sub svutEvent instances.
 * @author Sébastien Valat
 * @version 0.0.2
**/
class svutListenerMultiplexer : public svutListener
{
	public:
		virtual void onGlobalStart(void);
		virtual void onTestCaseStart(const svutTestCase & testCase);
		virtual void onTestCaseEnd(const svutTestCase & testCase);
		virtual void onTestMethodStart(const svutTestMethod & method);
		virtual void onTestMethodEnd(const svutTestMethod & method,svutStatusInfo status);
		virtual void onGlobalEnd(void);
		void addListener(svutListener * listener);
		void removeListener(svutListener * listener);
		unsigned int countListener(void) const;
	private:
		std::list<svutListener *> listeners;
		
};

}

#endif
