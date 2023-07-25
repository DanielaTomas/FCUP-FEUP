#include <gtest/gtest.h>
#include <funcs.h>
#include <math.h>

const double tol = 1e-05;

TEST(exp_taylor, x0_n0) {
    EXPECT_NEAR(
            1.0,
            exp_taylor(0.0, 0),
            tol);
}

TEST(exp_taylor, x0_n3) {
    EXPECT_NEAR(
            1.0,
            exp_taylor(0.0, 3),
            tol);
}

TEST(exp_taylor, x1_n0) {
    EXPECT_NEAR(
            1.0,
            exp_taylor(1.0, 0),
            tol);
}

TEST(exp_taylor, x1_n1) {
    EXPECT_NEAR(
             1.0 + 1.0,
            exp_taylor(1.0, 1),
            tol);
}

TEST(exp_taylor, x1_n4) {
    EXPECT_NEAR(
            1.0 + 1.0 + 0.5 + 0.166666667,
            exp_taylor(1.0, 3),
            tol);
}

TEST(exp_taylor, x1_n20) {
    EXPECT_NEAR(
            M_E,
            exp_taylor(1.0, 20),
            tol);
}

TEST(exp_taylor, x2_n1) {
    EXPECT_NEAR(
            1.0 + 2.0,
            exp_taylor(2.0, 1),
            tol);
}

TEST(exp_taylor, x2_n4) {
    EXPECT_NEAR(
            1.0 + 2.0 + 2.0 + 1.33333333,
            exp_taylor(2.0, 3),
            tol);
}

TEST(exp_taylor, x2_n25) {
    EXPECT_NEAR(
            M_E * M_E,
            exp_taylor(2.0, 25),
            tol);
}

TEST(exp_taylor, xm2_n1) {
    EXPECT_NEAR(
            1.0 - 2.0,
            exp_taylor(-2.0, 1),
            tol);
}

TEST(exp_taylor, xm2_n4) {
    EXPECT_NEAR(
            1.0 - 2.0 + 2.0 - 1.33333333,
            exp_taylor(-2.0, 3),
            tol);
}

TEST(exp_taylor, x_4_n25) {
    EXPECT_NEAR(
            M_E * M_E * M_E * M_E,
            exp_taylor(4.0, 25),
            tol);
}