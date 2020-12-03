/* Heloisa Hungaro Primolan RA 141026431 */

/* PROBLEMA 12592 - UVa */

/* O problema se resume em: dado um conjunto de slogans divididos em duas partes - para cada linha de slogan no input, deve-se encontrar a segunda linha
	correspondente ao slogan e exibí-la no output*/

#include <iostream>
#include <map>
#include <string>

using namespace std;

int main() 
{
    int n;
    cin >> n;
    cin.ignore();
    map<string, string> slogans;
    for(int i = 0; i < n; i++) 
	{
        string a,b;
        getline(cin, a);
        getline(cin, b);
        slogans[a] = b;

    }
    cin >> n;
    cin.ignore();

    string a;
    for (int i =0; i < n; i++) 
	{
        getline(cin, a);
        cout << slogans[a] << endl;
    }
    return 0;
}
