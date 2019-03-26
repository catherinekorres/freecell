#ifndef PILHAS_H
#define PILHAS_H
#include <stdlib.h>
#include <windows.h>
#include "cartas.h"


// "pilhas.h" contém as estruturas e funções necessárias para representar e manipular individualmente as pilhas de cartas que serão utilizadas no jogo



// --- Estrutura que define uma pilha de cartas dispostas na mesa
typedef struct stack{
    Carta_na_Pilha *topo;
} Pilha_Cartas;

// --- Estrutura que define uma pilha base de cartas para um só naipe
typedef struct final_stack{
    Carta_na_Pilha *topo;
    int naipe;
} Pilha_Cartas_Base;


// Permite que o cursor vá para um local específico da tela
// Pré-condição: coordenadas do eixo x e y do local desejado
// Pós-condição: cursor se posiciona nas coordenadas (x,y)
//              OBS: utilizada para auxiliar na impressao das pilhas
void gotoxy(int x, int y);


// --- Funções para Pilhas de Carta Comuns

// Cria uma pilha de cartas vazia
// Pré-condição: nenhuma
// Pós-condição: estrutura de pilha criada
Pilha_Cartas* criaPilha();

// Verifica se a pilha de cartas está vazia
// Pré-condição: Estrutura de pilha de cartas
// Pós-condição: retorna 1 se a pilha é vazia
//                       0 se a pilha contém algo
int PilhaVazia(Pilha_Cartas* p);

// Empilha uma carta no topo da pilha
// Pré-condição: Estrutura de pilha de cartas
// Pós-condição: Carta no topo da pilha
void push(Pilha_Cartas* p, Carta c);

// Desempilha uma carta da pilha, ou seja, retira uma carta do topo da pilha
// Pré-condição: Estrutura de pilha de cartas
// Pós-condição: Carta retirada da pilha
Carta* pop(Pilha_Cartas* p);

// Deleta uma pilha de cartas
// Pré-condição: Estrutura de pilha
// Pós-condição: Parte da memória que continha a estrutura da pilha é liberada
void deletaPilha(Pilha_Cartas* p);

// Inverte uma pilha de cartas
// Pré-condição: Estrutura de pilha de cartas
// Pós-condição: Estrutura de pilha de cartas com os mesmos itens, em ordem inversa
Pilha_Cartas* invertePilha(Pilha_Cartas* p);

// Imprime uma pilha de cartas
// Pré-condição: Estrutura de pilha de cartas
// Pós-condição: Pilha de cartas impressa na tela, com cada carta no formato "[ VALOR de NAIPE ]", uma abaixo da outra
//               OBS: Para realizar a impressao da pilha, ela sera antes invertida
//                    A inversao se viu necessaria para que a impressao do jogo fique mais intuitiva
//                    Dessa forma, a ultima carta a ser impressa sera a carta que pode ser movimentada
void imprimirPilha(Pilha_Cartas* p, int x, int y);



// --- Funções para Pilhas Base de Carta (Pilhas que representam um naipe)

// Cria uma pilha base de cartas vazia
// Pré-condição: nenhuma
// Pós-condição: estrutura de pilha criada
Pilha_Cartas_Base* criaPilhaBase(int naipe);

// Verifica se uma pilha base de cartas de um naipe está vazia
// Pré-condição: Estrutura de pilha base de cartas
// Pós-condição: retorna 1 se a pilha é vazia
//                       0 se a pilha contém algo
int PilhaBaseVazia(Pilha_Cartas_Base* p);

// Empilha uma carta no topo da pilha base
// Pré-condição: Estrutura de pilha base de cartas
// Pós-condição: Carta no topo da pilha
void push_base(Pilha_Cartas_Base* p, Carta c);

// Desempilha uma carta da pilha base, ou seja, retira uma carta do topo da pilha base
// Pré-condição: Estrutura de pilha base de cartas
// Pós-condição: Carta retirada da pilha base
//               OBS: Operação feita apenas ao final do jogo para desalocar a memoria
Carta* pop_base(Pilha_Cartas_Base* p);

// Deleta uma pilha de cartas
// Pré-condição: Estrutura de pilha base de cartas
// Pós-condição: Parte da memória que continha a estrutura da pilha é liberada
void deletaPilhaBase(Pilha_Cartas_Base* p);

// Imprime uma pilha base de cartas de um naipe
// Pré-condição: Estrutura de pilha base de cartas
// Pós-condição: Pilha de cartas base impressa na tela, com o cabeçalho "[ NAIPE ]" cada carta no formato "[ VALOR de NAIPE ]", uma abaixo da outra
void imprimirPilhaBase(Pilha_Cartas_Base* p, int x, int y);


#endif // PILHAS_H
