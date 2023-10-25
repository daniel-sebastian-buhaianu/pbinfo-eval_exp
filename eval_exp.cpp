#include <iostream>
#include <cstring>
#define LGMAX 51
#define MAXCIF 20
using namespace std;
bool cifra(char c);
void numarCaSir(long long, char*);
void calculeazaToateProdusele(char*);
long long calculeazaExpresie(char*);
int main()
{
	char s[LGMAX];
	cin.getline(s, LGMAX);
	calculeazaToateProdusele(s);
	cout << calculeazaExpresie(s);
	return 0;
}
long long calculeazaExpresie(char* s)
{
	int lg, i, j, st;
	long long sum, nr;
	char semn = '+';
	lg = strlen(s);
	for (sum = st = i = 0; i <= lg; i++)
	{
		if (!cifra(s[i]))
		{
			for (nr = 0, j = st; j < i; j++)
			{
				nr = nr*10 + (s[j]-'0');
			}
			if (semn == '+')
			{
				sum += nr;
			}
			else
			{
				sum -= nr;
			}
			semn = s[i];
			st = i+1;
		}
	}
	return sum;
}
void calculeazaToateProdusele(char* s)
{
	long long x, prod;
	char *p, *st, *dr, *q, nr[MAXCIF], aux[LGMAX];
	while((p = strchr(s, '*')))
	{
		for (st = p-1; cifra(*(st-1)); st--);
		for (dr = p+1; cifra(*(dr+1)); dr++);
		for (x = 0, q = st; q < p; q++)
		{
			x = x*10 + (*q-'0');
		}
		prod = x;
		for (x = 0, q = p+1; q <= dr; q++)
		{
			x = x*10 + (*q-'0');
		}
		prod *= x;
		numarCaSir(prod, nr);
		strcpy(aux, dr+1);
		*st = 0;
		strcat(s, nr);
		strcat(s, aux);
	}
}
void numarCaSir(long long x, char* s)
{
	int lg, i, j;
	char aux;
	strcpy(s, "");
	for (lg = 0; x; x /= 10)
	{
		s[lg++] = '0' + x%10;
	}
	s[lg] = 0;
	for (i = 0, j = lg-1; i < j; i++, j--)
	{
		aux = s[i];
		s[i] = s[j];
		s[j] = aux;
	}
}
bool cifra(char c)
{
	return c >= '0' && c <= '9';
}
