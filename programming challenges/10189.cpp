/* Heloisa Hungaro Primolan RA 141026431 */

/* PROBLEMA 10189 - UVa */

/* O problema simula o jogo campo minado: em um campo nxm , o programa mostra na tela qual seria a solução final do campo */


#include <iostream>

using namespace std;

int main()
{
	int l, c, n, m;
	long double i=1;
	char f[150][150];
	
	while (1)
	{	
		cin >> n >> m;	
		if (n==0 && m==0)
			break;
		long t[150][150]={0};
		for (l=0; l<n; l++)
		{
			for (c=0; c<m; c++)
			{
				cin >> f[l][c];
				if (f[l][c]=='*')
				{
					t[l][c+1]++;
					t[l][c-1]++;
					t[l+1][c]++;
					t[l-1][c]++;
					t[l+1][c+1]++;
					t[l-1][c-1]++;
					t[l-1][c+1]++;
					t[l+1][c-1]++;
				}
			}
		}
		if (i>1) 
			cout << endl;
		cout << "Field #" << i++ << ":" << endl;
		for (l=0; l<n; l++)
		{
			for (c=0; c<m; c++)
			{
				if (f[l][c]=='*')
					cout << '*';
				else
					cout << t[l][c];
			}
			cout << endl;
		}
	} 
	return 0;
}
