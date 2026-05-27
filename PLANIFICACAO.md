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
| 12 | Caso o utilizador ficar sem tentativas ou se acertar o número sorteado, o programa deve terminar a ronda, dizer qual era o número sorteado (no caso de não ter acertado) e perguntar se o utilizador pretende jogar novamente ou sair do jogo.|
| 13 | Caso o utilizador escolher a opção ``jogar novamente``, o programa deve recomeçar a partir do requesito 4.|
| 14 | Caso o utilizador escolher a opção ``Sair``, o programa deve finalizar-se.|



## 3. Tipos de dados: Entradas e saídas

### Dados de entrada:

| Entrada | Tipo de Dados | Exemplo válido | Exemplo inválido |
|---------|---------------|-----------------|--------|
| Opção do menu | ``int`` | ``1`` | ``3`` |
| Username | ``char[]`` | ``"João"`` | -
| Palpite do utilizador | ``int`` | ``4`` | ``3`` |
| Jogar novamente | ``int`` | ``2``| ``3`` |


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


## 5. Funções