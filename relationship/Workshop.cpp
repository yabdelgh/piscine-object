#include "Workshop.hpp"
#include "Worker.hpp"
#include <algorithm>
#include <iostream>

Workshop::Workshop() {
    std::cout << "Workshop constructed\n";
}

Workshop::~Workshop() {
    std::cout << "Workshop destroyed\n";
    for (std::vector<Worker*>::const_iterator it = workers.begin(); it != workers.end(); ++it) {
    // for (auto* worker : workers) {
        (*it)->leaveWorkshop(this);
    }
}

void Workshop::registerWorker(Worker* worker) {
    if (std::find(workers.begin(), workers.end(), worker) == workers.end()) {
        workers.push_back(worker);
    }
}

void Workshop::releaseWorker(Worker* worker) {
    auto it = std::find(workers.begin(), workers.end(), worker);
    if (it != workers.end()) {
        workers.erase(it);
    }
}

void Workshop::executeWorkDay() {
    
    for (std::vector<Worker*>::const_iterator it = workers.begin(); it != workers.end(); ++it) {
    // for (Worker* worker : workers) {
        (*it)->work();
    }
}