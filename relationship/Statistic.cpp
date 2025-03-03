#include "Statistic.hpp"
#include <iostream>

Statistic::Statistic() : level(1), exp(0) {
    std::cout << "Statistic constructed\n";
}

Statistic::~Statistic() {
    std::cout << "Statistic destroyed\n";
}