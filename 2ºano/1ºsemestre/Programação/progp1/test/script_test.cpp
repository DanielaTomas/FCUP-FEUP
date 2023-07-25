#include <gtest/gtest.h>
#include <rgb/rgb.hpp>

using namespace rgb;
const std::string root_path = ROOT_PROJ_DIR;

class script_test : public testing::Test {
protected:
    image* e_img;
    image* o_img;
    void SetUp() override {
        e_img = o_img = NULL;
    }
    void TearDown() override {
        if (e_img != NULL) {
            delete e_img;
        }
        if (o_img != NULL) {
            delete o_img;
        }
    }
    void execute(std::string id) {
        std::string script_file = root_path + "/scripts/" + id + ".txt";
        std::string output = root_path + "/output/" + id + ".png";
        std::string expected = root_path + "/expected/" + id + ".png";
        script s(script_file);
        s.process();
        e_img = png::load(expected);
        ASSERT_TRUE(e_img != NULL);
        o_img = png::load(output);
        ASSERT_TRUE(o_img != NULL);
        ASSERT_EQ(e_img -> width(), o_img -> width());
        ASSERT_EQ(e_img -> height(), o_img -> height());
        for (int x = 0; x < e_img -> width(); x++) {
            for (int y = 0; y < e_img->height(); y++) {
                ASSERT_EQ(e_img->at(x, y), o_img->at(x, y));
            }
        }
    }
};

TEST_F(script_test, open_save1) {
    execute("open_save1");
}
TEST_F(script_test, open_save2) {
    execute("open_save2");
}
TEST_F(script_test, blank1) {
    execute("blank1");
}
TEST_F(script_test, blank2) {
    execute("blank2");
}
TEST_F(script_test, blank3) {
    execute("blank3");
}

TEST_F(script_test, gray1) {
    execute("gray1");
}
TEST_F(script_test, gray2) {
    execute("gray2");
}
TEST_F(script_test, gray3) {
    execute("gray3");
}

TEST_F(script_test, invert1) {
    execute("invert1");
}
TEST_F(script_test, invert2) {
    execute("invert2");
}
TEST_F(script_test, invert3) {
    execute("invert3");
}

TEST_F(script_test, fill1) {
    execute("fill1");
}
TEST_F(script_test, fill2) {
    execute("fill2");
}
TEST_F(script_test, fill3) {
    execute("fill3");
}

TEST_F(script_test, replace1) {
    execute("replace1");
}
TEST_F(script_test, replace2) {
    execute("replace2");
}
TEST_F(script_test, replace3) {
    execute("replace3");
}

TEST_F(script_test, crop1) {
    execute("crop1");
}
TEST_F(script_test, crop2) {
    execute("crop2");
}
TEST_F(script_test, crop3) {
    execute("crop3");
}
TEST_F(script_test, crop4) {
    execute("crop4");
}
TEST_F(script_test, crop5) {
    execute("crop5");
}
TEST_F(script_test, crop6) {
    execute("crop6");
}

TEST_F(script_test, rotate1) {
    execute("rotate1");
}
TEST_F(script_test, rotate2) {
    execute("rotate2");
}
TEST_F(script_test, rotate3) {
    execute("rotate3");
}
TEST_F(script_test, rotate4) {
    execute("rotate4");
}
TEST_F(script_test, rotate5) {
    execute("rotate5");
}
TEST_F(script_test, rotate6) {
    execute("rotate6");
}
TEST_F(script_test, rotate7) {
    execute("rotate7");
}
TEST_F(script_test, rotate8) {
    execute("rotate8");
}

TEST_F(script_test, mix1) {
    execute("mix1");
}
TEST_F(script_test, mix2) {
    execute("mix2");
}
TEST_F(script_test, mix3) {
    execute("mix3");
}
TEST_F(script_test, mix4) {
    execute("mix4");
}
TEST_F(script_test, mix5) {
    execute("mix5");
}
TEST_F(script_test, mix6) {
    execute("mix6");
}

TEST_F(script_test, add1) {
    execute("add1");
}
TEST_F(script_test, add2) {
    execute("add2");
}
TEST_F(script_test, add3) {
    execute("add3");
}
TEST_F(script_test, add4) {
    execute("add4");
}
TEST_F(script_test, add5) {
    execute("add5");
}

TEST_F(script_test, extra1) {
    execute("extra1");
}
TEST_F(script_test, extra2) {
    execute("extra2");
}
TEST_F(script_test, extra3) {
    execute("extra3");
}
TEST_F(script_test, extra4) {
    execute("extra4");
}