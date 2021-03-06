/*****************************************************
             PROJECT  : svUnitTest
             VERSION  : 0.5.0-dev
             DATE     : 11/2012
             AUTHOR   : Valat Sébastien
             LICENSE  : CeCILL-C 2.1
*****************************************************/

#ifndef UNIT_TEST_EXTRA_HEADER
#define UNIT_TEST_EXTRA_HEADER

/********************  HEADERS  *********************/
#include <cppunit/extensions/HelperMacros.h>
#include <stdexcept>
#include <string.h>

/*******************  NAMESPACE  ********************/
namespace CPPUNIT_NS
{

#ifndef FAKE_CPP_UNIT
void assertEquals( const char * expected,const std::string & actual,CppUnit::SourceLine sourceLine,const std::string &message );
void assertEquals( const std::string & expected,const char * actual,CppUnit::SourceLine sourceLine,const std::string &message );
void assertEquals( int expected,unsigned int actual,SourceLine sourceLine,const std::string &message );
#endif

}

#endif
