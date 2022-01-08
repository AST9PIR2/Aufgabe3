#include "xmas_sort.h"

void xmas_sort(int* array, const int n) {
    
    int counter = 0;

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

}
