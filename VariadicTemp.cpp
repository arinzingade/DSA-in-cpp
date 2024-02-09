
#include <iostream>
using namespace std;

void printValues() {}

template <typename T, typename... Args>
void printValues(T first, Args... args) {
    cout << first << " ";
    printValues(args...);
}

int main() {
    printValues(1,2,3,"Hello World", 4.5);

    return 0;
}