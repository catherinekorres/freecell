#include "pilhas.h"

// "pilhas.c" contém as funções necessárias para representar e manipular individualmente as pilhas de cartas que serão utilizadas no jogo


// Permite que o cursor vá para um local específico da tela
// Pré-condição: coordenadas do eixo x e y do local desejado
// Pós-condição: cursor se posiciona nas coordenadas (x,y)
//              OBS: utilizada para auxiliar na impressao das pilhas
void gotoxy(int x, int y){
     SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),(COORD){x-1,y-1});
}


// --- Funções para Pilhas de Carta Comuns

// Cria uma pilha de cartas vazia
// Pré-condição: nenhuma
// Pós-condição: estrutura de pilha criada
Pilha_Cartas* criaPilha(){
    Pilha_Cartas* nova_pilha = (Pilha_Cartas*) malloc(sizeof(Pilha_Cartas));
    nova_pilha->topo = NULL;
    return nova_pilha;
}

// Verifica se a pilha de cartas está vazia
// Pré-condição: Estrutura de pilha de cartas
// Pós-condição: retorna 1 se a pilha é vazia
//                       0 se a pilha contém algo
int PilhaVazia(Pilha_Cartas* p) {
    return (p->topo == NULL);
}

// Empilha uma carta no topo da pilha
// Pré-condição: Estrutura de pilha de cartas
// Pós-condição: Carta no topo da pilha
void push(Pilha_Cartas* p, Carta c) {
    Carta_na_Pilha* aux = (Carta_na_Pilha*) malloc(sizeof(Carta_na_Pilha));
    aux->carta.naipe = c.naipe;
    aux->carta.valor = c.valor;
    aux->prox = p->topo;
    p->topo = aux;
}

// Desempilha uma carta da pilha, ou seja, retira uma carta do topo da pilha
// Pré-condição: Estrutura de pilha de cartas
// Pós-condição: Carta retirada da pilha
Carta* pop(Pilha_Cartas* p) {
    if(!PilhaVazia(p)) {
        Carta* c = (Carta*) malloc(sizeof(Carta));
        Carta_na_Pilha* aux = p->topo;
        *c = p->topo->carta;
        p->topo = p->topo->prox;
        free(aux);
        return c;
    }
    else {
        printf("[ VAZIO ]\n");
        return NULL;
    }
}

// Deleta uma pilha de cartas
// Pré-condição: Estrutura de pilha
// Pós-condição: Parte da memória que continha a estrutura da pilha é liberada
void deletaPilha(Pilha_Cartas* p){
    if(!PilhaVazia(p)){
        while(p->topo!=NULL){
            pop(p);
        }
        free(p);
    }
}

// Inverte uma pilha de cartas
// Pré-condição: Estrutura de pilha de cartas
// Pós-condição: Estrutura de pilha de cartas com os mesmos itens, em ordem inversa
Pilha_Cartas* invertePilha(Pilha_Cartas* p){
    if(!PilhaVazia(p)) {
        Pilha_Cartas* p_inversa = criaPilha(); //pilha auxiliar, que ira equivaler a pilha p inversa
        Carta_na_Pilha* c_aux = p->topo; //variável auxiliar usada para percorrer a pilha

        while(c_aux!=NULL){
            push(p_inversa,c_aux->carta);
            c_aux = c_aux->prox;
        }
        return p_inversa;
    }
    else
        return NULL;
}

// Imprime uma pilha de cartas
// Pré-condição: Estrutura de pilha de cartas
// Pós-condição: Pilha de cartas impressa na tela, com cada carta no formato "[ VALOR de NAIPE ]", uma abaixo da outra
//               OBS: Para realizar a impressao da pilha, ela sera antes invertida
//                    A inversao se viu necessaria para que a impressao do jogo fique mais intuitiva
//                    Dessa forma, a ultima carta a ser impressa sera a carta que pode ser movimentada
void imprimirPilha(Pilha_Cartas* p, int x, int y){
    if(!PilhaVazia(p)) {
        Pilha_Cartas* p_inversa = criaPilha();
        p_inversa = invertePilha(p);

        Carta_na_Pilha* aux = p_inversa->topo; //variável auxiliar usada para percorrer a pilha
        int i = y;
        while(aux!=NULL){
            gotoxy(x, i);
            imprimirCarta(aux->carta);
            aux = aux->prox;
            i++;
        }
    }
    else {
        gotoxy(x+2,y);
        printf("[ VAZIO ]\n");
    }
    printf("\n");
}



// --- Funções para Pilhas Base de Carta (Pilhas que representam um naipe)

// Cria uma pilha base de cartas vazia
// Pré-condição: nenhuma
// Pós-condição: estrutura de pilha criada
Pilha_Cartas_Base* criaPilhaBase(int naipe){
    Pilha_Cartas_Base* nova_pilha = (Pilha_Cartas_Base*) malloc(sizeof(Pilha_Cartas_Base));
    nova_pilha->topo = NULL;
    nova_pilha->naipe = naipe;
    return nova_pilha;
}

// Verifica se uma pilha base de cartas de um naipe está vazia
// Pré-condição: Estrutura de pilha base de cartas
// Pós-condição: retorna 1 se a pilha é vazia
//                       0 se a pilha contém algo
int PilhaBaseVazia(Pilha_Cartas_Base* p){
    return (p->topo == NULL);
}

// Empilha uma carta no topo da pilha base
// Pré-condição: Estrutura de pilha base de cartas
// Pós-condição: Carta no topo da pilha
void push_base(Pilha_Cartas_Base* p, Carta c){
    Carta_na_Pilha* aux = (Carta_na_Pilha*) malloc(sizeof(Carta_na_Pilha));
    aux->carta.naipe = c.naipe;
    aux->carta.valor = c.valor;
    aux->prox = p->topo;
    p->topo = aux;
}

// Desempilha uma carta da pilha base, ou seja, retira uma carta do topo da pilha base
// Pré-condição: Estrutura de pilha base de cartas
// Pós-condição: Carta retirada da pilha base
//               OBS: Operação feita apenas ao final do jogo para desalocar a memoria
Carta* pop_base(Pilha_Cartas_Base* p) {
    if(!PilhaBaseVazia(p)) {
        Carta* c = (Carta*) malloc(sizeof(Carta));
        Carta_na_Pilha* aux = p->topo;
        *c = p->topo->carta;
        p->topo = p->topo->prox;
        free(aux);
        return c;
    }
    else {
        printf("[ VAZIO ]\n");
        return NULL;
    }
}

// Deleta uma pilha de cartas
// Pré-condição: Estrutura de pilha base de cartas
// Pós-condição: Parte da memória que continha a estrutura da pilha é liberada
void deletaPilhaBase(Pilha_Cartas_Base* p){
    if(!PilhaBaseVazia(p)){
        while(p->topo!=NULL){
            pop_base(p);
        }
        free(p);
    }
}

// Imprime uma pilha base de cartas de um naipe
// Pré-condição: Estrutura de pilha base de cartas
// Pós-condição: Pilha de cartas base impressa na tela, com o cabeçalho "[ NAIPE ]" cada carta no formato "[ VALOR de NAIPE ]", uma abaixo da outra
void imprimirPilhaBase(Pilha_Cartas_Base* p, int x, int y){
    switch(p->naipe) {
        case 1: gotoxy(x+4,y); printf("PAUS\n"); break;
        case 2: gotoxy(x+4,y); printf("OUROS\n"); break;
        case 3: gotoxy(x+4,y); printf("COPAS\n"); break;
        case 4: gotoxy(x+3,y); printf("ESPADAS\n"); break;
    }
    if(!PilhaBaseVazia(p)) {
        gotoxy(x,y+1);
        imprimirCarta(p->topo->carta);
    }
    else {
        gotoxy(x+2,y+1);
        printf("[ VAZIO ]\n");
    }
    printf("\n");
}
