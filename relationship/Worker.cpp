#include "Worker.hpp"
#include "Workshop.hpp"
#include <algorithm>
#include <iostream>

Worker::Worker() {
    std::cout << "Worker constructed\n";
}

Worker::~Worker() {
    std::cout << "Worker destroyed\n";
    for (std::vector<Workshop*>::const_iterator it = workshops.begin(); it != workshops.end(); ++it) {
    // for (auto* workshop : workshops) {
        (*it)->releaseWorker(this);
    }
}

void Worker::addTool(Tool* tool) {
    if (std::find(tools.begin(), tools.end(), tool) == tools.end()) {
        tools.push_back(tool);
    }
}

// void Worker::removeTool(Tool* tool) {
//     tools.erase(std::remove(tools.begin(), tools.end(), tool), tools.end());
// }

void Worker::removeTool(Tool* tool) {
    auto it = std::find(tools.begin(), tools.end(), tool);
    if (it != tools.end()) {
        tools.erase(it);
    }
}

void Worker::work() const {
    std::cout << "Worker starts working.\n";
    for (std::vector<Tool*>::const_iterator it = tools.begin(); it != tools.end(); ++it) {
    // for (Tool* tool : tools) {
        (*it)->use();
    }
}

void Worker::registerWorkshop(Workshop* workshop) {
    if (std::find(workshops.begin(), workshops.end(), workshop) == workshops.end()) {
        workshops.push_back(workshop);
        workshop->registerWorker(this);
    }
}

// void Worker::leaveWorkshop(Workshop* workshop) {
//     workshops.erase(std::remove(workshops.begin(), workshops.end(), workshop), workshops.end());
//     workshop->releaseWorker(this);
// }
void Worker::leaveWorkshop(Workshop* workshop) {
    std::vector<Workshop*>::iterator it = std::find(workshops.begin(), workshops.end(), workshop);
    if (it != workshops.end()) {
        workshops.erase(it);
    }
    workshop->releaseWorker(this);
}


// template <typename T>
// T* Worker::getTool() {
//     for (std::vector<Tool*>::const_iterator it = tools.begin(); it != tools.end(); ++it) {
//     // for (Tool* tool : tools) {
//         T* t = dynamic_cast<T*>(*it);
//         if (t) return t;
//     }
//     return NULL;
// }