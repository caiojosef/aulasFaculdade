#include <stdio.h>
#include <stdlib.h>

/* Implemente um programa que crie 3 variáveis e faça uma função que altera os valores das mesmas, ex:
    a->b
      b->c
      c->a */

void trocar(int *p, int *q, int *s){
	int temp;
	
	temp = *p;
	*p = *q;
	*q = *s;
	*s = temp;
	
}

int main(int argc, char *argv[]) {
	
	int a = 15, b = 20, c = 35;
	int *temp, *p, *q, *s;
	
	p = &a;
	q = &b;
	s = &c;
	printf("\n \n%d %d %d", *p, *q, *s);
	trocar(p, q, s);
	printf("\n \n%d %d %d", *p, *q, *s);
	return 0;
}
