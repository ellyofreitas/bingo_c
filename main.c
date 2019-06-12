#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<time.h>

#include "numeros.h"
#include "cartela.h"
#include "rack.h"

void jogar(int *cart, int *rack){
    printf("\n");
    puts("Essa é sua cartela: ");

    print_cartela(cart, rack);

    puts("Fique de olho para ver se não tem ninguem roubando ;)");

    // print_rack(rack);

    // printf("%d\n", num_marcados(cart, rack));
    int acertos = num_marcados(cart, rack);
    // int last_acerto = 0;
    
    int buff = 0;
    
    printf("\nEscolha 1 para pedir bola e 0 para sair: ");
    
    scanf("%d", &buff);
    
    if(buff != 1){
        printf("\nJá desistiu?\n"); 
        return;
    }
    
    do{
        system("clear");
        printf("\n+%d\n", sortear(rack));

        print_rack(rack);

        int buff = num_marcados(cart, rack);

        if(buff > acertos){
            printf("Yeah, +1!\n");
            acertos = buff;
            print_cartela(cart, rack);
            if(acertos != 24)
                printf("Faltam apenas: %d\n", 24 - acertos);
            else{
                puts("Congratulations!!!");
                break;
            }
        }
        printf("\nEscolha 1 para pedir bola e 0 para sair: ");
    }while(acertos < 24 && scanf("%d", &buff) && buff == 1);
    
    printf("\n");
    
    if(buff != 1){
        printf("Já desistiu?\n");
        return;
    }
}

int main(){
    system("clear");

    int * cart = (int *) malloc(sizeof(int) * 25);
    int * rack = (int *) malloc(sizeof(int) * 75);

    zera_vet(cart, 25);

    zera_vet(rack, 75);

    create_cartela(cart);

    jogar(cart, rack);

    destroy_rack(rack);

    destroy_cartela(cart);

    // destroy_player(player);

}
