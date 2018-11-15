#include <iostream>
#include <math.h>

using namespace std;

void liczDelte(double, double, double);

int main()
{
	double a = 0.0, b = 0.0, c = 0.0;
	cout << "Prosze podac wspolczynniki rownania kwadratowego ax^2 + bx + c = 0: ";
	cin >> a >> b >> c;
	liczDelte(a, b, c);
	
	system("pause");
	return 0;
}

void liczDelte(double a, double b, double c)
{
	double delta = 0.0, x1 = 0.0, x2 = 0.0;
	if (a == 0)
		cout << "To nie jest rownanie kwadratowe\n";
	else
	{
		delta = b * b - 4 * a*c;
		if (delta < 0)
		{
			double czescRzeczywista = -b / (2 * a), czescUrojona = sqrt(-delta) / (2 * a);
			cout << "Pierwiastki zespolone rownania kwadratowego to x1 = " << czescRzeczywista << " - " << czescUrojona << "i"
				 << ", x2 = " << czescRzeczywista << " + " << czescUrojona << "i" << "\n";
		}
		else if (delta == 0)
		{
			x1 = -b / (2 * a);
			cout << "Rownanie ma rzeczywisty pierwiastek podwojny rowny " << x1 << "\n";
		}
		else
		{
			x1 = (-b - sqrt(delta)) / (2 * a);
			x2 = (-b + sqrt(delta)) / (2 * a);
			cout << "Pierwiastki rzeczywiste rownania kwadratowego to x1 = " << x1 << ", x2 = " << x2 << "\n";
		}
	}
}