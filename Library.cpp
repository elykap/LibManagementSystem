#include "Library.h"
#include <iostream>

void Library::addBook(const Book &book) {
    books.push_back(book);
    std::cout<<"Book added successfully.\n";
}

void Library::deleteBook(const std::string &ISBN) {
    for (size_t i = 0; i < books.size(); ++i) {
        if (books[i].getISBN() == ISBN) {
            books.erase(books.begin() + i);
            std::cout << "Book deleted successfully.\n";
            return;
        }
    }
    std::cout<<"Book not found.\n";
}

Book* Library::searchBook(const std::string &ISBN) {
    for (auto &book : books) {
        if (book.getISBN()==ISBN) {
            return &book;
        }
    }
    return nullptr;
}

void Library::registerUser(const User &user) {
    users.push_back(user);
    std::cout<<"User registered successfully.\n";
}

User* Library::searchUser(int userID) {
    for (auto &user : users) {
        if (user.getUserID()==userID) {
            return &user;
        }
    }
    return nullptr;
}

void Library::borrowBook(int userID, const std::string &ISBN) {
    User *user=searchUser(userID);
    Book *book=searchBook(ISBN);

    if (user && book) {
        user->borrowBook(*book);
    } else {
        std::cout<<"User or book not found.\n";
    }
}

void Library::returnBook(int userID, const std::string &ISBN) {
    User *user=searchUser(userID);
    if (user) {
        user->returnBook(ISBN);
    } else {
        std::cout<<"User not found.\n";
    }
}

void Library::displayBooks() const {
    std::cout<<"Library Books:\n";
    for (const auto &book : books) {
        book.displayInfo();
    }
}

void Library::displayUsers() const {
    std::cout<<"Library Users:\n";
    for (const auto &user : users) {
        user.displayInfo();
    }
}