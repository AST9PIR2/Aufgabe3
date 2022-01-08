#include <stdio.h>
#include <string.h>

int main() {

    //Create new file
    FILE *datei = fopen("integers_output.txt","w");

    //Check if file exists
    if (datei == NULL) {
        //Output of error code with description
        perror("Fehler: Konnte Datei nicht anlegen");
        return 1;
    }

    char zeile[255];

    //Output user instruction
    printf("Press ENTER without any character written to exit the program:\n");
    printf("Please enter your text:\n");

    //Endless loop
    while (1) {
        fgets(zeile, 255, stdin);
        //Interrupt endless loop with empty line,flush data and close file
        if (zeile[0] == '\n') {
            fflush(datei);
            fclose(datei);
            return 0;
        }
        //Write single numbers and number groups to file, new line in input stream results in new line in file.
        for (int i = 0; i <= strlen(zeile); i++) {
            if (zeile[i] >= '0' && zeile[i] <= '9') {
                fprintf(datei, "%c", zeile[i]);
                if (zeile[i + 1] < '0' || zeile[i + 1] > '9') {
                    fprintf(datei, " ");
                }
            }else if (zeile[i] == '\n') {
                fprintf(datei, "\n");
            }

        }
    }
}
