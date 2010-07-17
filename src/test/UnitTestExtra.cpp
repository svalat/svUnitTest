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
		std::string exp = assertion_traits<const char *>::toString(expected);
		Asserter::failNotEqual( exp, actual,sourceLine,message );
	}
}

/********************  METHOD  **********************/
void assertEquals( const std::string & expected,const char * actual,CppUnit::SourceLine sourceLine,const std::string &message )
{
	if ( actual!=expected) // lazy toString conversion...
	{
		std::string act = assertion_traits<const char *>::toString(actual);
		Asserter::failNotEqual( expected,act,sourceLine,message );
	}
}

/********************  METHOD  **********************/
void assertEquals( int expected,unsigned int actual,SourceLine sourceLine,const std::string &message )
{
	if ( (unsigned int)expected!=actual) // lazy toString conversion...
	{
		std::string act = assertion_traits<unsigned int>::toString(actual);
		std::string exp = assertion_traits<int>::toString(expected);
		Asserter::failNotEqual( exp,act,sourceLine,message );
	}
}

}

