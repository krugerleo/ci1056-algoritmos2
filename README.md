# ci1056-algoritmos2
(CI-1056) Algoritmos e Estrutura de Dados II - Prof: Elias duarte

Aluno: Leonardo Bueno Nogueira Kruger
##	Relatorio sobre o desenvolvimento do projeto de eleição - trabalho1:
Usamos uma lista duplamente encadeada para os candidato da seguinte maneira:
- Criamos um elemLista, um nodoLista e um tipoLista que nada mais é que um typedef do nodoLista.
- O elemLista contém os elementos de cada lista, que nesse caso são: nome do candidato, partido, numero do candidato e número de votos recebidos.
- O tipoLista/nodoLista por sua vez contêm uma variável do tipo elemLista chamada dados e dois ponteiros do tipo tipoLista *prox e *ant.
- Inicializamos o tipoLista com número do candidato “0”(lista->numero=0), para que nenhum candidato tenha número zero.

Usamos uma fila estática para os eleitores da seguinte maneira:
- Criamos um elemFila e um tipoFila.
- O elemFila contém o nome do eleitor, o número do título de eleitor e o voto. Nós inicializamos o voto como 0.
- O tipoFila contém um vetor de elemFila, e três inteiros frente, final e vez. I vez é utilizado para saber quem está na vez de votar sem precisar desenfileirar.

Usamos uma pilha dinâmica para os comprovantes de voto:
- Criamos um elemPilha, um nodoPilha e um tipoPilha.
- O elemPilha contêm o título de eleitor do votante.
- O nodoPilha contém o título do eleitor do votante no formato elemPilha e um ponteiro *prox do tipo nodoPilha
- O tipoPilha contém o tamanho da pilha(int) e um ponteiro *topo do tipo tipoPilha

Para a votação, criamos a função votar:
- Primeiro ela checa se a fila ou a lista estão vazias e se todos os eleitores da fila ja votaram, caso negativo a função prossegue.
- Então ela guarda o voto do eleitor e checa se o candidato existe, se ele existir ela contabiliza esse voto para ele(incrementa o número de votos desse candidato), cria o comprovante de voto (dá um push na pilha) e incrementa circularmente a variável da fila.vez.

Para lidar com os resultados da eleição usamos a função contabiliza da seguinte maneira:
- Checamos se a lista está vazia, caso contrário prosseguimos.
- Imprimimos na tela cada candidato e suas características(nome, número,partido e número de votos)
- Imprimimos o vencedor e o número de votos que ele teve.
- Imprimimos o número de votos e o número de comprovantes comprovando a legalidade ou a fraude das eleicoes.

##	Relatorio sobre o desenvolvimento do bingo algoritimico - trabalho2:

A struct utilizada foi "jogador" que possui um vetor[CARTELA] (CARTELA = 6) para seguir com o padrao de nao utilizar o vetor[0],
possui tres outras variaveis int para guardar as comparacoes sequenciais e binarias, e uma para guardar a quantidade de encontrados durante o jogar, para 		encontrados < 5 o jogador nao concorre ao premio.

O resultado do jogador vencedor leva em conta se ele encontrou os 5 numeros, e a quantidade de comparacoes no sequencial.
- Os resultados possiveis sao: "Jogador X ganhou, Felicitacoes ao jogador X", "Ninguem ganhou", "Empate".

Para jogar o bingo algoritimico o jogador precisa exececutar, o usuario deve ter em mente a ordem de execucao, sendo ela:
- Selecionar os numeros da sua cartela (void escolheNumero(jogador *jogador) funcao que escolhe o numero e nao permite receber repetidos).
- Gerar os numeros das cartelas dos outros jogadores(void geraNumero(jogador *jogador2,jogador *jogador3,jogador *jogador4); tambem nao permite repetidos).
- Gerar os sorteados (void geraSorteados(int sort[]) permite repetidos).
- Enfim jogador tem a opcao de imprimir os dados gerados ate o momento ou jogar.
- Apos jogar o vetor de sorteados foi ordenado pois era necessario para pesquisa binaria, jogar novamente sem gerar novos sorteados pode interferir no resultado.
Para jogar novamente:
- Para jogar novamente e recomendado, gerar todos os dados novamente, ou pelo menos os sorteados.
Para ordenacao:
- E preciso apenas gerar os sorteados.
- E entrar na opcao ordencao, la estao os algoritmos e basta selecionar um para ver a entrada e saida.
	
