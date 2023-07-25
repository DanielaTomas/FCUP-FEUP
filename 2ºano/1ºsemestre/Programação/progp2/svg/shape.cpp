#include "shape.hpp"
#include <stdexcept>
namespace svg {

    void not_implemented(const std::string& f) {
        throw std::runtime_error(f + ": not implemented!");
    }

    // Base class for shapes.
    shape::shape(const color &c) : s_color(c) {

    }

    shape::~shape() {

    }
    const color &shape::get_color() const {
        return s_color;
    }
    void shape::draw(png_image &img) const {
        not_implemented("draw");
    }
    void shape::translate(const point &c) {
        not_implemented("translate");
    }
    void shape::scale(const point &origin, int v) {
        not_implemented("scale");
    }
    void shape::rotate(const point &origin, int v) {
        not_implemented("rotate");
    }
    shape* shape::duplicate() const {
        not_implemented("duplicate");
        return NULL;
    }
}