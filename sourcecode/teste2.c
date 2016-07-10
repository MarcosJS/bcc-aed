#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mainfunctions/functionsaux.h"
#include "strutctsandconstants.h"

/*void toChargeFunc(funcionario *element, char directory[], int givenField, int selectedRow) {

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
}*/

/*------------------------------------------------------------------*/
/*int strlenPointer(char s[]) {
	int counter = 0;
	while(s[counter] != '\0') {
		counter++;
	}
	return counter;
}*/

void salvar_categorias(lista_categoria *l) {
	FILE *fp;
	fp = (FILE *) fopen("categorias.dat", "wb");
	if(fp != NULL) {
		no_categoria *temp;
		temp = l->inicio;
		while(temp != NULL) {
			fwrite(&temp->dado, sizeof(categoria), 1, fp);
			temp = temp->proximo;
		}	
		fclose(fp);
	} 
}

void carregar_categorias(lista_categoria *l) {
	FILE *fp;
	categoria *dado;
	dado = (categoria *) malloc(sizeof(categoria));

	inicializar_lista_categoria(l);

	fp = (FILE *) fopen("categorias.dat", "rb");
	if(fp != NULL) {

		while(fread(dado, sizeof(categoria), 1, fp)) {
			adicionar_inicio_categoria(l, *dado);
			dado = (categoria *) malloc(sizeof(categoria));		
		}	
		fclose(fp);
	}
}

/*------------------------------------------------------------------*/
int main(int argc, char *argv[]) {
	
	funcionario element;
	toChargeFunc(&element, "staff.csv", 0, 2);
	
	printf("%s\n", element.nome);
	printf("%s\n", element.cpf);
	printf("%s\n", element.dataNascimento);
	printf("%s\n", element.endereco);
	printf("%s\n", element.matricula);
	printf("%s\n", element.departamento);
	printf("%s\n", element.funcao);
	printf("%s\n", element.nivelAcesso);
	printf("%s\n", element.id);
	printf("%s", element.senha);
	
	getchar();
}
