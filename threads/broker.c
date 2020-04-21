#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void brokerCallback();
void removeInputLine();

int main() {
    brokerCallback();
    return 0;
}

void brokerCallback() {
    while (1) {
        FILE *inputPipe, *outputPipe;
        char input[100], output[100];

        inputPipe = fopen("pipes/inputs.txt", "r");
        if (fgets(input, sizeof(input), inputPipe) == NULL) {
            fclose(inputPipe);
            continue;
        }
        
        if (input[0] != 'c' || input[1] != 'm' || input[2] != 'd' || input[3] != ' ') {
            outputPipe = fopen("pipes/logs.txt", "a");
            strcpy(output, input);
        } else {
            outputPipe = fopen("pipes/commands.txt", "a");
            int j = 0;
            for (int i = 4; input[i] != '\0'; i++) {
                output[j] = input[i];
                j++;
            }
            output[j] = '\0';
        }
        
        fprintf(outputPipe, "%s", output);
        fclose(inputPipe);
        fclose(outputPipe);

        removeInputLine();
    }
}

void removeInputLine() {
    char removed[100], copy[100];
    FILE *aux, *pipe;

    aux = fopen("pipes/auxinp.txt", "w");
    pipe = fopen("pipes/inputs.txt", "r");
    fgets(removed, 100, pipe);
    while (fgets(copy, 100, pipe) != NULL) fputs(copy, aux);
    fclose(aux);
    fclose(pipe);

    aux = fopen("pipes/auxinp.txt", "r");
    pipe = fopen("pipes/inputs.txt", "w");
    while (fgets(copy, 100, aux) != NULL) fputs(copy, pipe);
    fclose(aux);
    fclose(pipe);
}