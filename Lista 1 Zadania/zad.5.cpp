#include <iostream>


using namespace std;

void rysujSzachownice(int);

int main()
{
	int n = 0;
	cout << "Prosze podac n: ";
	cin >> n;
	rysujSzachownice(n);

	system("pause");
	return 0;
}

void rysujSzachownice(int n)
{
	for (int i = 1; i <= n; i++)     // p�tla "pionowa", i - numer rz�du
	{
		for (int j = 1; j <= n; j++) // p�tla "pozioma", j - numer miejsca w rz�dzie
		{
			if (i % 2 == 0)          // dla rz�d�w o numerach parzystych
			{
				if (j % 2 == 0)      // je�li miejsce w rz�dzie na numer parzysty, to wypisuj� spacj�
					cout << "#"; 
				else                 // je�li miejsce w rz�dzie ma numer nieparzysty, to wypisuj� kratk�
					cout << " ";
			}
			else                     // dla rz�d�w o numerach nieparzystych
			{
				if (j % 2 == 0)      // je�li miejsce w rz�dzie ma numer parzysty, to wypisuj� spacj�
					cout << " ";
				else                 // je�li miejce w rz�dzie ma numer nieparzysty, to wypisuj� kratk�
					cout << "#";
			}
		}
		cout << "\n";                // nowa linia po ka�dym rz�dzie
	}
}