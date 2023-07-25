#include <gtest/gtest.h>
#include <stack.h>

// Test fixture
class test_stack : public testing::Test {
protected:
    stack* s;
    void SetUp() override {
        s = stack_create();
    }
    void TearDown() override {
        stack_destroy(s);
    }
};

// Auxiliary macro
#define EXPECT_ARRAY_EQ(exp, arr) { \
  int __sz = sizeof(exp) / sizeof(int); \
  for (int __i = 0; __i < __sz; __i++) { \
    EXPECT_EQ((exp)[__i], (arr)[__i]) << "array pos " << __i; \
  } \
}

TEST_F(test_stack, init) {
    int v;
    EXPECT_EQ(0, stack_size(s));
    EXPECT_TRUE(stack_is_empty(s));
    EXPECT_FALSE(stack_peek(s, &v));
}

TEST_F(test_stack, pop_on_empty_stack) {
    int v;
    EXPECT_FALSE(stack_pop(s, &v));
    EXPECT_FALSE(stack_peek(s, &v));
    EXPECT_EQ(0, stack_size(s));
    EXPECT_TRUE(stack_is_empty(s));
}

TEST_F(test_stack, one_push) {
    stack_push(s, 1);
    EXPECT_EQ(1, stack_size(s));
    EXPECT_FALSE(stack_is_empty(s));

    int v = 0; int a[1] = { 0 }, ea[] = {1};
    EXPECT_TRUE(stack_peek(s, &v));
    EXPECT_EQ(1, v);
    stack_to_array(s, a);
    EXPECT_ARRAY_EQ(ea, a);
}

TEST_F(test_stack, push_then_pop) {
    int v;
    stack_push(s, 1);
    stack_pop(s, &v);
    EXPECT_EQ(0, stack_size(s));
    EXPECT_TRUE(stack_is_empty(s));
    EXPECT_FALSE(stack_peek(s, &v));
}

TEST_F(test_stack, push_3_elements) {
    stack_push(s, 1);
    stack_push(s, 2);
    stack_push(s, 3);
    EXPECT_EQ(3, stack_size(s));
    EXPECT_FALSE(stack_is_empty(s));

    int v = 0; int a[3] = { 0 }; int ea[] = { 3, 2, 1};
    EXPECT_TRUE(stack_peek(s, &v));
    EXPECT_EQ(3, v);
    stack_to_array(s, a);
    EXPECT_ARRAY_EQ(ea, a);
}

TEST_F(test_stack, push_3_elements_then_pop) {
    int v_pop1=0, v_pop2=0, v_pop3=0;
    stack_push(s, 1);
    stack_push(s, 2);
    stack_push(s, 3);
    stack_pop(s, &v_pop1);
    stack_pop(s, &v_pop2);
    stack_pop(s, &v_pop3);
    EXPECT_EQ(3, v_pop1);
    EXPECT_EQ(2, v_pop2);
    EXPECT_EQ(1, v_pop3);
    EXPECT_EQ(0, stack_size(s));
    EXPECT_TRUE(stack_is_empty(s));
}



TEST_F(test_stack, multiple_push_and_pop) {
    int v_pop1=0, v_pop2=0, v_pop3=0, v_peek=0;
    stack_push(s, 1);
    stack_push(s, 2);
    stack_push(s, 3);   // stack -> 3,2,1
    stack_pop(s, &v_pop1); // -> 2,1
    stack_push(s, 4);   // -> 4,2,1
    stack_pop(s, &v_pop2); // -> 2,1
    stack_pop(s, &v_pop3); // -> 1
    stack_push(s, 5);  // -> 5, 1
    EXPECT_EQ(3, v_pop1);
    EXPECT_EQ(4, v_pop2);
    EXPECT_EQ(2, v_pop3);
    EXPECT_EQ(2, stack_size(s));
    EXPECT_FALSE(stack_is_empty(s));
    EXPECT_TRUE(stack_peek(s, &v_peek));
    int ea[] = { 5, 1 }, a[2];
    stack_to_array(s, a);
    EXPECT_ARRAY_EQ(ea, a);
}