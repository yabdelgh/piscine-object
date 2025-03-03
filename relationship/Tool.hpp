#ifndef TOOL_HPP
#define TOOL_HPP

class Worker;

class Tool {
public:
    Tool();
    virtual ~Tool();
    virtual void use() = 0;
    virtual Worker* getOwner() const = 0;
    virtual void setOwner(Worker* owner) = 0;
};

#endif