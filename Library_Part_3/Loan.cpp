#include <iostream>
#include "Loan.h"

// Constructor
Loan::Loan() : numOfBook(0), date(new Date()) {}

Loan::Loan(const std::list<Book*>& bookList, Date& date)
    : numOfBook(static_cast<int>(bookList.size())), date(new Date(date))
{
    for (const auto& book : bookList) {
        this->bookList.push_back(std::unique_ptr<Book>(book->clone()));
    }
}

// Copy Constructor
Loan::Loan(const Loan& other)
    : numOfBook(other.numOfBook), date(new Date(*other.date))
{
    for (const auto& book : other.bookList) {
        this->bookList.push_back(std::unique_ptr<Book>(book->clone()));
    }
}

// Move Constructor
Loan::Loan(Loan&& other) noexcept
    : bookList(std::move(other.bookList)), numOfBook(other.numOfBook), date(other.date)
{
    other.numOfBook = 0;
    other.date = nullptr;
}

// Destructor
Loan::~Loan()
{
    delete date;
}

// Assignment Operator
Loan& Loan::operator=(const Loan& other)
{
    if (this != &other) {
        numOfBook = other.numOfBook;
        date = new Date(*other.date);

        bookList.clear();
        for (const auto& book : other.bookList) {
            bookList.push_back(std::unique_ptr<Book>(book->clone()));
        }
    }
    return *this;
}

// Getters
const std::list<std::unique_ptr<Book>>& Loan::getBookList() const
{
    return bookList;
}

int Loan::getNumOfBook() const
{
    return numOfBook;
}

Date* Loan::getDate() const
{
    return date;
}

// Setters
bool Loan::setBookList(const std::list<Book*>& bookList)
{
    this->bookList.clear();
    numOfBook = static_cast<int>(bookList.size());
    for (const auto& book : bookList) {
        this->bookList.push_back(std::unique_ptr<Book>(book->clone()));
    }
    return true;
}

bool Loan::setDate(Date& date)
{
    this->date = &date;
    return true;
}

// Add a book to the loan
bool Loan::addBook(const Book* newBook)
{
    if (newBook) {
        bookList.push_back(std::unique_ptr<Book>(newBook->clone()));
        ++numOfBook;
        return true;
    }
    return false;
}

// Print all books in the loan
void Loan::printBookList() const
{
    for (const auto& book : bookList) {
        book->printBook();
        std::cout << "\n";
    }
}

// Print the entire loan
void Loan::printLoan() const
{
    std::cout << "The loaned books are:\n";
    printBookList();
    std::cout << "The end date of the loan: ";
    date->printDate();
}
