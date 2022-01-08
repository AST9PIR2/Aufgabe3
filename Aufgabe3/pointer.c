//#include <stdlib.h>
#include <stdio.h>

int main() {

    int a = 30;
    int * b = &a;

    printf("%p\n", &a);
    printf("%i\n", *b);

    return 0;
}