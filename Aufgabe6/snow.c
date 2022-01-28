#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct snow_data{
    char ski_resort[50];
    struct day_data {
        int snow_depth[50];
    }day[8];

} snow[30];

//Checking file for data and sort them in s struct
int collect_snow_data() {


    char filename[113];
    int file_counter = 1;

    for (int i = file_counter; i < 9; i++){

        //Prepare for variable filename
        sprintf(filename, "/mnt/c/Users/Pirmin.000/OneDrive - mci4me.at/Dokumente/Methoden der Softwareentwicklung/Aufgabe6/snow_data/%d.txt", file_counter);
        //Open text file
        FILE *datei = fopen(filename,"r");
        //printf("%s\n",filename);


        //Check if file exists
        if (datei == NULL) {
            //Output of error code with description
            fprintf(stderr,"Lesefehler_students.txt");
            return 1;
        }


        char buffer[50];
        int counter = 0;

        //Read from file and store data in structure
        while (fgets( buffer, 255 , datei) != NULL) {
            sscanf(buffer, "%49[^;];%i[^\n]",
                   snow[counter].ski_resort, snow[counter].day[file_counter-1].snow_depth);
            fflush(datei);

            //Overflow protection, ignore any line after 30 lines read
            if (counter > 30) {
                printf("**************************************************************************************\n\n");
                printf("Attention! This Program can only handle files with max. 30 lines\n");
                printf("Your input file has more than 30 lines\n");
                printf("The programm will only process the first 30 lines and ignore the rest\n\n");
                printf("**************************************************************************************\n");
                break;
            }
            counter++;
        }
        fclose(datei);
        file_counter++;
    }
    return 0;
}

int main(){

    if (collect_snow_data() == 1 ) {
        return 1;
    }

    char buffer[50];
    char resort[50];
    char day[50];
    int test = 0;
    int save = 0;

    //Asking for user input
    printf("> Geben Sie einen Ort an:");
    fgets( buffer, 255 , stdin);
    sscanf(buffer, "%s", resort);

    //Checking if skiresort ist listed
    for (int i = 0; i <8; i++) {
        if (strcmp(snow[i].ski_resort, resort) == 0) {
            save = i;
            test = 1;
        }
    }
    if (test == 0)  {
        fprintf(stderr,"Eingabefehler: Skiresort not listed!\n");
        return 1;
    }

    //Checking for correct integer input
    printf("> Geben Sie einen Tag an:");
    fgets(buffer, 255, stdin);
    sscanf(buffer, "%s", day);
    for (int i = 0; i < strlen(day); i++) {
        if (day[i] < '0' || day[i] > '8') {
            fprintf(stderr,"Eingabefehler: Not a integer!\n");
            return 1;
        }else if (atoi(day) > 8){
            fprintf(stderr,"Eingabefehler: Only 8 days listed\n");
            return 1;
        }
    }

    //Open new file with variable naming
    char filename[200];
    sprintf(filename, "/mnt/c/Users/Pirmin.000/OneDrive - mci4me.at/Dokumente/Methoden der Softwareentwicklung/Aufgabe6/snow_data/%s_%i.txt", resort, atoi(day));

    FILE *datei = fopen(filename,"wr");

    //Checking if file can be opened
    if (datei == NULL) {
        //Output of error code with description
        fprintf(stderr,"Lesefehler_%s_%i.txt", resort, atoi(day));
        return 1;
    }
    int sum = 0;

    //Writing data to file
    for (int a = 0; a < atoi(day);a++){
        fprintf(datei,"Tag %i: %i\n", (a+1),*snow[save].day[a].snow_depth);
        sum = sum + *snow[save].day[a].snow_depth;
    }
    fprintf(datei,"Summe: %i\n", sum);
    fclose(datei);
    printf("> Die Ergebnisse Ihrer Anfrage wurden erfolgreich in eine Datei geschrieben.");

    return 0;
}