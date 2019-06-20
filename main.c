#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<time.h>

#include "numeros.h"
#include "cartela.h"
#include "rack.h"

int menu(){
    int esc = 0;
    puts("Selecione uma modalidade\n");
    printf("1 - Full house\n2 - Linha ou Coluna\n\nEscolha: ");
    scanf("%d", &esc);
    return esc;
}

void jogar(int *cart, int *rack, int modo){
    printf("\n");
    puts("Essa é sua cartela: ");

    print_cartela(cart, rack);

    // puts("Fique de olho para ver se não tem ninguem roubando ;)");

    // print_rack(rack);

    // printf("%d\n", num_marcados(cart, rack));
    int acertos = num_marcados(cart, rack);
    // int last_acerto = 0;
    
    int buff = 0;
    
    printf("\nEscolha 1 para pedir bola e 0 para sair: ");
    
    scanf("%d", &buff);
    
    if(buff != 1){
        printf("\nObrigado e volte sempre.\n"); 
        return;
    }
    
    do{
        system("clear");
        printf("\nNumero sorteado: %d\n", sortear(rack));
        
        print_roleta(rack);
        print_rack(rack);

        int buff = num_marcados(cart, rack);

        if(buff > acertos){
            printf("Yeah, +1!\n");
            acertos = buff;
            print_cartela(cart, rack);
            if(ganhou(cart, rack, modo)){
                printf("Bingo!!!");
                break;
            }
        }
        printf("\nEscolha 1 para pedir bola e 0 para sair: ");
    }while(!ganhou(cart, rack, modo) && scanf("%d", &buff) && buff == 1);

    printf("\n");
    
    if(buff != 1){
        printf("\nObrigado e volte sempre.\n"); 
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

    jogar(cart, rack, menu());

    destroy_rack(rack);

    destroy_cartela(cart);

}
