#ifndef SHOVEL_HPP
#define SHOVEL_HPP

#include "Tool.hpp"

class Worker;

class Shovel : public Tool {
private:
    int numberOfUses;
    Worker* owner;

public:
    Shovel();
    virtual ~Shovel();

    void use();
    Worker* getOwner() const;
    void setOwner(Worker* owner);
};

#endif