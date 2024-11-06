#ifndef USER_H
#define USER_H
#include <string>
#include <vector>
#include "Book.h"

class User {
private:
    std::string name;
    int userID;
    std::vector<Book> borrowedBooks;

public:

    User(const std::string &name, int userID);

    std::string getName() const;
    int getUserID() const;
    std::vector<Book> getBorrowedBooks() const;

    void borrowBook(Book &book);
    void returnBook(const std::string &ISBN);

    void displayInfo() const;
};

#endif // USER_H