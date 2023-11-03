#include <iostream>

int main() {
    int i = 5, *p;

    p = &i;

    std::cout << p << " " << *p+2 << " " << 3**p;
    
    return 0;
}