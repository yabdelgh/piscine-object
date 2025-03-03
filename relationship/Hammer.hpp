#ifndef HAMMER_HPP
#define HAMMER_HPP

#include "Tool.hpp"

class Worker;

class Hammer : public Tool {
private:
    int numberOfUses;
    Worker* owner;

public:
    Hammer();
    virtual ~Hammer();

    void use();
    Worker* getOwner() const;
    void setOwner(Worker* owner);
};

#endif