#include <iostream>
using namespace std;

#include "Book.h"

// Default constructor
Book::Book() : publicationYear(0), copiesAvailable(0) {}

// Parameterized constructor
Book::Book(const std::string& bookName, const std::string& author, const std::string& ISBN, int publicationYear, int copiesAvailable, const std::string& genre)
    : bookName(bookName), author(author), ISBN(ISBN), publicationYear(publicationYear), copiesAvailable(copiesAvailable), genre(genre) {}

// Copy constructor
Book::Book(const Book& other)
    : bookName(other.bookName), author(other.author), ISBN(other.ISBN), publicationYear(other.publicationYear), copiesAvailable(other.copiesAvailable), genre(other.genre) {}

// Move constructor
Book::Book(Book&& other) noexcept
    : bookName(std::move(other.bookName)), author(std::move(other.author)), ISBN(std::move(other.ISBN)), publicationYear(other.publicationYear), copiesAvailable(other.copiesAvailable), genre(std::move(other.genre)) {}

// Assignment operator
Book& Book::operator=(const Book& other)
{
    if (this != &other) {
        bookName = other.bookName;
        author = other.author;
        ISBN = other.ISBN;
        publicationYear = other.publicationYear;
        copiesAvailable = other.copiesAvailable;
        genre = other.genre;
    }
    return *this;
}

// Destructor
Book::~Book() {}

// Getters
const std::string& Book::getBookName() const
{
    return bookName;
}
const std::string& Book::getAuthor() const
{
    return author;
}
const std::string& Book::getISBN() const
{
    return ISBN;
}
int Book::getPublicationYear() const
{
    return publicationYear;
}
int Book::getCopiesAvailable() const
{
    return copiesAvailable;
}
const std::string& Book::getGenre() const
{
    return genre;
}

// Setters
bool Book::setBookName(const std::string& newBookName)
{
    bookName = newBookName;
    return true;
}
bool Book::setCopiesAvailable(int newCopiesAvailable)
{
    if (newCopiesAvailable >= 0)
    {
        copiesAvailable = newCopiesAvailable;
        return true;
    }
    return false;
}
bool Book::setGenre(const std::string& newGenre)
{
    genre = newGenre;
    return true;
}

void Book::printBook() const
{
    std::cout << "Name: " << bookName << "\n" <<
        "Author: " << author << "\n" <<
        "ISBN: " << ISBN << "\n" <<
        "Year of publication: " << publicationYear << "\n" <<
        "Copies: " << copiesAvailable << "\n" <<
        "Genre: " << genre << std::endl;
}

Book* Book::findBookByName(const std::list<Book*>& books, const std::string& name)
{
    for (const auto& book : books)
    {
        if (book->getBookName() == name)
        {
            return book->clone(); // Return a clone to avoid object slicing
        }
    }
    return nullptr;
}
