/*****************************************************
             PROJECT  : svUnitTest
             VERSION  : 0.3.0-dev
             DATE     : 03/2011
             AUTHOR   : Valat Sébastien
             LICENSE  : CeCILL-C
*****************************************************/

#ifndef FAKE_SVUT_ASSERT_HEADER
#define FAKE_SVUT_ASSERT_HEADER

/********************  HEADERS  *********************/
#include <string>
#include <sstream>

/********************  NAMESPACE  *******************/
namespace svUnitTest
{

/********************  STRUCT  **********************/
struct svutExAssertFake
{
	svutExAssertFake(const char * status,const char * message,std::string location)
	{
		this->status = status;
		this->message = message;
		this->location = location;
	}
	svutExAssertFake(void) {};
	std::string status;
	std::string message;
	std::string location;
};

/*******************  FUNCTION  *********************/
inline std::string getLocationString(int line,const char * filename,const char * function)
{
	std::stringstream res;
	res << "line " << line << " of file " << filename << " on methode " << function << "()";
	return res.str();
}

/********************  MACRO  ***********************/
#define SVUT_CODE_LOCATION getLocationString(__LINE__,__FILE__,__FUNCTION__)

/********************  MACRO  ***********************/
#define SVUT_CAPTURE_ASSERT_EXCEPTIONS(x) try{x;} catch (svutExAssertFake & e) {setErrorMessage(e);}

/********************  MACRO  ***********************/
#define SVUT_ASSERT_TRUE(value) \
	if (((bool)(value)) ==  false) throw svUnitTest::svutExAssertFake("FAILED",("Assert fail : " #value " == true"),SVUT_CODE_LOCATION)

}

#endif
