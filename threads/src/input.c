#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "../lib/input.h"

void *inputCallback(void *param) {
    FILE *pipe;
    char input[100];

    while (1) {
        setbuf(stdin, NULL);
        printf("$ ");
        scanf("%[^\n]s", input);
        pipe = fopen("pipes/inputs.txt", "a");
        fprintf(pipe, "%s\n", input);
        fclose(pipe);
        sleep(0.7);
    }

    return 0;
}