#ifndef LOAN_H
#define LOAN_H

#include "Book.h"
#include "Date.h"
#include <list>
#include <memory>

class Loan {

protected:
    std::list<std::unique_ptr<Book>> bookList; // A list of unique pointers to manage the books loaned
    Date* date; 
    int numOfBook;

public:
    // Constructors
    Loan(); // Default Constructor
    Loan(const std::list<Book*>& bookList, Date& date);
    Loan(const Loan& other);        // Copy Constructor
    Loan(Loan&& other) noexcept;    // Move Constructor
    virtual ~Loan();                // Destructor

    Loan& operator=(const Loan& other); // Assignment Operator

    // Getters
    const std::list<std::unique_ptr<Book>>& getBookList() const;
    int getNumOfBook() const;
    Date* getDate() const;

    // Setters
    bool setBookList(const std::list<Book*>& bookList);
    bool setDate(Date& date);

    bool addBook(const Book* newBook);

    void printBookList() const;
    void printLoan() const;

};

#endif // LOAN_H
