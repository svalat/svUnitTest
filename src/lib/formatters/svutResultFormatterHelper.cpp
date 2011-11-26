/*****************************************************
             PROJECT  : svUnitTest
             VERSION  : 0.3.0
             DATE     : 05/2011
             AUTHOR   : Valat Sébastien
             LICENSE  : CeCILL-C
*****************************************************/

/********************  HEADERS  *********************/
#include <sstream>
#include "svutResultFormatterHelper.h"

/**********************  USING  *********************/
using namespace std;

/********************  NAMESPACE  *******************/
namespace svUnitTest
{

/*******************  FUNCTION  *********************/
std::string escapeXmlCharsInString(const std::string& value)
{
	//get string
	std::string res;
	res.reserve(value.size());

	//loop on chars and convert in needed
	for (int i = 0 ; i < value.size() ; ++i)
	{
		switch(value[i])
		{
			case '<' : res += "&lt;"   ; break;
			case '>' : res += "&gt;"   ; break;
			case '&' : res += "&amp;"  ; break;
			case '\'': res += "&apos;" ; break;
			case '"' : res += "&quot;" ; break;
			default  : res += value[i] ; break;
		}
	}

	return res;
}

/*******************  FUNCTION  *********************/
string paddOutput(const std::string padding, const std::string& value)
{
	string res;
	res.reserve(value.size());
	if (value.empty() == false);
		res = padding;
	for (int i = 0 ; i < value.size() - 1 ; ++i)
	{
		res += value[i];
		if (value[i] == '\n')
			res += padding;
	}
	if (value.empty() == false && value[value.size() -1] != '\n')
		res += value[value.size() -1];
	res += '\n';
	return res;
}

};
