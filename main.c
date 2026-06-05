#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <locale.h>

#define LIMITE_USERNAME 50
#define TAMANHO_NUMEROS 4
#define NUMERO_MINIMO 1
#define NUMERO_MAXIMO 6

typedef enum{
    NO_MENU,
    EM_CURSO,
    VITORIA,
    DERROTA,
    DESISTIU
}Estados;

Estados estado_jogo=NO_MENU;
char username[LIMITE_USERNAME];

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
/*/
neste momento tens 33 tentativas
(introduz 0 para sair)
> 0
Erraste ahah!
neste momento tens 32 tentativas
> 6789
/*/

void gerarCombinacao(int combinacao[]){
    int i, j;
    int numero;
    int repetido;

    for(i = 0; i < TAMANHO_NUMEROS; i++){

        do{
            numero = rand() % 6 + 1;

            repetido = 0;

            for(j = 0; j < i; j++){
                if(combinacao[j] == numero){
                    repetido = 1;
                    break;
                }
            }

        }while(repetido);

        combinacao[i] = numero;
    }
}


int pedir_palpite(int tentativas_user, int ciclo_jogo){
    int opcao_tentativas;
    int palpite_utilizador[TAMANHO_NUMEROS];
    int numero_utilizador;
    printf("Neste momento, tens %d tentativas.\n", tentativas_user);
    printf("Escreve %d números, de %d até %d ou 0 para para desistires: ", TAMANHO_NUMEROS, NUMERO_MINIMO, NUMERO_MAXIMO);
    scanf("%d", &numero_utilizador);
    if(numero_utilizador==0){
        printf("É uma pena teres abandonado o jogo a meio...\n");
        printf("Para a próxima corre melhor.");
        return 0;
    }else{
        for(int i=TAMANHO_NUMEROS-1; i>=0; i--){
            palpite_utilizador[i]=numero_utilizador%10;
            numero_utilizador=numero_utilizador/10;
        }
    }
    
    
    //    for(int i=0; i<TAMANHO_NUMEROS; i++){
        //        printf("%d",palpite_utilizador[i]);
        //    }
        return palpite_utilizador[TAMANHO_NUMEROS];
        
    }     
int verificarCombinacao(int combinacao[], int palpite[]){
    
        for(int i = 0; i < TAMANHO_NUMEROS; i++){
            if(combinacao[i] == palpite[i]){
                printf("\nParabéns %s!\n", username);
                printf("Acertaste na combinação!\n");
                return 0;
            }else{
                printf("Não acertaste no número!");
                //falta a implementação de quantos números estão na posição certa ou errada.
            }
        }
    
        return 1;
    }
    


/*/
for(int i=0; i<TAMANHO_NUMEROS; i++){
            if(palpite_utilizador>0){
                if(palpite_utilizador>=NUMERO_MINIMO && palpite_utilizador<=NUMERO_MAXIMO){
                    return 
                }
            }
}
/*/

int main(){
    //UTF-8
    setlocale(LC_ALL, "pt_PT.UTF-8");
        
    //variaveis
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
            int combinacao[TAMANHO_NUMEROS];
            int dados_palpite=pedir_palpite(10, ciclo_principal);
            if(dados_palpite==0){
                break;
            }

            //printf("A elaborar o programa. Espera por favor");
            //break;
        } else if(opcao_inicial_user==0){
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