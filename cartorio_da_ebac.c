#include <stdio.h> //biblioteca de comunica��o com o usuario
#include <stdlib.h> //biblioteca de aloca��o de espa�o em memoria 
#include <locale.h>	//bibiioteca de aloca��o de texto por regi�o
#include <string.h> // biblioteca responsavel por cuidar das string

int registro() //  fun��o responsavel por cadastra usuarios no sistema 
{

	// inivio cria��o de variaveis / string
	char unico[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	// Final cria��o de usuarios 

	printf("Digite o CPF para ser cadastrado: ");// coleta informa��o do usuiario 
	scanf("%s", cpf);// %s referece ao armazenamneto de string
	
	strcpy(unico, cpf);// responsavel por copiar o valor da string cpf para a string unico 
	
	FILE *file;//cria o arquivo 
	file = fopen(unico,"w");//cria o arquivo e o "W" significa escrever 
	fprintf(file,cpf);//salva o valor da variavel
	fclose(file);//fecha o arquivo "unico"
	
	file = fopen(unico, "a");//Acessa o arquivo, o"A" significa atualizar.
	fprintf(file, ",");//inclui uma virgula dentro do arquivo para que as infoma�oes nao fique sem separa��o.
	fclose(file);//fecha o arquivo .
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s", nome);
	
	file = fopen(unico, "a");
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(unico, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s",sobrenome);
	
	file = fopen(unico,"a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(unico, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s", cargo);
	
	file = fopen(unico,"a");
	fprintf(file,cargo);
	fclose(file);
	
		file = fopen(unico, "a");
	fprintf(file, ",");
	fclose(file);
	
	
}

int consultar()
{
		setlocale(LC_ALL, "portuguese"); // Definindo linguagem 
		
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado: ");//coletando informa��o para pesquisa dentro do sistema 
	scanf("%s",cpf);//salva na string
	
	FILE *file;// acessando o aruivo 
	file = fopen(cpf,"r");//abrindo e lendo o arquivo ( "r"  de read que significa ler ) 
	
	if (file==NULL)//responsavel por levar uma mensagem ao usuario caso o arquivo n�o seja encontrado/nullo
	{
		printf("\n Arquivo n�o localizado, CPF incorreto ou invalido\n\n");
	}
	while(fgets(conteudo,200,file) !=NULL)
	{
	
		printf("\n Essas s�o as informa��es do us�ario:\n\n");
		printf("%s",conteudo);
		printf("\n\n");
	}
	
	system("pause");// pausa o sistema para que o usuario tenha tempo de ler as informa��es na tela.
}

int deletar()
{
	char cpf[40];
	
	
	printf("Digite o Cpf a ser Deletado: ");//coletando dado que o �suario quer deletar 
	scanf("%s",cpf);//salva na string 
	
	remove(cpf);//remove o dado que o usuario desejou 
	
	FILE *file;// acessa os arquivo salvos.
	file = fopen(cpf,"r");// Abre o arquivo, verifica se os dados fornecido se encontra dentro do banco de dados,"r" le o arquivo  
	
	if(file==NULL)//responsavel por levar uma mensagem ao usuario caso o arquivo n�o seja encontrado/nullo
	{
		printf("Usuario n�o localizado!\n");
		system ("pause");
	}


}

int main()
{
	int opcao=0; //Definindo variaveis
	int laco=1; //la�o de repeti��o do menu 
	
	for(laco=1;laco=1;)
	{

		system("cls");// responsavel por limpar a Tela 
	
		setlocale(LC_ALL, "portuguese"); // Definindo o Idioma 
		
		//inicio do  menu 
		printf("### Caretorio da EBAC ### \n\n");
		printf("escolha a op��o desejada do menu: \n\n");
		printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n");
		printf("\t4 - sair do sistema \n");
		printf("op��o:");
	
		scanf("%d",&opcao); //Armmazenando a escolha do usuario
	
		system("cls"); // comando responsavel por limpar o sistema depois que o ussuario degitar
	
		switch(opcao) //
		{
			case 1:
			registro();//chamando a fun��o Registro 
			break;
			
			case 2:
			consultar();//chamando a fun��o consultar 
			break;
			
			case 3:
			deletar();// chamando a fun��o deletar 
			break; 
			
			case 4:
			printf("obrigado por usar o sistema\n ");
			return 0;
			break;
			
			
			default://
			printf("Essa opcao n�o esta disponivel \n");// caso o usuario digite uma op��o n�o valida aparece essa mensagem 
			system("pause");// da uma pausa no sistema para que o usuario tenha tempo de ler as informa�oes da tela 
			break;
			//fim da sele��o do menu.
		}
	
	
	}
}


