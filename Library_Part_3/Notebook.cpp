#include <iostream>
using namespace std;

#include "Notebook.h"

// Parameterized constructor
Notebook::Notebook(const std::string& bookName, const std::string& author, const std::string& ISBN, int publicationYear, int copiesAvailable, const std::string& genre, const std::string& type)
    : Book(bookName, author, ISBN, publicationYear, copiesAvailable, genre), type(type) {}

// Copy constructor
Notebook::Notebook(const Notebook& other) : Book(other), type(other.type) {}

// Move constructor
Notebook::Notebook(Notebook&& other) noexcept : Book(std::move(other)), type(std::move(other.type)) {}

// Assignment operator
Notebook& Notebook::operator=(const Notebook& other)
{
    if (this != &other)
    {
        Book::operator=(other);
        type = other.type;
    }
    return *this;
}

// Destructor
Notebook::~Notebook() {}

// Getters
const std::string& Notebook::getType() const
{
    return type;
}

// Setters
bool Notebook::setType(const std::string& newType)
{
    type = newType;
    return true;
}

// Implement the pure virtual function from Book
void Notebook::printBook() const
{
    Book::printBook();
    std::cout << "Type: " << type << std::endl;
}

Notebook* Notebook::clone() const
{
    return new Notebook(*this);
}
