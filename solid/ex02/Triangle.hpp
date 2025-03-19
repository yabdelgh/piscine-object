#ifndef TRIANGLE_HPP
#define TRIANGLE_HPP

#include "Shape.hpp"
#include <cmath>

class Triangle : public Shape {
    double a, b, c;
    
public:
    Triangle(double s1, double s2, double s3) : a(s1), b(s2), c(s3) {}
    
    virtual double area() const {
        double s = (a + b + c) / 2;
        return std::sqrt(s * (s - a) * (s - b) * (s - c));
    }
    
    virtual double perimeter() const {
        return a + b + c;
    }
};

#endif