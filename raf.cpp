#include <fstream>
#define LGMAX_S 100
#define LGMAX_ALFABET 26
using namespace std;
// fisiere intrare/iesire
ifstream fin("raf.in");
ofstream fout("raf.out");
// variabile globale
int f[LGMAX_ALFABET], poz;
char s[LGMAX_S];
// functii ajutatoare
bool eLitera(char);
void restaureaza();
// functia principala
int main()
{
	char nf;
	int af, i;
	fin.getline(s, LGMAX_S);
	while(fin >> nf >> af)
	{
		if (eLitera(nf))
		{
			f[nf-'a'] = af;
		}
	}
	fin.close();
	restaureaza();
	fout.close();
	return 0;
}
int aritate(char numeFunctie)
{
	return f[numeFunctie-'a'];
}
void restaureaza()
{
	fout << s[poz];
	int k = aritate(s[poz++]);
	if (k)
	{
		fout << '(';
		for (int i = 1; i < k; i++)
		{
			restaureaza();
			fout << ',';
		}
		restaureaza();
		fout << ')';
	}
}
bool eLitera(char c)
{
	return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}
