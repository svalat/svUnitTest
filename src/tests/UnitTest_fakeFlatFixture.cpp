/*****************************************************
             PROJECT  : svUnitTest
             VERSION  : 0.5.0-dev
             DATE     : 11/2012
             AUTHOR   : Valat Sébastien
             LICENSE  : CeCILL-C 2.1
*****************************************************/

/********************  HEADERS  *********************/
#include "../resources/svUnitTest_fake/include/svUnitTest/svUnitTest.h"

/**********************  USING  *********************/
using namespace svUnitTest;

/********************  GLOBALS  *********************/
class MyFixture : public svutFlatFixture
{
	public:
		MyFixture();
		virtual void setUp(void);
		virtual void tearDown(void);
		int value;
};

/*******************  FUNCTION  *********************/
MyFixture::MyFixture()
{
	value = 0;
}

/*******************  FUNCTION  *********************/
void MyFixture::setUp(void )
{
	SVUT_ASSERT_EQUAL(0,value);
	value = 10;
}

/*******************  FUNCTION  *********************/
void MyFixture::tearDown(void )
{
	SVUT_ASSERT_EQUAL(10,value);
	value = 0;
}

/*******************  FUNCTION  *********************/
SVUT_DECLARE_FLAT_TEST_F(MyFixture,testMethod1)
{
	SVUT_ASSERT_EQUAL(10,value);
}

SVUT_USE_DEFAULT_MAIN
