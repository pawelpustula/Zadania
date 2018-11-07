#include <iostream>
#include <cstring>
#include <cctype>

using namespace std;

bool czyPalindrom(char[]);

int main()
{
	char wyraz[1025] = {};
	cout << "Podaj ciag znakow do sprawdzenia: ";
	cin.getline(wyraz, 1025);
	if (czyPalindrom(wyraz))
		cout << "palindrom";
	else
		cout << "nie palindrom";
	cout << "\n";

	system("pause");
	return 0;
}

bool czyPalindrom(char wyraz[])
{
	int i = 0;
	int j = strlen(wyraz) - 1;
	
	while (j > i)
	{
		// je�eli funkcja isalnum zwr�ci warto�� 0, to znak nie jest liter�, ani cyfr�.
		while ( (i < j) && (isalnum(wyraz[i]) == 0) ) // szukam znaku, kt�ry b�dzie liter� lub cyfr�. P�tla wykonuje si�, dop�ki nie znajd� litery lub cyfry.
			i++;
		while ( (j > i) && (isalnum(wyraz[j]) == 0) )
			j--;

	    // brak rozr�niania ma�ych i du�ych liter
		if ( toupper(wyraz[i]) != toupper(wyraz[j]) ) // je�eli znaki na pozycjach i oraz j nie s� takie same, to zdanie nie jest palindromem
		{
			return false;
		}
			i++;
			j--;
	}
	return true;
}