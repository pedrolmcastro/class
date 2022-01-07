#include "Example.h"

#include <stdlib.h>
#include <stdio.h>


int main() {
    Example *first = new(Example, 1, 2);
    puts("FIRST OBJECT");
    call(first, method);

    Example *second = new(Example, -1, -2);
    puts("SECOND OBJECT");
    call(second, method);

    delete(first);
    delete(second);

    return EXIT_SUCCESS;
}
