/* Heloisa Hungaro Primolan RA 141026431 */

/* PROBLEMA 10258 - UVa */

/* O problema simula o scoreboard da maratona: como entrada, recebe os dados de envios dos competidores; como resultado, dá o placar final */

#include <iostream>
#include <algorithm>
#include <cstring>
#include <sstream>


using namespace std;

struct compete
{
	bool sub; /* fez submissao */
	int res[20]; /* problema resolvido */
	int tempo[20];
	int comp; /* competidor */
} x[150];

void limpa()
{
	for (int i=0;i<102;i++)
	{
		x[i].sub=false;
		memset (x[i].res, 0, sizeof x[i].res);
		memset (x[i].tempo, 0, sizeof x[i].tempo);
	}
}

bool ordena(compete a, compete p)
{	
	if (a.res[10]!=p.res[10])
	return a.res[10] > p.res[10];
	if (a.tempo[10]!=p.tempo[10])
	return a.tempo[10] < p.tempo[10];
	return a.comp < p.comp;
}
 
int main()
{
	int n,c,p; 
	long t;
	char L;
	string linha;
	stringstream s;
	
	cin >> n;
	cin.ignore();
	getline(cin,linha);
	for (int i=1;i<=n;i++)
	{
		
		limpa();
		int f=0;
		while (getline(cin,linha)&& linha.length()>0)
		{
			s.clear();
			s << linha;
			s >> c >> p >> t >> L;
			
			//cout << c << 'x' << p << 'x' << t << 'x' << L << 'x' << i << endl;
			
			x[c].sub=true;
			x[c].comp=c;
			if (L=='C' && x[c].res[p]==0)
			{
				x[c].res[10]++;
				x[c].res[p]=1;
				x[c].tempo[10]+=t+(x[c].tempo[p]);
			}
			else if (L=='I' && x[c].res[p]==0)
				x[c].tempo[p]+=20;
		}
		sort(x,x+102,ordena);
		
		for (int j=0;j<=102;j++)
		{
			if (x[j].sub==false)
				continue;
			cout << x[j].comp << ' ' << x[j].res[10] << ' ' << x[j].tempo[10] << endl; 
		}
		if (i<n)
			cout << endl;
	}
	return 0;
}

