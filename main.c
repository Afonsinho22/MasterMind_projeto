#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <locale.h>

#define LIMITE_USERNAME 50

void pedir_username(char nome[]){
    printf("Olá!\n");
    printf("Antes de continuar, introduz um username: ");
    fgets(nome, LIMITE_USERNAME, stdin);
    nome[strcspn(nome, "\n")]='\0';
}

int menu(){
    int opcao_user_main;
    printf("Para continuar, escolhe uma opção:\n");
    printf("1- Jogar\n");
    printf("0- Sair\n");
    printf("Opção -> ");
    scanf("%d", &opcao_user_main);

    return opcao_user_main;
}


int main(){
    //UTF-8
    setlocale(LC_ALL, "pt_PT.UTF-8");
    
    //variaveis
    char username[LIMITE_USERNAME];
    int opcao_inicial_user;
    int ciclo_principal=1;

    //Solicitacao do username
    pedir_username(username);

    //página inicial do programa
    printf("Olá %s! Bem-vindo ao MasterMind!\n", username);
    printf("Neste jogo, terás que adivinhar um número de 4 dígitos sorteado aleatóriamente. Os números podem repetidos.\n");
    opcao_inicial_user=menu();

    //motor do jogo
    while(ciclo_principal==1){
        if(opcao_inicial_user==1){
            //resto do código
            printf("A elaborar o programa. Espera por favor");
            break;
        }else if(opcao_inicial_user==0){
            printf("Obrigado por teres entrado no jogo. É uma pena teres desistido logo do jogo.\n");
            printf("Até breve!");
            break;
        }else{
            printf("A opção que introduziste está inválida.");
            opcao_inicial_user=menu();
        }
    }








    //Testes:

    //printf("Numero: %d", opcao_inicial_user);

    return 0;
}