/*****************************************************
             PROJECT  : svUnitTest
             VERSION  : 0.0.2
             DATE     : 06/2010
             AUTHOR   : Valat Sébastien
             LICENSE  : CeCILL-C
*****************************************************/

/********************  HEADERS  *********************/
#include "UnitTestExtra.h"

namespace CppUnit
{

/********************  METHOD  **********************/
void assertEquals( const char * expected,const std::string & actual,CppUnit::SourceLine sourceLine,const std::string &message )
{
	if ( actual!=expected) // lazy toString conversion...
	{
		Asserter::failNotEqual( assertion_traits<const char *>::toString(expected),
								actual,
										sourceLine,
		  message );
	}
}

/********************  METHOD  **********************/
void assertEquals( const std::string & expected,const char * actual,CppUnit::SourceLine sourceLine,const std::string &message )
{
	if ( actual!=expected) // lazy toString conversion...
	{
		Asserter::failNotEqual( expected,
								 assertion_traits<const char *>::toString(actual),
										sourceLine,
		  message );
	}
}

/********************  METHOD  **********************/
void assertEquals( int expected,unsigned int actual,SourceLine sourceLine,const std::string &message )
{
	if ( (unsigned int)expected!=actual) // lazy toString conversion...
	{
		Asserter::failNotEqual( assertion_traits<int>::toString(expected),
		                        assertion_traits<unsigned int>::toString(actual),
		                        sourceLine,
		                        message );
	}
}

};

