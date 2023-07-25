//! @file png_image.hpp
#ifndef __svg_png_image_hpp__
#define __svg_png_image_hpp__

#include "color.hpp"
#include "point.hpp"

#include <string>
#include <vector>

namespace svg {
    //! PNG image.
    class png_image {
    private:
        //! Width.
        int png_width;
        //! Height.
        int png_height;
        //! Pixels.
        color *pixels;
    public:
        //! Constructor that loads image from a file.
        //! @param png_file_name File name.
        png_image(const std::string& png_file_name);
        //! Constructor of blank image.
        //! Initally, all pixels will be white.
        //! @param w Image width.
        //! @param h Image height.
        png_image(int w, int h);
        //! Destructor.
        ~png_image();
        //! Get image width.
        //! @return The image width.
        int width() const;
        //! Get image height.
        //! @return The image height.
        int height() const;
        //! Get mutable reference to image pixel.
        //! @param x X position
        //! @param y Y position.
        //! @return Reference to pixel.
        color& at(int x, int y);
        //! Get const reference to image pixel.
        //! @param x X position
        //! @param y Y position.
        //! @return Reference to pixel.
        const color& at(int x, int y) const;
        //! Save to output file.
        //! @param png_file_name Output file name.
        void save(const std::string& png_file_name) const;
        //! Draw a line defined by 2 points.
        //! @param a First point.
        //! @param b Second point.
        //! @param c Color to use for the line.
        void draw_line(const point& a, const point& b, const color& c);
        //! Draw a polygon.
        //! @param points Vector of points defining the polygon.
        //! @param fill Color to use for the polygon fill.
        void draw_polygon(const std::vector<point>& points, const color& fill);
        //! Draw an ellipse.
        //! @param center Coordinates for the ellipse center.
        //! @param radius Radius in X and Y axis.
        //! @param fill Color to use for the ellipse fill.
        //! @param orientation ellipse orientation.
        void draw_ellipse(const point& center, const point& radius, const color& fill);
    };
}


#endif
