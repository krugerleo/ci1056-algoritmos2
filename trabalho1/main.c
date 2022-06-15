#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 127
#define tamMax 200
#include "header.h"

int main(){
	int i;
	tipoFila eleitores;
	tipoLista *candidatos;
	tipoPilha *comprovantes;
	comprovantes = (tipoPilha*)malloc(sizeof(tipoPilha));
	candidatos = (tipoLista*)malloc(sizeof(tipoLista));
	candidatos->dados.numero = 0; // nenhum candidato pode ter o numero zero 
	inicPilha(comprovantes);
	inicLista(candidatos);
	inicFila(&eleitores);
	printf("verificacao da lista (endereço lista) %p \n", &candidatos);
	printf("verificacao da lista (valor listsa) %p \n\n", candidatos);
	vaziaLista(candidatos);
	menu(candidatos, &eleitores, comprovantes);
	return 0;
}

// =================================================== FUNCOES DA PILHA ====================================================== 
void inicPilha(tipoPilha *pilha){
	puts("================================= ENTROU INIC PILHA ============================");
	pilha->topo = (nodoPilha*)malloc(sizeof(nodoPilha));
	pilha->tamanho = 0;
	pilha->topo->prox = NULL;
	puts("================================= SAIU INIC PILHA ============================\n");
}

int vaziaPilha(tipoPilha *pilha){
	return(pilha->tamanho == 0);
}

int tamanhoPilha(tipoPilha *pilha){
	return(pilha->tamanho);
}

void push(tipoPilha *pilha ,int titulo ){
	puts("================================= ENTROU PUSH ============================");
	nodoPilha *aux;
	aux = (nodoPilha*)malloc(sizeof(nodoPilha));
	aux->prox = pilha->topo;
	pilha->topo->titulo = titulo;
	pilha->topo = aux;
	pilha->tamanho++;
	puts("================================= SAIU PUSH ============================\n");
}

elemPilha pop(tipoPilha *pilha){
	puts("================================= ENTROU POP ============================");
	if(vaziaPilha(pilha))
		puts("Impossivel remover elemento pilha vazia");
	else{
		nodoPilha *aux;

		aux = pilha->topo;
		pilha->topo = pilha->topo->prox;
		free(aux);
		pilha->tamanho--;
		puts("================================= SAIU POP ============================\n");
		return(pilha->topo->titulo);
	}
}

void imprimePilha(tipoPilha *pilha){
	puts("================================= ENTROU IMPRIME PILHA ============================");
	if (vaziaPilha(pilha))
		puts("Impossivel imprimir a pilha esta vazia.");
	else{
		nodoPilha *aux;
		aux = pilha->topo->prox;
		while(aux != NULL){
			printf("Comprovante com o titulo = %d\n",aux->titulo );
			aux = aux->prox;
		}
		printf("\n");
	}
	puts("================================= SAIU IMPRIME PILHA ============================\n");	
}

// =================================================== FUNCOES DA FILA ======================================================

int vaziaFila(tipoFila *fila){
	return(fila->frente == fila->final);
}

void inicFila(tipoFila *fila){
	puts("================================= ENTROU INIC FILA ============================");
	fila->frente = 0;
	printf("frente da fila inicializada em %d\n", fila->frente );
	fila->final = 0;
	printf("final da fila inicializada em %d\n", fila->final );
	fila->vez = 0;
	printf("vez da fila inicializada em %d\n", fila->vez );
	if(vaziaFila(fila)) // verificacao de inicializacao
		puts("---- VERIFICACAO INICIA FILA VAZIA : TRUE----");
	puts("================================= SAIU  INIC FILA =============================\n");
}


void imprimeFila(tipoFila *fila){
	puts("================================= ENTROU IMPRIME FILA =============================");
	if(vaziaFila(fila))
		puts("Impossivel executar a oprecao, a fila esta vazia !");
	else{
		int aux;
		puts("Dados dos eleitores na fila: ");
		aux = fila->frente;
		while(aux != fila->final){
			printf("Lugar na fila : %d\n",aux );
			printf("Nome : %s", fila->vetor[aux].nome);
			printf("Titulo : %d\n", fila->vetor[aux].titulo);
			if(fila->vetor[aux].voto == 0 )
				puts("Eleitor ainda nao votou");
			else
			printf("Voto : %s\n", fila->vetor[aux].nome);
			aux = (aux + 1) % tamMax;
		}
	}
	puts("================================= SAIU IMPRIME FILA =============================\n");
}

void enfileiraEleitor(tipoFila *fila){
	puts("================================= ENTROU ENFILEIRA =============================");
	if ((fila->final + 1) % tamMax == fila->frente)
		puts("Impossivel executar a oprecao, a fila esta cheia !");
	else{
		puts("Insira os dados do eleitor");
		printf("Nome = ");
		fgets(fila->vetor[fila->final].nome,MAX,stdin);
		printf("Voce digitou : %s\n", fila->vetor[fila->final].nome);
		printf("Numero do titulo de eleitor ="); // numero a ser utilizado para verificacao no comprovante
		scanf("%d", &fila->vetor[fila->final].titulo);
		getchar();
		fila->vetor[fila->final].voto = 0; // nenhum candidato possui esse numero, voto inexistente
		printf("Voce digitou : %d\n",fila->vetor[fila->final].titulo );
		fila->final = (fila->final + 1) % tamMax;
		printf(" Fila Final = %d\n",fila->final );
	}
	puts("================================= SAIU ENFILEIRA =============================\n");
}

elemFila desenfileiraEleitor(tipoFila *fila){
	puts("================================= ENTROU DSENFILEIRA =============================");	
	elemFila salva;
	if(vaziaFila(fila))
		puts("Impossivel executar a oprecao, a fila esta vazia !");
	else{
		salva = fila->vetor[fila->frente];
		fila->frente = (fila->frente + 1) % tamMax; 
		puts("================================= SAIU DESENFILEIRA =============================\n");
		return salva;
	}
}


// ====================================================== FUNCOES DA LISTA =================================================== 
int vaziaLista(tipoLista *lista){
	return(lista->prox == lista); // retorna se a lista esta vazia
}

void imprimeLista(tipoLista *lista){
	nodoLista *aux;
	int cont = 1; // cont inicializa em 1, pois se comeca a imprimir pelo primeiro candidato
	puts("================================= ENTROU IMPRIME LISTA =================================");
	// Entro na funcao imprimeLista
	if (vaziaLista(lista)) // verifica se a lista esta vazia
		printf("Impossivel imprimir os cadidatos, a lista esta vazia\n");
	else{
		aux = lista->prox;
		while(aux != lista){
			printf("Candidato %d:\n", cont); // contabilizacao para quantidade de candidatos
			printf("Nome do candidato: %s",aux->dados.nome); // imprime o nome do candidato em questao
			printf("Partido do candidato: %s",aux->dados.partido); // imprime o partido do candidato em questao
			printf("Numero do candidato: %d\n", aux->dados.numero); // imprime o numero do candidato em questao
			aux = aux->prox; // aux recebe o prox candidato ou a lista se for o ultimo elemento
			cont++;	
		}
	}
	puts("================================= SAIU IMPRIME LISTA =================================\n");
	// Saiu da funcao imprimeLista
} 	



void inicLista(tipoLista *lista){
	puts("================================= ENTROU INICIA LISTA ==============================");
	// Entrou na funcao inicLista
	puts("Inicia lista duplamente encadeada");
	lista->prox = (nodoLista*)malloc(sizeof(nodoLista)); // aloca espaço
	lista->prox = lista; // proximo aponta para a lista
	lista->ant = (nodoLista*)malloc(sizeof(nodoLista)); // aloca espaço
	lista->ant = lista; //  anterior aponta para a lista
	if(vaziaLista(lista)) // verificacao de inicializacao
		puts("---- VERIFICACAO INICIA LISTA VAZIA : TRUE----");
	puts("================================= SAIU INICIA LISTA =================================\n");
	// Saiu da funcao inicLista
}

int procuraCandidato(tipoLista *lista,int numero){
  nodoLista *aux;
  puts("================================= ENTROU PROCURA CANDIDATO =================================");
  if(vaziaLista(lista)){
    puts("================================= SAIU PROCURA CANDIDATO VAZIO =================================\n");
    return(0);
  }
  else{
    aux = lista->prox;
    while (aux != lista){
	    if(aux->dados.numero == numero){
		    puts("================================= SAIU PROCURA CANDIDATO (encontrou) =================================\n");
		    return(1);
	    }
	    aux=aux->prox;
    }
  }
  puts("================================= SAIU PROCURA CANDIDATO (nao encontrou) =================================\n");
  return(0);
}

int adicionaVoto(tipoLista *lista,int numero){
  nodoLista *aux;
  puts("================================= ENTROU ADICIONA VOTO =================================");
  if(vaziaLista(lista)){
    puts("Lista vazia! impossivel adicionar voto\n");
    return (0);
  }
  else{
    aux = lista->prox;
    while (aux != lista){
	    if(aux->dados.numero == numero){
	    	aux->dados.votos++;
		    printf("contabilizou mais um voto para : %s \n Quantidade de votos = %d \n",aux->dados.nome, aux->dados.votos);
		    return(1);
	    }
	    aux=aux->prox;
    }
  }
  puts("================================= SAIU PROCURA CANDIDATO (nao encontrou) =================================\n");
  return(0);
}


	
elemLista insereDados(tipoLista *lista){
	int a;	
	elemLista dados;
	puts ("================================= ENTROU INSERE DADOS =================================");
 	puts("Dados para o novo candidato \n");
 	puts("Insira o nome do candidato: ");
 	printf("Nome = ");
	fgets(dados.nome,MAX,stdin);
	printf("voce digitou %s\n",dados.nome );
	puts("Insira o nome do partido: ");
	printf("Partido = " );
	fgets(dados.partido,MAX,stdin);
	printf("voce digitou %s\n",dados.partido );
	puts("Insira o numero do candidato: ");
	printf("Numero = ");
	scanf("%d",&dados.numero);
	getchar();
	printf("voce digitou %d\n",dados.numero );
	while(procuraCandidato(lista,dados.numero)){
		a = procuraCandidato(lista,dados.numero);
		printf("%d\n", a );
		printf("Esse numero ja possui um candidato cadastrado, por favor insira outro.\n");
		printf("Numero = ");
		scanf("%d",&dados.numero);
		getchar();
	}
	dados.votos=0;
	puts("================================= SAIU INSERE DADOS =================================\n");
	return dados;

}

void novoCandidato(tipoLista *lista){
	printf("================================= ENTROU NOVO CANDIDATO ================================= \n");
	nodoLista *aux;
	// alocando e inserindo na lista
	aux = lista->ant; 
	aux->prox = (nodoLista*)malloc(sizeof(nodoLista));
	aux = aux->prox;
	aux->ant = lista->ant;
	lista->ant = aux;
	aux->prox = lista;
	aux->dados = insereDados(lista); // Depois de alocado chama a funcao para inserir os dados
	// Abaixo verificacao dos valores inseridos em dadods
	printf("\n");
	printf("Dados cadastrados do candidato:\n" );
	printf("nome :%s",aux->dados.nome );
	printf("partido :%s", aux->dados.partido);
	printf("numero :%d\n", aux->dados.numero);
	puts("================================= SAIU NOVO CANDIDATO =================================\n");
	// fim da inserção 


}

elemLista removeCandidato(tipoLista *lista,int numero ){
  nodoLista *aux;
  elemLista dados;
  puts("================================= ENTRA REMOVE CANDIDATO =================================");
  // Entra na funcao removeCandidato
  if(vaziaLista(lista)){ // verifica se a lista esta vazia
    puts("Impossivel executar a tarefa");
  }
  else{
    aux = lista->prox; // aux vai para o primeiro elemento da lista
    while ( aux != lista) {
      	if(aux->dados.numero == numero){ // se encontrar o candidato com o numero para ser removido
	        aux->ant->prox = aux->prox; // anterior ao elemento aponta paro o proximo
	        aux->prox->ant = aux->ant; // anterior do proximo elemento aponta para o anterio
	        dados = aux->dados; // passa os dados para retornar 
	        free(aux); // libera o espaco que era utilizado na memoria
	        return(dados); // retorna os dados
	  		puts("================================= SAI REMOVE CANDIDATO =================================\n");
      		// Sai da funcao removeCandidato
      	}
      	aux = aux->prox; // Se ainda nao encontrou o candidato que corresponde continuar a percorrer a lista
    }
  }
  dados.numero = 0; // bota dados como 0 para nao imprimir os valores do candidato removido 
  printf("Nenhum candidato com o numero %d foi encontrado \n", numero ); // Printa se nao foi encontrado nenhum candidato com o numero correspondente
  puts("================================= SAI REMOVE CANDIDATO =================================\n");
  // Sai da funcao se nenhum candidato foi encontrado para ser removido
  return(dados);
}

// ===================================================== FUNCOES MISTAS =======================================================


void votar(tipoFila *fila,tipoPilha *pilha, tipoLista *lista){
	puts("================================= ENTROU VOTAR =============================");	
	int voto;
	printf("final %d\n", fila->final );
	if(vaziaFila(fila) ||  vaziaLista(lista))
		puts("Impossivel executar a oprecao de votar");
	else if( fila->vez == fila->final )
		puts("todos eleitores da fila ja tiveram seu voto registrado");
	else{
		printf("Voce iria registrar o voto de %s que e o %d na fila \n",fila->vetor[fila->vez].nome, fila->vez );
		printf("Voto = ");
		scanf("%d",&voto);
		getchar();
		while(!procuraCandidato(lista,voto)){ // Verifica se e um voto valido
			puts("Voto invalido ! nenhum candidato possui esse nuemro.");
			printf("Voto = ");
			scanf("%d",&voto);
			getchar();
		}
		fila->vetor[fila->vez].voto = voto;
		push(pilha,fila->vetor[fila->vez].titulo); // registra comprovante de voto
		adicionaVoto(lista,fila->vetor[fila->vez].voto); // contabiliza o voto para o candidato
			fila->vez = (fila->vez + 1) % tamMax;
		puts("================================= SAIU VOTAR =============================\n");
	}
}


void contabiliza(tipoLista *lista,tipoPilha *pilha){
	nodoLista *aux;
	nodoLista *salva;
	int contV = 0;
	int cont = 0;
	puts("================================= ENTROU CONTABILIZA =================================");
	// Entro na funcao imprimeLista
	if (vaziaLista(lista)) // verifica se a lista esta vazia
		printf("Impossivel imprimir os cadidatos, a lista esta vazia\n");
	else{
		aux = lista->prox;
		salva = lista->prox;
		while(aux != lista){
			printf("Candidato %d:\n", cont); // contabilizacao para quantidade de candidatos
			printf("Nome do candidato: %s",aux->dados.nome); // imprime o nome do candidato em questao
			printf("Numero de votos: %d\n",aux->dados.votos );
			contV = contV + aux->dados.votos;
			if(aux->dados.votos > salva->dados.votos)
				salva = aux;
			aux = aux->prox; // aux recebe o prox candidato ou a lista se for o ultimo elemento
			cont++;	
			printf("\n");
		}
		if(contV == pilha->tamanho){
			printf("E o vencedor da eleicao e : %s com %d Votos \n",salva->dados.nome, salva->dados.votos );
			printf("Quantidade de votos: %d e Quantidade de comprovante: %d \n",contV, pilha->tamanho );
		}
		else{
			puts("Falha na votacao, numero de votos diferente do numero de comprovante");
			printf("Votos = %d <> Comprovante = %d \n",contV, pilha->tamanho );
		}
	}
	puts("================================= SAIU CONTABILIZA =================================\n");
	// Saiu da funcao imprimeLista
}


void menu(tipoLista *lista, tipoFila *fila, tipoPilha *pilha){
	// inicia o menu para utilizar as funcoes 
	int j,i = 'a',num;
	elemLista candidato;
	elemFila eleitor;
	elemPilha comprovante;
	// elemFila eleitor;
	puts("================================= ENTROU NO MENU =================================");
	while(i != 0){

		printf("1 - Candidatos\n");
		printf("2 - Fila de eleitores\n");
		printf("3 - Comprovantes de voto\n");
		printf("4 - Votar\n");
		printf("5 - Contabilizar votacao\n" );
		printf("0 - Sair\n");
		do{
			printf("Entrada: ");
			scanf("%d",&i);
			getchar(); // recebe o \n que pode vir a interferir nas outras entradas
			printf("\n");
		}while(i != 1 && i != 2 && i != 3 && i != 0 && i != 4 && i != 5); // fica em loop caso receba algum parametro invalido de opcao

		switch(i){
			case (1):
				printf("1 - Mostrar candidatos\n");
				printf("2 - Inserir candidato \n");
				printf("3 - Remover candidato\n");
				do{
					printf("Entrada: ");
					scanf("%d",&j);
					getchar(); // recebe o \n que pode vir a interferir nas outras entradas
					printf("\n");
				}while( j != 1 && j != 2 && j != 3); // fica em loop caso receba algum parametro invalido de opcao
				switch(j){
					case (1):
						imprimeLista(lista);
						break;
					case (2):
						novoCandidato(lista);
						break;
				 	case (3):
				 		if(vaziaLista(lista))
				 			puts("Impossivel remover um candidato, a lista esta vazia.\n");
				 		else{
					 		printf("Digite o numero do candidato a ser removido: \n");
					 		printf("Entrada: " );
					 		scanf("%d",&num); // recebe o numero do candidato a ser removido
					 		getchar(); // recebe o \n que pode vir a interferir nas outras entradas
							candidato = removeCandidato(lista,num); // candidato recebe os dados do candidato removido.
				 			if(num == candidato.numero){
				 				puts("Dados do candidato removido:");
				 				printf("Nome = %s\n", candidato.nome );
				 				printf("Partido = %s\n", candidato.partido );
				 				printf("Numero = %d\n", candidato.numero );
				 			}
				 		}
						break;
				}
				break;
			case (2):
				printf("1 - Mostrar fila\n");
				printf("2 - Inserir eleitor \n");
				printf("3 -  Remover eleitor\n");
				printf("Entrada: ");
				scanf("%d",&j);
				getchar(); // recebe o \n que pode vir a interferir nas outras entradas
				printf("\n");
				switch(j){
					case (1):
						imprimeFila(fila);
						break;
					case (2):
						enfileiraEleitor(fila); // Tem q dar um jeito de recolher o eleitor 	
						break;
					case (3):
						if(vaziaFila(fila))
							puts("Impossivel remover a fila esta vazia !");
						else{
							puts("Eleitor da frente removido !");
							eleitor = desenfileiraEleitor(fila); 
						}
						break;
					}
				break;
			case (3):
				printf("1 - Mostrar comprovantes\n");
				printf("2 -  Remover comprovante\n");
				scanf("%d",&j);
				getchar(); // recebe o \n que pode vir a interferir nas outras entradas
				printf("\n");
				switch(j){
					case (1):
						imprimePilha(pilha);
						break;
					case (2):
						comprovante = pop(pilha); 
						break;
				break;
				}
			case(4):
				votar(fila,pilha,lista);
				break;
			
			case(5):
				contabiliza(lista,pilha);
				break;
		}		
	}
	puts("========================== SAIU DO MENU ========================\n");
}

