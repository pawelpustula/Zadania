#include <iostream>
#include <string>
#include <fstream>

using namespace std;

void szyfrowanie(string pA, string pB, int przesuniecie);

int main(int argc, char *argv[]) 
{
	if (argc < 4)
	{
		cout << "Za mala liczba parametrow. Poprawna liczba parametrow to 4. " << endl;
		cout << "parametr 1 - nazwa programu" << endl;
		cout << "parametr 2 - nazwa pliku do szyfrowania/deszyfrowania" << endl;
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
	ifstream doZakodowania(pA, ios::ate);
	ofstream odkodowany{ "odkodowany.txt" };
	fstream zakodowany(pB);
	if (doZakodowania.is_open() && zakodowany.is_open() && odkodowany.is_open())
	{
		char z;
		int n = doZakodowania.tellg();                  // ilosc znakow w pliku doZakodowania
		doZakodowania.seekg(0, ios::beg);               // ustawienie na poczatek pliku
		int i = 0;
		if (przesuniecie >= 0)                          // kodowanie 
		{
			while (i < n)
			{
					doZakodowania.get(z);
					z += przesuniecie;
					zakodowany << z;
					i++;
			}
		}
		else                                           // dekodowanie
		{
			while (i < n)
			{
					zakodowany.get(z);
					z += przesuniecie;
					odkodowany << z;
					i++;
			}
		}
	}
	else
		cout << "Nie mozna otworzyc plikow." << endl;
	doZakodowania.close();
	odkodowany.close();
	zakodowany.close();
}
