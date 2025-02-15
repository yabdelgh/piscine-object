#include <iostream>
#include <vector>
#include <iomanip>  // For std::setw and std::setfill

struct Vector2
{
    float x;
    float y;

    Vector2(float x = 0, float y = 0): x(x), y(y) {}
};

class Graph
{
    private:
    Vector2 size;
    std::vector<Vector2 *> vector;
    
    int min()
    {
        int min = 0;
        for (Vector2 *v: vector)
        {
            if (v->x < min)
                min = v->x;
            else if (v->y < min)
                min = v->y;
        }
        return min;
    }

    int max()
    {
        int max = 0;
        for (Vector2 *v: vector)
        {
            if (v->x > max)
                max = v->x;
            else if (v->y > max)
                max = v->y;
        }
        return max;
    }
    
    bool exist(const int x, const int y)
    {
        for (Vector2 *v: vector)
            if (v->x == x && v->y == y)
                return true;
        return false;
    }

    public:

    void addPoint(float x, float y)
    {
        Vector2 *vector2 = new Vector2(x, y);
        size.x = size.x < x ? x : size.x;
        size.y = size.y < y ? y : size.y;
        vector.push_back(vector2);
    }

    
    void printGrid() {
        for (int i = max(); i >=  min() ; i--)
        {
            std::cout << std::setw(5) << i;
            for (int j = min(); j <=  max() ; j++)
            {   
                if (exist(i, j))
                    std::cout << std::setw(5) << "X";
                else
                    std::cout << std::setw(5) << ".";
            }
            std::cout << std::endl;
        }
        std::cout << std::setw(5) << " ";
        for (int i = min(); i <= max(); i++)
        {
            std::cout << std::setw(5) << i;
        }
    }
};

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