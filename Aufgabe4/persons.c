#include <stdio.h>
#include <string.h>

struct person_data{
    char name[50];
    char surname[50];
    unsigned int age;
    struct hobby {
        char hobby[50];
    }hobby[4];

} id[21];

int main() {

    //Open text file
    FILE *datei = fopen("/mnt/c/Users/Pirmin.000/OneDrive - mci4me.at/Dokumente/"
                        "Methoden der Softwareentwicklung/Aufgabe4/persons_input.txt","r");

    //Check if file exists
    if (datei == NULL) {
        //Output of error code with description
        perror("Fehler: Konnte Datei nicht anlegen");
        return 1;
    }

    char buffer[50];
    int counter = 0;

    //Read from file and store data in structure
    while (fgets( buffer, 255 , datei) != NULL) {
        sscanf(buffer, "%49[^;];%49[^;];%i;%49[^,\n],%49[^,\n],%49[^,\n],%49[^,\n],%49[^,\n]",
               id[counter].name, id[counter].surname, & id[counter].age, id[counter].hobby[0].hobby,
               id[counter].hobby[1].hobby,id[counter].hobby[2].hobby, id[counter].hobby[3].hobby,
               id[counter].hobby[4].hobby);
        fflush(datei);
        //Overflow protection, ignore any line after 20 lines read
        if (counter > 19) {
            printf("**************************************************************************************\n\n");
            printf("Attention! This Program can only handle files with max. 20 lines\n");
            printf("Your input file has more than 20 lines\n");
            printf("The programm will only process the first 20 lines and ignore the rest\n\n");
            printf("**************************************************************************************\n");
            break;
        }
        counter++;
    }
    fclose(datei);

    char hobby[] = "Tanzen";
    //min_age exclusive
    int min_age = 20;
    //max age inclusive
    int max_age = 30;

    //Output surnames with common hobbies in a certain age range
    printf("The following persons are between %i and %i and like to %s:\n",min_age, max_age, hobby);
    for (int i = 0; i <= 19; i++) {
        for (int a = 0; a <=4; a++) {
            if ((strcmp(id[i].hobby[a].hobby, hobby) == 0 ) && (id[i].age >= (min_age +1) && id[i].age <= max_age )){
                printf("%s\n",id[i].surname);
            }
        }
    }

    return 0;
}