#include "User.h"
#include <iostream>

User::User(const std::string &name, int userID)
    : name(name), userID(userID) {}

std::string User::getName() const {
    return name;
}

int User::getUserID() const {
    return userID;
}

std::vector<Book> User::getBorrowedBooks() const {
    return borrowedBooks;
}

void User::borrowBook(Book &book) {
    if (!book.getStatus()) {
        book.setStatus(true);
        borrowedBooks.push_back(book);
        std::cout<<"Book borrowed successfully.\n";
    } else {
        std::cout<<"Book is already borrowed.\n";
    }
}

void User::returnBook(const std::string &ISBN) {
    for (size_t i=0; i<borrowedBooks.size(); ++i) {
        if (borrowedBooks[i].getISBN()==ISBN) {
            borrowedBooks[i].setStatus(false);
            borrowedBooks.erase(borrowedBooks.begin()+i);
            std::cout<<"Book returned successfully.\n";
            return;
        }
    }
    std::cout << "No book with this ISBN was found in the borrowed list.\n";
}

void User::displayInfo() const {
    std::cout<<"User Name: "<<name<<"\n";
    std::cout<<"User ID: "<<userID<<"\n";
    std::cout<<"Borrowed Books: \n";
    for (const auto &book : borrowedBooks) {
        book.displayInfo();
    }
}