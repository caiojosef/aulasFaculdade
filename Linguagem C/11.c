#include <stdio.h>
#include <stdlib.h>
#include <locale.h>


void triangulo(){
	int a, b, c;
	printf("Digite tres valores: ");
    scanf("%d%d%d", &a, &b, &c);
if(a == b && a == c)
        printf("Equilatero\n");
else
            if(a == b || a == c || b == c)
                printf("Isosceles\n");
            else
                printf("Escaleno\n");	
}

int main() {
	
	triangulo();
	setlocale(LC_ALL, "");
	return 0;
}
