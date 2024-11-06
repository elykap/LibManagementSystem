#ifndef DATABASE_H
#define DATABASE_H

#include <vector>
#include <string>
#include "Book.h"
#include "User.h"

class Database {
public:
    static void saveBooks(const std::vector<Book> &books, const std::string &filename);
    static std::vector<Book> loadBooks(const std::string &filename);

    static void saveUsers(const std::vector<User> &users, const std::string &filename);
    static std::vector<User> loadUsers(const std::string &filename);
};

#endif // DATABASE_H
