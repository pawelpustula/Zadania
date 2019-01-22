#include <iostream>
#include <fstream>
#include <string>

using namespace std;

float *pochodnaDyskretna(float *, float *, int, float);

int main()
{
	int n = 0;
	float arg = 1.75;
	float *tabXWsk = nullptr;
	float *tabYWsk = nullptr;
	string s;
	ifstream odczyt;
	odczyt.open("dane.txt");
	if (odczyt.is_open())
	{
		while (getline(odczyt, s)) // obliczanie liczby wierszy
			n++;
		tabXWsk = new float[n]; // dynamiczne alokowanie pamiêci
		tabYWsk = new float[n];
	}
	else
		cout << "Nie udalo sie otworzyc pliku";
	odczyt.close();

	odczyt.open("dane.txt");
	if (odczyt.is_open())
	{
		for (int i = 0; i < n; i++) // zapis wspolrzednych x do tablicy oraz wspolrzednych y do tablicy
		{
			odczyt >> s;
			*(tabXWsk + i) = stof(s);
			odczyt >> s;
			*(tabYWsk + i) = stof(s);
		}
	}
	else
		cout << "Nie udalo sie otworzyc pliku";

	float *wyniki = pochodnaDyskretna(tabXWsk, tabYWsk, n, arg);
	ofstream zapis;
	zapis.open("wyniki.txt");
	zapis << "Pochodna dyskretna policzona metoda ilorazu roznicowego wstecznego: " << *wyniki << endl;
	zapis << "Pochodna dyskretna policzona metoda ilorazu roznicowego przedniego: " << *(wyniki + 1) << endl;
	zapis << "Pochodna dyskretna policzona metoda ilorazu roznicowego centralnego: " << *(wyniki + 2) << endl;
	
	delete[] tabXWsk;
	delete[] tabYWsk;
	delete[]wyniki;
	odczyt.close();
	zapis.close();
	system("pause");
}

float *pochodnaDyskretna(float *tabXWsk, float *tabYWsk, int n, float arg)
{
	float *tabWynikow = new float[3]; // tablica na 3 pochodne
	for (int i = 0; i < n; i++)
	{
		if (*(tabXWsk + i) == arg)
		{
			*tabWynikow = (*(tabYWsk + i) - *(tabYWsk + i - 1)) / (*(tabXWsk + i) - *(tabXWsk + i - 1)); // iloraz wsteczny
			*(tabWynikow + 1) = (*(tabYWsk + i + 1) - *(tabYWsk + i)) / (*(tabXWsk + i + 1) - *(tabXWsk + i)); // iloraz przedni
			*(tabWynikow + 2) = (*(tabYWsk + i + 1) - *(tabYWsk + i - 1)) / (*(tabXWsk + i + 1) - *(tabXWsk + i - 1)); // iloraz centralny
			return tabWynikow;
		}
	}
}