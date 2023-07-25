#include <iostream>
#include <string>
#include <rgb/rgb.hpp>

int main(int argc, char** argv) {
    if (argc != 2) {
        std::cout << "Usage: image_dump file.png";
        return 1;
    }
    std::string file(argv[1]);
    rgb::image *img = png::load(file);
    if (img == NULL) {
        std::cout << "Could not load " << file << std::endl;
        return 1;
    }
    std::cout << "- Loaded " << file
              << " ( " << img -> width()
              << " x " << img -> height()
              << " )"  << std::endl;
    for (int x = 0; x < img -> width(); x++) {
        for (int y = 0; y < img -> height(); y++) {
            const rgb::color& c = img->at(x, y);
            std::cout << x << ',' << y << " --> "
                      << (int) c.red() << ','
                      << (int) c.green() << ','
                      << (int) c.blue() << std::endl;
        }
    }
    delete img;
    return 0;
}
