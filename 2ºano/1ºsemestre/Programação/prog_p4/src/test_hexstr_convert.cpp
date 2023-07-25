#include <gtest/gtest.h>
#include <funcs.h>

TEST(hexstr_convert, zero) {
    EXPECT_EQ(0, hexstr_convert("0"));
}

TEST(hexstr_convert, only_decimal_digits) {
    EXPECT_EQ(291, hexstr_convert("123"));
}

TEST(hexstr_convert, negative_number) {
    EXPECT_EQ(-43915396, hexstr_convert("-1e77C"));
}
