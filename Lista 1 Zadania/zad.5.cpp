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
	for (int i = 1; i <= n; i++)     // pêtla "pionowa", i - numer rzêdu
	{
		for (int j = 1; j <= n; j++) // pêtla "pozioma", j - numer miejsca w rzêdzie
		{
			if (i % 2 == 0)          // dla rzêdów o numerach parzystych
			{
				if (j % 2 == 0)      // jeœli miejsce w rzêdzie na numer parzysty, to wypisujê spacjê
					cout << "#"; 
				else                 // jeœli miejsce w rzêdzie ma numer nieparzysty, to wypisujê kratkê
					cout << " ";
			}
			else                     // dla rzêdów o numerach nieparzystych
			{
				if (j % 2 == 0)      // jeœli miejsce w rzêdzie ma numer parzysty, to wypisujê spacjê
					cout << " ";
				else                 // jeœli miejce w rzêdzie ma numer nieparzysty, to wypisujê kratkê
					cout << "#";
			}
		}
		cout << "\n";                // nowa linia po ka¿dym rzêdzie
	}
}