#ifndef MENU_H
#define MENU_H
#include "jogo.h"

// menu.h contém as estruturas de menu que apresentam as ações ao usuario e as funções que realizam essas ações


// Menu em loop que controla o jogo ativo
// Pré-condição: nenhuma
// Pós-condição: Permite que o usuario mova cartas, imprima pilhas, salve seu progresso e saia do jogo.
void menuJogo();

// Requisita uma ação ao usuario
// Pré-condição: nenhuma
// Pós-condição: retorna o numero que corresponde ao movimento desejado pelo usuario.
void pedirMovimento(int* num);

// Requisita detalhes da ação ao usuario
// Pré-condição: nenhuma
// Pós-condição: retorna o numero que corresponde ao movimento desejado pelo usuario, e numeros que permitem identificar
//               a natureza do movimento
void Movimento(int* acao, int* num1, int* num2);

// Requisita uma ação ao usuario
// Pré-condição: nenhuma
// Pós-condição: retorna o numero que corresponde ao movimento desejado pelo usuario.
void pedirImpressao(int* num);

#endif // MENU_H
