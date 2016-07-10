#include <stdio.h>

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
	
	system("clear");
	char local[] = "menugpmed.txt";
	FILE *textMenu;
	textMenu = fopen(local, "r");
	char linha[100];
	while(fgets(linha, 100, textMenu)!= NULL) {
		printf("%s", linha);
	}
	fclose(textMenu);
	
	getchar();
}
