#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	
	
	/*printf("%d\n", sizeof(char *));
	printf("%lu\n", sizeof(int *));
	printf("%lu\n", sizeof(double *));
	
	system("PAUSE");
	return 0;
	
	int exemplo;
	//o formatador %p � utilizado para mostrar endere�os de mem�ria
	printf("%p\n", &exemplo);
	system("PAUSE");
	return 0;*/
	
	int exemplo; // Uma vari�vel do tipo ponteiro
	int* ponteiro; //Um ponteiro para uma vari�vel do tipo inteiro
	
	printf("Endereco de 'exemplo': %p\n", &exemplo);
	printf("Endereco de 'ponteiro': %p\n", &ponteiro);
	system("PAUSE");
}
