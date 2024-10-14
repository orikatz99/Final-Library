#include <iostream>
#include "Administrator.h"

// Constructor
Administrator::Administrator(const Employee& employee)
    : Employee(employee), permissionLevel(1), employeeCount(0) {}

// Copy constructor
Administrator::Administrator(const Administrator& other)
    : Employee(other), permissionLevel(other.permissionLevel), employeeList(other.employeeList), employeeCount(other.employeeCount) {}

// Move constructor
Administrator::Administrator(Administrator&& other) noexcept
    : Employee(std::move(other)), permissionLevel(other.permissionLevel), employeeList(std::move(other.employeeList)), employeeCount(other.employeeCount) {
    other.employeeCount = 0;
}

// Assignment operator
Administrator& Administrator::operator=(const Administrator& other)
{
    if (this != &other) {
        Employee::operator=(other);
        permissionLevel = other.permissionLevel;
        employeeList = other.employeeList;
        employeeCount = other.employeeCount;
    }
    return *this;
}

// Destructor
Administrator::~Administrator() = default;

// Getters
int Administrator::getPermissionLevel() const 
{
    return permissionLevel;
}

const std::list<Employee>& Administrator::getEmployeeList() const 
{
    return employeeList;
}

int Administrator::getEmployeeCount() const 
{
    return employeeCount;
}

// Setters
bool Administrator::setPermissionLevel(int permissionLevel)
{
    this->permissionLevel = permissionLevel;
    return true;
}

bool Administrator::setEmployeeList(const std::list<Employee>& newEmployeeList) 
{
    employeeList = newEmployeeList;
    employeeCount = static_cast<int>(newEmployeeList.size());
    return true;
}

bool Administrator::setEmployeeCount(int newEmployeeCount) 
{
    if (newEmployeeCount < 0) {
        return false;
    }
    employeeCount = newEmployeeCount;
    return true;
}

// Print Administrator details
void Administrator::printAdministrator() const 
{
    printEmployee();
    std::cout << "Permission Level: " << permissionLevel << std::endl;
}

// Static method to add an Administrator
Administrator Administrator::addAdministrator(const Employee& employee) 
{
    return Administrator(employee);
}

// Add an employee
void Administrator::addEmployee(const Employee& newEmployee)
{
    for (const auto& employee : employeeList) {
        if (employee.getEmpNumber() == newEmployee.getEmpNumber()) {
            std::cout << "Employee with the same employee number already exists." << std::endl;
            return;
        }
    }
    employeeList.push_back(newEmployee);
    ++employeeCount;
}

// Show all employees
void Administrator::showEmployees() const 
{
    if (employeeCount == 0) {
        std::cout << "\nThere are currently no employees for the library" << std::endl;
    }
    else {
        std::cout << "Our Library has " << employeeCount << " employees:" << std::endl;
        int index = 1;
        for (const auto& employee : employeeList) {
            std::cout << "#" << index++ << std::endl;
            employee.printEmployee();
            std::cout << "\n";
        }
    }
}

// Find an employee by name
Employee* Administrator::findEmployeeByName(const std::string& name) 
{

    for (auto& employee : employeeList) { 
        if (employee.getName() == name) {
            return &employee;
        }
    }
    return nullptr;
}


