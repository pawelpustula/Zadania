#include <iostream>
#include <fstream>
#include <string>

using namespace std;

float metodaTrapezow(float *, float *, int);

int main()
{
	float tabX[5]{};
	float tabY[5]{};
	int n = 5;
	string s{};
	ifstream odczyt;
	ofstream zapis;
	zapis.open("wynik.txt");
	odczyt.open("dane.txt");
	if (odczyt.is_open())
	{
		for (int i = 0; i < n; i++)
		{
			odczyt >> s;
			tabX[i] = stof(s);
			odczyt >> s;
			tabY[i] = stof(s);
		}
	}
	else
		cout << "Nie mozna otworzyc pliku" << endl;

	float *tabXWsk = tabX;
	float *tabYWsk = tabY;
	float wynik = metodaTrapezow(tabXWsk, tabYWsk, n);
	zapis << "Przyblizona wartosc calki = " << wynik;
	odczyt.close();
	zapis.close();
	system("pause");
}

float metodaTrapezow(float *tabXWsk, float *tabYWsk, int n)
{
	float wynik = 0;
	float h = (*(tabXWsk + n - 1) - *(tabXWsk)) / (n - 1);

	for (int i = 0; i < n-1; i++)
		wynik += h * (*(tabYWsk + i) + *(tabYWsk + i + 1)) / 2;
	return wynik;
}