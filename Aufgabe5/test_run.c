#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int partition (int arr[], int low, int high) {
    int * pivot = &arr[high];
    int i = low - 1;

    for(int j = low; j <= high-1; j++){


        if (arr[j] <= *pivot)
        {
            i++;
            //int * t = &arr[i];
            arr[i] = arr[j];
        }
    }
    int * t = &arr[i + 1], arr[i + 1] = arr[high];
    return (i + 1);
}





void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {


        int pi = partition(arr, low, high);



        quickSort(arr,low,(pi - 1));
        quickSort(arr,(pi + 1),high);
    }
}


void printArray(int arr[], int size)
{

    for(int i = 0; i <= size-1; i++){
        printf("%d", arr[i]);
        printf("\t");
    }
}


int main()
{
    int arr[] = {4, 6, 2, 11, 3, 7};
    int n = sizeof(arr)/sizeof(arr[0]);
    quickSort(arr,0,(n-1));
    printf("\n");
    printArray(arr, n);
    printf("\n");
    return 0;
}