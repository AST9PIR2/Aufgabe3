#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct student_data{
    char name[50];
    char surname[50];
    struct inscription_data {
        char course[50];
    }inscribed_course[3];

} student_inscribed[31];

struct student_presence{
    char name[50];
    char surname[50];
    unsigned int log_on_time;
    unsigned int log_out_time;

} product[31];

//Checking file for data and sort them in s struct
int check_student_data() {
    //Open text file
    FILE *datei = fopen("/mnt/c/Users/Pirmin.000/OneDrive - mci4me.at/Dokumente/"
                        "Methoden der Softwareentwicklung/Aufgabe6/students.txt","r");


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
        sscanf(buffer, "%49[^;];%49[^;];%49[^,\n],%49[^,\n],%49[^,\n]",
               student_inscribed[counter].name, student_inscribed[counter].surname, student_inscribed[counter].inscribed_course[0].course,
               student_inscribed[counter].inscribed_course[1].course, student_inscribed[counter].inscribed_course[2].course);
        fflush(datei);
        //Overflow protection, ignore any line after 20 lines read
        if (counter > 30) {
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
    return 0;

}

//Checking file for data and sort them in s struct
int check_grocery_data(){

    //Open text file
    FILE *datei = fopen("/mnt/c/Users/Pirmin.000/OneDrive - mci4me.at/Dokumente/"
                        "Methoden der Softwareentwicklung/Aufgabe6/webinar.txt","r");


    //Check if file exists
    if (datei == NULL) {
        //Output of error code with description
        fprintf(stderr,"Lesefehler_webinar.txt");
        return 1;
    }


    char buffer[50];
    int counter = 0;

    //Read from file and store data in structure
    while (fgets( buffer, 255 , datei) != NULL) {
        sscanf(buffer, "%49[^:]:%49[^:]:%i:%i[^\n]", product[counter].name, product[counter].surname,
               & product[counter].log_on_time, & product[counter].log_out_time );
        fflush(datei);
        //Overflow protection, ignore any line after 20 lines read
        if (counter > 30) {
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
    return 0;

}


int main(int argc , char * argv[]) {

    //Checking for enough arguments
    if(argc != 3){
        fprintf(stderr,"Eingabefehler\n");
        return 1;
    }

    char course[50];
    strcpy(course, argv[1]);
    int presence_time = atoi(argv[2]);

    if (check_student_data() == 1 || check_grocery_data() == 1 ) {
        return 1;
    }

    int test = 0;

    //Checking if course ist listed
    for (int i = 0; i <30; i++) {
        for ( int a = 0; a < 4; a++) {
            if(strcmp(student_inscribed[i].inscribed_course[a].course, course)==0) {
                test = 1;
            }
        }
    }
    if (test == 0)  {
        fprintf(stderr,"Eingabefehler: Course not listed!\n");
        return 1;
    }

    //Sorting corresponding input parameters
    for ( int i = 0; i < 30; i++) {
        int test_counter = 0;
        for (int a = 0; a < 30; a++) {
            test_counter++;
            if((strcmp(student_inscribed[i].name, product[a].name ) == 0) && (strcmp(student_inscribed[i].surname, product[a].surname ) == 0) ) {
                test_counter = 0;
                for ( int b = 0; b < 3; b++) {
                    if (strcmp(student_inscribed[i].inscribed_course[b].course, course) == 0 ) {
                        if ((((product[a].log_out_time - product[a].log_on_time) / 60) ) < presence_time*0.75){
                            printf("%s %s: %s,  %i Minuten \n", product[a].name, product[a].surname, student_inscribed[i].inscribed_course[b].course, (product[a].log_out_time - product[a].log_on_time) / 60);
                        }else if ((((product[a].log_out_time - product[a].log_on_time) / 60) ) >= presence_time*0.75){
                            continue;
                        }
                    }
                }
            }

        }if (test_counter == 30){
            printf("%s %s: nicht anwesend \n", student_inscribed[i].name, student_inscribed[i].surname);
        }
    }
    return 0;
}
