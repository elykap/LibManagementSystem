//Defines the Database class, handling the persistent storage of book and user data.
#ifndef DATABASE_H
#define DATABASE_H

#include <vector>
#include <string>
#include "Book.h"
#include "User.h"

class Database {
public:
    //Saves the current library's book collection to a file.
    static void saveBooks(const std::vector<Book> &books, const std::string &filename);
    //Loads the library's book collection from a file.
    static std::vector<Book> loadBooks(const std::string &filename);

    //Saves registered users to a file.
    static void saveUsers(const std::vector<User> &users, const std::string &filename);
    //Loads registered users from a file.
    static std::vector<User> loadUsers(const std::string &filename);
};

#endif // DATABASE_H