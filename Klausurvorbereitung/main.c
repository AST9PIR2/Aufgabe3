#include <stdio.h>


int main(int argc, char * argv[]) {

    //Checking for enough arguments
    if(argc < 2 ){
        fprintf(stderr,"Eingabefehler\n");
        return 1;
    }

    int b[] = {5,6};
    int * a = b;

    printf("%s\n",argv[1]);
    printf("%s\n",argv[2]);
    printf("%s\n",argv[3]);

    printf("%p\n",&b[0]);
    printf("%p\n",&b[0]+1);
    printf("%i\n",b[0]);
    printf("%i\n",b[1]);
    printf("%i\n",b[0]+1);
    printf("%lu\n",sizeof(long));
    //printf("%i",b[0]);


    //test( *b);


    printf("Hello, World!\n");

    // oft ist es so, dass man die formatierte Eingabe, die scanf anbietet, trotzdem nutzen will
    // In diesem Fall kann man fgets mit sscanf kombinieren
    // D.h. im ersten Schritt liest man eine Zeile mit fgets ein,
    // und im zweiten Schritt kann man dann die eingelesene Zeile mit sscanf parsen;

    // Dies repräsentiert unsere mit fgets eingelesene Zeile
    char zeile[] = "1234.3 4321 Hallo";

    // Mit sscanf können wir nun diese Zeile parsen
    float f;
    int i;
    char s[256];
    sscanf(zeile, "%f %d %s", &f, &i, s);

    printf("f = %f, i = %d, s = %s\n", f, i, s);


    return 0;
}
