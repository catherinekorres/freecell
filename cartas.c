#include "cartas.h"

// "cartas.c" contém as funções necessárias para manipulação individual de uma carta



// Cria uma estrutura de carta
// Pré-condição: valor v e naipe n da carta
// Pós-condição: estrutura de carta criada
Carta criaCarta(int v, int n){
    Carta c;
    c.valor = v;
    c.naipe = n;
    return c;
}

// Testa se uma carta é válida
// Pré-condição: estrutura de carta
// Pós-condição: retorna 1 se a estrutura de carta é válida
//                       0 se a estrutura não é válida
// OBS: Entende-se por válida uma carta que contenha valor e naipe dentro do intervalo definido
//                                                   valor e naipe não estão repetidos no baralho
/*int CartaValida(Carta carta){

}*/

// Imprime uma carta
// Pré-condição: uma estrutura de carta válida, com valor e naipe
// Pós-condição: carta impressa na tela, no formato "[ VALOR de NAIPE ]"
void imprimirCarta(Carta carta){
    switch(carta.valor) {
        case 1: printf("[  A"); break;
        case 10: printf("[ 10"); break;
        case 11: printf("[  J"); break;
        case 12: printf("[  Q"); break;
        case 13: printf("[  K"); break;
        default: printf("[  %d", carta.valor); break;
    }
    switch(carta.naipe) {
        case 1: printf(" de Paus    ]\n"); break;
        case 2: printf(" de Ouros   ]\n"); break;
        case 3: printf(" de Copas   ]\n"); break;
        case 4: printf(" de Espadas ]\n"); break;
    }
}
