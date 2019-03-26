#ifndef JOGO_H
#define JOGO_H
#include "mesa.h"
#include "menu.h"

// "jogo.h" contém funções necessárias para administrar o jogo e seu estado atual



// Menu inicial que recebe o usuario
// Pré-condição: nenhuma
// Pós-condição: Permite que o usuario comece um novo jogo ou carregue um jogo ja salvo
void jogo();

// Verifica se o jogador continuara jogando
// Pré-condição: nenhum
// Pós-condição: retorna 1 caso o jogo continue
//                       0 caso o jogo deva se encerrar
int isPlaying(int ctrl);

// Checa se as pilhas base estão completas, ou seja, se o jogador venceu o jogo
// Pré-condição: 4 estruturas de pilhas base
// Pós-condição: Uma mensagem de vitoria é exibida
int isVitoria(Pilha_Cartas_Base* paus, Pilha_Cartas_Base* ouros, Pilha_Cartas_Base* copas, Pilha_Cartas_Base* espadas);


// Cabeçalho do arquivo para salvar o jogo
typedef struct {
    int pos_cabeca; //posição do inicio da lista
    int pos_topo; // primeira posição nao usada no fim do arquivo
    int pos_livre; // posição do inicio da lista de nós livres
} cabecalho;

// estrutura de no para lista encadeada
typedef struct {
    Carta carta;
    int prox;
} no;


// -- Funções de Arquivo Binário - para Salvar a Carregar o jogo

// Cria uma lista nova em arquivo
// Pré-condição: arquivo aberto para leitura/escrita
// Pós-condição: arquivo é inicializado com uma lista vazia
void cria_lista_vazia(FILE* arq);

// Lê o cabeçalho do arquivo contendo as informações da lista
// Pré-condição: arquivo deve estar aberto e ser um arquivo de lista
// Pós-condição: retorna o ponteiro para o cabeçalho lido
cabecalho* le_cabecalho(FILE * arq);

// Escreve no arquivo o cabeçalho contendo as informações da lista
// Pré-condição: arquivo deve estar aberto e ser um arquivo de lista
// Pós-condição: cabeçalho escrito no arquivo
void escreve_cabecalho(FILE* arq, cabecalho* cab);

// Lê um nó em uma determinada posição do arquivo
// Pré-condição: arquivo deve estar aberto e ser um arquivo de lista
//               pos deve ser uma posição válida da lista
// Pós-condição: ponteiro para nó lido é retornado
no* le_no(FILE* arq, int pos);

// Escreve um nó em uma determinada posição do arquivo
// Pré-condição: arquivo deve estar aberto e ser um arquivo de lista
//               pos deve ser uma posição válida do arquivo
// Pós-condição: nó escrito no arquivo
void escreve_no(FILE* arq, no* x, int pos);

// Insere um nó na cabeça da lista no arquivo
void insere(FILE* arq, Carta c);

// Retira um nó da lista
// Pré-condição: arquivo deve estar aberto e ser um arquivo de lista
// Pós-condição: nó retirado da lista caso pertença a ela
void retira(FILE* arq, Carta c);

// Lê uma da lista e insere seus elementos numa pilha de cartas
// Pré-condição: arquivo deve estar aberto e ser um arquivo de lista
// Pós-condição: elemento inserido na pilha
void le_coluna(FILE* arq, Pilha_Cartas* coluna);

// Lê uma lista e insere seus elementos numa pilha base de cartas de um naipe
// Pré-condição: arquivo deve estar aberto e ser um arquivo de lista
// Pós-condição: elemento inserido na pilha base
void le_pilhabase(FILE* arq, Pilha_Cartas_Base* pilhabase);

// Lê uma lista e insere seus elementos nas celulas de apoio
// Pré-condição: arquivo deve estar aberto e ser um arquivo de lista
// Pós-condição: retorna um ponteiro (vetor) de cartas a serem posicionadas nas celulas de apoio
Carta* le_celulas(FILE* arq);

// Lê uma pilha e insere seus elementos numa lista de arquivo
// Pré-condição: arquivo deve estar aberto e ser um arquivo de lista
// Pós-condição: arquivo contendo os elementos da pilha
void insereColuna(FILE* arq, Pilha_Cartas* pilha);

// Lê uma pilha e insere seus elementos numa lista de arquivo
// Pré-condição: arquivo deve estar aberto e ser um arquivo de lista
// Pós-condição: arquivo contendo os elementos da pilha
void inserePilhaBase(FILE* arq, Pilha_Cartas_Base* pilhabase);

// Lê uma pilha e insere seus elementos numa lista de arquivo
// Pré-condição: arquivo deve estar aberto e ser um arquivo de lista
// Pós-condição: arquivo contendo os elementos da pilha
void insereCelulas(FILE* arq, Carta apoio1, Carta apoio2, Carta apoio3, Carta apoio4);

#endif // JOGO_H
