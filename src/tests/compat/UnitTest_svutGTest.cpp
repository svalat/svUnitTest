/*****************************************************
             PROJECT  : svUnitTest
             VERSION  : 0.5.0-dev
             DATE     : 11/2012
             AUTHOR   : Valat Sébastien
             LICENSE  : CeCILL-C 2.1
*****************************************************/

/********************  HEADERS  *********************/
#include <svutGTest.h>

/**********************  USING  *********************/
using namespace testing;

/*********************  CLASS  **********************/
class MyFixture : public ::testing::Test
{
	public:
		MyFixture(void)
		{
			value = 10;
		}
		
		void SetUp(void)
		{
			ASSERT_EQ(10,value);
			value = 11;
		}
		
		void TearDown(void)
		{
			ASSERT_EQ(11,value);
			value = 10;
		}
	protected:
		int value;
};

/*******************  FUNCTION  *********************/
TEST(svutGTest,assert_true)
{
	ASSERT_TRUE(true);
	EXPECT_TRUE(true);
	
	SVUT_ASSERT_THROW_SOMETHING(ASSERT_TRUE(false));
	SVUT_ASSERT_THROW_SOMETHING(EXPECT_TRUE(false));
}

/*******************  FUNCTION  *********************/
TEST(svutGTest,assert_false)
{
	ASSERT_FALSE(false);
	EXPECT_FALSE(false);
	
	SVUT_ASSERT_THROW_SOMETHING(ASSERT_FALSE(true));
	SVUT_ASSERT_THROW_SOMETHING(EXPECT_FALSE(true));
}

/*******************  FUNCTION  *********************/
TEST(svutGTest,assert_eq)
{
	ASSERT_EQ(1,1);
	EXPECT_EQ(1,1);
	
	SVUT_ASSERT_THROW_SOMETHING(ASSERT_EQ(1,2));
	SVUT_ASSERT_THROW_SOMETHING(EXPECT_EQ(1,2));
}

/*******************  FUNCTION  *********************/
TEST(svutGTest,assert_ne)
{
	ASSERT_NE(1,2);
	EXPECT_NE(1,2);
	
	SVUT_ASSERT_THROW_SOMETHING(ASSERT_NE(1,1));
	SVUT_ASSERT_THROW_SOMETHING(EXPECT_NE(1,1));
}

/*******************  FUNCTION  *********************/
TEST(svutGTest,assert_lt)
{
	ASSERT_LT(1,2);
	EXPECT_LT(1,2);
	
	SVUT_ASSERT_THROW_SOMETHING(ASSERT_LT(2,1));
	SVUT_ASSERT_THROW_SOMETHING(EXPECT_LT(2,1));
	
	SVUT_ASSERT_THROW_SOMETHING(ASSERT_LT(2,2));
	SVUT_ASSERT_THROW_SOMETHING(EXPECT_LT(2,2));
}

/*******************  FUNCTION  *********************/
TEST(svutGTest,assert_le)
{
	ASSERT_LE(1,2);
	EXPECT_LE(1,2);
	
	ASSERT_LE(2,2);
	EXPECT_LE(2,2);
	
	SVUT_ASSERT_THROW_SOMETHING(ASSERT_LE(2,1));
	SVUT_ASSERT_THROW_SOMETHING(EXPECT_LE(2,1));
}

/*******************  FUNCTION  *********************/
TEST(svutGTest,assert_gt)
{
	ASSERT_GT(2,1);
	EXPECT_GT(2,1);
	
	SVUT_ASSERT_THROW_SOMETHING(ASSERT_GT(1,2));
	SVUT_ASSERT_THROW_SOMETHING(EXPECT_GT(1,2));
	
	SVUT_ASSERT_THROW_SOMETHING(ASSERT_GT(2,2));
	SVUT_ASSERT_THROW_SOMETHING(EXPECT_GT(2,2));
}

/*******************  FUNCTION  *********************/
TEST(svutGTest,assert_ge)
{
	ASSERT_GE(2,1);
	EXPECT_GE(2,1);
	
	ASSERT_GE(2,2);
	EXPECT_GE(2,2);
	
	SVUT_ASSERT_THROW_SOMETHING(ASSERT_GE(1,2));
	SVUT_ASSERT_THROW_SOMETHING(EXPECT_GE(1,2));
}

/*******************  FUNCTION  *********************/
TEST(svutGTest,assert_streq)
{
	ASSERT_STREQ("aa","aa");
	EXPECT_STREQ("aa","aa");

	SVUT_ASSERT_THROW_SOMETHING(ASSERT_STREQ("ab","aa"));
	SVUT_ASSERT_THROW_SOMETHING(EXPECT_STREQ("ab","aa"));
}

/*******************  FUNCTION  *********************/
TEST(svutGTest,assert_strne)
{
	ASSERT_STRNE("ab","aa");
	EXPECT_STRNE("ab","aa");

	SVUT_ASSERT_THROW_SOMETHING(ASSERT_STRNE("aa","aa"));
	SVUT_ASSERT_THROW_SOMETHING(EXPECT_STRNE("aa","aa"));
}

/*******************  FUNCTION  *********************/
TEST(svutGTest,fail)
{
	SVUT_ASSERT_THROW_SOMETHING(FAIL());
	SVUT_ASSERT_THROW_SOMETHING(ADD_FAILURE());
	SVUT_ASSERT_THROW_SOMETHING(ADD_FAILURE_AT("test",33));
}

/*******************  FUNCTION  *********************/
TEST(svutGTest,assert_throw)
{
	ASSERT_THROW(throw 10,int);
	EXPECT_THROW(throw 10,int);

	SVUT_ASSERT_THROW_SOMETHING(ASSERT_THROW(free(NULL),int));
	SVUT_ASSERT_THROW_SOMETHING(EXPECT_THROW(free(NULL),int));
}

/*******************  FUNCTION  *********************/
TEST(svutGTest,assert_any_throw)
{
	ASSERT_ANY_THROW(throw 10);
	EXPECT_ANY_THROW(throw 10);

	SVUT_ASSERT_THROW_SOMETHING(ASSERT_ANY_THROW(free(NULL)));
	SVUT_ASSERT_THROW_SOMETHING(EXPECT_ANY_THROW(free(NULL)));
}

/*******************  FUNCTION  *********************/
TEST(svutGTest,assert_no_throw)
{
	ASSERT_NO_THROW(free(NULL));
	EXPECT_NO_THROW(free(NULL));

	SVUT_ASSERT_THROW_SOMETHING(ASSERT_NO_THROW(throw 10));
	SVUT_ASSERT_THROW_SOMETHING(EXPECT_NO_THROW(throw 10));
}

/*******************  FUNCTION  *********************/
TEST(svutGTest,assert_float_eq)
{
	ASSERT_FLOAT_EQ(1.4,1.4);
	EXPECT_FLOAT_EQ(1.4,1.4);
	
	SVUT_ASSERT_THROW_SOMETHING(ASSERT_FLOAT_EQ(1.4,2.4));
	SVUT_ASSERT_THROW_SOMETHING(EXPECT_FLOAT_EQ(1.4,2.4));
}

/*******************  FUNCTION  *********************/
TEST(svutGTest,assert_double_eq)
{
	ASSERT_DOUBLE_EQ(1.4,1.4);
	EXPECT_DOUBLE_EQ(1.4,1.4);
	
	SVUT_ASSERT_THROW_SOMETHING(ASSERT_DOUBLE_EQ(1.4,2.4));
	SVUT_ASSERT_THROW_SOMETHING(EXPECT_DOUBLE_EQ(1.4,2.4));
}

/*******************  FUNCTION  *********************/
TEST(svutGTest,assert_death_if_supported)
{
	int * tmp = NULL;

	ASSERT_DEATH_IF_SUPPORTED(*tmp=20,"segfault");
	EXPECT_DEATH_IF_SUPPORTED(*tmp=20,"segfault");

	SVUT_ASSERT_EQUAL((int*)NULL,tmp);
}

/*******************  FUNCTION  *********************/
TEST_F(MyFixture,test)
{
	ASSERT_EQ(11,value);
}
