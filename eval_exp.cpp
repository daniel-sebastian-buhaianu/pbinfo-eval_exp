#include <iostream>
#include <cstring>
#define LGMAX 51
using namespace std;
bool ok;
int poz, lg;
long long p=1, rez;
char semn='+', op[]="-+", e[LGMAX];
void evalExp();
int main()
{
	cin.getline(e, LGMAX);	
	lg = strlen(e);
	evalExp();
	cout << rez;
	return 0;
}
bool cifra(char c)
{
	return c >= '0' && c <= '9';
}
void evalExp()
{
	if (poz > lg)
	{
		return;
	}
	long long nr;
	for (nr = 0; cifra(e[poz]); poz++)
	{
		nr = nr*10 + (e[poz]-'0');
	}
	if (e[poz] == '*')
	{
		p *= nr;
		ok = 1;
	}
	else
	{
		if (ok)
		{
			nr *= p;
			p = 1;
			ok = 0;
		}
		rez = (semn == '+') ? rez+nr : rez-nr;
		if (strchr(op, e[poz]))
		{
			semn = e[poz];
		}
	}
	poz++;
	evalExp();
}
// scor 100
