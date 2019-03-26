#ifndef CARTAS_H
#define CARTAS_H
#include <stdio.h>
#include <stdlib.h>

// "cartas.h" contém a estrutura que representa uma carta e funções para sua manipulação individual



// --- Pré-definições

// Definição de naipes para auxílio da manipulação
#define PAUS 1
#define OUROS 2
#define COPAS 3
#define ESPADAS 4

// Definição de cartas não numéricas para auxílio da manipulação
#define A 1
#define J 11
#define Q 12
#define K 13



// --- Estrutura para definir uma carta
typedef struct carta{
    int valor;
    int naipe;
} Carta;

// --- Estrutura para definir uma carta inserida na pilha
// Semelhante a um nó para estrutura de pilha
typedef struct carta_na_pilha{
    Carta carta;
    struct carta_na_pilha *prox;
} Carta_na_Pilha;




// --- Funções

// Cria uma carta por atribuição simples
// Pré-condição: valor v e naipe n da carta
// Pós-condição: estrutura de carta criada
Carta criaCarta(int v, int n);

// Testa se uma carta é válida
// Pré-condição: estrutura de carta
// Pós-condição: retorna 1 se a estrutura de carta é válida
//                       0 se a estrutura não é válida
// OBS: Entende-se por válida uma carta que contenha valor e naipe dentro do intervalo definido
//                                                   valor e naipe não estão repetidos no baralho
//int CartaValida(Carta carta);

// Imprime uma carta
// Pré-condição: uma estrutura de carta válida, com valor e naipe
// Pós-condição: carta impressa na tela, no formato "[ VALOR de NAIPE ]"
void imprimirCarta(Carta carta);



#endif // CARTAS_H
