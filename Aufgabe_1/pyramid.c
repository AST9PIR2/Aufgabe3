#include <stdio.h>

void stern(){

    printf("*");

}

void leerzeichen(){

    printf(" ");

}

int main() {

    int counter = 1;
    for (int i = 3; i > 0; i--) {
        int a = 2;
        while(a <= i) {
            leerzeichen();
            a += 1;
        }
        int b = 2 + counter;
        while(i <= b) {
            stern();
            b -= 1;
        }
        printf("\n");
        counter += 1;

    }
    return 0;
}