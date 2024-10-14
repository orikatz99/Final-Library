#include <iostream>
#include <cstring>
using namespace std;

#include "MemberEmployee.h"

// Default constructor
MemberEmployee::MemberEmployee() : Member(), Employee(), numberOfBenefits(0) {}

// Parameterized constructor
MemberEmployee::MemberEmployee(const std::string& name, const Member& member, const Employee& employee, int numberOfBenefits)
    : Member(name, member.getMemNumber(), member.getPhoneNumber(), *member.getLoanMember()),
    Employee(name, employee.getEmpNumber()),
    numberOfBenefits(numberOfBenefits) {}

// Copy constructor
MemberEmployee::MemberEmployee(const MemberEmployee& other)
    : Member(other), Employee(other), numberOfBenefits(other.numberOfBenefits) {}

// Move constructor
MemberEmployee::MemberEmployee(MemberEmployee&& other) noexcept
    : Member(std::move(other)), Employee(std::move(other)), numberOfBenefits(other.numberOfBenefits) {}

// Assignment operator
MemberEmployee& MemberEmployee::operator=(const MemberEmployee& other)
{
    if (this != &other) {
        // Assign base class parts
        Member::operator=(other);
        Employee::operator=(other);

        // Assign derived class part
        numberOfBenefits = other.numberOfBenefits;
    }
    return *this;
}

std::ostream& operator<<(std::ostream& os, const MemberEmployee& memberEmployee) 
{
    os << static_cast<const Member&>(memberEmployee); // Print Member part
    os << static_cast<const Employee&>(memberEmployee); // Print Employee part
    os << "Number of Benefits: " << memberEmployee.getNumberOfBenefits() << "\n";
    return os;
}


// Getters
int MemberEmployee::getNumberOfBenefits() const
{
    return numberOfBenefits;
}

// Setters
bool MemberEmployee::setNumberOfBenefits(int numberOfBenefits)
{
    if (numberOfBenefits < 0)
        return false;

    this->numberOfBenefits = numberOfBenefits;
    return true;
}

// Print MemberEmployee details
void MemberEmployee::printMemberEmployee() const
{
    Member::printMember();
    Employee::printEmployee();
    std::cout << "Number of Benefits: " << numberOfBenefits << std::endl;
}
