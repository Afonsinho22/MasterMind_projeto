# Planificação  Mini-Projeto - MasterMind

## 1. Contexto do programa

O programa será um MasterMind onde terá de receber 4 números por parte do utilizador. O contexto do progrma está neste ficheiro:
[PERGUNTAS_INICIAIS.md](https://github.com/Afonsinho22/MasterMind_projeto/blob/master/PERGUNTAS_INICIAIS.md)

## 2. Requesitos funcionais

| Nº  | Requesito funcional|
|-----|--------------------|
|  1  | O programa deve começar por mostrar um menu com 2 opções: ``Jogar`` e ``Sair``.|
|  2  | O programa deve pedir um ``username`` para efeitos estéticos durante o jogo (será pedido caso escolha a opção ``Jogar``).|
|  3  | O programa deve guardar o ``username`` numa variável.|
|  4  | O programa deve gerar uma combinação aleatória de 4 números entre 1 e 6, sem repetição de números.|
|  5  | O programa deve criar uma variável onde estará o número máximo de tentativas.|
|  6  | O programa deve mostrar as tentativas que o utilizador tem sempre que use uma tentativa.|
|  7  | O programa deve aceitar 4 números dados pelo utilizador.|
|  8  | O programa deve guardar os números dados pelo utilizador numa variável.|
|  9  | Caso o palpite esteja errado, o programa deve diminuir uma tentativa. |
| 10 | Caso o palpite esteja errado, o programa deve subtrair uma tentativa. Ex: se tem ``10`` tentativas, passa a ter ``9`` tentativas.|
| 11 | O programa deve aceitar o palpite se este corresponder ao número sorteado.|
| 12 | No final de cada palpite, o programa deve perguntar ao utilizador se pretende continuar a inserir um palpite ou desistir do jogo. Além disso, deve mostrar quantas tentativas faltam.
| 13 | Caso o utilizador ficar sem tentativas ou se acertar o número sorteado, o programa deve terminar a ronda, dizer qual era o número sorteado (no caso de não ter acertado) e perguntar se o utilizador pretende jogar novamente ou sair do jogo.|
| 14 | Caso o utilizador escolher a opção ``jogar novamente``, o programa deve recomeçar a partir do requesito 4.|
| 15 | Caso o utilizador escolher a opção ``Sair``, o programa deve finalizar-se.|



## 3. Tipos de dados: Entradas e saídas

### Dados de entrada:

| Entrada | Tipo de Dados | Exemplo válido | Exemplo inválido |
|---------|---------------|-----------------|--------|
| Opção do menu | ``int`` | ``1`` | ``3`` |
| Username | ``char[]`` | ``"João"`` | -
| Palpite do utilizador | ``int`` | ``4`` | ``3`` |
| Palpitar novamente | ``int`` | ``1`` | ``9`` |
| Jogar novamente | ``int`` | ``0``| ``3`` |


### Dados de saída:

- **Utilizador**:
    ```text
    Olá!
    Antes de continuar, introduz um username:
    ```

- **Menu principal**:
    ```text
    Olá Afonso! Bem vindo ao MasterMind!

    Neste jogo, terás que adivinhar um número de 4 dígitos sorteado aleatóriamente. Os números têm dígitos diferentes. 

    Para continuar, escolhe uma opção:

    1- Jogar
    0- Sair do jogo
    ```

- **Tentativas iniciais**:
    ```text
    Número de tentativas: 10
    ```

- **Palpite errado**:
    ```text
    Palpite Errado!
    Números descobertos na posição certa: 0
    Números descobertos na posição errada: 2

    Tentativas restantes: 4
    ```

- **Palpitar novamente**
    ```text
    O que pretende fazer?
    1- Voltar a jogar
    2- Desistir do jogo (esperemos que não o faças)
    ```

- **Número descoberto**:
    ```text
    Parabéns! Descobriste o número!!
    ```

- **Fim de tentativas**:
    ```text
    Infelizmente, não descobriste o número! O número era 1234.
    ```

- **Voltar a jogar/sair do jogo**:
    ```text
    Escolha uma opção:
    
    1- Voltar a jogar
    0- Sair
    ```



## 4. Estruturas de dados:

Neste projeto, vamos utilizar algumas estruturas de dados, nomeadamente ``arrys estáticos``, ``strucs`` (utilizando o ``typedef``), ``enums`` (utilizando o ``typedef``), ``arry de strucs`` e ``constantes``.

Exemplos:

### ``Arry estático``:

```C
#incude <studio.h>

int main(){
    int tentativa_utilizador[4]={1,2,3,4};

    return 0;
}
```

### ``Struc``:
```C
typedef struct{
    int maximo_tentativas;
    int tentativas_ja_dadas; //pode ser usada para verificar se o utilizador já atingiu as tentativas.
    int estado; //poderá ser substituida com os dados do enum.
}Verificacao_tentativas;
```

### ``Enums``:
```C
typedef enum {
    EM_CURSO,
    VITORIA,
    DERROTA,
    DESISTENCIA
} Estado_jogo;
```


### ``Arry de struct``:
```C
typedef struct{
    int numeros[4];
    int certos_posicao_errada;
    int certos_posicao_certa;
} Tentativas_user;
```

### ``Constante``:

```C
#define TAMANHO_NUMERO 4
#define LIMITE_TENTATIVAS 10

int main(){
    int limite=LIMITE_TENTATIVAS;

    return 0;
}
```

## 5. Funções

Funções que serão usadas:  
| Nome da possível função | Objetivo | Recebe dados? | Altera dados? | Devolve dados?
|---|---|---|---|---|
| `mostrarMenu()` | Mostrar o menu principal | Não | Não | Sim (com o int)
| `pedirUsername()` | Pedir o username | Sim (com o char) | Sim (fica guardado no array) | Não (fica como void)
| `gerarCombinacao()` | Gerar a combinação aleatória | Sim (com o int) | Sim (vai preencher o array) | Não (fica como void)
| `pedirPalpite()` | Ler os números do utilizador | Sim (com o int) | Sim (vai preencher o array) | Não (fica como void)
| `verificarPalpite()` | Comparar o palpite com a combinação | Sim (usando palpite[], combinacao[]) | Sim (resultado da verificação) | Sim (com o int ou struct)
| `mostrarTentativas()` | Mostrar tentativas restantes | Sim (com o int) | Não | Não (fica como void)
| `jogarNovamente()` | Perguntar se deseja continuar | Não | Não | Sim (com o int)
| `main()` | Controlar o programa principal | Não | Não | Sim (com o int)
