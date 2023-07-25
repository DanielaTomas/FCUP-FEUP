//! @file color.hpp
#ifndef __rgb_color_hpp__
#define __rgb_color_hpp__

#include <iostream>

namespace rgb {
    typedef unsigned char rgb_value;

    class color {
    private:
        //! Red value of RGB components
        rgb_value r;
        //! Green value of RGB components
        rgb_value g;
        //! Blue value of RGB components
        rgb_value b;
    public:
        //! Red constant
        static const color RED;
        //! Green constant
        static const color GREEN;
        //! Blue constant
        static const color BLUE;
        //! Black constant
        static const color BLACK;
        //! White constant
        static const color WHITE;

        //! Default Constructor. Initialize all RGB components with value 0
        color();
        //! Constructor that uses supplied values to initialize RGB components
        //!
        //! \param c Color
        color(const color &c);
        //! Constructor by copy
        //!
        //! \param r Red value of RGB components
        //! \param g Green value of RGB components
        //! \param b Blue value of RGB components
        color(rgb_value r, rgb_value g, rgb_value b);
        //! Return red value
        //!
        //! \return Corresponding rgb_value
        rgb_value red() const;
        //! Return red reference
        //!
        //! \return Corresponding rgb_value reference
        rgb_value& red();
        //! Return green value
        //!
        //! \return Corresponding rgb_value
        rgb_value green() const;
        //! Return green reference
        //!
        //! \return Corresponding rgb_value reference
        rgb_value& green();
        //! Return blue value
        //!
        //! \return Corresponding rgb_value
        rgb_value blue() const;
        //! Return blue reference
        //!
        //! \return Corresponding rgb_value reference
        rgb_value& blue();
        //! Attribution operator
        //!
        //! \param c Color reference
        //! \return Corresponding color reference
        color& operator=(const color&c);
        //! Comparison operator (equal)
        //!
        //! \param c Color reference
        //! \return Corresponding bool
        bool operator==(const color &c) const;
        //! Comparison operator (different)
        //!
        //! \param c Color reference
        //! \return Corresponding bool
        bool operator!=(const color &c) const;
        //! Color inversion
        void invert();
        //! Convert to gray scale
        void to_gray_scale();
        //! Mix the color c with a factor f between 0 and 100
        //!
        //! \param c Color reference
        //! \param f Corresponding integer
        void mix(const color& c, int f);
    };
}
#endif
