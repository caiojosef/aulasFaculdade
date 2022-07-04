#include <stdio.h>
#include <stdlib.h>

/*  Implemente um programa que contenha um vetor com 10 números, posteriormente crie um ponteiro para este vetor e percorra com um laço de repetição este vetor incrementando e mostrando pelo ponteiro. */

int main(int argc, char *argv[]) {
	int vetor[10] = {20, 30, 40, 50, 60, 70, 80, 90, 100, 110};
	int i, *ponteiro;
	
	ponteiro = vetor;
	
	
	for(i = 0; i < 10; i++){
		printf("Vetor[%d] = %d /  ponteiro = [%d]\n", i, vetor[i], *ponteiro++);
	}
	
	return 0;
}
