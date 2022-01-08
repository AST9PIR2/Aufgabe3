#include <stdio.h>
#include <string.h>

int main() {
    char input_string[50] = "Hallo Welt";
    char *start_pointer = input_string;

    for (int i = 20; i < 127; i++) {
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