#include "graph.hpp"
#include <iostream>
#include <iomanip>

Vector2::Vector2(float x, float y): x(x), y(y) {}

// Private method: returns the minimum value between all points in the vector
int Graph::min() {
    int min = 0;
    for (Vector2 *v: vector) {
        if (v->x < min) min = v->x;
        if (v->y < min) min = v->y;
    }
    return min;
}

// Private method: returns the maximum value between all points in the vector
int Graph::max() {
    int max = 0;
    for (Vector2 *v: vector) {
        if (v->x > max) max = v->x;
        if (v->y > max) max = v->y;
    }
    return max;
}

// Private method: check if the point (x, y) already exists in the vector
bool Graph::exist(int x, int y) {
    for (Vector2 *v: vector)
        if (v->x == x && v->y == y)
            return true;
    return false;
}

// Public method: adds a new point to the graph
void Graph::addPoint(float x, float y) {
    Vector2 *vector2 = new Vector2(x, y);
    size.x = size.x < x ? x : size.x;
    size.y = size.y < y ? y : size.y;
    vector.push_back(vector2);
}

// Public method: prints the grid representation of the graph
void Graph::printGrid() {
    for (int i = max(); i >= min(); i--) {
        std::cout << std::setw(5) << i;
        for (int j = min(); j <= max(); j++) {
            if (exist(i, j))
                std::cout << std::setw(5) << "X";
            else
                std::cout << std::setw(5) << ".";
        }
        std::cout << std::endl;
    }
    std::cout << std::setw(5) << " ";
    for (int i = min(); i <= max(); i++) {
        std::cout << std::setw(5) << i;
    }
}
