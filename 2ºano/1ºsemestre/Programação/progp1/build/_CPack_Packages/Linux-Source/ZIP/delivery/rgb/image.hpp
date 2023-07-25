//! @file image.hpp
#ifndef __rgb_image_hpp__
#define __rgb_image_hpp__
#include <cassert>
#include <rgb/color.hpp>

namespace rgb {
    class image {
    private:
        //! Image width
        int iwidth;
        //! Image height
        int iheight;
        //! Matrix for pixels
        color **pixels;
    public:
        //! Image constructor
        //!
        //! \param w Width
        //! \param h Height
        //! \param fill Initial color reference for all pixels
        image(int w, int h, const color& fill = color::WHITE);
        //! Destructor
        ~image();
        //! Return the image Width
        //!
        //! \return Corresponding integer
        int width() const;
        //! Return the image height
        //!
        //! \return Corresponding integer
        int height() const;
        //! Return the mutable reference in (x,y)
        //!
        //! \param x Position x
        //! \param y Position y
        //! \return Corresponding color reference
        color& at(int x, int y);
        //! Return the constant for the pixel color in (x,y)
        //!
        //! \param x Position x
        //! \param y Position y
        //! \return Corresponding color reference
        const color& at(int x, int y) const;
        //! Inverts all image pixels
        void invert();
        //! Converts all image pixels to gray scale
        void to_gray_scale();
        //! Change all pixels color with color a to color b
        //!
        //! \param a Color reference
        //! \param b Color reference
        void replace(const color& a, const color& b);
        //! Define the color c for all pixels
        //!
        //! \param x Position x
        //! \param y Position y
        //! \param w Width
        //! \param h Height
        //! \param c Color reference
        void fill(int x, int y, int w, int h, const color& c);
        //! Mix the image pixels with a factor f
        //!
        //! \param  img Image reference
        //! \param  factor Corresponding integer
        void mix(const image& img, int factor);
        //! Crop the image
        //!
        //! \param x Position x
        //! \param y Position y
        //! \param w Width
        //! \param h Height
        void crop(int x, int y, int w, int h);
        //! Rotate the image to the left
        void rotate_left();
        //! Rotate the image to the right
        void rotate_right();
        //! Add the image content, replacing current pixels from (x,y) except for pixels that have neutral color
        //!
        //! \param img Image reference
        //! \param neutral Neutral color
        //! \param x Position x
        //! \param y Position y
        void add(const image& img, const color& neutral, int x, int y);
    };
}


#endif
