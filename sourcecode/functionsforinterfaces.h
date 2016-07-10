#include <stdio.h>
#include <stdlib.h>

//Exibir o menu na tela
//Recebe o texto como parametro que será redenrizado na tela
int showMenu(char * txtMenu) {
	int op = 1;
	system("clear");
	FILE *textMenu;
	textMenu = fopen(txtMenu, "r");
	char linha[100];
	while(fgets(linha, 100, textMenu) != NULL) {
		printf("%s", linha);
	}
	fclose(textMenu);
	printf("\t|Opcao:");
	scanf("%d", &op);
	getchar();
	return op;
}

//Exibir mensagens de erros
//Recebe o texto como parametro que será redenrizado na tela
void ShowMsgAlert(char *txtMsg) {
	system("clear");
	FILE *textMsg;
	textMsg = fopen(txtMsg, "r");
	char linha[100];
	while(fgets(linha, 100, textMsg) != NULL) {
		printf("%s", linha);
	}
	fclose(textMsg);
	getchar();
}

//Limpa o buffer do teclado
void clearBuffer(){
	char c;
	while((c = getchar()) != '\n' && c != EOF); 
}

//Função que encerra o módulo atual
void leave(int *mod) {
	system("clear");
   	mod = 0;
}

//Função ao menu anterior
void back(int *op) {
	system("clear");
   	op = 0;
}
