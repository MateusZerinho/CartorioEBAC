#include <stdio.h> // biblioteca de comunica��o com o usu�rio
#include <stdlib.h> // biblioteca de aloca��o de espa�o em memoria
#include <locale.h> // biblioteca de aloca��es de texto por regi�o
#include <string.h> // biblioteca respons�vel pelas string

int registrar() // cadastro dos usu�rios
{
	// inicio das vari�veis/string
	char arquivo[50];
	char cpf[50];
	char nome[50];
	char sobrenome[50];
	char cargo[50];
	// final das vari�veis/string
	
	printf("Voc� escolheu: 1 - Registrar nomes\n\n");
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

int consultar() // cunsulta dos usu�rios
{
	setlocale(LC_ALL, "Portuguese"); // linguagem
	
	// inicio das vari�veis/string
	char cpf[50];
	char conteudo[200];
	// final das vari�veis/string
	
	printf("Voc� escolheu: 2 - Consultar nomes\n\n");
	printf("Digite o CPF para consultar: "); // coleta de dados
	scanf("%s", cpf);
	
	FILE *file; // cria o arquivo
	file = fopen(cpf, "r"); // abre o arquivo e le
	
	if(file == NULL) //caso n�o encontre o usu�rio
	{
		printf("CPF n�o encontrado. \n");
	}
	
	while(fgets(conteudo, 200, file) != NULL) //caso encontre o usu�rio
	{
		printf("\nEssas s�o as informa��es do usu�rio: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause"); // pausa a tela
}

int deletar() // deletendo o usu�rio
{
	// inicio das vari�veis/string
	char cpf[50];
	// final das vari�veis/string
	
	printf("Voc� escolheu: 3 - Deletar nomes\n\n");
	printf("Digite um CPF para deletar: "); // coleta de dados
	scanf("%s", cpf);
	
	remove(cpf); // remove o cpf
	
	FILE *file; // cria o arquivo
	file = fopen(cpf, "r"); // abre o arquivo e le
	
	if(file == NULL) // resposta para o usu�rio
	{
		printf("\nUsu�rio deletado!\n\n");
		system("pause"); // pausa a tela
	}

}

int main()
{
	int resposta = 0; // variaveis
	int x = 1;
	
	for(x = 1; x =1;) // repeti��o
	{
		system("cls"); // limpar a tela
		
		setlocale(LC_ALL, "Portuguese"); // linguagem
  	  
		printf("### Cart�rio da EBAC ###\n\n"); // inicio do menu
		printf("Escolha a op��o desejada do menu:\n\n");
		printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n");
		printf("\t4 - Sair do menu\n\n");
		printf("Op��o: "); // final do menu
  	 	 
		scanf("%d", &resposta); // armazenando a resposta
			    
		system("cls"); // limpar a tela
		
		switch(resposta) // inicio da sele��o
		{
			case 1:
				registrar(); // chama a fun��o	
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
		} // fim da sele��o
	}
}
