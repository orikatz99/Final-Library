#ifndef EXTERNALDIGITALBOOK_H
#define EXTERNALDIGITALBOOK_H

#include <string>

class ExternalDigitalBook {
private:
    std::string bookName;
    std::string author;
    std::string ISBN;
    int publicationYear;
    int copiesAvailable;
    std::string genre;
    double fileSize;
    std::string format;

public:
    ExternalDigitalBook(const std::string& bookName, const std::string& author, const std::string& ISBN, int publicationYear, int copiesAvailable, const std::string& genre, double fileSize, const std::string& format);

    // Getters
    const std::string& getBookNam() const;
    const std::string& getAuthor() const;
    const std::string& getISBN() const;
    int getPublicationYear() const;
    int getCopiesAvailable() const;
    const std::string& getGenre() const;
    double getFileSize() const;
    const std::string& getFormat() const;

    // Setters
    bool setCopiesAvailable(int newCopiesAvailable);
};

#endif // EXTERNALDIGITALBOOK_H
