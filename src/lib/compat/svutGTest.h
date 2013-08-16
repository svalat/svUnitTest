/*****************************************************
             PROJECT  : svUnitTest
             VERSION  : 0.5.0-dev
             DATE     : 08/2013
             AUTHOR   : Valat Sébastien
             LICENSE  : CeCILL-C 2.1
*****************************************************/

#ifndef SVUT_GTEST_HEADER
#define SVUT_GTEST_HEADER

/*********************** DOC*************************/
/**
 * @file svutGTest.h This file provide a wrapper to emulate the gtest interface. This way it is possible to
 * compile tests written for gtest onto svUnitTest without rewriting the test.
 * CAUTION, this support is currenly experimental and of not complete by supporting only basic features.
**/

/********************  HEADERS  *********************/
#include "svUnitTest.h"

/********************  MACRO  ***********************/
//assert
#define ASSERT_TRUE(condition) SVUT_ASSERT_TRUE(condition)
#define ASSERT_FALSE(condition) SVUT_ASSERT_FALSE(condition)
//expect
#define EXPECT_TRUE(condition) SVUT_ASSERT_TRUE(condition)
#define EXPECT_FALSE(condition) SVUT_ASSERT_FALSE(condition)

/********************  MACRO  ***********************/
//assert
#define ASSERT_EQ(expected,actual) SVUT_ASSERT_EQUAL(expected,actual)
#define ASSERT_NE(expected,actual) SVUT_ASSERT_NOT_EQUAL(expected,actual)
#define ASSERT_LT(val1,val2)       SVUT_ASSERT_LT(val2,val1)
#define ASSERT_LE(val1,val2)       SVUT_ASSERT_LE(val2,val1)
#define ASSERT_GT(val1,val2)       SVUT_ASSERT_GT(val2,val1)
#define ASSERT_GE(val1,val2)       SVUT_ASSERT_GE(val2,val1)
//expect
#define EXPECT_EQ(expected,actual) SVUT_ASSERT_EQUAL(expected,actual)
#define EXPECT_NE(expected,actual) SVUT_ASSERT_NOT_EQUAL(expected,actual)
#define EXPECT_LT(val1,val2)       SVUT_ASSERT_LT(val2,val1)
#define EXPECT_LE(val1,val2)       SVUT_ASSERT_LE(val2,val1)
#define EXPECT_GT(val1,val2)       SVUT_ASSERT_GT(val2,val1)
#define EXPECT_GE(val1,val2)       SVUT_ASSERT_GE(val2,val1)

/********************  MACRO  ***********************/
//assert
#define ASSERT_STREQ(expected_str, actual_str) SVUT_ASSERT_EQUAL(expected_str, actual_str)
#define ASSERT_STRNE(expected_str, actual_str) SVUT_ASSERT_NOT_EQUAL(expected_str, actual_str)
//expect
#define EXPECT_STREQ(expected_str, actual_str) SVUT_ASSERT_EQUAL(expected_str, actual_str)
#define EXPECT_STRNE(expected_str, actual_str) SVUT_ASSERT_NOT_EQUAL(expected_str, actual_str)

/********************  MACRO  ***********************/
//manual fail
#define FAIL()                    SVUT_ASSERT_FAIL("Failure")
#define ADD_FAILURE()             SVUT_ASSERT_FAIL("Failure")
#define ADD_FAILURE_AT(file,line) SVUT_ASSERT_FAIL("Failure") 

/********************  MACRO  ***********************/
//exception handling
#define ASSERT_THROW(statement,exception_type) SVUT_ASSERT_THROW(exception_type,statement)
#define ASSERT_ANY_THROW(statement)            SVUT_ASSERT_THROW_SOMETHING(statement)
#define ASSERT_NO_THROW(statement)             SVUT_ASSERT_MAY_NOT_THROW(statement)
//expect
#define EXPECT_THROW(statement,exception_type) SVUT_ASSERT_THROW(exception_type,statement)
#define EXPECT_ANY_THROW(statement)            SVUT_ASSERT_THROW_SOMETHING(statement)
#define EXPECT_NO_THROW(statement)             SVUT_ASSERT_MAY_NOT_THROW(statement)

/********************  MACRO  ***********************/
//assert
#define ASSERT_FLOAT_EQ(expected, actual)      SVUT_ASSERT_EQUAL((float)expected,(float)actual)
#define ASSERT_DOUBLE_EQ(expected, actual)      SVUT_ASSERT_EQUAL((double)expected,(double)actual)
//expect
#define EXPECT_FLOAT_EQ(expected, actual)      SVUT_ASSERT_EQUAL((float)expected,(float)actual)
#define EXPECT_DOUBLE_EQ(expected, actual)      SVUT_ASSERT_EQUAL((double)expected,(double)actual)

/********************  MACRO  ***********************/
#define ASSERT_DEATH_IF_SUPPORTED(statement, regex) do{} while(0)
#define EXPECT_DEATH_IF_SUPPORTED(statement, regex) do{} while(0)

/********************  MACRO  ***********************/
//test declaration
#define TEST(testCaseName,testName) SVUT_DECLARE_FLAT_TEST(testCaseName,testName)
#define TEST_F(testCaseName,testName) SVUT_DECLARE_FLAT_TEST_F(testCaseName,testName)

/********************  MACRO  ***********************/
//Need work for support


/********************  NAMESPACE  *******************/
namespace svUnitTest
{
	class Test : public svUnitTest::svutFlatFixture
	{
		public:
			virtual void SetUp(void)    {};
			virtual void TearDown(void) {};
			virtual void setUp(void)    {this->SetUp();}
			virtual void tearDown(void) {this->TearDown();};
	};
}

/********************  NAMESPACE  *******************/
namespace testing = ::svUnitTest;

/********************  MACRO  ***********************/
SVUT_USE_DEFAULT_MAIN

#endif //SVUT_GTEST_HEADER
