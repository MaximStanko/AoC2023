#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const int MAX_STR_LEN = 256;

int isdig(char* str) {
    if (str[0] >= '0' && str[0] <= '9') 
        return str[0] - '0';

    char digstrings[] = "one,two,three,four,five,six,seven,eight,nine";

    char intstr[MAX_STR_LEN];
    char* cmpstr;
    int c = 1;
    int cmpstrlen;

    cmpstr = strtok(digstrings, ",");

    while (cmpstr != NULL) {
        cmpstrlen = strlen(cmpstr);
        strncpy(intstr, str, cmpstrlen);
        intstr[cmpstrlen] = '\0';

        if (!strcmp(cmpstr, intstr)) {
            return c;
        }

        cmpstr = strtok(NULL, ",");
        c++;
    }

    return -1;
}

int main()
{
    FILE* inp = fopen("input.txt", "r");

    int sum = 0;
    char line[MAX_STR_LEN + 1];
    
    int linelen, firstdig, lastdig, result;

    while (fgets(line, MAX_STR_LEN, inp)) {
        linelen = strlen(line);

        for (int i = 0; i < linelen; i++) {
            result = isdig(line + i);
            if (result != -1) {
                firstdig = result;
                break;
            } 
        }

        for (int i = linelen - 1; i >= 0; i--) {
            result = isdig(line + i);
            if (result != -1) {
                lastdig = result;
                break;
            } 
        }

        sum += 10 * firstdig + lastdig;
    }

    fclose(inp);

    printf("Sum: %d\n", sum); //54431

    return 0;
}