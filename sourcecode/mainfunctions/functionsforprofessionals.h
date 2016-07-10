#include "functionsaux.h"
#define TOTALFUNCIONARIOS 100
#define TOTALCLIENTES 1000
#define TOTALPRONTUARIOS 1000000

void inicializarFunc(listafunc *l) {
	l->n = 0;
}
/****************************************************/
int vaziaFunc(listafunc *l) {
	return (l->n == 0);
}
/****************************************************/
int cheiaFunc(listafunc *l) {
	return (l->n == TOTALFUNCIONARIOS);
}
/****************************************************/
int tamanhoFunc(listafunc *l) {
	return l->n;
}
/****************************************************/
//Copia para o parâmetro dado, as informações armazenadas 
//na posição pos e retorna 1
//Se a posicção for inválida, retorna 0
int carregarFunc(listafunc *l, int pos, funcionario *dado){
	int sucesso = 0;
	if(pos > 0 && pos < l->n) {
		*dado = l->dados[pos - 1];
		sucesso = 1;
	}
	return sucesso;
}
/****************************************************/
//Insere o elemento dado no fim da lista e retorna 1
//Caso a lista esteja cheia, retorna 0
int inserirFimFunc(listafunc *l, funcionario dado){
	int sucesso = 0;
	if(l->n < TOTALFUNCIONARIOS) {
		l->dados[l->n] = dado;
		l->n++; //atualiza a quantidade de elementos
		sucesso = 1;
	}
	return sucesso;
}
/****************************************************/
//Insere o elemento dado na posição pos e retorna 1
//Caso a lista esteja cheia ou a posição seja inválida, retorna 0
int inserirPosicaoFunc(listafunc *l, funcionario dado, int pos) {
	int sucesso = 0;
	int i;
	if(l->n < TOTALFUNCIONARIOS && pos > 0 && pos <= l->n) {
		for(i = l->n; i > pos; i--) {
			l->dados[i] = l->dados[i - 1];
		}
		l->dados[pos - 1] = dado;
		l->n++;
		sucesso = 1;
	}
	return sucesso;
}
/****************************************************/
int removerFimFunc(listafunc *l) {
	int sucesso = 0;
	if(l->n > 0) {
		l->n--;
		sucesso = 1;
	}
	return sucesso;
}
/****************************************************/
int removerPosicaoFunc(listafunc *l, int pos){
	int sucesso = 0;
	int i;
	if(l->n > 0 && pos > 0 && pos <= l->n) {
		for(i = pos - 1; i <= pos; i++) {
			l->dados[i] = l->dados[i + 1];
		}
		sucesso = 1;
		l->n--;
	} 
	return sucesso;
}
/****************************************************/
int procurarElementoFunc(listafunc *l, funcionario dado) {
	int resultado = -1;
	int i;
	if(l->n > 0) {
		for(i = 0; i < l->n; i++) {
			if(compararStrings(l->dados[i].cpf, dado.cpf)) {
					resultado = i + 1;
					break;
			}
		}
	}
	return resultado;
}
/****************************************************/
void exibirElementosFunc(listafunc *l) {
	int i;
	if(l->n > 0) {
		printf("\t|                     POSICAO | ELEMENTO                      |\n");
		for(i = 0; i < l->n; i++) {
			if(i < 9){
				//printf("\t|                           %d | %d\n", (i + 1), l->dados[i]);
				printf("\t|%28d | %s\n", (i + 1), l->dados[i].cpf);
			} else {
				//printf("\t|                          %d | %d\n", (i + 1), l->dados[i]);
				printf("\t|%27d | %d\n", (i + 1), l->dados[i].nivelAcesso);
			}
		}
	} else {
		printf("\t|           NAO EXITEM ELEMENTOS PARA SEREM EXIBIDOS          |\n");
	}
}
