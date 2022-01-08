//#include <stdlib.h>
#include <stdio.h>

int main() {
    int a = 8;
    int *b = &a;
    printf("%p\n", b);
    printf("%i\n", *b);

    int myarray[] = {1 ,2, 3,4};
    printf("%p\n",myarray);
    printf("%i\n",*(myarray));
    printf("%i\n",myarray[0]);
    return 0;
}