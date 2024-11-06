//Implements utility functions for input validation, ID generation, and string manipulation.
#include "Utils.h"
#include <algorithm>
#include <cctype>
#include <chrono>
#include <sstream>

bool Utils::isDigits(const std::string &str) {
    return std::all_of(str.begin(), str.end(), ::isdigit);
}

int Utils::generateUniqueID() {
    auto now=std::chrono::system_clock::now();
    auto duration=now.time_since_epoch();
    return static_cast<int>(duration.count() % 1000000);
}

std::string Utils::toLower(const std::string &str) {
    std::string lowerStr=str;
    std::transform(lowerStr.begin(), lowerStr.end(), lowerStr.begin(), ::tolower);
    return lowerStr;
}

std::string Utils::trim(const std::string &str) {
    size_t start=str.find_first_not_of(" \t\n\r\f\v");
    size_t end=str.find_last_not_of(" \t\n\r\f\v");
    return (start==std::string::npos) ? "" : str.substr(start, end - start + 1);
}