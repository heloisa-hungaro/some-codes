/* Heloisa Hungaro Primolan RA 141026431 */

/* PROBLEMA 10010 - UVa */

/* O problema é encontrar palavras em um grid, em qualquer direção, e mostrar na tela a linha/coluna em que a palavra foi encontrada pela primeira vez
	(mais acima e mais à esquerda) - WHERE'S WALDORF? */
	
#include <iostream>
#include <string>
#include <algorithm> 

using namespace std;

int lin,col;
string a;
char grid[100][100];

/*
TIPOS DE PROCURA
1 - esqdir
2 - diresq
3 - cimabaixo
4 - baixocima
5 - diagdirbaixo
6 - diagesqbaixo
7 - diagdircima
8 - diagesqcima
*/


int esqdir(int l, int c, int pos)
{
	if (pos==a.length())
	{
		lin=l;
		col=c-pos;
		return 1;
	}
	if (grid[l][c]==a[pos])
	{
		esqdir(l,c+1,pos+1);
	}
	else
		return 0;
}

int diresq(int l, int c, int pos)
{
	if (pos==a.length())
	{
		lin=l;
		col=c+pos;
		return 1;
	}
	if (grid[l][c]==a[pos])
	{
		diresq(l,c-1,pos+1);
	}
	else
		return 0;
}

int cimabaixo(int l, int c, int pos)
{
	if (pos==a.length())
	{
		lin=l-pos;
		col=c;
		return 1;
	}
	if (grid[l][c]==a[pos])
	{
		cimabaixo(l+1,c,pos+1);
	}
	else
		return 0;
}

int baixocima(int l, int c, int pos)
{
	if (pos==a.length())
	{
		lin=l+pos;
		col=c;
		return 1;
	}
	if (grid[l][c]==a[pos])
	{
		baixocima(l-1,c,pos+1);
	}
	else
		return 0;
}

int diagdirbaixo(int l, int c, int pos)
{
	if (pos==a.length())
	{
		lin=l-pos;
		col=c-pos;
		return 1;
	}
	if (grid[l][c]==a[pos])
	{
		diagdirbaixo(l+1,c+1,pos+1);
	}
	else
		return 0;
}

int diagdircima(int l, int c, int pos)
{
	if (pos==a.length())
	{
		lin=l+pos;
		col=c-pos;
		return 1;
	}
	if (grid[l][c]==a[pos])
	{
		diagdircima(l-1,c+1,pos+1);
	}
	else
		return 0;
}

int diagesqbaixo(int l, int c, int pos)
{
	if (pos==a.length())
	{
		lin=l-pos;
		col=c+pos;
		return 1;
	}
	if (grid[l][c]==a[pos])
	{
		diagesqbaixo(l+1,c-1,pos+1);
	}
	else
		return 0;
}

int diagesqcima(int l, int c, int pos)
{
	if (pos==a.length())
	{
		lin=l+pos;
		col=c+pos;
		return 1;
	}
	if (grid[l][c]==a[pos])
	{
		diagesqcima(l-1,c-1,pos+1);
	}
	else
		return 0;
}

void procura(int m,int n)
{
	int l,c;
	
	for (l=1;l<=m;l++)
	{
		for (c=1;c<=n;c++)
		{
			if ((n-c+1)>=a.length()) 
				if (esqdir(l,c,0)) return;
			if (c>=a.length()) 
				if (diresq(l,c,0)) return;
			if ((m-l+1)>=a.length()) 
				if (cimabaixo(l,c,0)) return;
			if (l>=a.length()) 
				if (baixocima(l,c,0)) return;
			if ((n-c+1)>=a.length() && (m-l+1)>=a.length()) 
				if (diagdirbaixo(l,c,0)) return;
			if ((n-c+1)>=a.length() && l>=a.length()) 
				if (diagdircima(l,c,0)) return;
			if (c>=a.length() && (m-l+1)>=a.length()) 
				if (diagesqbaixo(l,c,0)) return;
			if (c>=a.length() && l>=a.length()) 
				if (diagesqcima(l,c,0)) return;
		}
	}		
	return;		
}


int main()
{
	int casos,m/*linha*/,n/*coluna*/,p/*k no exercício*/;
	int k,l,c;
	
	
	cin >> casos;
	cin.ignore();
	for (k=1;k<=casos;k++)
	{
		string pal[100];
		cin >> m >> n;
		for (l=1;l<=m;l++)
		{
			for (c=1;c<=n;c++)
			{
				cin >> grid[l][c];
				grid[l][c]=tolower(grid[l][c]);
			}
		}
		cin >> p;
		cin.ignore();
		for (l=1;l<=p;l++)
		{
			getline(cin, a);
			if (int(a[a.length()-1])==13) 
			{
				a[a.length()-1]='\0';
				a.resize(a.length()-1);
			}
			for (c=0;c<a.length();c++)
				a[c]=tolower(a[c]);
			procura(m,n);
			cout << lin << ' ' << col << endl;	
		}
		getline(cin, a);
		if (k!=casos) cout << endl;	
	}
}

