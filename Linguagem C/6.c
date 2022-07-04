#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

/* 3. Escreva um procedimento que recebes 3 valores reais X, Y e Z e que verifique se esses valores podem ser os comprimentos dos lados de um tri�ngulo e, 
neste caso, retornar qual o tipo de tri�ngulo formado. Para que X, Y e Z formem um tri�ngulo � necess�rio que a seguinte propriedade seja satisfeita: 
o comprimento de cada lado de um tri�ngulo � menor do que a soma do comprimento dos outros dois lados. 
O procedimento deve identificar o tipo de tri�ngulo formado observando as seguintes defini��es:

        Tri�ngulo Equil�tero: os comprimentos dos 3 lados s�o iguais.
        Tri�ngulo Is�sceles: os comprimentos de 2 lados s�o iguais.
        Tri�ngulo Escaleno: os comprimentos dos 3 lados s�o diferentes. */
    
void triangulo (int a, int b, int c){
	
	
        
        if(a == b && a == c)
            printf("Equilatero\n");
        else
            if(a == b || a == c || b == c)
                printf("Isosceles\n");
            else
                printf("Escaleno\n");
    
    
}


int main() {
	setlocale(LC_ALL, "");
	
    int a, b, c;

    printf("Digite o primeiro ponto do tri�ngulo: ");
    scanf("%d", &a);
    
    printf("Digite o segundo ponto do tri�ngulo: ");
    scanf("%d", &b);
    
    printf("Digite o terceiro ponto do tri�ngulo: ");
    scanf("%d", &c);

    triangulo(a, b, c);
    
    

	return 0;
}
