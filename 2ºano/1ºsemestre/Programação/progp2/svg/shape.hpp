//! @file shape.hpp
#ifndef __svg_shape_hpp__
#define __svg_shape_hpp__

#include <string>
#include <vector>
#include <map>
#include "color.hpp"
#include "point.hpp"
#include "png_image.hpp"

namespace svg {
    class shape {
    private:
        color s_color;
    public:
        //! Constructor.
        //! @param c Color to use for shape.
        shape(const color& c);
        //! Destructor.
        virtual ~shape();
        //! Get color associated to shape.
        //! @return Color of shape.
        const color& get_color() const;
        //! Draw shape.
        //! @param img PNG image to draw on.
        virtual void draw(png_image& img) const;
        //! Translate shape.
        //! @param t translation.
        virtual void translate(const point& c);
        //! Scale shape.
        //! @param origin Reference origin for scaling.
        //! @param v Scale factor (assumed to be >= 1).
        virtual void scale(const point& origin, int v);
        //! Rotate shape.
        //! @param origin Reference origin for rotation.
        //! @param degrees Degrees of rotation.
        virtual void rotate(const point& center, int degrees);
        //! Duplicate shape.
        //! Function should return a newly allocated shape
        //! with the same characteristics.
        //! @return Duplicate of shape.
        virtual shape* duplicate() const;
    };



}
#endif


