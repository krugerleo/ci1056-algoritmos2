#ifndef HEADER_H
#define HEADER_H
#define MAX 127
#define tamMax 200

//============================================ TIPOS DA LISTA ===========================================================
typedef struct{
  char nome[MAX]; // vetor de char para nome do candidato
  int numero; // numero do candidato para votacao
  char partido[MAX]; // partido em que o candidato e filiado
  int votos;
}elemLista;

typedef struct nodoLista{
  elemLista dados; // valores do elemento da lista
  struct nodoLista *prox; // nodo para proximo elemento da lista
  struct nodoLista *ant; // nodo para elemento anterior da lista
}nodoLista;

typedef nodoLista tipoLista; // tipo lista “”typedef nao e ponteiro””


// ================================================== TIPOS DA FILA =============================================

typedef struct{
	char nome[MAX]; // vetor de char para nome do eleitor
	int voto; // numero do candidato que foi votado
	int titulo; // numero de titulo de eleitor 
}elemFila;

typedef struct tipoFila{
	elemFila vetor[tamMax];
	int frente,final,vez;
}tipoFila;

// =================================================== FUNCOES DA FILA ======================================================

int vaziaFila(tipoFila *fila);
void inicFila(tipoFila *fila);
void imprimeFila(tipoFila *fila);
void enfileiraEleitor(tipoFila *fila);
elemFila desenfileiraEleitor(tipoFila *fila);

// ====================================================== FUNCOES DA LISTA =================================================== 

int vaziaLista(tipoLista *lista);
void imprimeLista(tipoLista *lista);
void inicLista(tipoLista *lista);
int procuraCandidato(tipoLista *lista,int numero);
elemLista insereDados(tipoLista *lista);
void novoCandidato(tipoLista *lista);
elemLista removeCandidato(tipoLista *lista,int numero );

// ====================================================== TIPOS DA PILHA =================================================== 

typedef int elemPilha;

typedef struct nodoPilha{
	elemPilha titulo;
	struct nodoPilha *prox;
}nodoPilha;

typedef struct{
	nodoPilha *topo;
	int tamanho;
}tipoPilha;


// ====================================================== FUNCOES DA PILHA =================================================== 

void imprimePilha(tipoPilha *pilha);
elemPilha pop(tipoPilha *pilha);
void push(tipoPilha *pilha ,int titulo );
int tamanhoPilha(tipoPilha *pilha);
int vaziaPilha(tipoPilha *pilha);
void inicPilha(tipoPilha *pilha);


// ====================================================== FUNCAO MENU =================================================== 

void menu(tipoLista *lista, tipoFila *fila, tipoPilha *pilha);
void votar(tipoFila *fila,tipoPilha *pilha, tipoLista *lista);
void contabiliza(tipoLista *lista,tipoPilha *pilha);

#endif

