#include <iostream>
#include <string>
#include <fstream>

using namespace std;

float interpolacja(float *, float *, int, float);

int main()
{
	float tabX[10];
	float tabY[10];
	int n = 10;
	float arg = 7;
	string s{};
	ofstream zapis;
	zapis.open("wynik.txt");

	ifstream odczyt;
	odczyt.open("dane.txt");
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
		cout << "Nie mozna otworzyc pliku" << endl;

	float *tabXWsk = tabX;
	float *tabYWsk = tabY;
	float wynik = interpolacja(tabXWsk, tabYWsk, n, arg);
	zapis << "W(arg) = " << wynik;

	odczyt.close();
	zapis.close();
	system("pause");
}


float interpolacja(float *tabXWsk, float *tabYWsk, int n, float arg)
{
	float tymczasowaSuma = 0, calkowitaSuma = 0, iloczyn = 1;
	for (int i = 0; i < n; i++)
	{
		tymczasowaSuma = 0;
		iloczyn = 1;
		for (int j = 0; j < n; j++)
		{
			if (j != i)
			iloczyn *= (arg - *(tabXWsk + j)) / (*(tabXWsk + i) - *(tabXWsk + j));
		}
		tymczasowaSuma = *(tabYWsk + i) * iloczyn;
		calkowitaSuma += tymczasowaSuma;
	}
	return calkowitaSuma;
}