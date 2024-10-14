#include <iostream>
using namespace std;

#include "PhysicalBook.h"

// Parameterized constructor
PhysicalBook::PhysicalBook(const std::string& bookName, const std::string& author, const std::string& ISBN, int publicationYear, int copiesAvailable, const std::string& genre, const std::string& place)
    : Book(bookName, author, ISBN, publicationYear, copiesAvailable, genre), place(place) {}

// Copy constructor
PhysicalBook::PhysicalBook(const PhysicalBook& other) : Book(other), place(other.place) {}

// Move constructor
PhysicalBook::PhysicalBook(PhysicalBook&& other) noexcept : Book(std::move(other)), place(std::move(other.place)) {}

// Assignment operator
PhysicalBook& PhysicalBook::operator=(const PhysicalBook& other)
{
    if (this != &other)
    {
        Book::operator=(other);
        place = other.place;
    }
    return *this;
}

// Destructor
PhysicalBook::~PhysicalBook() {}

// Getters
const std::string& PhysicalBook::getPlace() const
{
    return place;
}

// Setters
bool PhysicalBook::setPlace(const std::string& newPlace)
{
    place = newPlace;
    return true;
}

// Implement the pure virtual function from Book
void PhysicalBook::printBook() const
{
    Book::printBook();
    std::cout << "Book location: " << place << std::endl;
}

PhysicalBook* PhysicalBook::clone() const
{
    return new PhysicalBook(*this);
}
