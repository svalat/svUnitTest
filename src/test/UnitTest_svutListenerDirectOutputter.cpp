/*****************************************************
             PROJECT  : svUnitTest
             VERSION  : 0.1.0
             DATE     : 01/2011
             AUTHOR   : Valat Sébastien
             LICENSE  : CeCILL-C
*****************************************************/

/********************  HEADERS  *********************/
#include "UnitTestExtra.h"
#include <iostream>
#include <cppunit/TestCase.h>
#include <cppunit/extensions/TestFactoryRegistry.h>
#include <cppunit/extensions/HelperMacros.h>
#include <svutListenerDirectOutputter.h>
#include "UnitTestMockResultFormatter.h"
#include "UnitTestMockTestCase.h"

/**********************  USING  *********************/
using namespace svUnitTest;
using namespace CPPUNIT_NS;

/*********************  CLASS  **********************/
class UnitTest_svutListenerDirectOutputter : public TestCase
{
	CPPUNIT_TEST_SUITE(UnitTest_svutListenerDirectOutputter);
	CPPUNIT_TEST(testOnGlobalStart);
	CPPUNIT_TEST(testOnTestCaseStart);
	CPPUNIT_TEST(testOnTestCaseEnd);
	CPPUNIT_TEST(testOnTestMethodStart);
	CPPUNIT_TEST(testOnTestMethodEnd);
	CPPUNIT_TEST(testOnGlobalEnd_1);
	CPPUNIT_TEST(testOnGlobalEnd_2);
	CPPUNIT_TEST_SUITE_END();

	public:
		void setUp(void);
		void tearDown(void);

	protected:
		void testOnGlobalStart(void);
		void testOnTestCaseStart(void);
		void testOnTestCaseEnd(void);
		void testOnTestMethodStart();
		void testOnTestMethodEnd(void);
		void testOnGlobalEnd_1(void);
		void testOnGlobalEnd_2(void);

		svutListenerDirectOutputter * listener;
		UnitTestMockResultFormater * formatter;
		UnitTestMockResultFormater * ref;
};

/*******************  FUNCTION  *********************/
void UnitTest_svutListenerDirectOutputter::setUp(void)
{
	this->formatter = new UnitTestMockResultFormater();
	this->listener = new svutListenerDirectOutputter(*this->formatter);
	this->ref = new UnitTestMockResultFormater();
}

/*******************  FUNCTION  *********************/
void UnitTest_svutListenerDirectOutputter::tearDown(void)
{
	delete listener;
	delete ref;
	delete formatter;
}

/*******************  FUNCTION  *********************/
void UnitTest_svutListenerDirectOutputter::testOnGlobalStart(void )
{
	CPPUNIT_ASSERT_EQUAL(true,formatter->isEmpty());

	listener->onGlobalStart();
	ref->openOutput();
	
	CPPUNIT_ASSERT_EQUAL(false,formatter->isEmpty());
	CPPUNIT_ASSERT_EQUAL(*ref,*formatter);
}

/*******************  FUNCTION  *********************/
void UnitTest_svutListenerDirectOutputter::testOnGlobalEnd_1(void )
{
	svutResultSummary summary;
	
	CPPUNIT_ASSERT_EQUAL(true,formatter->isEmpty());

	listener->onGlobalEnd();
	
	ref->printSummary(summary);
	ref->closeOutput();

	CPPUNIT_ASSERT_EQUAL(false,formatter->isEmpty());
	CPPUNIT_ASSERT_EQUAL(*ref,*formatter);
}

/*******************  FUNCTION  *********************/
void UnitTest_svutListenerDirectOutputter::testOnGlobalEnd_2(void )
{
	svutResultSummary summary;
	summary.set(SVUT_STATUS_SUCCESS,1);
	summary.set(SVUT_STATUS_UNKNOWN,2);
	
	CPPUNIT_ASSERT_EQUAL(true,formatter->isEmpty());

	UnitTestMockTestCase testCase;
	svutTestMethod testMethod("test",NULL,SVUT_CODE_LOCATION);
	listener->onTestMethodEnd(testCase,testMethod,SVUT_STATUS_SUCCESS);
	listener->onTestMethodEnd(testCase,testMethod,SVUT_STATUS_UNKNOWN);
	listener->onTestMethodEnd(testCase,testMethod,SVUT_STATUS_UNKNOWN);
	listener->onGlobalEnd();

	ref->closeTestMethod(testCase,testMethod,SVUT_STATUS_SUCCESS);
	ref->closeTestMethod(testCase,testMethod,SVUT_STATUS_UNKNOWN);
	ref->closeTestMethod(testCase,testMethod,SVUT_STATUS_UNKNOWN);
	ref->printSummary(summary);
	ref->closeOutput();

	CPPUNIT_ASSERT_EQUAL(false,formatter->isEmpty());
	CPPUNIT_ASSERT_EQUAL(*ref,*formatter);
}

/*******************  FUNCTION  *********************/
void UnitTest_svutListenerDirectOutputter::testOnTestCaseStart(void )
{
	CPPUNIT_ASSERT_EQUAL(true,formatter->isEmpty());

	UnitTestMockTestCase testCase;
	listener->onTestCaseStart(testCase);
	ref->openTestCase(testCase);

	CPPUNIT_ASSERT_EQUAL(false,formatter->isEmpty());
	CPPUNIT_ASSERT_EQUAL(*ref,*formatter);
}

/*******************  FUNCTION  *********************/
void UnitTest_svutListenerDirectOutputter::testOnTestCaseEnd(void )
{
	CPPUNIT_ASSERT_EQUAL(true,formatter->isEmpty());

	UnitTestMockTestCase testCase;
	listener->onTestCaseEnd(testCase);
	ref->closeTestCase(testCase);

	CPPUNIT_ASSERT_EQUAL(false,formatter->isEmpty());
	CPPUNIT_ASSERT_EQUAL(*ref,*formatter);
}

/*******************  FUNCTION  *********************/
void UnitTest_svutListenerDirectOutputter::testOnTestMethodStart()
{
	CPPUNIT_ASSERT_EQUAL(true,formatter->isEmpty());

	UnitTestMockTestCase testCase;
	svutTestMethod testMethod("test",NULL,SVUT_CODE_LOCATION);
	listener->onTestMethodStart(testCase,testMethod);
	ref->openTestMethod(testCase,testMethod);

	CPPUNIT_ASSERT_EQUAL(false,formatter->isEmpty());
	CPPUNIT_ASSERT_EQUAL(*ref,*formatter);
}

/*******************  FUNCTION  *********************/
void UnitTest_svutListenerDirectOutputter::testOnTestMethodEnd(void )
{
	CPPUNIT_ASSERT_EQUAL(true,formatter->isEmpty());

	UnitTestMockTestCase testCase;
	svutTestMethod testMethod("test",NULL,SVUT_CODE_LOCATION);
	listener->onTestMethodEnd(testCase,testMethod,SVUT_STATUS_TODO);
	ref->closeTestMethod(testCase,testMethod,SVUT_STATUS_TODO);

	CPPUNIT_ASSERT_EQUAL(false,formatter->isEmpty());
	CPPUNIT_ASSERT_EQUAL(*ref,*formatter);
}

CPPUNIT_TEST_SUITE_REGISTRATION(UnitTest_svutListenerDirectOutputter);
