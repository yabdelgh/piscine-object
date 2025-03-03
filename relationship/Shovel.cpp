#include "Shovel.hpp"
#include "Worker.hpp"
#include <iostream>

Shovel::Shovel() : numberOfUses(10), owner(NULL) {
    std::cout << "Shovel constructed\n";
}

Shovel::~Shovel() {
    std::cout << "Shovel destroyed\n";
}

void Shovel::use() {
    if (numberOfUses <= 0) {
        std::cout << "Shovel is broken.\n";
        return;
    }
    numberOfUses--;
    std::cout << "Using shovel. Remaining uses: " << numberOfUses << std::endl;
}

Worker* Shovel::getOwner() const {
    return owner;
}

void Shovel::setOwner(Worker* newOwner) {
    if (owner == newOwner) return;
    Worker* oldOwner = owner;
    owner = newOwner;
    if (oldOwner)
        oldOwner->removeTool(this);
    if (newOwner)
        newOwner->addTool(this);
}