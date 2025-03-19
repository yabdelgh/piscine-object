#ifndef __HOURLYEMPLOYEE_HPP__
#define __HOURLYEMPLOYEE_HPP__

#include "employee.hpp"
#include "salariedEmployee.hpp"

class TempWorker : public Employee {
    int mobilizedHours;
    int workedHours;
public:
    TempWorker(int hourlyValue, int mobilizedHours) 
        : Employee(hourlyValue), mobilizedHours(mobilizedHours), workedHours(0) {}
    
    virtual int executeWorkday() {
        int hours = std::min(7, mobilizedHours);
        workedHours += hours;
        mobilizedHours -= hours;
        return hours;
    }
    
    virtual int calculatePay() const {
        return workedHours * hourlyValue;
    }
};

class Apprentice : public ContractEmployee {
    int schoolHours;
public:
    Apprentice(int hourlyValue) 
        : ContractEmployee(hourlyValue), schoolHours(0) {}
    
    virtual int calculatePay() const {
        int contractPay = ContractEmployee::calculatePay();
        int schoolPay = schoolHours * hourlyValue / 2;
        return contractPay - schoolPay;
    }
    
    void attendSchool(int hours) {
        schoolHours += hours;
    }
};

#endif