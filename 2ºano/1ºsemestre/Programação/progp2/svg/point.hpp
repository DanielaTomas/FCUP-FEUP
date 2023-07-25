//! @file point.hpp
#ifndef __coord2d_hpp__
#define __coord2d_hpp__
#include <cmath>

namespace svg {
    //! 2D Point.
    struct point {
        //! X coordinate.
        int x;
        //! Y coordinate.
        int y;
        //! Translation.
        //! @param t translation direction.
        //! @return Translated point.
        point translate(const point &t) const {
            return  { x + t.x, y + t.y };;
        }
        //! Rotation.
        //! @param origin Rotation origin
        //! @param degrees Degrees of rotation.
        //! @return Rotated point.
        point rotate(const point& origin, int degrees) const {
            double angle = M_PI * degrees / 180.0;
            double dx = x - origin.x;
            double dy = y - origin.y;
            double s = ::sin(angle);
            double c = ::cos(angle);
            int rx = (int) ::lround(c * dx - s * dy);
            int ry = (int) ::lround(s * dx + c * dy);
            return {origin.x + rx , origin.y + ry};
        }
        //! Scaling.
        //! @param origin Scaling origin.
        //! @param v Scale amount.
        //¡ @return Scaled point.
        point scale(const point& origin, int v) const {
            return { origin.x + (x - origin.x) * v,
                     origin.y + (y - origin.y) * v };
        }
    };

}


#endif
