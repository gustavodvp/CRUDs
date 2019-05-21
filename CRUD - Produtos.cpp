#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <locale.h>
#define TAM 10

int menu();


struct tProduto{
	int codigo;
	char descricao[30];
	float valor;
};

int main (void){
	setlocale(LC_ALL,"portuguese");
	struct tProduto produtos[TAM];
	int cod, l, opcao, i, quantidade=0;
	
	do{		
		opcao=menu();
		
		
		switch(opcao){
			case 1:
				printf("*** INCLUSÃO ***\n\n");
				if(quantidade<TAM){
					
					printf("Digite o codigo do produto que deseja incluir:\n");
					scanf("%d", &produtos[quantidade].codigo);
					printf("Digite a descrição do produto:\n");
					fflush(stdin);
					gets(produtos[quantidade].descricao);
					printf("Digite o valor do produto em R$:\n");
					scanf("%f", &produtos[quantidade].valor);					
					quantidade++;
					fflush(stdin);
				} else {
					printf("Não há mais espaço.\n");
				} 
				
			
				break;
				
			case 2:
				printf("*** LISTAGEM ***\n");
				printf("COD - DESCRICAO - VALOR\n");
				for(i=0; i<quantidade; i++)
					printf("%d - %s - %.2f\n", produtos[i].codigo, produtos[i].descricao, produtos[i].valor);
					break;
				
			case 3:
				
				printf("*** CONSULTAR ****\n");
				printf("Digite o codigo do produto que deseja consultar:\n");
				scanf("%d", &cod);
				for(i=0; i<quantidade; i++){
					if(cod==produtos[i].codigo){
						printf("\nCodigo: %d\n", produtos[i].codigo);
						printf("Descrição: %s\n", produtos[i].descricao);
						printf("Valor: %.2f\n", produtos[i].valor);
						
					} else {
						printf("Não existe esse produto!\n");
					}
				}
				break;
		}		
	} while (opcao!=0);
	
	
	return 0;
}

int menu(){
	int opcao;
	do{
		printf("------------------------\n");
		printf("CRUD PRODUTOS \n");
		printf("1. Incluir\n");
		printf("2. Listar \n");
		printf("3. Consultar \n");
		printf("0. Sair\n");
		printf("------------------------\n");	
		printf("\n\nDigite sua opção:\n");	
	
		scanf("%d", &opcao);
	} while (opcao!=1 && opcao != 2 && opcao != 3 && opcao!=0);

	return opcao;
}


