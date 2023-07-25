
//! @file script.hpp
#ifndef __rgb_script_hpp__
#define __rgb_script_hpp__

#include <fstream>
#include <rgb/image.hpp>

namespace rgb {
    class script {
    private:
        //! Initialize file image
        void open();
        //! Initialize the image
        void blank();
        //! Save the image to a PNG file
        void save();
        //! Member function from rgb::image that applies the corresponding transformation to the image
        void fill();
        //! Member function from rgb::image that applies the corresponding transformation to the image
        void invert();
        //! Member function from rgb::image that applies the corresponding transformation to the image
        void to_gray_scale();
        //! Member function from rgb::image that applies the corresponding transformation to the image
        void replace();
        //! Member function from rgb::image that applies the corresponding transformation to the image
        void mix();
        //! Member function from rgb::image that applies the corresponding transformation to the image
        void add();
        //! Member function from rgb::image that applies the corresponding transformation to the image
        void crop();
        //! Member function from rgb::image that applies the corresponding transformation to the image
        void rotate_left();
        //! Member function from rgb::image that applies the corresponding transformation to the image
        void rotate_right();
    public:
        //! Constructor
        //!
        //! \param filename Filename
        script(const std::string& filename);
        //! Destructor
        ~script();
        //! Process the script by reading the commands
        void process();
    private:
        //! Image for the commands
        image* img;
        //! Input
        std::ifstream input;
        //! Root Path
        std::string root_path;
    };
}
#endif
