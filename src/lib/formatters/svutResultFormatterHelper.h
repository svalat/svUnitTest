/*****************************************************
             PROJECT  : svUnitTest
             VERSION  : 0.4.0
             DATE     : 11/2012
             AUTHOR   : Valat Sébastien
             LICENSE  : CeCILL-C
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
