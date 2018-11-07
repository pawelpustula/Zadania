#include <iostream>
#include <cstring>
#include <cctype> // funkcje dla znak�w
using namespace std;

void wypiszDuzymi(char[]);

int main()
{
	char zdanie[1025] = {};
	cout << "Podaj zdanie: ";
	cin.getline(zdanie, 1025);
	wypiszDuzymi(zdanie);

	system("pause");
	return 0;
}

void wypiszDuzymi(char zdanie[])
{
	for (int i = 0; i < strlen(zdanie); i++)
	{
		if (zdanie[i] == 32)                         // spacja w kodzie ASCII ma reprezentacj� dziesi�tn� 32
			cout << "";                              // wypisywany jest pusty ci�g znak�w, poniewa� spacje mia�y zosta� pomini�te
		else if(zdanie[i] >= 97 && zdanie[i] <= 122) // ma�e litery w kodzie ASCII maj� reprezentacj� dziesi�tn� pomi�dzy 97, a 122
			cout << (char)(zdanie[i] - 32);          // du�e odpowiedniki ma�ych liter s� oddalone odpowiednio o 32 pozycje w kodzie ASCII (od 65 do 90)
		else
			cout << zdanie[i];

	}
	cout << "\n";
}

/*
void wypiszDuzymi(char zdanie[])
{
	for (int i = 0; i < strlen(zdanie); i++)
	{
		if (zdanie[i] == 32)
			cout << "";
		else
			cout << (char)toupper(zdanie[i]);
	}
	cout << "\n";
}
*/
