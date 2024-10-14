#ifndef NOTEBOOK_H
#define NOTEBOOK_H

#include "Book.h"
#include <string>

class Notebook : public Book {

private:
    std::string type;

public:
    Notebook(const std::string& bookName, const std::string& author, const std::string& ISBN, int publicationYear, int copiesAvailable, const std::string& genre, const std::string& type);
    Notebook(const Notebook& other);
    Notebook(Notebook&& other) noexcept;
    Notebook& operator=(const Notebook& other);
    virtual ~Notebook();

    // Getters
    const std::string& getType() const;

    // Setters
    bool setType(const std::string& type);

    void printBook() const override;

    // Override clone method
    virtual Notebook* clone() const override;
};

#endif // NOTEBOOK_H
