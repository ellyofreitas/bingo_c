
#pragma once

#include <stdlib.h>
#include <time.h>
#include "numeros.h"

int sortear(int *rack){

    srand(time(NULL));

    int buff = num_aleatorio_unico(rack, 75, 1, 75);

    rack[ buff - 1 ] = buff;

    return buff;
}

void print_rack(int *rack){
    printf("\nRack: ");
    for(int i = 0; i < 75; i++){
        if(i % 15 == 0)
            printf("\n");
        if(rack[i] != 0)
            printf("%d", rack[i]);
        else
            printf("_");
        printf("\t");
    }

    printf("\n\n");
}

void print_roleta(int *rack){
    printf("\nRoleta: ");
    for(int i = 0; i < 75; i++){
        if(i % 15 == 0)
            printf("\n");
        if(rack[i] != 0)
            printf("_");
        else
            printf("%d", i + 1);
        printf("\t");
    }
    printf("\n\n");
}

void destroy_rack(int *rack){
    free(rack);
}