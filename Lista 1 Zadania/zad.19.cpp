#include <iostream>
#include <cstring>

using namespace std;

int zamien(char[]);

int main()
{
	char liczba[1024] = {};
	cout << "Prosze podac liczbe do zamiany: ";
	cin >> liczba;
	cout << "Po zamianie: " << zamien(liczba) << "\n";;

	system("pause");
	return 0;
}

int zamien(char liczba[])
{
	int wynik = 0, znak = 1, i = 0;

	if (liczba[0] == '-')
	{
		znak = -1;
		i++;
	}
	
	while (liczba[i] >= 48 && liczba[i] <= 57 && i < strlen(liczba)) // dopoki znak ma reprezentacje dziesietna w postaci cyfry od 0 do 9
	{
		wynik = wynik * 10 + liczba[i] - '0';
		i++;
	}

	return znak*wynik;
}
