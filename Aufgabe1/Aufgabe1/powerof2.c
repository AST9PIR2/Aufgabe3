#include <stdio.h>
#include <stdlib.h>

int main(int argc , char * argv[] ) {
// Program needs an argument form command line!
    if(argc != 2){
        return 0;
    }

    int num1 = atoi(argv[1]);
    int save_num1 = num1;
    int counter = 0;

    if (num1 == 0) {
        return 0;
    }

    while (num1 > 0) {
        if (num1 % 2 == 0 || num1 == 1) {
            num1 = num1 / 2;
        }else {
            return 0;
        }
        counter += 1;
    }
    printf("Bei der eingegebenen Zahl %d, handelt es sich um eine Zweierpotenz mit dem Exponent: %d\n", save_num1 , counter-1);
}