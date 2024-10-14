#include <iostream>
#include <algorithm>
#include <list>
#include "Library.h"
#include "ExternalDigitalBook.h"

// Initialize the static instance pointer to nullptr
Library* Library::instance = nullptr;

// Private constructor
Library::Library(const std::string& name, Administrator& admin, const std::list<Member>& members, const std::list<Book*>& books, LinkedList<MemberEmployee>& memberEmployees)
    : name(name), admin(admin), members(members), books(books), memberEmployees(memberEmployees)
{}

// Static method to get the single instance of the Library
Library* Library::getInstance(const std::string& name, Administrator& admin, const std::list<Member>& members, const std::list<Book*>& books, LinkedList<MemberEmployee>& memberEmployees) {
    if (instance == nullptr) {
        instance = new Library(name, admin, members, books, memberEmployees);
    }
    return instance;
}

// Destructor
Library::~Library() = default;

// Getters
const std::string& Library::getName() const
{
    return name;
}
Administrator& Library::getAdmin()
{
    return admin;
}
std::list<Member>& Library::getMembers()
{
    return members;
}
const std::list<Member>& Library::getMembers() const
{
    return members;
}
std::list<Book*>& Library::getBooks()
{
    return books;
}
const std::list<Book*>& Library::getBooks() const
{
    return books;
}
LinkedList<MemberEmployee>& Library::getMemberEmployees()
{
    return memberEmployees;
}

// Setters
bool Library::setName(const std::string& name)
{
    this->name = name;
    return true;
}
bool Library::setMembers(const std::list<Member>& newMembers)
{
    members = newMembers;
    return true;
}
bool Library::setBooks(const std::list<Book*>& newBooks)
{
    books = newBooks;
    return true;
}
bool Library::setMemberEmployees(const LinkedList<MemberEmployee>& newMemberEmployees)
{
    memberEmployees = newMemberEmployees;
    return true;
}

// Print Library details
void Library::printLibrary() const
{
    std::cout << "\nLibrary Name: " << name << std::endl;
    std::cout << "Administrator: " << admin.getName() << std::endl;
    std::cout << "Number of Members: " << members.size() << std::endl;
    std::cout << "Number of Employees: " << admin.getEmployeeCount() << std::endl;
    std::cout << "Number of Member Employees: " << memberEmployees.getSize() << std::endl;
    std::cout << "Number of Books: " << books.size() << std::endl;
}

void Library::showMembers() const
{
    if (members.empty())
        std::cout << "\nThere are currently no members for the library" << std::endl;
    else
    {
        std::cout << "\nOur Library " << name << " has " << members.size() << " members:" << std::endl;
        int count = 1;
        for (const auto& member : members)
        {
            std::cout << "#" << count++ << std::endl;
            member.printMember();
            std::cout << "\n";
        }
    }
}

void Library::showBooks() const
{
    if (books.empty())
        std::cout << "\nThere are currently no books for the library" << std::endl;
    else
    {
        std::cout << "\nOur Library " << name << " has the following books: " << std::endl;
        for (const auto& book : books)
        {
            book->printBook();
            std::cout << "\n";
        }
    }
}

void Library::showMemberEmployees() const
{
    if (memberEmployees.getSize() == 0)
        std::cout << "\nIn our library " << name << " there are no members who are also employees" << std::endl;
    else
    {
        std::cout << "\nOur Library " << name << " has " << memberEmployees.getSize() << " members that are also employees:" << std::endl;
        memberEmployees.printList();
    }
}

// Add a book to the library
void Library::addBook(Book* newBook)
{
    books.push_back(newBook);
    notifyObservers("New book added ");
}

// Add a member to the library
void Library::addMember(const Member& newMember)
{
    // Check if a member with the same member number already exists
    for (const auto& member : members)
    {
        if (member.getMemNumber() == newMember.getMemNumber())
        {
            std::cout << "Member with the same member number already exists." << std::endl;
            return;
        }
    }

    members.push_back(newMember);
    addObserver(&members.back());  // Add the member as an observer
}

// Add a member-employee to the library
void Library::addMemberEmployee(const MemberEmployee& newMemberEmployee)
{
    memberEmployees.addToEnd(newMemberEmployee);
}

// Find a member by their number
Member* Library::findMemByNum(const std::string& num)
{
    for (auto& member : members)
    {
        if (member.getMemNumber() == num)
        {
            return &member;
        }
    }
    return nullptr;
}

// Find a member by their name
Member* Library::findMemByName(const std::string& name)
{
    for (auto& member : members)
    {
        if (member.getName() == name)
        {
            return &member;
        }
    }
    return nullptr;
}

// Sort books by publication year
void Library::sortBooksByPublicationYear()
{
    books.sort([](const Book* a, const Book* b) {
        return a->getPublicationYear() < b->getPublicationYear();
        });
}

// Sort books by copies available
void Library::sortBooksByCopiesAvailable()
{
    books.sort([](const Book* a, const Book* b) {
        return a->getCopiesAvailable() < b->getCopiesAvailable();
        });
}

// Sort books by book name
void Library::sortBooksByBookName()
{
    books.sort([](const Book* a, const Book* b) {
        return a->getBookName() < b->getBookName();
        });
}

// Check if there are copies available
bool Library::copyAvailable() const
{
    for (const auto& book : books)
    {
        if (book->getCopiesAvailable() != 0)
            return true;
    }
    return false;
}

void Library::addObserver(NotificationObserver* observer)
{
    observers.push_back(observer);
}

void Library::removeObserver(NotificationObserver* observer)
{
    observers.remove(observer);
}

void Library::notifyObservers(const std::string& message)
{
    for (NotificationObserver* observer : observers) {
        observer->update(message);
    }
}

void Library::updateCopies(const std::string& name)
{
    for (const auto& book : books)
    {
        if (book->getBookName() == name)
        {
            book->setCopiesAvailable(book->getCopiesAvailable() - 1); // Return a clone to avoid object slicing
        }
    }
}