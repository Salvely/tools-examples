#include "reverse.h"
#include <iostream>
using std::cout;
using std::endl;
using std::string;

int main(void) {
    string str = "hello";
    string new_str = reverse(str);
    cout << new_str << endl;
}