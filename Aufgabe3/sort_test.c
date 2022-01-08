#include <stdio.h>
#include "xmas_sort.h"

void vertausche2(int *a, int *b) {
    printf("Calling vertausche2(%p, %p)\n", a, b);
    int tmp = *a;
    *a = *b;
    *b = tmp;
    printf("Ergebnis vertausche2: a = %d, b = %d\n", *a, *b);
}


int main() {

    int array[] = {9, 4, 6, 2, 7, 4, 3, 6};
    int counter = 0;
    int pointer = * (array+counter);
    int n = sizeof(array)/sizeof(int);


    //printf("%i\n",array[counter]);
    //printf("%i\n", *array);
    //printf("%i\n", pointer);
    //printf("%i\n", * (array + counter ));

    printf("a[] = { ");
    for (int* e = array; e < (array + n); e++) {
        printf("%d, ", *e);
    }
    printf("}\n");

    while (counter < n-1) {
        if ( array[counter] <= array[counter+1]) {
            counter++;
        } else if (array[counter] > array[counter+1]) {
            int tmp = array[counter+1];
            array[counter+1] = array[counter];
            array[counter] = tmp;
            if (counter == 0) {
                counter++;
            } else {
                counter--;
            }
        }
    }
    printf("a[] = { ");
    for (int* e = array; e < array + n; e++) {
        printf("%i, ", *e);
    }
    printf("}\n");

    return 0;
}

