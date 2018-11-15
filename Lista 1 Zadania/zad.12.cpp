#include <iostream>
#include <cstring>

using namespace std;

int zliczSlowa(char[]);

int main()
{
	char zdanie[1024] = {};
	cout << "Prosze podac zdanie: ";
	cin.getline(zdanie, 1024);
	cout << "Ilosc slow w podanym zdaniu: " << zliczSlowa(zdanie) << "\n";

	system("pause");
	return 0;
}

int zliczSlowa(char zdanie[])
{
	bool czySlowo = false; // stan poczatkowy
	int licznik = 0;
	for (int i = 0; zdanie[i] != '\0'; i++)
	{
		// jezeli nastepny znak jest spacja lub znakiem tabulacji, to przypisuje zmiennej czySlowo wartosc false
		// wartosc false oznacza, ze napotkano spacje lub znak tabulacji
		// wartosc true oznacza, ze napotkano znak rozpoczynajacy slowo
		if (zdanie[i] == ' ' || zdanie[i] == '\t')
			czySlowo = false;

		// jezeli nastepny znak nie jest spacja, ani znakiem tabulacji i zmienna czySlowo ma wartosc false
		// wtedy przypisuje zmiennej czySlowo wartosc true i inkrementuje licznik
		else if (czySlowo == false)
		{
			czySlowo = true;
			licznik++; // inkrementuje licznik wtedy, gdy poprzedni znak by³ spacja lub znakiem tabulacji, a nastepny jest znakiem rozpoczynajacym slowo
		}
	}
	return licznik;
}


/*
// jezeli w zdaniu jest spacja miedzy kazdymi dwoma slowami, to liczba slow jest o 1 wieksza od liczby spacji
int zliczSlowa(char zdanie[])
{
	int licznik = 0;
	for (int i = 0; zdanie[i] != '\0'; i++)
	{
		if (zdanie[i] == ' ')
			licznik++;
	}
	licznik++;
	return licznik;
}
*/