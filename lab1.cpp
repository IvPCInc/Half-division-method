/* решить уравнение x + √x + ∛x - 2.5 = 0 
на отрезке [0,4 : 1] методом половинного деления*/

#include <iostream>
#include <cmath>
using namespace std;

double F(double x) {
	return x + sqrt(x) + pow(x, 1.0 / 3.0) - 2.5;
}

double FindSqrt(double a, double b, double eps ) {
	double x;
	x = (a + b) / 2; // иницилизация x как середина отрезка
	while ((b - a) > eps) { // пока отрезок не станет меньше eps
		x = (a + b) / 2; // пересчитываем как середину отрезка
		if (F(a) * F(x) < 0) {
			b = x; // корень находиться в левой половине [a,x]
		}
		else
			a = x; // корень находиться в правой половине [b,x]
		x = (a + b) / 2;
	}
	return x;
}

int main() {
	setlocale(LC_ALL, "Russian");
	double a = 0.4, b = 1, eps;
	cout << "Введите значение eps: ";
	cin >> eps;
	double find = FindSqrt(a, b, eps);

	cout << "Корень уравнения = " << find << endl;
	return 0;
}