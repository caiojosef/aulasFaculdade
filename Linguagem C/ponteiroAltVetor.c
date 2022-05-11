#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

/* passando o novo valor a ser alterado, a posição em que ele deve entrar e o vetor de inteiros, a função deve retornar 1 se a alteração for um sucesso
ou 0 se falhou. A função também deve retornar o vetor com o valor alterado e impresso no main */

int alteraValor(int novoValor, int posicao, int vetor[]){
	int i;
	for(i = 0; i < 10; i++){
		if(posicao == vetor[i]){
			
			vetor[i] = novoValor;
			return 1;
		}
	}
	return 0;
}

int main(int argc, char *argv[]) {
	setlocale(LC_ALL, "");
	int *ptr;
	int num;
	int pos;
	int i; 
	int vet[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	
	printf("Digite o o novo valor: ");
	fflush(stdin);
	scanf("%d", &num);
	printf("\nDigite a posição: ");
	fflush(stdin);
	scanf("%d", &pos);
	
	ptr = &vet;
	
	alteraValor(num, pos, ptr);
	
	for(i = 0; i < 10; i++){
		printf("\nPosição = %d / valor = [%d]", i+1, ptr[i]);	
	}
	
	
	return 0;
}
