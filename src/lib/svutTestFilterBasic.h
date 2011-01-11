/*****************************************************
             PROJECT  : svUnitTest
             VERSION  : 0.0.2
             DATE     : 12/2010
             AUTHOR   : Valat Sébastien
             LICENSE  : CeCILL-C
*****************************************************/

#ifndef SVUT_TEST_FILTER_BASIC_HEADER
#define SVUT_TEST_FILTER_BASIC_HEADER

/********************  HEADERS  *********************/
#include <string>
#include <list>
#include "svutTestFilter.h"

namespace svUnitTest
{

/********************  STRUCT  **********************/
/**
 * Define the parameters needed fot the basic test filter. Here, we simply consider the aggregation
 * of a test case and a method name. We will consider a default accept filter. If the list is
 * empry, all request are acceped, if not, the entries must valid a filter rule to be valid.
 * @brief Decribe a filter rule for the basic test filter.
 * @author Valat Sébastien
 * @version 0.0.2
**/
struct svutTestFilterBasicRule
{
	/** Define the test case name. Use empty string for ALL. **/
	std::string caseName;
	/** Define the mathod name. Use empty string for ALL. **/
	std::string methode;
};

/********************  CLASSE  **********************/
/**
 * Implement a simple support for test case filtering. Here, we only execute tests which match
 * the rules. A rule, is simply a name of a test case and a name of a function. One can use wildcard
 * to say "all the test cases", or "all the methods".
 * @brief Basic class for test filtering.
 * @author Valat Sébastien.
 * @version 0.0.2.
**/
class svutTestFilterBasic : public svutTestFilter
{
	public:
		svutTestFilterBasic(void);
		virtual bool accept(std::string caseName,std::string methode) const;
		virtual bool accept(std::string caseName) const;
		void addAccepted(std::string caseName,std::string methode);
		void clear(void);
	protected:
		/** List of rules for accepted methods, if empty all are accepted. **/
		std::list<svutTestFilterBasicRule> filters;
};

}

#endif // SVUT_TEST_FILTER_BASIC_HEADER
