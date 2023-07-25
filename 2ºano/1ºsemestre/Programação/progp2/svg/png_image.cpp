#include "png_image.hpp"

#include <stdexcept>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <cassert>

#define STBI_ONLY_PNG
#define STB_IMAGE_IMPLEMENTATION
#include <stb_image.h>
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include <stb_image_write.h>

namespace svg {
    png_image::png_image(const std::string& png_file_name) {
        int dummy;
        pixels = (color*) stbi_load(png_file_name.c_str(),
                                    &png_width, &png_height,
                                    &dummy, 3);
        if (pixels == NULL) {
            throw std::runtime_error(png_file_name + ": could not load image!");
        }
    }
    png_image::png_image(int w, int h) {
        assert(w > 0 && h > 0);
        size_t sz = w * h * sizeof(color);
        pixels = (color*) stbi__malloc(sz);
        png_width = w;
        png_height = h;
        ::memset(pixels, 0xFF, sz);
    }
    void png_image::save(const std::string& png_file_name) const {
        stbi_write_png(png_file_name.c_str(),
                       png_width,
                       png_height,
                       3,
                       pixels,
                       png_width * 3);
    }

    png_image::~png_image() {
        stbi_image_free(pixels);
    }

    int png_image::width() const {
        return png_width;
    }
    int png_image::height() const {
        return png_height;
    }
    color& png_image::at(int x, int y) {
        assert(x >= 0 && x < png_width);
        assert(y >= 0 && y < png_height);
        return pixels[y * png_width + x];
    }
    const color& png_image::at(int x, int y) const {
        assert(x >= 0 && x < png_width);
        assert(y >= 0 && y < png_height);
        return pixels[y * png_width + x];
    }
    void png_image::draw_line(const point& a, const point& b, const color& c) {
        //  Bresenham Algorithm.
        int x_from = a.x;
        int y_from = a.y;
        int x_to = b.x;
        int y_to = b.y;
        int dy = y_to - y_from;
        int dx = x_to - x_from;
        int step_x = 1, step_y = 1;
        if (dy < 0) {
            dy = -dy;
            step_y = -1;
        }
        if (dx < 0) {
            dx = -dx;
            step_x = -1;
        }
        dy *= 2;
        dx *= 2;
        at(x_from, y_from) = c;
        if (dx > dy) {
            int fraction = dy - (dx / 2);
            while (x_from != x_to) {
                if (fraction >= 0) {
                    y_from += step_y;
                    fraction -= dx;
                }
                x_from += step_x;
                fraction += dy;
                at(x_from, y_from) = c;
            }
        } else {
            int fraction = dx - (dy >> 1);
            while (y_from != y_to) {
                if (fraction >= 0) {
                    x_from += step_x;
                    fraction -= dy;
                }
                y_from += step_y;
                fraction += dx;
                at(x_from, y_from) = c;
            }
        }
    }

    void png_image::draw_polygon(const std::vector<point>& points, const color& c) {
        int x_min = width(), x_max = 0, y_min = height(), y_max = 0;
        for (auto& p : points) {
            x_min = std::min(x_min, p.x);
            x_max = std::max(x_max, p.x);
            y_min = std::min(y_min, p.y);
            y_max = std::max(y_max, p.y);
        }

        std::vector<double> seg;
        for (int y = y_min; y < y_max; y++) {
            for (auto i = 0U; i < points.size(); i++) {
                point a = points[i];
                point b = points[(i + 1) % points.size()];
                if (y < std::min(a.y, b.y) || y > std::max(a.y, b.y)) {
                    continue;
                }
                if (a.y != b.y) {
                    double x_inters = (double) (y - a.y) * (b.x - a.x) / (double) (b.y - a.y) + a.x;
                    seg.push_back(x_inters);
                }
            }
            std::sort(seg.begin(), seg.end());
            size_t i_s = 0;
            while ((i_s+1) < seg.size()) {
                point a = {(int) round(seg.at(i_s)), y };
                point b = {(int) round(seg.at(i_s + 1)), y };
                if (a.x == b.x) {
                    i_s ++;

                } else {
                    draw_line(a, b, c);
                    i_s += 2;
                }
            }
            seg.clear();
        }
        for (auto i = 0U; i < points.size(); i++) {
            draw_line(points[i], points[(i+1) % points.size()], c);
        }
    }

    void png_image::draw_ellipse
    (const point& center, const point& radius, const color& fill) {
        draw_line(center.translate({-radius.x, 0}),
                  center.translate({+radius.x, 0}),
                  fill);
        int x0 = radius.x;
        int dx = 0;
        for (int y = 1; y <= radius.y; y++) {
            double vy = (double) y / (double) radius.y;
            vy *= vy;
            int x1 = x0 - (dx - 1);
            for (; x1 > 0; x1--) {
                double vx = (double) x1 / (double) radius.x;
                vx *= vx;
                if (vx + vy <= 1) {
                    break;
                }
            }
            dx = x0 - x1;
            x0 = x1;

            draw_line(center.translate({-x0, -y}),
                      center.translate({+x0, -y}),
                      fill);
            draw_line(center.translate({-x0, +y}),
                      center.translate({+x0, +y}),
                      fill);
        }
    }

}
