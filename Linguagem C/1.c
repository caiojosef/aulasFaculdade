#include <stdio.h>
#include <stdlib.h>

/* Implemente um programa que crie 3 vari�veis inteiras, atribua valores
para as mesmas. Crie 3 ponteiros (um para cada vari�vel). Atribua
valores para os ponteiros e mostre o comportamento das vari�veis e
dos ponteiros com as altera��es. */

int main(int argc, char *argv[]) {
	int a = 15, b = 35, c = 95;
	int *temp, *p, *q, *s;
	 
	p = &a;
	q = &b;
	s = &c;
	printf("\n \n%d %d %d", *p, *q, *s);
	
	return 0;
}
