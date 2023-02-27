#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>


typedef struct no(){
	int dado;
	struct no *prox;
	
}tno;

typedef tno * tpilha;

void criarPilha(tpilha *pp){
	*pp = NULL;
}

bool push(tpilha *pp, int valor){
	tpilha novo = (tno *)malloc(sizeof(tno));
	novo->dado = valor;
	novo->prox = *pp;
	*pp = novo;
	return true;
}

int main(int argc, char *argv[]) {	
	tpilha p;
	criarPilha(&p);
	//tno *p;
	//struct no *p;
	
	if(push(&p,1))
		printf("Inserido o valor na pilha\n");
	else
		printf("\n ERRO!");
		
	if(push(&p,2))
		printf("Inserido o valor na pilha\n");
	else
		printf("\n ERRO!");
	
	
	
	
	return 0;
}
