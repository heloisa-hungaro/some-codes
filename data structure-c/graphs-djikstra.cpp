//AUTORA: Heloisa Hungaro Primolan
//dez-2015

// manipulação de grafos e algoritmo de Djikstra

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <conio.h>
#include <limits.h>
#define max 100


typedef struct reg *no; 
struct reg
{
		int vertice;
		unsigned long int peso;
		unsigned char marcado;
		struct reg *prox;
};


int menu()
{
    int op;
    do
    {
		system("cls");
    	printf("***TRABALHO ED2 2015 - por Heloisa Hungaro (RA 141026431)***\n\n\n\n0 - SAIR\n\n1 - Nova lista de adjacência (NECESSÁRIO)\n2 - Mostrar lista de adjacência\n3 - Busca em profundidade\n4 - Ordenação topológica\n5 - Dijkstra\n\n\nOpção (entre 0 e 5): \n");
    	scanf("%d",&op);
    } while (op<0 || op>5);
    system("cls");
    return (op);
}


void tipo_lista(unsigned char *tipo)
{
	int op;
    do
    {
		system("cls");
    	printf("Escolha o tipo de grafo a ser criado:\n\n1 - GRAFO PONDERADO\n2 - GRAFO NÃO PONDERADO\n\n\nOpção (entre 1 e 2): \n");
    	scanf("%d",&op);
    } while (op!=1 && op!=2);
    system("cls");
    *tipo=op-1;
}


void cria_lista (no lista) 
{
    lista = NULL;
} 


void mostra_lista(no listas[], int n, unsigned char tipo)
{
	int i;
	no q;
	printf("LISTA DE ADJACÊNCIA:\n\n");
	for (i=1;i<=n;i++)
	{
		q=listas[i]; //no para caminhar pela lista
		printf(" %d ->", q->vertice);
		q=q->prox;
		while (q)
		{
			if (tipo==0)
				printf(" %d [%d] ->", q->vertice, q->peso);
			else 
				printf(" %d ->", q->vertice);
		    q=q->prox;
		}
		printf(" /\n");
	}	
	printf("\n\n\n***PRESSIONE QUALQUER TECLA PARA VOLTAR AO MENU***");
	getch();
}


void limpa_lista(no listas[], int n)  // limpa lista de adjacencia para criar nova lista
{
	int i;
	no p,q;
	for (i=1;i<=n;i++)
	{
		q=listas[i]; //no para caminhar pela lista
		while (q->prox)
		{
			p=q;
		    q=q->prox;
		    free(p);
		}
		free(q);
	}	
}


void inclui_na_lista(no lista, int vert, unsigned long int pes)
{
	no p = (no) malloc(sizeof(struct reg));
	p->prox=NULL;
	p->vertice=vert;
	p->marcado=0; 
	p->peso=pes;
	no q=lista; //no para caminhar pela lista
	while (q->prox)
	   q=q->prox;
	q->prox=p; //adiciona vertice no final da lista
}


void nova_lista(no listas[], unsigned char *temlista, int *n, unsigned char tipo)
{
	if (*temlista==1)
		limpa_lista(listas, (*n));
	do
	{	
		system("cls");
		printf("Quantidade de vértices do grafo (entre 1 e 100): ");
		scanf("%d",n);
		printf("\n\n");
		printf("OBS: Digite o valor -1 para CANCELAR a inserção de dados.\n     Digite o valor 0 para finalizar uma lista.\n     Somente serão aceitos vértices existentes.\n\n\n");
	}
	while ((*n)<1 || (*n)>100);
	int i, j, vert=0, aux[(*n)+1];
	unsigned long int pes=0;
	no p;
	for (i=1; i<=(*n); i++)
	{
		for (j=1; j<=(*n); j++)
			aux[j]=0;
		printf("*LISTA DE ARESTAS DO VÉRTICE %d\n\n",i);	
		cria_lista(listas[i]);
		p = (no) malloc(sizeof(struct reg));
		p->prox=NULL;
		p->vertice=i;
		p->marcado=0; 
		p->peso=0;
		listas[i]=p;
		do
		{
			printf("%d -> ", i);
			scanf("%d",&vert);	
			if (vert==-1)
			{
				*temlista=0;
				return;
			}
			if ((vert>0) && (vert<=(*n)))
			{
				if (aux[vert]==0)
				{
					if (tipo==0)
					{
						printf("Peso da aresta (>0): ");
						scanf("%d", &pes);
						while (pes<=0)
						{
							printf("Peso inválido! Redigite (>0): ");
							scanf("%d", &pes);
						}
						inclui_na_lista(listas[i],vert,pes);
					}
					else inclui_na_lista(listas[i],vert,0);
						
					aux[vert]=1;
				}
				else if (aux[vert]==1)
					printf("^ ARESTA JÁ INCLUSA!\n");
			}
			else if (vert!=0)
				printf("^ AÇÃO INVÁLIDA!\n");
		} while (vert!=0);
	printf("\n\n");
	}
	*temlista=1;
	printf("***PRESSIONE QUALQUER TECLA PARA VOLTAR AO MENU***");
	getch();
}


void desmarca_todos(no listas[], int n)
{
	int i;
	no q;
	for (i=1;i<=n;i++)
	{
		q=listas[i]; //no para caminhar pela lista
		while (q)
		{
			q->marcado=0;	
		    q=q->prox;
		}
	}	
}


void busca_profundidade(no listas[], int n, no p)
{
	if (p->marcado==0)
	{
		p->marcado=1;	
		printf("%d ", p->vertice);
	}
	while (p->prox)
	{
		p=p->prox;
		p->marcado=1;
		if (listas[(p->vertice)]->marcado==0)
			busca_profundidade(listas,n,listas[p->vertice]);	
	}
}


void busca(no listas[], int n)
{
	int ini;
	desmarca_todos(listas,n);
	do
	{
		printf("Digite o vértice origem (entre 1 e %d): ",n);
		scanf("%d", &ini);
	} while (ini<1 || ini>n);
	printf("\n\nNÓS VISITADOS:\n\n");
	busca_profundidade(listas,n,listas[ini]);
	printf("\n\n\n***PRESSIONE QUALQUER TECLA PARA VOLTAR AO MENU***");
	getch();
}


void dijkstra(no listas[], int n)
{
	int i, ini, dist[n+1], pred[n+1];
	unsigned char marcado[n+1];
	for (i=1;i<=n;i++)
	{
		dist[i]=ULONG_MAX;
		marcado[i]=0;
		pred[i]=0;
	}
	do
	{
		system("cls");
		printf("Digite o vértice origem (entre 1 e %d): ",n);
		scanf("%d", &ini);
	} while (ini<1 || ini>n);
	printf("\n\n");
	dist[ini]=0;
	int v, j;
	no q;
	unsigned long int menor;//v=vertice em que está, d = dist 
	for (i=1;i<=n;i++)
	{
		menor=ULONG_MAX;
		for (j=1;j<=n;j++)
		{
			if ((dist[j]<menor) && (marcado[j]==0))
			{
				menor=dist[j];
				v=j;
			}
		}
		q=listas[v]; //no para caminhar pela lista de arestas de v
		q=q->prox;
		while (q)
		{
			if (dist[q->vertice]>dist[v]+(q->peso))
			{
				dist[q->vertice]=dist[v]+(q->peso);
				pred[q->vertice]=v;
			}
		    q=q->prox;
		}
		if (pred[v]!=0 && marcado[v]==0)	
		{
			printf ("Vértice: %d\nDistância: %d\nPredecessor: %d\n\n",v,dist[v],pred[v]);	
		}
		marcado[v]=1;	
	}
	for (i=1;i<=n;i++)
	{
		if (pred[i]==0 && i!=ini)
			printf("Não há caminho de %d a %d!\n\n",ini,i);
	}
	printf("\n***PRESSIONE QUALQUER TECLA PARA VOLTAR AO MENU***");
	getch();
}


void ordena_e_verifica(no listas[], int n, int *acic, int ordenado[])
{
	int grau[n+1],i,j,cont=0, contanterior;
	no q;
	
	for (i=1;i<=n;i++)
	{
		grau[i]=0;
		ordenado[i]=0;
	}
	for (i=1;i<=n;i++)
	{
		q=listas[i]; //no para caminhar pela lista
		q=q->prox;
		while (q)
		{
			grau[q->vertice]++;
		    q=q->prox;
		}
	}
	while (cont<n)
	{
		contanterior=cont;
		for (i=1;i<=n;i++)
		{
			if (grau[i]==0)
			{
				grau[i]=-1;
				cont++;
				ordenado[cont]=i;
			}
		}
		if (cont==contanterior)
		{
			*acic=0;
			return;
		}
		for (i=contanterior+1;i<=cont;i++)
		{
			q=listas[ordenado[i]]; //no para caminhar pela lista
			q=q->prox;
			while (q)
			{
				grau[q->vertice]--;
			    q=q->prox;
			}
		}
	}
}


void ordenacao_topologica(no listas[],int n)
{
	int aciclico=1,ordenado[n+1],i;
	ordena_e_verifica(listas,n,&aciclico,ordenado);
	if (aciclico==0)
	{
		printf("GRAFO DEVE SER ACÍCLICO PARA EXECUTAR ESTA OPERAÇÃO!\n\n\n***PRESSIONE QUALQUER TECLA PARA VOLTAR AO MENU***");
		getch();
		return;
	}
	printf("UMA DAS ORDENAÇÕES TOPOLÓGICAS POSSÍVEIS PARA O GRAFO DADO É:\n\n{");
	for (i=1;i<n;i++)
	{
		printf("%d, ", ordenado[i]);
	}
	printf("%d}\n\n\n***PRESSIONE QUALQUER TECLA PARA VOLTAR AO MENU***", ordenado[i]);
	getch();
}


int main ()
{	
    setlocale(LC_ALL, "Portuguese");
    no listas[max];
    int n, sai=0;
    unsigned char temlista=0, tipolista; //tipolista=0: grafo ponderado; tipolista=1: grafo nao ponderado
    while (sai==0)
    {
        switch (menu())
        {
                case 1: tipo_lista(&tipolista);
						nova_lista(listas, &temlista, &n, tipolista);
                        break;
                case 2: if (temlista==0)
                		{
                			printf("LISTA VAZIA\n\n\n***PRESSIONE QUALQUER TECLA PARA VOLTAR AO MENU***");
							getch();
						}
						else
							mostra_lista(listas,n,tipolista);
                        break;
                case 3: if (temlista==0)
                		{
                			printf("CRIE UMA LISTA DE ADJACÊNCIA PARA EXECUTAR ESTA OPERAÇÃO!\n\n\n***PRESSIONE QUALQUER TECLA PARA VOLTAR AO MENU***");
							getch();
						}
						else
							busca(listas,n);
                        break;
                case 4: if (temlista==0)
                		{
                			printf("CRIE UMA LISTA DE ADJACÊNCIA PARA EXECUTAR ESTA OPERAÇÃO!\n\n\n***PRESSIONE QUALQUER TECLA PARA VOLTAR AO MENU***");
							getch();
						}
						else
							ordenacao_topologica(listas,n);
                        break;
                case 5: if (temlista==0)
                		{
                			printf("CRIE UMA LISTA DE ADJACÊNCIA PARA EXECUTAR ESTA OPERAÇÃO!\n\n\n***PRESSIONE QUALQUER TECLA PARA VOLTAR AO MENU***");
							getch();
						}
						else if (tipolista==1)
						{
							printf("O GRAFO DEVE SER PONDERADO PARA EXECUTAR ESTA OPERAÇÃO!\n\n\n***PRESSIONE QUALQUER TECLA PARA VOLTAR AO MENU***");
							getch();
						}
						else
							dijkstra(listas,n);
                        break;
                case 0: sai=1;
    	}
    }
}
