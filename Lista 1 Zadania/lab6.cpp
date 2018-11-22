#include <iostream>

using namespace std;

void drukujBinarnie(int);

void zapalBit(unsigned int, int);

int main()
{
	//drukujBinarnie(14);
	zapalBit(25, 5);
	system("pause");

}

void drukujBinarnie(int liczba)
{
	int bity[32];
	int i = 31;

	for (int j = 0; j < 32; j++)
	{
		bity[i] = liczba & 1;
		liczba = liczba >> 1;
		i--;
	}

	for (int j = 0; j < 32; j++)
		cout << bity[j];
	cout << endl;
}

void zapalBit(unsigned int liczba, int n)
{
	cout << "Liczba przed zapaleniem bitu: " << liczba << endl;
	drukujBinarnie(liczba);
	int poZapaleniu = liczba | (1 << n);
	cout << "Po zapaleniu n-tego bitu: " << poZapaleniu << endl;
	drukujBinarnie(poZapaleniu);

	int xor = liczba ^ poZapaleniu;
	cout << "Po operacji XOR: " << xor << endl;
	drukujBinarnie(xor);
}

/*

void drukujBinarnie(int liczba)
{
	for (int i = 31; i >= 0; i--)
	{
		int x = liczba >> i;
		if (x & 1)
			cout << '1';
		else
			cout << '0';
	}
}
*/