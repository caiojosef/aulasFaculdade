#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#define tamVet 1
#include <windows.h>

/* 
1.       O sistema deve possuir um menu para
a escolha das opções. Sempre que uma opção for escolhida, o sistema deve limpar
a tela antes de exibir a nova tela escolhida.


2.       O sistema deve ser capaz de
cadastrar, alterar e excluir clientes


3.       O sistema deve ser capaz de
cadastrar, alterar e excluir produtos


4.       O sistema deve ser capaz de
cadastrar, alterar e excluir pedidos


5.       O sistema não deve permitir a
exclusão dos clientes com pedidos associados


6.       O Sistema deve apresentar uma lista
que permita selecionar o cliente e o sistema retornar a lista de produtos pedidos
do cliente


7.       O sistema não deve permitir
cadastrar dois clientes repetidos na lista de clientes


8.       O sistema deve gerenciar o estoque,
não permitindo fazer pedidos de produtos sem estoque


9.       O sistema deve exibir o relatório do
total de vendas/faturamento
*/

struct produto{
	int id;
	char produto[30];
};

struct cliente{
	char nomeCliente[30];
	int id;
	
};

struct pedido{
	int id;
    char pedido[50];
    float preco;
    int quantidadePedido;
};

struct cliente Cliente[tamVet];
struct produto Produto[tamVet];
struct pedido Pedido[tamVet];
void cabecalhoCliente();
void cabecalhoPedidos();
void cabecalhoProdutos();
void cabecalho();
void inputProduto(int indice);
void inputCliente(int ind);
void inputPedido(int indicePedidos);
void mostrarCliente(struct cliente Cliente);
void mostrarProduto(struct produto Produto);
void mostrarPedido(struct pedido Pedido);
int findCliente(int limCliente, int findIdc);
int findProd(int limProd, int findId);
int findPedido(int limPedido, int findIdp);

int main(int argc, char *argv[]) {
	int opc, limCliente = 0, limProd = 0, qtd = 0, i = 0, opcCliente, posicVetc = 0, findIdc = 0, findId = 0, posicVet = 0, posicVetp = 0, findIdp = 0, limPedido = 0;
	
	
	setlocale(LC_ALL, "Portuguese");
	
	do{
		cabecalho();
		printf("Digite a sessão que gostaria de entrar \n");
		printf("1 - Cliente \n");
		printf("2 - Produtos \n");
		printf("3 - Pedidos \n");
		printf("0 - Sair\n");
		printf("Digite a opção desejada: ");
		fflush(stdin);
		scanf("%d", &opc);
		
		switch(opc){
			case 1:
				do{
					cabecalhoCliente();
					printf("1 - Cadastrar Cliente \n");
					printf("2 - Alterar Cliente \n");
					printf("3 - Excluir Cliente \n");
					printf("4 - Listar os Clientes \n");
					printf("0 - Retornar ao Menu Anterior\n");
					printf("Digite a opção: ");
					scanf("%d", &opcCliente);
					
					
					switch(opcCliente){
						case 1:
							cabecalhoCliente();
							printf("Quantos clientes deseja inserir?\n");
            				fflush(stdin);
            				scanf("%d", &qtd);
            				
            				for(i = 1; i <= qtd; i++){
            					limCliente++;
            					printf("Insira o ID do Cliente: ");
                    			inputCliente(limCliente);
                    			
                    			printf("\nCliente Cadastrado!\n");
							}
							break;
							
						case 2:
							cabecalhoCliente();
							system("cls");
            				posicVetc = 0;
            				printf("\nDigite o ID do cliente que você deseja ALTERAR: ");
            				scanf("%d", &findIdc);
            				
            				if(findCliente(limCliente, findIdc) >= 0){
            					printf("Digite o novo ID do cliente: ");
                				inputCliente(findCliente(limCliente, findIdc));
                				printf("\nCliente ALTERADO com sucesso!\n");
           					}else{
                    			printf("\nO Cliente com esse ID não foi encontrado!");
            				}
            				system("pause");
                		break; 
                		case 3:
                			cabecalhoCliente();
                			printf("\nDigite o ID do Cliente que voce deseja EXCLUIR: ");
                			scanf("%d", &findIdc);
                			
                			if(findCliente(limCliente, findIdc) >= 0){
                				Cliente[findCliente(limCliente, findIdc)] = Cliente[limCliente];
                    			limCliente--;
                    			printf("\nCliente EXCLUIDO com sucesso!\n");
                			} else {
                    			printf("\nO Cliente com esse ID nao foi encontrado!\n");
                			}
                			system("pause");
                		break;

						case 4:
							cabecalhoCliente();
							for(i = 1;i <= qtd;i++){
                        		mostrarCliente(Cliente[i]);
                    		}
                    		printf("\n");
                    		system("pause");
                    		break;
							default:
								break;
					}

				}while(opcCliente != 0);
				
			
				break;
				//parte de produtos
			case 2:
				do{
					cabecalhoProdutos();
					printf("1 - Cadastrar Produto \n");
					printf("2 - Alterar Produto \n");
					printf("3 - Excluir Produto \n");
					printf("4 - Listar os Produtos \n");
					printf("0 - Retornar ao Menu Anterior\n");
					printf("Digite a opção: ");
					scanf("%d", &opcCliente);
					
					
					switch(opcCliente){
						case 1:
							cabecalhoProdutos();
							printf("Quantos produtos deseja inserir?\n");
            				fflush(stdin);
            				scanf("%d", &qtd);
            				
            				for(i = 1; i <= qtd; i++){
            					printf("Insira o ID do Produto:");
                    			inputProduto(limProd);
                    			
                    			printf("Produto Cadastrado!\n");
                    			limProd++;
							}
							break;
							
						case 2:
							cabecalhoProdutos();
							posicVet = 0;
            				printf("\nDigite o ID do produto que você deseja ALTERAR: ");
            				scanf("%d", &findId);
            				if(findProd(limProd, findId) >= 0){
                				printf("\nDigite o novo ID do PRODUTO: ");
                				inputProduto(findProd(limProd, findId));
                				printf("\nProduto ALTERADO com sucesso!\n");
            				}else{
                    			printf("\nO produto com esse ID não foi encontrado!");
            				}
							break;
						case 3:
							cabecalhoProdutos();
							printf("\nDigite o ID do produto que voce deseja EXCLUIR: ");
                			scanf("%d", &findId);
               				if(findProd(limProd, findId) >= 0){
                				Produto[findProd(limProd, findId)] = Produto[limProd];
                    			limProd--;
                    			printf("\nProduto EXCLUIDO com sucesso!\n");
                			}else {
                    			printf("\nO produto com esse ID nao foi encontrado!\n");
                			}
                			system("pause");
                		break;                
							
						case 4:
							cabecalhoProdutos();
							for(i = 0;i < qtd;i++){
                        		mostrarProduto(Produto[i]);
                    		}
                    		printf("\n");
                    		system("pause");
                    		break;
                    		
							default:
								break;
					}

				}while(opcCliente != 0);
				
				break;
				case 3:
					//parte de pedidos
					do{
					cabecalhoProdutos();
					printf("1 - Cadastrar Pedidos \n");
					printf("2 - Alterar Pedido \n");
					printf("3 - Excluir Pedido \n");
					printf("4 - Listar os Produtos \n");
					printf("0 - Retornar ao Menu Anterior\n");
					printf("Digite a opção: ");
					scanf("%d", &opcCliente);
					
					
					switch(opcCliente){
						case 1:
							cabecalhoPedidos();
							printf("Quantos pedidos deseja cadastrar?\n");
            				fflush(stdin);
            				scanf("%d", &qtd);
            				
            				for(i = 1; i <= qtd; i++){
            					printf("Insira o ID do produto:");
                    			inputPedido(limPedido);
                    			
                    			printf("Pedido Cadastrado!\n");
                    			limPedido++;
							}
							break;
							
						case 2:
							cabecalhoPedidos();
							posicVetp = 0;
            				printf("\nDigite o ID do pedido que você deseja ALTERAR: ");
            				scanf("%d", &findIdp);
            				if(findPedido(limPedido, findIdp) >= 0){
                				printf("\nAgora Digite as novas informações do novo pedido: ");
                				inputPedido(findPedido(limPedido, findIdp));
                				printf("\nPedido ALTERADO com sucesso!\n");
            				}else{
                    			printf("\nO Pedido com esse ID não foi encontrado!");
            				}
            				system("pause");
                		break;   
						
						case 3:
							cabecalhoPedidos();
							printf("\nDigite o ID do Pedido que voce deseja EXCLUIR: ");
                			scanf("%d", &findIdp);
                			if(findPedido(limPedido, findIdp) >= 0){
                				Pedido[findPedido(limPedido, findIdp)] = Pedido[limPedido];
                    			limPedido--;
                    			printf("\nPedido EXCLUIDO com sucesso!\n");
                			}else{
                    			printf("\nO Pedido com esse ID nao foi encontrado!\n");
                			}
                break;          
            
							

						case 4:
							cabecalhoPedidos();
							for(i = 0;i < qtd;i++){
                        		mostrarPedido(Pedido[i]);
                    		}
                    		printf("\n");
                    		system("pause");
                    		break;
							default:
								break;
					}

				}while(opcCliente != 0);
				
				break;
			default:
				printf("Não possui esse número na tabela!");
				break;
		}
		
	}while(opc != 0);
	return 0;
}
void cabecalhoProdutos(){
	system("cls");
	printf("---------------------------------------------\n");
	printf("              ABA DE PRODUTOS\n");
	printf("---------------------------------------------\n\n");
}

void cabecalhoPedidos(){
	system("cls");
	printf("---------------------------------------------\n");
	printf("              ABA DE PEDIDOS\n");
	printf("---------------------------------------------\n\n");
}

void cabecalhoCliente(){
	system("cls");
	printf("---------------------------------------------\n");
	printf("              ABA DE CLIENTES\n");
	printf("---------------------------------------------\n\n");
}
void cabecalho(){
	Sleep(1000);
	system("cls");
	printf("---------------------------------------------\n");
	printf("                   MENU\n");
	printf("---------------------------------------------\n\n");
}


int findCliente(int limCliente, int findIdc){
    int j = 0;
    int findc = 0;
    int posicVetc = 0;
    for(j = 0;j <= limCliente;j++)
	{
        if(findIdc == Cliente[j].id)
		{
            findc = 1;
            posicVetc = j;
            break;
    	}
    }
    if(findc == 1)
	{
        return posicVetc;
    } else if(findc == 0)
			{
        		return -1;
    		}
}

int findProd(int limProd, int findId){
    int i = 0;
    int find = 0;
    int posicVet = 0;
    for(i = 0;i <= limProd;i++)
	{
        if(findId == Produto[i].id)
		{
            find = 1;
            posicVet = i;
            break;
    	}
    }
    if(find == 1)
	{
        return posicVet;
    } else if(find == 0)
			{
        		return -1;
    		}
}

int findPedido(int limPedido, int findIdp){
    int k = 0;
    int findp = 0;
    int posicVetp = 0;
    for(k = 0;k <= limPedido;k++)
	{
        if(findIdp == Pedido[k].id)
		{
            findp = 1;
            posicVetp = k;
            break;
    	}
    }
    if(findp == 1)
	{
        return posicVetp;
    } else if(findp == 0)
			{
        		return -1;
    		}
}
				
void inputPedido(int indicePedidos){
		fflush(stdin);
		scanf("%d", &Pedido[indicePedidos].id);
		printf("\nDigite o pedido: ");
		fflush(stdin);
		scanf("%s", &Pedido[indicePedidos].pedido);
		printf("\nDigite o valor do pedido: ");
		fflush(stdin);
		scanf("%f", &Pedido[indicePedidos].preco);
		printf("\nDigite a quantidade do Pedido: ");
		fflush(stdin);
		scanf("%d", &Pedido[indicePedidos].quantidadePedido);
		
				
}

void inputCliente(int ind){
		fflush(stdin);
		scanf("%d", &Cliente[ind].id);
		printf("\nAgora digite o nome do Cliente: ");
		fflush(stdin);
		scanf("%s", &Cliente[ind].nomeCliente);
				
}
void inputProduto(int indice){
		fflush(stdin);
		scanf("%d", &Produto[indice].id);
		printf("\nDigite o nome do produto: ");
		scanf("%s", &Produto[indice].produto);
		
}

void inputPedidos(int ind){
	int indp;
	printf("ID: ");
    fflush(stdin);
    scanf("%d", &Pedido[indp].id);
    
    printf("Nome: ");
    fflush(stdin);
    scanf("%s", &Pedido[indp].pedido);

    printf("Valor: ");
    fflush(stdin);
    scanf("%f", &Pedido[indp].preco);

    printf("Quantidade: ");
    fflush(stdin);
    scanf("%d", &Pedido[indp].quantidadePedido);
				
}

void mostrarCliente(struct cliente Cliente){ 
	printf("ID do Cliente: %d \n", Cliente.id);
    printf("Nome do Cliente: %s \n", Cliente.nomeCliente);
    
}
    
void mostrarProduto(struct produto Produto){ 
    printf("ID do Produto: %d \n", Produto.id);
    printf("\nNOME do Produto: %s \n", Produto.produto);
}

void mostrarPedido(struct pedido Pedido){ 
    printf("ID do Produto: %d \n", Pedido.id);
    printf("\nNome do Pedido: %s \n", Pedido.pedido);
    printf("\nValor do Pedido: %.2f \n", Pedido.preco);
    printf("\nQuantidade: %d \n", Pedido.quantidadePedido);
}
