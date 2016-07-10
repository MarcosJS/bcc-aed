#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mainfunctions/functionsaux.h"
#include "strutctsandconstants.h"

void toChargeFunc(funcionario *element, char directory[], int givenField, int selectedRow) {

	int i;
	int j = 0;
	int field;
	int currentLine = 1;
	int endsString = 0;

	FILE *textMenu;
	textMenu = fopen(directory, "r");
	char entireRow[150];

	if(givenField == 0) {//Linha inteira.
	
		while(fgets(entireRow, 150, textMenu) != NULL) {
			field = 1;
			i = 0;
			while(entireRow[i] != '\n') {

				if((entireRow[i] == ',') || (entireRow[i] == ';')) {
					if(givenField == 0) {
						field++;
						endsString = 0;
					}
					i++;
					j = 0;	
				}
				if((field == 1) && (currentLine == selectedRow)) {
					if(entireRow[i] == '\"') {
						endsString++;
					} else {
						element->nome[j] = entireRow[i];
						j++;
					}
					if(endsString == 2) {
						element->nome[j] = '\0';
					}
				}

				if((field == 2) && (currentLine == selectedRow)) {
					if(entireRow[i] == '\"') {
						endsString++;
					} else {
						element->cpf[j] = entireRow[i];
						j++;
					}
					if(endsString == 2) {
						element->cpf[j] = '\0';
					}
				}

				if((field == 3) && (currentLine == selectedRow)) {
					if(entireRow[i] == '\"') {
						endsString++;
					} else {
						element->dataNascimento[j] = entireRow[i];
						j++;
					}
					if(endsString == 2) {
						element->dataNascimento[j] = '\0';
					}
				}

				if((field == 4) && (currentLine == selectedRow)) {
					if(entireRow[i] == '\"') {
						endsString++;
					} else {
						element->endereco[j] = entireRow[i];
						j++;
					}
					if(endsString == 2) {
						element->endereco[j] = '\0';
					}
				}

				if((field == 5) && (currentLine == selectedRow)) {
					if(entireRow[i] == '\"') {
						endsString++;
					} else {
						element->matricula[j] = entireRow[i];
						j++;
					}
					if(endsString == 2) {
						element->matricula[j] = '\0';
					}
				}

				if((field == 6) && (currentLine == selectedRow)) {
					if(entireRow[i] == '\"') {
						endsString++;
					} else {
						element->departamento[j] = entireRow[i];
						j++;
					}
					if(endsString == 2) {
						element->departamento[j] = '\0';
					}
				}

				if((field == 7) && (currentLine == selectedRow)) {
					if(entireRow[i] == '\"') {
						endsString++;
					} else {
						element->funcao[j] = entireRow[i];
						j++;
					}
					if(endsString == 2) {
						element->funcao[j] = '\0';
					}
				}

				if((field == 8) && (currentLine == selectedRow)) {
					if(entireRow[i] == '\"') {
						endsString++;
					} else {
						element->nivelAcesso[j] = entireRow[i];
						j++;
					}
					if(endsString == 2) {
						element->nivelAcesso[j] = '\0';
					}
				}

				if((field == 9) && (currentLine == selectedRow)) {
					if(entireRow[i] == '\"') {
						endsString++;
					} else {
						element->id[j] = entireRow[i];
						j++;
					}
					if(endsString == 2) {
						element->id[j] = '\0';
					}
				}

				if((field == 10) && (currentLine == selectedRow)) {
					if(entireRow[i] == '\"') {
						endsString++;
					} else {
						element->senha[j] = entireRow[i];
						j++;
					}
					if(endsString == 2) {
						element->senha[j] = '\0';
					}
				}
				i++;
			}
			currentLine++;
		}

	} else if(givenField > 0) {//Apenas um campo.

		while(fgets(entireRow, 150, textMenu) != NULL) {
			field = 1;
			i = 0;
			while(entireRow[i] != '\n') {
					if((entireRow[i] == ',') || (entireRow[i] == ';')) {
				field++;
				i++;	
				}
					if((field == givenField) && (currentLine == selectedRow) && (entireRow[i] != '\"')) {
					element->nome[j] = entireRow[i];
					j++;
				}
				i++;
			}
			currentLine++;
		}

	} 
	fclose(textMenu);
}

/*------------------------------------------------------------------*/
int strlenPointer(char *s) {
	int counter = 0;
	while(s[counter] != '\0') {
		counter++;
	}
	return counter;
}

/*------------------------------------------------------------------*/
int main(int argc, char *argv[]) {
	/*system("clear");
	char local[] = "textforinterfaces/menumain.txt";
	FILE *textMenu;
	textMenu = fopen(local, "r");
	char linha[100];
	while(fgets(linha, 100, textMenu)!= NULL) {
		printf("%s", linha);
	}
	fclose(textMenu);*/
/*------------------------------------------------------------------*/
	/*printf("%s - %s", __DATE__ , __TIME__);
	getchar();
	system("clear");*/
/*------------------------------------------------------------------*/
	/*int i;
	int campo;
	int l = 1;
	system("clear");
	FILE *textMenu;
	textMenu = fopen("staff.csv", "r");
	char linha[100];
	while(fgets(linha, 100, textMenu) != NULL) {
		campo = 1;
		i = 0;
		while(linha[i] != '\n') {

			if((linha[i] == ',') || (linha[i] == ';')) {
			campo++;
			i++;	
			}

			if((campo == 4) && (l == 6) && (linha[i] != '\"')) {
				printf("%c", linha[i]);
			}
			i++;
		}
		l++;
	}
	fclose(textMenu);
	getchar();*/
/*------------------------------------------------------------------*/
	funcionario elemento;
	char *s;
	s = toChargeChar("staff.csv", 150, 1, 2);
	printf("%s", s);
	printf("\n\n%d", strlenPointerC(s));
	//elemento.nome = *carregar("staff.csv", 150, 2, 2);
	//printf("%s", elemento.nome);
	//printf("%s", toChargeChar("staff.csv", 150, 1, 2));
	//printf("\n\n%c", s[0]);
	/*int i;
	int campo;
	int l = 1;
	system("clear");
	FILE *textMenu;
	textMenu = fopen("staff.csv", "r");
	char linha[150];
	while(fgets(linha, 150, textMenu) != NULL) {
		campo = 1;
		i = 0;
		while(linha[i] != '\n') {

			if((linha[i] == ',') || (linha[i] == ';')) {
			campo++;
			i++;	
			}

			if((campo == 4) && (l == 6) && (linha[i] != '\"')) {
				printf("%c", linha[i]);
			}
			i++;
		}
		l++;
	}
	fclose(textMenu);*/
	getchar();
}
