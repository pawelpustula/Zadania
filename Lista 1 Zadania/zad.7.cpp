#include <iostream>
#include <cstring>

using namespace std;

void wypiszOdKonca(char[]);

int main()
{
	char slowo[1025] = {};
	cout << "Podaj slowo: ";
	cin >> slowo;
	wypiszOdKonca(slowo);

	system("pause");
	return 0;
}

void wypiszOdKonca(char slowo[])
{
	for (int i = 1024; i >= 0; i--)
	{
		if (slowo[i] != 0)
		cout << slowo[i];
	}
	cout << "\n";
}

/*
void wypiszOdKonca(char slowo[])
{
	for (int i = strlen(slowo) - 1; i >= 0; i--)
	{
		cout << slowo[i];
	}
	cout << "\n";
}
*/

