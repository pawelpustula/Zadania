#include <iostream>
#include"naglowek.h"

using namespace std;

double zwyklaFunkcja(double x)
{
	return x*x - 3;
}

int main()
{
	double w[3] = { 1, 2, 1 };
	int stopien = 2;
	double x = 3;

	cout << wielomian(w, stopien, x) << endl;
	//double(*wskDoFun)(double) = fun; // nazwa funkcji jest tez jej adresem
	//cout << bisekcja(wskDoFun, 5, 7) << endl;
	//cout << bisekcja(&zwyklaFunkcja, 0, 4) << endl;
	system("pause");
}