

#include <iostream>
#include <string>

#include <svg/svg.hpp>

int main(int argc, char** argv) {
    if (argc != 3) {
        std::cout << "Usage: image_diff file1.png file2.png";
        return 1;
    }
    std::string file1(argv[1]);
    std::string file2(argv[2]);
    svg::png_image img1(file1);

    std::cout << "- Loaded " << file1
              << " ( " << img1.width()
              << " x " << img1.height()
              << " )"  << std::endl;
    svg::png_image img2(file2);
    std::cout << "- Loaded " << file2
              << " ( " << img2.width()
              << " x " << img2.height()
              << " )"  << std::endl;
    bool eq = img1.width() == img2.width() &&
              img1.height() == img2.height();
    if (!eq) {
        std::cout << "- Different image dimensions!" << std::endl;
    } else {
        for (int x = 0; x < img1.width() && eq ; x++) {
            for (int y = 0; y < img1.height() && eq; y++) {
                const svg::color& c1 = img1.at(x, y);
                const svg::color& c2 = img2.at(x, y);
                eq = (c1 == c2);
                if (!eq) {
                    std::cout << "- Pixel (" << x << ',' << y << ") is different: "
                               << '(' << (int) c1.red << ',' <<
                              (int) c1.green << ','
                              << (int) c1.blue
                              << ") != ("
                              << (int) c2.red << ',' <<
                              (int) c2.green << ','
                              << (int) c2.blue
                              << ')' << std::endl;
                }
            }
        }
    }
    if (eq) {
        std::cout << "- No differences found!" << std::endl;
    }
    return eq ? 0 : 1;
}
