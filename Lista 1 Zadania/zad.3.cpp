#include <iostream>

using namespace std;

void rysujTrojkat(int);

int main()
{
	int liczba = 0;
	cout << "Prosze podac liczbe: ";
	cin >> liczba;
	rysujTrojkat(liczba);

	system("pause");
	return 0;
}

void rysujTrojkat(int liczbaRzedow)
{
	for (int i = liczbaRzedow; i >= 1; i--)
	{
		for (int j = i; j >= 1; j--)
		{
			cout << "*";
		}
		cout << "\n";
	}
}