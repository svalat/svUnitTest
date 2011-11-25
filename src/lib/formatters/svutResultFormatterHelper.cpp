/*****************************************************
             PROJECT  : svUnitTest
             VERSION  : 0.3.0
             DATE     : 05/2011
             AUTHOR   : Valat Sébastien
             LICENSE  : CeCILL-C
*****************************************************/

/********************  HEADERS  *********************/
#include "svutResultFormatterHelper.h"

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
	
};
