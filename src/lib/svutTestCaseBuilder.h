/*****************************************************
             PROJECT  : svUnitTest
             VERSION  : 0.0.2
             DATE     : 12/2010
             AUTHOR   : Valat Sébastien
             LICENSE  : CeCILL-C
*****************************************************/

#ifndef SVUT_TEST_CASE_BUILDER_HEADER
#define SVUT_TEST_CASE_BUILDER_HEADER

/********************  HEADERS  *********************/
namespace svUnitTest
{

/********************  CLASSE  **********************/
#ifndef svutTestCase
class svutTestCase;
#endif

/********************  CLASSE  **********************/
/**
 * Base class which permit to describe the requirement for a test case builder. By this way,
 * we can inherit from this base class to build a generic allocation mechanisms base on templates.
 * This permit to avoid a construction of the tests directly at load time. The test register a builder
 * at load time, and when needed, the builder will be call to create the requied test case object.
 * @brief Asbtract constructor of test cases.
 * @author Valat Sébastien
 * @version 0.0.2
**/
class svutTestCaseBuilder
{
	public:
		/** Class constructor responsible of the registration. **/
		svutTestCaseBuilder(void){};
		/** Class destructor responsible of the unregistration. **/
		virtual ~svutTestCaseBuilder(void){};
		/**
		 * Methode used to build the test case. Caution, this is your own responsability to free
		 * the builded test case at the end.
		**/
		virtual svutTestCase * build(void) const = 0;
};

/********************  CLASSE  **********************/
/**
 * Generic version of svutTestCaseBuilder base on template. It will be called at load time to
 * and registred into svutAutoRegister.
 * @brief Generic version of svutTestCaseBuilder.
 * @author Valat Sébastien
 * @version 0.0.2
**/
template <class T>
class svutTestCaseBuilderGeneric : public svutTestCaseBuilder
{
	public:
		svutTestCaseBuilderGeneric(void) {};
		virtual svutTestCase * build(void) const
			{return new T();};
};

}

#endif // SVUT_TEST_CASE_BUILDER_HEADER
