#include <iostream>

using namespace std;

void postacBinarna(int);

int main()
{
	int liczba = 0;
	cout << "Prosze podac liczbe: ";
	cin >> liczba;
	cout << "Liczba " << liczba << " w systemie dwojkowym ma postac ";
	postacBinarna(liczba);
	cout << "\n";

	system("pause");
	return 0;
}

void postacBinarna(int liczba)
{
	int liczbaBinarna[1000] = { 0 };
	int i = 0;
	while (liczba > 0)
	{
		liczbaBinarna[i] = liczba % 2;
		liczba /= 2;
		i++;
	}
	for (int j = i - 1; j >= 0; j--)
		cout << liczbaBinarna[j];
}