#include <stdio.h>
#include <stdlib.h>

char test() {

    printf("\nInvalid input\n\nPlease enter one number!\n\n");

    return 0;
}

int main(int argc , char **argv[] ) {

    if(argc != 2){
        test();
        return 0;
    }

    int num1 = atoi(argv[1]);

    if (num1 % 2 == 0) {
        printf("False\n");

    } else {
        printf("True\n");

    }
}