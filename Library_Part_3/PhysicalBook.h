#ifndef PHYSICALBOOK_H
#define PHYSICALBOOK_H

#include "Book.h"
#include <string>

class PhysicalBook : public Book {

private:
    std::string place;

public:
    PhysicalBook(const std::string& bookName, const std::string& author, const std::string& ISBN, int publicationYear, int copiesAvailable, const std::string& genre, const std::string& place);
    PhysicalBook(const PhysicalBook& other);
    PhysicalBook(PhysicalBook&& other) noexcept;
    PhysicalBook& operator=(const PhysicalBook& other);
    virtual ~PhysicalBook();

    // Getters
    const std::string& getPlace() const;

    // Setters
    bool setPlace(const std::string& place);

    void printBook() const override;

    // Override clone method
    virtual PhysicalBook* clone() const override;
};

#endif // PHYSICALBOOK_H
