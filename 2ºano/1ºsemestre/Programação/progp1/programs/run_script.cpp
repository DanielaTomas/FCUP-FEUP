#include <rgb/rgb.hpp>

int main(int argc, char** argv) {
    for (int i = 1; i < argc; i++) {
        rgb::script s(argv[i]);
        s.process();
    }
    return 0;
}