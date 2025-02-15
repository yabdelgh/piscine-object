#ifndef GRAPH_HPP
#define GRAPH_HPP

#include <vector>

struct Vector2 {
    float x;
    float y;

    Vector2(float x = 0, float y = 0);
};

class Graph {
    private:
        Vector2 size;
        std::vector<Vector2 *> vector;
    
        int min();
        int max();
        bool exist(int x, int y);
    
    public:
        void addPoint(float x, float y);
        void printGrid();
};

#endif // GRAPH_HPP
