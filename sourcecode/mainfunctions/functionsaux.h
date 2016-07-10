#include <stdio.h>
#include <string.h>
//Retorna um se as strings forem iguais
int compararStrings(char *string1, char *string2) {
	int resultado = 0;	
	int i;
	int nIguais = 0;
	for(i = 0; i < strlen(string2); i++){
		if(string1[i] == string2[i]) {
			nIguais++;
		}
	}
	if(nIguais == strlen(string2)) {
		resultado = 1;
	}
	return resultado;
}
/****************************************************/
void replicateCharacter(char c, int n) {
	int i;
	for(i = 0; i < n; i++) {
		printf("%c", c);
	}
}
/****************************************************/
int strlenPointer(char *s) {
	int counter = 0;
	while(s[counter] != '\0') {
		counter++;
	}
	return counter;
}
