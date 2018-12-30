#include <iostream>
#include <string>

using namespace std;

enum class Wydawnictwo { PWN, Helion, Operon, NowaEra, WSIP};

struct Autor 
{
	string imie;
	string nazwisko;
	void drukuj();
};

void Autor::drukuj() 
{
	cout << imie << " " << nazwisko;
}

struct Ksiazka 
{
	string tytul;
	Autor autor; 
	Wydawnictwo w;
	Ksiazka *kolejna;
	void drukuj();
};

void Ksiazka::drukuj() 
{
	cout << autor.imie << " " << autor.nazwisko << "  " << tytul << "  ";
	
	switch (w)
	{
	case Wydawnictwo::PWN:
		cout << "PWN";
		break;
	case Wydawnictwo::Helion:
		cout << "Helion";
		break;
	case Wydawnictwo::Operon:
		cout << "Operon";
		break;
	case Wydawnictwo::NowaEra:
		cout << "Nowa Era";
		break;
	case Wydawnictwo::WSIP:
		cout << "WSIP";
		break;
	}
}

struct Ksiegozbior 
{
	Ksiazka *pierwsza;
	Ksiazka *szukaj(string tytul);
	void dodaj(Autor a, string tytul, Wydawnictwo w);
	void usun(string tytul);
	void drukuj();
};

void Ksiegozbior::dodaj(Autor a, string tytul, Wydawnictwo w)
{
	Ksiazka *Nowa = new Ksiazka;

	Nowa->tytul = tytul;
	(Nowa->autor).imie = a.imie;
	(Nowa->autor).nazwisko = a.nazwisko;
	Nowa->w = w;
	Nowa->kolejna = nullptr;

	if (pierwsza == nullptr)
		pierwsza = Nowa;
	else
	{
		Ksiazka *biezaca = pierwsza;

		while (biezaca->kolejna != nullptr)
		{
			biezaca = biezaca->kolejna;
		}
		biezaca->kolejna = Nowa;
	}
}

void Ksiegozbior::drukuj()
{
	Ksiazka *biezaca = pierwsza;

	while (biezaca != nullptr)
	{
		biezaca->drukuj();
		cout << endl;
		biezaca = biezaca->kolejna;
	}
}

void Ksiegozbior::usun(string tytul)
{
	Ksiazka *wczesniejsza = nullptr, *biezaca = nullptr;

	if (pierwsza == nullptr)
		return;
	if (pierwsza->tytul == tytul)
	{
		biezaca = pierwsza->kolejna;
		delete pierwsza;
		pierwsza = biezaca;
	}
	else
	{
		biezaca = pierwsza;
		wczesniejsza = pierwsza;
		while (biezaca->tytul != tytul)
		{
			wczesniejsza = biezaca;
			biezaca = biezaca->kolejna;
		}
		if (biezaca != nullptr)
		{
			wczesniejsza->kolejna = biezaca->kolejna;
			delete biezaca;
		}
	}
}

Ksiazka * Ksiegozbior::szukaj(string tytul)
{
	Ksiazka *biezaca = pierwsza;

	while (biezaca != nullptr)
	{
		if (biezaca->tytul == tytul)
			return biezaca;
		biezaca = biezaca->kolejna;
	}
	return nullptr;
}

int main()
{
	Ksiegozbior mojeKsiazki;
	mojeKsiazki.pierwsza = nullptr;
	Ksiazka *szukana = nullptr;

	mojeKsiazki.dodaj(Autor{ "Adam", "Mickiewicz" }, "Pan Tadeusz", Wydawnictwo::PWN);
	mojeKsiazki.dodaj(Autor{ "Boleslaw", "Prus" }, "Lalka", Wydawnictwo::NowaEra);
	mojeKsiazki.dodaj(Autor{ "Stanislaw", "Wyspianski" }, "Wesele", Wydawnictwo::Helion);
	mojeKsiazki.drukuj();

	mojeKsiazki.usun("Lalka");
	cout << endl << "Po usunieciu:" << endl << endl;
	mojeKsiazki.drukuj();

	szukana = mojeKsiazki.szukaj("Wesele");
	if (szukana != nullptr)
	{
		cout << endl << "Znaleziono szukana ksiazke:" << endl << endl;
		szukana->drukuj();
	}
	else
		cout << endl << "Nie znaleziono szukanej ksiazki." << endl;
	
	cout << endl;
	system("pause");
}
