#include <gtest/gtest.h>
#include <rgb/rgb.hpp>

using namespace rgb;

void assert_color_is(const color& c, rgb_value r, rgb_value g, rgb_value b) {
    ASSERT_EQ((int)r, (int) c.red()) << "red component";
    ASSERT_EQ((int) g, (int)c.green()) << "green component";
    ASSERT_EQ((int) b, (int) c.blue()) << "blue component";
}
TEST(color, default_constructor) {
    color c;
    assert_color_is(c, 0, 0, 0);
}
TEST(color, rgb_constructor) {
    color c(1, 2, 3);
    assert_color_is(c, 1, 2, 3);
}
TEST(color, copy_constructor) {
    color c(1, 2, 3);
    color c2 = c;
    assert_color_is(c2, 1, 2, 3);
}
TEST(color, set) {
    color c;
    c.red() = 1;
    c.green() = 2;
    c.blue() = 3;
    assert_color_is(c, 1, 2, 3);
}
TEST(color, equality1) {
    color c(82, 0, 39);
    color c2 = c;
    ASSERT_TRUE(c == c2);
    ASSERT_FALSE(c != c2);
}
TEST(color, equality2) {
    color c(82, 0, 39);
    color c2(82, 0, 40);
    ASSERT_FALSE(c == c2);
    ASSERT_TRUE(c != c2);
}
TEST(color, equality3) {
    color c(82, 0, 39);
    color c2(83, 0, 40);
    ASSERT_FALSE(c == c2);
    ASSERT_TRUE(c != c2);
}
TEST(color, equality4) {
    color c(82, 0, 39);
    color c2(82, 1, 40);
    ASSERT_FALSE(c == c2);
    ASSERT_TRUE(c != c2);
}
TEST(color, assign1) {
    color c1(1,2,3);
    color c2;
    color c3 = c2 = c1;
    assert_color_is(c2, c1.red(), c1.green(), c1.blue());
    assert_color_is(c3, c1.red(), c1.green(), c1.blue());
}
TEST(color, invert1) {
    color c;
    c.invert();
    assert_color_is(c, 255, 255, 255);
}
TEST(color, invert2) {
    color c(255, 255, 255);
    c.invert();
    assert_color_is(c, 0, 0, 0);
}
TEST(color, invert3) {
    color c(128, 127, 30);
    c.invert();
    assert_color_is(c, 127, 128, 225);
}
TEST(color, to_gray_scale1) {
    color c;
    c.to_gray_scale();
    assert_color_is(c, 0, 0, 0);
}
TEST(color, to_gray_scale2) {
    color c(255, 255, 255);
    c.to_gray_scale();
    assert_color_is(c, 255, 255, 255);
}
TEST(color, to_gray_scale3) {
    color c(123, 123, 123);
    c.to_gray_scale();
    assert_color_is(c, 123, 123, 123);
}
TEST(color, to_gray_scale4) {
    color c(60, 50, 40);
    c.to_gray_scale();
    assert_color_is(c, 50, 50, 50);
}
TEST(color, to_gray_scale5) {
    color c(82, 0, 39);
    c.to_gray_scale();
    assert_color_is(c, 40, 40, 40);
}
void test_mix(color c1, color c2, int f) {
    int d = 100 - f;
    int r = (d * c1.red() + f * c2.red()) / 100;
    int g = (d * c1.green() + f * c2.green()) / 100;
    int b = (d * c1.blue() + f * c2.blue()) / 100;
    c1.mix(c2, f);
    assert_color_is(c1, r, g, b);
}
void test_mix(color c1, color c2) {
    test_mix(c1, c2, 0);
    test_mix(c1, c2, 10);
    test_mix(c1, c2, 90);
    test_mix(c1, c2, 100);
}
TEST(color, mix1) {
    color c1(0,0,0), c2(255,255,255);
    test_mix(c1, c2);
}
TEST(color, mix2) {
    color c1(100,26,99), c2(34,12,188);
    test_mix(c1, c2);
}
TEST(color, mix3) {
    color c1(255,0,255), c2(0,255,0);
    test_mix(c1, c2);
}