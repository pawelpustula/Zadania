#include <iostream>
#include <fstream>
#include <string>

using namespace std;

float metodaProstokatow(float *, float *, int);

int main()
{
	float tabX[5];
	float tabY[5];
	int n = 5; // n punktow
	string s{};
	ifstream odczyt;
	odczyt.open("dane.txt");
	ofstream zapis;
	zapis.open("wynik.txt");
	if (odczyt.is_open() && zapis.is_open())
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
		cout << "Nie udalo sie otworzyc odczytu" << endl;

	float *tabXWsk = tabX;
	float *tabYWsk = tabY;
	float wynik = metodaProstokatow(tabXWsk, tabYWsk, n);
	zapis << "Przyblizona wartosc calki = " << wynik;
	odczyt.close();
	zapis.close();

	system("pause");
}

float metodaProstokatow(float *tabXWsk, float *tabYWsk, int n)
{
	float wynik = 0;
	float dx = (*(tabXWsk + n-1) - *(tabXWsk)) / (n-1); // dzielenie przez n-1, bo podzia³ na 4 prostok¹ty
	for (int i = 0; i < n-1; i++)
		wynik += dx * *(tabYWsk + i);
	return wynik;
}