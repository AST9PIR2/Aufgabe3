#include <stdio.h>
#include <string.h>


int main(){

    char buffer[51];

    printf("***********************************************************************************\n\n");
    printf("This Program converts a string with lower- and upper-, to all upper case letters.\n\n");
    printf("***********************************************************************************\n\n");
    printf("Please enter your string: ");
    scanf("%[^\n]50s", buffer);

    unsigned long str_length = strlen(buffer);

    if ( str_length > 49) {
        printf("\n***********************************************************************************\n\n");
        printf("ERROR!!! BUFFER OVERFLOW!!! Max length string: 49 letters!\n\n");
        printf("***********************************************************************************\n\n");

        return 1;
    }


    for (int i = 0; i < str_length; i++) {
        if (buffer[i] >= 'a' && buffer[i] <= 'z') {
            printf("%c", buffer[i] - 32);
        }
        else {
            printf("%c", buffer[i] );
        }
    }


    return 0;
}


