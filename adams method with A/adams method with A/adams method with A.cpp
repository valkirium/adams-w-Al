﻿#include "iostream"
#include "vector"
#include "cmath"

using namespace std;

double F(double y, double t)
{
	return -t * y + (1 - t) * exp(t) * pow(y, 2);
}

int main()
{
	setlocale(LC_ALL, "ru");

	double h = 0.1, e = 0.1, eps = 1, t = 0, y2;

	vector<double> y;

	

	y.push_back(1);
	y.push_back(0);

	while (eps > e)
	{
		t = h;

		y[1] = y[0] + h * F(y[0], t);
		y2 = y[0] + (h / 2) * F(y[0], t);

		eps = abs(y2 - y[0]);

		
		y[1] = y2;
	}

	t = h;

	for (int i = 2; i < 4; i++)
	{
		t += h;
		y.push_back(y[i - 1] + h * F(y[i - 1], t));
	}

	for (int i = 0; i < 4; i++)
	{
		cout << "y = " << y[i] << '\t' << 1 / (-exp(t) + 2 * exp(0.5 * pow(t, 2))) << "\t h = " << h << "\t t = " << i * h << endl;
	}

	eps = abs(y[3] + 1 / (-exp(t*3) + 2 * exp(0.5 * pow(t*3, 2))));

	for (int i = 4; t <= 1; i++)
	{
		t += h;

		y.push_back(y[i - 1] + (h / 24) * (55 * (F(y[i - 1], t - h)) - 59 * (F(y[i - 2], t - 2 * h)) + 37 * (F(y[i - 3], t - 3 * h)) - 9 * (F(y[i - 4], t - 4 * h))));

		cout << "y = " << y[i] << '\t' << -1 / (-1 + i * h) << "\t h = " << h << "\t t = " << i * h << endl;

		if (abs(y[i] + 1 / (-1 + i * h)) > eps)
		{
			eps = abs(y[i] + 1 / (-exp(t*i) + 2 * exp(0.5 * pow(t*i, 2))));
		}
	}

	cout << "\n\t r(h) = " << eps << endl;

	system("pause");
}