#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //biblioteca de aloca��es de texto por regi�o
#include <string.h> // biblioteca respons�vel por cuidar das string

	int registro()	//Respons�vel por candastrar os usu�rios
	
	{	 //inicializa��o das vari�veis
		char arquivo[50]; //char � um caracter ou s� n�mero um, como um espa�o, j� o string[] entra nele, no string tem 50 arquivos
		char cpf[50]; // e outro string tem 50 cpfs em um outro char(espa�o), etc
		char nome[50];
		char sobrenome[50];
		char idade[50];
		char email[50];
		char telefone[50];
		char cargo[50];
		 //finaliza��o das vari�veis
		
		printf("Digita o CPF do usu�rio:");	//apresenta escrito na tela (printf)
		scanf("%s", cpf); //porcetagem(%) chama uma coisa(n� de cpf), string(s) armaneza dado, logo atende um vari�vel depois da virgula, como caso do cpf. Lembrando que string � um conjunto de vari�veis
		
			strcpy(arquivo,cpf); // nome de arquivo = cpf - respons�vel por copiar os valores dos string	
	
		 //Abrindo a pasta
		FILE*file; //FILE = procurar na biblio e file = criar arquivo
		file = fopen(arquivo, "w"); //arquivo � nesse strcpy e "w" � como papel para come�ar a escrever - Arquivo da pasta
		fprintf(file, "<");
		fprintf(file, cpf); //escrito dentro do arquivo - salvo o valor da vari�vel
		fprintf(file, ">\n\n");
		fclose(file); //fecha o arquivo  
		 //Pasta fechada
		 
		 //Escrevendo na tela
		printf("\nDigita o nome do usu�rio:\n");
		scanf("%s" , nome);
		
		printf("\nDigita sobrenome do usu�rio:\n");
		scanf("%s", sobrenome);
		
		 //Abrindo a pasta
		file = fopen(arquivo, "a"); // esse file � chamado para continuar no mesmo arquivo. Fopen pede abrir o file, "(arquivo," chama o string e "a" para atualizar, continua escrevendo no mesmo arquivo
		fprintf(file, "�ltimo nome / Nome:"); // fprintf aparece escrito na pasta no file, mas "file," chama p continuar e "" para escrever algo na pasta
		fprintf(file, "\n[");
		fprintf(file, sobrenome); // no fprintf, tem sobrenome para armaneza no mesmo arquivo com file antes dele
		fprintf(file, "] ");
		fclose(file);
		 //Pasta  fechada
		
		 //Abrindo a pasta
		file = fopen(arquivo, "a");
		fprintf(file, nome);
		fprintf(file, "\t\t");
		fclose(file);
		 //Pasta fechada		
		
		 //Escrevendo na tela
		 printf("\nData de nascimento:\n");
		 scanf("%s" , idade);
		 
		 //Abrindo a pasta
		file = fopen(arquivo, "a");
		fprintf(file, idade);
		fprintf(file, "\n\n");
		fclose(file);
		 //Pasta fechada
		 
		 //Escrevendo na tela
		printf("\nEmail:");
		scanf("%s" , email);
		 
		 //Escrevendo na tela
		printf("\nTelefone:");
		scanf("%s", telefone);
		 
		 //Abrindo a pasta
		file = fopen(arquivo, "a");
		fprintf(file, "Email / Telefone:\n");
		fprintf(file, email);
		fprintf(file, "\t");
		fclose(file);
		 //Pasta fechada
		
		 //Abrindo a pasta
		file = fopen(arquivo, "a");
		fprintf(file, telefone);
		fprintf(file, "\n\n");
		fclose(file);
		 //Pasta fechada
				
		 //Escrevendo a tela
		printf("\nDigita seu cargo:\n");
		scanf("%s" , cargo);
		printf("\n");
		
		 //Abrindo a pasta
		file = fopen(arquivo, "a");
		fprintf(file, "Cargo:\n");
		fprintf(file, cargo);
		fprintf(file, "\n\n");
		fclose(file);
		 //Pasta fechada
		
		system("pause"); //system conversa com computador, e pause para travar a tela para algo
		
		
	}
	
	
	int consulta ()
	
	{		
		setlocale(LC_ALL,"Portuguese");
		
		char cpf [50];
		char conteudo [250];
		
		printf("Digite o CPF de usu�rio:\n");
		scanf("%s" , cpf);
		system("cls"); // limpa todos escritos em cima
		
		FILE*file;
		file = fopen(cpf, "r"); // r l� uma pasta toda em cpf depois da virgula dele
		
		if(file == NULL) // if usa como "esse ou esse" dependendo da escolha de usu�rio, == � procurar uma coisa igual absoluta do file, em seguiente com NULL s� para restar os dados que s�o existentes
		{
			printf("O usu�rio n�o cadastrado.\n");
		}
		
			printf("\nEis as informa��es do usu�rio:");
	

		while(fgets(conteudo, 250, file) !=NULL) // while neste caso busca os dados existentes. fgets busca algo e dentro dele(): "(conteudo," � um vari�vel string, 250 idem, file para procurar o arquivo existente do registro
		{
			printf("%s" , conteudo); // conteudo depois de "%s," para atender o fgets
		}
		fclose(file);
		system("pause");	
	}
	
	  
	int exclusao()

	{
		char cpf[50];
		
		printf("Qual usu�rio ser� excluido?\n");
		scanf("%s", cpf);
		
		FILE*file;
		file = fopen(cpf, "r");
		fclose(file);
				
		if(file == NULL)
		{
			printf("Usu�rio inexistente.\n\n");
			system("pause");	
		}
				
		else
		{
			remove(cpf);
			printf("Usu�rio escolhido excluido.\n\n");
			system("pause");
		}
			
	}	

int main ()

	{
	int opcao=0; //Definindo vari�veis
	int laco=1;		
		
		for(laco==1;laco==1;)
		{
			system("cls"); 
		
			setlocale(LC_ALL,"Portuguese"); //Definindo a linguagem
			
			printf("### Cart�rio da EBAC ###\n\n"); //inicio do menu
			printf("Qual op��o do menu voc� deseja:\n\n\n");
			printf("\t1. Registrar usu�rio\n\n");
			printf("\t2. Consultar usu�rio\n\n");
			printf("\t3. Excluir usu�rios\n\n\n"); //fim do menu
			printf("\t4. Sa�da do sistema\n\n");
			printf("Op��o:\n\n");
			
			scanf("%d", &opcao); //armazenando a escolha de usu�rio
		
			system("cls");//limpar
			
			switch(opcao)
			{
				case 1:
				registro();
				break;
				
				case 2:
				consulta();
				break;
				
				case 3:
				exclusao();
				break;
				
				case 4:
				printf("Obrigado e volte sempre!\n");
				return 0;
				break;
				
				default:
				printf("Op��o inexistente!");
				system("pause");
				break;		
			}
		}
	} 
	

