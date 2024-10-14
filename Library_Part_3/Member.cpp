#include <iostream>
#include <cstring>
using namespace std;

#include "Member.h"

// Default constructor
Member::Member() : memberLoan(nullptr) {}

// Parameterized constructor
Member::Member(const std::string& name, const std::string& memberNumber, const std::string& phoneNumber, Loan& memberLoan)
    : name(name), memberNumber(memberNumber), phoneNumber(phoneNumber), memberLoan(new Loan(memberLoan)) {}

// Copy constructor
Member::Member(const Member& other)
    : name(other.name), memberNumber(other.memberNumber), phoneNumber(other.phoneNumber), memberLoan(new Loan(*other.memberLoan)) {}

// Move constructor
Member::Member(Member&& other) noexcept
    : name(std::move(other.name)), memberNumber(std::move(other.memberNumber)), phoneNumber(std::move(other.phoneNumber)), memberLoan(other.memberLoan)
{
    other.memberLoan = nullptr;
}

// Assignment operator
Member& Member::operator=(const Member& other)
{
    if (this != &other) {
        name = other.name;
        memberNumber = other.memberNumber;
        phoneNumber = other.phoneNumber;

        delete memberLoan;
        memberLoan = new Loan(*other.memberLoan);
    }
    return *this;
}

std::ostream& operator<<(std::ostream& os, const Member& member) {
    os << "Member Name: " << member.getName() << "\n";
    os << "Member Number: " << member.getMemNumber() << "\n";
    os << "Phone Number: " << member.getPhoneNumber() << "\n";
    return os;
}


// Destructor
Member::~Member()
{
    delete memberLoan;
}

// getters
const std::string& Member::getName() const
{
    return name;
}

const std::string& Member::getMemNumber() const
{
    return memberNumber;
}

const std::string& Member::getPhoneNumber() const
{
    return phoneNumber;
}

Loan* Member::getLoanMember() const
{
    return memberLoan;
}

// setters
bool Member::setName(const std::string& name)
{
    if (name.empty())
        return false;

    this->name = name;
    return true;
}

bool Member::setMemNumber(const std::string& memNumber)
{
    if (memNumber.empty())
        return false;

    this->memberNumber = memNumber;
    return true;
}

bool Member::setPhoneNumber(const std::string& phoneNumber)
{
    if (phoneNumber.empty())
        return false;

    this->phoneNumber = phoneNumber;
    return true;
}

void Member::printMember() const
{
    std::cout << "Name: " << name << "\n"
        << "Member Number: " << memberNumber << "\n"
        << "Phone Number: " << phoneNumber << std::endl;
    cout << "Member loan: ";
    if (memberLoan->getNumOfBook() > 0)
        memberLoan->printLoan();
    else
        cout << "Books have not yet been borrowed\n";
}

void Member::update(const std::string& message) {
    std::cout << "Notification for " << name << ": " << message << std::endl;
}