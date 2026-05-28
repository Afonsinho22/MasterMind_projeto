#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define LIMITE_USERNAME 50

int main(){
    char username[LIMITE_USERNAME];
    printf("Olá!\n");
    printf("Antes de continuar, introduz um username: ");
    fgets(username, sizeof username, stdin);
    printf("Nome do user: %s", username);

    return 0;
}