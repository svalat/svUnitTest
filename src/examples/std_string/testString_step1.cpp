//needed to build a new test case.
#include <svUnitTest/svutTestCase.h>
#include <svUnitTest/svutDefaultMain.h>

using namespace svUnitTest;

class testString : public svutTestCase
{
    public:
       testString(void);
       virtual void setUp(void);
       virtual void tearDown(void);
   protected:
       void testSize(void);
       void testClear(void);
       void testOperatorPlus(void);
};

//Now register the test case and generate the default main function
SVUT_REGISTER_STANDELONE(testString);


testString::testString(void)
           :svutTestCase("testString")
{
     SVUT_REG_TEST_METHOD(testString,testSize);
     SVUT_REG_TEST_METHOD(testString,testClear);
     SVUT_REG_TEST_METHOD(testString,testOperatorPlus);
};

void testString::setUp(void)    {};
void testString::tearDown(void) {};

void testString::testSize(void)            { SVUT_ASSERT_TODO("Need implementation");};
void testString::testClear(void)           { SVUT_ASSERT_TODO("Need implementation");};
void testString::testOperatorPlus(void   ) { SVUT_ASSERT_TODO("Need implementation");};

