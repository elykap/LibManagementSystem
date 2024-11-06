#ifndef LIBRARY_H
#define LIBRARY_H

#include <vector>
#include <string>
#include "Book.h"
#include "User.h"

class Library {
private:
    std::vector<Book> books;
    std::vector<User> users;

public:
    void addBook(const Book &book);
    void deleteBook(const std::string &ISBN);
    Book* searchBook(const std::string &ISBN);

    void registerUser(const User &user);
    User* searchUser(int userID);

    void borrowBook(int userID, const std::string &ISBN);
    void returnBook(int userID, const std::string &ISBN);

    void displayBooks() const;
    void displayUsers() const;
};

#endif // LIBRARY_H