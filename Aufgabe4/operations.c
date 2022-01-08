
int calc(int number1,int number2,char operator, float* result) {
    int calculation = 0;
    //Checking for Operator, only + - * / defined
    if (operator == '+' ){
        calculation = number1 + number2;
    }else if (operator == '-'){
        calculation = number1 - number2;
    }else if (operator == '*'){
        calculation = number1 * number2;
    }else {
        *result = (float)number1 / (float)number2;
    }
    return calculation;
}
