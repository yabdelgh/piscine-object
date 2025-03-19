#ifndef __EMPLOYEE_HPP__
#define __EMPLOYEE_HPP__

#include <iostream>
#include <vector>
#include <algorithm>

class Employee {
protected:
    int hourlyValue;
public:
    Employee(int hourlyValue) : hourlyValue(hourlyValue) {}
    virtual ~Employee() {}
    virtual int executeWorkday() = 0;
    virtual int calculatePay() const = 0;
};

#endif