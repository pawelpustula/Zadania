#include<iostream>

using namespace std;

void tabliczkaMnozenia(int, int);

int main()
{
	int liczbaRzedow = 0, liczbaKolumn = 0;
	cout << "Prosze podac wymiary tabliczki mnozenia (liczba rzedow x liczba kolumn): ";
	cin >> liczbaRzedow >> liczbaKolumn;
	tabliczkaMnozenia(liczbaRzedow, liczbaKolumn);

	system("pause");
	return 0;
}

void tabliczkaMnozenia(int liczbaRzedow, int liczbaKolumn)
{
	for (int i = 1; i <= liczbaRzedow; i++)
	{
		for (int j = 1; j <= liczbaKolumn; j++)
		{
			cout.width(4);
			cout << right << i * j;
		}
		cout << "\n"; // nowa linia po wypisaniu kazdego rzedu
	}
}