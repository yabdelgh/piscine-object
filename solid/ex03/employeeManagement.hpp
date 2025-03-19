#ifndef __EMPLOYEEMANAGEMENT_HPP__
#define __EMPLOYEEMANAGEMENT_HPP__

#include "employee.hpp"

class EmployeeManager {
    std::vector<Employee*> employees;
public:
    void addEmployee(Employee* emp) {
        employees.push_back(emp);
    }
    
    void removeEmployee(Employee* emp) {
        std::vector<Employee*>::iterator it = std::find(employees.begin(), employees.end(), emp);
        if (it != employees.end()) {
            employees.erase(it);
        }
    }
    
    void executeWorkday() {
        for (std::vector<Employee*>::iterator it = employees.begin(); it != employees.end(); ++it) {
            (*it)->executeWorkday();
        }
    }
    
    void calculatePayroll() {
        for (std::vector<Employee*>::iterator it = employees.begin(); it != employees.end(); ++it) {
            std::cout << "Payroll: " << (*it)->calculatePay() << std::endl;
        }
    }
};

#endif
