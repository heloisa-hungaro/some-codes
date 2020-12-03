/* Heloisa Hungaro Primolan RA 141026431 */

/* PROBLEMA 10035 - UVa */

/* O problema se resume em contar quantas operações CARRY ocorrem ao somar dois números dados */

#include <sstream>
#include <iostream>
#include <string>

using namespace std;

int main()
{
	bool c, temdgt1, temdgt2;
	string a, n1, n2, aux;
	int i, r, carry;
	do
	{
		carry=0;
		getline(cin,a);
        stringstream s(a);
		getline(s,n1,' ');
		getline(s,n2);
		
		aux=n1;
		for (i=0;i<n1.length();i++)
		{
			n1[i]=aux[n1.length()-1-i];
		}
		aux=n2;
		for (i=0;i<n2.length();i++)
		{
			n2[i]=aux[n2.length()-1-i];
		}
		
		if (stoi(n1)!=0 || stoi(n2)!=0)
		{
			temdgt1=1;
			temdgt2=1;
			c=0;
			for (i=0;(temdgt1 || temdgt2);i++)
			{
				if (temdgt1 && temdgt2)
					r=n1[i]+(int)n2[i]-'0'-'0'+c;
				else if (temdgt1)
					r=n1[i]-'0'+c;
				else 
					r=n2[i]-'0'+c;
				if (r>=10)
				{
					carry++;
					c=1;
				}
				else
					c=0;
				if (i==n1.length()-1)
					temdgt1=0;
				if (i==n2.length()-1)
					temdgt2=0;
			}
			if (carry==0)
				cout << "No";
			else
				cout << carry;
			cout << " carry operation";
			if (carry<=1)
				cout << '.' << endl;
			else
				cout << "s." << endl;
		}
	} while (stoi(n1)!=0 || stoi(n2)!=0);
	return 0;
}
