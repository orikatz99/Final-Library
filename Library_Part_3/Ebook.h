#ifndef EBOOK_H
#define EBOOK_H

#include "Book.h"
#include <string>

class Ebook : public Book
{
private:
    double fileSize;
    std::string format;

public:
    Ebook(const std::string& bookName, const std::string& author, const std::string& ISBN, int publicationYear, int copiesAvailable, const std::string& genre, double fileSize, const std::string& format);
    Ebook(const Ebook& other);
    Ebook(Ebook&& other) noexcept;
    Ebook& operator=(const Ebook& other);
    virtual ~Ebook();

    // Getters
    double getFileSize() const;
    const std::string& getFormat() const;

    // Setters
    bool setFormat(const std::string& format);

    void printBook() const override;

    // Override clone method
    virtual Ebook* clone() const override;
};

#endif // EBOOK_H
