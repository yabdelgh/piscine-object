#include "employeeManagement.hpp"
#include "hourlyEmployee.hpp"
#include "salariedEmployee.hpp"

int main() {
    EmployeeManager manager;

    TempWorker* temp = new TempWorker(10, 20);
    ContractEmployee* contract = new ContractEmployee(20);
    Apprentice* apprentice = new Apprentice(15);

    manager.addEmployee(temp);
    manager.addEmployee(contract);
    manager.addEmployee(apprentice);

    contract->addAbsence(8);
    apprentice->attendSchool(10);

    manager.executeWorkday();
    manager.executeWorkday();
    manager.executeWorkday();

    manager.calculatePayroll();

    delete temp;
    delete contract;
    delete apprentice;

    return 0;
}