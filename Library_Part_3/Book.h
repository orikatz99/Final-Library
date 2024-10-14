#ifndef BOOK_H
#define BOOK_H

#include <string>
#include <list>

class Book {//abstract 

protected:
    std::string bookName;
    std::string author;
    std::string ISBN;
    int publicationYear;
    int copiesAvailable;
    std::string genre;

public:
    Book(); // Default constructor
    Book(const std::string& bookName, const std::string& author, const std::string& ISBN, int publicationYear, int copiesAvailable, const std::string& genre);
    Book(const Book& other);
    Book(Book&& other) noexcept;
    Book& operator=(const Book& other);
    virtual ~Book();

    // Getters
    const std::string& getBookName() const;
    const std::string& getAuthor() const;
    const std::string& getISBN() const;
    int getPublicationYear() const;
    int getCopiesAvailable() const;
    const std::string& getGenre() const;

    // Setters
    bool setBookName(const std::string& newBookName);
    bool setCopiesAvailable(int newCopiesAvailable);
    bool setGenre(const std::string& newGenre);

    virtual void printBook() const = 0;
    virtual Book* clone() const = 0;
    static Book* findBookByName(const std::list<Book*>& books, const std::string& name);

};

#endif // BOOK_H
