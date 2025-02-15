#include "graph.hpp"

int main()
{

    Graph graph;

    graph.addPoint(0, 0);
    graph.addPoint(2, 2);
    graph.addPoint(4, 2);
    graph.addPoint(2, 4);
    // graph.addPoint(10, -25);
    // graph.addPoint(-25, 10);
    // graph.addPoint(-2, 4);
    graph.printGrid();
    return 0;
}