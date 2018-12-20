#include <iostream>
#include <string>

using namespace std;

enum class Wydawnictwo { PWN = 1, Helion, Operon };

struct Autor {
	string imie;
	string nazwisko;
	void drukuj();
};

void Autor::drukuj() {
	cout << imie << " " << nazwisko << endl;
}

struct Ksiazka {
	string tytul;
	Autor autor; // obiekt typu Autor
	Wydawnictwo w;
	Ksiazka *kolejna;
	void drukuj(); // drukuje imie, nazwisko i tytul jednej ksiazki
};

void Ksiazka::drukuj() {
	cout << autor.imie << " " << autor.nazwisko << " " << tytul << endl;
}

struct Ksiegozbior {
	Ksiazka *pierwsza;
	Ksiazka *szukaj;
	void dodaj(Autor a, string tytul, Wydawnictwo W);
	void usun();
	void drukuj();
};

int main()
{
	Wydawnictwo wydawnictwo1 = Wydawnictwo::PWN;
	Autor autor1 = { "Adam", "Mickiewicz" };
	autor1.drukuj();
	Ksiazka ksiazka1 = { "Pan Tadeusz", autor1, wydawnictwo1};
	ksiazka1.drukuj();


	cout << endl;
	system("pause");
}

/*
lista jednokierunkowa
ksiegozbior mojeKsiazki
mojeKsiazki.dodaj(Autor{Adam,Mickiewicz}, Pan Tadeusz, Wydawnictwo PWN)
*/