#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <iomanip>

using namespace std;

float monteCarlo(int);

int main()
{
	srand((unsigned)time(nullptr));
	int n = 1000; // n - liczba wszystkich punktow
	cout << "Przyblizona wartosc liczby pi wynosi " << setprecision(5) << monteCarlo(n) << endl;
	system("pause");
}

float monteCarlo(int n)
{
	float *tabXWsk = new float[n];
	float *tabYWsk = new float[n];
	float x = 0, y = 0; // wspó³rzêdne punktów   
	float l = 0; // licznik punktów w kole
	float pi = 0;

	for (int i = 0; i < n; i++)
	{
		x = -1 + ((float)rand() / (float)(RAND_MAX + 1)) * 2; // dla przedzialu <a,b> a = -1, b = 1, c = 2 = b - a;
		*(tabXWsk + i) = x;

		y = -1 + ((float)rand() / (float)(RAND_MAX + 1)) * 2;
		*(tabYWsk + i) = y;
	}
	for (int i = 0; i < n; i++)
	{
		if ((*(tabXWsk + i) * *(tabXWsk + i) + *(tabYWsk + i) * *(tabYWsk + i)) <= 1) // 1 - promieñ
			l++;
	}

	pi = 4 * (l / n);
	delete[] tabXWsk;
	delete[] tabYWsk;
	return pi;
}