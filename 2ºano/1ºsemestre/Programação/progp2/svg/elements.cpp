#include "elements.hpp"
namespace svg {
    ellipse::ellipse(const svg::color &fill,
                     const point &center,
                     const point &radius) :
            shape(fill), center(center), radius(radius) {
    }
    void ellipse::draw(png_image &img) const {
        img.draw_ellipse(center, radius, get_color());
    }
    void ellipse::translate(const point &t) {
        center = center.translate(t);
    }
    void ellipse::scale(const point &origin, int v) {
        radius.x *= v;
        radius.y *= v;
        center = center.scale(origin,v);
    }
    void ellipse::rotate(const point &origin, int degrees) {
        center = center.rotate(origin, degrees);
    }
    shape *ellipse::duplicate() const {
        return new ellipse(get_color(), center, radius);
    }
//--------------------------
    circle::circle(const svg::color &fill,
                    const point &center,
                    const point &radius) :
            ellipse(fill,center,radius) {
    }
//--------------------------
    polyline::polyline(const svg::color &stroke,
                       const std::vector<point>& points) :
            shape(stroke), points(points) {
    }
    void polyline::draw(png_image &img) const {
        for(int i = 0; i < points.size()-1; i++)
            img.draw_line(points[i], points[i + 1], get_color());
    }
    void polyline::translate(const point &t) {
        for(point& point : points)
            point = point.translate(t);
    }
    void polyline::scale(const point &origin, int v) {
        for(point& point : points)
            point = point.scale(origin,v);
    }
    void polyline::rotate(const point &origin, int degrees) {
        for(point& point : points)
            point = point.rotate(origin,degrees);
    }
    shape *polyline::duplicate() const {
        return new polyline(get_color(), points);
    }
//--------------------------
    line::line(const svg::color &stroke,
               const std::vector<point>& points) :
            polyline(stroke, points) {
    }
//--------------------------
    polygon::polygon(const svg::color &fill,
                       const std::vector<point>& points) :
            shape(fill), points(points) {
    }
    void polygon::draw(png_image &img) const {
         img.draw_polygon(points,get_color());
    }
    void polygon::translate(const point &t) {
        for(point& point : points)
            point = point.translate(t);
    }
    void polygon::scale(const point &origin, int v) {
        for(point& point : points)
            point = point.scale(origin,v);
    }
    void polygon::rotate(const point &origin, int degrees) {
        for(point& point : points)
            point = point.rotate(origin,degrees);
    }
    shape *polygon::duplicate() const {
        return new polygon(get_color(), points);
    }
//--------------------------
    rect::rect(const svg::color &fill,
               const point point, int width, int height) :
            polygon(fill, {point,{point.x + width-1,point.y},{point.x + width-1,point.y + height-1},{point.x,point.y + height-1}}) {
    }
//--------------------------
    group::group(const std::vector<shape*>& shapes) :
            shape({0,0,0}), shapes(shapes) {
    }
    void group::draw(png_image &img) const {
        for(auto shape : shapes)
            shape->draw(img);
    }
    void group::translate(const point &t) {
         for(auto shape : shapes) {
             shape->translate(t);
         }
    }
    void group::scale(const point &origin, int v) {
        for(auto shape : shapes)
            shape->scale(origin,v);
    }
    void group::rotate(const point &origin, int degrees) {
        for(auto shape : shapes)
            shape->rotate(origin,degrees);
    }
    shape *group::duplicate() const {
        std::vector<shape*> duplicateShape;
        for(auto shape : shapes)
            duplicateShape.push_back(shape->duplicate());
        return new group(duplicateShape);
    }
    group::~group() {
        for (auto shape : shapes)
            delete shape;
    }
}