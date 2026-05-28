#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main() {
    int numero_secreto, palpite;
    int tentativas=0;
    const int MAX_TENTATIVAS=5;
    
    printf("Bem-vindo ao jogo do início do tempo! ✨🪄🧙⌛🌍\n");
    
    srand(time(NULL));
    numero_secreto = rand() %100;
    
    while(tentativas < MAX_TENTATIVAS){
        printf("Tentativa %d: ", tentativas);
        scanf("%d", &palpite);
        if(palpite < numero_secreto){
            printf("\nNúmero demasiado baixo... artolas! ");
        }else if(palpite > numero_secreto){
            printf("\nNúmero demasiado alto..."); //falta acabar
        }
    }
    return 0;
}