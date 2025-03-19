#ifndef __SALARIEDEMPLOYEE_HPP__
#define __SALARIEDEMPLOYEE_HPP__

#include "employee.hpp"

class ContractEmployee : public Employee {
protected:
    int workdays;
    int absenceHours;
public:
    ContractEmployee(int hourlyValue) 
        : Employee(hourlyValue), workdays(0), absenceHours(0) {}
    
    virtual int executeWorkday() {
        workdays++;
        return 7;
    }
    
    virtual int calculatePay() const {
        return (workdays * 7 - absenceHours) * hourlyValue;
    }
    
    void addAbsence(int hours) {
        absenceHours += hours;
    }
};

#endif
