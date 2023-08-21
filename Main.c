#include<stdio.h>
#include<stdlib.h>
#include <string.h>
#include <locale.h>
#include <time.h>

#define TRUE 1
#define FALSE 0

struct cliente{
	int id;
	char deletado;
	char nome[40];
	char cpf[14];
	char nascimento[12];
	};


void limpaTela(void){
		system("cls"); 
		printf("||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
		printf("|||||     SGBD Vithor,Honorio,Kevin e Leonardo      ||||||\n");
		printf("||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n \n");
	}	

void adiciona(FILE *arquivo){

	if (arquivo == NULL){
	printf("Erro ao abrir arquivo");
	return;
	}

	struct cliente novoCliente;
	
	srand(time(NULL));
	novoCliente.id = rand()%101;
	novoCliente.deletado = 0;
 
	printf("Digite o nome do cliente: \n");
	gets(novoCliente.nome);


	printf("Digite o cpf do cliente: \n");
	gets(novoCliente.cpf);


	printf("Digite o nascimento do cliente: \n");
	gets(novoCliente.nascimento);

	

	fwrite (&novoCliente, sizeof(novoCliente), 1, arquivo);
}


int main(){

	//	Setando caracteres para portugues
	setlocale(LC_ALL,"");

	limpaTela();
	
	printf("Qual o nome do arquivo que deseja acessar: ");
	
	char nomeDoArquivo[20];					//aloca string
	fgets(nomeDoArquivo, 15, stdin);		//recebe a entrada

	nomeDoArquivo[strcspn(nomeDoArquivo, "\n")] = 0; //seta o primeiro \n , para \0 
	fflush(stdin);									//limpa a entrada
	
	strcat(nomeDoArquivo,".txt");
	FILE *arquivo = fopen(nomeDoArquivo,"w+");

	while(1){
		char opcao;
		
		printf("\nArquivo selecionado: %s \n\n",nomeDoArquivo);
		printf("Selecione uma opção: \n \n");
		printf("1 - Criar novo Registro\n");
		printf("2 - Ler um Registro\n");
		printf("3 - Atualizar Registro\n");
		printf("4 - Remover Registro\n");
		printf("Q - Sair do Programa\n");
		
		opcao = getchar();
		fflush(stdin); //limpa a entrada apos o caractere escolhido

		limpaTela();
		
		//printf("Opção escolhida: %c , %d\n",opcao,opcao);

		if(opcao == 113 || opcao == 81){
			break;
		}
		else{
				switch(opcao){
					case 49:
						printf("Opção escolhida: 1\n");
						adiciona(arquivo);
						break;
					case 50:
						printf("Opção escolhida: 2\n");
						break;
					case 51:
						printf("Opção escolhida: 3\n");
						break;
					case 52:
						printf("Opção escolhida: 4\n");
						break;
					default:
						printf("Opção Invalida\n");
						break;
				}
		}
	}
	fclose(arquivo);
	return 0;
}
