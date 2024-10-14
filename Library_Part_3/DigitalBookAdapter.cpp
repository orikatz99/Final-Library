#include "DigitalBookAdapter.h"
#include <iostream>

// Constructor
DigitalBookAdapter::DigitalBookAdapter(ExternalDigitalBook* externalBook)
    : externalBook(externalBook) {}

// Destructor
DigitalBookAdapter::~DigitalBookAdapter() {
    delete externalBook; // Clean up the externalBook instance
}

// Implementing the pure virtual methods from Book
void DigitalBookAdapter::printBook() const {
    std::cout << "Name: " << getBookName() << "\n"
        << "Author: " << getAuthor() << "\n"
        << "ISBN: " << getISBN() << "\n"
        << "Year of publication: " << getPublicationYear() << "\n"
        << "Copies: " << getCopiesAvailable() << "\n"
        << "Genre: " << getGenre() << "\n"
        << "File Size: " << externalBook->getFileSize() << " MB\n"
        << "Format: " << externalBook->getFormat() << std::endl;
}

Book* DigitalBookAdapter::clone() const {
    return new DigitalBookAdapter(new ExternalDigitalBook(*externalBook));
}

// Getters
const std::string& DigitalBookAdapter::getBookName() const {
    return externalBook->getBookNam();
}

const std::string& DigitalBookAdapter::getAuthor() const {
    return externalBook->getAuthor();
}

const std::string& DigitalBookAdapter::getISBN() const {
    return externalBook->getISBN();
}

int DigitalBookAdapter::getPublicationYear() const {
    return externalBook->getPublicationYear();
}

int DigitalBookAdapter::getCopiesAvailable() const {
    return externalBook->getCopiesAvailable();
}

const std::string& DigitalBookAdapter::getGenre() const {
    return externalBook->getGenre();
}

// Setters
bool DigitalBookAdapter::setCopiesAvailable(int newCopiesAvailable) {
    return externalBook->setCopiesAvailable(newCopiesAvailable);
}
