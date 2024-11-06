//Defines the Library class, which manages a collection of books and users, allowing for adding, searching, borrowing, and returning books.
#ifndef LIBRARY_H
#define LIBRARY_H

#include <vector>
#include <string>
#include "Book.h"
#include "User.h"

//Library class provides methods to manage books and users, register new users, and handle book borrowing and returns.
class Library {
private:
    std::vector<Book> books;
    std::vector<User> users;

public:
    //Adds a new book to the library collection.
    void addBook(const Book &book);
    //Deletes a book from the collection by ISBN.
    void deleteBook(const std::string &ISBN);
    //Searches for a book in the collection by ISBN.
    Book* searchBook(const std::string &ISBN);

    //Registers a new user in the library."
    void registerUser(const User &user);
    User* searchUser(int userID);

    //Allows a user to borrow a book by updating its borrow status.
    void borrowBook(int userID, const std::string &ISBN);
    //Allows a user to return a borrowed book, updating its status.
    void returnBook(int userID, const std::string &ISBN);

    void displayBooks() const;
    void displayUsers() const;
};

#endif // LIBRARY_H