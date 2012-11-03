/*****************************************************
             PROJECT  : svUnitTest
             VERSION  : 0.5.0-dev
             DATE     : 11/2012
             AUTHOR   : Valat Sébastien
             LICENSE  : CeCILL-C
*****************************************************/

/********************  HEADERS  *********************/
#include "UnitTestExtra.h"
#include <svutCodeLocation.h>
#include <sstream>

/**********************  USING  *********************/
using namespace CPPUNIT_NS;
using namespace svUnitTest;
using namespace std;

/*********************  CLASS  **********************/
class UnitTest_svutCodeLocation : public TestCase
{
	CPPUNIT_TEST_SUITE(UnitTest_svutCodeLocation);
	CPPUNIT_TEST(testConstruct);
	CPPUNIT_TEST(testConstruct_str_str_int);
	CPPUNIT_TEST(testGetFilename);
	CPPUNIT_TEST(testGetMethodeName);
	CPPUNIT_TEST(testHasLocation);
	CPPUNIT_TEST(testGetLine);
	CPPUNIT_TEST(testMacroSVUT_CODE_LOCATION);
	CPPUNIT_TEST(testConstSVUT_NO_LOCATION);
	CPPUNIT_TEST(testOperatorOstream);
	CPPUNIT_TEST(testOperatorOstream_nolocation);
	CPPUNIT_TEST(testOperatorEqualEqual);
	CPPUNIT_TEST_SUITE_END();

	public:
		void setUp(void);
		void tearDown(void);

	protected:
		void testConstruct(void);
		void testConstruct_str_str_int(void);
		void testGetFilename(void);
		void testGetMethodeName(void);
		void testHasLocation(void);
		void testGetLine(void);
		void testMacroSVUT_CODE_LOCATION(void);
		void testConstSVUT_NO_LOCATION(void);
		void testOperatorOstream(void);
		void testOperatorOstream_nolocation(void);
		void testOperatorEqualEqual(void);
		
		const svutCodeLocation * location;
};

/*******************  FUNCTION  *********************/
void UnitTest_svutCodeLocation::setUp(void)
{
	location = new svutCodeLocation("main.cpp","main",42);
}

/*******************  FUNCTION  *********************/
void UnitTest_svutCodeLocation::tearDown(void)
{
	delete location;
}

/*******************  FUNCTION  *********************/
void UnitTest_svutCodeLocation::testConstruct(void)
{
	const svutCodeLocation loc;
	CPPUNIT_ASSERT_EQUAL("unknown",loc.getFilename());
	CPPUNIT_ASSERT_EQUAL("unknown",loc.getMethodeName());
	CPPUNIT_ASSERT_EQUAL(-1,loc.getLine());
	CPPUNIT_ASSERT_EQUAL(false,loc.hasLocation());
}

/*******************  FUNCTION  *********************/
void UnitTest_svutCodeLocation::testConstruct_str_str_int(void)
{
	const svutCodeLocation loc("main.cpp","main",42);
	CPPUNIT_ASSERT_EQUAL("main.cpp",loc.getFilename());
	CPPUNIT_ASSERT_EQUAL("main",loc.getMethodeName());
	CPPUNIT_ASSERT_EQUAL(42,loc.getLine());
	CPPUNIT_ASSERT_EQUAL(true,loc.hasLocation());
}

/*******************  FUNCTION  *********************/
void UnitTest_svutCodeLocation::testGetFilename(void)
{
	CPPUNIT_ASSERT_EQUAL("main.cpp",location->getFilename());
}

/*******************  FUNCTION  *********************/
void UnitTest_svutCodeLocation::testGetMethodeName(void)
{
	CPPUNIT_ASSERT_EQUAL("main",location->getMethodeName());
}

/*******************  FUNCTION  *********************/
void UnitTest_svutCodeLocation::testHasLocation(void)
{
	CPPUNIT_ASSERT_EQUAL(true,location->hasLocation());
}

/*******************  FUNCTION  *********************/
void UnitTest_svutCodeLocation::testGetLine(void)
{
	CPPUNIT_ASSERT_EQUAL(42,location->getLine());
}

/*******************  FUNCTION  *********************/
void UnitTest_svutCodeLocation::testMacroSVUT_CODE_LOCATION(void)
{
	svutCodeLocation loc = SVUT_CODE_LOCATION;int line = __LINE__;
	CPPUNIT_ASSERT_EQUAL(__FILE__,loc.getFilename());
	CPPUNIT_ASSERT_EQUAL("testMacroSVUT_CODE_LOCATION",loc.getMethodeName());
	CPPUNIT_ASSERT_EQUAL(line,loc.getLine());
	CPPUNIT_ASSERT_EQUAL(true,loc.hasLocation());
}

/*******************  FUNCTION  *********************/
void UnitTest_svutCodeLocation::testConstSVUT_NO_LOCATION(void)
{
	svutCodeLocation loc = SVUT_NO_LOCATION;
	CPPUNIT_ASSERT_EQUAL("unknown",loc.getFilename());
	CPPUNIT_ASSERT_EQUAL("unknown",loc.getMethodeName());
	CPPUNIT_ASSERT_EQUAL(-1,loc.getLine());
	CPPUNIT_ASSERT_EQUAL(false,loc.hasLocation());
}

/*******************  FUNCTION  *********************/
void UnitTest_svutCodeLocation::testOperatorOstream(void)
{
	stringstream str;
	str << *location;
	CPPUNIT_ASSERT_EQUAL("line 42 of file main.cpp on methode main()",str.str());
}

/*******************  FUNCTION  *********************/
void UnitTest_svutCodeLocation::testOperatorOstream_nolocation(void)
{
	stringstream str;
	str << SVUT_NO_LOCATION;
	CPPUNIT_ASSERT_EQUAL("unknown location",str.str());
}

/*******************  FUNCTION  *********************/
void UnitTest_svutCodeLocation::testOperatorEqualEqual(void)
{
	const svutCodeLocation loc1("main.cpp","main",42);
	const svutCodeLocation loc2("main.cpp","main",42);
	const svutCodeLocation loc3("main2.cpp","main",42);
	const svutCodeLocation loc4("main.cpp","main2",42);
	const svutCodeLocation loc5("main.cpp","main",43);
	CPPUNIT_ASSERT_EQUAL(loc1,loc2);
	CPPUNIT_ASSERT(!(loc1==loc3));
	CPPUNIT_ASSERT(!(loc1==loc4));
	CPPUNIT_ASSERT(!(loc1==loc5));
}

CPPUNIT_TEST_SUITE_REGISTRATION(UnitTest_svutCodeLocation);
