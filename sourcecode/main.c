#include <stdio.h>
#include <stdlib.h>
#include "modulos/menugmed.h"

int main(int argc, char *argv[]){

	int mod = 1;//Isso permite que o menu inicial seja exibído primeiro sempre que o sistema for iniciado
	
	system("clear");

	while(mod != 0){
	
     
		switch(mod) {
			case 0://Caso a opção seja "0" a função leave é chamada para o encerramento do sistema
				leave(&mod);
				break;
			case 1://Caso a opção seja "1" a função showMenu é chamada para exibir o menu desejado
				mod = showMenu("textforinterfaces/menumain.txt");
				break;
				    
			case 2:
				ShowMsgAlert("textforinterfaces/alertconstruct.txt");
				mod = 1;
				break;
				    
			case 3:////Caso a opção seja "3" o módulo gmed é iniciado contendo seu proprio menu
				startGmed(&mod);
				break;

			case 4:
				ShowMsgAlert("textforinterfaces/alertconstruct.txt");
				mod = 1;
				break;

			default:
				ShowMsgAlert("textforinterfaces/alertinvalidoption.txt");
				mod = 1;
				break;
		}

		system("clear");

	}
}
