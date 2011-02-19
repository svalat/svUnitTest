/*****************************************************
             PROJECT  : svUnitTest
             VERSION  : 0.1.0
             DATE     : 02/2011
             AUTHOR   : Valat Sébastien
             LICENSE  : CeCILL-C
*****************************************************/

#ifndef FAKE_CPP_UNIT_HEADER
#define FAKE_CPP_UNIT_HEADER

/********************  HEADERS  *********************/
#include <cassert>
#include <vector>
#include <iostream>

/********************  NAMESPACE  *******************/
namespace CPPUNIT_NS
{

/********************  MACRO  ***********************/
#define CPPUNIT_ASSERT(x) assert(x)
#define CPPUNIT_ASSERT_EQUAL(x,y) assert( (x) == (y) )
#define CPPUNIT_FAIL(x) std::cerr << x << std::endl; assert(false);
#define CPPUNIT_TEST_SUITE(x) void runTests(void) {
#define CPPUNIT_TEST_SUITE_END() }
#define CPPUNIT_TEST(x) markStartTest(#x); setUp(); x(); tearDown(); markAsPassed()
#define CPPUNIT_TEST_SUITE_REGISTRATION(name)\
	static CPPUNIT_NS::TestCaseBuilderGeneric<name> ___FAKE_CPPUNIT_case_##name##___;\
	static int ___FAKE_CPPUNIT_res_case_registration_of##name##__ = CPPUNIT_NS::fakeCppUnitRegisterTestCase(___FAKE_CPPUNIT_case_##name##___)
#define FAKE_CPP_UNIT

/*********************  CLASS  **********************/
class TestCase
{
	public:
		virtual ~TestCase(void) {};
		void run() {this->runTests();};
	protected:
		void markAsPassed(void) const;
		void markStartTest(const char * name) const;
		virtual void runTests(void) = 0;
		virtual void setUp(void) = 0;
		virtual void tearDown(void) = 0;
};

/*********************  CLASS  **********************/
class TestCaseBuilder
{
	public:
		virtual ~TestCaseBuilder(void);
		virtual TestCase * build(void) = 0;
};

/*********************  CLASS  **********************/
template <class T>
class TestCaseBuilderGeneric : public TestCaseBuilder
{
	public:
		virtual TestCase * build(void) { return new T();};
};

/*******************  FUNCTION **********************/
int fakeCppUnitRegisterTestCase(CPPUNIT_NS::TestCaseBuilder & builder);

}

#endif
