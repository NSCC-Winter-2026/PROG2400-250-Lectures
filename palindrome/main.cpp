#include <iostream>
#include <cstring>

bool is_palindrome(const char* str, const size_t length) {
    for (auto i = 0; i < length / 2; i++) {
        if (str[i] != str[length - 1 - i]) return false;
    }
    return true;
}

bool is_palindrome_recursive(const char* str, const size_t length) {
    // consider the simplest form of the problem
    if (length <= 1) return true;

    // compare the first and last letters
    if (str[0] == str[length - 1]) {
        return is_palindrome_recursive(&str[1], length - 2);
    }

    return false;
}

int main() {
    constexpr auto BUFFER_SIZE = 80;
    char buffer[BUFFER_SIZE];

    std::cout << "Enter a word: ";
    std::cin.getline(buffer, BUFFER_SIZE);

    if (is_palindrome(buffer, strnlen(buffer, BUFFER_SIZE))) {
        std::cout << buffer << " IS a palindrome." << std::endl;
    } else {
        std::cout << buffer << " is NOT a palindrome." << std::endl;
    }

    if (is_palindrome_recursive(buffer, strnlen(buffer, BUFFER_SIZE))) {
        std::cout << buffer << " IS a palindrome." << std::endl;
    } else {
        std::cout << buffer << " is NOT a palindrome." << std::endl;
    }

    return 0;
}
