#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

#include "Shape.hpp"

class Rectangle : public Shape {
    double width;
    double height;
    
public:
    Rectangle(double w, double h) : width(w), height(h) {}
    
    virtual double area() const {
        return width * height;
    }
    
    virtual double perimeter() const {
        return 2 * (width + height);
    }
};

#endif