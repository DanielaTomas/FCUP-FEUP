#include <iostream>
#include <svg/svg.hpp>

void convert(const std::string& svg_file, const std::string& png_file) {
    std::cout << "- Processing " << svg_file << " ..."  << std::endl;
    svg::svg_to_png(svg_file, png_file);
    std::cout << "- Generated " << png_file << std::endl;
}

int main(int argc, char** argv) {
    if (argc < 3) {
        std::cout << "Usage:" << std::endl
                  << "  convert svg_file png_file" << std::endl
                  << "or" << std::endl
                  << "  convert output_dir svg_file1 ... svg_filen"
                  << std::endl;
        return 1;
    }
    if (argc == 3) {
        convert(argv[1], argv[2]);
    } else {
        --argc; ++argv;
        std::string output_dir(argv[0]);
        while(--argc) {
            ++argv;
            std::string svg_file(*argv);
            std::string png_file;
            size_t pos1 = svg_file.rfind('/');
            if (pos1 == std::string::npos) {
                pos1 = 0;
            } else {
                pos1++;
            }
            size_t pos2 = svg_file.rfind(".svg");
            if (pos2 == std::string::npos) {
                pos2 = svg_file.length();
            }

            png_file = output_dir
                    + "/"
                    + svg_file.substr(pos1).substr(0,pos2-pos1)
                    + ".png";
            convert(svg_file, png_file);
        }
    }
    return 0;
}