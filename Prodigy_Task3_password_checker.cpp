#include <iostream>
#include <cstring>

bool hasUppercase(const char* password) {
    int length = std::strlen(password);
    for (int i = 0; i < length; ++i) {
        if (password[i] >= 'A' && password[i] <= 'Z') {
            return true;
        }
    }
    return false;
}

bool hasLowercase(const char* password) {
    int length = std::strlen(password);
    for (int i = 0; i < length; ++i) {
        if (password[i] >= 'a' && password[i] <= 'z') {
            return true;
        }
    }
    return false;
}

int check_password(const char* password) {
    int length = std::strlen(password);
    bool has_uppercase = hasUppercase(password);
    bool has_lowercase = hasLowercase(password);

    if (length < 8 || !has_uppercase || !has_lowercase) {
        return 0; // Weak
    } else {
        return 1; // Strong
    }
}

int main() {
    char password[100];
    std::cout << "Enter your password: ";
    std::cin >> password;

    int check = check_password(password);

    if (check == 0) {
        std::cout << "Password strength: Weak" << std::endl;
    } else {
        std::cout << "Password strength: Strong" << std::endl;
    }

    return 0;
}