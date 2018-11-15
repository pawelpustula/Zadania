#include <iostream>

using namespace std;

void kalkulator();

int main()
{
	kalkulator();

	system("pause");
	return 0;
}

void kalkulator()
{
	double a = 0.0, b = 0.0;
	char dzialanie = '\0', decyzja = '\0';

	do
	{
		cout << "\nProsze podac liczbe a oraz liczbe b: ";
		cin >> a >> b;
		cout << "\nProsze podac dzialanie, ktore chcesz wykonac na liczbach a i b (+,-,*,/) ";
		cin >> dzialanie;
		switch (dzialanie)
		{
		case '+':
			cout << a << " + " << b << " = " << a + b << "\n";
			break;
		case '-':
			cout << a << " - " << b << " = " << a - b << "\n";
			break;
		case '*':
			cout << a << " * " << b << " = " << a * b << "\n";
			break;
		case '/':
			if (b == 0)
				cout << "\nNie mozna dzielic przez zero\n";
			else
				cout << a << " / " << b << " = " << a / b << "\n";
			break;
		default:
			cout << "Nieznana operacja\n";
			break;
		}
		cout << "\nCzy chcesz kontynuowac obliczenia? [t/n] ";
		cin >> decyzja;
	} while (decyzja != 'n');
}