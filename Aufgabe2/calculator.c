#include <stdio.h>
#include "operations.h"
#include <stdlib.h>


int main(int argc , char * argv[]) {
    //Checking for correct amount of arguments
    if(argc != 4){
        printf("\nInvalid input\n\nPlease enter something like 5 + 5 !\n\n");
        return 1;
    }
    //Checking if calc function is finishing without error
    int calc_value = calc(atoi(argv[1]),atoi(argv[3]),*(argv[2]));
    if (calc_value == -2147483648) {
        return 1;
    }
    printf("Result: %i\n", calc_value);
    return 0;
}
