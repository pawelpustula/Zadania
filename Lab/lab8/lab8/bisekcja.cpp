#include"naglowek.h"

double bisekcja(double(*f)(double), double a, double b)
{
	double m = (a + b) / 2;

	while ( (b - a) > blad)
	{
		m = (a + b) / 2;
		if (f(m) * f(a) < 0)
			b = m;
		else
			a = m;
	}

	return m;
}