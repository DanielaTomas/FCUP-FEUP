//! @file color.hpp
#ifndef __svg_color_hpp__
#define __svg_color_hpp__

namespace svg {
    typedef unsigned char rgb_value;

    struct color {
        rgb_value red;
        rgb_value green;
        rgb_value blue;
    };
    inline bool operator==(const color& a, const color& b) {
        return a.red == b.red &&
               a.green == b.green &&
               a.blue == b.blue;
    }
    inline bool operator!=(const color& a, const color& b) {
        return ! (a == b);
    }
}
#endif