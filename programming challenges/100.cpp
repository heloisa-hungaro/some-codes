/* Heloisa Hungaro Primolan RA 141026431 */

/* PROBLEMA 100 - UVa */

/* O problema encontra qual o maior número de ciclos da sequência 3n+1 para um intervalo [a,b]
	A sequência funciona da seguinte forma: se n é par, n=n/2 ; se n é ímpar, n=3*n+1  -> até n=1 */
	
#include <iostream>

using namespace std;

int main()
{
	long ai, bi, a, b;
	while (cin >> a >> b)
	{
		ai=a;
		bi=b;
		if (b<a)
			swap(a,b);
		long m=0;
		for (long i=a;i<=b;i++)
		{
			long n=i;
			long c=1;
			while (n>1)
			{
				if (n%2==0)
					n/=2;
				else
					n=3*n+1;
				c++;
			}
			if (c>m) 
				m=c;
		}
	    	cout << ai << ' ' << bi << ' ' << m << endl;
	}
	return 0;
}
