#include <iostream>
#include "Library.h"
#include "Database.h"
#include "Utils.h"

void displayMenu() {
    std::cout<<"\nLibrary Management System\n";
    std::cout<<"1. Add Book\n";
    std::cout<<"2. Delete Book\n";
    std::cout<<"3. Search Book\n";
    std::cout<<"4. Register User\n";
    std::cout<<"5. Borrow Book\n";
    std::cout<<"6. Return Book\n";
    std::cout<<"7. Display All Books\n";
    std::cout<<"8. Display All Users\n";
    std::cout<<"9. Save and Exit\n";
    std::cout<<"Select an option: ";
}

int main() {
    Library library;

    library.displayBooks();
    library.displayUsers();
    
    int choice;
    while (true) {
        displayMenu();
        std::cin >> choice;
        std::cin.ignore();

        if (choice==9) {
            std::cout<<"Saving data and exiting...\n";
            break;
        }

        switch (choice) {
            case 1: {
                std::string title, author, ISBN;
                std::cout<<"Enter book title: ";
                std::getline(std::cin, title);
                std::cout<<"Enter book author: ";
                std::getline(std::cin, author);
                std::cout<<"Enter book ISBN: ";
                std::getline(std::cin, ISBN);
                
                if (!Utils::isDigits(ISBN)) {
                    std::cout<<"Invalid ISBN. Must contain only digits.\n";
                    break;
                }

                library.addBook(Book(title, author, ISBN));
                break;
            }
            case 2: {
                std::string ISBN;
                std::cout<<"Enter book ISBN to delete: ";
                std::getline(std::cin, ISBN);
                library.deleteBook(ISBN);
                break;
            }
            case 3: {
                std::string ISBN;
                std::cout<<"Enter book ISBN to search: ";
                std::getline(std::cin, ISBN);
                Book *book = library.searchBook(ISBN);
                if (book) {
                    book->displayInfo();
                } else {
                    std::cout<<"Book not found.\n";
                }
                break;
            }
            case 4: {
                std::string name;
                std::cout<<"Enter user name: ";
                std::getline(std::cin, name);
                int userID = Utils::generateUniqueID();
                library.registerUser(User(name, userID));
                break;
            }
            case 5: {
                int userID;
                std::string ISBN;
                std::cout<<"Enter user ID: ";
                std::cin>>userID;
                std::cin.ignore();
                std::cout<<"Enter book ISBN to borrow: ";
                std::getline(std::cin, ISBN);
                library.borrowBook(userID, ISBN);
                break;
            }
            case 6: {
                int userID;
                std::string ISBN;
                std::cout<<"Enter user ID: ";
                std::cin>>userID;
                std::cin.ignore();
                std::cout<<"Enter book ISBN to return: ";
                std::getline(std::cin, ISBN);
                library.returnBook(userID, ISBN);
                break;
            }
            case 7:
                library.displayBooks();
                break;
            case 8:
                library.displayUsers();
                break;
            default:
                std::cout<<"Invalid option. Please try again.\n";
        }
    }

    return 0;
}