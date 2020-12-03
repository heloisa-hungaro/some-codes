// o sistema utiliza lista encadeada para simular o atendimento de pacientes em um pronto socorro, levando em conta o estado do paciente além da ordem de chegada

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <ctype.h>
typedef struct reg *no;
struct reg
{
       char nome[50], est; //A-pessimo B-ruim C-regular
       struct reg *prox;
};


int menu()
{
    int op;
    do
    {
		system("cls");
    	printf("0 - SAIR\n\n1 - Adicionar paciente\n2 - Chamar paciente\n\n\nOpção (digite novamente se não for válida): \n");
    	scanf("%d",&op);
    } while (op<0 || op>2);
    system("cls");
    return (op);
}


void cria_lista (no *lista) 
{
     *lista = NULL;
} 

void chama (no *lista) 
{
     if (!*lista)
        printf("SEM NOVOS PACIENTES!");
     else
     {
         no p = *lista;
         printf("PACIENTE: %s",p->nome);
         *lista = p->prox;
         free (p);
     }
     fflush(stdin);
     getchar();    
}


void inclui(no *lista)
{
     no p = (no) malloc(sizeof(struct reg));
     p->prox=NULL; 
     printf("Nome:\n");
     fflush(stdin);
     gets(p->nome);
     printf("\n\nEstado (A - PÉSSIMO; B - RUIM; C - REGULAR)\n");
     do
     {
       scanf("%c",&p->est);
     } while (toupper(p->est)!='A' && toupper(p->est)!='B' && toupper(p->est)!='C');       
     if (!*lista) //no começo da lista
     {
        *lista=p;
        return;
     }
     no q=*lista; //end que vai apontar pra p ou o contrario
     if (!q->prox && q->est<=p->est) //so tem um na lista e adiciona na frente
     {
        q->prox=p;
        return;
     }
     if (q->est > p->est) //ja vai ser o primeiro da lista
     {
        *lista=p;
        p->prox=q;
        return;
     } 
     //a partir daqui vai estar no meio ou no final
     no r=*lista; //guarda o end que p vai apontar
     while (q->prox)
     {
           q=q->prox;
           if (q->est > p->est) //se q ainda nao ta no fim e p entra no meio
           {
              r->prox=p;
              p->prox=q;
              return;
           }
           r=r->prox;
     }
     //aqui q ta no fim, entao vai apontar pra p
     q->prox=p;      
}


int main ()
{
     setlocale(LC_ALL, "Portuguese");
     no lista;
     cria_lista (&lista);
     while (1)
     {
         switch (menu())
         {
                case 1: inclui(&lista);
                        break;
                case 2: chama(&lista);
                        break;
                case 0: exit(0);
         }
     }
}
