#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>

/* Fa�a uma fun��o que recebe, por par�metro, uma matriz A(6,6) e 
retorna a soma dos elementos da sua diagonal principal e da sua diagonal secund�ria. Utilize uma fun��o diferente para cada retorno. */
void diagonal_secundaria(int matriz[6][6]){	
	int i, j=5;
	int soma = 0;
	for( i = 0; i < 6; i++ ){
		
			soma += matriz[i][j];
			j--;     
        }
        
	
	printf("A soma da diagonal secund�ria �: %d\n", soma);
	 
}

void diag_principal(int matriz[6][6]){
	
	int i, j;
	int soma = 0;
	for( i = 0; i < 6; i++ ){
        for( j = 0; j < 6; j++ ){
            if( i==j ){
                soma += matriz[i][j];
            }
            
        }
        
	}
	printf("A soma da diagonal principal �: %d\n", soma);
}

int main() {
	setlocale(LC_ALL,"");
	int i, j, mat[6][6];
	
	srand(150);
	
    for(i=0; i<6; i++){
    	for(j=0; j<6; j++){
    		mat[i][j] = rand() % 50;
		}
	} 
	
	for(i=0; i<6; i++){
    	for(j=0; j<6; j++){
    		printf(" %2d ", mat[i][j]);
    		
		}
		printf("\n");
	}

	diag_principal(mat);
	diagonal_secundaria(mat);
	return 0;
}
