#pragma once

#include <stdbool.h>
#include <stdlib.h>

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

    for(int i = 0; i < 25; i ++)
        p[i] = 0;

    srand(time(NULL));

    for(int i = 0; i < 25; i++)
        if(i == 12)
            p[i] = 100;
        else{
            
        }
            
        // else if(i%5==0){
        //         p[i]=16;
        //     while(p[i]>15){
        //         p[i] = num_aleatorio(p, 75);
        //     }
        // }
        // else if(i==1 || i==6 || i==11 || i==16 || i==21){
        //         p[i]=31;
        //     while(p[i]>30 || p[i]<16 ){
        //         p[i] = num_aleatorio(p, 75);
        //     }
        // }
        // else if(i==2 || i==7 || i==17 || i==22){
        //         p[i]=46;
        //     while(p[i]>45 || p[i]<31 ){
        //         p[i] = num_aleatorio(p, 75);
        //     }
        // }
        // else if(i==3 || i==8 || i==13 || i==18 || i==23){
        //         p[i]=61;
        //     while(p[i]>60 || p[i]<46 ){
        //         p[i] = num_aleatorio(p, 75);
        //     }
        // }
        // else if(i==4 || i==9 || i==14 || i==19 || i==24){
        //         p[i]=76;
        //     while(p[i]>75 || p[i]<61 ){
        //         p[i] = num_aleatorio(p, 75);
        //     }
        // }
}

void print_linha(int tam, bool skip_linha){
    if(skip_linha)
        printf("\n");
    for(int i = 0; i < tam; i++)
        printf("=");
}

int num_marcados(int *cart, int *rack){
    int count = 0;

    for(int i = 0; i < 75; i++)
        if(num_exists(rack[i], cart, 25))
            count++;

    return count;
}

void print_cartela(int *cart, int *rack){

    // printf("\nEllyo");
    // print_linha(26, true);
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
    // print_linha(26, true);
    printf("\n\n");
}

void destroy_cartela(int *cart){
    free(cart);
}
