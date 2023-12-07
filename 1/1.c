#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const int MAX_STR_LEN = 256;

int main()
{
    FILE* inp = fopen("input.txt", "r");

    int sum = 0;
    char line[MAX_STR_LEN + 1];
    
    int linelen, firstdig, lastdig;

    while (fgets(line, MAX_STR_LEN, inp)) {
        linelen = strlen(line);

        for (int i = 0; i < linelen; i++) {
            if (line[i] >= '0' && line[i] <= '9') {
                firstdig = line[i] - '0';
                break;
            }
        }

        for (int i = linelen - 1; i >= 0; i--) {
            if (line[i] >= '0' && line[i] <= '9') {
                lastdig = line[i] - '0';
                break;
            }
        }

        sum += 10 * firstdig + lastdig;
    }

    fclose(inp);

    printf("Sum: %d\n", sum); // 55477

    return 0;
}