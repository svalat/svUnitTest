/*****************************************************
             PROJECT  : svUnitTest
             VERSION  : 0.0.2
             DATE     : 07/2010
             AUTHOR   : Valat Sébastien
             LICENSE  : CeCILL-C
*****************************************************/

/********************  HEADERS  *********************/
#include "UnitTestMockResultFormatter.h"
#include <cstdio>
#include <sstream>

using namespace std;

/********************  METHOD  **********************/
void UnitTestMockResultFormater::openOutput(void )
{
	event.push_back("openOutput()");
}

/********************  METHOD  **********************/
void UnitTestMockResultFormater::closeOutput(void )
{
	event.push_back("closeOutput()");
}

/********************  METHOD  **********************/
void UnitTestMockResultFormater::closeTestCase(const svUnitTest::svutTestCase& testCase)
{
	char buffer[1024];
	sprintf(buffer,"closeTestCase(%s)",testCase.getName().c_str());
	event.push_back(buffer);
}

/********************  METHOD  **********************/
void UnitTestMockResultFormater::closeTestMethod(const svUnitTest::svutTestCase& testCase, const svUnitTest::svutTestMethod& meth, const svUnitTest::svutStatusInfo& status)
{
	char buffer[1024];
	sprintf(buffer,"closeTestMethod(%s, %s, %s)",testCase.getName().c_str(),meth.getName().c_str(),status.getStatusName().c_str());
	event.push_back(buffer);
}

/********************  METHOD  **********************/
bool UnitTestMockResultFormater::isEmpty(void ) const
{
	return event.empty();
}

/********************  METHOD  **********************/
void UnitTestMockResultFormater::openTestCase(const svUnitTest::svutTestCase& testCase)
{
	char buffer[1024];
	sprintf(buffer,"openTestCase(%s)",testCase.getName().c_str());
	event.push_back(buffer);
}

/********************  METHOD  **********************/
void UnitTestMockResultFormater::openTestMethod(const svUnitTest::svutTestCase& testCase, const svUnitTest::svutTestMethod& meth)
{
	char buffer[1024];
	sprintf(buffer,"openTestMethod(%s, %s)",testCase.getName().c_str(),meth.getName().c_str());
	event.push_back(buffer);
}

/********************  METHOD  **********************/
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

/********************  METHOD  **********************/
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

/********************  METHOD  **********************/
std::ostream& operator<<(std::ostream& out, const UnitTestMockResultFormater& formater)
{
	for (std::list<std::string>::const_iterator it = formater.event.begin() ; it != formater.event.end() ; ++it)
		out << *it << "; ";
	return out;
}

/********************  METHOD  **********************/
void UnitTestMockResultFormater::reset(void )
{
	event.clear();
}

/********************  METHOD  **********************/
void UnitTestMockResultFormater::printSummary(svUnitTest::svutResultSummary summary)
{
	char buffer[4096];
	sprintf(buffer,"success=%d, failed=%d, todo=%d, indev=%d, unknown=%d, skiped=%d",
			summary.success,summary.failed,summary.todo,summary.indev,summary.unknown,
			summary.skiped);
	event.push_back(buffer);
}

/********************  METHOD  **********************/
bool operator == (const std::string & str,const UnitTestMockResultFormater & formater)
{
	stringstream stream;
	stream << formater;
	return str == stream.str();
}

/********************  METHOD  **********************/
bool operator != (const std::string & str,const UnitTestMockResultFormater & formater)
{
	stringstream stream;
	stream << formater;
	return str != stream.str();
}
