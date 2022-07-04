#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

/* 3. Escreva um procedimento que recebes 3 valores reais X, Y e Z e que verifique se esses valores podem ser os comprimentos dos lados de um triângulo e, 
neste caso, retornar qual o tipo de triângulo formado. Para que X, Y e Z formem um triângulo é necessário que a seguinte propriedade seja satisfeita: 
o comprimento de cada lado de um triângulo é menor do que a soma do comprimento dos outros dois lados. 
O procedimento deve identificar o tipo de triângulo formado observando as seguintes definições:

        Triângulo Equilátero: os comprimentos dos 3 lados são iguais.
        Triângulo Isósceles: os comprimentos de 2 lados são iguais.
        Triângulo Escaleno: os comprimentos dos 3 lados são diferentes. */
    
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

    printf("Digite o primeiro ponto do triângulo: ");
    scanf("%d", &a);
    
    printf("Digite o segundo ponto do triângulo: ");
    scanf("%d", &b);
    
    printf("Digite o terceiro ponto do triângulo: ");
    scanf("%d", &c);

    triangulo(a, b, c);
    
    

	return 0;
}
