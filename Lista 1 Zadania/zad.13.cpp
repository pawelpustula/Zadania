#include <iostream>
#include <cstring>

using namespace std;

int sumaCyfr(unsigned int);
int sumaCyfr(char[]);

int main()
{
	unsigned int liczba = 0;
	//char liczba[1024] = {};
	cout << "Prosze podac liczbe: ";
	cin >> liczba;
	cout << "Suma cyfr liczby " << liczba << " wynosi " << sumaCyfr(liczba) << "\n";
	system("pause");
	return 0;
}


int sumaCyfr(unsigned int liczba)
{
	int cyfra = 0, suma = 0;
	while (liczba > 0)
	{
		cyfra = liczba % 10;
		suma += cyfra;
		liczba /= 10;
	}
	return suma;
}

// funkcja dla liczb wiekszych niz zakres typu unsigned int
int sumaCyfr(char liczba[])
{
	int cyfra = 0, suma = 0;
	for (int i = 0; i < strlen(liczba); i++)
	{
		cyfra = liczba[i] - '0'; // 0 w tabeli ASCII ma wartosc dziesietna 48, cyfry maja reprezentacje dziesietna od 48 do 57
		suma += cyfra;
	}
	return suma;
}