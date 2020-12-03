// programa que realiza diversas operações com listas

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#define max 100
int v[max],v2[max],v3[max],n=0,n2=0,n3=0;

int menu()
{
    int op;
    system("cls");
    printf("0) SAIR\n\n1) Criação da lista\n2) Ordenação\n3) Busca do valor do nó na k-ésima posição da lista\n");
    printf("4) Inclusão de um nó na k-ésima posição da lista\n5) Remoção de um nó na k-ésima posição da lista\n");
    printf("6) Procura por um determinado elemento na lista\n7) Busca recursiva por um determinado elemento na lista (ordenada)\n");
    printf("8) Inclusão de um elemento no início da lista\n9) Inclusão de um elemento no fim da lista\n");
    printf("10) Inclusão de um elemento na lista ordenada\n11) Exclusão de um elemento da lista\n");
    printf("12) Exclusão de um elemento da lista ordenada\n13) Concatenação de duas listas\n");
    printf("14) Concatenação de duas listas gerando uma terceira lista ordenada\n\nOpção (digite novamente se não for válida): \n");
    do
    {
      scanf("%d",&op);
    } while (op<0 || op>14);
    system("cls");
    return (op);
}

void desloca(int p, int op)
{
     int i;
     if (op==1) //desloca p inclusao (dir)
        for (i=n-1;i>=p-1;i--)
            v[i+1]=v[i];
     else //desloca p remoçao (esq)
          for (i=p-1;i<n;i++)
            v[i]=v[i+1];     
}

void cria()
{
     int i;
     printf("Digite o tamanho inicial da lista (max 100):\n");
     do
     {
       scanf("%d",&n);
     } while (n<0 || n>100); 
     printf("\n\nDigite a lista a seguir:\n"); 
     for (i=0; i<n; i++)
         scanf ("%d", v[i]);
}
 
void ordena()
{
     int aux, i, j;
     for(i=0;i<n-1;i++)
         for (j=i+1;j<n;j++)
             if (v[j]<v[i]) 
             {
                 aux=v[i];
                 v[i]=v[j];
                 v[j]=aux;
             }
     printf("Lista ordenada:\n");
     for (i=0;i<n;i++)
         printf ("%d | ", v[i]);
}

void buscapos()
{
     int p;
     printf ("Digite a posição:\n");
     do
     {
       scanf("%d",&p);
     } while (p<0 || p>n);
     printf("\n\nValor do nó na posição %d da lista: %d",p,v[p-1]);
     getchar();
}


void incluipos()
{
     int p;
     printf("Digite a posição em que deseja inserir o nó:\n");
     do
     {
       scanf("%d",&p);
     } while (p<0 || p>n);
     desloca(p,1);
     n++;
     printf("Digite o valor do nó:\n");
     scanf("%d", v[p-1]);
     printf ("\n\nNó inserido!");
     getchar();     
}

void removepos()
{
     int p;
     printf("Digite a posição em que deseja remover o nó:\n");
     do
     {
       scanf("%d",&p);
     } while (p<0 || p>n);
     desloca(p,0);
     n--;
     printf ("\n\nNó removido!");
     getchar();     
}

void busca()
{
     int i,x;
     printf ("Digite o valor a ser procurado: ");
     scanf("%d", &x);
     for (i=0;i<n;i++)
         if (v[i]==x)
         {
            printf("Valor encontrado na posição %d", i+1);
            getchar();
            return;
         }
     printf("\n\nValor não encontrado na lista");
     getchar();
}

int buscarecursiva(int p, int x)
{
     if (p=0)
        return printf("\n\nValor não encontrado na lista");
     if (v[p]==x)
        return  printf("Valor encontrado na posição %d", p);
     buscarecursiva(p-1,x);
}

void incluiinicio()
{
     desloca(1,1);
     n++;
     printf("Digite o valor a ser inserido:\n");
     scanf("%d", v[0]);
     printf ("\n\nElemento inserido!");
     getchar();       
}

void incluifim()
{
     n++;
     printf("Digite o valor a ser inserido:\n");
     scanf("%d", v[n-1]);
     printf ("\n\nElemento inserido!");
     getchar();       
}

void incluiordenada()
{
     int i=1,x;
     printf("Digite o valor a ser inserido:\n");
     scanf("%d", &x);
     n++;
     while (v[i-1]<=x)
           i++;
     desloca(i+1,1);
     v[i]=x;
     printf ("\n\nElemento inserido!");
     getchar();       
}

void remove()
{
     int i,x;
     printf ("Digite o elemento a ser excluído: ");
     scanf:("%d",&x);
     for (i=0;i<n;i++)
         if (v[i]==x)
         {
            desloca(i+1,0);
            n--;
         } 
     printf("\n\nExclusão realizada");
     getchar();
}

void excluiordenada()
{
     int i,x;
     printf ("Digite o elemento a ser excluído: ");
     scanf:("%d",&x);
     for (i=0;i<n;i++)
         if (v[i]==x)
         {
            desloca(i+1,0);
            n--;
         } 
     printf("\n\nExclusão realizada");
     getchar();      
}

void concatena()
{
     int i,j;
     printf("Digite o tamanho da segunda lista (max 100):\n");
     do
     {
       scanf("%d",&n2);
     } while (n<0 || n>100); 
     printf("\n\nDigite a lista a seguir:\n"); 
     for (i=0; i<n; i++)
         scanf ("%d", v2[i]);
     j=0;
     for (i=n;i<n+n2;i++)
     {
         v[i]=v2[j];
         j++;
     }
     printf("Listas concatenadas");
     getchar();
}

void concatenaemoutra()
{
     int i,j,k;
     printf("Digite o tamanho da segunda lista (max 100):\n");
     do
     {
       scanf("%d",&n2);
     } while (n<0 || n>100); 
     printf("\n\nDigite a lista a seguir:\n"); 
     for (i=0; i<n; i++)
         scanf ("%d", v2[i]);
     j=0;
     k=0;
     for (i=0;i<n+n2; i++)
     {
         if (i<n)
         {
            v3[i]=v[j];
            j++;
         }
         else
         {
            v3[i]=v2[k];
            k++; 
         }
     }
     printf("Listas concatenadas em nova lista");
     getchar();
}

int main ()
{
    int x;
     setlocale(LC_ALL, "Portuguese");
     while (1)
     {
         switch (menu())
         {
                case 1: cria();
                        break;
                case 2: ordena();
                        break;
                case 3: buscapos();
                        break;
                case 4: incluipos();
                        break;
                case 5: removepos();
                        break;
                case 6: busca();
                        break;
                case 7: printf ("Digite o valor a ser procurado: ");
                        scanf ("%d", &x);
                        buscarecursiva(n-1,x);
                        break;
                case 8: incluiinicio();
                        break;
                case 9: incluifim();
                        break;
                case 10: incluiordenada();
                         break;
                case 11: remove();
                         break;
                case 12: excluiordenada();
                         break;
                case 13: concatena();
                         break;
                case 14: concatenaemoutra();
                         break;
                case 0: exit(0);
         }
     }
}
