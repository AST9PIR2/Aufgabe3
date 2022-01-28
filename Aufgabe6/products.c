#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct grocery_data{
    char item[50];
    char store[50];
    float weight;
    float price;

} product[36];

//Checking file for data and sort them in s struct
int check_grocery_data(){

    //Open text file
    FILE *datei = fopen("/mnt/c/Users/Pirmin.000/OneDrive - mci4me.at/Dokumente/"
                        "Methoden der Softwareentwicklung/Aufgabe6/products.txt","r");


    //Check if file exists
    if (datei == NULL) {
        //Output of error code with description
        fprintf(stderr,"Lesefehler: products.txt not found!\n");
        return 1;
    }


    char buffer[50];
    int counter = 0;

    //Read from file and store data in structure
    while (fgets( buffer, 255 , datei) != NULL) {
        sscanf(buffer, "%49[^;];%49[^;];%f;%f[^\n]", product[counter].item, product[counter].store, & product[counter].weight, & product[counter].price );
        fflush(datei);
        //Overflow protection, ignore any line after 36 lines read
        if (counter > 35) {
            printf("**************************************************************************************\n\n");
            printf("Attention! This Program can only handle files with max. 36 lines\n");
            printf("Your input file has more than 36 lines\n");
            printf("The programm will only process the first 36 lines and ignore the rest\n\n");
            printf("**************************************************************************************\n");
            break;
        }
        counter++;
    }

    fclose(datei);
    return 0;


}


int main (int argc , char * argv[]){

    //Checking for enough arguments
    if(argc < 2 ){
        fprintf(stderr,"Eingabefehler\n");
        return 1;
    }

    //Checking if file reading is ok
    if (check_grocery_data() == 1 ) {
        return 1;
    }

    //Checking for cheapest prize of corresponding item
    for (int i = 1; i < argc; i++) {
        float temp = 1000;
        char item[50] = "default";
        char store[50];
        for ( int a = 0; a < 36; a++) {
            if (strcmp(product[a].item, argv[i]) == 0) {
                if (product[a].price/product[a].weight < temp) {
                    temp = product[a].price/product[a].weight;
                    strcpy(item, product[a].item);
                    strcpy(store,product[a].store);
                }
            }
        }
        //Checking if item is in list
        if (strcmp(item,"default") == 0){
            printf("Produkt '%s' nicht gefunden\n",argv[i]);
        }else {
            printf("%s: %0.1f €/kg, %s  \n",item, temp, store);
        }

    }


    return 0;
}