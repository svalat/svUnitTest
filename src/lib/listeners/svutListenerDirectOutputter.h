/*****************************************************
             PROJECT  : svUnitTest
             VERSION  : 0.5.0-dev
             DATE     : 11/2012
             AUTHOR   : Valat Sébastien
             LICENSE  : CeCILL-C
*****************************************************/

#ifndef SVUT_LISTENER_DIRECT_OUTPUTTER_H
#define SVUT_LISTENER_DIRECT_OUTPUTTER_H

/********************  HEADERS  *********************/
#include "svutListenerSummary.h"

/********************  NAMESPACE  *******************/
namespace svUnitTest
{

/********************* CLASS ************************/
class svutResultFormatter;

/********************* CLASS ************************/
/**
 * Listener used to control the output system. It redirect event directly to result outputter.
 * It may be used when using sequential an ordered run. This is the simpler link to output results.
 * It's based on svutListenerSummary to produce a summary and display it at the end.
 * @brief Listener to direcly send the events to output system.
 * @author Valat Sébastien
**/
class svutListenerDirectOutputter : public svutListenerSummary
{
	public:
		svutListenerDirectOutputter(svutResultFormatter & formatter);
		virtual void onGlobalStart(void);
		virtual void onTestCaseStart(const svutTestCase & testCase);
		virtual void onTestCaseEnd(const svutTestCase & testCase);
		virtual void onTestMethodStart(const svutTestCase & testCase,const svutTestMethod & method);
		virtual void onTestMethodEnd(const svutTestCase & testCase,const svutTestMethod & method,svutStatusInfo status);
		virtual void onGlobalEnd(void);
		virtual void onListingStart(void );
		virtual void onListMethod(const svUnitTest::svutTestCase& testCase, const svUnitTest::svutTestMethod& method);
		virtual void onListingEnd(void );
	protected:
		/** Store the pointer to the output formatter to use. **/
		svutResultFormatter * formatter;
};

}

#endif // SVUT_LISTENER_DIRECT_OUTPUTTER_H
