#include <stdio.h>
#include <pthread.h>

#include "threads/lib/broker.h"
#include "threads/lib/command.h"
#include "threads/lib/input.h"
#include "threads/lib/print.h"

int main() {
    pthread_t broker_id;
    pthread_t command_id;
    pthread_t print_id;
    pthread_t input_id;

    pthread_create(&broker_id, NULL, brokerCallback, NULL);
    pthread_create(&command_id, NULL, commandCallback, NULL);
    pthread_create(&print_id, NULL, printCallback, NULL);
    pthread_create(&input_id, NULL, inputCallback, NULL);

    while (1);

    return 0;
}