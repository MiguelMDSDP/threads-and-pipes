#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../lib/command.h"

void removeCommandInputLine();

void *commandCallback(void *param) {
    while (1) {
        FILE *inputPipe;
        char input[100];

        inputPipe = fopen("pipes/commands.txt", "r");
        if (fgets(input, sizeof(input), inputPipe) == NULL) {
            fclose(inputPipe);
            continue;
        }
        
        printf("[COMMAND-THREAD]: %s", input);
        fclose(inputPipe);

        removeCommandInputLine();
    }
}

void removeCommandInputLine() {
    char removed[100], copy[100];
    FILE *aux, *pipe;

    aux = fopen("pipes/auxcmd.txt", "w");
    pipe = fopen("pipes/commands.txt", "r");
    fgets(removed, 100, pipe);
    while (fgets(copy, 100, pipe) != NULL) fputs(copy, aux);
    fclose(aux);
    fclose(pipe);

    aux = fopen("pipes/auxcmd.txt", "r");
    pipe = fopen("pipes/commands.txt", "w");
    while (fgets(copy, 100, aux) != NULL) fputs(copy, pipe);
    fclose(aux);
    fclose(pipe);
}