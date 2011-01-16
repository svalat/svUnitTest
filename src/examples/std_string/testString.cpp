//needed to build a new test case.
#include <svutTestCase.h>
#include <svutDefaultMain.h>

using namespace svUnitTest;

class testString : public svutTestCase
{
    public:
       testString(void);
       virtual void setUp(void);
       virtual void tearDown(void);
   protected:
       void testCount(void);
       void testReset(void);
       void testOperator_equal(void);
       void testOperator_plus(void);
       void testOperator_compare(void);
};

//Now register the test case and generate the default main function
SVUT_REGISTER_STANDELONE(testString);


testString::testString(void)
           :svutTestCase("testString")
{
     SVUT_REG_TEST_METHOD(testString,testCount);
     SVUT_REG_TEST_METHOD(testString,testReset);
     SVUT_REG_TEST_METHOD(testString,testOperator_equal);
     SVUT_REG_TEST_METHOD(testString,testOperator_plus);
     SVUT_REG_TEST_METHOD(testString,testOperator_compare);
};

void testString::setUp(void)    {};
void testString::tearDown(void) {};

void testString::testCount(void)            { SVUT_ASSERT_TODO("Need implementation");};
void testString::testReset(void)            { SVUT_ASSERT_TODO("Need implementation");};
void testString::testOperator_equal(void)   { SVUT_ASSERT_TODO("Need implementation");};
void testString::testOperator_plus(void   ) { SVUT_ASSERT_TODO("Need implementation");};
void testString::testOperator_compare(void) { SVUT_ASSERT_TODO("Need implementation");};

