#pragma once

#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

bool valida_cartela(int *cart){
    for(int i = 0, count = 0; i < 24; i++){
        for(int j = 0; j < 24; j++)
            if(cart[i] == cart[j] && i != j)
                count++;
        if(count > 0)
            return false;
    }
    return true;
}

void create_cartela(int *p){
    srand(time(NULL));
    for(int i = 0; i < 25; i++)
        if(i == 12)
            p[i] = 100;
        else{
            int mod = i % 5, m = mod * 15, M = (mod + 1) * 15;
            if(m != 0)
                m++;
            p[i] = num_aleatorio_unico(p, 25, m, M);
        }
}

void print_linha(int tam, char carac, bool skip_linha){
    if(skip_linha)
        printf("\n");
    for(int i = 0; i < tam; i++)
        printf("%c", carac);
}

void print_nome_bingo(){
    print_linha(26, 's',true);
    printf("\n| B  | I  | N  | G  | O  |");
    print_linha(26, 's',true);
}

int num_marcados(int *cart, int *rack){
    int count = 0;

    for(int i = 0; i < 75; i++)
        if(num_exists(rack[i], cart, 25))
            count++;

    return count;
}

void print_cartela(int *cart, int *rack){
    
    print_nome_bingo();
    for(int i = 0; i < 25; i ++){
        if(i % 5 == 0)
            printf("\n|");
        if(i == 12)
            printf(" $$ |");
            // if(num_exists(cart[i], rack, 75))
            //     printf(" $ |");
            // else

        else
            if(num_exists(cart[i], rack, 75))
                printf(" ** |");
            else
                if(cart[i] < 10)
                    printf(" %d  |", cart[i]);
                else
                    printf(" %d |", cart[i]);
    }
    print_linha(26, 's', true);
    printf("\n\n");
}

bool linha_bateu(int *cart, int *rack, int lin){
    if(lin == 2)
        return false;
    else{
        int count = 0;
        for(int i = (lin * 5); i < ((lin * 5) + 5); i++){
            if(cart[i] != 0 && num_exists(cart[i], rack, 75))
                count++;
        }
        if(count == 5)
            return true;
        else
            return false;
    }
    return false;
}

bool coluna_bateu(int *cart, int *rack, int col){
    if(col == 2)
        return false;
    else{
        int count = 0;
        for(int i = col; i < 25; i+= 5){
            if(cart[i] != 0 && num_exists(cart[i], rack, 75))
                count++;
        }
        if(count == 5)
            return true;
        else
            return false;
    }
    return false;
}

bool ganhou(int *cart, int *rack, int modo){
    switch(modo){
        case 1:
            if(num_marcados(cart, rack) >= 24)
                return true;
            else
                return false; 
            break;
        case 2:
            for(int i = 0; i < 5; i++)
                if(linha_bateu(cart, rack, i))
                    return true;
            for(int i = 0; i < 5; i++)
                if(coluna_bateu(cart, rack, i))
                    return true;
            return false;
            break;
    }
    return false;
}

void destroy_cartela(int *cart){
    free(cart);
}
