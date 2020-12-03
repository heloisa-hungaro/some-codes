/* Heloisa Hungaro Primolan RA 141026431 */

/* PROBLEMA 10194 - UVa */

/* O problema se resume em, a partir de dados de jogos de times de uma competição, determinar o ranking do torneio a partir dos dados dos jogos */

#include <iostream>
#include <string>
#include <algorithm> 
#include <regex>
#include <map>
#include <list>

using namespace std;

struct estado
{
	string nome;
	int	vitorias,perdas,empates,pontos,numjogos,golsfeitos,golstomados;	
};

bool compara(estado n, estado p) 	
{
	if (n.pontos!=p.pontos)
		return n.pontos>p.pontos;
	if (n.vitorias!=p.vitorias)
		return n.vitorias>p.vitorias;
	if ((n.golsfeitos-n.golstomados)!=(p.golsfeitos-p.golstomados))
		return ((n.golsfeitos-n.golstomados)>(p.golsfeitos-p.golstomados));
	if (n.golsfeitos!=p.golsfeitos)
		return n.golsfeitos>p.golsfeitos;
	if (n.numjogos!=p.numjogos)
		return n.numjogos<p.numjogos;
		
	for(int i=0; i<(int)n.nome.length(); i++) 
		n.nome[i] = tolower(n.nome[i]);
	for(int i=0; i<(int)p.nome.length(); i++) 
		p.nome[i] = tolower(p.nome[i]);	
	return n.nome<p.nome;			
};



int main()
{
	string a;
	int numtorneios, numtimes, numjogos, k, t, j, t1, t2;
	cin >> numtorneios;
	cin.ignore();
	for (k=1;k<=numtorneios;k++)
	{	
		list<estado> lista;
		map<string, int> indicetimes;
		estado times[40];
		getline(cin, a);
		cout << a << endl; /* mostra o nome do torneio */
		cin >> numtimes;
		cin.ignore();
		for (t=0;t<numtimes;t++)
		{
			getline(cin, times[t].nome);
			times[t].vitorias=0;
			times[t].perdas=0;
			times[t].empates=0;
			times[t].pontos=0;
			times[t].numjogos=0;
			times[t].golsfeitos=0;
			times[t].golstomados=0;	
			indicetimes[times[t].nome]=t;
		}
		cin >> numjogos;
		cin.ignore();
		for (j=0;j<numjogos;j++)
		{
			//smatch m;
			//getline(cin, a);	
			//regex_match(a, m, regex("^(.*)#([0-9]*)@([0-9]*)#(.*)")); /*m[1] = time1 ; m[2] = gols1 ; m[3] = gols2 ; m[4] = time2 */
			
			getline(cin, a);
            char buff;
            stringstream s(a);
            string nome1, nome2;
            int gols1, gols2;
             
            getline(s,nome1,'#');
            s >> gols1 >> buff >> gols2 >> buff;
            getline(s,nome2);
			
			t1=indicetimes[nome1];
			t2=indicetimes[nome2];	
			times[t1].numjogos++;
			times[t2].numjogos++;
			
			times[t1].golsfeitos+=gols1;
			times[t1].golstomados+=gols2;
			times[t2].golsfeitos+=gols2;
			times[t2].golstomados+=gols1;
			
			if (gols1>gols2) /* time1 ganhou */
			{
				times[t1].vitorias++;
				times[t1].pontos+=3;
				times[t2].perdas++;
			}
			else if (gols1<gols2) /* time2 ganhou */
			{
				times[t1].perdas++;
				times[t2].vitorias++;
				times[t2].pontos+=3;
			}
			else /* deu empate */
			{
				times[t1].empates++;
				times[t1].pontos+=1;
				times[t2].empates++;
				times[t2].pontos+=1;	
			}
		}
		for (t=0;t<numtimes;t++)
		{
			lista.push_front(times[t]);
		}
		lista.sort(compara);
		for (t=0;t<numtimes;t++)
		{
			cout << t+1 << ") " << lista.front().nome << " " << lista.front().pontos << "p, " << lista.front().numjogos;
			cout << "g (" << lista.front().vitorias << '-' << lista.front().empates << '-' << lista.front().perdas;
			cout << "), " << lista.front().golsfeitos-lista.front().golstomados << "gd (" << lista.front().golsfeitos;
			cout << '-' << lista.front().golstomados << ")" << endl;
			lista.pop_front();
		}
		if (k<numtorneios)
			cout << endl;
	}
	return 0;
}

