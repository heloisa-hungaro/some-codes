/* Heloisa Hungaro Primolan RA 141026431 */

/* PROBLEMA 10018 - UVa */

/* O problema se resume em somar um número com seu inverso e, se necessário, realizar esta operação com o resultado, até que este resultado seja palindromo */

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
	int k, casos, i, itera;
	unsigned int r;
	string n1, n2;
	
	cin >> casos;
	cin.ignore();
	for (k=1;k<=casos;k++)
	{
		itera=0;	
		getline(cin,n1);
		n2=n1;
		reverse(n2.begin(),n2.end());
		do
		{
		
			r=stoi(n1)+stoi(n2);
			n1=to_string(r);
			n2=n1;
			reverse(n2.begin(),n2.end());
			itera++;
		} while (n2!=n1);
		cout << itera << ' ' << n1 << endl;
	}
	return 0;
}

