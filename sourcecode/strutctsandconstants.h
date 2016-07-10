#define TOTALFUNCIONARIOS 100
#define TOTALCLIENTES 1000
#define TOTALPRONTUARIOS 1000000
#define TAMANHOSTRINGMEDIO 150

typedef struct Funcionario {
	//1 dados pessoais
	char nome[TAMANHOSTRINGMEDIO];
	char cpf[12];
	char dataNascimento[9];
	//1.1 dados de endereço compõem os dados pessoais
	char endereco[TAMANHOSTRINGMEDIO];
	//2 dados funcionais
	char matricula[5];
	char departamento[TAMANHOSTRINGMEDIO];
	//2.2 dados de funções compõem os dados pessoais
	char funcao[TAMANHOSTRINGMEDIO];
	//char nivelAcesso[2];
	int nivelAcesso;
	char id[50];
	char senha[20];
} funcionario;

typedef struct {
	funcionario dados[TOTALFUNCIONARIOS]; // Matriz que contém os elementos
	int n; //Número de elementos
} listafunc;

typedef struct Cliente {
	//1 dados pessoais
	char nome[TAMANHOSTRINGMEDIO];
	char cpf[12];
	char dataNascimento[7];
	//1.1 dados de endereço compõem os dados pessoais
	char endereco[TAMANHOSTRINGMEDIO];
	//2 dados do cliente
	char codigoCliente[5];
	int familiaPaciente;//de 1 a 3("proximo","familiar","proprio")
	//4 dados do prontuario
	char numeroProntuario[8];
	//5 dados do plano
	int tipoPlano;
	double saldo;
} cliente;

typedef struct {
	cliente dados[TOTALCLIENTES]; // Matriz que contém os elementos
	int n; //Número de elementos
} listacliente;

typedef struct Prontuario {
	//1 dados pessoais do paciente que compõem o prontuario
	char nome[TAMANHOSTRINGMEDIO];
	char cpf[12];
	char dataNascimento[7];
	//1.1 dados de endereço compõem os dados pessoais
	char endereco[TAMANHOSTRINGMEDIO];
	//2 dados do paciente que compõem o prontuário
	char codigoResponsavel[5];
	//dados do prontuario
	char numero[8];
	int estadoAtual;//de 1 a 4("sem risco","observação","grave","morte")
   	int tipo;//"normal" ou "quaretena"
} prontuario;

typedef struct {
	prontuario dados[TOTALPRONTUARIOS]; // Matriz que contém os elementos
	int n; //Número de elementos
} listapront;
