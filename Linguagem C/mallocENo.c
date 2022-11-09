#include <stdio.h>
#include <stdlib.h>

struct lista{
	int info;
	struct lista *next;
};
typedef struct lista Lista;

Lista * inicializaLista(){
	return NULL;
}

Lista * inserir(Lista *pL, int elemento){
	Lista * novo = (Lista *) malloc(sizeof(Lista));
	if(novo != NULL){
		novo -> info = elemento;
		novo -> next = pL;
		printf("Novo -> Info: [%d] ", novo->info);
		return novo;
	}
}

void imprime(Lista * pL){
	while(pL != NULL){
		printf("[%d] -> ", pL->info);
		pL = pL->next;
	}
}

Lista * buscar(Lista * pL, int valor){
	while(pL != NULL){
		if(pL->info == valor)
			return pL;

		pL = pL -> next;
	}
}

Lista *remover(Lista * pL, int valor){
	Lista * anterior = NULL;
	Lista * aux = pL;
	
	while(pL != NULL && pL->info != valor){
		anterior = pL;
		pL = pL->next;
	}
	if(anterior == NULL) // remover o primeiro nó da lista
		aux = aux->next;
	else{
		if(anterior -> next == NULL) // o dado não existe na lista
			return aux;
		else
			anterior-> next = pL->next; // está no meio da lista ou no final
	}
	
	free(pL);	
	return aux;
}

int main(int argc, char *argv[]) {
	
	Lista *L;
	
	L = inicializaLista();
	L = inserir(L, 1000);
	L = inserir(L, 100);
	L = inserir(L, 10);
	L = inserir(L, 1);
	printf("\n Imprimindo a Lista! \n");
	imprime(L);
	printf("\n Buscar o valor na lista! \n");
	int valor;
	scanf("%d", &valor);
	Lista * getEnd = buscar(L, valor);
	if(getEnd != NULL)
		printf("\n Valor %d existe na lista e está na posicao: %p \n", getEnd->info, getEnd);
		
	L = remover(L, 1);
	printf("\n Imprimindo a Lista! \n");
	imprime(L);	
	
	//criar uma função para inserir dados no final da lista.
	//Criar uma função para encontrar um valor na lista e dividir a lista em 2.

	return 0;
}
