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
		printf("\n[%d] -> ", pL->info);
		pL = pL->next;
	}
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

	return 0;
}
