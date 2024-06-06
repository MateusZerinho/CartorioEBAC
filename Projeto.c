#include <stdio.h> // biblioteca de comunicação com o usuário
#include <stdlib.h> // biblioteca de alocação de espaço em memoria
#include <locale.h> // biblioteca de alocações de texto por região
#include <string.h> // biblioteca responsável pelas string

int registrar() // cadastro dos usuários
{
	// inicio das variáveis/string
	char arquivo[50];
	char cpf[50];
	char nome[50];
	char sobrenome[50];
	char cargo[50];
	// final das variáveis/string
	
	printf("Você escolheu: 1 - Registrar nomes\n\n");
	printf("Digite um CPF para registrar: "); // coleta de dados
	scanf("%s", cpf);
	
	strcpy(arquivo, cpf); // responsalvel por copiar os valores das string
	
	FILE *file; // cria o arquivo
	file = fopen(arquivo, "w"); // cria o arquivo e escreve
	
	file = fopen(arquivo, "a"); // abre o arquivo e atualiza
	fprintf(file, "CPF: "); // adiciona complemento
	fclose(file); // fecha o arquivo
	
	file = fopen(arquivo, "a");
	fprintf(file, cpf); // salva o valor da variavel
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ", NOME: ");
	fclose(file);
	
	printf("Digite um nome para registrar: ");
	scanf("%s", nome);
	
	file = fopen(arquivo, "a");
	fprintf(file, nome); // adiciona o nome no arquivo
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ", SOBRENOME: ");
	fclose(file);
	
	printf("Digite um sobrenome para registrar: ");
	scanf("%s", sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file, sobrenome); // adiciona o sobrenome no arquivo
	fclose(file);	
	
	file = fopen(arquivo, "a");
	fprintf(file, ", CARGO: ");
	fclose(file);
	
	printf("Digite um cargo para registrar: ");
	scanf("%s", cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file, cargo); // adiciona o cargo no arquivo
	fclose(file);
	
	system("pause"); // pausa a tela
	
}

int consultar() // cunsulta dos usuários
{
	setlocale(LC_ALL, "Portuguese"); // linguagem
	
	// inicio das variáveis/string
	char cpf[50];
	char conteudo[200];
	// final das variáveis/string
	
	printf("Você escolheu: 2 - Consultar nomes\n\n");
	printf("Digite o CPF para consultar: "); // coleta de dados
	scanf("%s", cpf);
	
	FILE *file; // cria o arquivo
	file = fopen(cpf, "r"); // abre o arquivo e le
	
	if(file == NULL) //caso não encontre o usuário
	{
		printf("CPF não encontrado. \n");
	}
	
	while(fgets(conteudo, 200, file) != NULL) //caso encontre o usuário
	{
		printf("\nEssas são as informações do usuário: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause"); // pausa a tela
}

int deletar() // deletendo o usuário
{
	// inicio das variáveis/string
	char cpf[50];
	// final das variáveis/string
	
	printf("Você escolheu: 3 - Deletar nomes\n\n");
	printf("Digite um CPF para deletar: "); // coleta de dados
	scanf("%s", cpf);
	
	remove(cpf); // remove o cpf
	
	FILE *file; // cria o arquivo
	file = fopen(cpf, "r"); // abre o arquivo e le
	
	if(file == NULL) // resposta para o usuário
	{
		printf("\nUsuário deletado!\n\n");
		system("pause"); // pausa a tela
	}

}

int main()
{
	int resposta = 0; // variaveis
	int x = 1;
	
	for(x = 1; x =1;) // repetição
	{
		system("cls"); // limpar a tela
		
		setlocale(LC_ALL, "Portuguese"); // linguagem
  	  
		printf("### Cartório da EBAC ###\n\n"); // inicio do menu
		printf("Escolha a opção desejada do menu:\n\n");
		printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n");
		printf("\t4 - Sair do menu\n\n");
		printf("Opção: "); // final do menu
  	 	 
		scanf("%d", &resposta); // armazenando a resposta
			    
		system("cls"); // limpar a tela
		
		switch(resposta) // inicio da seleção
		{
			case 1:
				registrar(); // chama a função	
    		break;
   		
    		case 2:
    			consultar();  		
    		break;
	
			case 3:
    			deletar(); 		
    		break;
    		
    		case 4:
    			printf("Obrigado por utilizar nosso sistema!\n");
    			return 0;
    		break;
    			
    		default:
    			printf("Digite um numero valido\n\n");
				system("pause");
			break;
		} // fim da seleção
	}
}
