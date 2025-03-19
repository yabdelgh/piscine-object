#include <iostream>
#include <vector>
#include "Shape.hpp"
#include "Rectangle.hpp"
#include "Triangle.hpp"
#include "Circle.hpp"

int main() {
    std::vector<Shape*> shapes;
    
    shapes.push_back(new Rectangle(4, 5));
    shapes.push_back(new Triangle(3, 4, 5));
    shapes.push_back(new Circle(2.5));

    // Process all shapes uniformly
    for(size_t i = 0; i < shapes.size(); ++i) {
        std::cout << "Shape " << i+1 << ":\n";
        std::cout << "Area: " << shapes[i]->area() << "\n";
        std::cout << "Perimeter: " << shapes[i]->perimeter() << "\n\n";
        delete shapes[i];
    }

    return 0;
}