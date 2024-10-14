#include "Library.h"
#include "Ebook.h"
#include "Notebook.h"
#include "PhysicalBook.h"
#include "DigitalBookAdapter.h"
#include "ExternalDigitalBook.h"
#include "MemberEmployee.h"

enum eMenuOptions
{
    eAddBook, eAddMember, eAddEmployee, ePrintBooks, ePrintMembers, ePrintEmployees, ePrintMemberEmployees, ePrintLibary,
    eSortBooks, eLoanBook, eNofOptions
};

const std::string str[eNofOptions] = { "Add Book","Add Member", "Add Employee", "Print all books", "Print all members", "Print all employees",
                                       "Print all Member Employees", "Print library", "Sort books", "Loan a book" };

#define EXIT -1

int menu();
Library* initLibrary();
void addBook(Library& library);
void addMember(Library& library);
void addEmployee(Library& library);
void addLoan(Loan& memberLoan, Library& library);
void addBookForLoan(Loan& memberLoan, Library& library);

int main()
{
    Library* lib = initLibrary();  // Singleton instance of Library
    int option;

    bool stop = false;
    do
    {
        option = menu();
        switch (option)
        {
        case eAddBook:
            addBook(*lib);
            break;

        case eAddMember:
            addMember(*lib);
            break;

        case eAddEmployee:
            addEmployee(*lib);
            break;

        case ePrintBooks:
            lib->showBooks();
            break;

        case ePrintMembers:
            lib->showMembers();
            break;

        case ePrintEmployees:
            lib->getAdmin().showEmployees();
            break;

        case ePrintMemberEmployees:
            lib->showMemberEmployees();
            break;

        case ePrintLibary:
            lib->printLibrary();
            break;

        case eSortBooks:
        {
            int sortOption;
            std::cout << "Choose the attribute to sort by:" << std::endl;
            std::cout << "1 - Publication Year" << std::endl;
            std::cout << "2 - Copies Available" << std::endl;
            std::cout << "3 - Book Name" << std::endl;
            std::cin >> sortOption;

            switch (sortOption)
            {
            case 1:
                lib->sortBooksByPublicationYear();
                break;
            case 2:
                lib->sortBooksByCopiesAvailable();
                break;
            case 3:
                lib->sortBooksByBookName();
                break;
            default:
                std::cout << "Invalid option" << std::endl;
                break;
            }
            break;
        }

        case eLoanBook:
        {
            if (lib->getMembers().empty())
            {
                std::cout << "There are no members in the library in order to loan a book" << std::endl;
                break;
            }
            lib->showMembers();
            Member* member = nullptr;
            std::string numMem;
            bool exists;
            do {
                exists = false;
                std::cout << "For which member would you like to make the loan? Write the member number" << std::endl;
                std::getline(std::cin, numMem);
                member = lib->findMemByNum(numMem);
                if (member != nullptr)
                {
                    exists = true;
                }
                else
                {
                    std::cout << "There is no member with this number." << std::endl;
                }

            } while (!exists);

            addLoan(*member->getLoanMember(), *lib);

            break;
        }

        case EXIT:
            std::cout << "Bye bye" << std::endl;
            stop = true;
            break;

        default:
            std::cout << "Wrong option" << std::endl;
            break;
        }
    } while (!stop);

    delete lib;
    return 0;
}

int menu()
{
    int option;
    std::cout << "\n\n";
    std::cout << "Please choose one of the following options" << std::endl;
    for (int i = 0; i < eNofOptions; i++)
        std::cout << i << " - " << str[i] << std::endl;
    std::cout << EXIT << " - Quit" << std::endl;
    std::cin >> option;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // clean buffer
    return option;
}

Library* initLibrary()
{
    std::string libraryName;
    std::string adminName;
    std::string adminNumber;

    std::cout << "Enter the name of the library: " << std::endl;
    std::getline(std::cin, libraryName);

    std::cout << "Enter the administrator's name: " << std::endl;
    std::getline(std::cin, adminName);

    std::cout << "Enter the administrator's employee number: " << std::endl;
    std::getline(std::cin, adminNumber);

    Employee adminEmployee(adminName, adminNumber);
    Administrator admin(adminEmployee);

    LinkedList<MemberEmployee> memberEmployees; // Initialize an empty linked list

    return Library::getInstance(libraryName, admin, std::list<Member>(), std::list<Book*>(), memberEmployees);
}

void addBook(Library& library)
{
    std::string bookName;
    std::cout << "\nEnter the book name: " << std::endl;
    std::getline(std::cin, bookName);

    std::string author;
    std::cout << "Enter the book author: " << std::endl;
    std::getline(std::cin, author);

    std::string ISBN;
    std::cout << "Enter the book ISBN: " << std::endl;
    std::getline(std::cin, ISBN);

    for (const auto& book : library.getBooks())
    {
        if (book->getISBN() == ISBN)
        {
            std::cout << "This book already exists in the library " << std::endl;
            return;
        }
    }

    int publicationYear;
    bool valid = true;
    do
    {
        valid = true;
        std::cout << "Enter the book publication year (between 1 and 2024): ";
        std::cin >> publicationYear;

        if (publicationYear <= 0 || publicationYear > 2024) {
            std::cout << "Invalid year ";
            valid = false;
        }

    } while (!valid);

    int copiesAvailable;
    do
    {
        valid = true;
        std::cout << "Enter the book number of copies available: ";
        std::cin >> copiesAvailable;

        if (copiesAvailable < 0) {
            std::cout << "Invalid number ";
            valid = false;
        }

    } while (!valid);

    std::cin.ignore(); // To ignore the newline character left in the input buffer

    std::string genre;
    std::cout << "Enter the book genre: " << std::endl;
    std::getline(std::cin, genre);

    int choice;
    std::cout << "\nPlease check what kind of book you would like to add : ";
    std::cout << "\nChoose 1 for Ebook, 2 for Physical Book, 3 for Notebook, 4 for External Digital Book: ";

    bool stop = false;
    do {
        std::cin >> choice;
        switch (choice)
        {
        case 1: // Ebook
        {
            double fileSize;
            std::string format;

            do
            {
                valid = true;
                std::cout << "Enter book file size: ";
                std::cin >> fileSize;

                if (fileSize < 0) {
                    std::cout << "Invalid number ";
                    valid = false;
                }

            } while (!valid);

            std::cin.ignore(); // To ignore the newline character left in the input buffer

            std::cout << "Enter book format: ";
            std::getline(std::cin, format);

            Book* newBook = new Ebook(bookName, author, ISBN, publicationYear, copiesAvailable, genre, fileSize, format);
            library.addBook(newBook);
            stop = true;
            break;
        }
        case 2: // Physical Book
        {
            std::string place;
            std::cin.ignore();
            std::cout << "Enter the book place in the library: ";
            std::getline(std::cin, place);

            Book* newBook = new PhysicalBook(bookName, author, ISBN, publicationYear, copiesAvailable, genre, place);
            library.addBook(newBook);
            stop = true;
            break;
        }

        case 3: // Notebook
        {
            std::string type;
            std::cin.ignore();
            std::cout << "Enter the book type: " << std::endl;
            std::getline(std::cin, type);

            Book* newBook = new Notebook(bookName, author, ISBN, publicationYear, copiesAvailable, genre, type);
            library.addBook(newBook);
            stop = true;
            break;
        }
        case 4: // External Digital Book
        {
            double fileSize;
            std::string format;

            std::cout << "Enter the file size in MB: ";
            std::cin >> fileSize;
            std::cin.ignore(); // To ignore the newline character left in the input buffer

            std::cout << "Enter the file format: ";
            std::getline(std::cin, format);

            // Create an ExternalDigitalBook instance
            ExternalDigitalBook* externalBook = new ExternalDigitalBook(bookName, author, ISBN, publicationYear, copiesAvailable, genre, fileSize, format);

            // Wrap it with the adapter
            Book* adaptedBook = new DigitalBookAdapter(externalBook);

            library.addBook(adaptedBook);
            stop = true;
            break;
        }
        case EXIT:
            std::cout << "Bye bye" << std::endl;
            stop = true;
            break;

        default:
            std::cout << "Invalid choice" << std::endl;
            break;
        }
    } while (!stop);
}

void addMember(Library& library)
{
    std::string memberName;
    std::cout << "\nEnter the member name: " << std::endl;
    std::getline(std::cin, memberName);

    std::string memberNumber;
    bool exists;
    do {
        exists = false;
        std::cout << "Enter the member number: " << std::endl;
        std::getline(std::cin, memberNumber);

        // Checking if we have a member with this number
        if (library.findMemByNum(memberNumber))
        {
            exists = true;
            std::cout << "There is already a member with this number" << std::endl;
        }

    } while (exists);

    std::string phoneNumber;
    std::cout << "Enter the member phone number: " << std::endl;
    std::getline(std::cin, phoneNumber);

    Loan* memberLoan = nullptr;
    char answer;

    do
    {
        std::cout << "Do you want to loan books now? (y- for Yes , n- for No)" << std::endl;
        std::cin >> answer;
        std::cin.ignore(); // To ignore the newline character left in the input buffer

        if (answer == 'y')
        {
            memberLoan = new Loan();
            addLoan(*memberLoan, library);
        }
        else if (answer == 'n')
        {
            memberLoan = new Loan();
        }
        else
        {
            std::cout << "Invalid input entered" << std::endl;
        }
    } while (answer != 'y' && answer != 'n');

    if (memberLoan == nullptr) {
        memberLoan = new Loan();
    }

    Member newMember(memberName, memberNumber, phoneNumber, *memberLoan);
    library.addMember(newMember);

    // check if the new member is an employee in the library
    for (const auto& employee : library.getAdmin().getEmployeeList())
    {
        if (employee.getName() == newMember.getName())
        {
            do
            {
                std::cout << "There is an Employee in our library with the same name, is it the same person? (y- for Yes , n- for No)" << std::endl;
                std::cin >> answer;
                std::cin.ignore();

                if (answer == 'y')
                {
                    Employee* emp = library.getAdmin().findEmployeeByName(newMember.getName());
                    MemberEmployee* memberEmployee = new MemberEmployee(newMember.getName(), newMember, *emp, 1);
                    library.addMemberEmployee(*memberEmployee);
                }
                else if (answer != 'n')
                {
                    std::cout << "Invalid input entered" << std::endl;
                }

            } while (answer != 'y' && answer != 'n');
        }
    }
}

void addLoan(Loan& memberLoan, Library& library)
{
    if (library.getBooks().empty())
    {
        std::cout << "There are currently no books in the library, you can add books to the library using the main menu" << std::endl;
        return;
    }

    if (library.copyAvailable())
    {
        library.showBooks();
        addBookForLoan(memberLoan, library);
        char answer;
        do
        {
            std::cout << "Would you like to loan another book? (y- for Yes , n- for No)" << std::endl;
            std::cin >> answer;
            std::cin.ignore(); // To ignore the newline character left in the input buffer
            if (library.copyAvailable())
            {
                if (answer == 'y')
                    addBookForLoan(memberLoan, library);

                else if (answer != 'n')
                    std::cout << "Invalid input entered" << std::endl;
            }
            else
            {
                std::cout << "There are currently no books available to borrow" << std::endl;
                answer = 'n';
            }
        } while (answer != 'n');

        int day, month, year;
        bool correct;
        do {
            correct = true;
            std::cout << "When does the member have to return the books?" << std::endl;
            std::cout << "Enter a day (a number): ";
            std::cin >> day;
            std::cout << "Enter a month (a number): ";
            std::cin >> month;
            std::cout << "Enter a year: ";
            std::cin >> year;
            if (!memberLoan.getDate()->setYear(year) || !memberLoan.getDate()->setMonth(month) || !memberLoan.getDate()->setDay(day))
            {
                std::cout << "The date is incorrect " << std::endl;
                correct = false;
            }
        } while (!correct);
    }
    else
    {
        std::cout << "There are currently no books available to borrow" << std::endl;
    }
}

void addBookForLoan(Loan& memberLoan, Library& library)
{
    Book* thisBook = nullptr;
    std::string bookName;
    bool exists;
    do {
        exists = false;
        std::cout << "Which book do you want to borrow from the books in the library?: Choose the name of the book" << std::endl;
        std::getline(std::cin, bookName);

        // Use findBookByName with the list of books
        thisBook = Book::findBookByName(library.getBooks(), bookName);

        if (thisBook != nullptr)
        {
            // Check if a copy is available
            if (thisBook->getCopiesAvailable() > 0)
            {
                thisBook->setCopiesAvailable(thisBook->getCopiesAvailable() - 1);
                library.updateCopies(bookName);
                exists = true;
            }
            else
            {
                std::cout << "No copies available for this book." << std::endl;
                delete thisBook; // Free the cloned book
                thisBook = nullptr;
            }
        }
        else
        {
            std::cout << "The book does not exist in the library." << std::endl;
        }
    } while (!exists);

    if (thisBook)
    {
        memberLoan.addBook(thisBook);
    }
}

void addEmployee(Library& library)
{
    std::string employeeName;
    std::cout << "Enter the Employee name: " << std::endl;
    std::getline(std::cin, employeeName);

    std::string employeeNumber;
    std::cout << "Enter the Employee number: " << std::endl;
    std::getline(std::cin, employeeNumber);

    Employee newEmployee(employeeName, employeeNumber);
    library.getAdmin().addEmployee(newEmployee);

    char answer;
    bool found = false;

    // Check if the new employee is a member in the library
    for (const Member& member : library.getMembers())
    {
        if (newEmployee.getName() == member.getName())
        {
            found = true;
            do
            {
                std::cout << "There is a Member in our library with the same name, is it the same person? (y- for Yes , n- for No)" << std::endl;
                std::cin >> answer;
                std::cin.ignore();
                if (answer == 'y')
                {
                    MemberEmployee* memberEmployee = new MemberEmployee(newEmployee.getName(), member, newEmployee, 1);
                    library.addMemberEmployee(*memberEmployee);
                }
                else if (answer != 'n')
                {
                    std::cout << "Invalid input entered" << std::endl;
                }

            } while (answer != 'y' && answer != 'n');
        }
    }

    if (!found)
    {
        std::cout << "No member with the same name found in the library." << std::endl;
    }
}
