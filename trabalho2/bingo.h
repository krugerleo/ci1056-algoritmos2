#ifndef BINGO_H
#define BINGO_H
#define CARTELA 6

typedef struct jogador{
	int cartela[CARTELA];
	int bin;
	int seq;
	int found;
}jogador;

void imprimeCartela(int cartela[],int tam);

void geraSorteados(int sort[]);

int buscaNum(int vetor[6],int num);

void escolheNumero(jogador *jogador);

void geraNumero(jogador *jogador2,jogador *jogador3,jogador *jogador4);

void menu(jogador *JogUm,jogador *JogDois,jogador *JogTres,jogador *JogQuatro);

void jogar(jogador *Jog1,jogador *Jog2, jogador *Jog3, jogador *Jog4, int vetor[]);

int pesSeq(int vetor[],int valor);

int pesBin(int vetor[], int valor, int *x);

void troca(int* a, int* b);

int particao (int vetor[], int esq, int dir);

void quickSort(int vetor[], int esq, int dir);

void ShellSortUm(int vetor[], int n);

void copiaVetor(int vet[], int cpy[]);

void SelectSort (int vetor[],int max);

void compSelect(int tam);

// void compQuick();

void shell_sort_um(int vet[], int tam);

void shell_sort_dois(int vet[], int tam);

void shell_sort_tres(int vet[], int tam);

#endif