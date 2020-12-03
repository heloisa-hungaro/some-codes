#include <stdio.h>
#include <string.h>

typedef struct pilha_dinamica *no;
struct pilha_dinamica 
{
        char dado;
        no prox;
};

void inicializar(no *p)
{
     *p=NULL;
}

void push(no *p, char c)
{
     no q=(no) malloc(sizeof(struct pilha_dinamica));
     q->dado=c;
     if (!p)
         q->prox=NULL;
     else
         q->prox=*p;
     *p=q;
}

char pop(no *p)
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
    int i;
    char s[100];
    inicializar(&pilha);
    printf("Digite a frase:\n");
    gets(s);
    for (i=0;i<strlen(s);i++)
        push(&pilha,s[i]);
    printf("\nFrase invertida: \n");
    while (pilha)
          printf("%c",pop(&pilha));
    fflush(stdin);
    getchar();
}
