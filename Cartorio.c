#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //biblioteca de aloca��es de texto por regi�o
#include <string.h> //biblioteca respons�vel por cuidar das strings

int reg() //fun��o de registro
{
	setlocale(LC_ALL,"Portuguese"); //Definindo a lingu�gem
	
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	char escolha;
		
	printf("Digite o CPF a ser cadastrado: ");
	scanf("%s",cpf);
	
	strcpy(arquivo, cpf); //respons�vel por copiar os valores das strings
	
	FILE *file; //cria o arquivo
	file = fopen(arquivo, "w"); //cria o arquivo
	fprintf(file,cpf); //salva o valor da vari�vel
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
	
	printf("Deseja registrar outro nome?(s/n)\n");
	scanf(" %c",&escolha);
	
	system("cls");
	
	if (escolha == 's')
	reg();
	
	else
	if (escolha == 'n')
	main();
		
	else
    printf ("Op��o indispon�vel, retornando ao menu principal!\n");	
	
	
	system("pause");
	
			
}

int cons() //fun��o de consulta
{
	setlocale(LC_ALL,"Portuguese"); //Definindo a lingu�gem
	
	char cpf[40];
	char conteudo[200];
	char *token;
	char escolha;
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file == NULL)
	{
		printf("N�o foi poss�vel abrir o arquivo, CPF n�o localizado! \n");
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nEssas s�o as informa��es do usu�rio: \n");
		
		token = strtok(conteudo, ",");
		printf("CPF: %s\n",token);
		
		token = strtok(NULL, ",");
		printf("Nome: %s\n",token);
		
		token = strtok(NULL, ",");
		printf("sobrenome: %s\n",token);
		
		token = strtok(NULL, ",");
		printf("Cargo: %s\n",token);
		
		printf("\n\n");
		
	printf("Deseja consultar outro nome?(s/n)\n");
	scanf(" %c",&escolha);
	
	system("cls");
	
	if (escolha == 's')
	cons();
	
	else
	if (escolha == 'n')
	main();
		
	else
    printf ("Op��o indispon�vel, retornando ao menu principal!\n");
	}
	system("pause");
}

int del() //fun��o de deletar
{
	setlocale(LC_ALL,"Portuguese"); //Definindo a lingu�gem
	
	char cpf[40];
	char escolha;
	
	printf("Digite o CPF do usu�rio a ser deletado: ");
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("O usu�rio n�o se encontra no sistema!\n");
		system("pause");
	}
	else
	{
		remove(cpf);
		printf("Usu�rio removido com sucesso! \n");
		system("pause");
	}
	
		printf("Deseja deletar outro nome?(s/n)\n");
	scanf(" %c",&escolha);
	
	system("cls");
	
	if (escolha == 's')
	del();
	
	else
	if (escolha == 'n')
	main();
		
	else
    printf ("Op��o indispon�vel, retornando ao menu principal!\n");
	
}

int main()
{
	int opcao=0; //Definindo as vaari�veis
	int laco=1;
	char senhadigitada[10]="a"; //string de senha
	int comparacao; //variavel de compara��o de senha
	
	setlocale(LC_ALL,"Portuguese"); //Definindo a lingu�gem
	
	printf("### Cart�rio da EBAC ###\n\n");
	printf("Login de administrador!\n\nDigite sua senha:");
	scanf("%s",senhadigitada);
	
	comparacao = strcmp(senhadigitada, "admin");
	
	if (comparacao == 0)
	{
					
		for(laco=1;laco=1;)
		{
			
			system("cls");
		
			
		
			printf("### Cart�rio da EBAC ###\n\n"); //In�cio do menu
			printf("Escolha a op��o desejada do menu:\n\n");
			printf("\t1 - Registrar nomes\n");
			printf("\t2 - Consultar nomes\n");
			printf("\t3 - Deletar nomes\n");
			printf("\t4 - Sair do sistema\n\n"); 
			printf("Op��o:"); //Fim do menu
			
			scanf("%d",&opcao); //armazenando a escolha do usu�rio
		
			system("cls");
		
			switch(opcao) //In�cio da sele��o
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
			
				case 4:
				printf("Obrigado por utilizar o sistema!\n\n");
				return 0;
				break;
			
				default:
				printf("Esta op��o n�o est� dispon�vel!\n");
				system("pause");
				break;
			}//Fim da sele��o
		}
	}
	
	else
		printf("Senha incorreta!\n\n");
		system("pause");
		system("cls");
		main();
}
