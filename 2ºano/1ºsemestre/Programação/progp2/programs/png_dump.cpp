#include <iostream>
#include <string>
#include <svg/svg.hpp>

int main(int argc, char** argv) {
    if (argc != 2) {
        std::cout << "Usage: image_dump file.png";
        return 1;
    }
    svg::png_image img(argv[1]);
    std::cout << "- Loaded " << argv[1]
              << " ( " << img.width()
              << " x " << img.height()
              << " )"  << std::endl;
    for (int x = 0; x < img.width(); x++) {
        for (int y = 0; y < img.height(); y++) {
            const svg::color& c = img.at(x, y);
            std::cout << x << ',' << y << " --> "
                      << (int) c.red << ','
                      << (int) c.green << ','
                      << (int) c.blue << std::endl;
        }
    }
    return 0;
}
