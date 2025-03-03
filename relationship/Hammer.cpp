#include "Hammer.hpp"
#include "Worker.hpp"
#include <iostream>

Hammer::Hammer() : numberOfUses(5), owner(NULL) {
    std::cout << "Hammer constructed\n";
}

Hammer::~Hammer() {
    std::cout << "Hammer destroyed\n";
}

void Hammer::use() {
    if (numberOfUses <= 0) {
        std::cout << "Hammer is broken.\n";
        return;
    }
    numberOfUses--;
    std::cout << "Using hammer. Remaining uses: " << numberOfUses << std::endl;
}

Worker* Hammer::getOwner() const {
    return owner;
}

void Hammer::setOwner(Worker* newOwner) {
    if (owner == newOwner) return;
    Worker* oldOwner = owner;
    owner = newOwner;
    if (oldOwner)
        oldOwner->removeTool(this);
    if (newOwner)
        newOwner->addTool(this);
}