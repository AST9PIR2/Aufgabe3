#include <stdio.h>
#include "operations.h"
#include <stdlib.h>
#include <string.h>

int main() {

    printf("**************************************************************************************\n\n");
    printf("This calculator can process the following operations:  +,-,* and / , with integers\n");
    printf("Enter tmp to stop the calculator\n\n");
    printf("**************************************************************************************\n");

    char buffer[51];

    int input1;
    char input2;
    int input3;

    const char * string[] = {"number 1:","operator:","number 2:"};

    char tmp[51];

    while(1){
        start:
        for (int i = 0; i < 3; i++){
            printf("Please enter %s\n",string[i]);
            fgets(buffer,50,stdin);
            sscanf(buffer, "%50s", tmp);

            //Terminating the program by user input
            if(strcmp(tmp, "exit") == 0) {
                printf("**************************************************************************************\n\n");
                printf("Program terminated by user \n\n");
                printf("**************************************************************************************\n");
                return 0;
            }
            //Checking for allowed characters for corresponding input
            for (int a = 0; a < strlen(tmp); a++) {
                if (((tmp[a] < '0' || tmp[a] > '9') && (i == 0 || i == 2)) || (((tmp[a] < '*' || tmp[a] > '/') || (tmp[a] == ',') || (tmp[a] == '.')) && (i == 1))) {
                    printf("**************************************************************************************\n\n");
                    fprintf(stderr, "Falsche Eingabe!\n\n");
                    printf("**************************************************************************************\n");
                    goto start;
                }
            }

            //Assign tmp data to corresponding variables and check for undefined division through 0
            if (i == 0)  {
                input1 = atoi(tmp);
            }else if (i == 1) {
                input2 = (char)* tmp;
            }else if (i ==2) {
                input3 = atoi(tmp);
                if (input2 == '/' && input3 == 0) {
                    printf("**************************************************************************************\n\n");
                    fprintf(stderr, "ERROR: Dividing by zero is undefined!\n");
                    printf("**************************************************************************************\n");
                    break;
                }
            }
        }

        //Result output with differentiation between int(+,-,*) and float(/) output
        float result;
        int int_result = calc(input1,input3,input2,&result);
        printf("**************************************************************************************\n\n");
        if (input2 == '/') {
            printf("Result: %0.1f\n\n", result);
        }else{
            printf("Result: %i\n\n", int_result);
        }
        printf("**************************************************************************************\n");
    }
}
