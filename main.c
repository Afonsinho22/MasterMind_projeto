#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define LIMITE_USERNAME 50

void pedir_username(char nome[]){
    printf("Olá!\n");
    printf("Antes de continuar, introduz um username: ");
    nome[strcspn(nome, "\n")]='\0';
    fgets(nome, LIMITE_USERNAME, stdin);

    printf("Nome do user: %s", nome);
}

int main(){
    char username[LIMITE_USERNAME];
    pedir_username(username);

    return 0;
}