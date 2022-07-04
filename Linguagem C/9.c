#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>

/* 6. Faça uma função que receba, por parâmetro, uma matriz A(12,12) e retorna o produto dos elementos acima da diagonal principal e 
da diagonal secundária.
 Utilize uma função diferente para cada retorno. */

void diag_principal(int matriz[12][12]){
	int i, j=1;
	
	printf("\nOs valores em cima da diagonal principal são: ");
	for( i = 0; i < 11; i++ ){
                printf(" %d ", matriz[i][j]);
                j++;
	}
}

void diagonal_secundaria(int matriz[12][12]){	
	int i, j=10;
	
	printf("\nOs valores em cima da diagonal principal são: ");
	for( i = 0; i < 11; i++ ){
			printf(" %d ", matriz[i][j]);
			j--;     
        }	 
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
	diagonal_secundaria(mat);
	return 0;
}
