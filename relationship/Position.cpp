#include "Position.hpp"
#include <iostream>

Position::Position() : x(0), y(0), z(0) {
    std::cout << "Position constructed\n";
}

Position::~Position() {
    std::cout << "Position destroyed\n";
}