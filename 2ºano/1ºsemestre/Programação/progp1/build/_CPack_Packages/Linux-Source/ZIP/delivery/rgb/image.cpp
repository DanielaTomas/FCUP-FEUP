#include <rgb/image.hpp>

namespace rgb {
    image::image(int w, int h, const color& fill) {
        assert(w > 0 && h > 0);
        iwidth = w;
        iheight = h;
        pixels = new color*[iwidth];
        color *data = new color[iwidth * iheight];

        for(int i = 0; i < iwidth; i++) {
            pixels[i] = data + i * iheight;
            for(int j = 0; j < iheight; j++)
                pixels[i][j] = fill;
        }
    }
    image::~image() {
       delete[] pixels[0];
       delete[] pixels;
    }
    int image::width() const {
        return iwidth;
    }
    int image::height() const {
        return iheight;
    }
    color& image::at(int x, int y) {
        return pixels[x][y];
    }
    const color& image::at(int x, int y) const {
        return pixels[x][y];
    }
    void image::invert() {
        for (int i = 0; i < iwidth; i++) {
            for (int j = 0; j < iheight; j++)
                pixels[i][j].invert();
        }
    }
    void image::to_gray_scale() {
        for (int i = 0; i < iwidth; i++) {
            for (int j = 0; j < iheight; j++)
                pixels[i][j].to_gray_scale();
        }
    }
    void image::fill(int x, int y, int w, int h, const color& c) {
        for (int i = x; i < x + w; i++) {
            for (int j = y; j < y + h; j++)
                  pixels[i][j] = c;
        }
    }
    void image::replace(const color& a, const color& b) {
        for (int i = 0; i < iwidth; i++) {
            for (int j = 0; j < iheight; j++) {
                if (pixels[i][j] == a) {
                    pixels[i][j] = b;
                }
            }
        }
    }
    void image::add(const image& img, const color& neutral, int x, int y) {
        for (int i = 0; i < img.width(); i++) {
            for (int j = 0; j < img.height(); j++)
                if(img.pixels[i][j] != neutral)
                    pixels[i+x][j+y] = img.pixels[i][j];
        }
    }
    void image::crop(int x, int y, int w, int h) {
        for (int i1 = 0, i2 = x; i2 < iwidth; i1++, i2++) {
            for (int j1 = 0, j2 = y; j2 < iheight; j1++, j2++) {
                pixels[i1][j1] = pixels[i2][j2];
            }
        }
        iwidth = w;
        iheight = h;
    }
    void image::rotate_left() {
        color **new_pixels = new color*[iheight];
        color *data1 = new color[iwidth * iheight];

        for(int i = 0; i < iheight; i++)
            new_pixels[i] = data1 + i * iwidth;

        for(int i = 0; i < iwidth; i++)
            for (int j = 0; j < iheight; j++)
                new_pixels[j][iwidth - i - 1] = pixels[i][j];

        int tmp = iwidth;
        iwidth = iheight;
        iheight = tmp;

        delete[] pixels[0];
        delete[] pixels;

        pixels = new color*[iwidth];
        color *data2 = new color[iwidth * iheight];
        for(int i = 0; i < iwidth; i++) {
            pixels[i] = data2 + i * iheight;
            for(int j = 0; j < iheight; j++)
                pixels[i][j] = new_pixels[i][j];
        }

        delete[] new_pixels[0];
        delete[] new_pixels;
    }
    void image::rotate_right() {
        color **new_pixels = new color*[iheight];
        color *data1 = new color[iwidth * iheight];

        for(int i = 0; i < iheight; i++)
            new_pixels[i] = data1 + i * iwidth;

        for(int i = 0; i < iwidth; i++)
            for (int j = 0; j < iheight; j++)
                new_pixels[iheight - j - 1][i] = pixels[i][j];

        int tmp = iwidth;
        iwidth = iheight;
        iheight = tmp;

        delete[] pixels[0];
        delete[] pixels;

        pixels = new color*[iwidth];
        color *data2 = new color[iwidth * iheight];
        for(int i = 0; i < iwidth; i++) {
            pixels[i] = data2 + i * iheight;
            for(int j = 0; j < iheight; j++)
                pixels[i][j] = new_pixels[i][j];
        }

        delete[] new_pixels[0];
        delete[] new_pixels;
    }
    void image::mix(const image& img, int factor) {
        for (int i = 0; i < iwidth; i++) {
            for (int j = 0; j < iheight; j++)
                pixels[i][j].mix(img.pixels[i][j],factor);
        }
    }
}
