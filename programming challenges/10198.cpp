/* Heloisa Hungaro Primolan RA 141026431 */

/* PROBLEMA 10198 - UVa */

/* O problema se resume em, dado n, verificar quantas combinações do número 1,2,3,4 somam n - porém 4=1 !!! */

/* Como gera resultados muito grandes em valor inteiro, foi necessário utilizar a implementação do bigint novamente (bign) */


#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <stack>
#include <queue>
#include <cctype>
#include <cstdio>
#include <string>
#include <vector>
#include <climits>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#define LL long long
#define PI 3.1415926535897932626

using namespace std;



int gcd(int a, int b) {return a % b == 0 ? b : gcd(b, a % b);}
const int numlen=420;
struct bign {
    int len, s[numlen];
    bign() {
        memset(s, 0, sizeof(s));
        len = 1;
    }
    bign(int num) { *this = num; }
    bign(const char *num) { *this = num; }
    bign operator = (const int num) {
        char s[numlen];
        sprintf(s, "%d", num);
        *this = s;
        return *this;
    }
    bign operator = (const char *num) {
        len = strlen(num);
        while(len > 1 && num[0] == '0') num++, len--;
        for(int i = 0;i < len; i++) s[i] = num[len-i-1] - '0';
        return *this;
    }

    void deal() {
        while(len > 1 && !s[len-1]) len--;
    }

    bign operator + (const bign &a) const {
        bign ret;
        ret.len = 0;
        int top = max(len, a.len) , add = 0;
        for(int i = 0;add || i < top; i++) {
            int now = add;
            if(i < len) now += s[i];
            if(i < a.len)   now += a.s[i];
            ret.s[ret.len++] = now%10;
            add = now/10;
        }
        return ret;
    }
    bign operator - (const bign &a) const {
        bign ret;
        ret.len = 0;
        int cal = 0;
        for(int i = 0;i < len; i++) {
            int now = s[i] - cal;
            if(i < a.len)   now -= a.s[i];
            if(now >= 0)    cal = 0;
            else {
                cal = 1; now += 10;
            }
            ret.s[ret.len++] = now;
        }
        ret.deal();
        return ret;
    }
    bign operator * (const bign &a) const {
        bign ret;
        ret.len = len + a.len;
        for(int i = 0;i < len; i++) {
            for(int j = 0;j < a.len; j++)
                ret.s[i+j] += s[i]*a.s[j];
        }
        for(int i = 0;i < ret.len; i++) {
            ret.s[i+1] += ret.s[i]/10;
            ret.s[i] %= 10;
        }
        ret.deal();
        return ret;
    }

    bign operator * (const int num) {
//        printf("num = %d\n", num);
        bign ret;
        ret.len = 0;
        int bb = 0;
        for(int i = 0;i < len; i++) {
            int now = bb + s[i]*num;
            ret.s[ret.len++] = now%10;
            bb = now/10;
        }
        while(bb) {
            ret.s[ret.len++] = bb % 10;
            bb /= 10;
        }
        ret.deal();
        return ret;
    }

    bign operator / (const bign &a) const {
        bign ret, cur = 0;
        ret.len = len;
        for(int i = len-1;i >= 0; i--) {
            cur = cur*10;
            cur.s[0] = s[i];
            while(cur >= a) {
                cur -= a;
                ret.s[i]++;
            }
        }
        ret.deal();
        return ret;
    }

    bign operator % (const bign &a) const {
        bign b = *this / a;
        return *this - b*a;
    }

    bign operator += (const bign &a) { *this = *this + a; return *this; }
    bign operator -= (const bign &a) { *this = *this - a; return *this; }
    bign operator *= (const bign &a) { *this = *this * a; return *this; }
    bign operator /= (const bign &a) { *this = *this / a; return *this; }
    bign operator %= (const bign &a) { *this = *this % a; return *this; }

    bool operator < (const bign &a) const {
        if(len != a.len)    return len < a.len;
        for(int i = len-1;i >= 0; i--) if(s[i] != a.s[i])
            return s[i] < a.s[i];
        return false;
    }
    bool operator > (const bign &a) const  { return a < *this; }
    bool operator <= (const bign &a) const { return !(*this > a); }
    bool operator >= (const bign &a) const { return !(*this < a); }
    bool operator == (const bign &a) const { return !(*this > a || *this < a); }
    bool operator != (const bign &a) const { return *this > a || *this < a; }

    string str() const {
        string ret = "";
        for(int i = 0;i < len; i++) ret = char(s[i] + '0') + ret;
        return ret;
    }
};
istream& operator >> (istream &in, bign &x) {
    string s;
    in >> s;
    x = s.c_str();
    return in;
}
ostream& operator << (ostream &out, const bign &x) {
    out << x.str();
    return out;
}



/* meu código é daqui para baixo! */


int main()
{	
	bign x[1005];
	bign mil;
	int i,n;
	x[0]=0;
	x[1]=2;
	x[2]=5;
	x[3]=13;
	for (i=4;i<=1000;i++)
	{
		x[i]=0;
		x[i]=x[i-1];
		x[i]=x[i]+x[i-1]; 
		x[i]=x[i]+x[i-2];
		x[i]=x[i]+x[i-3];
		if (i==1000)
			mil=x[i];
	}
	while (cin >> n)
	{
		if (n==1000) 
			cout << mil << endl; 
		else
			cout << x[n] << endl;
	}
	return 0;
}

