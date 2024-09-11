#include "reverse.h"
#include <iostream>
#include <string>

using std::string;

string reverse(string str) {
    string new_str = str;
    size_t len = new_str.length();
    for (size_t i = 0; i < len / 2; i++) {
        char temp = new_str[len - 1 - i];
        new_str[len - 1 - i] = new_str[i];
        new_str[i] = temp;
    }
    return new_str;
}