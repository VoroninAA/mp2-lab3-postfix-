#include "postfix.h"
#include <gtest.h>

TEST(TPostfix, can_create_postfix)
{
  ASSERT_NO_THROW(TPostfix p);
}

TEST(TPostfix, can_create_postfix_with_starting_infix)
{
	ASSERT_NO_THROW(TPostfix p("1"));
}

TEST(TPostfix, can_get_right_correctness)
{
	TPostfix p("(a+b)");
	ASSERT_NO_THROW(p.CheckInputCorrectness());
}

TEST(TPostfix, can_get_wrong_correctness)
{
	TPostfix p(")a+b(");
	EXPECT_EQ(p.CheckInputCorrectness(), 0);
}

TEST(TPostfix, can_get_wrong_correctness_2)
{
	TPostfix p("()a+b(");
	EXPECT_EQ(p.CheckInputCorrectness(),0);
}
TEST(TPostfix, can_get_right_correctness_2)
{
	TPostfix p("()a+b()(())");
	
	ASSERT_NO_THROW(p.CheckInputCorrectness());
}

TEST(TPostfix, can_check_operation_right)
{
	TPostfix p("a+b");
	EXPECT_EQ(1,p.CheckOperation('+'));
}

TEST(TPostfix, can_check_operation_wrong)
{
	TPostfix p("a+b");
	EXPECT_EQ(0, p.CheckOperation('9'));
}

TEST(TPostfix, can_check_operand_right)
{
	TPostfix p("a+b");
	EXPECT_EQ(1, p.CheckOperand('h'));
}

TEST(TPostfix, can_check_operand_wrong)
{
	TPostfix p("a+b");
	EXPECT_EQ(0, p.CheckOperand(')'));
}
TEST(TPostfix, can_check_priority_right)
{
	TPostfix p("a+b");
	EXPECT_EQ(2, p.GetPriority('+'));
}
TEST(TPostfix, can_check_priority_wrong)
{
	TPostfix p("a+b");
	EXPECT_EQ(-1, p.GetPriority('k'));
}
TEST(TPostfix, can_use_to_postfix)
{
	TPostfix p("((d+e)a+b*c)");
	EXPECT_EQ("de+abc*+", p.ToPostfix());
}
