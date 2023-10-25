#include <iostream>
#include <cstring>
#define LGMAX 52
using namespace std;
bool cifra(char);
int main()
{
	char e[LGMAX], stvOp[LGMAX/2];
	long long stvNr[LGMAX/2], nr, rez;
	int vfOp, vfNr, i, lg;
	cin.getline(e, LGMAX);
	vfOp = vfNr = -1;
	stvOp[++vfOp] = '+';
	for (lg = strlen(e), nr = i = 0; i <= lg; i++)
	{
		if (!cifra(e[i]))
		{
			if (stvOp[vfOp] == '*')
			{
				stvNr[vfNr] *= nr;
				vfOp--;
			}
			else
			{
				stvNr[++vfNr] = nr;
			}
			nr = 0;
			if (i < lg)
			{
				stvOp[++vfOp] = e[i];
			}
		}
		else
		{
			nr = nr*10 + (e[i]-'0');
		}
	}
	rez = 0;
	while (vfNr >= 0 && vfOp >= 0)
	{
		if(stvOp[vfOp] == '+')
		{
			rez += stvNr[vfNr];
		}
		else if (stvOp[vfOp] == '-')
		{
			rez -= stvNr[vfNr];
		}
		else
		{
			cout << "Ceva nu a mers bine.\n";
			return 1;
		}
		vfNr--;
		vfOp--;
	}
	cout << rez;
	return 0;
}
bool cifra(char c)
{
	return c >= '0' && c <= '9';
}
// scor 100
