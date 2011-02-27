/*****************************************************
             PROJECT  : svUnitTest
             VERSION  : 0.2.0
             DATE     : 02/2011
             AUTHOR   : Valat Sébastien
             LICENSE  : CeCILL-C
*****************************************************/

/********************  HEADERS  *********************/
#include "UnitTestExtra.h"
#include <iostream>
#include <cppunit/TestCase.h>
#include <cppunit/extensions/TestFactoryRegistry.h>
#include <cppunit/extensions/HelperMacros.h>
#include <svutResultSummary.h>

/**********************  USING  *********************/
using namespace svUnitTest;
using namespace CPPUNIT_NS;

/*********************  CLASS  **********************/
class UnitTest_svutResultSummary : public TestCase
{
	CPPUNIT_TEST_SUITE(UnitTest_svutResultSummary);
	CPPUNIT_TEST(testConstructor);
	CPPUNIT_TEST(testGetTotal);
	CPPUNIT_TEST(testGetCount);
	CPPUNIT_TEST(testGetPercentage);
	CPPUNIT_TEST(testIncrement);
	CPPUNIT_TEST(testSet);
	CPPUNIT_TEST(testReset);
	CPPUNIT_TEST(testGetStatus);
	CPPUNIT_TEST_SUITE_END();

	public:
		void setUp(void);
		void tearDown(void);

		void testConstructor(void);
		void testGetTotal(void);
		void testGetCount(void);
		void testGetPercentage(void);
		void testIncrement(void);
		void testSet(void);
		void testReset(void);
		void testGetStatus(void);

	protected:
		svutResultSummary * summary;
		const svutResultSummary * cstSummary;
};

/*******************  FUNCTION  *********************/
void UnitTest_svutResultSummary::setUp(void)
{
	this->summary = new svutResultSummary;
	this->summary->set(SVUT_STATUS_FAILED,5);
	this->summary->set(SVUT_STATUS_SUCCESS,4);
	this->summary->set(SVUT_STATUS_TODO,1);
	this->summary->set(SVUT_STATUS_INDEV,2);
	this->summary->set(SVUT_STATUS_UNKNOWN,0);
	this->summary->set(SVUT_STATUS_SKIPED,3);
	this->cstSummary = this->summary;
}

/*******************  FUNCTION  *********************/
void UnitTest_svutResultSummary::tearDown(void)
{
	delete this->summary;
}


/*******************  FUNCTION  *********************/
void UnitTest_svutResultSummary::testConstructor(void )
{
	const svutResultSummary obj;
	CPPUNIT_ASSERT_EQUAL(0,obj.getCount(SVUT_STATUS_FAILED));
	CPPUNIT_ASSERT_EQUAL(0,obj.getCount(SVUT_STATUS_SUCCESS));
	CPPUNIT_ASSERT_EQUAL(0,obj.getCount(SVUT_STATUS_TODO));
	CPPUNIT_ASSERT_EQUAL(0,obj.getCount(SVUT_STATUS_INDEV));
	CPPUNIT_ASSERT_EQUAL(0,obj.getCount(SVUT_STATUS_UNKNOWN));
	CPPUNIT_ASSERT_EQUAL(0,obj.getCount(SVUT_STATUS_SKIPED));
}

/*******************  FUNCTION  *********************/
void UnitTest_svutResultSummary::testGetTotal(void )
{
	CPPUNIT_ASSERT_EQUAL(15,cstSummary->getTotal());
}

/*******************  FUNCTION  *********************/
void UnitTest_svutResultSummary::testGetCount(void )
{
	CPPUNIT_ASSERT_EQUAL(5,cstSummary->getCount(SVUT_STATUS_FAILED));
	CPPUNIT_ASSERT_EQUAL(4,cstSummary->getCount(SVUT_STATUS_SUCCESS));
	CPPUNIT_ASSERT_EQUAL(1,cstSummary->getCount(SVUT_STATUS_TODO));
	CPPUNIT_ASSERT_EQUAL(2,cstSummary->getCount(SVUT_STATUS_INDEV));
	CPPUNIT_ASSERT_EQUAL(0,cstSummary->getCount(SVUT_STATUS_UNKNOWN));
	CPPUNIT_ASSERT_EQUAL(3,cstSummary->getCount(SVUT_STATUS_SKIPED));
}

/*******************  FUNCTION  *********************/
void UnitTest_svutResultSummary::testGetPercentage(void )
{
	CPPUNIT_ASSERT_EQUAL(33,cstSummary->getPercentage(SVUT_STATUS_FAILED));
	CPPUNIT_ASSERT_EQUAL(26,cstSummary->getPercentage(SVUT_STATUS_SUCCESS));
	CPPUNIT_ASSERT_EQUAL(6,cstSummary->getPercentage(SVUT_STATUS_TODO));
	CPPUNIT_ASSERT_EQUAL(13,cstSummary->getPercentage(SVUT_STATUS_INDEV));
	CPPUNIT_ASSERT_EQUAL(0,cstSummary->getPercentage(SVUT_STATUS_UNKNOWN));
	CPPUNIT_ASSERT_EQUAL(20,cstSummary->getPercentage(SVUT_STATUS_SKIPED));
}

/*******************  FUNCTION  *********************/
void UnitTest_svutResultSummary::testGetStatus(void )
{
	CPPUNIT_ASSERT_EQUAL(SVUT_STATUS_FAILED,cstSummary->getStatus());
	summary->set(SVUT_STATUS_FAILED,0);
	CPPUNIT_ASSERT_EQUAL(SVUT_STATUS_TODO,cstSummary->getStatus());
	summary->set(SVUT_STATUS_TODO,0);
	CPPUNIT_ASSERT_EQUAL(SVUT_STATUS_INDEV,cstSummary->getStatus());
	summary->set(SVUT_STATUS_INDEV,0);
	CPPUNIT_ASSERT_EQUAL(SVUT_STATUS_SUCCESS,cstSummary->getStatus());
}

/*******************  FUNCTION  *********************/
void UnitTest_svutResultSummary::testIncrement(void )
{
	//success
	CPPUNIT_ASSERT_EQUAL(4,cstSummary->getCount(SVUT_STATUS_SUCCESS));
	summary->increment(SVUT_STATUS_SUCCESS,2);
	CPPUNIT_ASSERT_EQUAL(6,cstSummary->getCount(SVUT_STATUS_SUCCESS));
	//failed
	CPPUNIT_ASSERT_EQUAL(5,cstSummary->getCount(SVUT_STATUS_FAILED));
	summary->increment(SVUT_STATUS_FAILED,2);
	CPPUNIT_ASSERT_EQUAL(7,cstSummary->getCount(SVUT_STATUS_FAILED));
	//todo
	CPPUNIT_ASSERT_EQUAL(1,cstSummary->getCount(SVUT_STATUS_TODO));
	summary->increment(SVUT_STATUS_TODO,2);
	CPPUNIT_ASSERT_EQUAL(3,cstSummary->getCount(SVUT_STATUS_TODO));
	//indev
	CPPUNIT_ASSERT_EQUAL(2,cstSummary->getCount(SVUT_STATUS_INDEV));
	summary->increment(SVUT_STATUS_INDEV,2);
	CPPUNIT_ASSERT_EQUAL(4,cstSummary->getCount(SVUT_STATUS_INDEV));
	//unknown
	CPPUNIT_ASSERT_EQUAL(0,cstSummary->getCount(SVUT_STATUS_UNKNOWN));
	summary->increment(SVUT_STATUS_UNKNOWN,2);
	CPPUNIT_ASSERT_EQUAL(2,cstSummary->getCount(SVUT_STATUS_UNKNOWN));
	//skiped
	CPPUNIT_ASSERT_EQUAL(3,cstSummary->getCount(SVUT_STATUS_SKIPED));
	summary->increment(SVUT_STATUS_SKIPED,2);
	CPPUNIT_ASSERT_EQUAL(5,cstSummary->getCount(SVUT_STATUS_SKIPED));

	//default arg
	CPPUNIT_ASSERT_EQUAL(6,cstSummary->getCount(SVUT_STATUS_SUCCESS));
	summary->increment(SVUT_STATUS_SUCCESS);
	CPPUNIT_ASSERT_EQUAL(7,cstSummary->getCount(SVUT_STATUS_SUCCESS));
}

/*******************  FUNCTION  *********************/
void UnitTest_svutResultSummary::testReset(void )
{
	CPPUNIT_ASSERT_EQUAL(5,cstSummary->getCount(SVUT_STATUS_FAILED));
	CPPUNIT_ASSERT_EQUAL(4,cstSummary->getCount(SVUT_STATUS_SUCCESS));
	CPPUNIT_ASSERT_EQUAL(1,cstSummary->getCount(SVUT_STATUS_TODO));
	CPPUNIT_ASSERT_EQUAL(2,cstSummary->getCount(SVUT_STATUS_INDEV));
	CPPUNIT_ASSERT_EQUAL(0,cstSummary->getCount(SVUT_STATUS_UNKNOWN));
	CPPUNIT_ASSERT_EQUAL(3,cstSummary->getCount(SVUT_STATUS_SKIPED));
	
	summary->reset();

	CPPUNIT_ASSERT_EQUAL(0,cstSummary->getCount(SVUT_STATUS_FAILED));
	CPPUNIT_ASSERT_EQUAL(0,cstSummary->getCount(SVUT_STATUS_SUCCESS));
	CPPUNIT_ASSERT_EQUAL(0,cstSummary->getCount(SVUT_STATUS_TODO));
	CPPUNIT_ASSERT_EQUAL(0,cstSummary->getCount(SVUT_STATUS_INDEV));
	CPPUNIT_ASSERT_EQUAL(0,cstSummary->getCount(SVUT_STATUS_UNKNOWN));
	CPPUNIT_ASSERT_EQUAL(0,cstSummary->getCount(SVUT_STATUS_SKIPED));
}

/*******************  FUNCTION  *********************/
void UnitTest_svutResultSummary::testSet(void )
{
	CPPUNIT_ASSERT_EQUAL(5,cstSummary->getCount(SVUT_STATUS_FAILED));
	CPPUNIT_ASSERT_EQUAL(4,cstSummary->getCount(SVUT_STATUS_SUCCESS));
	CPPUNIT_ASSERT_EQUAL(1,cstSummary->getCount(SVUT_STATUS_TODO));
	CPPUNIT_ASSERT_EQUAL(2,cstSummary->getCount(SVUT_STATUS_INDEV));
	CPPUNIT_ASSERT_EQUAL(0,cstSummary->getCount(SVUT_STATUS_UNKNOWN));
	CPPUNIT_ASSERT_EQUAL(3,cstSummary->getCount(SVUT_STATUS_SKIPED));

	CPPUNIT_ASSERT_EQUAL(11,summary->set(SVUT_STATUS_FAILED,11));
	CPPUNIT_ASSERT_EQUAL(12,summary->set(SVUT_STATUS_SUCCESS,12));
	CPPUNIT_ASSERT_EQUAL(13,summary->set(SVUT_STATUS_TODO,13));
	CPPUNIT_ASSERT_EQUAL(14,summary->set(SVUT_STATUS_INDEV,14));
	CPPUNIT_ASSERT_EQUAL(15,summary->set(SVUT_STATUS_UNKNOWN,15));
	CPPUNIT_ASSERT_EQUAL(16,summary->set(SVUT_STATUS_SKIPED,16));

	CPPUNIT_ASSERT_EQUAL(11,cstSummary->getCount(SVUT_STATUS_FAILED));
	CPPUNIT_ASSERT_EQUAL(12,cstSummary->getCount(SVUT_STATUS_SUCCESS));
	CPPUNIT_ASSERT_EQUAL(13,cstSummary->getCount(SVUT_STATUS_TODO));
	CPPUNIT_ASSERT_EQUAL(14,cstSummary->getCount(SVUT_STATUS_INDEV));
	CPPUNIT_ASSERT_EQUAL(15,cstSummary->getCount(SVUT_STATUS_UNKNOWN));
	CPPUNIT_ASSERT_EQUAL(16,cstSummary->getCount(SVUT_STATUS_SKIPED));
}

CPPUNIT_TEST_SUITE_REGISTRATION(UnitTest_svutResultSummary);
