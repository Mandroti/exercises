#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<windows.h>
#include<stdlib.h>
#include<conio.h>

#define TF 100
struct Data
{
	int Dia,Mes,Ano;
};

struct TpFuncionarios
{
	char Nome[30], Sexo, Cargo[30];
	int Idade, Cpf, Setor;
	Data Datax;
};

char Menu(void)
{
	printf("\t****MENU****\n");
	printf("[A]-Inserir dados\n");
	printf("[B]-Mostrar dados\n");
	printf("[C]-Procurar Funcionario por Nome\n");
	printf("[D]-Funcionarios Masculinos\n");
	printf("[E]-Funcionarios Femininos\n");
	printf("[ESC]-Sair\n");
	
	return toupper(getch());
}

void InsercaoDados(TpFuncionarios Funcx[], int &TL)
{
	char AuxNome[30], Aux;
	system("cls");
	printf("\t****CADASTRO DE FUNCIONARIOS****\n");
	printf("Informe nome:\n");
	fflush(stdin);
	gets(AuxNome);
	while(TL<TF && strcmp(AuxNome,"\0")!=0)
	{
		strcpy(Funcx[TL].Nome,AuxNome);
		printf("Idade:\n");
		scanf("%d",&Funcx[TL].Idade);
		printf("Data de Nascimento:\n");
		scanf("%d%d%d",&Funcx[TL].Datax.Dia,&Funcx[TL].Datax.Mes,&Funcx[TL].Datax.Ano);
		printf("Informe o CPF:\n");
		scanf("%d",&Funcx[TL].Cpf);
		printf("Sexo (F|M):\n");
		fflush(stdin);
		scanf("%c",&Aux);
		Aux = toupper(Aux);
		Funcx[TL].Sexo = Aux;
		printf("Cargo Ocupado:\n");
		fflush(stdin);
		gets(Funcx[TL].Cargo);
		printf("Codigo do Setor:\n");
		scanf("%d",&Funcx[TL].Setor);
		TL++;
		printf("\nFuncionario Cadastrado!\n");
		Sleep(500);
		
		if(TL<TF)
		{
			system("cls");
			printf("\t****CADASTRO DE FUNCIONARIOS****\n");
			printf("Informe nome:\n");
			fflush(stdin);
			gets(AuxNome);
		}
	}
	system("cls");
}

void Mostra (TpFuncionarios Funcx[], int TL)
{
	int i;
	system("cls");
	printf("\t****RELATORIO DE FUNCIONARIOS****\n");
	for(i=0;i<TL;i++)
		printf("Funcionario: %s\t Cargo|Funcao: %s\t Setor Pertencente: %d\n",Funcx[i].Nome,Funcx[i].Cargo,Funcx[i].Setor);
}

int BuscaNome(TpFuncionarios Funcx[], int TL, char AuxN[])
{
	int i,j, auxJ=0, cont=0;
	char aux[30];
	for(i=0; i<TL; i++)
	{
		for(j=0; j<strlen(AuxN) && (Funcx[i].Nome[j]!= ' '); j++)
		{
				aux[auxJ++] = Funcx[i].Nome[j];
		}
		aux[auxJ] = '\0';
		auxJ=0;
		if(stricmp(AuxN,aux)==0)
		{
			printf("Nome: %s\t Cargo: %s\n", Funcx[i].Nome,Funcx[i].Cargo);
			cont++;	
		}
	}
	return cont;
	
}

void ProcuraNome(TpFuncionarios Funcx[], int TL)
{
	char AuxNome[30];
	int pos;
	printf("\t****PESQUISA POR FUNCIONARIO****\n");
	printf("Digite o nome a ser procurado:\n");
	fflush(stdin);
	gets(AuxNome);
	while(strcmp(AuxNome,"\0")!=0)
	{
		pos = BuscaNome(Funcx,TL,AuxNome);
		if(pos==0)
			printf("Nome nao existe!\n");
			
		printf("Digite o nome a ser procurado:\n");
		fflush(stdin);
		gets(AuxNome);
	}
	system("cls");
}

void FuncionariosM(TpFuncionarios Funcx[], int TL)
{
	int cont=0;
	printf("\t****HOMENS NA EMPRESA****\n");
	for(int i=0;i<TL;i++)
	{
		if(Funcx[i].Sexo=='m' || Funcx[i].Sexo=='M')
		{
			printf("Funcionario: %s\t Cargo|Funcao: %s\t Setor Pertencente: %d\n",Funcx[i].Nome,Funcx[i].Cargo,Funcx[i].Setor);
			cont++;
		}
	}
	if(cont==0)
			printf("Nao ha homens na empresa!\n");
	getch();
	system("cls");
}

void FuncionariosF(TpFuncionarios Funcx[], int TL)
{
	int cont=0;
	printf("\t****MULHERES NA EMPRESA****\n");
	for(int i=0;i<TL;i++)
	{
		if(Funcx[i].Sexo=='f' || Funcx[i].Sexo=='F')
		{
			cont++;
			printf("Funcionario: %s\t Cargo|Funcao: %s\t Setor Pertencente: %d\n",Funcx[i].Nome,Funcx[i].Cargo,Funcx[i].Setor);
		}
	}
	if(cont==0)
		printf("Nao ha mulheres na empresa!\n");
	getch();
	system("cls");
}

int main()
{
	TpFuncionarios Funcx[TF];
	char op;
	int TL=0;
	do
	{
		op=Menu();
		system("cls");
		switch(op)
		{
			case 'A': InsercaoDados(Funcx,TL);
				break;
				
			case 'B':	if(TL==0)
							printf("Nenhum funcionario foi cadastrado!\n");
						else
							Mostra(Funcx,TL);
						getch();
						system("cls");
				break;
				
			case 'C':	if(TL==0)
							printf("Nenhum funcionario foi cadastrado!\n");
						else
							ProcuraNome(Funcx,TL);
				break;
				
			case 'D':	if(TL==0)
							printf("Nenhum funcionario foi cadastrado!\n");
						else
							FuncionariosM(Funcx,TL);
				break;
						
			case 'E': 	if(TL==0)
							printf("Nenhum funcionario foi cadastrado!\n");
						else
							FuncionariosF(Funcx,TL);
				break;
		}	
	}while(op!=27);
	
}
