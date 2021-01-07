#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<ctype.h>
#include<windows.h>
#include<stdlib.h>
#define TF 100

struct TpEndereco
{
	char Rua[30], Bairro[30], Cidade[30], Estado[30], Pais[30];
	int Numero,	Cep;
};

struct TpData
{
	int Dia,Mes,Ano;	
};

struct TpAgenda
{
	char Nome[30];
	char Email[30];	
	int Telefone;
	char Observacao[100];
	TpEndereco Enderecox;
	TpData Datax;
};

void Ordena(TpAgenda Agendax[], int TL)
{
	TpAgenda Aux;
	int i;
	for(i=0;i<TL-1;i++)
	{
		if(stricmp(Agendax[i].Nome,Agendax[i+1].Nome)>0)
		{
			Aux = Agendax[i];
			Agendax[i] = Agendax[i+1];
			Agendax[i+1] = Aux;
		}
	}
}


void Cadastrando(TpAgenda Agendax[], int &TL)
{	
	system("cls");
	char AuxNome[30];
	printf("\t**Cadastro de Clientes**\n");
	printf("Nome do Cliente:\n");
	fflush(stdin);
	gets(AuxNome);
	while(TL<TF && strcmp(AuxNome,"\0")!=0)
	{
		strcpy(Agendax[TL].Nome,AuxNome);
		printf("Digite o E-mail:\n");
		fflush(stdin);
		gets(Agendax[TL].Email);
		printf("Informe o Telefone:\n");
		scanf("%d",&Agendax[TL].Telefone);
		printf("\n\t**Dados de Endereco**\n");
		printf("Rua:\n");
		fflush(stdin);
		gets(Agendax[TL].Enderecox.Rua);
		printf("Numero:\n");
		scanf("%d",&Agendax[TL].Enderecox.Numero);
		printf("Bairro:\n");
		fflush(stdin);
		gets(Agendax[TL].Enderecox.Bairro);
		printf("CEP:\n");
		scanf("%d",&Agendax[TL].Enderecox.Cep);
		printf("Cidade:\n");
		fflush(stdin);
		gets(Agendax[TL].Enderecox.Cidade);
		printf("Estado:\n");
		fflush(stdin);
		gets(Agendax[TL].Enderecox.Estado);
		printf("Pais:\n");
		fflush(stdin);
		gets(Agendax[TL].Enderecox.Pais);
		printf("\n\t**Dados de Aniversario**\n");
		printf("Data de aniversario dd/mm/aaaa:\n");
		scanf("%d%d%d",&Agendax[TL].Datax.Dia,&Agendax[TL].Datax.Mes,&Agendax[TL].Datax.Ano);
		
		TL++;
		Ordena(Agendax,TL);
		if(TL<TF)
		{
			system("cls");
			printf("\tCadastro de Clientes**\n");
			printf("Nome do Cliente:\n");
			fflush(stdin);
			gets(AuxNome);
		}
	}
}

void Relatorio(TpAgenda Agendax[], int TL)
{
	int i;
	for(i=0;i<TL;i++)
	{
		printf("\n\t ****RELATORIO DE CLIENTES****\n");
		printf("Nome: %s\t E-mail: %s\t Telefone: %d\n", Agendax[i].Nome,Agendax[i].Email,Agendax[i].Telefone);
		printf("Rua: %s\t Num: %d\t Bairro: %s\n", Agendax[i].Enderecox.Rua,Agendax[i].Enderecox.Numero,Agendax[i].Enderecox.Bairro);
		printf("CEP: %d\t Cidade: %s\t Estado: %s\t Pais: %s\n", Agendax[i].Enderecox.Cep,Agendax[i].Enderecox.Cidade,Agendax[i].Enderecox.Estado,Agendax[i].Enderecox.Pais);
		printf("Aniversario: %d/%d/%d\n",Agendax[i].Datax.Dia,Agendax[i].Datax.Mes,Agendax[i].Datax.Ano);	
	}
}

void Buscando(TpAgenda Agendax[], int TL, char AuxNome[])
{
	int i, achou=0;
	for(i=0;i<TL;i++)
	{
		if(stricmp(Agendax[i].Nome,AuxNome)==0)
		{
			achou=1;
			printf("Nome: %s\t E-mail: %s\t Telefone: %d\n", Agendax[i].Nome,Agendax[i].Email,Agendax[i].Telefone);
		}
	}
	if(achou==0)
		printf("Nome Nao Encontrado!\n");
}

void BuscaNome (TpAgenda Agendax[], int TL)
{
	system("cls");
	char AuxNome[30];
	printf("\t**PESQUISA POR NOME**\n");
	printf("Digite o nome a ser consultado:\n");
	fflush(stdin);
	gets(AuxNome);
	while(strcmp(AuxNome,"\0")!=0)
	{
		Buscando(Agendax,TL,AuxNome);
		
		printf("Digite o nome a ser consultado:\n");
		fflush(stdin);
		gets(AuxNome);
	}
}

void BuscaMes(TpAgenda Agendax[], int AuxMes, int TL)
{
	system("cls");
	int i, achou=0;
	for(i=0; i<TL; i++)
	{
		if(AuxMes==Agendax[i].Datax.Mes)
		{
			achou=1;
			printf("Nome: %s\t E-mail: %s\t Telefone: %d\n", Agendax[i].Nome,Agendax[i].Email,Agendax[i].Telefone);
			printf("Aniversario: %d/%d/%d\n",Agendax[i].Datax.Dia,Agendax[i].Datax.Mes,Agendax[i].Datax.Ano);	
		}
	}
	if(achou==0)
		printf("Nenhum cliente faz aniversario neste mes!\n");
}

void Aniversario(TpAgenda Agendax[], int TL)
{
	int AuxMes;
	system("cls");
	printf("\t**BUSCA POR MES DE ANIVERSARIO**\n");
	printf("Digite o mes mm:\n");
	scanf("%d",&AuxMes);
	while(AuxMes>0 && AuxMes<=12)
	{
		BuscaMes(Agendax,AuxMes,TL);
		  
		printf("Digite o mes mm:\n");
		scanf("%d",&AuxMes);
	}
}


int Excluir(TpAgenda Agendax[], int TL, char AuxNome[])
{
	int i=0;
	while(i<TL && stricmp(AuxNome,Agendax[i].Nome)!=0)
		i++;
	if(i<TL)
		return i;
	else
		return -1;
}

void Remove(TpAgenda Agendax[], int &TL)
{
	char AuxNome[30];
	int pos,i;
	printf("Digite o Cliente a ser Excluido:\n");
	fflush(stdin);
	gets(AuxNome);
	while(strcmp(AuxNome,"\0")!=0)
	{
		pos = Excluir(Agendax,TL,AuxNome);
		if(pos>=0)
		{
			for(i=pos;i<TL-1;i++)
				Agendax[i]=Agendax[i+1];
			TL--;
			printf("Excluido com sucesso!\n");
		}
		else
			printf("Nao encontramos nenhum cliente com este nome!\n");
		printf("Digite o Cliente a ser Excluido:\n");
		fflush(stdin);
		gets(AuxNome);
	}
}

char Menu(void)
{
	system("cls");
	printf("******MENU*******\n");
	printf("[A]-Cadastrar\n");
	printf("[B]-Procurar por Nome\n");
	printf("[C]-Relatorio\n");
	printf("[D]-Procurar por Mes\n");
	printf("[E]-Excluir Cliente\n");
	return toupper(getch());
}

int main()
{
	TpAgenda Agendax[TF];
	int TL=0;
	char Opcao;
	do
	{
		Opcao=Menu();
		
		switch(Opcao)
		{
			case 'A': system("cls");
					  Cadastrando(Agendax,TL);
				break;
			case 'B': system("cls");
						if(TL==0)
							printf("Nenhum Cliente Cadastrado!\n");
						else
							BuscaNome(Agendax,TL);
						getch();
				break;
			case 'C': system("cls");
						if(TL==0)
							printf("Nenhum Cliente Cadastrado!\n");
						else
							Relatorio(Agendax,TL);
						getch();
				break;	
			case 'D': system("cls");
						if(TL==0)
							printf("Nenhum Cliente Cadastrado!\n");
				    	else
						   	Aniversario(Agendax,TL);
						getch();
				break;
			case 'E': system("cls");
						Remove(Agendax,TL);
				break;
		}
	}while(Opcao!=27);
	
}
