//Defines the User class, representing a library user with a unique ID, name, and list of borrowed books.
#ifndef USER_H
#define USER_H
#include <string>
#include <vector>
#include "Book.h"

//User class manages details for each library user, including borrowing and returning books.
class User {
private:
    std::string name;
    int userID;
    std::vector<Book> borrowedBooks;

public:
    //Initializes a user with a name and a unique ID.
    User(const std::string &name, int userID);

    std::string getName() const;
    int getUserID() const;
    std::vector<Book> getBorrowedBooks() const;

    //Adds a book to the user's list of borrowed books.
    void borrowBook(Book &book);
    //Removes a book from the user's borrowed list based on ISBN.
    void returnBook(const std::string &ISBN);
    //Displays user details, including borrowed books.
    void displayInfo() const;
};

#endif // USER_H