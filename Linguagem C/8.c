#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>

/* 5. Faça uma função que receba, por parâmetro, uma matriz A(12,12) e retorne a média aritmética dos elementos abaixo da diagonal principal. */
void diag_principal(int matriz[12][12]){
	int media=0;
	int i, j=0;
	int soma = 0;
	for( i = 1; i < 12; i++ ){
        soma += matriz[i][j];
        j++;
	}
	printf("\n");
	media = soma / 11;
	printf("A soma da diagonal principal é: %d\n", soma);
	printf("A media é: %d\n", media);
}

int main() {
	setlocale(LC_ALL,"");
	int i, j, mat[12][12];
	
	srand(100);
	
    for(i=0; i<12; i++){
    	for(j=0; j<12; j++){
    		mat[i][j] = rand() % 50;
		}
	} 
	
	for(i=0; i<12; i++){
    	for(j=0; j<12; j++){
    		printf(" %2d ", mat[i][j]);
    		
		}
		printf("\n");
	}
	diag_principal(mat);
	return 0;
}
