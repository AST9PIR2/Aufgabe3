#include <stdio.h>

struct snow_data{
    char ski_resort[50];
    struct day_data {
        int snow_depth[50];
    }day[8];

} snow[30];

//Checking file for data and sort them in struct
int  file_handler(char * path, char * authorization, int number_of_files) {

    char filename[200];
    int file_counter = 1;

    for (int i = file_counter; i < number_of_files+1; i++){

        //Prepare for variable filename
        sprintf(filename, path, file_counter);
        //Open text file
        FILE *datei = fopen(filename,authorization);

        //FILE *datei = fopen(path,authorization);

        //Check if file exists
        if (datei == NULL) {
            //Error output with description
            fprintf(stderr,"*** ERROR! *** Could not open: %s\n",path);
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
                printf("The programm will only process the first 30 lines and ignore the rest\n\n");
                break;
            }
            counter++;
        }
        fclose(datei);
        file_counter++;
    }
    return 0;
}

int main() {

    //File path. If multiple files with continually numbering, replace number with %d
    char * path = "/mnt/c/Users/Pirmin.000/OneDrive - mci4me.at/Dokumente/Methoden der Softwareentwicklung/Aufgabe6/snow_data/%d.txt";
    //Required rights
    char * authorization = "r";
    int number_of_files = 1;


    //Check if function exit with error
    if (file_handler(path, authorization, number_of_files) == 1) {
        return 1;
    }

    for (int i = 0; i < number_of_files; i++) {
        printf("%s: ",snow[i].ski_resort);
        for (int a = 0; a < number_of_files; a++) {
            printf("%i ", *snow[i].day[a].snow_depth);
        }
        printf("\n");
    }


    return 0;
}
