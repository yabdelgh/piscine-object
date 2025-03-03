#ifndef WORKER_HPP
#define WORKER_HPP

#include <vector>
#include "Position.hpp"
#include "Statistic.hpp"
#include "Tool.hpp"

class Workshop;

class Worker {
private:
    Position coordonnee;
    Statistic stat;
    std::vector<Tool*> tools;
    std::vector<Workshop*> workshops;

public:
    Worker();
    ~Worker();

    void addTool(Tool* tool);
    void removeTool(Tool* tool);
    void work() const;

    void registerWorkshop(Workshop* workshop);
    void leaveWorkshop(Workshop* workshop);

    // template <typename T>
    // T* getTool();
};

#endif