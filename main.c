#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<time.h>

#include "numeros.h"
#include "cartela.h"
#include "rack.h"

// typedef struct {
//     char nome[50];
//     int *cart;
//     int *rack;
// } PLAYER;

// void create_player(PLAYER *p){

//     // printf("Digite o nome: ");
//     // scanf("%s", p->nome);

//     p->cart = (int *)  malloc(sizeof(int) * 25);
//     create_cartela(p->cart);

// }

// void destroy_player(PLAYER *p){
//     destroy_cartela(p->cart);
//     free(p);
// }

void jogar(int *cart, int *rack){
    printf("\n");
    puts("Essa é sua cartela: ");

    print_cartela(cart, rack);

    puts("Fique de olho para ver se não tem ninguem roubando ;)");

    // print_rack(rack);

    // printf("%d\n", num_marcados(cart, rack));

    int acertos = num_marcados(cart, rack);
    // int last_acerto = 0;


    do{
        int continuar_sair;
        printf("\nEscolha 1 para pedir bola e 0 para sair:");
        scanf("%d", &continuar_sair);
        if(continuar_sair==0){
            acertos=25;
        }else{
            printf("\n+%d\n", sortear(rack));

            print_rack(rack);

            int buff = num_marcados(cart, rack);

            if(buff > acertos){
                printf("Yeah, +1!\n");
                acertos = buff;
                print_cartela(cart, rack);
                if(acertos != 24)
                    printf("Faltam apenas: %d", 24 - acertos);
                else
                    puts("Acho que alguem ganhou!"), puts("Congratulations!!!");
                    // printf("\n+%d\n", last_acerto);
            }
        }
        // print_rack(rack);
    }while(acertos < 24);
    printf("\n");
    // print_cartela(cart, rack);

    // print_rack(rack);
}

int main(){
    system("clear");
    // PLAYER * player = malloc(sizeof(PLAYER));

    // create_player(player);

    int * cart = (int *) malloc(sizeof(int) * 25);
    int * rack = (int *) malloc(sizeof(int) * 75);

    zera_vet(rack, 75);

    create_cartela(cart);

    // rack[ cart[0] - 1 ] = cart[0];

    // jogar(cart, rack);

    printf("%d\n", num_aleatorio(5, 10));

    destroy_rack(rack);

    destroy_cartela(cart);

    // destroy_player(player);

}
