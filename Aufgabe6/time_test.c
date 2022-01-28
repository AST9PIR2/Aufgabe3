
// imported from https://www.epochconverter.com/programming/c

#include <stdio.h>
#include <time.h>

int main(void)
{
    time_t rawtime = 1611598481 - 1611594206;
    struct tm  ts;
    char       buf[80];

    // Format time, "ddd yyyy-mm-dd hh:mm:ss zzz"
    ts = *localtime(&rawtime);
    strftime(buf, sizeof(buf), "%a %Y-%m-%d %H:%M:%S %Z", &ts);
    printf("%s\n", buf);
    printf("%i\n", (1611598481 - 1611594206)/60);
    return 0;
}