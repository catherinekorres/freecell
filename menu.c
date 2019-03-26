#include "menu.h"
#define COLUNA1 "coluna1.txt"
#define COLUNA2 "coluna2.txt"
#define COLUNA3 "coluna3.txt"
#define COLUNA4 "coluna4.txt"
#define COLUNA5 "coluna5.txt"
#define COLUNA6 "coluna6.txt"
#define COLUNA7 "coluna7.txt"
#define COLUNA8 "coluna8.txt"
#define BASE1 "paus.txt"
#define BASE2 "ouros.txt"
#define BASE3 "copas.txt"
#define BASE4 "espadas.txt"
#define CELULAS "celulas.txt"


// menu.c contém as estruturas de menu que apresentam as ações ao usuario e as funções que realizam essas ações



// Menu em loop que controla o jogo ativo
// Pré-condição: nenhuma
// Pós-condição: Permite que o usuario mova cartas, imprima pilhas, salve seu progresso e saia do jogo.
void menuJogo(int game){
    system("cls");
    fullscreen();

    // Criando células de apoio
    Carta apoio1 = criaCarta(0,0);
    Carta apoio2 = criaCarta(0,0);
    Carta apoio3 = criaCarta(0,0);
    Carta apoio4 = criaCarta(0,0);

    // Criando pilhas base
    Pilha_Cartas_Base* paus = criaPilhaBase(1);
    Pilha_Cartas_Base* ouros = criaPilhaBase(2);
    Pilha_Cartas_Base* copas= criaPilhaBase(3);
    Pilha_Cartas_Base* espadas = criaPilhaBase(4);

    // Criando colunas
    Pilha_Cartas* coluna1 = criaPilha();
    Pilha_Cartas* coluna2 = criaPilha();
    Pilha_Cartas* coluna3 = criaPilha();
    Pilha_Cartas* coluna4 = criaPilha();
    Pilha_Cartas* coluna5 = criaPilha();
    Pilha_Cartas* coluna6 = criaPilha();
    Pilha_Cartas* coluna7 = criaPilha();
    Pilha_Cartas* coluna8 = criaPilha();

    int num = 0; // variavel auxiliar para coletar inputs do usuario
    int mov = 0; // variavel auxiliar para identificar o movimento desejado pelo usuario
    int num1 = 0; // variavel para auxiliar no movimento
    int num2 = 0; // variavel para auxiliar no movimento
    int imp = 0; // variavel auxiliar para identificar a impressao desejada pelo usuario

    if(game==1){ // NOVO JOGO
        // Distribui as cartas aleatoriamente na mesa
        darCartas(coluna1,coluna2,coluna3,coluna4,coluna5,coluna6,coluna7,coluna8);
    }
    if(game==2){ // CARREGAR JOGO

        // Carregando Colunas
        FILE* arq_coluna1 = fopen(COLUNA1, "r+b");
        le_coluna(arq_coluna1,coluna1);
        fclose(arq_coluna1);

        FILE* arq_coluna2 = fopen(COLUNA2, "r+b");
        le_coluna(arq_coluna2,coluna2);
        fclose(arq_coluna2);

        FILE* arq_coluna3 = fopen(COLUNA3, "r+b");
        le_coluna(arq_coluna3,coluna3);
        fclose(arq_coluna3);

        FILE* arq_coluna4 = fopen(COLUNA4, "r+b");
        le_coluna(arq_coluna4,coluna4);
        fclose(arq_coluna4);

        FILE* arq_coluna5 = fopen(COLUNA5, "r+b");
        le_coluna(arq_coluna5,coluna5);
        fclose(arq_coluna5);

        FILE* arq_coluna6 = fopen(COLUNA6, "r+b");
        le_coluna(arq_coluna6,coluna6);
        fclose(arq_coluna6);

        FILE* arq_coluna7 = fopen(COLUNA7, "r+b");
        le_coluna(arq_coluna7,coluna7);
        fclose(arq_coluna7);

        FILE* arq_coluna8 = fopen(COLUNA8, "r+b");
        le_coluna(arq_coluna8,coluna8);
        fclose(arq_coluna8);

        // Carregando Pilhas Base
        FILE* arq_base1 = fopen(BASE1, "r+b");
        le_pilhabase(arq_base1,paus);
        fclose(arq_base1);

        FILE* arq_base2 = fopen(BASE2, "r+b");
        le_pilhabase(arq_base2,ouros);
        fclose(arq_base2);

        FILE* arq_base3 = fopen(BASE3, "r+b");
        le_pilhabase(arq_base3,copas);
        fclose(arq_base3);

        FILE* arq_base4 = fopen(BASE4, "r+b");
        le_pilhabase(arq_base4,espadas);
        fclose(arq_base4);

        // Carregando Celulas
        FILE* arq_celulas = fopen(CELULAS, "r+b");
        Carta* card_array;
        card_array = le_celulas(arq_celulas);

        apoio1 = *(card_array + 3); //Desinvertendo a ordem das celulas
        apoio2 = *(card_array + 2);
        apoio3 = *(card_array + 1);
        apoio4 = *card_array;

        fclose(arq_celulas);
    }

    int ctrl = 0;
    while(isPlaying(ctrl)){
        // Imprimindo a mesa
        system("cls");
        imprimirBordas();
        imprimirCelulasDeApoio(apoio1,apoio2,apoio3,apoio4);
        imprimirPilhasBase(paus, ouros, copas, espadas);
        imprimirPilhasMoveis(coluna1,coluna2,coluna3,coluna4,coluna5,coluna6,coluna7,coluna8);

        num = 0; // variavel auxiliar para coletar inputs do usuario
        mov = 0;  // variavel auxiliar para identificar o movimento desejado pelo usuario
        num1 = 0; // variavel para auxiliar no movimento
        num2 = 0; // variavel para auxiliar no movimento
        imp = 0;  // variavel auxiliar para identificar a impressao desejada pelo usuario

        gotoxy(1,35);
        printf("O que deseja fazer?\n\n");
        printf("(1) - MOVER CARTA\n");
        printf("(2) - IMPRIMIR UMA PILHA \n");
        printf("(3) - SALVAR PROGRESSO\n");
        printf("(4) - SAIR DO JOGO\n");

        printf("\n\n\nDigite o numero correspondente ao movimento:\n");
        scanf("%d", &num);

        switch (num) {
        case 1: // MOVER CARTA
            system("cls");
            imprimirBordas();
            imprimirCelulasDeApoio(apoio1,apoio2,apoio3,apoio4);
            imprimirPilhasBase(paus, ouros, copas, espadas);
            imprimirPilhasMoveis(coluna1,coluna2,coluna3,coluna4,coluna5,coluna6,coluna7,coluna8);
            Movimento(&mov,&num1,&num2); // Solicita ao usuario qual movimento deseja fazer

            if(mov==0) // Caso em que uma entrada do usuario foi invalida
                break;
            else{
                if(mov==1){ // Mover carta de uma coluna X para outra coluna Y (COLUNA X -> COLUNA Y)
                    if(num1==1){
                        if(num2==2)
                            moverCarta(coluna1,coluna2); // COLUNA 1 -> COLUNA 2
                        if(num2==3)
                            moverCarta(coluna1,coluna3); // COLUNA 1 -> COLUNA 3
                        if(num2==4)
                            moverCarta(coluna1,coluna4); // COLUNA 1 -> COLUNA 4
                        if(num2==5)
                            moverCarta(coluna1,coluna5); // COLUNA 1 -> COLUNA 5
                        if(num2==6)
                            moverCarta(coluna1,coluna6); // COLUNA 1 -> COLUNA 6
                        if(num2==7)
                            moverCarta(coluna1,coluna7); // COLUNA 1 -> COLUNA 7
                        if(num2==8)
                            moverCarta(coluna1,coluna8); // COLUNA 1 -> COLUNA 8
                    }
                    if(num1==2){
                        if(num2==1)
                            moverCarta(coluna2,coluna1); // COLUNA 2 -> COLUNA 1
                        if(num2==3)
                            moverCarta(coluna2,coluna3); // COLUNA 2 -> COLUNA 3
                        if(num2==4)
                            moverCarta(coluna2,coluna4); // COLUNA 2 -> COLUNA 4
                        if(num2==5)
                            moverCarta(coluna2,coluna5); // COLUNA 2 -> COLUNA 5
                        if(num2==6)
                            moverCarta(coluna2,coluna6); // COLUNA 2 -> COLUNA 6
                        if(num2==7)
                            moverCarta(coluna2,coluna7); // COLUNA 2 -> COLUNA 7
                        if(num2==8)
                            moverCarta(coluna2,coluna8); // COLUNA 2 -> COLUNA 8
                    }
                    if(num1==3){
                        if(num2==1)
                            moverCarta(coluna3,coluna1); // COLUNA 3 -> COLUNA 1
                        if(num2==2)
                            moverCarta(coluna3,coluna2); // COLUNA 3 -> COLUNA 2
                        if(num2==4)
                            moverCarta(coluna3,coluna4); // COLUNA 3 -> COLUNA 4
                        if(num2==5)
                            moverCarta(coluna3,coluna5); // COLUNA 3 -> COLUNA 5
                        if(num2==6)
                            moverCarta(coluna3,coluna6); // COLUNA 3 -> COLUNA 6
                        if(num2==7)
                            moverCarta(coluna3,coluna7); // COLUNA 3 -> COLUNA 7
                        if(num2==8)
                            moverCarta(coluna3,coluna8); // COLUNA 3 -> COLUNA 8
                    }
                    if(num1==4){
                        if(num2==1)
                            moverCarta(coluna4,coluna1); // COLUNA 4 -> COLUNA 1
                        if(num2==2)
                            moverCarta(coluna4,coluna2); // COLUNA 4 -> COLUNA 2
                        if(num2==3)
                            moverCarta(coluna4,coluna3); // COLUNA 4 -> COLUNA 3
                        if(num2==5)
                            moverCarta(coluna4,coluna5); // COLUNA 4 -> COLUNA 5
                        if(num2==6)
                            moverCarta(coluna4,coluna6); // COLUNA 4 -> COLUNA 6
                        if(num2==7)
                            moverCarta(coluna4,coluna7); // COLUNA 4 -> COLUNA 7
                        if(num2==8)
                            moverCarta(coluna4,coluna8); // COLUNA 4 -> COLUNA 8
                    }
                    if(num1==5){
                        if(num2==1)
                            moverCarta(coluna5,coluna1); // COLUNA 5 -> COLUNA 1
                        if(num2==2)
                            moverCarta(coluna5,coluna2); // COLUNA 5 -> COLUNA 2
                        if(num2==3)
                            moverCarta(coluna5,coluna3); // COLUNA 5 -> COLUNA 3
                        if(num2==4)
                            moverCarta(coluna5,coluna4); // COLUNA 5 -> COLUNA 4
                        if(num2==6)
                            moverCarta(coluna5,coluna6); // COLUNA 5 -> COLUNA 6
                        if(num2==7)
                            moverCarta(coluna5,coluna7); // COLUNA 5 -> COLUNA 7
                        if(num2==8)
                            moverCarta(coluna5,coluna8); // COLUNA 5 -> COLUNA 8
                    }
                    if(num1==6){
                        if(num2==1)
                            moverCarta(coluna6,coluna1); // COLUNA 6 -> COLUNA 1
                        if(num2==2)
                            moverCarta(coluna6,coluna2); // COLUNA 6 -> COLUNA 2
                        if(num2==3)
                            moverCarta(coluna6,coluna3); // COLUNA 6 -> COLUNA 3
                        if(num2==4)
                            moverCarta(coluna6,coluna4); // COLUNA 6 -> COLUNA 4
                        if(num2==5)
                            moverCarta(coluna6,coluna5); // COLUNA 6 -> COLUNA 5
                        if(num2==7)
                            moverCarta(coluna6,coluna7); // COLUNA 6 -> COLUNA 7
                        if(num2==8)
                            moverCarta(coluna6,coluna8); // COLUNA 6 -> COLUNA 8
                    }
                    if(num1==7){
                        if(num2==1)
                            moverCarta(coluna7,coluna1); // COLUNA 7 -> COLUNA 1
                        if(num2==2)
                            moverCarta(coluna7,coluna2); // COLUNA 7 -> COLUNA 2
                        if(num2==3)
                            moverCarta(coluna7,coluna3); // COLUNA 7 -> COLUNA 3
                        if(num2==4)
                            moverCarta(coluna7,coluna4); // COLUNA 7 -> COLUNA 4
                        if(num2==5)
                            moverCarta(coluna7,coluna5); // COLUNA 7 -> COLUNA 5
                        if(num2==6)
                            moverCarta(coluna7,coluna6); // COLUNA 7 -> COLUNA 6
                        if(num2==8)
                            moverCarta(coluna7,coluna8); // COLUNA 7 -> COLUNA 8
                    }
                    if(num1==8){
                        if(num2==1)
                            moverCarta(coluna8,coluna1); // COLUNA 8 -> COLUNA 1
                        if(num2==2)
                            moverCarta(coluna8,coluna2); // COLUNA 8 -> COLUNA 2
                        if(num2==3)
                            moverCarta(coluna8,coluna3); // COLUNA 8 -> COLUNA 3
                        if(num2==4)
                            moverCarta(coluna8,coluna4); // COLUNA 8 -> COLUNA 4
                        if(num2==5)
                            moverCarta(coluna8,coluna5); // COLUNA 8 -> COLUNA 5
                        if(num2==6)
                            moverCarta(coluna8,coluna6); // COLUNA 8 -> COLUNA 6
                        if(num2==7)
                            moverCarta(coluna8,coluna7); // COLUNA 8 -> COLUNA 7
                    }
                    break;
                }
                if(mov==2){ // Mover carta de uma coluna X para uma Pilha Base Y
                    if(num1==1){
                        if(num2==1)
                            moverCartaBase(coluna1,paus); // COLUNA 1 -> PILHA DE PAUS
                        if(num2==2)
                            moverCartaBase(coluna1,ouros); // COLUNA 1 -> PILHA DE OUROS
                        if(num2==3)
                            moverCartaBase(coluna1,copas); // COLUNA 1 -> PILHA DE COPAS
                        if(num2==4)
                            moverCartaBase(coluna1,espadas); // COLUNA 1 -> PILHA DE ESPADAS
                    }
                    if(num1==2){
                        if(num2==1)
                            moverCartaBase(coluna2,paus); // COLUNA 2 -> PILHA DE PAUS
                        if(num2==2)
                            moverCartaBase(coluna2,ouros); // COLUNA 2 -> PILHA DE OUROS
                        if(num2==3)
                            moverCartaBase(coluna2,copas); // COLUNA 2 -> PILHA DE COPAS
                        if(num2==4)
                            moverCartaBase(coluna2,espadas); // COLUNA 2 -> PILHA DE ESPADAS
                    }
                    if(num1==3){
                        if(num2==1)
                            moverCartaBase(coluna3,paus); // COLUNA 3 -> PILHA DE PAUS
                        if(num2==2)
                            moverCartaBase(coluna3,ouros); // COLUNA 3 -> PILHA DE OUROS
                        if(num2==3)
                            moverCartaBase(coluna3,copas); // COLUNA 3 -> PILHA DE COPAS
                        if(num2==4)
                            moverCartaBase(coluna3,espadas); // COLUNA 3 -> PILHA DE ESPADAS
                    }
                    if(num1==4){
                        if(num2==1)
                            moverCartaBase(coluna4,paus); // COLUNA 4 -> PILHA DE PAUS
                        if(num2==2)
                            moverCartaBase(coluna4,ouros); // COLUNA 4 -> PILHA DE OUROS
                        if(num2==3)
                            moverCartaBase(coluna4,copas); // COLUNA 4 -> PILHA DE COPAS
                        if(num2==4)
                            moverCartaBase(coluna4,espadas); // COLUNA 4 -> PILHA DE ESPADAS
                    }
                    if(num1==5){
                        if(num2==1)
                            moverCartaBase(coluna5,paus); // COLUNA 5 -> PILHA DE PAUS
                        if(num2==2)
                            moverCartaBase(coluna5,ouros); // COLUNA 5 -> PILHA DE OUROS
                        if(num2==3)
                            moverCartaBase(coluna5,copas); // COLUNA 5 -> PILHA DE COPAS
                        if(num2==4)
                            moverCartaBase(coluna5,espadas); // COLUNA 5 -> PILHA DE ESPADAS
                    }
                    if(num1==6){
                        if(num2==1)
                            moverCartaBase(coluna6,paus); // COLUNA 6 -> PILHA DE PAUS
                        if(num2==2)
                            moverCartaBase(coluna6,ouros); // COLUNA 6 -> PILHA DE OUROS
                        if(num2==3)
                            moverCartaBase(coluna6,copas); // COLUNA 6 -> PILHA DE COPAS
                        if(num2==4)
                            moverCartaBase(coluna6,espadas); // COLUNA 6 -> PILHA DE ESPADAS
                    }
                    if(num1==7){
                        if(num2==1)
                            moverCartaBase(coluna7,paus); // COLUNA 7 -> PILHA DE PAUS
                        if(num2==2)
                            moverCartaBase(coluna7,ouros); // COLUNA 7 -> PILHA DE OUROS
                        if(num2==3)
                            moverCartaBase(coluna7,copas); // COLUNA 7 -> PILHA DE COPAS
                        if(num2==4)
                            moverCartaBase(coluna7,espadas); // COLUNA 7 -> PILHA DE ESPADAS
                    }
                    if(num1==8){
                        if(num2==1)
                            moverCartaBase(coluna8,paus); // COLUNA 8 -> PILHA DE PAUS
                        if(num2==2)
                            moverCartaBase(coluna8,ouros); // COLUNA 8 -> PILHA DE OUROS
                        if(num2==3)
                            moverCartaBase(coluna8,copas); // COLUNA 8 -> PILHA DE COPAS
                        if(num2==4)
                            moverCartaBase(coluna8,espadas); // COLUNA 8 -> PILHA DE ESPADAS
                    }
                    break;
                }
                if(mov==3){ // Mover carta de uma coluna X para uma Celula de Apoio Y
                    if(num1==1){
                        if(num2==1)
                            apoio1 = moverCartaPilhaParaCelula(coluna1,apoio1); // COLUNA 1 -> CELULA DE APOIO 1
                        if(num2==2)
                            apoio2 = moverCartaPilhaParaCelula(coluna1,apoio2); // COLUNA 1 -> CELULA DE APOIO 2
                        if(num2==3)
                            apoio3 = moverCartaPilhaParaCelula(coluna1,apoio3); // COLUNA 1 -> CELULA DE APOIO 3
                        if(num2==4)
                            apoio4 = moverCartaPilhaParaCelula(coluna1,apoio4); // COLUNA 1 -> CELULA DE APOIO 4
                    }
                    if(num1==2){
                        if(num2==1)
                            apoio1 = moverCartaPilhaParaCelula(coluna2,apoio1); // COLUNA 2 -> CELULA DE APOIO 1
                        if(num2==2)
                            apoio2 = moverCartaPilhaParaCelula(coluna2,apoio2); // COLUNA 2 -> CELULA DE APOIO 2
                        if(num2==3)
                            apoio3 = moverCartaPilhaParaCelula(coluna2,apoio3); // COLUNA 2 -> CELULA DE APOIO 3
                        if(num2==4)
                            apoio4 = moverCartaPilhaParaCelula(coluna2,apoio4); // COLUNA 2 -> CELULA DE APOIO 4
                    }
                    if(num1==3){
                        if(num2==1)
                            apoio1 = moverCartaPilhaParaCelula(coluna3,apoio1); // COLUNA 3 -> CELULA DE APOIO 1
                        if(num2==2)
                            apoio2 = moverCartaPilhaParaCelula(coluna3,apoio2); // COLUNA 3 -> CELULA DE APOIO 2
                        if(num2==3)
                            apoio3 = moverCartaPilhaParaCelula(coluna3,apoio3); // COLUNA 3 -> CELULA DE APOIO 3
                        if(num2==4)
                            apoio4 = moverCartaPilhaParaCelula(coluna3,apoio4); // COLUNA 3 -> CELULA DE APOIO 4
                    }
                    if(num1==4){
                        if(num2==1)
                            apoio1 = moverCartaPilhaParaCelula(coluna4,apoio1); // COLUNA 4 -> CELULA DE APOIO 1
                        if(num2==2)
                            apoio2 = moverCartaPilhaParaCelula(coluna4,apoio2); // COLUNA 4 -> CELULA DE APOIO 2
                        if(num2==3)
                            apoio3 = moverCartaPilhaParaCelula(coluna4,apoio3); // COLUNA 4 -> CELULA DE APOIO 3
                        if(num2==4)
                            apoio4 = moverCartaPilhaParaCelula(coluna4,apoio4); // COLUNA 4 -> CELULA DE APOIO 4
                    }
                    if(num1==5){
                        if(num2==1)
                            apoio1 = moverCartaPilhaParaCelula(coluna5,apoio1); // COLUNA 5 -> CELULA DE APOIO 1
                        if(num2==2)
                            apoio2 = moverCartaPilhaParaCelula(coluna5,apoio2); // COLUNA 5 -> CELULA DE APOIO 2
                        if(num2==3)
                            apoio3 = moverCartaPilhaParaCelula(coluna5,apoio3); // COLUNA 5 -> CELULA DE APOIO 3
                        if(num2==4)
                            apoio4 = moverCartaPilhaParaCelula(coluna5,apoio4); // COLUNA 5 -> CELULA DE APOIO 4
                    }
                    if(num1==6){
                        if(num2==1)
                            apoio1 = moverCartaPilhaParaCelula(coluna6,apoio1); // COLUNA 6 -> CELULA DE APOIO 1
                        if(num2==2)
                            apoio2 = moverCartaPilhaParaCelula(coluna6,apoio2); // COLUNA 6 -> CELULA DE APOIO 2
                        if(num2==3)
                            apoio3 = moverCartaPilhaParaCelula(coluna6,apoio3); // COLUNA 6 -> CELULA DE APOIO 3
                        if(num2==4)
                            apoio4 = moverCartaPilhaParaCelula(coluna6,apoio4); // COLUNA 6 -> CELULA DE APOIO 4
                    }
                    if(num1==7){
                        if(num2==1)
                            apoio1 = moverCartaPilhaParaCelula(coluna7,apoio1); // COLUNA 7 -> CELULA DE APOIO 1
                        if(num2==2)
                            apoio2 = moverCartaPilhaParaCelula(coluna7,apoio2); // COLUNA 7 -> CELULA DE APOIO 2
                        if(num2==3)
                            apoio3 = moverCartaPilhaParaCelula(coluna7,apoio3); // COLUNA 7 -> CELULA DE APOIO 3
                        if(num2==4)
                            apoio4 = moverCartaPilhaParaCelula(coluna7,apoio4); // COLUNA 7 -> CELULA DE APOIO 4
                    }
                    if(num1==8){
                        if(num2==1)
                            apoio1 = moverCartaPilhaParaCelula(coluna8,apoio1); // COLUNA 8 -> CELULA DE APOIO 1
                        if(num2==2)
                            apoio2 = moverCartaPilhaParaCelula(coluna8,apoio2); // COLUNA 8 -> CELULA DE APOIO 2
                        if(num2==3)
                            apoio3 = moverCartaPilhaParaCelula(coluna8,apoio3); // COLUNA 8 -> CELULA DE APOIO 3
                        if(num2==4)
                            apoio4 = moverCartaPilhaParaCelula(coluna8,apoio4); // COLUNA 8 -> CELULA DE APOIO 4
                    }
                    break;
                }
                if(mov==4){ // Mover carta de uma Celula de Apoio X para uma  oluna Y
                    if(num1==1){
                        if(num2==1)
                            apoio1 = moverCartaCelulaParaPilha(apoio1,coluna1); // CELULA DE APOIO 1 -> COLUNA 1
                        if(num2==2)
                            apoio1 = moverCartaCelulaParaPilha(apoio1,coluna2); // CELULA DE APOIO 1 -> COLUNA 2
                        if(num2==3)
                            apoio1 = moverCartaCelulaParaPilha(apoio1,coluna3); // CELULA DE APOIO 1 -> COLUNA 3
                        if(num2==4)
                            apoio1 = moverCartaCelulaParaPilha(apoio1,coluna4); // CELULA DE APOIO 1 -> COLUNA 4
                        if(num2==5)
                            apoio1 = moverCartaCelulaParaPilha(apoio1,coluna5); // CELULA DE APOIO 1 -> COLUNA 5
                        if(num2==6)
                            apoio1 = moverCartaCelulaParaPilha(apoio1,coluna6); // CELULA DE APOIO 1 -> COLUNA 6
                        if(num2==7)
                            apoio1 = moverCartaCelulaParaPilha(apoio1,coluna7); // CELULA DE APOIO 1 -> COLUNA 7
                        if(num2==8)
                            apoio1 = moverCartaCelulaParaPilha(apoio1,coluna8); // CELULA DE APOIO 1 -> COLUNA 8
                    }
                    if(num1==2){
                        if(num2==1)
                            apoio2 = moverCartaCelulaParaPilha(apoio2,coluna1); // CELULA DE APOIO 2 -> COLUNA 1
                        if(num2==2)
                            apoio2 = moverCartaCelulaParaPilha(apoio2,coluna2); // CELULA DE APOIO 2 -> COLUNA 2
                        if(num2==3)
                            apoio2 = moverCartaCelulaParaPilha(apoio2,coluna3); // CELULA DE APOIO 2 -> COLUNA 3
                        if(num2==4)
                            apoio2 = moverCartaCelulaParaPilha(apoio2,coluna4); // CELULA DE APOIO 2 -> COLUNA 4
                        if(num2==5)
                            apoio2 = moverCartaCelulaParaPilha(apoio2,coluna5); // CELULA DE APOIO 2 -> COLUNA 5
                        if(num2==6)
                            apoio2 = moverCartaCelulaParaPilha(apoio2,coluna6); // CELULA DE APOIO 2 -> COLUNA 6
                        if(num2==7)
                            apoio2 = moverCartaCelulaParaPilha(apoio2,coluna7); // CELULA DE APOIO 2 -> COLUNA 7
                        if(num2==8)
                            apoio2 = moverCartaCelulaParaPilha(apoio2,coluna8); // CELULA DE APOIO 2 -> COLUNA 8
                    }
                    if(num1==3){
                        if(num2==1)
                            apoio3 = moverCartaCelulaParaPilha(apoio3,coluna1); // CELULA DE APOIO 3 -> COLUNA 1
                        if(num2==2)
                            apoio3 = moverCartaCelulaParaPilha(apoio3,coluna2); // CELULA DE APOIO 3 -> COLUNA 2
                        if(num2==3)
                            apoio3 = moverCartaCelulaParaPilha(apoio3,coluna3); // CELULA DE APOIO 3 -> COLUNA 3
                        if(num2==4)
                            apoio3 = moverCartaCelulaParaPilha(apoio3,coluna4); // CELULA DE APOIO 3 -> COLUNA 4
                        if(num2==5)
                            apoio3 = moverCartaCelulaParaPilha(apoio3,coluna5); // CELULA DE APOIO 3 -> COLUNA 5
                        if(num2==6)
                            apoio3 = moverCartaCelulaParaPilha(apoio3,coluna6); // CELULA DE APOIO 3 -> COLUNA 6
                        if(num2==7)
                            apoio3 = moverCartaCelulaParaPilha(apoio3,coluna7); // CELULA DE APOIO 3 -> COLUNA 7
                        if(num2==8)
                            apoio3 = moverCartaCelulaParaPilha(apoio3,coluna8); // CELULA DE APOIO 3 -> COLUNA 8
                    }
                    if(num1==4){
                        if(num2==1)
                            apoio4 = moverCartaCelulaParaPilha(apoio4,coluna1); // CELULA DE APOIO 4 -> COLUNA 1
                        if(num2==2)
                            apoio4 = moverCartaCelulaParaPilha(apoio4,coluna2); // CELULA DE APOIO 4 -> COLUNA 2
                        if(num2==3)
                            apoio4 = moverCartaCelulaParaPilha(apoio4,coluna3); // CELULA DE APOIO 4 -> COLUNA 3
                        if(num2==4)
                            apoio4 = moverCartaCelulaParaPilha(apoio4,coluna4); // CELULA DE APOIO 4 -> COLUNA 4
                        if(num2==5)
                            apoio4 = moverCartaCelulaParaPilha(apoio4,coluna5); // CELULA DE APOIO 4 -> COLUNA 5
                        if(num2==6)
                            apoio4 = moverCartaCelulaParaPilha(apoio4,coluna6); // CELULA DE APOIO 4 -> COLUNA 6
                        if(num2==7)
                            apoio4 = moverCartaCelulaParaPilha(apoio4,coluna7); // CELULA DE APOIO 4 -> COLUNA 7
                        if(num2==8)
                            apoio4 = moverCartaCelulaParaPilha(apoio4,coluna8); // CELULA DE APOIO 4 -> COLUNA 8
                    }
                    break;
                }
                if(mov==5){ // Movimento cancelado
                    gotoxy(1,60);
                    printf("\nMOVIMENTO CANCELADO.\n");
                    system("pause");
                    break;
                }
            }
        case 2: // IMPRIMIR UMA PILHA
            system("cls");
            imprimirBordas();
            imprimirCelulasDeApoio(apoio1,apoio2,apoio3,apoio4);
            imprimirPilhasBase(paus, ouros, copas, espadas);
            imprimirPilhasMoveis(coluna1,coluna2,coluna3,coluna4,coluna5,coluna6,coluna7,coluna8);

            pedirImpressao(&imp); // Consulta que tipo de pilha de cartas o usuario deseja imprimir

            if(imp==1){ // IMPRESSAO DE UMA COLUNA
                system("cls");
                imprimirBordas();
                imprimirCelulasDeApoio(apoio1,apoio2,apoio3,apoio4);
                imprimirPilhasBase(paus, ouros, copas, espadas);
                imprimirPilhasMoveis(coluna1,coluna2,coluna3,coluna4,coluna5,coluna6,coluna7,coluna8);

                gotoxy(1,35);
                printf("Qual coluna deseja imprimir?\n\n");
                printf("(1) - IMPRIMIR COLUNA 1\n");
                printf("(2) - IMPRIMIR COLUNA 2\n");
                printf("(3) - IMPRIMIR COLUNA 3\n");
                printf("(4) - IMPRIMIR COLUNA 4\n");
                printf("(5) - IMPRIMIR COLUNA 5\n");
                printf("(6) - IMPRIMIR COLUNA 6\n");
                printf("(7) - IMPRIMIR COLUNA 7\n");
                printf("(8) - IMPRIMIR COLUNA 8\n");
                printf("\n\nDigite o numero correspondente a opcao desejada:\n");
                scanf("%d", &num);

                if(num>=1 && num<=8){
                    system("cls");
                    imprimirBordas();
                    imprimirCelulasDeApoio(apoio1,apoio2,apoio3,apoio4);
                    imprimirPilhasBase(paus, ouros, copas, espadas);
                    imprimirPilhasMoveis(coluna1,coluna2,coluna3,coluna4,coluna5,coluna6,coluna7,coluna8);

                    if(num==1)
                        imprimirPilha(coluna1, 1, 42);
                    if(num==2)
                        imprimirPilha(coluna2, 1, 42);
                    if(num==3)
                        imprimirPilha(coluna3, 1, 42);
                    if(num==4)
                        imprimirPilha(coluna4, 1, 42);
                    if(num==5)
                        imprimirPilha(coluna5, 1, 42);
                    if(num==6)
                        imprimirPilha(coluna6, 1, 42);
                    if(num==7)
                        imprimirPilha(coluna7, 1, 42);
                    if(num==8)
                        imprimirPilha(coluna8, 1, 42);
                    system("pause");
                    break;
                }
                else{ // COLUNA INVALIDA
                    gotoxy(1,60);
                    printf("\n\nENTRADA INVALIDA. POR FAVOR, TENTE NOVAMENTE.\n");
                    system("pause");
                    break;
                }
            }
            if(imp==2){  // IMPRESSAO DE UMA PILHA BASE
                system("cls");
                imprimirBordas();
                imprimirCelulasDeApoio(apoio1,apoio2,apoio3,apoio4);
                imprimirPilhasBase(paus, ouros, copas, espadas);
                imprimirPilhasMoveis(coluna1,coluna2,coluna3,coluna4,coluna5,coluna6,coluna7,coluna8);

                gotoxy(1,35);
                printf("Qual pilha base deseja imprimir?\n\n");
                printf("(1) - PAUS\n");
                printf("(2) - OUROS\n");
                printf("(3) - COPAS\n");
                printf("(4) - ESPADAS\n");
                printf("\n\nDigite o numero correspondente a opcao desejada:\n");
                scanf("%d", &num);

                if(num>=1 && num<=8){
                    system("cls");
                    imprimirBordas();
                    imprimirCelulasDeApoio(apoio1,apoio2,apoio3,apoio4);
                    imprimirPilhasBase(paus, ouros, copas, espadas);
                    imprimirPilhasMoveis(coluna1,coluna2,coluna3,coluna4,coluna5,coluna6,coluna7,coluna8);

                    if(num==1)
                        imprimirPilhaBase(paus, 1, 42);
                    if(num==2)
                        imprimirPilhaBase(ouros, 1, 42);
                    if(num==3)
                        imprimirPilhaBase(copas, 1, 42);
                    if(num==4)
                        imprimirPilhaBase(espadas, 1, 42);
                    system("pause");
                    break;
                }
                else{ // PILHA BASE INVALIDA
                    gotoxy(1,60);
                    printf("\n\nENTRADA INVALIDA. POR FAVOR, TENTE NOVAMENTE.\n");
                    system("pause");
                    break;
                }
            }
            if(imp==3){
                gotoxy(1,60);
                printf("\nMOVIMENTO CANCELADO.\n");
                system("pause");
                break;
            }
            if(imp<1 || imp>3){ // ENTRADA INVALIDA
                gotoxy(1,60);
                printf("\n\nENTRADA INVALIDA. POR FAVOR, TENTE NOVAMENTE.\n");
                system("pause");
                break;
            }
        case 3: // SALVAR PROGRESSO
            // Saída do switch para possibilitar abertura de arquivos
            goto save_game;
        case 4: // SAIR DO JOGO
            ctrl = -1;
            gotoxy(1,60);
            printf("SAINDO...\n");
            system("pause");
            goto leave_game;
            break;
        default:
            gotoxy(1,60);
            printf("\n\nENTRADA INVALIDA. POR FAVOR, TENTE NOVAMENTE.\n");
            system("pause");
            break;
        }
        save_game:
        if(num==3){ // SALVAR PROGRESSO - INÍCIO
            // Salvando Colunas
            FILE* arq_coluna1 = fopen(COLUNA1, "w+b");
            insereColuna(arq_coluna1,coluna1);
            fclose(arq_coluna1);

            FILE* arq_coluna2 = fopen(COLUNA2, "w+b");
            insereColuna(arq_coluna2,coluna2);
            fclose(arq_coluna2);

            FILE* arq_coluna3 = fopen(COLUNA3, "w+b");
            insereColuna(arq_coluna3,coluna3);
            fclose(arq_coluna3);

            FILE* arq_coluna4 = fopen(COLUNA4, "w+b");
            insereColuna(arq_coluna4,coluna4);
            fclose(arq_coluna4);

            FILE* arq_coluna5 = fopen(COLUNA5, "w+b");
            insereColuna(arq_coluna5,coluna5);
            fclose(arq_coluna5);

            FILE* arq_coluna6 = fopen(COLUNA6, "w+b");
            insereColuna(arq_coluna6,coluna6);
            fclose(arq_coluna6);

            FILE* arq_coluna7 = fopen(COLUNA7, "w+b");
            insereColuna(arq_coluna7,coluna7);
            fclose(arq_coluna7);

            FILE* arq_coluna8 = fopen(COLUNA8, "w+b");
            insereColuna(arq_coluna8,coluna8);
            fclose(arq_coluna8);

            // Salvando Pilhas Base
            FILE* arq_base1 = fopen(BASE1, "w+b");
            inserePilhaBase(arq_base1,paus);
            fclose(arq_base1);

            FILE* arq_base2 = fopen(BASE2, "w+b");
            inserePilhaBase(arq_base2,ouros);
            fclose(arq_base2);

            FILE* arq_base3 = fopen(BASE3, "w+b");
            inserePilhaBase(arq_base3,copas);
            fclose(arq_base3);

            FILE* arq_base4 = fopen(BASE4, "w+b");
            inserePilhaBase(arq_base4,espadas);
            fclose(arq_base4);

            // Salvando Celulas
            FILE* arq_celulas = fopen(CELULAS, "w+b");
            insereCelulas(arq_celulas, apoio1, apoio2, apoio3, apoio4);
            fclose(arq_celulas);

            gotoxy(1,60);
            printf("JOGO SALVO COM SUCESSO.\n\n");
            system("pause");
        }
        ctrl = isVitoria(paus, ouros, copas, espadas); // Checa se o jogador venceu a partida com a ultima ação
    }

    leave_game:
    // Liberando a memoria das estruturas de pilhas base
    deletaPilhaBase(paus);
    deletaPilhaBase(ouros);
    deletaPilhaBase(copas);
    deletaPilhaBase(espadas);

    // Liberando a memoria das estruturas de colunas
    deletaPilha(coluna1);
    deletaPilha(coluna2);
    deletaPilha(coluna3);
    deletaPilha(coluna4);
    deletaPilha(coluna5);
    deletaPilha(coluna6);
    deletaPilha(coluna7);
    deletaPilha(coluna8);
}

// Requisita uma ação ao usuario
// Pré-condição: nenhuma
// Pós-condição: retorna o numero que corresponde ao movimento desejado pelo usuario.
void pedirMovimento(int* num){
    gotoxy(1,35);
    printf("Qual movimento deseja fazer?\n\n");
    printf("(1) - MOVER CARTA DE UMA COLUNA PARA OUTRA\n");
    printf("(2) - MOVER CARTA DE UMA COLUNA PARA UMA PILHA BASE\n");
    printf("(3) - MOVER CARTA DE UMA COLUNA PARA UMA CELULA DE APOIO\n");
    printf("(4) - MOVER CARTA DE UMA CELULA DE APOIO PARA UMA COLUNA \n");
    printf("(5) - CANCELAR MOVIMENTO \n");

    printf("\n\nDigite o numero correspondente ao movimento:\n");
    scanf("%d", num);
}

// Requisita detalhes da ação ao usuario
// Pré-condição: nenhuma
// Pós-condição: retorna o numero que corresponde ao movimento desejado pelo usuario, e numeros que permitem identificar
//               a natureza do movimento
void Movimento(int* mov, int* num1, int* num2){
    *mov = 0;
    *num1 = 0;
    *num2 = 0;

    pedirMovimento(mov);

    int aux = *mov; // Variável auxiliar para utilização no switch

    switch (aux) {
    case 1:  // MOVER CARTA DE UMA COLUNA PARA OUTRA
        printf("\nDe qual coluna gostaria de mover a carta?\n");
        printf("Digite o numero correspondente a coluna:\n");
        scanf("%d", num1);

        if(*num1>=1 && *num1<=8){  // COLUNA FONTE VALIDA
            printf("\nPara qual coluna essa carta sera movida?\n");
            printf("Digite o numero correspondente a coluna:\n");
            scanf("%d", num2);
            if(*num2>=1 && *num2<=8) // COLUNA DESTINO VALIDA
                break;
            else{ // COLUNA DESTINO INVALIDA
                *num1 = 0; // reinicializa o valor da variável
                *num2 = 0; // reinicializa o valor da variável
                printf("\n\nENTRADA INVALIDA. POR FAVOR, TENTE NOVAMENTE.\n");
                break;
            }
        }
        else{ // COLUNA FONTE INVALIDA
            *num1 = 0;
            printf("\n\nENTRADA INVALIDA. POR FAVOR, TENTE NOVAMENTE.\n");
            break;
        }
    case 2: // MOVER CARTA DE UMA COLUNA PARA UMA PILHA BASE
        printf("\nDe qual coluna gostaria de mover a carta?\n");
        printf("Digite o numero correspondente a coluna:\n");
        scanf("%d", num1);

        if(*num1>=1 && *num1<=8){ // COLUNA FONTE VALIDA
            printf("\nPara qual pilha base essa carta sera movida?\n");
            printf("PILHAS BASE:\n(1) - PAUS \n(2) - OUROS \n(3) - COPAS \n(4) - ESPADAS \n\n");
            printf("Apos efetuado o movimento, essa carta nao podera ser retirada da pilha base.\n");
            printf("Digite o numero correspondente a pilha base:\n");
            scanf("%d", num2);
            if(*num2>=1 && *num2<=4) // PILHA BASE VALIDA
                break;
            else{ // PILHA BASE INVALIDA
                *num1 = 0; // reinicializa o valor da variável
                *num2 = 0; // reinicializa o valor da variável
                printf("\n\nENTRADA INVALIDA. POR FAVOR, TENTE NOVAMENTE.\n");
                break;
            }
        }
        else{ // COLUNA FONTE INVALIDA
            *num1 = 0;
            printf("\n\nENTRADA INVALIDA. POR FAVOR, TENTE NOVAMENTE.\n");
            break;
        }
    case 3: // MOVER CARTA DE UMA COLUNA PARA UMA CELULA DE APOIO
        printf("\nDe qual coluna gostaria de mover a carta?\n");
        printf("Digite o numero correspondente a coluna:\n");
        scanf("%d", num1);

        if(*num1>=1 && *num1<=8){ // COLUNA FONTE VALIDA
            printf("\nPara qual celula de apoio essa carta sera movida?\n");
            printf("Digite o numero correspondente a celula de apoio:\n");
            scanf("%d", num2);
            if(*num2>=1 && *num2<=4) // CELULA DE APOIO VALIDA
                break;
            else{ // CELULA DE APOIO INVALIDA
                *num1 = 0; // reinicializa o valor da variável
                *num2 = 0; // reinicializa o valor da variável
                printf("\n\nENTRADA INVALIDA. POR FAVOR, TENTE NOVAMENTE.\n");
                break;
            }
        }
        else{ // COLUNA FONTE INVALIDA
            *num1 = 0;
            printf("\n\nENTRADA INVALIDA. POR FAVOR, TENTE NOVAMENTE.\n");
            break;
        }
    case 4: // MOVER CARTA DE UMA CELULA DE APOIO PARA UMA COLUNA
        printf("\nDe qual celula de apoio gostaria de mover a carta?\n");
        printf("Digite o numero correspondente a celula de apoio:\n");
        scanf("%d", num1);

        if(*num1>=1 && *num1<=4){ // CELULA DE APOIO VALIDA
            printf("\nPara qual coluna essa carta sera movida?\n");
            printf("Digite o numero correspondente a coluna:\n");
            scanf("%d", num2);
            if(*num2>=1 && *num2<=8) // COLUNA DESTINO VALIDA
                break;
            else{ // COLUNA DESTINO INVALIDA
                *num1 = 0; // reinicializa o valor da variável
                *num2 = 0; // reinicializa o valor da variável
                printf("\n\nENTRADA INVALIDA. POR FAVOR, TENTE NOVAMENTE.\n");
                break;
            }
        }
        else{ // CELULA DE APOIO INVALIDA
            *num1 = 0; // reinicializa o valor da variável
            printf("\n\nENTRADA INVALIDA. POR FAVOR, TENTE NOVAMENTE.\n");
            break;
        }
    case 5:  // CANCELAR MOVIMENTO
        break;
    default: // ENTRADA DE MOVIMENTO NÃO EXISTENTE
        *mov = 0; // reinicializa o valor da variável
        printf("\n\nENTRADA INVALIDA. POR FAVOR, TENTE NOVAMENTE.\n");
        break;
    }
    system("pause");
}

// Requisita uma ação ao usuario
// Pré-condição: nenhuma
// Pós-condição: retorna o numero que corresponde ao movimento desejado pelo usuario.
void pedirImpressao(int* num){
    gotoxy(1,35);
    printf("Qual tipo de pilha de cartas deseja imprimir?\n\n");
    printf("(1) - IMPRIMIR COLUNA\n");
    printf("(2) - IMPRIMIR PILHA BASE\n");
    printf("(3) - CANCELAR IMPRESSAO \n");

    printf("\n\nDigite o numero correspondente a opcao desejada:\n");
    scanf("%d", num);
}
