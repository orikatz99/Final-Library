
#include <iostream>
#include "ExternalDigitalBook.h"

ExternalDigitalBook::ExternalDigitalBook(const std::string& bookName, const std::string& author, const std::string& ISBN, int publicationYear, int copiesAvailable, const std::string& genre, double fileSize, const std::string& format)
    : bookName(bookName), author(author), ISBN(ISBN), publicationYear(publicationYear), copiesAvailable(copiesAvailable), genre(genre), fileSize(fileSize), format(format) {}

// Getters
const std::string& ExternalDigitalBook::getBookNam() const {
    return bookName;
}

const std::string& ExternalDigitalBook::getAuthor() const {
    return author;
}

const std::string& ExternalDigitalBook::getISBN() const {
    return ISBN;
}

int ExternalDigitalBook::getPublicationYear() const {
    return publicationYear;
}

int ExternalDigitalBook::getCopiesAvailable() const {
    return copiesAvailable;
}

const std::string& ExternalDigitalBook::getGenre() const {
    return genre;
}

double ExternalDigitalBook::getFileSize() const {
    return fileSize;
}

const std::string& ExternalDigitalBook::getFormat() const {
    return format;
}

// Setters
bool ExternalDigitalBook::setCopiesAvailable(int newCopiesAvailable) {
    if (newCopiesAvailable >= 0) {
        copiesAvailable = newCopiesAvailable;
        return true;
    }
    return false;
}
