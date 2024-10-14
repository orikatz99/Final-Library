#include <iostream>
#include <cstring>
using namespace std;

#include "Employee.h"

// Parameterized constructor
Employee::Employee(const std::string& name, const std::string& employeeNumber)
    : name(name), employeeNumber(employeeNumber) {}

// Copy constructor
Employee::Employee(const Employee& other)
    : name(other.name), employeeNumber(other.employeeNumber) {}

// Move constructor
Employee::Employee(Employee&& other) noexcept
    : name(std::move(other.name)), employeeNumber(std::move(other.employeeNumber)) {}

// Assignment operator
Employee& Employee::operator=(const Employee& other)
{
    if (this != &other) {
        name = other.name;
        employeeNumber = other.employeeNumber;
    }
    return *this;
}

std::ostream& operator<<(std::ostream& os, const Employee& employee) 
{
    os << "Employee Name: " << employee.getName() << "\n";
    os << "Employee Number: " << employee.getEmpNumber() << "\n";
    return os;
}

// Getters
const std::string& Employee::getName() const
{
    return name;
}

const std::string& Employee::getEmpNumber() const
{
    return employeeNumber;
}

// Setters
bool Employee::setName(const std::string& name)
{
    this->name = name;
    return true;
}

bool Employee::setEmpNumber(const std::string& empNumber)
{
    this->employeeNumber = empNumber;
    return true;
}

// Print Employee details
void Employee::printEmployee() const
{
    std::cout << "Name: " << name << "\n"
        << "Employee Number: " << employeeNumber << std::endl;
}
