#include <stdio.h>
#include <stdlib.h>

struct person_data_read_test{
    char name[50];
    char surename[50];
    unsigned int age;
    struct hobby {
        char hobby[50];
    }hobby[4];

} id[50];

int main() {

    FILE *datei = fopen("/mnt/c/Users/Pirmin.000/OneDrive - mci4me.at/Dokumente/Methoden der Softwareentwicklung/Aufgabe4/persons_input.txt","r");

    //Check if file exists
    if (datei == NULL) {
        //Output of error code with description
        perror("Fehler: Konnte Datei nicht anlegen");
        return 1;
    }

    char buffer[50];
    char test[50];
    fgets( buffer, 50 , datei);

    sscanf(buffer, "%49[^;];%49[^;];%d", id[0].name, id[0].surename, & id[0].age);

    printf("%s;\n%s;\n%d", id[0].name, id[0].surename,  id[0].age);

    return 0;
}