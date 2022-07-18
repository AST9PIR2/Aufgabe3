#include <stdio.h>

int main() {
    int a = 0;
    for (int i = 2; i <= 1000; i = i + 8) {
        a = a+ i;
    }
    printf("i = %i\n", a);
    return 0;
}