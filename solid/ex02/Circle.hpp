#ifndef CIRCLE_HPP
#define CIRCLE_HPP

#include "Shape.hpp"

class Circle : public Shape {
    double radius;
    
public:
    Circle(double r) : radius(r) {}
    
    virtual double area() const {
        return 3.14159 * radius * radius;
    }
    
    virtual double perimeter() const {
        return 2 * 3.14159 * radius;
    }
};

#endif