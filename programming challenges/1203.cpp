/* Heloisa Hungaro Primolan RA 141026431 */

/* PROBLEMA 1203 - UVa */

/* O problema é o Argus: queries são executadas com determinada frequência e seus respectivos resultados são exibidos. */

#include <sstream>
#include <iostream>
#include <string>
#include <list>

using namespace std;

struct reg
{
	int qnum, period;
	
	reg(int q, int p)
	{
		qnum=q;
		period=p;
	}
};

bool compara(reg n, reg p) 	
{
		return n.qnum<p.qnum;
};

int main()
{
	string a, x;
	char c;
	int k, i, n, q, p;
	list<reg> todos, mostra;
	todos.clear(); 
	getline(cin, a);
	while (a.compare("#")!=0)
	{
		stringstream ss;
		ss << a;
		getline(ss,x,' ');
		ss >> q >> p;
		todos.push_front(reg(q,p));
		getline(cin, a);
	}
	cin >> k;
	cin.ignore();

	i=0;
	for (n=1;i<k;n++)
	{
		mostra.clear();
		for (auto it=todos.begin();it!=todos.end();++it)
		{
			if (n%it->period==0) 
				mostra.push_front(reg(it->qnum,it->period));
		}
		if (!mostra.empty())
		{			
			mostra.sort(compara);
			for (auto it=mostra.begin();it!=mostra.end() && i<k;++it)
			{
				cout << it->qnum << endl;
				i++;
			}
		}
	}
	return 0;
}

