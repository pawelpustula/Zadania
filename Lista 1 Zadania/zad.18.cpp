#include <iostream>

using namespace std;

void pobierzWspolczynniki(double[2][3]);
void rozwiazRownania(double[2][3]);

int main()
{
	double wspolczynniki[2][3] = { 0 }; // tablica wspolczynnikow
	pobierzWspolczynniki(wspolczynniki);
	rozwiazRownania(wspolczynniki);

	system("pause");
	return 0;
}

void pobierzWspolczynniki(double wspolczynniki[2][3])
{
	cout << "Prosze podac wspolczynniki ukladu rownan\nax + by = c\ndx + ey = f\n";
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cin >> wspolczynniki[i][j];
		}
	}
}

void rozwiazRownania(double wspolczynniki[2][3])
{
	double x = 0.0, y = 0.0, w = 0.0, wx = 0.0, wy = 0.0;

	// metoda wyznacznikow
	w = wspolczynniki[0][0] * wspolczynniki[1][1] - wspolczynniki[0][1] * wspolczynniki[1][0];   // w - wyznacznik glowny
	wx = wspolczynniki[0][2] * wspolczynniki[1][1] - wspolczynniki[0][1] * wspolczynniki[1][2];  // wx, wy - wyznaczniki, w ktorych wspolczynniki przy x, y zastepuje wyrazami wolnymi
	wy = wspolczynniki[0][0] * wspolczynniki[1][2] - wspolczynniki[0][2] * wspolczynniki[1][0];
	if (w == 0 && wx == 0 && wy == 0)
		cout << "Uklad ma nieskonczenie wiele rozwiazan.\n";
	else if (w == 0 && (wx != 0 || wy != 0))
		cout << "Uklad nie ma rozwiazan.\n";
	else
	{
		x = wx / w;
		y = wy / w;
		cout << "x = " << x << "\n" << "y = " << y << "\n";
	}
	
}