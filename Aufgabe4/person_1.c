#include <stdio.h>
#include <string.h>

struct data {
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

    //strcpy(id[0].name, "Pirmin");
    //strcpy(id[0].surname, "Aster");

    int struct_counter = 0;
    int id_counter = 0;
    char temp[50];
    int temp_counter = 0;

    char zeichen;
    printf("Datei-Inhalt 1: \n");
    while ((zeichen = fgetc(datei)) != EOF) {
        temp[temp_counter] = 0;
        temp[temp_counter] +=zeichen;
        printf("x-%c", zeichen);
        if (zeichen == ';'&& struct_counter == 0) {
            strcat(id[0].name, temp);
            printf("xxxxxxxxxxxxxxxxxxxxxxxx_%s",temp);
            struct_counter++;
            printf("xxxxxxxxxxxxxxxxxxxxxxxx_%s",id[0].name);
        }
        fputc(zeichen, stdout);
    }
    fputc('\n', stdout);


    fclose(datei);
    return 0;
}