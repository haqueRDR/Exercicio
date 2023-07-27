#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço em memória
#include <locale.h> //biblioteca de alocações de texto por região
#include <string.h> // biblioteca responsável por cuidar das string

	int registro()	//Responsável por candastrar os usuários
	
	{	 //inicialização das variáveis
		char arquivo[50]; //char é um caracter ou só número um, como um espaço, já o string[] entra nele, no string tem 50 arquivos
		char cpf[50]; // e outro string tem 50 cpfs em um outro char(espaço), etc
		char nome[50];
		char sobrenome[50];
		char idade[50];
		char email[50];
		char telefone[50];
		char cargo[50];
		 //finalização das variáveis
		
		printf("Digita o CPF do usuário:");	//apresenta escrito na tela (printf)
		scanf("%s", cpf); //porcetagem(%) chama uma coisa(nº de cpf), string(s) armaneza dado, logo atende um variável depois da virgula, como caso do cpf. Lembrando que string é um conjunto de variáveis
		
			strcpy(arquivo,cpf); // nome de arquivo = cpf - responsável por copiar os valores dos string	
	
		 //Abrindo a pasta
		FILE*file; //FILE = procurar na biblio e file = criar arquivo
		file = fopen(arquivo, "w"); //arquivo é nesse strcpy e "w" é como papel para começar a escrever - Arquivo da pasta
		fprintf(file, "<");
		fprintf(file, cpf); //escrito dentro do arquivo - salvo o valor da variável
		fprintf(file, ">\n\n");
		fclose(file); //fecha o arquivo  
		 //Pasta fechada
		 
		 //Escrevendo na tela
		printf("\nDigita o nome do usuário:\n");
		scanf("%s" , nome);
		
		printf("\nDigita sobrenome do usuário:\n");
		scanf("%s", sobrenome);
		
		 //Abrindo a pasta
		file = fopen(arquivo, "a"); // esse file é chamado para continuar no mesmo arquivo. Fopen pede abrir o file, "(arquivo," chama o string e "a" para atualizar, continua escrevendo no mesmo arquivo
		fprintf(file, "Último nome / Nome:"); // fprintf aparece escrito na pasta no file, mas "file," chama p continuar e "" para escrever algo na pasta
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
		
		printf("Digite o CPF de usuário:\n");
		scanf("%s" , cpf);
		system("cls"); // limpa todos escritos em cima
		
		FILE*file;
		file = fopen(cpf, "r"); // r lê uma pasta toda em cpf depois da virgula dele
		
		if(file == NULL) // if usa como "esse ou esse" dependendo da escolha de usuário, == é procurar uma coisa igual absoluta do file, em seguiente com NULL só para restar os dados que são existentes
		{
			printf("O usuário não cadastrado.\n");
		}
		
			printf("\nEis as informações do usuário:");
	

		while(fgets(conteudo, 250, file) !=NULL) // while neste caso busca os dados existentes. fgets busca algo e dentro dele(): "(conteudo," é um variável string, 250 idem, file para procurar o arquivo existente do registro
		{
			printf("%s" , conteudo); // conteudo depois de "%s," para atender o fgets
		}
		fclose(file);
		system("pause");	
	}
	
	  
	int exclusao()

	{
		char cpf[50];
		
		printf("Qual usuário será excluido?\n");
		scanf("%s", cpf);
		
		FILE*file;
		file = fopen(cpf, "r");
		fclose(file);
				
		if(file == NULL)
		{
			printf("Usuário inexistente.\n\n");
			system("pause");	
		}
				
		else
		{
			remove(cpf);
			printf("Usuário escolhido excluido.\n\n");
			system("pause");
		}
			
	}	

int main ()

	{
	int opcao=0; //Definindo variáveis
	int laco=1;		
		
		for(laco==1;laco==1;)
		{
			system("cls"); 
		
			setlocale(LC_ALL,"Portuguese"); //Definindo a linguagem
			
			printf("### Cartório da EBAC ###\n\n"); //inicio do menu
			printf("Qual opção do menu você deseja:\n\n\n");
			printf("\t1. Registrar usuário\n\n");
			printf("\t2. Consultar usuário\n\n");
			printf("\t3. Excluir usuários\n\n\n"); //fim do menu
			printf("\t4. Saída do sistema\n\n");
			printf("Opção:\n\n");
			
			scanf("%d", &opcao); //armazenando a escolha de usuário
		
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
				printf("Opção inexistente!");
				system("pause");
				break;		
			}
		}
	} 
	

