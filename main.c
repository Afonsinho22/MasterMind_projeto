#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <locale.h>
#include <ctype.h>

#define LIMITE_USERNAME 50
#define TAMANHO_NUMEROS 4
#define NUMERO_MINIMO 1
#define NUMERO_MAXIMO 6
#define MAX_TENTATIVAS 10

char username[LIMITE_USERNAME];

typedef struct
{
    int certos_posicao_certa;
    int certos_posicao_errada;
} Posicao_numeros;

typedef struct
{
    int tentativas_restantes;
    int maximo_tentativas;
} Tentativas;

typedef enum
{
    NO_MENU,
    EM_CURSO,
    VITORIA,
    DERROTA,
    DESISTIU
} Estados;

void pedir_username(char nome[])
{
    printf("Olá!\n");
    printf("Antes de continuar, introduz um username: ");

    fgets(nome, LIMITE_USERNAME, stdin);
    nome[strcspn(nome, "\n")] = '\0';
}

int menu()
{
    int opcao;

    printf("\n=== MASTERMIND ===\n");
    printf("1 - Jogar\n");
    printf("0 - Sair\n");
    printf("Opção -> ");

    scanf("%d", &opcao);

    while(getchar() != '\n');

    return opcao;
}

void gerarCombinacao(int combinacao[])
{
    int i, j;
    int numero;
    int repetido;

    for(i = 0; i < TAMANHO_NUMEROS; i++)
    {
        do
        {
            numero = rand() % 6 + 1;
            repetido = 0;

            for(j = 0; j < i; j++)
            {
                if(combinacao[j] == numero)
                {
                    repetido = 1;
                    break;
                }
            }

        } while(repetido);

        combinacao[i] = numero;
    }
}

int pedir_palpite(int palpite[])
{
    char entrada[100];

    printf("\nIntroduz 4 números entre 1 e 6 (ou 0 para desistir): ");
    fgets(entrada, sizeof(entrada), stdin);
    entrada[strcspn(entrada, "\n")] = '\0';

    if(strcmp(entrada, "0") == 0)
    {
        return 0;
    }

    if(strlen(entrada) != 4)
    {
        printf("Erro: tens de introduzir exatamente 4 dígitos.\n");
        return -1;
    }

    int valido = 1;

    for(int i = 0; i < TAMANHO_NUMEROS; i++)
    {
        if(!isdigit(entrada[i]))
        {
            valido = 0;
            break;
        }

        palpite[i] = entrada[i] - '0';

            if(palpite[i] < 1 || palpite[i] > 6)
            {
                valido = 0;
                break;
            }
        }

    if(!valido)
    {
        printf("Erro: só são permitidos números entre 1 e 6.\n");
        return -1; //mais/menos de 4 dígitos, caracteres não numéricos, número fora de 1-6
    }

    return 1;
}

int verificarCombinacao(int combinacao[],int palpite[],Posicao_numeros *resultado)
{
    resultado->certos_posicao_certa = 0;
    resultado->certos_posicao_errada = 0;

    for(int i = 0; i < TAMANHO_NUMEROS; i++)
    {
        if(combinacao[i] == palpite[i])
        {
            resultado->certos_posicao_certa++;
        }
        else
        {
            for(int j = 0; j < TAMANHO_NUMEROS; j++)
            {
                if(i != j && palpite[i] == combinacao[j])
                {
                    resultado->certos_posicao_errada++;
                    break;
                }
            }
        }
    }

    printf("\nResultado:\n");
    printf("Números na posição certa: %d\n",
           resultado->certos_posicao_certa);

    printf("Números certos na posição errada: %d\n",
           resultado->certos_posicao_errada);

    if(resultado->certos_posicao_certa == TAMANHO_NUMEROS)
    {
        return 1;
    }

    return 0;
}

void validar_tentativas(Tentativas *tentativas)
{
    if(tentativas->tentativas_restantes > 0)
    {
        tentativas->tentativas_restantes--;
    }
}

int jogar_novamente()
{
    int opcao;

    do
    {
        printf("\nQueres jogar novamente?\n");
        printf("1 - Sim\n");
        printf("0 - Não\n");
        printf("Opção -> ");

        scanf("%d", &opcao);

        if(opcao != 0 && opcao != 1)
        {
            printf("Opção inválida! Escolhe 0 ou 1.\n");
        }
    } while(opcao != 0 && opcao != 1);

    return opcao;
}

int main()
{
    setlocale(LC_ALL, "pt_PT.UTF-8");
    srand(time(NULL));

    pedir_username(username);

    printf("\nOlá %s!\n", username);
    printf("Bem-vindo ao MasterMind!\n");
    printf("Tens de adivinhar uma combinação de 4 números.\n");
    printf("Cada número está entre 1 e 6.\n");
    printf("Os números da combinação não se repetem.\n");

    int opcao = menu();

    if(opcao == 0)
    {
        printf("Até breve!\n");
        return 0;
    }

    if(opcao != 1)
    {
        printf("Opção inválida.\n");
        return 0;
    }

    while(1)
    {
        int combinacao[TAMANHO_NUMEROS];
        int palpite[TAMANHO_NUMEROS];
        Posicao_numeros resultado;
        Tentativas tentativas;
        Estados estado_partida = EM_CURSO;

        gerarCombinacao(combinacao);
        tentativas.maximo_tentativas = MAX_TENTATIVAS;
        tentativas.tentativas_restantes = MAX_TENTATIVAS;

        while(estado_partida == EM_CURSO && tentativas.tentativas_restantes > 0)
        {
            printf("\n=====================================\n");
            printf("Tentativas restantes: %d\n", tentativas.tentativas_restantes);
            printf("=====================================\n");

            int estado = pedir_palpite(palpite);

            if(estado == 0)
            {
                estado_partida = DESISTIU;
                printf("\nDesististe do jogo.\n");
                printf("A combinação era: ");

                for(int i = 0; i < TAMANHO_NUMEROS; i++)
                {
                    printf("%d", combinacao[i]);
                }

                printf("\n");
                break;
            }

            if(estado == -1)
            {
                validar_tentativas(&tentativas);

                if(tentativas.tentativas_restantes == 0)
                {
                    estado_partida = DERROTA;
                    printf("\nFicaste sem tentativas!\n");
                    printf("A combinação correta era: ");

                    for(int i = 0; i < TAMANHO_NUMEROS; i++)
                    {
                        printf("%d", combinacao[i]);
                    }

                    printf("\n");
                    break;
                }

                continue;
            }

            if(verificarCombinacao(combinacao, palpite, &resultado))
            {
                estado_partida = VITORIA;
                printf("\nParabéns %s!\n", username);
                printf("Acertaste na combinação!\n");
                break;
            }

            validar_tentativas(&tentativas);

            if(tentativas.tentativas_restantes == 0)
            {
                estado_partida = DERROTA;
                printf("\nFicaste sem tentativas!\n");
                printf("A combinação correta era: ");

                for(int i = 0; i < TAMANHO_NUMEROS; i++)
                {
                    printf("%d", combinacao[i]);
                }

                printf("\n");
                break;
            }
        }

        if(estado_partida == DESISTIU)
        {
            printf("\nObrigado por jogar o MasterMind, até breve!\n");
            break;
        }

        if(jogar_novamente() == 0)
        {
            printf("\nObrigado por jogar o MasterMind, até breve!\n");
            break;
        }
    }

    return 0;
}