#include <iostream>

using namespace std;

int zliczPary(char[]);

int main()
{
	char napis[1024] = {};
	cout << "Prosze podac napis: ";
	cin.getline(napis, 1024);
	cout << "Ilosc par sasiadujacych ze soba liter 'o' w podanym napisie: " << zliczPary(napis) << "\n";
	system("pause");
	return 0;
}

int zliczPary(char napis[])
{
	int licznik = 0;
	for (int i = 0; i < strlen(napis); i++)
	{
		// jezeli wystepuja dwie litery 'o' lub 'O' obok siebie, to znaleziono pare
		if ( (napis[i] == 'o' || napis[i] == 'O') && (napis[i + 1] == 'o' || napis[i + 1] == 'O') )
			licznik++;
	}
	return licznik;
}