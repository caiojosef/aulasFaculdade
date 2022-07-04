#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <locale.h>

/* 1. Crie um programa que, utilizando fun��es, valide os modelos de placas de carro adotado no Brasil.
Existem atualmente em circula��o 2 modelos de placa.
    1. Padr�o antigo: Composto por 3 letras e 4 numeros (AAA-1234);
    2. Padr�o atual: Composto por 3 letras, 2 numeros, 1 letra e 1 numero (AAA-12B3).
O programa deve ler um conjunto de caracteres do teclado e validar se a placa est� no padr�o antigo, no padr�o atual ou fora de padr�o. */

void mostrar_placa(){
	char placa[7];
	int i=0;
	int controle = 0;
	
	
	printf("Digite a placa do ve�culo: ");
	scanf("%s", &placa);
	
	for(i=0; i < 3; i++){
		placa[i] = toupper(placa[i]);
	}
	
	for(i=0; i < 3; i++){
		if(isdigit(placa[i]) == 1){
			printf("Os 3 primeiros digitos s�o letras, voc� inseriu n�meros!");
			controle = 1;
			break;
		}
			
	}
		
		if(controle == 0){
			
			for(i=4; i < 7; i++){
		placa[i] = toupper(placa[i]);
		}
	
			for(i=4; i<=7; i++){
				if(isdigit  (placa[i]) == 1){
					printf("Placa do Mercosul.");
					break;
				
				}
			
				if(isdigit (placa[i]) == 0){
				printf("Placa antiga.");
				break;
				}
			}
		
		// N�o consegui fazer ele entrar em somente 1 :/
		
	}
		
	
}

int main() {
	setlocale(LC_ALL, "");
	mostrar_placa();
	return 0;
}
