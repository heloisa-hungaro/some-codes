#include <stdio.h>
typedef struct pilha_dinamica *no;

struct pilha_dinamica 
{
        int dado;
        no prox;
};

void inicializar(no *p)
{
     *p=NULL;
}

void push(no *p, int c)
{
     no q=(no) malloc(sizeof(struct pilha_dinamica));
     q->dado=c;
     if (!p)
         q->prox=NULL;
     else
         q->prox=*p;
     *p=q;
}

int pop(no *p)
{
     char c;
     if (!*p) 
     {
        printf("UNDERFLOW!");
        exit(1);
     }
     c=(*p)->dado;
     if (!(*p)->prox)
     {
        free(*p);
        *p=NULL;
        return (c);
     }
     no q;
     q=*p;
     *p=q->prox;
     free(q);
     return (c);
}

int main ()
{
    no pilha;
    int x;
    inicializar(&pilha);
    printf("Digite o numero:\n");
    scanf("%d",&x);
    while (x>1)
    {
          push(&pilha,(x%2));
          x=(int)(x/2);
    }   
    push(&pilha,x);
    printf("\nBinario: \n");
    while (pilha)
          printf("%d",pop(&pilha));
    fflush(stdin);
    getchar();
}
