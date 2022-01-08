#include <stdio.h>
#include <string.h>
#include "my_string.h"

void string_rev(unsigned char* str) {

    int counter = 0;
    const char * c = (const char *)str;
    unsigned char temp[strlen(c)];


    for (int i = strlen(c)-1; i >= 0; i--) {
        temp[counter] = str[i];
        counter++;
    }

    memcpy((void *)str, temp, sizeof(temp) );

}

void test_string_rev(const char* str) {
    // First we need to copy the string into a memory region that is write-enabled
    unsigned char tmp[strlen(str) + 1];
    memcpy(tmp, str, sizeof(tmp));
    string_rev(tmp);
    printf("string_rev(\"%s\"): %s\n", str, tmp);

}

int main() {

    //test_string_rev("");
    test_string_rev("Hallo Welt!");
    //test_string_rev("X");
    //test_string_rev("blabla");

}