#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <string>

class Employee {

protected:
    std::string name;
    std::string employeeNumber;

public:
    Employee() = default; // Default constructor
    Employee(const std::string& name, const std::string& employeeNumber);
    Employee(const Employee& other);
    Employee(Employee&& other) noexcept;
    Employee& operator=(const Employee& other);
    friend std::ostream& operator<<(std::ostream& os, const Employee& employee);
    virtual ~Employee() = default;

    // getters
    const std::string& getName() const;
    const std::string& getEmpNumber() const;

    // setters
    bool setName(const std::string& name);
    bool setEmpNumber(const std::string& empNumber);

    void printEmployee() const;
};

#endif // EMPLOYEE_H
