#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <locale.h>


/* 2. Faça uma função que recebe por parâmetro o raio de uma esfera e calcula o seu volume (v = 4/3.P . R³). */

void raio(){
	float raio = 0, v = 0;
	      
	
    printf("Digite o valor do RAIO: ");
    scanf("%f",&raio);   
	  
    v = 4/3 * (3.14*pow(raio,3));      
    printf("\nO volume da esfera é: %.4f\n\n", v);  
}

int main(int argc, char *argv[]) {
	setlocale(LC_ALL, "");
	raio();
	return 0;
}
