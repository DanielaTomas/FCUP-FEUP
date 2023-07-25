#include <png/png.hpp>
#include <rgb/image.hpp>
#include <cassert>
#define STBI_ONLY_PNG
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb_image_write.h"

using namespace rgb;

namespace png {
    image* load(const std::string& file) {
        int w, h, dummy;
        rgb_value *buffer = stbi_load(file.c_str(), &w, &h, &dummy, 3);
        if (buffer == NULL) {
            return NULL; // Could not load image!
        }
        auto p = buffer;
        auto img = new image(w, h);
        for (int y = 0; y < h; y++) {
            for (int x = 0; x < w; x++) {
                rgb_value red = p[0];
                rgb_value green = p[1];
                rgb_value blue = p[2];
                img -> at(x, y) = color(red, green, blue);
                p += 3;
            }
        }
        stbi_image_free(buffer);
        return img;
    }

    void save(const std::string& file, const image* image) {
        auto w = image->width();
        auto h = image->height();
        auto buffer = new rgb_value[w * h * 3];
        auto p = buffer;
        for (auto y = 0; y < h; y++) {
            for (auto x = 0; x < w; x++) {
                auto c = image->at(x, y);
                p[0] = c.red();
                p[1] = c.green();
                p[2] = c.blue();
                p += 3;
            }
        }
        stbi_write_png(file.c_str(),
                       w,
                       h,
                       3,
                       buffer,
                       w * 3);
        delete [] buffer;
    }
}



