/* Heloisa Hungaro Primolan RA 141026431 */

/* PROBLEMA 501 - UVa */

/* O problema consiste em um "banco de dados primitivo" que apresenta duas operações - GET e ADD. Uma variável i inicia-se em 0.
	ADD(x) coloca o elemento x na base de dados; GET incrementa i e retorna o elemento de posição i dentro dos elementos na base de dados*/
	
#include <iostream>
#include <sstream>
#include <string>
#include <set>
#include <vector>

using namespace std;


int main() 
{
    int tests;

    cin >> tests;
    string a;
    getline(cin, a);

    for(int t = 0; t < tests; t++) 
	{
        if (t > 0)
            cout << "\n";
        int m, n;
        cin >> m >> n;

        int nums[30000];

        for (int i = 0; i < m; i++)
            cin >> nums[i];

        multiset<long> x;
        multiset<long>::iterator it;
        long sz = 1;
        x.insert(nums[0]);
        bool first = true;
        long vu;

        for(int i = 0; i < n; i++) 
		{
            cin >> vu;
            while (vu > sz) 
			{
                x.insert(nums[sz]);

                if (!first && *it > nums[sz]) 
				{
                    it--;
                }
                sz++;
            }
            if (first) 
			{
                it = x.begin();
                first = false;
            } else 
			{
                it++;
            }

            cout << *it << endl;
        }
    }
}
