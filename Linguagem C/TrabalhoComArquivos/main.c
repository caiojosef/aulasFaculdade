#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

/* Nome: Caio Josef / C�digo: 04721-023
   Nome: Jefferson Henrique / C�digo: 04721-053
   Nome: Antonio Filomeno / C�digo: 04719-300 */
   
struct biblioteca{
	int id;
	char nomeDoLivro[30];
	char descricao[30];
};

typedef struct biblioteca BIBLIOTECA;
void inputData();
void listar();


int main(int argc, char *argv[]) {
	int opc;
	
	setlocale(LC_ALL, "Portuguese");
	
	do{
		printf("1 - Inserir dados \n");
		printf("2 - Mostrar dados \n");
		printf("0 - Sair\n");
		printf("Digite a op��o desejada: ");
		fflush(stdin);
		scanf("%d", &opc);
		
		switch(opc){
			case 1:
				inputData();
				break;
			case 2:
				listar();
				break;
			default:
				break;
		}
		
	}while(opc != 0);
	return 0;
}

void inputData(){
	FILE *arquivo;
	arquivo = fopen("arquivo.txt", "a");
	BIBLIOTECA ctt;
	
	if(arquivo == NULL){
		printf("\nArquivo n�o existente.");
	}else{
		do{
			printf("Digite o ID do livro: ");
			fflush(stdin);
			scanf("%d", &ctt.id);
			
			printf("Digite o nome do livro: ");
			fflush(stdin);
			gets(ctt.nomeDoLivro);
			
			printf("Digite a descri��o do livro: ");
			fflush(stdin);
			gets(ctt.descricao);
			
			fwrite(&ctt, sizeof(BIBLIOTECA), 1, arquivo);
			printf("Deseja Continuar? (s/n)");
			
			
		}while(getche() == 's');
		
		fclose(arquivo);
	}
}

void listar(){
	FILE *arquivo;
	arquivo = fopen("arquivo.txt", "r");
	BIBLIOTECA ctt;
	
	if(arquivo == NULL){
		printf("\nArquivo n�o existente.");
	}else{
		while(fread(&ctt, sizeof(BIBLIOTECA), 1, arquivo) == 1){
			printf("\nID: %d\n", ctt.id);
			printf("NOME: %s\n", ctt.nomeDoLivro);
			printf("DESCRI��O: %s\n", ctt.descricao);
		}
	}
	fclose(arquivo);
	getch();
}
