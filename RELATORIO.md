# Jogo MasterMind - Mini projeto de C

## Introdução

Este trabalho teve o objetivo de desenvolver um programa no terminal que consiste em sortear um número aleatório de 4 dígitos entre 1 e 6 e o utilizador tentar adivinhar esse número. O utilizador tem 10 tentativas para poder adivinhar o número. Caso as tentativas se esgotarem, o jogo (ronda) termina, revelando qual era o número sorteado.



## Funções existentes no programa

- ``pedir_username``
- ``menu``
- ``gerarCombinacao``
- ``pedir_palpite``
- ``verificarCombinacao``
- ``validar_tentativas``
- ``jogar_novamente``
- ``main``



## Funcionamento das funções presentes no programa:

### ``pedir_username``

- Recebe uma string chamada ``nome``;
- Não altera nada;
- Não devolve nada;

Esta função pede ao utilizador um username que será utilizado durante o programa inteiro.

### ``menu``

- Não recebe nada;
- Não altera nada;
- Devolve uma opção escolhida pelo utilizador no valor de inteiro.

Esta função mostra o menu principal do jogo, onde existem 2 opções: jogar e sair. Também remove o ``/n`` para que não assume enter quando arranca o jogo.

### gerar_combinacao

- Recebe um array onde vai ser colocado o número sorteado;
- Não altera nada;
- Não devolve nada;

Esta função irá sortear o número de 4 dígitos entre 1 e 6, evitando repetições. Faz isso através de um ciclo ``do while``.

### pedir_palpite

- Recebe um array que será o palpite que o utilizador colocar;
- Não altera nada;
- Devolve valores relacionados com o cumprimento das regras do jogo ou não. ``0`` significa que o utilizador desistiu, ``1`` significa que é válido e ``-1`` significa que é inválido.

Esta função vai pedir ao utilizador 4 números de acordo com as regras já mencionadas para poder adivinhar o número sorteado. Permite também o utilizador desistir a meio do jogo, introduzindo o valor ``0``.

### verificar_combinacao

- Recebe o número sorteado e o palpite do utilizado em ``array`` e variável resultado vinda do ``struct`` ``Posicao_numeros``;
- Altera os valores relacionados com o resultado do jogo, indicando quantos é que estão certos na posição certa e quantos estão certos na posição errada;
- Retorna ``0`` ou ``1`` consoante o resultado obtido com a comparação.

Esta função vai comparar se o número que o utilizdor inseriu corresponde ao número sorteado pelo computador, dizendo se existe algum número certo e se está na posição certa ou não.

### validar_tentativas

- Recebe o número de tentativas que o utilizador tem no momento, vindo numa struct;
- Não altera nada;
- Não retorna nada.

Esta função vai retirar uma tentativa se o utilizador errar na combinação do númemero e verifica se ainda tem tentativas.

### jogar_novamente()

- Não recebe nada;
- Não altera nada;
- Retorna uma opção escolhida pelo utilizador.

Esta funcao pergunta no final de cada ronda se pretente voltar a jogar ou terminar o programa naquele momento. Também remove o ``/n`` para que não assume enter quando arranca o jogo.

### main

- Não recebe nada;
- Não altera nada;
- Retorna ``0``;

É a função principal do jogo. É ela que executa todas as funções do jogo, inicializa os contadores das tentativas e a semente do sorteio do mesmo. Dá também as informações iniciais do jogo, opções inválidas e despedidas do jogo. Também mostra as tentativas que o utilizador tem. Tudo isto funciona num ciclo While que alterna entre ``0`` e ``1``.