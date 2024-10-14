#ifndef MEMBEREMPLOYEE_H
#define MEMBEREMPLOYEE_H

#include "Member.h"
#include "Employee.h"

class MemberEmployee : public Member, public Employee {

private:
    int numberOfBenefits;

public:
    MemberEmployee(); // Default constructor
    MemberEmployee(const std::string& name, const Member& member, const Employee& employee, int numberOfBenefits);
    MemberEmployee(const MemberEmployee& other);
    MemberEmployee(MemberEmployee&& other) noexcept;
    MemberEmployee& operator=(const MemberEmployee& other);
    friend std::ostream& operator<<(std::ostream& os, const MemberEmployee& memberEmployee);

    // getters
    int getNumberOfBenefits() const;

    // setters
    bool setNumberOfBenefits(int numberOfBenefits);

    void printMemberEmployee() const;
};

#endif // MEMBEREMPLOYEE_H
