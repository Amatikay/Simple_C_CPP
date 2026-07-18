#include <stdio.h>

#include "foo.h"

int main(void) {
    const int a = 2;
    const int b = 3;
    printf("Hello world!\n");
    printf("foo(%d, %d) %d\n", a, b, foo(a, b));
    return 0;
}
