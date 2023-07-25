#include <random>
#include <gtest/gtest.h>
#include <rgb/rgb.hpp>

using namespace rgb;

void assert_all_pixels_are(const image& image, const color& c) {
    for (int i = 0; i < image.width(); i++) {
        for (int j = 0; j < image.height(); j++) {
            ASSERT_EQ(c, image.at(i, j));
        }
    }
}


TEST(image, constructor) {
    image image(10, 20);
    ASSERT_EQ(10, image.width());
    ASSERT_EQ(20, image.height());
    assert_all_pixels_are(image, color::WHITE);
}
TEST(image, constructor2) {
    color c(1,2,3); // DEFAULT
    image image(20, 10, c);
    ASSERT_EQ(20, image.width());
    ASSERT_EQ(10, image.height());
    assert_all_pixels_are(image, c);
}
TEST(image, set) {
    image img(20, 10);
    color colors[20][10];
    std::default_random_engine rng;
    std::uniform_int_distribution<int> distribution(1,255);
    for (int x = 0; x < 20; x++) {
        for (int y = 0; y < 10; y++) {
            color c;
            c.red() = (rgb_value) distribution(rng);
            c.green() = (rgb_value) distribution(rng);
            c.blue() = (rgb_value) distribution(rng);
            img.at(x, y) = c;
            colors[x][y] = c;
        }
    }
    for (int x = 0; x < 20; x++) {
        for (int y = 0; y < 10; y++) {
            ASSERT_EQ(colors[x][y], img.at(x, y));
        }
    }
}
