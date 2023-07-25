#ifndef __test_hpp__
#define __test_hpp__

#include <gtest/gtest.h>
#include <svg/svg.hpp>

using namespace svg;
const std::string root_path = ROOT_PROJ_DIR;


void svg_test(std::string id) {
    std::string input = root_path + "/input/" + id + ".svg";
    std::string output = root_path + "/output/" + id + ".png";
    std::string expected = root_path + "/expected/" + id + ".png";
    svg_to_png(input, output);
    png_image e_img(expected);
    png_image o_img(output);
    ASSERT_EQ(e_img.width(), o_img.width()) << " - different width!";
    ASSERT_EQ(e_img.height(), o_img.height()) << " - different height!";
    for (int x = 0; x < e_img.width(); x++) {
        for (int y = 0; y < e_img.height(); y++) {
            ASSERT_EQ(e_img.at(x, y), o_img.at(x, y)) << " pixel " << x << ',' << y;
        }
    }
}
#endif