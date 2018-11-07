#include <iostream>

using namespace std;

int ile_a(char[]);

int main()
{
	char imie[1025] = {};
	cout << "Prosze podac imie: ";
	cin >> imie;
	cout << "Liczba liter a w Twoim imieniu: " << ile_a(imie) << "\n";

	system("pause");
	return 0;
}

int ile_a(char imie [])
{
	int licznik = 0;
	for (unsigned int i = 0; i <= 1024; i++)
	{
		if (imie[i] == 'a' || imie[i] == 'A')
			licznik++;
	}

	return licznik;
}