#ifndef ADMINISTRATOR_H
#define ADMINISTRATOR_H

#include "Employee.h"
#include <string>
#include <list>

class Administrator : public Employee {

private:
    int permissionLevel;
    std::list<Employee> employeeList; // Using a list to manage the employees
    int employeeCount;

public:
    Administrator(const Employee& employee);
    Administrator(const Administrator& other);
    Administrator(Administrator&& other) noexcept;
    Administrator& operator=(const Administrator& other);
    ~Administrator();

    // Getters
    int getPermissionLevel() const;
    const std::list<Employee>& getEmployeeList() const;
    int getEmployeeCount() const;

    // Setters
    bool setPermissionLevel(int permissionLevel);
    bool setEmployeeList(const std::list<Employee>& newEmployeeList);
    bool setEmployeeCount(int newEmployeeCount);

    void printAdministrator() const;
    static Administrator addAdministrator(const Employee& employee);
    Employee* findEmployeeByName(const std::string& name);

    void addEmployee(const Employee& newEmployee);
    void showEmployees() const;
};

#endif // ADMINISTRATOR_H
