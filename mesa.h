#ifndef MESA_H
#define MESA_H
#include <time.h>
#include <stdlib.h>
#include "pilhas.h"

// "mesa.h" contém estruturas e funções para visualizar e alterar o estado atual da mesa


// Permite que o programa apareça em tela cheia
// Pré-condição: nenhuma
// Pós-condição: programa ocupa toda a tela
void fullscreen();

// Troca o valor das duas cartas
// Pré-condição: 2 Cartas
// Pós-condição: Carta a recebe o valor da Carta b e vice-e-versa
void trocarCartas (Carta* a, Carta* b);

// Embaralha um vetor de cartas
// Pré-condição: Vetor de cartas e o tamanho n do vetor
// Pós-condição: Posição das cartas no vetor é sorteada de forma diferente toda vez que o programa é aberto
void embaralha(Carta* vetor, int n);

// Dá as cartas no início do jogo
// Pré-condição: nenhuma
// Pós-condição: Distribui as cartas de forma aleatoria nas 8 colunas da mesa
void darCartas(Pilha_Cartas* pilha1, Pilha_Cartas* pilha2, Pilha_Cartas* pilha3, Pilha_Cartas* pilha4, Pilha_Cartas* pilha5, Pilha_Cartas* pilha6, Pilha_Cartas* pilha7, Pilha_Cartas* pilha8);

// Imprime as bordas que delimitam as áreas da mesa
// Pré-condição: nenhuma
// Pós-condição: bordas impressas na tela
void imprimirBordas();

// Imprime as 8 Pilhas que representam as pilhas de cartas móveis de jogo
// Pré-condição: nenhuma
// Pós-condição: Pilhas impressas na tela
void imprimirPilhasMoveis(Pilha_Cartas* pilha1, Pilha_Cartas* pilha2, Pilha_Cartas* pilha3, Pilha_Cartas* pilha4, Pilha_Cartas* pilha5, Pilha_Cartas* pilha6, Pilha_Cartas* pilha7, Pilha_Cartas* pilha8);

// Imprime as 4 Pilhas que representam cada naipe
// Pré-condição: nenhuma
// Pós-condição: Pilhas impressas na tela
void imprimirPilhasBase(Pilha_Cartas_Base* pilha_base_paus, Pilha_Cartas_Base* pilha_base_ouros, Pilha_Cartas_Base* pilha_base_copas, Pilha_Cartas_Base* pilha_base_espadas);

// Imprime as 4 Células de apoio para movimentação das cartas na mesa
// Pré-condição: nenhuma
// Pós-condição: Células impressas na tela
void imprimirCelulasDeApoio(Carta celula1, Carta celula2, Carta celula3, Carta celula4);

// Verifica se uma carta é antecessora a outra na ordem crescente de valores: A, 2, 3, 4, 5, 6, 7, 8, 9, 10, J, Q, K
// Pré-condição: Duas cartas
// Pós-condição: retorna 1 se a primeira carta é antecessora a segunda
//                       0 se a afirmação for falsa
int CartaAntecessora(Carta carta1, Carta carta2);

// Move uma carta na mesa, de uma pilha para outra
// Pré-condição: Estrutura da Pilha fonte e Estrutura da Pilha destino
// Pós-condição: A carta é removida do topo da pilha fonte e inserida no topo da pilha destino
void moverCarta(Pilha_Cartas* fonte, Pilha_Cartas* destino);

// Move uma carta do topo de uma pilha para o topo da Pilha Base
// Pré-condição: Estrutura da Pilha fonte e Estrutura da Pilha Base.
//               As cartas no topo da Pilha fonte e Pilha Base devem ter mesmo naipe.
//               O valor da carta no topo da Pilha fonte deve suceder o valor da carta no topo da Pilha destino na ordem crescente de
//               valores: A, 2, 3, 4, 5, 6, 7, 8, 9, 10, J, Q, K.
// Pós-condição: Caso as cartas atendam as condições, a carta é removida do topo da pilha fonte e inserida no topo da pilha Base.
//               Caso contrário, uma mensagem de erro é exibida
void moverCartaBase(Pilha_Cartas* fonte, Pilha_Cartas_Base* pilha_base);

// Move uma carta do topo de uma pilha para uma celula de apoio
// Pré-condição: Estrutura da Pilha fonte e Celula de apoio
// Pós-condição: A carta é removida do topo da pilha fonte e inserida na celula de apoio
Carta moverCartaPilhaParaCelula(Pilha_Cartas* fonte, Carta celula);

// Move uma carta de uma celula de apoio para o topo de uma pilha
// Pré-condição: Estrutura da Pilha destino e Celula de apoio
// Pós-condição: A carta é removida da celula de apoio e inserida no topo da pilha destino
Carta moverCartaCelulaParaPilha(Carta celula, Pilha_Cartas* fonte);

#endif // MESA_H
