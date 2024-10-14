#ifndef LIBRARY_H
#define LIBRARY_H

#include <string>
#include <list>
#include <algorithm>
#include "Administrator.h"
#include "Member.h"
#include "Book.h"
#include "MemberEmployee.h"
#include "LinkedList.h"
#include "NotificationSubject.h"
#include "NotificationObserver.h"

class Library : public NotificationSubject {
private:
    static Library* instance;
    std::string name;
    Administrator admin;
    std::list<Member> members;
    std::list<Book*> books;
    LinkedList<MemberEmployee> memberEmployees;
    std::list<NotificationObserver*> observers;

    // Private constructor
    Library(const std::string& name, Administrator& admin, const std::list<Member>& members, const std::list<Book*>& books, LinkedList<MemberEmployee>& memberEmployees);

    // Private copy constructor and assignment operator to prevent copying
    Library(const Library& other) = delete;
    Library& operator=(const Library& other) = delete;

public:
    // Static method to get the single instance of the Library
    static Library* getInstance(const std::string& name, Administrator& admin, const std::list<Member>& members = std::list<Member>(), const std::list<Book*>& books = std::list<Book*>(), LinkedList<MemberEmployee>& memberEmployees = *(new LinkedList<MemberEmployee>()));

    // Destructor
    ~Library();

    // getters
    const std::string& getName() const;
    Administrator& getAdmin();
    std::list<Member>& getMembers();
    const std::list<Member>& getMembers() const;
    std::list<Book*>& getBooks();
    const std::list<Book*>& getBooks() const;
    LinkedList<MemberEmployee>& getMemberEmployees();

    // setters
    bool setName(const std::string& name);
    bool setMembers(const std::list<Member>& members);
    bool setBooks(const std::list<Book*>& books);
    bool setMemberEmployees(const LinkedList<MemberEmployee>& newMemberEmployees);

    void printLibrary() const;
    void showMembers() const;
    void showBooks() const;
    void showMemberEmployees() const;
    void addBook(Book* newBook);
    void addMember(const Member& newMember);
    void addMemberEmployee(const MemberEmployee& newMemberEmployee);
    Member* findMemByNum(const std::string& num);
    Member* findMemByName(const std::string& name);

    void sortBooksByPublicationYear();
    void sortBooksByCopiesAvailable();
    void sortBooksByBookName();

    bool copyAvailable() const;

    void addObserver(NotificationObserver* observer) override;
    void removeObserver(NotificationObserver* observer) override;
    void notifyObservers(const std::string& message) override;

    void updateCopies(const std::string& name);
};

#endif // LIBRARY_H
