/*****************************************************
             PROJECT  : svUnitTest
             VERSION  : 0.0.2
             DATE     : 12/2010
             AUTHOR   : Valat Sébastien
             LICENSE  : CeCILL-C
*****************************************************/

/********************  HEADERS  *********************/
#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include <iostream>
#include "svutTestFilterBasic.h"

using namespace std;
namespace svUnitTest
{

/********************  METHODE  *********************/
/**
 * Default constructor of the class.
**/
svutTestFilterBasic::svutTestFilterBasic(void)
{
}

/********************  METHODE  *********************/
bool svutTestFilterBasic::accept(std::string caseName,std::string methode) const
{
	//trivial
	if (filters.empty())
		return true;
	//filter
	for (list<svutTestFilterBasicRule>::const_iterator it=filters.begin();it!=filters.end();++it)
	{
		if ((it->caseName.empty() || it->caseName == caseName) && (it->methode.empty() || it->methode == methode))
			return true;
	}
	return false;
}

/********************  METHODE  *********************/
bool svutTestFilterBasic::accept(std::string caseName) const
{
	//trivial
	if (filters.empty())
		return true;
	//filter
	for (list<svutTestFilterBasicRule>::const_iterator it=filters.begin();it!=filters.end();++it)
	{
		if ((it->caseName.empty() || it->caseName == caseName))
			return true;
	}
	return false;
}

/********************  METHODE  *********************/
/**
 * Add a rule to accept a specific method. Caution, you cant let the caseName AND methodName
 * empty. On such error, the method simply return.
 * @param caseName Define the name of the test case to accept. If empty, all test cases will
 * be accepted.
 * @param methode Define the name of the method to accept. If empty, all methods of the test case
 * will be accepted.
**/
void svutTestFilterBasic::addAccepted(std::string caseName,std::string methodName)
{
	//error
	if (caseName.empty() && methodName.empty())
		return;
	//ok
	svutTestFilterBasicRule entry = {caseName,methodName};
	filters.push_back(entry);
}

/********************  METHODE  *********************/
/**
 * Clear all the rules into the filter. So the filter will accept all requests.
**/
void svutTestFilterBasic::clear(void )
{
	filters.clear();
}

}
