/*****************************************************
             PROJECT  : svUnitTest
             VERSION  : 0.5.0-dev
             DATE     : 11/2012
             AUTHOR   : Valat Sébastien
             LICENSE  : CeCILL-C
*****************************************************/

/********************  HEADERS  *********************/
#include "UnitTestMockResultFormatter.h"
#include <svutTestCase.h>
#include <cstdio>

/**********************  USING  *********************/
using namespace svUnitTest;
using namespace std;

/*******************  FUNCTION  *********************/
void UnitTestMockResultFormater::openOutput(void )
{
	event.push_back("openOutput()");
}

/*******************  FUNCTION  *********************/
void UnitTestMockResultFormater::closeOutput(void )
{
	event.push_back("closeOutput()");
}

/*******************  FUNCTION  *********************/
void UnitTestMockResultFormater::closeTestCase(const svUnitTest::svutTestCase& testCase)
{
	char buffer[1024];
	sprintf(buffer,"closeTestCase(%s)",testCase.getName().c_str());
	event.push_back(buffer);
}

/*******************  FUNCTION  *********************/
void UnitTestMockResultFormater::closeTestMethod(const svUnitTest::svutTestCase& testCase, const svUnitTest::svutTestMethod& meth, const svUnitTest::svutStatusInfo& status)
{
	char buffer[1024];
	sprintf(buffer,"closeTestMethod(%s, %s, %s)",testCase.getName().c_str(),meth.getName().c_str(),status.getStatusName().c_str());
	event.push_back(buffer);
}

/*******************  FUNCTION  *********************/
bool UnitTestMockResultFormater::isEmpty(void ) const
{
	return event.empty();
}

/*******************  FUNCTION  *********************/
void UnitTestMockResultFormater::openTestCase(const svUnitTest::svutTestCase& testCase)
{
	char buffer[1024];
	sprintf(buffer,"openTestCase(%s)",testCase.getName().c_str());
	event.push_back(buffer);
}

/*******************  FUNCTION  *********************/
void UnitTestMockResultFormater::openTestMethod(const svUnitTest::svutTestCase& testCase, const svUnitTest::svutTestMethod& meth)
{
	char buffer[1024];
	sprintf(buffer,"openTestMethod(%s, %s)",testCase.getName().c_str(),meth.getName().c_str());
	event.push_back(buffer);
}

/*******************  FUNCTION  *********************/
void UnitTestMockResultFormater::onListingStart(void )
{
	event.push_back("onListingStart()");
}

/*******************  FUNCTION  *********************/
void UnitTestMockResultFormater::onListingEnd(void )
{
	event.push_back("onListingEnd()");
}

/*******************  FUNCTION  *********************/
void UnitTestMockResultFormater::onListMethod(const svUnitTest::svutTestCase& testCase, const svUnitTest::svutTestMethod& method)
{
	char buffer[1024];
	sprintf(buffer,"onListMethod(%s, %s)",testCase.getName().c_str(),method.getName().c_str());
	event.push_back(buffer);
}

/*******************  FUNCTION  *********************/
bool operator!=(const UnitTestMockResultFormater& formater1, const UnitTestMockResultFormater& formater2)
{
	if (formater1.event.size() != formater2.event.size())
		return true;

	std::list<std::string>::const_iterator it1 = formater1.event.begin();
	std::list<std::string>::const_iterator it2 = formater2.event.begin();
	while (it1 != formater1.event.end())
	{
		if (*it1 != *it2)
			return true;
		++it1;
		++it2;
	}

	return false;
}

/*******************  FUNCTION  *********************/
bool operator==(const UnitTestMockResultFormater& formater1, const UnitTestMockResultFormater& formater2)
{
	if (formater1.event.size() != formater2.event.size())
		return false;

	std::list<std::string>::const_iterator it1 = formater1.event.begin();
	std::list<std::string>::const_iterator it2 = formater2.event.begin();
	while (it1 != formater1.event.end())
	{
		if (*it1 != *it2)
			return false;
		++it1;
		++it2;
	}

	return true;
}

/*******************  FUNCTION  *********************/
std::ostream& operator<<(std::ostream& out, const UnitTestMockResultFormater& formater)
{
	for (std::list<std::string>::const_iterator it = formater.event.begin() ; it != formater.event.end() ; ++it)
		out << *it << "; ";
	return out;
}

/*******************  FUNCTION  *********************/
void UnitTestMockResultFormater::reset(void )
{
	event.clear();
}

/*******************  FUNCTION  *********************/
void UnitTestMockResultFormater::printSummary(svUnitTest::svutResultSummary summary)
{
	char buffer[4096];
	sprintf(buffer,"success=%d, failed=%d, todo=%d, indev=%d, unknown=%d, skiped=%d",
			summary.getCount(SVUT_STATUS_SUCCESS),summary.getCount(SVUT_STATUS_FAILED),
			summary.getCount(SVUT_STATUS_TODO),summary.getCount(SVUT_STATUS_INDEV),
			summary.getCount(SVUT_STATUS_UNKNOWN),summary.getCount(SVUT_STATUS_SKIPED));
	event.push_back(buffer);
}

/*******************  FUNCTION  *********************/
bool operator == (const std::string & str,const UnitTestMockResultFormater & formater)
{
	stringstream stream;
	stream << formater;
	return str == stream.str();
}

/*******************  FUNCTION  *********************/
bool operator != (const std::string & str,const UnitTestMockResultFormater & formater)
{
	stringstream stream;
	stream << formater;
	return str != stream.str();
}
