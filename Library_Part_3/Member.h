#ifndef MEMBER_H
#define MEMBER_H

#include "Loan.h"
#include "NotificationObserver.h"
#include <string>


class Member : public NotificationObserver {

protected:
    std::string name;
    std::string memberNumber;
    std::string phoneNumber;
    Loan* memberLoan;

public:
    Member(); // Default constructor
    Member(const std::string& name, const std::string& memberNumber, const std::string& phoneNumber, Loan& memberLoan);
    Member(const Member& other);
    Member(Member&& other) noexcept;
    Member& operator=(const Member& other);
    friend std::ostream& operator<<(std::ostream& os, const Member& member);
    virtual ~Member();

    // getters
    const std::string& getName() const;
    const std::string& getMemNumber() const;
    const std::string& getPhoneNumber() const;
    Loan* getLoanMember() const;

    // setters
    bool setName(const std::string& name);
    bool setMemNumber(const std::string& memNumber);
    bool setPhoneNumber(const std::string& phoneNumber);

    void printMember() const;

    void update(const std::string& message) override;
};

#endif // MEMBER_H
