//Implements the Database class functions to save and load book and user data for persistence.
#include "Database.h"
#include <fstream>
#include <iostream>

void Database::saveBooks(const std::vector<Book> &books, const std::string &filename) {
    std::ofstream file(filename);
    if (!file) {
        std::cerr<<"Error opening file for saving books.\n";
        return;
    }
    for (const auto &book : books) {
        file<<book.getTitle()<<"," << book.getAuthor()<<","
             <<book.getISBN()<<","<<book.getStatus()<<"\n";
    }
    file.close();
    std::cout<<"Books saved successfully.\n";
}

std::vector<Book> Database::loadBooks(const std::string &filename) {
    std::vector<Book> books;
    std::ifstream file(filename);
    if (!file) {
        std::cerr<<"Error opening file for loading books.\n";
        return books;
    }
    std::string title, author, ISBN, statusStr;
    bool status;
    while (getline(file, title, ',') &&
           getline(file, author, ',') &&
           getline(file, ISBN, ',') &&
           getline(file, statusStr)) {
        status=(statusStr == "1");
        Book book(title, author, ISBN);
        book.setStatus(status);
        books.push_back(book);
    }
    file.close();
    std::cout<<"Books loaded successfully.\n";
    return books;
}

void Database::saveUsers(const std::vector<User> &users, const std::string &filename) {
    std::ofstream file(filename);
    if (!file) {
        std::cerr<<"Error opening file for saving users.\n";
        return;
    }
    for (const auto &user : users) {
        file<<user.getName()<<","<<user.getUserID()<<"\n";
    }
    file.close();
    std::cout<<"Users saved successfully.\n";
}

std::vector<User> Database::loadUsers(const std::string &filename) {
    std::vector<User> users;
    std::ifstream file(filename);
    if (!file) {
        std::cerr<<"Error opening file for loading users.\n";
        return users;
    }
    std::string name;
    int userID;
    while (file>>userID && getline(file, name, ',')) {
        if (name.front()==' ') name.erase(0, 1);
        users.emplace_back(name, userID);
    }
    file.close();
    std::cout<<"Users loaded successfully.\n";
    return users;
}
//TODO: Improve error handling for file I/O to ensure graceful program shutdown on failure.
//TODO: Consider using a database library to improve data persistence and query capabilities.