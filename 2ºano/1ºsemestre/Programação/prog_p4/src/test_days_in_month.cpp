#include <gtest/gtest.h>
#include <funcs.h>

TEST(days_in_month, january_2021) {
    EXPECT_EQ(31,
              days_in_month(JANUARY, 2021));
}

TEST(days_in_month, february_2016) {
    EXPECT_EQ(29,
              days_in_month(FEBRUARY, 2016));
}

TEST(days_in_month, february_1900) {
    EXPECT_EQ(28,
              days_in_month(FEBRUARY, 1900));
}

TEST(days_in_month, february_2000) {
    EXPECT_EQ(29,
              days_in_month(FEBRUARY, 2000));
}

TEST(days_in_month, february_2021) {
    EXPECT_EQ(28,
              days_in_month(FEBRUARY, 2021));
}

TEST(days_in_month, march_2021) {
    EXPECT_EQ(31,
              days_in_month(MARCH, 2021));
}

TEST(days_in_month, april_2021) {
    EXPECT_EQ(30,
days_in_month(APRIL, 2021));
}

TEST(days_in_month, may_2021) {
    EXPECT_EQ(31,
              days_in_month(MAY, 2021));
}

TEST(days_in_month, june_2021) {
    EXPECT_EQ(30,
              days_in_month(JUNE, 2021));
}

TEST(days_in_month, july_2021) {
    EXPECT_EQ(31,
              days_in_month(JULY, 2021));
}

TEST(days_in_month, august_2021) {
    EXPECT_EQ(31,
              days_in_month(AUGUST, 2021));
}

TEST(days_in_month, september_2021) {
    EXPECT_EQ(30,
              days_in_month(SEPTEMBER, 2021));
}

TEST(days_in_month, october_2021) {
    EXPECT_EQ(31,
              days_in_month(OCTOBER, 2021));
}

TEST(days_in_month, november_2021) {
    EXPECT_EQ(30,
              days_in_month(NOVEMBER, 2021));
}

TEST(days_in_month, december_2021) {
    EXPECT_EQ(31,
              days_in_month(DECEMBER, 2021));
}

