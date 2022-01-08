#include <stdio.h>

int calc(int number1,int number2,char operator) {
    int result;
    //Checking for Operator, only + - * / defined
    if (operator == '+' ){
        result = number1 + number2;
    }else if (operator == '-'){
        result = number1 - number2;
    }else if (operator == '*'){
        result = number1 * number2;
    }else if (operator == '/'){
        if (number2 <1){
            printf("\nERROR: Dividing by zero is undefined\n");
            return -2147483648; //Error code delivered via smallest int
        }
        result = number1 / number2;
    }else {
        printf("\nERROR: Operator undefined\n\nFollwing operators are valid + - '*' /\n");
        return -2147483648; //Error code delivered via smallest int
    }
    return result;
}
