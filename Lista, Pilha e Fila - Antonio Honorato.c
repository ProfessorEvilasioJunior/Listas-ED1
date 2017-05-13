#include <stdio.h>
#include <stdlib.h>
#define MAX 10

// Todas as quest�es da lista est�o em um s� c�digo! E eu j� fiz os testes na main!
// Ant�nio Honorato - UECE - ED1
// ----------------------------
// Todos os m�todos para Lista ( Quest�o 1 e 2)
// ----------------------------

struct cliente{
	char nome[30];
	int cpf;
};

typedef struct cliente Cliente;

struct lista{
	int tamanho;
	Cliente listaDeClientes[MAX];
};

typedef struct lista Lista;

// M�todos auxiliares de verifica��o da lista
int tamanho_cheia(Lista* list){
	if(list == NULL){
		return -1;
	} 
	
	else{
		return (list->tamanho == MAX);
	}
}


int tamanho_vazia(Lista* list){
	if(list == NULL){
		return -1;
	} 
	
	else{
		return (list->tamanho == 0);
	}
}

void imprime_list(Lista* list){
	int i;
	
	for(i=0; i<list->tamanho; i++){
		printf("Lista: cliente %d: %s\n", (i+1), list->listaDeClientes[i].nome);
	}
}

						//M�todos da Lista

//M�todo: Criar Lista (Item a)
Lista* criarlistavazia(){
	Lista *list;
	list = (Lista*) malloc(sizeof(struct lista));
	
	if (list != NULL){
		list->tamanho=0;
	}
	
	return list;
}


// M�todos inserir no come�o, meio e fim. (Item b)
int inserirComecoLista(Lista* list , Cliente clt){
	//Verifica��o
	if(list == NULL){
		return 0;
	}
	
	if(tamanho_cheia(list)){
		return 0;
	}
	
	int i;
	
	for (i=list->tamanho-1; i>=0; i--){
		list->listaDeClientes[i+1] = list->listaDeClientes[i];
		}
		
		list->listaDeClientes[0] = clt;
		list->tamanho++;
		return 1;
}


int inserirMeioLista(Lista* list , struct cliente clt, int posicao){
	//Verifica��o
	if(list == NULL){
		return 0;
	}
	
	if(tamanho_cheia(list)){
		return 0;
	}
	
		int i;
	
	for (i=list->tamanho-1; i>=posicao ; i--){
		list->listaDeClientes[i+1] = list->listaDeClientes[i];
	}
		list->listaDeClientes[posicao] = clt;
		list->tamanho++;
		return 1;
	
}

int inserirFinalLista(Lista* list , struct cliente clt){
	//Verifica��o 
	if(list == NULL){
		return 0;
	}
	
	if(tamanho_cheia(list)){
		return 0;
	}
	
	list->listaDeClientes[list->tamanho] = clt;
	list->tamanho++;
	
	return 1;
}


// M�todo remover ((Item c)

int removedalista(Lista* list , int posicao){
	if(list == NULL){
		return 0;
	}
	
	if(tamanho_vazia(list)){
		return 0;
	}
	
	int i=posicao;
	int cpf = list->listaDeClientes[posicao].cpf;
	
	for(i=posicao; i<(list->tamanho-1); i++){
		list->listaDeClientes[i] = list->listaDeClientes[i+1];
	}
	
	list->tamanho--;
	return cpf;
}

// M�todo buscar ((Item d)
int buscaElemento(Lista* list , Cliente clt){
	if(list == NULL){
		return 0;
	}
	
	if(tamanho_vazia(list)){
		return 0;
	}
	
	int i = 0;
	for(i=0; i<list->tamanho-1;i++){
		if(clt.cpf == list->listaDeClientes[i].cpf){
			return i;
		}
		
		else{
			return;
		}
		
	}
}

//M�todo: Deletar Lista (Item e)
void deletarLista(Lista* list){
	free(list);
}


// ----------------------------
// Todos os m�todos para Pilha (Quest�o 3)
// ----------------------------

struct pilha{
	int tamanho;
	Cliente pilhaDeClientes[MAX];
};

typedef struct pilha Pilha;


// M�todos auxiliares de verifica��o da pilha
int pilha_tamanho_cheia(Pilha* pilh){
	if(pilh == NULL){
		return -1;
	} 
	
	else{
		return (pilh->tamanho == MAX);
	}
}


int pilha_tamanho_vazia(Pilha* pilh){
	if(pilh == NULL){
		return -1;
	} 
	
	else{
		return (pilh->tamanho == 0);
	}
}


void imprime_pilha(Pilha* pil){
	int i;
	for(i=0; i<pil->tamanho; i++){
		printf("Pilha: cliente %d: %s\n", (i+1), pil->pilhaDeClientes[i].nome);
	}
}


						//M�todos da Pilha

//M�todo: Criar Pilha (Item a)
Pilha* criarPilhaVazia(){
	Pilha *pilh;
	pilh = (Pilha*) malloc(sizeof(struct pilha));
	
	if (pilh != NULL){
		pilh->tamanho=0;
	}
	
	return pilh;
}


// M�todos inserir na pilha (Item b)
int inserirPilha(Pilha* pilh , struct cliente clt){
	//Verifica��o
	if(pilh == NULL){
		return 0;
	}
	
	if(pilha_tamanho_cheia(pilh)){
		return 0;
	}
	
	pilh->pilhaDeClientes[pilh->tamanho] = clt;
	pilh->tamanho++;
	return 1;
	
	}


// M�todo remover ((Item c)

int removedapilha(Pilha* pilh){
	if(pilh == NULL){
		return 0;
	}
	
	if(pilha_tamanho_vazia(pilh)){
		return 0;
	}
	
	int Cpf = pilh->pilhaDeClientes[pilh->tamanho-1].cpf;
	pilh->tamanho--;
	return Cpf;
	
}


//M�todo: Deletar Pilha (Item d)
void deletarPilha(Pilha* pilh){
	free(pilh);
}


// ----------------------------
// Todos os m�todos para Fila ( Quest�o 4)
// ----------------------------

struct fila{
	int tamanho;
	int inicio;
	int final;
	Cliente FilaDeClientes[MAX];
};

typedef struct fila Fila;


// M�todos auxiliares de verifica��o da fila
int fila_tamanho_cheia(Fila* fil){
	if(fil == NULL){
		return -1;
	} 
	
	else{
		return (fil->tamanho == MAX);
	}
}


int fila_tamanho_vazia(Fila* fil){
	if(fil == NULL){
		return -1;
	} 
	
	else{
		return (fil->tamanho == 0);
	}
}


void imprime_Fila(Fila* fil){
	int i;
	for(i=0; i<fil->tamanho; i++){
		printf("Fila: cliente %d: %s\n", (i+1), fil->FilaDeClientes[i].nome);
	}
}



						//M�todos da fila

//M�todo: Criar fila (Item a)
Fila* criarfilaVazia(){
	Fila *fil;
	fil = (Fila*) malloc(sizeof(struct fila));
	
	if (fil != NULL){
		fil->inicio=0;
		fil->final=0;
		fil->tamanho=0;
	}
	
	return fil;
}


// M�todos inserir na fila (Item b)
int inserirfila(Fila *fil , struct cliente clt){
	//M�todos de Verifica��o
	if(fil == NULL){
		return 0;
	}
	
	if(fila_tamanho_cheia(fil)){
		return 0;
	}
	
	fil->FilaDeClientes[fil->tamanho] = clt;
	fil->final = (fil->final+1) % MAX;
	(fil->tamanho)++;
	return 1;
	
}



// M�todo remover ((Item c)

int removedafila(Fila *fil){
	if(fil == NULL){
		return 0;
	}
	
	if(fila_tamanho_vazia(fil)){
		return 0;
	}
	
	int Cpf = fil->FilaDeClientes[0].cpf;
	fil->inicio = (fil->inicio+1) % MAX;
	(fil->tamanho)--;
	return Cpf;
	
}


//M�todo: Deletar fila (Item d)
void deletarfila(Fila *fil){
	free(fil);
}


int main(){
	
	// Clientes criados para teste
	Cliente Beth 	= {"Beth", 001};
	Cliente Vanessa = {"Vanessa", 002};
	Cliente Larissa = {"Larissa", 003};
	Cliente Leticia = {"Leticia", 004};
	Cliente Beatriz = {"Beatriz", 005};
	
	printf("----------------Lista----------------\n");
	//Teste dos m�todos da 2 quest�o (Lista)	
	// Criando Lista 
	Lista* lta;
	lta = criarlistavazia();
		
	//Inserir
	inserirComecoLista(lta,Beth);
	inserirFinalLista(lta,Beatriz);
	inserirMeioLista(lta, Vanessa, 2);
 	imprime_list(lta);
	printf("\n");
	
	//Remover
	removedalista(lta, 2);
	imprime_list(lta);
	printf("\n");
		
	//Buscar
	int aux = buscaElemento(lta, Beatriz);
	printf("Esta na lista? = %d \n", aux);
	printf("\n");
	
	//Deletar
	deletarLista(lta);
	printf("\n");
	
	
	printf("----------------Pilha---------------- \n");	
	//Teste dos m�todos da 3 quest�o (Pilha)
	// Criando pilha 
	Pilha* plh;
	plh = criarPilhaVazia();
	
	// Inserir Elemento na pilha
	inserirPilha(plh, Beth);
	inserirPilha(plh, Beatriz);
	inserirPilha(plh, Vanessa);
	imprime_pilha(plh);
	printf("\n");
	
	// Remover
	removedapilha(plh);
	imprime_pilha(plh);
	printf("\n");
	
	// Deletar
	deletarPilha(plh);
	printf("\n");

	
		printf("----------------Fila---------------- \n");	
	//Teste dos m�todos da 4 quest�o (Fila)
	// Criando Fila
	Fila* fla;
	fla = criarfilaVazia();
	
	// Inserindo elementos na fila
	inserirfila(fla, Beth);
	inserirfila(fla, Beatriz);
	inserirfila(fla, Vanessa);
	imprime_Fila(fla);
	printf("\n");
	
	// Remover elementos da fila
	removedafila(fla);	
	imprime_Fila(fla);
	printf("\n");
	
	// Deletar Fila
	deletarfila(fla);

	
	system("pause");
	return 0;
}
