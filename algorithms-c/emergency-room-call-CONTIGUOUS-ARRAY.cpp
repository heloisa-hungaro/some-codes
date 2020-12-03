// o sistema utiliza lista contígua para simular o atendimento de pacientes em um pronto socorro, levando em conta o estado do paciente além da ordem de chegada


#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <ctype.h>
#include <string.h>
#define max 100
struct campos
{
       char nome[50], est; //A-pessimo B-ruim C-regular
} p[max];
int n=0;

int menu()
{
    int op;
    system("cls");
    printf("0 - SAIR\n\n1 - Adicionar paciente\n2 - Chamar paciente\n\n\nOpção (digite novamente se não for válida): \n");
    do
    {
      scanf("%d",&op);
    } while (op<0 || op>2);
    system("cls");
    return (op);
}

void desloca(int x, int op)
{
     int i;
     if (op==1) //desloca p inclusao (dir)  
        for(i=n-1;i>=x;i--)
            p[i+1]=p[i]; 
     else //desloca p chamada (esq)
          for (i=x;i<n;i++)
            p[i]=p[i+1];    
}

void inclui()
{
     struct campos x;
     int i=0;
     printf("Nome:\n");
     fflush(stdin);
     gets(x.nome);
     printf("\n\nEstado (A - PÉSSIMO; B - RUIM; C - REGULAR)\n");
     do
     {
       scanf("%c",&x.est);
     } while (toupper(x.est)!='A' && toupper(x.est)!='B' && toupper(x.est)!='C');
     if (n>0)
     {
         while (toupper(p[i].est)<=toupper(x.est) && i<n)
               i++;
         printf("%d",i);
         desloca(i,1);
     }
     p[i]=x;
     n++;
}

void chama()
{
     if (n==0)
        printf("SEM NOVOS PACIENTES!");
     else
     {
         printf("PACIENTE: %s",p[0].nome);
         desloca(0,0);
         n--;
     }
     fflush(stdin);
     getchar();
}

int main ()
{
     setlocale(LC_ALL, "Portuguese");
     while (1)
     {
         switch (menu())
         {
                case 1: inclui();
                        break;
                case 2: chama();
                        break;
                case 0: exit(0);
         }
     }
}
