#include <iostream>
using namespace std;

#include "Ebook.h"

// Parameterized constructor
Ebook::Ebook(const std::string& bookName, const std::string& author, const std::string& ISBN, int publicationYear, int copiesAvailable, const std::string& genre, double fileSize, const std::string& format)
    : Book(bookName, author, ISBN, publicationYear, copiesAvailable, genre), fileSize(fileSize), format(format) {}

// Copy constructor
Ebook::Ebook(const Ebook& other) : Book(other), fileSize(other.fileSize), format(other.format) {}

// Move constructor
Ebook::Ebook(Ebook&& other) noexcept : Book(std::move(other)), fileSize(other.fileSize), format(std::move(other.format)) {}

// Assignment operator
Ebook& Ebook::operator=(const Ebook& other)
{
    if (this != &other)
    {
        Book::operator=(other);
        fileSize = other.fileSize;
        format = other.format;
    }
    return *this;
}

// Destructor
Ebook::~Ebook() {}

// Getters
double Ebook::getFileSize() const
{
    return fileSize;
}
const std::string& Ebook::getFormat() const
{
    return format;
}

// Setter
bool Ebook::setFormat(const std::string& newFormat)
{
    format = newFormat;
    return true;
}

// Implement the pure virtual function from Book
void Ebook::printBook() const
{
    Book::printBook();
    std::cout << "File Size: " << fileSize << "\n" << "Format: " << format << std::endl;
}

Ebook* Ebook::clone() const
{
    return new Ebook(*this);
}
