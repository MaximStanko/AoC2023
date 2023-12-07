#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

const int MAX_STR_LEN = 1024;

int main()
{
    FILE* inp = fopen("input.txt", "r");

    int sum1 = 0, sum2 = 0, c = 1;
    int r, g, b, maxr, maxg, maxb, temp, subsum;
    bool impossible;
    int or = 12, og = 13, ob = 14;
    char* line = malloc(MAX_STR_LEN + 1); char* lptr;
    char* draw = malloc(MAX_STR_LEN + 1); char* dptr;
    char* part = malloc(MAX_STR_LEN + 1); char* pptr;

    while (fgets(line, MAX_STR_LEN, inp) != NULL) {
        line += 5;
        while (*line != ':')
            line += 1;
        line += 2;
        if (line[strlen(line) - 1] == '\n')
            line[strlen(line) - 1] = '\0';

        impossible = false;
        maxr = 0, maxg = 0, maxb = 0;

        draw = strtok_r(line, ";", &lptr);
        while (draw) {
            r = 0, g = 0, b = 0;

            part = strtok_r(draw, ",", &dptr);
            while (part) {
                if (part[0] == ' ')
                    part += 1;

                temp = atoi(strtok_r(part, " ", &pptr));
                part = strtok_r(NULL, " ", &pptr);
                
                if (!strcmp(part, "green")) g = temp;
                else if (!strcmp(part, "blue")) b = temp;
                else if (!strcmp(part, "red")) r = temp;

                part = strtok_r(NULL, ",", &dptr);
            }

            if (r + g + b > or + og + ob || r > or || g > og || b > ob) {
                impossible = true;
            }

            if (r > maxr) maxr = r;
            if (g > maxg) maxg = g;
            if (b > maxb) maxb = b;

            draw = strtok_r(NULL, ";", &lptr);
        }

        if (!impossible)
            sum1 += c;
        
        sum2 += maxr * maxg * maxb;

        c++;
    }

    printf("Sum: %d\n", sum1); // 2486
    printf("Bonus: %d\n", sum2); // 87984

    fclose(inp);

    return 0;
}