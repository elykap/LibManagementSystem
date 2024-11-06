//Defines the Book class, representing a single book in the library with details such as title, author, ISBN, and borrowing status.
#ifndef BOOK_H
#define BOOK_H

#include <string>

//Book class represents a book in the library and provides methods to manage book details and borrow status.
class Book {
private:
    std::string title;
    std::string author;
    std::string ISBN;
    bool isBorrowed;

public:
    //Initializes a book with title, author, and ISBN.
    Book(const std::string &title, const std::string &author, const std::string &ISBN);

    std::string getTitle() const;
    std::string getAuthor() const;
    std::string getISBN() const;
    //Returns the current borrow status of the book (true if borrowed).
    bool getStatus() const;
    //Updates the borrow status of the book (true for borrowed, false for available).
    void setStatus(bool borrowed);
    //Displays all book details, including borrow status.
    void displayInfo() const;
};

#endif // BOOK_H