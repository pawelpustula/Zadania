#include<cmath>

double fun(double x)
{
	return 2 * x - sqrt(x + 1);
}

double wielomian(double *wsp, int stopien, double x)
{
	double wynik = 0;
	int y = stopien;
	for (int i = 0; i <= stopien; i++)
	{
		wynik += *(wsp + i) * pow(x, y--);
	}
	return wynik;
}