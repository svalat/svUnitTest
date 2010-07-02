/*****************************************************
             PROJECT  : svUnitTest
             VERSION  : 0.0.2
             DATE     : 06/2010
             AUTHOR   : Valat Sébastien
             LICENSE  : CeCILL-C
*****************************************************/

#ifndef UNIT_TEST_EXTRA_HEADER
#define UNIT_TEST_EXTRA_HEADER

/********************  HEADERS  *********************/
#include <cppunit/extensions/HelperMacros.h>
#include <stdexcept>
#include <string.h>

namespace CppUnit
{

void assertEquals( const char * expected,const std::string & actual,CppUnit::SourceLine sourceLine,const std::string &message );
void assertEquals( int expected,unsigned int actual,SourceLine sourceLine,const std::string &message );

};

#endif
