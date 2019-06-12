#pragma once

#include<stdlib.h>
#include<stdbool.h>
#include<time.h>

bool num_exists(int num, int *p, int n){
    for(int i = 0; i < n; i++)
        if(num == p[i])
            return true;
   return false;
}

int num_aleatorio(int menor, int maior) {
    return rand() % ((maior + 1) - menor) + menor;
}

int num_aleatorio_unico(int *p, int n, int inicio, int limite){
    
    int random_buff = 0;
    
    do{
        random_buff = num_aleatorio(inicio, limite);
    }while(num_exists(random_buff, p, n));

    return random_buff;
}

void zera_vet(int *p, int n){
    for(int i = 0; i < n; i++)
        p[i] = 0;
}