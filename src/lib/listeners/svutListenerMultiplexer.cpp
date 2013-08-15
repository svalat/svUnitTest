/*****************************************************
             PROJECT  : svUnitTest
             VERSION  : 0.5.0-dev
             DATE     : 11/2012
             AUTHOR   : Valat Sébastien
             LICENSE  : CeCILL-C 2.1
*****************************************************/

/********************  HEADERS  *********************/
#include "svutListenerMultiplexer.h"
#include "svutException.h"

/**********************  USING  *********************/
using namespace std;

/********************  NAMESPACE  *******************/
namespace svUnitTest
{

/*******************  FUNCTION  *********************/
void svutListenerMultiplexer::onGlobalStart(void )
{
	for (svutListenerPtrList::iterator it = listeners.begin() ; it != listeners.end() ; ++it)
		(*it)->onGlobalStart();
}

/*******************  FUNCTION  *********************/
void svutListenerMultiplexer::onGlobalEnd(void )
{
	for (svutListenerPtrList::iterator it = listeners.begin() ; it != listeners.end() ; ++it)
		(*it)->onGlobalEnd();
}

/*******************  FUNCTION  *********************/
void svutListenerMultiplexer::onTestCaseEnd(const svUnitTest::svutTestCase& testCase)
{
	for (svutListenerPtrList::iterator it = listeners.begin() ; it != listeners.end() ; ++it)
		(*it)->onTestCaseEnd(testCase);
}

/*******************  FUNCTION  *********************/
void svutListenerMultiplexer::onTestCaseStart(const svUnitTest::svutTestCase& testCase)
{
	for (svutListenerPtrList::iterator it = listeners.begin() ; it != listeners.end() ; ++it)
		(*it)->onTestCaseStart(testCase);
}

/*******************  FUNCTION  *********************/
void svutListenerMultiplexer::onTestMethodEnd(const svUnitTest::svutTestCase & testCase,const svutTestMethod & method, svutStatusInfo status)
{
	for (svutListenerPtrList::iterator it = listeners.begin() ; it != listeners.end() ; ++it)
		(*it)->onTestMethodEnd(testCase,method,status);
}

/*******************  FUNCTION  *********************/
void svutListenerMultiplexer::onTestMethodStart(const svUnitTest::svutTestCase & testCase,const svutTestMethod & method)
{
	for (svutListenerPtrList::iterator it = listeners.begin() ; it != listeners.end() ; ++it)
		(*it)->onTestMethodStart(testCase,method);
}

/*******************  FUNCTION  *********************/
void svutListenerMultiplexer::onListingStart(void )
{
	for (svutListenerPtrList::iterator it = listeners.begin() ; it != listeners.end() ; ++it)
		(*it)->onListingStart();
}

/*******************  FUNCTION  *********************/
void svutListenerMultiplexer::onListMethod(const svUnitTest::svutTestCase& testCase, const svUnitTest::svutTestMethod& method)
{
	for (svutListenerPtrList::iterator it = listeners.begin() ; it != listeners.end() ; ++it)
		(*it)->onListMethod(testCase,method);
}

/*******************  FUNCTION  *********************/
void svutListenerMultiplexer::onListingEnd(void )
{
	for (svutListenerPtrList::iterator it = listeners.begin() ; it != listeners.end() ; ++it)
		(*it)->onListingEnd();
}

/*******************  FUNCTION  *********************/
/**
 * Add a sub listener for event dispatching.
 * @param listener Define the listener to add. It's your own responsability to free this memory at
 * exit time.
**/
void svutListenerMultiplexer::addListener(svutListener* listener)
{
	listeners.push_back(listener);
}

/*******************  FUNCTION  *********************/
/**
 * Remove a listener for event dispatching.
 * @param listener Define the listener to remove.
**/
void svutListenerMultiplexer::removeListener(svutListener* listener)
{
	for (svutListenerPtrList::iterator it = listeners.begin() ; it != listeners.end() ; ++it)
		if (*it == listener)
		{
			listeners.remove(listener);
			return;
		}
	throw svutExInternalError("Can't find the requested listener for removale.");
	
}

/*******************  FUNCTION  *********************/
/**
 * @return Return the number of sub listener contained in the multiplexer.
**/
unsigned int svutListenerMultiplexer::countListener(void ) const
{
	return (unsigned int)listeners.size();
}

}
