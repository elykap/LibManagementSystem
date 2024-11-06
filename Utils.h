//Defines utility functions for input validation, ID generation, and string manipulation used throughout the project.
#ifndef UTILS_H
#define UTILS_H
#include <string>

namespace Utils {
    //Checks if a string contains only numeric characters.
    bool isDigits(const std::string &str);
    //Creates a unique integer ID based on the current timestamp.
    int generateUniqueID();
    //Converts a string to lowercase for case-insensitive comparisons.
    std::string toLower(const std::string &str);
    //Removes whitespace from the start and end of a string.
    std::string trim(const std::string &str);
}

#endif // UTILS_H