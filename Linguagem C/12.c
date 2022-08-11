#include <stdio.h>
#include <stdlib.h>

struct Tfabricante { //Struct do fabricante

int mat;
char marca[30];
};

struct Tmodelo { // Struct do Modelo do veiculos

int mat;
int ano;
char nome[30];
char cor[30];
char fichaTecnica[1000];
float valor;
};

void listaVeiculo(char s[12]);
void cadastrarVeiculo(char s[12]);


void menuVeiculo(char s[12]) {

int menu;
printf("-------------- MENU ---------------\n\n");
printf("1 - Cadastro de veiculos\n");
printf("2 - lista de veiculos\n");
printf("3 - Consultar veiculos\n");
printf("4 - Alterar veiculo\n");
printf("5 - Excluir veiculo\n");
printf("6 - Cadastro de fabricante\n");
printf("2 - lista de veiculos\n");
printf("3 - Consultar veiculos\n");
printf("4 - Alterar veiculo\n");
printf("5 - Excluir veiculo\n");
printf("0 - Voltar ao menu\n");
printf("\nDigite um numero:\n");
scanf("%d", &menu);
system("cls");
switch(menu){
case 1 :
cadastrarVeiculo(s);
break ;
case 2:
listaVeiculo(s);
break ;

case 3:
consultarVeiculo(s);
break ;
case 4:
printf("alterarVeiculo;");
break ;
case 5:
printf("excluirVeiculo;");
break ;
}
}

void cadastrarVeiculo(char s[12]) { // Cadastro da marca e modelo

FILE * p;
struct Tfabricante f;
struct Tmodelo d;
int con;

p = fopen(s, "ab+");



printf("---------------- Cadastro de Veiculos ------------------\n\n");

    do {

        getchar();

        printf("Marca do fabricante: "); // Marca do Veiculo
        fflush(stdin);
        fgets(f.marca, sizeof(f.marca), stdin);
       
        fwrite(&f, sizeof(f), 1, p);
       
        printf("Modelo: "); // Modelo do veiculo
        fflush(stdin);
        fgets(d.nome, sizeof(d.nome), stdin);
       
        printf("Cor: "); // Cor do veiculo
        fflush(stdin);
        fgets(d.cor, sizeof(d.cor), stdin);
       
        printf("Ficha tecnica: "); // Ficha técnica
        fflush(stdin);
        fgets(d.fichaTecnica, sizeof(d.fichaTecnica), stdin);
       
        printf("Ano: "); // Ano do veiculo
        scanf("%d", &d.ano);
       
        printf("Valor: "); // Valor do veiculo
        scanf("%f", &d.valor);
       
        fwrite(&d, sizeof(d), 1, p);
       
        printf("\n\nDeseja inserir um novo cadastro?\n 1 - Sim\n 0 - Nao e voltar ao menu\n\n");
        scanf("%d", &con);
       
        system("cls");
       
    } while (con==1);

fclose(p);
menuVeiculo(s);
}

void listaVeiculo(char s[12]) {

FILE * p;
struct Tfabricante f;
struct Tmodelo d;
p = fopen(s, "rb");
printf("----------------- Lista de Cadastro ----------------------\n\n");

if(p == NULL) printf("Nenhum veiculo cadastrado\n\n");
else {
while(fread(&f, sizeof(f), 1, p)) {

        printf("Marca: ...........%s", f.marca);
           
        fread(&d, sizeof(d), 1, p);

        printf("Modelo: ..........%s", d.nome);
        printf("Cor: .............%s", d.cor);
        printf("Ficha tecnica: ...%s", d.fichaTecnica);
        printf("Ano: .............%d\n", d.ano);
        printf("Valor: ...........%.2f\n", d.valor);

        printf("\n\n");
    }
fclose(p);
}
printf("Aperte enter para retornar ao menu:");
system("pause");
system("cls");
menuVeiculo(s);
}

int consultarVeiculo(char s[12]){
FILE *p;
char procurado[30];
printf("Digite a marca que deseja procurar: \n");
fflush(stdin);
scanf("%s", &procurado);

p=fopen (s,"rb");

struct Tfabricante f;
struct Tmodelo d;
fpos_t byte;
int tam=sizeof(f);
printf("qtd byes da estrtura %d",tam);

do{
	fread(&f,sizeof(f),1,p);
	fread(&d, sizeof(d), 1, p);
	
	printf("\n laco %s=",f.marca);
	getch();
	if(strcmp(procurado,f.marca)==0){
		byte = ftell(p) - tam;		
		fclose(p);		
	    return(byte);}	
}while(eof(p));

printf("%d",byte);

return (-1);
} 


void main() {


char nomeArqV[20] = "veiculo.dat";
char nomeArqF[20] = "fabricante.dat";
menuVeiculo(nomeArqV);
menuVeiculo(nomeArqF);

}
