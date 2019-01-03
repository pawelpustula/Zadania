#include <iostream>
#include <string>
#include <fstream>

using namespace std;
// pA - plik, z ktorego odczytujemy - tekst.txt
// pB - plik do zapisu - zakodowany.txt
// przesuniecie - klucz = 7

void szyfrowanie (string pA, string pB, int przesuniecie)           // otworzyc plik do czytania, sprawdzic ile ma znakow np. ustawiajac kurors na koncu instrukcja tellg, utworzyc tablice znakow, gdzie je wpiszemy, 
                                                                    //przeksztalcic tablice znakow szyfrem i wpisac do nowego pliku

int main(int argc, char *argv[]) // argc - liczba argumentow w linii polecen
{
	if (argc < 4)
	{
		cout << "Za mala liczba parametrow. Poprawna liczba parametrow to 4. " << endl;
		cout << "parametr 1 - nazwa programu" << endl;
		cout << "parametr 2 - nazwa pliku do szyforwania/deszyfrowania" << endl;
		cout << "parametr 3 - nazwa pliku do wpisania zaszyfrowanego/odszyfrowanego tekstu" << endl;
		cout << "parametr 4 klucz" << endl;
	}
	else
	{
		szyfrowanie(argv[1], argv[2], atoi(argv[3]));
	}
	system("pause");
	return 0;
}

void szyfrowanie(string pA, string pB, int przesuniecie)
{
	ifstream odczyt;
	ofstream zapis;
	char tab[100] = {};
	zapis << pA;
	odczyt.open("doZakodowania.txt", ios::in);
	if (odczyt.is_open())
	{
		while (!odczyt.eof())
		{
			getline(odczyt, pA);
		}
	}
	else
		cout << "Nie mozna otworzyc pliku." << endl;
	odczyt.close();








	zapis.close();
	odczyt.close();

}