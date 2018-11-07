#include <iostream>

using namespace std;

void rysujChoinke(int wysokosc);

int main()
{
	int wysokosc = 0;
	cout << "Prosze podac wysokosc choinki: ";
	cin >> wysokosc;
	rysujChoinke(wysokosc);
	system("pause");
	return 0;
}

void rysujChoinke(int wysokosc)
{
	for (int i = 1; i <= wysokosc - 1; i++)         // i - numer rzêdu
	{
		for (int j = wysokosc - i - 1; j >= 1; j--) // j - spacje do wypisania w jednym rzêdzie
		{
			cout << " ";
		}
		for (int k = 1; k <= i * 2 - 1; k++)        // k - gwiazdki do wypisania w jednym rzêdzie
		{
			cout << "*";
		}
		cout << "\n";
	}
	for (int m = 1; m <= wysokosc - 2; m++)        // m - spacje poprzedzaj¹ce pieñ choinki
	{
		cout << " ";
	}
	cout << "#\n";
	for (int n = 1; n < 2 * wysokosc - 2; n++)     // n - znaki odejmowania
	{
		cout << "-";
	}
	cout << "\n";

}
