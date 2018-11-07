#include <iostream>
#include <cstring>
#include <cctype> // funkcje dla znaków
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
		if (zdanie[i] == 32)                         // spacja w kodzie ASCII ma reprezentacjê dziesiêtn¹ 32
			cout << "";                              // wypisywany jest pusty ci¹g znaków, poniewa¿ spacje mia³y zostaæ pominiête
		else if(zdanie[i] >= 97 && zdanie[i] <= 122) // ma³e litery w kodzie ASCII maj¹ reprezentacjê dziesiêtn¹ pomiêdzy 97, a 122
			cout << (char)(zdanie[i] - 32);          // du¿e odpowiedniki ma³ych liter s¹ oddalone odpowiednio o 32 pozycje w kodzie ASCII (od 65 do 90)
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
