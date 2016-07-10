#include <time.h>

listafunc matriz;
funcionario elemento;
bool status;

int uploadStaff(char * txtStaff) {
	int op = 1;
	system("clear");
	FILE *textMenu;
	textMenu = fopen(txtStaff, "r");
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
