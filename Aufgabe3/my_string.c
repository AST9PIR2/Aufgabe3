#include <string.h>
#include "my_string.h"

int string_cmp(const char* str1, const char* str2) {

    if (str1 == str2) {
        return 1;
    }

    return 0;
}

unsigned int string_len(const char* str) {

    return strlen(str);
}

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

char *string_chr(const char* str, const char c) {

    for (int i = 0; i <= strlen(str); i++) {
        if (str[i] == c) {
            return (char *)& str[i];
        }
    }

    return 0;
}