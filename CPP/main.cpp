#include <iostream>

#include "foo.hpp"

int main() {
    const int a = 2;
    const int b = 3;
    std::cout << "Hello world!" << '\n';
    std::cout << "cpp::foo(" << a << ", " << b << ") " << cpp::foo(a, b)
              << '\n';
}
