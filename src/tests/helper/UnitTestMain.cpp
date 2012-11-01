/*****************************************************
             PROJECT  : svUnitTest
             VERSION  : 0.4.0
             DATE     : 11/2012
             AUTHOR   : Valat Sébastien
             LICENSE  : CeCILL-C
*****************************************************/

/********************  HEADERS  *********************/
#include <cppunit/TextTestRunner.h>
#include <cppunit/TestResult.h>
#include <cppunit/TestResultCollector.h>
#include <cppunit/extensions/HelperMacros.h>
#include <cppunit/BriefTestProgressListener.h>
// #include <cppunit/TextOutputter.h>
// #include <cppunit/XmlOutputter.h>
#include <cppunit/CompilerOutputter.h>

/**********************  USING  *********************/
using namespace CppUnit;

/*******************  FUNCTION  *********************/
int main(int /*argc*/, char* /*argv*/[])
{
	// Get the top level suite from the registry
	Test *suite = CppUnit::TestFactoryRegistry::getRegistry().makeTest();

	// Adds the test to the list of test to run
	TextTestRunner runner;
	runner.addTest( suite );
	

	// Change the default outputter to a compiler error format outputter
	runner.setOutputter( new CompilerOutputter ( &runner.result(),std::cerr ));

	//seup biref progress mode
	BriefTestProgressListener progress;
	runner.eventManager().addListener( &progress );

	// Run the tests.
	bool wasSucessful = runner.run();

	// Return error code 1 if the one of test failed.
	return wasSucessful ? 0 : 1;
}

