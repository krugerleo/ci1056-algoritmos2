/* --------------------------------------------------------------------------------------
   Programa que implementa um bingo algoritmo utilizando algoritmos de ordenacao e pesquisa
   Objetivo: Implementar pesquisa e ordenacoes estudadas em sala
   Restricoes: O usuario deve ter em mente a execucao dos passos em ordem correta

   Autor: Leonardo B. N. Kruger
   Disciplina: Algoritmos II
   Data da ultima atualizacao: 15/11/2018
----------------------------------------------------------------------------------------*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define TamMax 101
#include "bingo.h"
#include <math.h>
void imprimeCartela(int cartela[],int tam){
	int i,k;
	printf("\n");
	for(i=1;i<tam;i++){
		if(cartela[i]<10)
			printf("|0%d",cartela[i] );
		else
			printf("|%d",cartela[i] );
		if( i%20 == 0)
			printf("|\n");
	}
	if(i == CARTELA)
		printf("|\n");
	printf("\n");
}

void geraSorteados(int sort[]){
	puts("============================ ENTROU GERA SORTEADOS ============================");
	int i,j;
	for(i=1;i < TamMax;i++){
		j = rand() % 100;
		sort[i]=j;
	}
	printf("Os numeros sorteados sao \n");
	imprimeCartela(sort,TamMax);
	puts("============================ SAIU GERA SORTEADOS ============================");
}

int buscaNum(int vetor[6],int num){
	int i;
	for(i=1;i < CARTELA;i++){
		if(num == vetor[i]){
			printf("Nao e permitido numeros repetidos na cartela.\n");
			printf("Escolha ou gere outro numero.\n");
			return 1;
		}
	}
	return 0;
}


void escolheNumero(jogador *jogador){
	puts("============================ ENTROU ESCOLHA DE NUMEROS ============================");
	int i,j,busca;
	
	for(i=1;i<CARTELA;i++) // zera o vetor para escolha de novos, sem que fique dando como repetidos
		jogador->cartela[i]=-1;

	for(i=1;i < CARTELA; i++){
		do{
			printf("Digite o %d numero da cartela\n",i );
			printf("Entrada : ");
			scanf("%d",&j);
			getchar();
			printf("Entrada Digirada : %d \n",j ); // verifica se nao foram digitados valores repetidos
			busca = buscaNum(jogador->cartela,j); 
			if(j < 0 || j >= 100){ // verifica se o numero esta no intervalo especifico
				printf("O numero %d nao esta entre 0 e 99 \n",j );
				busca = 1;
			}
		}while(busca == 1);
		jogador->cartela[i] = j;
	}
	printf("A sua cartela sera :\n");
	imprimeCartela(jogador->cartela,CARTELA);
	puts("============================== SAIU ESCOLHA DE NUMEROS ============================");
}

void geraNumero(jogador *jogador2,jogador *jogador3,jogador *jogador4){
	puts("============================ ENTROU GERA NUMEROS JOG ============================");
	int i,j,busca;

	for(i=1;i < CARTELA; i++){
		do{
			j = rand() % 100;
			busca = buscaNum(jogador2->cartela,j); // verifica se nao e um numero repetido
		}while(busca == 1);
		jogador2->cartela[i] = j;
	}
	printf("\n");
	puts("Cartela jogador 2:");
	imprimeCartela(jogador2->cartela,CARTELA);
	for(i=1;i < CARTELA; i++){
		do{
			j = rand() % 100;
			busca = buscaNum(jogador3->cartela,j); // verifica se nao e um numero repetido
		}while(busca == 1);
		jogador3->cartela[i] = j;
	}
	printf("\n");
	puts("Cartela jogador 3:");
	imprimeCartela(jogador3->cartela,CARTELA);
	for(i=1;i < CARTELA; i++){
		do{
			j = rand() % 100;
			busca = buscaNum(jogador4->cartela,j); // verifica se nao e um numero repetido
		}while(busca == 1);
		jogador4->cartela[i] = j;
	}
	printf("\n");
	puts("Cartela jogador 4:");
	imprimeCartela(jogador4->cartela,CARTELA);
	puts("============================== SAIU GERA NUMEROS JOG ============================");
}

void copiaVetor(int vet[], int cpy[]){
	for(int i=1; i < TamMax; i++)
		cpy[i] = vet[i];
}

void menu(jogador *JogUm,jogador *JogDois,jogador *JogTres,jogador *JogQuatro){
	int j,i = 10;
	int sorteado[TamMax];
	int select[TamMax];
	int shellUm[TamMax];
	int shellDois[TamMax];
	int shellTres[TamMax];
	int quick[TamMax];
	puts("================================= ENTROU NO MENU =================================");
	puts("======================== BEM VINDO AO BINGO ALGORITMICO ==========================\n");
	puts("Para o funcionamento correto do jogo crie as cartelas de todos os jogadores\n e os numeros sorteados antes de jogar! divirta-se !\n");
	while(i != 0){
		printf("1 - Selecionar numeros para jogar\n"); // Faz a escolha dos numeros para sua cartela
		printf("2 - Gerar numeros dos outros jogadores\n"); // Gera numeros aleatorios para as cartelas dos outros jogadores
		printf("3 - Gerar Sorteados\n"); // Gera numeros aleatorios para as cartelas dos outros jogadores
		printf("4 - Imprime Cartelas e Sorteados\n");
		printf("5 - Jogar\n"); // Gera o vetor de sorteados e desencadeia o jogo 
		printf("6 - Odernacao\n");
		printf("0 - Sair\n");
		do{
			printf("Entrada: ");
			scanf("%d",&i);
			getchar();
			printf("\n");
			printf("Entrada recebida : %d \n",i );
		}while(i != 1 && i != 2 && i != 3 && i != 4 && i != 6 && i != 5 && i != 0 );
		
		switch(i){
			case (1):
				escolheNumero(JogUm);
				break;
			case(2):
				geraNumero(JogDois,JogTres,JogQuatro);
				break;
			case(3):
				geraSorteados(sorteado);
				copiaVetor(sorteado,select);
				copiaVetor(sorteado,shellUm);
				copiaVetor(sorteado,shellDois);
				copiaVetor(sorteado,shellTres);
				copiaVetor(sorteado,quick);
				break;
			case(4):
				puts("Cartela do jogador 1");
				imprimeCartela(JogUm->cartela,CARTELA);
				puts("Cartela do jogador 2");
				imprimeCartela(JogDois->cartela,CARTELA);
				puts("Cartela do jogador 3");
				imprimeCartela(JogTres->cartela,CARTELA);
				puts("Cartela do jogador 4");
				imprimeCartela(JogQuatro->cartela,CARTELA);
				puts("Os numeros sorteados sao");
				imprimeCartela(sorteado,TamMax);
				break;
			case(5):
				jogar(JogUm,JogDois,JogTres,JogQuatro,sorteado);
				break;
			case(6):
				while(j != 0){
					printf("1 - QuickSort\n" );
					printf("2 - SelectSort\n" );
					printf("3 - ShellSort (Espacamento da aula N/3)\n" );
					printf("4 - ShellSort (Potencia de 2)\n" );
					printf("5 - ShellSort (N-1/3)\n" );
					printf("0 - Sair\n" );
					do{
						printf("Entrada: ");
						scanf("%d",&j);
						getchar();
						printf("\n");
						printf("Entrada recebida : %d \n",j );
					}while(j != 0 && j != 1 && j != 2 && j != 3 && j != 4 && j != 5);
					switch(j){
						case(1):
							puts("Sorteados:");
							imprimeCartela(quick,TamMax);
							quickSort(quick,1,TamMax - 1);
							puts("comparacoes realizadas igual ao somatorio das comparacoes");
							imprimeCartela(quick,TamMax);
							break;
						case(2):
							puts("Sorteados:");
							imprimeCartela(select,TamMax);
							SelectSort(select,TamMax);
							compSelect(TamMax-1);
							imprimeCartela(select,TamMax);
							break;
						case(3):
							puts("Sorteados:");
							imprimeCartela(shellUm,TamMax);
							shell_sort_um(shellUm, TamMax);
							imprimeCartela(shellUm,TamMax);
							break;
						case(4):
							puts("Sorteados:");
							imprimeCartela(shellDois,TamMax);
							shell_sort_dois(shellDois,TamMax);
							imprimeCartela(shellDois,TamMax);
							break;
						case(5):
							puts("Sorteados:");
							imprimeCartela(shellTres,TamMax);
							shell_sort_tres(shellTres,TamMax);
							imprimeCartela(shellTres,TamMax);
							break;
						case(0):
							break;
					}
				}
				break;
			case(0):
				break;
		}
	}
	puts("================================= SAIU  MENU =================================");
}

void compSelect(int tam){
	int r = ((tam * tam)-tam)  / 2;
	printf("Ordem de  %d comparacoes \n", r);
	printf("(tam^² - tam) / 2 \n");
}

// void compQuick(int tam){
// 	double n = log2((double)tam);
// 	int r = (tam * n)/2;
// 	printf("Ordem de  %d comparacoes \n", r);
// 	printf("(nN * logN) / 2 \n");
// }

int pesSeq(int vetor[],int valor){
	// puts("================================= ENTROU PES-SEQ =================================");
	int posi;
	vetor[0] = valor;
	posi = TamMax;
	while(vetor[posi] != valor){
		posi--;
	}
	// puts("================================= SAIU  PES-SEQ =================================");
	return (posi);
}

int pesBin(int vetor[], int valor, int *x){
	// puts("================================= ENTROU PES-BIN =================================");
	int meio,esq,dir;
	*x = 0;
	esq = 1;
	dir = TamMax;
	do{
		meio = (esq + dir)/2;
		if(valor > vetor[meio])
			esq = meio + 1;
		else
			dir = meio - 1;
	*x = *x + 1;
	}while(valor != vetor[meio] && esq <= dir);
	if(valor == vetor[meio]){	
		// puts("================================= SAIU PES-BIN =================================");
		return (meio);
	}
	else{
		// puts("================================= SAIU PES-BIN =================================");
		return 0;
	}
}

// funcao para troca do valor de dois elementos 
void troca(int* a, int* b){
	int aux; 
    aux = *a; 
    *a = *b; 
    *b = aux; 
} 
  
int particao (int vetor[], int esq, int dir){ 
	// puts("================================= ENTROU PARTICAO =================================");
    int pivo = vetor[dir];    // pivo 
    int i = (esq - 1);  // Index of smaller element 
    int x= 0 ;
    for (int j = esq; j <= dir- 1; j++) 
    { 
        // Se o elemento atual e menor ou  
        // igual ao pivo 
        if (vetor[j] <= pivo) 
        { 
            i++;    // incrementa o index do menor elemento 
            troca(&vetor[i], &vetor[j]); 
        } 
        x++;
    } 
    printf(" comparacoes = %d\n",x );
    troca(&vetor[i + 1], &vetor[dir]); 
	// puts("================================= SAIU PARTICAO =================================");
    return (i + 1); 
} 
  
void quickSort(int vetor[], int esq, int dir){
	// puts("================================= ENTROU QUICKSORT =================================");
    if (esq < dir) 
    { 
        int pi = particao(vetor, esq, dir);
        quickSort(vetor, esq, pi - 1); 
        quickSort(vetor, pi + 1, dir); 
    } 
	// puts("================================= ENTROU QUICKSORT =================================");
} 

void shell_sort_um(int vet[], int tam) {
    int i , j , value,x=0;
    int gap = 1;
    while(gap < tam) {
        gap = 3*gap+1;
    }
    while ( gap > 1) {
        gap /= 3;
        for(i = gap; i < tam; i++) {
            value = vet[i];
            j = i;
            while (j >= gap && value < vet[j - gap]) {
                vet[j] = vet [j - gap];
                j = j - gap;
                x++;
            }
            vet [j] = value;
        }
    }
    printf("Comparacoes shell sort = %d\n", x);
}

void shell_sort_dois(int vet[], int tam) {
    int i , j , value,x=0;
    int gap = 1;
    while(gap < tam) {
        gap = 2*gap;
    }
    while ( gap > 1) {
        gap /= 2;
        for(i = gap; i < tam; i++) {
            value = vet[i];
            j = i;
            while (j >= gap && value < vet[j - gap]) {
                vet[j] = vet [j - gap];
                j = j - gap;
                x++;
            }
            vet [j] = value;
        }
    }
    printf("Comparacoes shell sort = %d\n", x);
}
void shell_sort_tres(int vet[], int tam) {
    int i , j , value,x=0;
    int gap = 1;
    while(gap < tam) {
        gap = 3*gap+1;
    }
    while ( gap > 1) {
        gap = (gap-1) /3;
        for(i = gap; i < tam; i++) {
            value = vet[i];
            j = i;
            while (j >= gap && value < vet[j - gap]) {
                vet[j] = vet [j - gap];
                j = j - gap;
                x++;
            }
            vet [j] = value;
        }
    }
    printf("Comparacoes shell sort = %d\n", x);
}

void SelectSort (int vetor[],int max) {
	int i, j, min, aux,x=0;
	puts("================================= ENTROU SELECT SORT =================================");
  
	for (i = 1; i < (max - 1); i++) {
		min = i;
		for (j = i+1; j < max; j++) {
			if (vetor[j] < vetor[min]) {
				min = j;
				x++;
			}
		}
		if (i != min) {
			aux = vetor[i];
		vetor[i] = vetor[min];
		vetor[min] = aux;
		// x++;
		}
	}
	printf("Comparacoes = %d\n", x);
	puts("================================= SAIU SELECT SORT =================================");
}

void jogar(jogador *Jog1,jogador *Jog2, jogador *Jog3, jogador *Jog4, int vetor[]){
	puts("================================= ENTROU JOGAR =================================");
	int i,x,result,status = 0;
	jogador *ganhou;
	// valor das comparacoes = 0
	printf("%d %d %d \n",Jog1->found,Jog1->bin,Jog1->seq );
	Jog1->seq = 0;
	Jog1->bin = 0;  
	Jog1->found = 0;  
	printf("%d %d %d \n",Jog1->found,Jog1->bin,Jog1->seq );

	Jog2->seq = 0;
	Jog2->bin = 0;
	Jog2->found = 0;

	Jog3->seq = 0;
	Jog3->bin = 0;
	Jog3->found = 0;

	Jog4->seq = 0;
	Jog4->bin = 0;
	Jog4->found = 0;
	printf("zerou\n");
	// For para calcular seq do Jogador 1
	puts("Pesquisa sequencial para o jogador 1");
	puts("Cartela do jogador ");
	imprimeCartela(Jog1->cartela,CARTELA);

	for(i=1; i < CARTELA; i++){
		result = pesSeq(vetor,Jog1->cartela[i]);
		if (result != 0){
			Jog1->found = Jog1->found + 1;
			printf("Encontrou = %d\n", Jog1->found);
		}
		else
			puts("Nao encontrou");	
		Jog1->seq = Jog1->seq + (TamMax - result);
		printf("Numero de comparacoes em 1 = %d\n",Jog1->seq );
		printf("\n");
	}

	puts("----------------------------------------------------------------------------------------");

	// For para calcular seq do Jogador 2
	puts("Pesquisa sequencial para o jogador 2");
	puts("Cartela do jogador =  ");
	imprimeCartela(Jog2->cartela,CARTELA);

	for(i=1; i < CARTELA; i++){
		result = pesSeq(vetor,Jog2->cartela[i]);
		if (result != 0){
			Jog2->found = Jog2->found + 1;
			printf("Encontrou = %d\n", Jog2->found);
		}
		else
			puts("Nao encontrou");
		Jog2->seq = Jog2->seq + (TamMax - result);
		printf("Numero de comparacoes em 2 = %d\n",Jog2->seq );
		printf("\n");
	}
	puts("----------------------------------------------------------------------------------------");
	// For para calcular seq do Jogador 3
	puts("Pesquisa sequencial para o jogador 3");
	puts("Cartela do jogador =  ");
	imprimeCartela(Jog3->cartela,CARTELA);
	
	for(i=1; i < CARTELA; i++){
		result = pesSeq(vetor,Jog3->cartela[i]);
		if (result != 0){
			Jog3->found = Jog3->found + 1;
			printf("Econtrou = %d\n", Jog3->found);
		}
		else
			puts("Nao encontrou");
		Jog3->seq = Jog3->seq + (TamMax - result);
		printf("Numero de comparacoes em 3 = %d\n",Jog3->seq );
		printf("\n");
	}
	puts("----------------------------------------------------------------------------------------");
	// For para calcular seq do Jogador 4
	puts("Pesquisa sequencial para o jogador 4");
	puts("Cartela do jogador =  ");
	imprimeCartela(Jog4->cartela,CARTELA);
	
	for(i=1; i < CARTELA; i++){
		result = pesSeq(vetor,Jog4->cartela[i]);
		if (result != 0){
			Jog4->found = Jog4->found + 1;
			printf("Encontrou = %d\n", Jog4->found);
		}
		else
			puts("Nao encontrou");
		Jog4->seq = Jog4->seq + (TamMax - result);
		printf("Numero de comparacoes em 4 = %d\n",Jog4->seq );
		printf("\n");
	}

	quickSort(vetor,1,TamMax-1);
	imprimeCartela(vetor,TamMax);

	// For para calcular bin do Jogador 1
	puts("----------------------------------------------------------------------------------------");
	puts("Comparacoes Binarias em 1");
	x=0;
	for(i=1; i < CARTELA; i++){
		printf("%d\n",x );
		result = pesBin(vetor,Jog1->cartela[i],&x);
		if(result != 0)
			printf("Encontrou \n");
		else
			printf("Nao encontrou\n");
		Jog1->bin = Jog1->bin + x;
	}
	printf("Comparacoes binarias = %d \n",Jog1->bin );
	puts("----------------------------------------------------------------------------------------");
	puts("Comparacoes Binarias em 2");
	for(i=1; i < CARTELA; i++){
		result = pesBin(vetor,Jog2->cartela[i],&x);
		if(result != 0)
			printf("Encontrou \n");
		else
			printf("Nao encontrou\n");
		Jog2->bin = Jog2->bin + x;
	}

	printf("Comparacoes binarias = %d \n",Jog2->bin );
	puts("----------------------------------------------------------------------------------------");
	puts("Comparacoes Binarias em 3");
	for(i=1; i < CARTELA; i++){
		result = pesBin(vetor,Jog3->cartela[i],&x);
		if(result != 0)
			printf("Encontrou \n");
		else
			printf("Nao encontrou\n");
		Jog3->bin = Jog3->bin + x;
	}

	printf("Comparacoes binarias = %d \n",Jog3->bin );
	puts("----------------------------------------------------------------------------------------");
	puts("Comparacoes Binarias em 4");
	for(i=1; i < CARTELA; i++){
		result = pesBin(vetor,Jog4->cartela[i],&x);
		if(result != 0)
			printf("Encontrou \n");
		else
			printf("Nao encontrou\n");
		Jog4->bin = Jog4->bin + x;
	}
	printf("Comparacoes binarias = %d \n",Jog4->bin );
	puts("----------------------------------------------------------------------------------------");
	puts("================================= JOGADORES E RESULTADO =================================");
	puts("Jogador 1");
	printf("Encontrados = %d ",Jog1->found );
	if(Jog1->found != 5)
		printf(" (Nao concorre)\n");
	else
		printf("\n");
	printf("Comparacoes na pesquisa sequencial %d \n",Jog1->seq );
	printf("Comparacoes na pesquisa binaria %d \n",Jog1->bin );
	printf("\n");
	puts("Jogador 2");
	printf("Encontrados = %d ",Jog2->found );
	if(Jog2->found != 5)
		printf(" (Nao concorre)\n");
	else
		printf("\n");
	printf("Comparacoes na pesquisa sequencial %d \n",Jog2->seq );
	printf("Comparacoes na pesquisa binaria %d \n",Jog2->bin );
	printf("\n");
	puts("Jogador 3");
	printf("Encontrados = %d ",Jog3->found );
	if(Jog3->found != 5)
		printf(" (Nao concorre )\n");
	else
		printf("\n");
	printf("Comparacoes na pesquisa sequencial %d \n",Jog3->seq );
	printf("Comparacoes na pesquisa binaria %d \n",Jog3->bin );
	printf("\n");
	puts("Jogador 4");
	printf("Encontrados = %d ",Jog4->found );
	if(Jog4->found != 5)
		printf(" (Nao concorre)\n");
	else
		printf("\n");
	printf("Comparacoes na pesquisa sequencial %d \n",Jog4->seq );
	printf("Comparacoes na pesquisa binaria %d \n",Jog4->bin );
	printf("\n");
	if(Jog1->found != 5 && Jog2->found != 5 && Jog3->found != 5 && Jog4->found != 5 ){
		status = -1;
		printf("Ninguem ganhou\n");
	}
	else
	{
		if(Jog1->seq == Jog2->seq && Jog2->found == 5 && Jog1->seq == 5 )
			status = 10;
		else if(Jog1->seq == Jog3->seq && Jog3->found == 5 && Jog1->seq == 5 )
			status = 10;
		else if(Jog1->seq == Jog4->seq && Jog4->found == 5 && Jog1->seq == 5 )
			status = 10;
		else if(Jog2->seq == Jog3->seq && Jog3->found == 5 && Jog2->seq == 5 )
			status = 10;
		else if(Jog2->seq == Jog4->seq && Jog4->found == 5 && Jog2->seq == 5 )
			status = 10;
		else if(Jog3->seq == Jog4->seq && Jog4->found == 5 && Jog3->seq == 5 )
			status = 10;
		if(status == 10 )
			printf("Empate !\n");
		if(status != 10 || status != -1){
			if(Jog1->seq < Jog2->seq && Jog1->found == 5 && Jog1->seq < Jog3->seq && Jog1->seq < Jog4->seq || (Jog2->found != 5 && Jog3->found != 5 && Jog4->found != 5 && Jog1->found == 5)){
				printf("Ganhou o jogador 1 \n");
				printf("FELICITACOES ao jogador 1 \n");
				ganhou = Jog1;
			}
			else if(Jog2->seq < Jog1->seq && Jog2->seq < Jog3->seq && Jog2->seq < Jog4->seq && Jog2->found == 5 || (Jog1->found != 5 && Jog3->found != 5 && Jog4->found != 5 && Jog2->found == 5)){
				printf("Ganhou o jogador 2 \n");
				printf("FELICITACOES ao jogador 2 \n");
				ganhou = Jog2;
			}
			else if(Jog3->seq < Jog1->seq && Jog3->seq < Jog2->seq && Jog3->seq < Jog4->seq && Jog3->found == 5 || (Jog2->found != 5 && Jog1->found != 5 && Jog4->found != 5 && Jog3->found == 5)){
				printf("Ganhou o jogador 3 \n");
				printf("FELICITACOES ao jogador 3 \n");
				ganhou = Jog3;
			}
			else if(Jog4->seq < Jog1->seq && Jog4->seq < Jog3->seq && Jog4->seq < Jog2->seq && Jog4->found == 5 || (Jog2->found != 5 && Jog3->found != 5 && Jog1->found != 5 && Jog4->found == 5)){
				printf("Ganhou o jogador 4 \n");
				printf("FELICITACOES ao jogador 4 \n");
				ganhou = Jog4;
			}


		}
	}
	puts("============ SE VOCE ESCOLHER JOGAR NOVAMENTE OS RESULTADOS MUDARAO POIS\n O SEQUENCIAL SERA CALCULADO A PARTIR DO SORTEADOS JA ORDENADO =============");
	puts("================================= SAIU JOGAR =================================");
}

int main(){
	time_t t;
	srand((unsigned) time(&t));

	jogador JogUm,JogDois,JogTres,JogQuatro;

	menu(&JogUm,&JogDois,&JogTres,&JogQuatro);
}