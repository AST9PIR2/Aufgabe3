#include <stdio.h>
#include <stdlib.h>

int main(int argc , char * argv[] ) {
    //Checking for correct amount of arguments
    if(argc != 2){
        printf("\nInvalid input\n\nPlease enter one number!\n\n");
        return 1;
    }

    int loop = atoi(argv[1]);
    int counter = 1;
    //Checking for a valid input greater than 0
    if (loop < 1){
        printf("\nInvalid input\n\nPlease enter a number greater than 0!\n\n");
        return 1;
    }

    for (int i = loop; i > 0; i--) {
        int a = 2;
        while(a <= i) {
            printf(" ");
            a ++;
        }
        int b = (loop-1) + counter;
        while(i <= b) {
            printf("*");
            b --;
        }
        printf("\n");
        counter ++;
    }
    return 0;
}