
#pragma once

#include <stdlib.h>
#include "numeros.h"

int sortear(int *rack){

    int buff = num_aleatorio_unico(rack, 75, 1, 75);

    rack[ buff - 1 ] = buff;

    return buff;
}

void print_rack(int *rack){
    
    for(int i = 0; i < 75; i++){
        if(i % 15 == 0)
            printf("\n");
        if(rack[i] != 0)
            printf("%d ", rack[i]);
        else
            printf("_ ");
    }

    printf("\n\n");
}

void destroy_rack(int *rack){
    free(rack);
}