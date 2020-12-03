// o programa funciona como uma agenda de compromissos salva em arquivo externo .txt

#include <stdio.h>
#include <conio.c>
#include <conio.h>
#include <stdlib.h>
#include <locale.h>
FILE *arq;

typedef struct reg *no;
struct reg
{
       char comp[81];
       int dia,mes,ano,hora,min;
       struct reg *prox;
};

void abrearq(int x)
{
     char s[5];
     if (x)
        strcpy(s,"w");
     else 
          strcpy(s,"r");
     if ((arq=fopen("agenda.txt",s))==NULL)
     {
       printf("\nErro ao abrir/criar arquivo de agenda!\n");
       exit(1);
     }
}

void criaagenda (no *agenda) 
{
     *agenda = NULL;
} 

int letecla(int *lin)
{
    const int 
      cima=72,baixo=80,setas=224,func=0,enter=13;
    int tec;
    fflush(stdin);
    tec = getch();
    if (tec == setas||tec == func)
    {
       fflush(stdin);
       tec = getch();
       switch (tec)
       {
           case cima: *lin-=1; printf("cima");
                      return -1;
                      break;
           case baixo:*lin+=1; printf("baixo");
                      return -1;
                      break;
           default:   return -1;
       }
    }
    else if (tec==enter)
    {
         clrscr();
         gotoxy(1,1);
         return *lin;
    }
    else return -1;
}

void aguarda(char s[])
{
     printf("\n\n\n%s",s);
     printf("\n\n\nPRESSIONE QUALQUER TECLA PARA VOLTAR AO MENU");
     getch();
}

int menorigual(no q, no p)
{
    if (q->ano < p->ano)
       return 1;
    else if (q->ano > p->ano)
         return 0;
    else if (q->mes < p->mes)
         return 1;
    else if (q->mes > p->mes)
         return 0;
    else if (q->dia < p->dia)
         return 1;
    else if (q->dia > p->dia)
         return 0;
    else if (q->hora < p->hora)
         return 1;
    else if (q->hora > p->hora)
         return 0;    
    else if (q->min < p->min)
         return 1;
    else if (q->min > p->min)
         return 0;
    else return 1;
}

void insere(no *agenda, no p)
{
    if (!*agenda) //no começo da lista
     {
        *agenda=p;
        return;
     }
     no q=*agenda; //end que vai apontar pra p ou o contrario
     if (!q->prox && menorigual(q,p)==1) //so tem um na lista e adiciona na frente
     {
        q->prox=p;
        return;
     }
     if (menorigual(q,p)==0) //ja vai ser o primeiro da lista
     {
        *agenda=p;
        p->prox=q;
        return;
     } 
     //a partir daqui vai estar no meio ou no final
     no r=*agenda; //guarda o end que p vai apontar
     while (q->prox)
     {
           q=q->prox;
           if (menorigual(q,p)==0) //se q ainda nao ta no fim e p entra no meio
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

void leparainserir(no *agenda)
{
     no p = (no) malloc(sizeof(struct reg));
     p->prox=NULL; 
     printf("DATA (digite assim: DD/MM/AAAA):\n");
     scanf("%d/%d/%d",&p->dia,&p->mes,&p->ano);
     printf("\nHORA (digite assim: HH:MM):\n");
     scanf("%d:%d",&p->hora,&p->min);
     printf("\nCOMPROMISSO:\n");   
     fflush(stdin);
     gets(p->comp);
     insere(agenda,p);
     aguarda("COMPROMISSO SALVO!");
}

void remove(no *agenda)
{
     int d,m,a,r=0;
     printf("DATA DE REMOÇÃO (digite assim: DD/MM/AAAA):\n");
     scanf("%d/%d/%d",&d,&m,&a);
     if (*agenda)
     {
         no p = *agenda;
         while (p->dia==d && p->mes==m && p->ano==a) //se o dia ja esta no começo da lista
         {
               *agenda = p->prox;
               free (p);
               r=1;
               if (!*agenda)
                  break;
               p = *agenda;
         }
         if (!r)
         {
                no q = *agenda; //se o dia estiver no meio da lista, q salva o proximo
                if (q->prox)
                   p=q->prox;
                else
                    p=NULL;
                while (p)
                {
                      if (p->dia==d && p->mes==m && p->ano==a)
                      {
                         q->prox=p->prox;
                         free (p);
                         if (!q->prox)
                            break;
                         p=q->prox;
                         r=1;
                      }   
                      else if (!r)
                      {
                           q=p;
                           p=q->prox;
                      }
                      else
                         break;          
               }
         }
     }
     if (r)
        aguarda("COMPROMISSOS REMOVIDOS COM SUCESSO!");
     else
         aguarda("SEM COMPROMISSOS PARA REMOVER!");
}

void consulta(no agenda)
{
      int d,m,a,c=0;
      printf("DATA DE PROCURA (digite assim: DD/MM/AAAA):\n");
      scanf("%d/%d/%d",&d,&m,&a);
      no p = agenda;
      while (p) 
      {
          if (p->dia==d && p->mes==m && p->ano==a)
          {
             printf ("\n\n%02d:%02d\n%s",p->hora,p->min,p->comp);
             c=1;
          }
          p = p->prox;
      }
      if (c)
         aguarda("COMPROMISSOS LISTADOS!");
      else
          aguarda("SEM COMPROMISSOS PARA LISTAR!");
}

void procuraporpalavra(no agenda)
{
     char s[81];
     int a=0;
     printf("Digite a palavra a ser procurada (maiúscula/acentuação faz diferença): \n");
     fflush(stdin);
     gets(s);
     no p = agenda;
     while (p) 
     {
           if (strstr(p->comp,s))
           {
              a=1;
              printf ("\n\n%02d/%02d/%04d  %02d:%02d\n%s",p->dia,p->mes,p->ano,p->hora,p->min,p->comp);
           }
           p = p->prox;
     }
     if (a)
        aguarda("COMPROMISSOS LISTADOS!");
     else
         aguarda("SEM COMPROMISSOS PARA LISTAR!");
}

void salvadisco(no agenda)
{
     no p = agenda;
     abrearq(1);
     while (p)
     {
           fprintf (arq,"\n%d %d %d %d %d %s",p->dia,p->mes,p->ano,p->hora,p->min,p->comp);
           p=p->prox;     
     }
     fclose(arq);
     aguarda("ARQUIVO SALVO COM SUCESSO!");
}

void ledoarq(no *agenda)
{
         no p = (no) malloc(sizeof(struct reg));
         p->prox=NULL;
         fscanf (arq,"%d %d %d %d %d %[^\n]s",&p->dia,&p->mes,&p->ano,&p->hora,&p->min,p->comp);
         insere (agenda,p);
}

void ledisco(no *agenda)
{
     abrearq(0);
     while (!feof(arq))
           ledoarq(agenda);
     fclose(arq);
     aguarda("ARQUIVO LIDO COM SUCESSO!");
}

int menu(int lin)
{
    int op,col=2;
    clrscr();
    gotoxy(1,1);
    printf("[ ] - INSERIR COMPROMISSO NA AGENDA\n[ ] - REMOVER COMPROMISSO DA AGENDA\n[ ] - CONSULTAR COMPROMISSOS DA AGENDA\n[ ] - PROCURAR COMPROMISSOS DA AGENDA POR PALAVRA\n[ ] - SALVAR COMPROMISSOS EM DISCO\n[ ] - LER COMPROMISSOS SALVOS EM DISCO\n[ ] - SAIR");
    gotoxy(col,lin);
    textcolor(12);
    printf("X");
    textcolor(7);
    gotoxy(col,lin);
    op=letecla(&lin);
    if (lin<1)
       lin=7;
    else if (lin>7)
       lin=1;
    if (op==-1)
       menu(lin);
}

int main ()
{
     setlocale(LC_ALL, "Portuguese");
     no agenda;
     criaagenda (&agenda);
     while (1)
     {
         switch (menu(1))
         {
                case 1: leparainserir(&agenda); //ok
                        break;
                case 2: remove(&agenda); //ok
                        break;
                case 3: consulta(agenda);
                        break;
                case 4: procuraporpalavra(agenda); //
                        break;
                case 5: salvadisco(agenda);
                        break;
                case 6: ledisco(&agenda);
                        break;
                case 7: exit(0);
         }
     }    
}
