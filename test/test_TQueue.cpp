#include "Queue.h"
#include "../gtest/gtest.h"

TEST(TQueue, can_create_queue_with_positive_length) {
	ASSERT_NO_THROW(TQueue<int> t(3));
}

TEST(TQueue, cannot_create_queue_with_negative_length) {
	ASSERT_ANY_THROW(TQueue<int> t(-1));
}


TEST(TQueue, can_push_and_get_from_queue) {
	TQueue<int> t(3);
	t.Push(2);
	EXPECT_EQ(t.Get(), 2);
}

TEST(TQueue, cannot_push_into_full_queue) {
	TQueue<int> t(1);
	t.Push(1);
	ASSERT_ANY_THROW(t.Push(0));
}

TEST(TQueue, cannot_get_if_queue_empty) {
	TQueue<int> t(1);
	ASSERT_ANY_THROW(t.Get());
}

TEST(TQueue, can_use_copy_operator) {
	TQueue<int> t(3);
	t.Push(1);
	t.Push(2);
	TQueue<int> c(t);
	EXPECT_EQ(t, c);
}

TEST(TQueue, can_use_assignment_operator) {
	TQueue<int> t(3);
	t.Push(1);
	t.Push(2);
	TQueue<int> c = t;
	EXPECT_EQ(t, c);
}

TEST(TQueue, can_get_length) {
	TQueue<int> t(3);
	t.Push(1);
	t.Push(2);
	EXPECT_EQ(t.Length(), 2);
}

TEST(TQueue, can_find_min) {
	TQueue<int> t(3);
	t.Push(4);
	t.Push(2);
	t.Push(3);
	EXPECT_EQ(t.FindMin(), 2);
}

TEST(TQueue, can_find_max) {
	TQueue<int> t(3);
	t.Push(2);
	t.Push(4);
	t.Push(5);
	EXPECT_EQ(t.FindMax(), 5);
}