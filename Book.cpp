#include "Book.h"
#include <iostream>

Book::Book(const std::string &title, const std::string &author, const std::string &ISBN)
    : title(title), author(author), ISBN(ISBN), isBorrowed(false) {}

std::string Book::getTitle() const {
    return title;
}

std::string Book::getAuthor() const {
    return author;
}

std::string Book::getISBN() const {
    return ISBN;
}

bool Book::getStatus() const {
    return isBorrowed;
}

void Book::setStatus(bool borrowed) {
    isBorrowed=borrowed;
}

void Book::displayInfo() const {
    std::cout<<"Title: "<<title<<"\n";
    std::cout<<"Author: "<<author<<"\n";
    std::cout<<"ISBN: "<<ISBN<<"\n";
    std::cout<<"Status: "<<(isBorrowed ? "Borrowed" : "Available")<<"\n";
}