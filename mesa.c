#include "mesa.h"

// "mesa.c" contém estruturas e funções para visualizar e alterar o estado atual da mesa e suas pilhas


// Permite que o programa apareça em tela cheia
// Pré-condição: nenhuma
// Pós-condição: programa ocupa toda a tela
void fullscreen(){
    keybd_event(VK_MENU,0x38,0,0);
    keybd_event(VK_RETURN,0x1c,0,0);
    keybd_event(VK_RETURN,0x1c,KEYEVENTF_KEYUP,0);
    keybd_event(VK_MENU,0x38,KEYEVENTF_KEYUP,0);
}

// Troca o valor das duas cartas
// Pré-condição: 2 Cartas
// Pós-condição: Carta a recebe o valor da Carta b e vice-e-versa
void trocarCartas (Carta* a, Carta* b)
{
    Carta aux = *a;
    *a = *b;
    *b = aux;
}

// Embaralha um vetor de cartas
// Pré-condição: Vetor de cartas e o tamanho n do vetor
// Pós-condição: Posição das cartas no vetor é sorteada de forma diferente toda vez que o programa é aberto
void embaralha(Carta* vetor, int n){
    srand (time(NULL)); // Permite mudar a semente de sequência de valores gerados por rand() sempre que iniciar o programa
                        // Dessa forma, rand() sempre irá gerar uma sequencia de valores diferentes
    int i;

    for (i = n-1; i > 0; i--) // Loop para percorrer o vetor de cartas
    {
        // Pega um valor aleatório de 0 a i
        int x = rand() % (i+1);

        // Troca o elemento que está em vetor[i] com o elemento que esta em vetor[x], escolhido aleatoriamente
        trocarCartas(&vetor[i], &vetor[x]);
    }
}

// Dá as cartas no início do jogo
// Pré-condição: nenhuma
// Pós-condição: Distribui as cartas de forma aleatoria nas 8 colunas da mesa
void darCartas(Pilha_Cartas* pilha1, Pilha_Cartas* pilha2, Pilha_Cartas* pilha3, Pilha_Cartas* pilha4, Pilha_Cartas* pilha5, Pilha_Cartas* pilha6, Pilha_Cartas* pilha7, Pilha_Cartas* pilha8){
    //srand (time(NULL)); // Permite mudar a semente de sequência de valores gerados por rand() sempre que iniciar o programa
                        // Dessa forma, rand() sempre irá gerar uma sequencia de valores diferentes
    int i, j;
    int k = 0;
    Carta aux[52];

    //Loop que distribui as cartas de cada naipe, ordenadas com valor crescente
    for(i=1; i<=4; i++){ // Seleciona um naipe
        for(j=1; j<=13; j++){ // Distribui as cartas em ordem crescente do naipe i
            aux[k].naipe = i;
            aux[k].valor = j;
            k++; // Variável auxiliar para percorrer o vetor de cartas
        }
    }

    embaralha(aux, 52); // Embaralha o vetor de cartas aleatoriamente

    int count = 0; // Variável auxiliar para percorrer o vetor inteiro e distribuir as cartas pela mesa
    for(i=0; i<7; i++){ // Distribui 7 cartas na coluna 1
        push(pilha1,aux[count]);
        count++;
    }
    for(i=0; i<7; i++){ // Distribui 7 cartas na coluna 2
        push(pilha2,aux[count]);
        count++;
    }
    for(i=0; i<7; i++){ // Distribui 7 cartas na coluna 3
        push(pilha3,aux[count]);
        count++;
    }
    for(i=0; i<7; i++){ // Distribui 7 cartas na coluna 4
        push(pilha4,aux[count]);
        count++;
    }
    for(i=0; i<6; i++){ // Distribui 6 cartas na coluna 5
        push(pilha5,aux[count]);
        count++;
    }
    for(i=0; i<6; i++){ // Distribui 6 cartas na coluna 6
        push(pilha6,aux[count]);
        count++;
    }
    for(i=0; i<6; i++){ // Distribui 6 cartas na coluna 7
        push(pilha7,aux[count]);
        count++;
    }
    for(i=0; i<6; i++){ // Distribui 6 cartas na coluna 8
        push(pilha8,aux[count]);
        count++;
    }
}

// Imprime as bordas que delimitam as áreas da mesa
// Pré-condição: nenhuma
// Pós-condição: bordas impressas na tela
void imprimirBordas(){
    int i;
    printf("+-------------------------------------------------------------------------------------------------------------------------------------------------------------------+\n");
    for(i=0; i<=30;i++){
        printf("|                                                                                                                                                                   |\n");
    }
    printf("+-------------------------------------------------------------------------------------------------------------------------------------------------------------------+\n");
    for(i=2; i<=9; i++){
        gotoxy(83,i);
        printf("|\n");
    }
}

// Imprime as 8 Pilhas que representam as pilhas de cartas móveis de jogo
// Pré-condição: nenhuma
// Pós-condição: Pilhas impressas na tela
void imprimirPilhasMoveis(Pilha_Cartas* pilha1, Pilha_Cartas* pilha2, Pilha_Cartas* pilha3, Pilha_Cartas* pilha4, Pilha_Cartas* pilha5, Pilha_Cartas* pilha6, Pilha_Cartas* pilha7, Pilha_Cartas* pilha8)
{
    gotoxy(5,16);
    gotoxy(2,10);
    printf("-------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");

    gotoxy(10,13); printf("COLUNA 1");
    imprimirPilha(pilha1, 5, 15);

    gotoxy(30,13); printf("COLUNA 2");
    imprimirPilha(pilha2, 25, 15);

    gotoxy(50,13); printf("COLUNA 3");
    imprimirPilha(pilha3, 45, 15);

    gotoxy(70,13); printf("COLUNA 4");
    imprimirPilha(pilha4, 65, 15);

    gotoxy(90,13); printf("COLUNA 5");
    imprimirPilha(pilha5, 85, 15);

    gotoxy(110,13); printf("COLUNA 6");
    imprimirPilha(pilha6, 105, 15);

    gotoxy(130,13); printf("COLUNA 7");
    imprimirPilha(pilha7, 125, 15);

    gotoxy(150,13); printf("COLUNA 8");
    imprimirPilha(pilha8, 145, 15);
}

// Imprime as 4 Pilhas que representam cada naipe
// Pré-condição: nenhuma
// Pós-condição: Pilhas impressas na tela
void imprimirPilhasBase(Pilha_Cartas_Base* pilha_base_paus, Pilha_Cartas_Base* pilha_base_ouros, Pilha_Cartas_Base* pilha_base_copas, Pilha_Cartas_Base* pilha_base_espadas)
{
    gotoxy(115,3);
    printf("PILHAS BASE\n");
    imprimirPilhaBase(pilha_base_paus, 85, 5);
    imprimirPilhaBase(pilha_base_ouros, 105, 5);
    imprimirPilhaBase(pilha_base_copas, 125, 5);
    imprimirPilhaBase(pilha_base_espadas, 145, 5);
}

// Imprime as 4 Células de apoio para movimentação das cartas na mesa
// Pré-condição: nenhuma
// Pós-condição: Células impressas na tela
void imprimirCelulasDeApoio(Carta celula1, Carta celula2, Carta celula3, Carta celula4){
    gotoxy(30,3);
    printf("CELULAS DE APOIO\n");
    switch (celula1.valor) {
        case 0: gotoxy(10,5);
                printf("CELULA 1\n");
                gotoxy(10,6);
                printf("[ VAZIO ]\n");
                break;
        default: gotoxy(10,5);
                 printf("CELULA 1\n");
                 gotoxy(5,6);
                 imprimirCarta(celula1);
                 break;
    }
    switch (celula2.valor) {
        case 0: gotoxy(30,5);
                printf("CELULA 2\n");
                gotoxy(30,6);
                printf("[ VAZIO ]\n");
                break;
        default: gotoxy(30,5);
                 printf("CELULA 2\n");
                 gotoxy(25,6);
                 imprimirCarta(celula2);
                 break;
    }
    switch (celula3.valor) {
        case 0: gotoxy(50,5);
                printf("CELULA 3\n");
                gotoxy(50,6);
                printf("[ VAZIO ]\n");
                break;
        default: gotoxy(50,5);
                 printf("CELULA 3\n");
                 gotoxy(45,6);
                 imprimirCarta(celula3);
                 break;
    }
    switch (celula4.valor) {
        case 0: gotoxy(70,5);
                printf("CELULA 4\n");
                gotoxy(70,6);
                printf("[ VAZIO ]\n");
                break;
        default: gotoxy(70,5);
                 printf("CELULA 4\n");
                 gotoxy(65,6);
                 imprimirCarta(celula4);
                 break;
    }
}

// Verifica se uma carta é antecessora a outra na ordem crescente de valores: A, 2, 3, 4, 5, 6, 7, 8, 9, 10, J, Q, K
// Pré-condição: Duas cartas
// Pós-condição: retorna 1 se a primeira carta é antecessora a segunda
//                       0 se a afirmação for falsa
int CartaAntecessora(Carta carta1, Carta carta2) {
    return ((carta1.valor+1) == carta2.valor);
}

// Move uma carta na mesa, de uma pilha para outra
// Pré-condição: Estrutura da Pilha fonte e Estrutura da Pilha destino
// Pós-condição: A carta é removida do topo da pilha fonte e inserida no topo da pilha destino
void moverCarta(Pilha_Cartas* fonte, Pilha_Cartas* destino){
     int naipe = fonte->topo->carta.naipe;

     switch (naipe) {
         case 1: //Naipe de Paus (PRETO)
             if(destino->topo->carta.naipe == 4){  // Checa se o naipe da carta no topo da pilha destino tem a mesma cor
                 gotoxy(1,60);
                 printf("[ ERRO ] -- MOVIMENTO INVALIDO!\n");
                 system("pause");
                 break;
             }
             else{ // Situação em que os naipes são de cores diferentes
                 if(CartaAntecessora(fonte->topo->carta, destino->topo->carta)){ // Checa se a carta da pilha fonte antecede a carta
                                                                   // da pilha destino na ordem crescente de valores
                     push(destino,fonte->topo->carta);
                     pop(fonte);
                     break;
                 }
                 else{ // Situação em que os naipes são de cores diferentes porém os valores das cartas não permitem o movimento
                     gotoxy(1,60);
                     printf("[ ERRO ] -- MOVIMENTO INVALIDO!\n");
                     system("pause");
                     break;
                 }
             }
         case 2: //Naipe de Ouros (VERMELHO)
             if(destino->topo->carta.naipe == 3){  // Checa se o naipe da carta no topo da pilha destino tem a mesma cor
                 gotoxy(1,60);
                 printf("[ ERRO ] -- MOVIMENTO INVALIDO!\n");
                 system("pause");
                 break;
             }
             else{ // Situação em que os naipes são de cores diferentes
                 if(CartaAntecessora(fonte->topo->carta, destino->topo->carta)){ // Checa se a carta da pilha fonte antecede a carta
                                                                   // da pilha destino na ordem crescente de valores
                     push(destino,fonte->topo->carta);
                     pop(fonte);
                     break;
                 }
                 else{ // Situação em que os naipes são de cores diferentes porém os valores das cartas não permitem o movimento
                     gotoxy(1,60);
                     printf("[ ERRO ] -- MOVIMENTO INVALIDO!\n");
                     system("pause");
                     break;
                 }
             }
         case 3: //Naipe de Copas (VERMELHO)
             if(destino->topo->carta.naipe == 2){  // Checa se o naipe da carta no topo da pilha destino tem a mesma cor
                 gotoxy(1,60);
                 printf("[ ERRO ] -- MOVIMENTO INVALIDO!\n");
                 system("pause");
                 break;
             }
             else{ // Situação em que os naipes são de cores diferentes
                 if(CartaAntecessora(fonte->topo->carta, destino->topo->carta)){ // Checa se a carta da pilha fonte antecede a carta
                                                                   // da pilha destino na ordem crescente de valores
                     push(destino,fonte->topo->carta);
                     pop(fonte);
                     break;
                 }
                 else{ // Situação em que os naipes são de cores diferentes porém os valores das cartas não permitem o movimento
                     gotoxy(1,60);
                     printf("[ ERRO ] -- MOVIMENTO INVALIDO!\n");
                     system("pause");
                     break;
                 }
             }
         case 4: //Naipe de Espadas (PRETO)
             if(destino->topo->carta.naipe == 1){  // Checa se o naipe da carta no topo da pilha destino tem a mesma cor
                 gotoxy(1,60);
                 printf("[ ERRO ] -- MOVIMENTO INVALIDO!\n");
                 system("pause");
                 break;
             }
             else{ // Situação em que os naipes são de cores diferentes
                 if(CartaAntecessora(fonte->topo->carta, destino->topo->carta)){ // Checa se a carta da pilha fonte antecede a carta
                                                                   // da pilha destino na ordem crescente de valores
                     push(destino,fonte->topo->carta);
                     pop(fonte);
                     break;
                 }
                 else{ // Situação em que os naipes são de cores diferentes porém os valores das cartas não permitem o movimento
                     gotoxy(1,60);
                     printf("[ ERRO ] -- MOVIMENTO INVALIDO!\n");
                     system("pause");
                     break;
                 }
             }
     }
}

// Move uma carta do topo de uma pilha para o topo da Pilha Base
// Pré-condição: Estrutura da Pilha fonte e Estrutura da Pilha Base.
//               As cartas no topo da Pilha fonte e Pilha Base devem ter mesmo naipe.
//               O valor da carta no topo da Pilha fonte deve suceder o valor da carta no topo da Pilha destino na ordem crescente de
//               valores: A, 2, 3, 4, 5, 6, 7, 8, 9, 10, J, Q, K.
// Pós-condição: Caso as cartas atendam as condições, a carta é removida do topo da pilha fonte e inserida no topo da pilha Base.
//               Caso contrário, uma mensagem de erro é exibida
void moverCartaBase(Pilha_Cartas* fonte, Pilha_Cartas_Base* pilha_base){
    int valor_fonte = fonte->topo->carta.valor;
    int naipe_fonte = fonte->topo->carta.naipe;

    if(pilha_base->naipe == naipe_fonte){
        if(!PilhaBaseVazia(pilha_base)){ // Caso em que a pilha base contém cartas
            if(CartaAntecessora(pilha_base->topo->carta, fonte->topo->carta)){ // Checa se a carta da pilha base antecede a carta
                                                                 // da pilha fonte na ordem crescente de valores
                push_base(pilha_base,fonte->topo->carta);
                pop(fonte);
            }
            else{
                gotoxy(1,60);
                printf("\n\n[ ERRO ] -- MOVIMENTO INVALIDO!\n"); // Caso em que a carta a ser empilhada não condiz com a ordem
                system("pause");
            }
        }
        else{ // Caso em que a pilha base está vazia
            if(valor_fonte == 1){ //Checa se a carta a ser empilhada é um A
                push_base(pilha_base,fonte->topo->carta);
                pop(fonte);
            }
            else{
                gotoxy(1,60);
                printf("\n\n[ ERRO ] -- MOVIMENTO INVALIDO!\n"); // Caso em que a pilha base está vazia e a carta a ser empilhada não é um A
                system("pause");
            }
        }
    }
    else{
        gotoxy(1,60);
        printf("\n\n[ ERRO ] -- MOVIMENTO INVALIDO!\n"); // Caso em que o naipe da carta a ser empilhada nao condiz com a pilha base
        system("pause");
    }
}


// Move uma carta do topo de uma pilha para uma celula de apoio
// Pré-condição: Estrutura da Pilha fonte e Celula de apoio
// Pós-condição: A carta é removida do topo da pilha fonte e inserida na celula de apoio
Carta moverCartaPilhaParaCelula(Pilha_Cartas* fonte, Carta celula){
    if(celula.valor!=0 && celula.naipe!=0){ // Caso já exista uma carta na celula de apoio
        gotoxy(1,60);
        printf("\n\n[ ERRO ] -- MOVIMENTO INVALIDO!\n");
        printf("\n\nJa existe uma carta nesta celula de apoio.\n");
        system("pause");
        return celula; // Retorna a mesma carta sem alteração
    }
    else{
        celula.naipe = fonte->topo->carta.naipe;
        celula.valor = fonte->topo->carta.valor;

        pop(fonte);
        return celula;
    }
}

// Move uma carta de uma celula de apoio para o topo de uma pilha
// Pré-condição: Estrutura da Pilha destino e Celula de apoio
// Pós-condição: A carta é removida da celula de apoio e inserida no topo da pilha destino
Carta moverCartaCelulaParaPilha(Carta celula, Pilha_Cartas* fonte){
    if(celula.valor==0 && celula.naipe==0){ // Caso não exista uma carta na celula de apoio
        gotoxy(1,60);
        printf("\n\n[ ERRO ] -- MOVIMENTO INVALIDO!\n");
        printf("\n\nNao existe uma carta nesta celula de apoio.\n");
        system("pause");
        return celula; // Retorna a mesma carta (no caso, "carta vazia") sem alteração
    }
    else{
        push(fonte,celula);

        celula.naipe = 0;
        celula.valor = 0;

        return celula;
    }
}
