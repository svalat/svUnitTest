/*****************************************************
             PROJECT  : svUnitTest
             VERSION  : 0.0.2
             DATE     : 06/2010
             AUTHOR   : Valat Sébastien
             LICENSE  : CeCILL-C
*****************************************************/

/********************  HEADERS  *********************/
#include <cppunit/TextTestRunner.h>
#include <cppunit/TestResult.h>
#include <cppunit/TestResultCollector.h>
#include <cppunit/extensions/HelperMacros.h>
#include <cppunit/BriefTestProgressListener.h>
#include <cppunit/TextOutputter.h>
#include <cppunit/TextOutputter.h>

/********************  METHODE  *********************/
int main( int ac, char **av )
{
	//Create the event manager and test controller
	CppUnit::TestResult controller;

	//Add a listener that colllects test result
	CppUnit::TestResultCollector result;
	controller.addListener( &result );        

	//Add a listener that print dots as test run.
	CppUnit::BriefTestProgressListener progress;
	controller.addListener( &progress );      

	//Add the top suite to the test runner
	CppUnit::TextTestRunner runner(new CppUnit::TextOutputter ( &runner.result(),std::cerr ) );
	runner.addTest( CppUnit::TestFactoryRegistry::getRegistry().makeTest() );
	runner.run( controller );

	return result.wasSuccessful() ? 0 : 1;
}
