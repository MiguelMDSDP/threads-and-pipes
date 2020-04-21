#include <stdio.h>
#include <stdlib.h>

void inputCallback();

void inputCallback() {
    FILE *pipe;
    char input[100];

    while (1) {
        setbuf(stdin, NULL);
        scanf("%[^\n]s", input);
        pipe = fopen("../pipes/inputs", "a");
        fprintf(pipe, "%s\n", input);
        fclose(pipe);
    }

    return 0;
}