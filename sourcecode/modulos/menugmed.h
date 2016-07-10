#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../strutctsandconstants.h"
#include "../mainfunctions/functionsforprofessionals.h"
#include "../functionsforinterfaces.h"

/*int main(int argc, char* argv[]) {*/
int startGmed(int* mod) {
 	int ativo = 1;
	int opcao = 1;
	listafunc matriz;
	funcionario elemento;
	int posicao;
	
	while(opcao != 0) {
		switch(opcao) {
		 	case -1:
		  		ativo = 0;
		  		opcao = 0;
		  		break;
		  
			case 1:
				opcao = showMenu("textforinterfaces/menugmed.txt");
				break;
				
			case 2:
				inicializarFunc(&matriz);
				system("clear");
				printf("\n\n\t|                     Lista inicializada!                     |");
				opcao = 1;
				getchar();
				break;
	
			case 3:
				system("clear");
				if(vaziaFunc(&matriz)) {
					printf("\n\n\t|                         Lista vazia!                        |");
				} else {
					printf("\n\n\t|                   A lista nao esta vazia!                   |");
				}
				opcao = 1;
				getchar();
				break;
				
			case 4:
				system("clear");
				if(cheiaFunc(&matriz)) {
					printf("\n\n\t|                         Lista cheia!                        |");
				} else {
					printf("\n\n\t|                   A lista nao esta cheia!                   |");
				}
					opcao = 1;
				getchar();
				break;
				
			case 5:
				system("clear");
				printf("\n\n\t|                         Tamanho = %d                        |", tamanhoFunc(&matriz));
				opcao = 1;
				getchar();
				break;
				
			case 6:
				system("clear");
				printf("\n\n\t|     Selecione a posicao do elemento para carregar: ");
				scanf("%d", &posicao);
				getchar();
				if(carregarFunc(&matriz, posicao, &elemento)) {
					printf("\n\n\t|                  O elemento carregado e: %s.                |", elemento.nome);
				} else {
					printf("\n\n\t|                     Posicao invalida!                       |");
					printf("\n\t|   A lista esta vazia ou nao entrou com valores de 1 a 50.   |");
					printf("\n\t|    Confira o tamanho da lista antes de tentar esta opcao!   |");
				}
				opcao = 1;
				getchar();
				break;
				
			case 7:
				system("clear");
				printf("\n\n\t|     Informe o elemento que sera inserido no fim da lista: ");
				fgets(elemento.cpf, 12, stdin);
				clearBuffer();
				//getchar();
				if(inserirFimFunc(&matriz, elemento)) {
					printf("\n\n\t|                     Elemento inserido!                      |");
				} else {
					printf("\n\n\t|                        Lista cheia!                         |");
				}
				opcao = 1;
				getchar();
				break;
				
			case 8:
				system("clear");
				printf("\n\n\t|     Informe o elemento a ser inserido: ");
				fgets(elemento.cpf, 12, stdin);
				clearBuffer();
				//getchar();
				printf("\t|     Informe a posicao em que o elemento sera inserido: ");
				scanf("%d", &posicao);
				getchar();
				if(posicao == 1 && tamanhoFunc(&matriz) == 0) {
					inserirFimFunc(&matriz, elemento);
					printf("\n\n\t|                     Elemento inserido!                      |");
				} else {
					if(inserirPosicaoFunc(&matriz, elemento, posicao)) {
						printf("\n\n\t|                     Elemento inserido!                      |");
					} else {
						printf("\n\n\n\n\n\n\t|  Lista cheia ou nao esta sendo incrementada sequecialmente! |");
						printf("\n\t|    Confira o tamanho da lista antes de tentar esta opcao!   |");
					}
				}
				opcao = 1;
				getchar();
				break;
				
			case 9:
				system("clear");
				if(removerFimFunc(&matriz)) {
					printf("\n\n\t|                     Elemento removido!                      |");
				} else {
					printf("\n\n\t|                     A lista esta vazia!                     |");
				}
				opcao = 1;
				getchar();
				break;
				
			case 10:
				system("clear");
				printf("\n\n\t|     Informe a posicao do elemento a ser removido: ");
				scanf("%d", &posicao);
				getchar();
				if(removerPosicaoFunc(&matriz, posicao)) {
					printf("\n\n\t|                     Elemento removido!                      |");
				} else {
					printf("\n\n\t|Lista esta vazia ou tentou remover de posicoes inexistentes! |");
					printf("\n\t|    Confira o tamanho da lista antes de tentar esta opcao!   |");
				}
				opcao = 1;
				getchar();
				break;
				
			case 11:
				system("clear");
				printf("\n\n\t|     Informe o elemento a ser encontrado: ");
				fgets(elemento.cpf, 12, stdin);
				clearBuffer();

				//getchar();
				if(procurarElementoFunc(&matriz, elemento) == -1) {
					printf("\n\n\t|                   Elemento nao encontrado!                  |");
				} else {
					printf("\n\n\t|               O elemento esta na posicao:%d            |", procurarElementoFunc(&matriz, elemento));
				}
				opcao = 1;
				getchar();
				break;
				
			case 12:
				system("clear");
				exibirElementosFunc(&matriz);
				opcao = 1;
				getchar();
				break;
			default:
				ShowMsgAlert("textforinterfaces/alertinvalidoption.txt");
				opcao = 1;
				break;
		}
	}
	if(ativo == 0) {
		*mod = 0;
	} else {
		*mod = 1;	
	}
	system("clear");
	return *mod;
}
