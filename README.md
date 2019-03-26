# Freecell
Trabalho apresentado para disciplina Algoritmos e Estruturas de Dados, pelo curso de Ciência da Computação da UNIOESTE em maio de 2018

# Especificações do trabalho

O jogo FreeCell  ́e um jogo de cartas que tem por finalidade agrupar todas as cartas do mesmo naipe em
4 pilhas em ordem crescente. Antes de iniciar o jogo, as cartas são embaralhadas e distribuidas na mesa em
8 pilhas.
No canto direito superior, tem-se 4 pilhas em que se deve colocar as cartas agrupadas por naipe em
ordem crescente.
Os 4 espaços no canto esquerdo superior são usados como espaços de trabalho em que se pode colocar
apenas 1 carta de qualquer uma das pilhas de cartas embaralhadas.
As cartas embaralhadas das 8 pilhas só podem ser movimentadas segundo a definição de pilha. E além
disso, ao se movimentar uma carta de uma pilha para outra, os valores devem ser decrescentes e de naipes
de cores alternadas.

Implemente uma versão do jogo na linguagem C, considerando:
- um baralho padrão de 52 cartas de 4 naipes (paus, copas, espada e ouros)
- uma carta e identificada pelo naipe e por seu valor: (A,1,2,3,4,5,6,7,8,9,10,J,Q,K)
- crie uma estrutura de dados adequada para representação/identificação das pilhas existentes no jogo
- elabore uma forma do usuário executar comandos tal que permita-o jogar segundo as regras do jogo
- a cada comando/operação realizada pelo jogador, imprimir a configuração atualizada do jogo
- não  ́e necessário implementar interface gráfica para o jogo, podendo usar apenas modo texto.

O programa deve atender às seguintes condições:
- ao iniciar um novo jogo, fazer o embaralhamento das cartas através de randomização
- o programa não deve permitir ao jogador fazer movimentos inválidos de acordo com as regras do jogo
- permitir o usuário parar de jogar em um determinado ponto do jogo, salvar o estado atual do jogo,
sair do programa e entrar novamente no programa e continuar o jogo de onde parou
- as informações do estado do jogo do item anterior devem ser salvas/carregadas em/de arquivo(s)
binário(s)
- a carga de um jogo salvo anteriormente deve ser indicada passando o nome do arquivo na linha de
comando ao executar o programa
- o usuário pode solicitar a impressão do conteúdo de cada uma das pilhas de cartas do jogo
- a implementação das pilhas em memória deve ser feita usando estrutura similar a de lista encadeada
com alocação dinamica
