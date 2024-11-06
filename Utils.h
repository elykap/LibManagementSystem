#ifndef UTILS_H
#define UTILS_H
#include <string>

namespace Utils {
    bool isDigits(const std::string &str);

    int generateUniqueID();

    std::string toLower(const std::string &str);

    std::string trim(const std::string &str);
}

#endif // UTILS_H