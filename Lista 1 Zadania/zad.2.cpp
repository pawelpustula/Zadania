#include <iostream>

using namespace std;

void rysujGwiazdki(int dlugosc);

int main()
{
	int dlugosc = 0;
	cout << "Prosze podac dlugosc linii: ";
	cin >> dlugosc;
	rysujGwiazdki(dlugosc);

	system("pause");
	return 0;
}

void rysujGwiazdki(int dlugosc)
{
	for (int i = 1; i <= dlugosc; i++)
	{
		cout << "*";
	}
	cout << "\n";
}