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
#define SVUT_NOT_SUPPORTED_MACRO(x) throw svUnitTest::svutExAssertFake("FAILED","Macro not supported : " #x,SVUT_CODE_LOCATION)

/********************  MACRO  ***********************/
#define SVUT_CODE_LOCATION getLocationString(__LINE__,__FILE__,__FUNCTION__)

/********************  MACRO  ***********************/
#define SVUT_CAPTURE_ASSERT_EXCEPTIONS(x) \
	try{\
		x;\
	} catch (svutExAssertFake & e) {\
		setErrorMessage(e);\
	} catch (...) {\
		svUnitTest::svutExAssertFake e("UNKNOWN","Unknown exception thrown",SVUT_CODE_LOCATION);\
		setErrorMessage(e);\
	}

/********************  MACRO  ***********************/
#define SVUT_ASSERT_TRUE(value) \
	if (((bool)(value)) ==  false) throw svUnitTest::svutExAssertFake("FAILED",("Assert fail : " #value " == true"),SVUT_CODE_LOCATION)

/********************  MACRO  ***********************/
#define SVUT_ASSERT_FALSE(value) \
	if (((bool)(value)) ==  true) throw svUnitTest::svutExAssertFake("FAILED",("Assert fail : " #value " == false"),SVUT_CODE_LOCATION)

/********************  MACRO  ***********************/
#define SVUT_ASSERT_NULL(value) SVUT_NOT_SUPPORTED_MACRO(SVUT_ASSERT_NULL)
// 	if (((void*)(value)) != NULL) \
// 		throw svUnitTest::svutExAssertFailNullPointer(true,SVUT_CODE_LOCATION)


/********************  MACRO  ***********************/
#define SVUT_ASSERT_NOT_NULL(value) SVUT_NOT_SUPPORTED_MACRO(SVUT_ASSERT_NOT_NULL)
// 	if (((void*)(value)) == NULL) \
// 		throw svUnitTest::svutExAssertFailNullPointer(false,SVUT_CODE_LOCATION)

/********************  MACRO  ***********************/
#define SVUT_ASSERT_EQUAL(expected,actual) SVUT_NOT_SUPPORTED_MACRO(SVUT_ASSERT_EQUAL)
// 	svUnitTest::assertEqual((expected),(actual),SVUT_CODE_LOCATION)

/********************  MACRO  ***********************/
#define SVUT_ASSERT_NOT_EQUAL(expected,actual)  SVUT_NOT_SUPPORTED_MACRO(SVUT_ASSERT_NOT_EQUAL)
// 	svUnitTest::assertNotEqual((expected),(actual),SVUT_CODE_LOCATION)

/********************  MACRO  ***********************/
#define SVUT_ASSERT_EQUAL_STRICT(expected,actual)  SVUT_NOT_SUPPORTED_MACRO(SVUT_ASSERT_EQUAL_STRICT)
// 	assertEqualStrict((expected),(actual),SVUT_CODE_LOCATION)

/********************  MACRO  ***********************/
#define SVUT_ASSERT_NOT_EQUAL_STRICT(expected,actual)  SVUT_NOT_SUPPORTED_MACRO(SVUT_ASSERT_NOT_EQUAL_STRICT)
// 	assertNotEqualStrict((expected),(actual),SVUT_CODE_LOCATION)

/********************  MACRO  ***********************/
#define SVUT_ASSERT_SAME(expected,actual)  SVUT_NOT_SUPPORTED_MACRO(SVUT_ASSERT_SAME)
// 	assertSame((expected),(actual),SVUT_CODE_LOCATION)

/********************  MACRO  ***********************/
#define SVUT_ASSERT_NOT_SAME(expected,actual)  SVUT_NOT_SUPPORTED_MACRO(SVUT_ASSERT_NOT_SAME)
// 	assertNotSame((expected),(actual),SVUT_CODE_LOCATION)

/********************  MACRO  ***********************/
#define SVUT_ASSERT_FAIL(message) \
	throw svUnitTest::svutExAssertFake("FAILED",message,SVUT_CODE_LOCATION)

/********************  MACRO  ***********************/
#define SVUT_ASSERT_TODO(message)  SVUT_NOT_SUPPORTED_MACRO(SVUT_ASSERT_TODO)
// 	throw svUnitTest::svutExNotifyTodo((message),SVUT_CODE_LOCATION)

/********************  MACRO  ***********************/
#define SVUT_ASSERT_INDEV(message)  SVUT_NOT_SUPPORTED_MACRO(SVUT_ASSERT_INDEV)
// 	throw svUnitTest::svutExNotifyIndev((message),SVUT_CODE_LOCATION)

/********************  MACRO  ***********************/
#define SVUT_ASSERT_NOT_EXEC_THIS()  SVUT_NOT_SUPPORTED_MACRO(SVUT_ASSERT_NOT_EXEC_THIS)
// 	throw svUnitTest::svutExAssertFailNotExec(SVUT_CODE_LOCATION)

/********************  MACRO  ***********************/
#define SVUT_ASSERT_THROW(name,what)  SVUT_NOT_SUPPORTED_MACRO(SVUT_ASSERT_THROW)
// 	try {\
// 		what;\
// 		throw svUnitTest::svutExAssertFailThrow(#name,"NONE",SVUT_CODE_LOCATION);\
// 	} catch(name) {\
// 	}  catch(svUnitTest::svutExAssertFailThrow & e) { \
// 		throw e; \
// 	} catch(...) {\
// 		throw svUnitTest::svutExAssertFailThrow(#name,"UNKNOWN",SVUT_CODE_LOCATION);\
// 	}

/********************  MACRO  ***********************/
#define SVUT_ASSERT_THROW_SOMETHING(what)  SVUT_NOT_SUPPORTED_MACRO(SVUT_ASSERT_THROW_SOMETHING)
// 	try {\
// 		what;\
// 		throw svUnitTest::svutExAssertFailThrow("...","NONE",SVUT_CODE_LOCATION);\
// 	}  catch(svUnitTest::svutExAssertFailThrow & e) { \
// 		throw e; \
// 	} catch(...) {\
// 	}

/********************  MACRO  ***********************/
#define SVUT_ASSERT_NOT_THROW(name,what)  SVUT_NOT_SUPPORTED_MACRO(SVUT_ASSERT_NOT_THROW)
// 	try {\
// 		what;\
// 	} catch(name) {\
// 		throw svUnitTest::svutExAssertFailThrow("NONE",#name,SVUT_CODE_LOCATION);\
// 	} catch(...) {\
// 	}

/********************  MACRO  ***********************/
#define SVUT_ASSERT_MAY_NOT_THROW(what)  SVUT_NOT_SUPPORTED_MACRO(SVUT_ASSERT_MAY_NOT_THROW)
// 	try {\
// 		what;\
// 	} catch(...) {\
// 		throw svUnitTest::svutExAssertFailThrow("NONE","...",SVUT_CODE_LOCATION);\
// 	}

}

#endif
