#include <stdio.h>


void foo(const int* input, int array_size, float* average, float * variance) {

    float sum_average = 0;
    float result_variance = 0;

    for (int i = 0; i < array_size; i++) {
        sum_average += input[i];
    }

    *average = sum_average / array_size;

    for (int x = 0; x < array_size; x++){
        result_variance += ((input[x]-(*average)) * (input[x]-(*average)) / array_size);
    }

    *variance = result_variance;


}

int main(){

    printf("***********************************************************************************\n\n");
    printf("This Program calculates average and variance of a entered integer array.\n");
    printf("A non numeric input will crash the Program!!!\n\n");
    printf("***********************************************************************************\n\n");

    int array_size;
    int counter = 0;
    float average = 0;
    float variance = 0;

    printf("Please enter array size: ");
    scanf("%i", &array_size);

    int array[array_size];
    int add_to_array;

    while (counter < array_size) {
        printf("Please enter array element #%i:\n", counter + 1);
        scanf("%i", &add_to_array);
        array[counter] = add_to_array;
        counter++;
    }
    printf("Entered array: {");
    for (int i = 0; i < counter; i++) {
        printf("%d", array[i]);
        if (i != counter - 1) {
            printf(",");
        }
    }
    printf(" }\n");

    foo(array, array_size, &average,&variance);
    printf("The average of the array is: %.1f\n", average);
    printf("The variance of the array is: %.1f\n", variance);


    return 0;
}

