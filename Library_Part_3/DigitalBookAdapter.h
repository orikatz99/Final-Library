#ifndef DIGITALBOOKADAPTER_H
#define DIGITALBOOKADAPTER_H

#include "Book.h"
#include "ExternalDigitalBook.h"

class DigitalBookAdapter : public Book {
private:
    ExternalDigitalBook* externalBook;

public:
    DigitalBookAdapter(ExternalDigitalBook* externalBook);
    virtual ~DigitalBookAdapter();

    // Implement abstract methods from the Book class
    virtual void printBook() const override;
    virtual Book* clone() const override;

    // Getters
    virtual const std::string& getBookName() const;
    virtual const std::string& getAuthor() const;
    virtual const std::string& getISBN() const;
    virtual int getPublicationYear() const;
    virtual int getCopiesAvailable() const;
    virtual const std::string& getGenre() const;

    // Setters 
    virtual bool setCopiesAvailable(int newCopiesAvailable);
};

#endif // DIGITALBOOKADAPTER_H
