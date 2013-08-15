/*****************************************************
             PROJECT  : svUnitTest
             VERSION  : 0.5.0-dev
             DATE     : 11/2012
             AUTHOR   : Valat Sébastien
             LICENSE  : CeCILL-C 2.1
*****************************************************/

#ifndef SVUTRESULTFORMATTERHELPER_H
#define SVUTRESULTFORMATTERHELPER_H

/********************  HEADERS  *********************/
#include <string>

/********************  NAMESPACE  *******************/
namespace svUnitTest
{

/*******************  FUNCTION  *********************/
std::string escapeXmlCharsInString(const std::string & value);
std::string paddOutput(const std::string & padding,const std::string & value);

}

#endif // SVUTRESULTFORMATTERHELPER_H
