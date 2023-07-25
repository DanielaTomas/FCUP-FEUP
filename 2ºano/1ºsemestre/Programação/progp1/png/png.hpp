#ifndef __rgb_png_hpp__
#define __rgb_png_hpp__

#include <string>
#include <rgb/image.hpp>

namespace png {
    //! Load an image from a PNG file.
    //! @param file File name.
    //! @return A new image (dynamically allocated).
    rgb::image *load(const std::string &file);

    //! Save an image to a PNG file.
    //! @param file File name.
    //! //! @param img Image to save.
    void save(const std::string &file, const rgb::image *img);

}
#endif
