/*****************************************************
             PROJECT  : svUnitTest
             VERSION  : 0.0.2
             DATE     : 07/2010
             AUTHOR   : Valat Sébastien
             LICENSE  : CeCILL-C
*****************************************************/

/********************  HEADERS  *********************/
#include "svutListenerMultiplexer.h"
#include "svutException.h"

using namespace std;
namespace svUnitTest
{

/********************  METHODE  *********************/
void svutListenerMultiplexer::onGlobalStart(void )
{
	for (list<svutListener*>::iterator it = listeners.begin() ; it != listeners.end() ; ++it)
		(*it)->onGlobalStart();
}

/********************  METHODE  *********************/
void svutListenerMultiplexer::onGlobalEnd(void )
{
	for (list<svutListener*>::iterator it = listeners.begin() ; it != listeners.end() ; ++it)
		(*it)->onGlobalEnd();
}

/********************  METHODE  *********************/
void svutListenerMultiplexer::onTestCaseEnd(const svUnitTest::svutTestCase& testCase)
{
	for (list<svutListener*>::iterator it = listeners.begin() ; it != listeners.end() ; ++it)
		(*it)->onTestCaseEnd(testCase);
}

/********************  METHODE  *********************/
void svutListenerMultiplexer::onTestCaseStart(const svUnitTest::svutTestCase& testCase)
{
	for (list<svutListener*>::iterator it = listeners.begin() ; it != listeners.end() ; ++it)
		(*it)->onTestCaseStart(testCase);
}

/********************  METHODE  *********************/
void svutListenerMultiplexer::onTestMethodEnd(const svutTestMethod & method, svutStatusInfo status)
{
	for (list<svutListener*>::iterator it = listeners.begin() ; it != listeners.end() ; ++it)
		(*it)->onTestMethodEnd(method,status);
}

/********************  METHODE  *********************/
void svutListenerMultiplexer::onTestMethodStart(const svutTestMethod & method)
{
	for (list<svutListener*>::iterator it = listeners.begin() ; it != listeners.end() ; ++it)
		(*it)->onTestMethodStart(method);
}

/********************  METHODE  *********************/
/**
 * Add a sub listener for event dispatching.
 * @param listener Define the listener to add. It's your own responsability to free this memory at
 * exit time.
**/
void svutListenerMultiplexer::addListener(svutListener* listener)
{
	listeners.push_back(listener);
}

/********************  METHODE  *********************/
/**
 * Remove a listener for event dispatching.
 * @param listener Define the listener to remove.
**/
void svutListenerMultiplexer::removeListener(svutListener* listener)
{
	for (list<svutListener*>::iterator it = listeners.begin() ; it != listeners.end() ; ++it)
		if (*it == listener)
		{
			listeners.remove(listener);
			return;
		}
	throw svutExInternalError("Can't find the requested listener for removale.");
	
}

/********************  METHODE  *********************/
/**
 * @return Return the number of sub listener contained in the multiplexer.
**/
unsigned int svutListenerMultiplexer::countListener(void ) const
{
	return listeners.size();
}

}