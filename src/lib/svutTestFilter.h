/*****************************************************
             PROJECT  : svUnitTest
             VERSION  : 0.0.2
             DATE     : 12/2010
             AUTHOR   : Valat Sébastien
             LICENSE  : CeCILL-C
*****************************************************/

#ifndef SVUT_TEST_FILTER_HEADER
#define SVUT_TEST_FILTER_HEADER

/********************  HEADERS  *********************/
#include <string>

namespace svUnitTest
{

/********************  CLASSE  **********************/
/**
 * Class used as a bases for the definition of filter to execute only the wanted tests.
 * This provide an abstraction of test filtering to simply provide multiple way to select the tests.
 * @brief Abstract class to define the bases of test filteing.
 * @author Valat Sébastien.
 * @version 0.0.2.
**/
class svutTestFilter {
	public:
		svutTestFilter(void) {};
		virtual ~svutTestFilter(void) {};
		/**
		 * Method used to check if the given test must be executed of not.
		 * @param caseName Define the name of the related test case.
		 * @param methode Define the name of the method to run.
		 * @return Return true if the function must be executed or not.
		**/
		virtual bool accept(std::string caseName,std::string methode) const=0;
		/**
		 * Method to test if a particular test case must be executed or complextely ignored.
		 * @param caseName Define the name of the related test case.
		 * @return Return true if the test case must be executed or not.
		**/
		virtual bool accept(std::string caseName) const=0;
};

}

#endif // SVUT_TEST_FILTER_HEADER
