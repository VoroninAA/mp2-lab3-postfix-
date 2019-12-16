#include "stack.h"
#include <gtest.h>

TEST(TStack, can_create_stack_with_positive_length)
{
  ASSERT_NO_THROW(TStack<int> st(5));
}

TEST(TStack, cant_create_stack_with_too_big_length)
{
	ASSERT_ANY_THROW(TStack<int> st(200));
}

TEST(TStack, cant_create_stack_with_negative_length)
{
	ASSERT_ANY_THROW(TStack<int> st(-5));
}
TEST(TStack, can_create_copied_stack)
{
	TStack<int> s(5);
	ASSERT_NO_THROW(TStack<int> st(s));
}
TEST(TStack, copied_stack_is_equal_to_source_one)
{
	TStack<int> s(5);
	s.Push(10);
	TStack<int> st(s);
	EXPECT_EQ(s.Pop(), st.Pop());
}
TEST(TStack, copied_stack_has_its_own_memory)
{
	TStack<int> s(5);
	s.Push(3);
	TStack<int> s1(s);
	s1.Pop();
	s1.Push(2);
	EXPECT_EQ(s.Pop(), 3);
	EXPECT_EQ(s1.Pop(), 2);
}
TEST(TStack, can_get_and_set_element)
{
	TStack<int> s(5);
	ASSERT_NO_THROW(s.Push(3));
	ASSERT_NO_THROW(s.Pop());
	
}
TEST(TStack, throws_when_try_to_get_element_from_empty_stack)
{
	TStack<int> s(5);
	ASSERT_ANY_THROW(s.Pop());

}

TEST(TStack, throws_when_try_to_put_element_to_full_stack)
{
	TStack<int> s(1);
	s.Push(2);
	ASSERT_ANY_THROW(s.Push(2));
}
TEST(TStack, can_use_is_empty)
{
	TStack<int> s(1);
	EXPECT_EQ(s.IsEmpty(),1);
}
TEST(TStack, can_use_is_empty_2)
{
	TStack<int> s(1);
	s.Push(1);
	EXPECT_EQ(s.IsEmpty(), 0);
}
TEST(TStack, can_use_is_full)
{
	TStack<int> s(1);
	EXPECT_EQ(s.IsFull(), 0);
}
TEST(TStack, can_use_is_full_2)
{
	TStack<int> s(1);
	s.Push(1);
	EXPECT_EQ(s.IsFull(), 1);
}
TEST(TStack, can_get_top_element) {
	TStack<int> s(2);
	s.Push(3);
	s.Push(5);
	EXPECT_EQ(s.GetTopElement(), 5);
}