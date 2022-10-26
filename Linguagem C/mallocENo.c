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
int main(int argc, char *argv[]) {
	
	Lista *L;
	
	L = inicializaLista();
	L = inserir(L, 1000);
	L = inserir(L, 100);
	L = inserir(L, 10);
	L = inserir(L, 1);
	return 0;
}
