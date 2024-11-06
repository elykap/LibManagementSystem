#include <iostream>
#include <cassert>
#include "Library.h"
#include "User.h"
#include "Book.h"

void testAddAndSearchBook() {
    Library library;
    Book book("Test Title", "Test Author", "12345");
    library.addBook(book);

    Book *searchedBook=library.searchBook("12345");
    assert(searchedBook!=nullptr&&searchedBook->getTitle()=="Test Title");
    std::cout<<"testAddAndSearchBook passed.\n";
}

void testRegisterAndSearchUser() {
    Library library;
    User user("Test User", 1001);
    library.registerUser(user);

    User *searchedUser=library.searchUser(1001);
    assert(searchedUser!=nullptr&&searchedUser->getName()=="Test User");
    std::cout<<"testRegisterAndSearchUser passed.\n";
}

int main() {
    testAddAndSearchBook();
    testRegisterAndSearchUser();
    return 0;
}