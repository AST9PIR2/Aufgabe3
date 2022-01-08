#include <stdio.h>
#include <string.h>

int main(int argc , char * argv[]) {

    //Checking for correct amount of arguments
    if(argc < 2){
        printf("\n***********************************************************************************\n\n");
        printf("\nInvalid input\n\nMake sure to type at least one argument!\n\n");
        printf("\n***********************************************************************************\n\n");

        return 1;
    }

    //Connecting the commandline data to a string
    char input_string[51];
    strcpy(input_string, argv[1]);
    for (int i = 2; i < argc; i++) {
        strcat (input_string," ");
        strcat (input_string,argv[i]);
    }

    //Make sure there is no buffer overflow
    unsigned long str_length = strlen(input_string);
    if ( str_length > 50) {
        printf("\n***********************************************************************************\n\n");
        printf("ERROR!!! BUFFER OVERFLOW!!! Max length string: 50 letters!\n\n");
        printf("***********************************************************************************\n\n");

        return 1;
    }

    //Check for matches and count of frequency
    char * start_pointer = input_string;
    for (int i = 0; i < 128; i++) {
        int counter = 0;
        char text;
        for (int e = 0; e < strlen(start_pointer); e++) {
            if (*(start_pointer+e) == i) {
                counter++;
                text = *(start_pointer+e);
            }
        }
        if (counter > 0) {
            printf("> Zeichen: '%c' - Häufigkeit: %i\n", text, counter);
        }
    }


    return 0;
}