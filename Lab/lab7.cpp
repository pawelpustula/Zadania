#include <iostream>

using namespace std;

void odwroc(char *s, char *t);
void zliczajZnaki(char *tekst1, char *znaki1, int *czestotliwosc1);

int main()
{
	/*
	Zad.6
	char tabT[1024] = {};
	char tabS[1024] = {};

	cout << "Podaj zdanie: ";
	cin.get(tabT, 1024);

	odwroc(tabS, tabT);


	int i = 0;

	while (*(tabS + i) != 0)
	{
		cout << (*(tabS + i));
		i++;
	}
	*/

	// Zad.7
	char tekst[1024] = {};
	char znaki[1024] = {};
	int czest[1024] = {};

	cout << "Podaj tekst: ";
	cin.get(tekst, 1024);
	zliczajZnaki(tekst, znaki, czest);

	int i = 0;
	while (*(znaki + i) != 0)
	{
		cout << *(znaki + i) << ": " << *(czest + i) << endl;
		i++;
	}
	

	cout << endl;
	system("pause");
}

void odwroc(char *s, char *t)
{
	int dlugosc = 0;
	char *wsk = t;

	while (*wsk != 0)
	{
		dlugosc++;
		wsk++;
	}
	
	wsk = (s + dlugosc);
	*wsk = 0;
	wsk--;

	while (*t != 0)
	{
		*wsk = *t;
		wsk--;
		t++;
	}
}

void zliczajZnaki(char *tekst1, char *znaki1, int *czestotliwosc1)
{
	char *znaki = znaki1;
	char *tekst = tekst1;
	int *czestotliwosc = czestotliwosc1;
	bool czyJest = false;

	*znaki = *tekst;
	znaki++;
	tekst++;
	*czestotliwosc = 1;
	*znaki = 0;

	// glowna petla
	while (*tekst != 0)
	{
		znaki = znaki1;
		czestotliwosc = czestotliwosc1;
		czyJest = false;

		while (*znaki != 0)
		{
			if (*tekst == *znaki)
			{
				*czestotliwosc += 1;
				czyJest = true;
				break;
			}

			znaki++;
			czestotliwosc++;
		}

		if (!czyJest)
		{
			*znaki = *tekst;
			znaki++;
			*znaki = 0;
			*czestotliwosc = 1;
		}
		tekst++;
	}
}