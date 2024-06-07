#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço em memória
#include <locale.h> //biblioteca de alocações de texto por região
#include <string.h> //biblioteca responsável por cuidar das strings

int reg() //função de registro
{
	setlocale(LC_ALL,"Portuguese"); //Definindo a linguágem
	
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	
	printf("Digite o CPF a ser cadastrado: ");
	scanf("%s",cpf);
	
	strcpy(arquivo, cpf); //responsável por copiar os valores das strings
	
	FILE *file; //cria o arquivo
	file = fopen(arquivo, "w"); //cria o arquivo
	fprintf(file,cpf); //salva o valor da variável
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s",nome);
	
	file = fopen(arquivo, "a");
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);	
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s",sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file,sobrenome);
	fclose(file);	
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s",cargo);
		
	file = fopen(arquivo, "a");
	fprintf(file,cargo);
	fclose(file);	
	
	system("pause");
	
			
}

int cons() //função de consulta
{
	setlocale(LC_ALL,"Portuguese"); //Definindo a linguágem
	
	char cpf[40];
	char conteudo[200];
	char *token;
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file == NULL)
	{
		printf("Não foi possível abrir o arquivo, CPF não localizado! \n");
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nEssas são as informações do usuário: \n");
		
		token = strtok(conteudo, ",");
		printf("CPF: %s\n",token);
		
		token = strtok(NULL, ",");
		printf("Nome: %s\n",token);
		
		token = strtok(NULL, ",");
		printf("sobrenome: %s\n",token);
		
		token = strtok(NULL, ",");
		printf("Cargo: %s\n",token);
		
		printf("\n\n");
	}
	system("pause");
}

int del() //função de deletar
{
	setlocale(LC_ALL,"Portuguese"); //Definindo a linguágem
	
	char cpf[40];
	
	printf("Digite o CPF do usuário a ser deletado: ");
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("O usuário não se encontra no sistema!\n");
		system("pause");
	}
	else
	{
		remove(cpf);
		printf("Usuário removido com sucesso! \n");
		system("pause");
	}
}

int main()
{
	int opcao=0; //Definindo as vaariáveis
	int laco=1;
			
	for(laco=1;laco=1;)
	{
		
		system("cls");
		
		setlocale(LC_ALL,"Portuguese"); //Definindo a linguágem
		
		printf("### Cartório da EBAC ###\n\n"); //Início do menu
		printf("Escolha a opção desejada do menu:\n\n");
		printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n\n"); 
		printf("Opção:"); //Fim do menu
		
		scanf("%d",&opcao); //armazenando a escolha do usuário
		
		system("cls");
		
		switch(opcao) //Início da seleção
		{
			case 1:
			reg();
			break;
			
			case 2:
			cons();
			break;
			
			case 3:
			del();
			break;
			
			default:
			printf("Esta opção não está disponível!\n");
			system("pause");
			break;
		}//Fim da seleção
	}	
}
