#include "jogo.h"

// "jogo.c" contém funções necessárias para administrar o jogo e seu estado atual

// Recebe o usuario e o insere no jogo
// Pré-condição: nenhuma
// Pós-condição: Permite que o usuario comece um novo jogo ou carregue um jogo ja salvo
void jogo(){
    int num = 0;
    printf(" ------------------------------ [ FREECELL ] ------------------------------\n\n");
    printf("(1) - NOVO JOGO\n");
    printf("(2) - CARREGAR JOGO\n");
    printf("\nDigite o numero correspondente a sua escolha:\n");
    scanf("%d", &num);

    if(num==1 || num==2)
        menuJogo(num);
    else
        printf("ENTRADA INVALIDA.\n");
}

// Verifica se o jogador continuara jogando
// Pré-condição: nenhum
// Pós-condição: retorna 1 caso o jogo continue
//                       0 caso o jogo deva se encerrar
int isPlaying(int ctrl){
    return (ctrl != -1);
}

// Checa se as pilhas base estão completas, ou seja, se o jogador venceu o jogo
// Pré-condição: 4 estruturas de pilhas base
// Pós-condição: Uma mensagem de vitoria é exibida
int isVitoria(Pilha_Cartas_Base* paus, Pilha_Cartas_Base* ouros, Pilha_Cartas_Base* copas, Pilha_Cartas_Base* espadas){
    int control = 0;

    /*
    Carta carta_paus = criaCarta(0,1);
    Carta carta_ouros = criaCarta(0,2);
    Carta carta_copas = criaCarta(0,3);
    Carta carta_espadas = criaCarta(0,4);

    carta_paus.valor = paus->topo->carta.valor;
    carta_ouros.valor = ouros->topo->carta.valor;
    carta_copas.valor = copas->topo->carta.valor;
    carta_espadas.valor = espadas->topo->carta.valor;
    */

    if((paus->topo==NULL) || (paus->topo==NULL) || (paus->topo==NULL) || (paus->topo==NULL)){
        return control;
    }
    if((paus->topo->carta.valor == 13) &&
                                    (ouros->topo->carta.valor == 13) &&
                                                                  (copas->topo->carta.valor == 13) &&
                                                                                                (espadas->topo->carta.valor == 13)){
        control = -1; // variável auxiliar no loop de menu que encerra o loop
        system("clear");
        gotoxy(15, 15);
        printf("***********  PARABÉNS!!  *********** \n\n");
        printf("            VOCÊ VENCEU!                 ");
        system("pause");
    }
    return control;
}

// -- Funções de Arquivo Binário - para Salvar a Carregar o jogo

// Cria uma lista nova em arquivo
// Pré-condição: arquivo aberto para leitura/escrita
// Pós-condição: arquivo é inicializado com uma lista vazia
void cria_lista_vazia(FILE* arq){
    cabecalho * cab = (cabecalho*) malloc(sizeof(cabecalho));
    cab->pos_cabeca = -1;
    cab->pos_topo = 0;
    cab->pos_livre = -1;
    escreve_cabecalho(arq,cab);
    free(cab);
}

// Lê o cabeçalho do arquivo contendo as informações da lista
// Pré-condição: arquivo deve estar aberto e ser um arquivo de lista
// Pós-condição: retorna o ponteiro para o cabeçalho lido
cabecalho* le_cabecalho(FILE * arq) {
    cabecalho * cab = (cabecalho*) malloc(sizeof(cabecalho));
    fseek(arq,0,SEEK_SET); // posiciona no início do arquivo
    fread(cab,sizeof(cabecalho),1,arq);
    return cab;
}

// Escreve no arquivo o cabeçalho contendo as informações da lista
// Pré-condição: arquivo deve estar aberto e ser um arquivo de lista
// Pós-condição: cabeçalho escrito no arquivo
void escreve_cabecalho(FILE* arq, cabecalho* cab){
    fseek(arq,0,SEEK_SET); //posiciona no início do arquivo
    fwrite(cab,sizeof(cabecalho),1,arq);
}

// Lê um nó em uma determinada posição do arquivo
// Pré-condição: arquivo deve estar aberto e ser um arquivo de lista
//               pos deve ser uma posição válida da lista
// Pós-condição: ponteiro para nó lido é retornado
no* le_no(FILE* arq, int pos) {
    no* x = malloc(sizeof(no));
    fseek(arq,sizeof(cabecalho)+ pos*sizeof(no),SEEK_SET);
    fread(x,sizeof(no),1,arq);
    return x;
}

// Escreve um nó em uma determinada posição do arquivo
// Pré-condição: arquivo deve estar aberto e ser um arquivo de lista
//               pos deve ser uma posição válida do arquivo
// Pós-condição: nó escrito no arquivo
void escreve_no(FILE* arq, no* x, int pos){
    fseek(arq,sizeof(cabecalho)+ pos*sizeof(no),SEEK_SET);
    fwrite(x,sizeof(no),1,arq);
}

// Insere um nó na cabeça da lista no arquivo
void insere(FILE* arq, Carta card){
    cabecalho* cab = le_cabecalho(arq);
    no x;
    x.carta.naipe = card.naipe;
    x.carta.valor = card.valor;
    x.prox = cab->pos_cabeca;
    if(cab->pos_livre == -1) { // não há nó livres, então usar o topo
        escreve_no(arq,&x,cab->pos_topo);
        cab->pos_cabeca = cab->pos_topo;
        cab->pos_topo++;
    }
    else { // usar nó da lista de livres
        no* aux = le_no(arq,cab->pos_livre);
        escreve_no(arq,&x,cab->pos_livre);
        cab->pos_cabeca = cab->pos_livre;
        cab->pos_livre = aux->prox;
        free(aux);
    }
    escreve_cabecalho(arq,cab); free(cab);
}

// Retira um nó da lista
// Pré-condição: arquivo deve estar aberto e ser um arquivo de lista
// Pós-condição: nó retirado da lista caso pertença a ela
void retira(FILE* arq, Carta c){
    cabecalho* cab = le_cabecalho(arq);
    int pos_aux = cab->pos_cabeca;
    int pos_ant = cab->pos_cabeca;
    no* aux = NULL;
    while(pos_aux != -1 && // procura o elemento a ser retirado
                          ((aux = le_no(arq,pos_aux))!= NULL) &&
                                                                (aux->carta.naipe != c.naipe) &&
                                                                                                (aux->carta.valor != c.valor)){
        pos_ant = pos_aux;
        pos_aux = aux->prox;
        free(aux);
        aux = NULL;
    }
    if(pos_aux != -1) { //encontrou o elemento
        if(pos_ant == pos_aux){ // remoção na cabeça
            cab->pos_cabeca = aux->prox;
        }
        else { // remoção no meio
            no * ant = le_no(arq,pos_ant);
            ant->prox = aux->prox;
            escreve_no(arq,ant,pos_ant);
            free(ant);
        }
        aux->prox = cab->pos_livre; // torna o nó removido um nó livre
        cab->pos_livre = pos_aux;
        escreve_no(arq,aux,pos_aux);
        escreve_cabecalho(arq,cab);
        free(aux);
    }
    free(cab);
}

// Lê uma da lista e insere seus elementos numa pilha de cartas
// Pré-condição: arquivo deve estar aberto e ser um arquivo de lista
// Pós-condição: elemento inserido na pilha
void le_coluna(FILE* arq, Pilha_Cartas* coluna){
    cabecalho* cab = le_cabecalho(arq);
    no* read_node = le_no(arq,cab->pos_cabeca); // no da lista para arquivo que recebe as informações do arquivo

    Carta_na_Pilha* aux = (Carta_na_Pilha*) malloc(sizeof(Carta_na_Pilha)); // variavel auxiliar para inserir a carta na estrutura de pilha

    if(read_node->carta.valor != -1){
        int pos=0;
        while(pos!=-1){ // percorre o arquivo até o ultimo elemento
            aux->carta = read_node->carta; // recebe o elemento
            push(coluna,aux->carta); // insere o elemento na coluna

            pos = read_node->prox;
            read_node = le_no(arq, pos); // passa para o próximo elemento
        }
    }
    else{ // Lista vazia
        coluna->topo=NULL;
    }
}

// Lê uma lista e insere seus elementos numa pilha base de cartas de um naipe
// Pré-condição: arquivo deve estar aberto e ser um arquivo de lista
// Pós-condição: elemento inserido na pilha base
void le_pilhabase(FILE* arq, Pilha_Cartas_Base* pilhabase){
    cabecalho* cab = le_cabecalho(arq);
    no* read_node = le_no(arq,cab->pos_cabeca); // no da lista para arquivo que recebe as informações do arquivo

    Carta_na_Pilha* aux = (Carta_na_Pilha*) malloc(sizeof(Carta_na_Pilha)); // variavel auxiliar para inserir a carta na estrutura de pilha base

    if(read_node->carta.valor != -1){
        int pos=0;
        while(pos!=-1){ // percorre o arquivo até o ultimo elemento
            aux->carta = read_node->carta; // recebe o elemento
            push_base(pilhabase,aux->carta); // insere o elemento na pilha base

            pos = read_node->prox;
            read_node = le_no(arq, pos); // passa para o próximo elemento
        }
    }
    else{ // Lista vazia
        pilhabase->topo=NULL;
    }
}

// Lê uma lista e insere seus elementos nas celulas de apoio
// Pré-condição: arquivo deve estar aberto e ser um arquivo de lista
// Pós-condição: retorna um ponteiro (vetor) de cartas a serem posicionadas nas celulas de apoio
Carta* le_celulas(FILE* arq){
    cabecalho* cab = le_cabecalho(arq);
    no* read_node = le_no(arq,cab->pos_cabeca); // no da lista para arquivo que recebe as informações do arquivo

    Carta* card = (Carta*) malloc(sizeof(Carta));

    int i = 0;

    int pos=0;
    while(pos!=-1){ // percorre o arquivo até o ultimo elemento
        // recebe o elemento
        (card + i)->naipe = read_node->carta.naipe;
        (card + i)->valor = read_node->carta.valor;

        pos = read_node->prox;
        read_node = le_no(arq, pos); // passa para o próximo elemento
        i++;
    }


    return card;
}

// Lê uma pilha e insere seus elementos numa lista de arquivo
// Pré-condição: arquivo deve estar aberto e ser um arquivo de lista
// Pós-condição: arquivo contendo os elementos da pilha
void insereColuna(FILE* arq, Pilha_Cartas* pilha){
    cria_lista_vazia(arq);

    Carta_na_Pilha* aux = (Carta_na_Pilha*) malloc(sizeof(Carta_na_Pilha));
    aux = pilha->topo;

    if(!PilhaVazia(pilha)){
        while(aux!=NULL){
            insere(arq,aux->carta);
            aux = aux->prox;
        }
    }
}

// Lê uma pilha e insere seus elementos numa lista de arquivo
// Pré-condição: arquivo deve estar aberto e ser um arquivo de lista
// Pós-condição: arquivo contendo os elementos da pilha
void inserePilhaBase(FILE* arq, Pilha_Cartas_Base* pilhabase){
    cria_lista_vazia(arq);

    Carta_na_Pilha* aux = (Carta_na_Pilha*) malloc(sizeof(Carta_na_Pilha));
    aux = pilhabase->topo;

    if(!PilhaBaseVazia(pilhabase)){
        while(aux!=NULL){
            insere(arq,aux->carta);
            aux = aux->prox;
        }
    }
}

// Lê uma pilha e insere seus elementos numa lista de arquivo
// Pré-condição: arquivo deve estar aberto e ser um arquivo de lista
// Pós-condição: arquivo contendo os elementos da pilha
void insereCelulas(FILE* arq, Carta apoio1, Carta apoio2, Carta apoio3, Carta apoio4){
    cria_lista_vazia(arq);

    insere(arq, apoio1);
    insere(arq, apoio2);
    insere(arq, apoio3);
    insere(arq, apoio4);
}
