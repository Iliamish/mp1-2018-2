#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <math.h>
#include "Header.h"

#define M_PI 3.1415926535897932384626433832795


double power(double x, int deg)
{
	double result = 1;
	for (int i = 1; i <= deg; i++)
	{
		result *= x;
	}
	return result;
}

double combinations(int n, int k)
{
	double result = 1;
	for (unsigned i = 1; i <= n-k; i++)
	{
		result *= double(k + i) / double(i);
	}
	return result;
}

double bernulli(int n) 
{
	double bernull[300] = {0};
	bernull[0] = 1.;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			bernull[i] += combinations(i + 1, j + 1) * bernull[i - j];
		}
		bernull[i] *= (-1.) / double(i + 1);
	}
	return bernull[n];
}

void my_sin(double x, double accuracy, int n_elements) 
{
	int i;
	double result = 0, middleres;
	double machineResult = sin(x * M_PI / 180);
	
	printf("\nReference value: %lf", machineResult);

	x *= M_PI / 180;
	middleres = x;
	for (i = 1; i < n_elements; i++)
	{
		result += middleres;
		middleres *= ((-1) * power(x,2)) / (double(2 * i) * double(2*i+1));
		if (fabs(result - machineResult) < accuracy) break;
	}
	printf("\nFunction value: %lf\nAccuracy: %lf\nNumber of elements: %d", result, fabs(result - machineResult), i - 1);
	_getch();
}

void my_sin(double x, int n_experiments) 
{
	int i;
	double result = 0, middleres;
	double machineResult = sin(x * M_PI / 180);

	printf("\nReference value: %lf", machineResult);

	x *= M_PI / 180;
	middleres = x;
	for (i = 1; i < n_experiments; i++)
	{
		result += middleres;
		middleres *= ((-1) * power(x, 2)) / (double(2 * i) * double(2 * i + 1));
//		printf("\n*%d* Function value: %lf Accuracy: %lf", resu);
	}
	_getch();
}

void my_cos(double x, double accuracy, int n_elements) 
{
	int i;
	double result = 0, middleres;
	double machineResult = cos(x * M_PI / 180);

	printf("\nReference value: %lf", machineResult);

	x *= M_PI / 180;
	middleres = 1;
	for (i = 1; i < n_elements; i++)
	{
		result += middleres;
		middleres *= ((-1) * power(x, 2)) / (double(2 * i) * double(2 * i - 1));
		if (fabs(result - machineResult) < accuracy) break;
	}
	printf("\nFunction value: %lf\nAccuracy: %lf\nNumber of elements: %d", result, fabs(result - machineResult), i - 1);
	_getch();
}

void my_cos(double x, int n_experiments)
{

}

void my_exp(double x, double accuracy, int n_elements) 
{
	int i;
	double result = 1.0, middleres;
	double machineResult = exp(x);

	printf("\nReference value: %lf", machineResult);

	middleres = x;
	for (i = 1; i < n_elements; i++)
	{
		result += middleres;
		middleres *= x / double(i + 1);
		if (fabs(result-machineResult) < accuracy) break; 
	}
	printf("\nFunction value: %lf\nAccuracy: %lf\nNumber of elements: %d", result, fabs(result - machineResult), i - 1);
	_getch();
}

void my_exp(double x, int n_experiments)
{

}

void my_tg(double x, double accuracy, int n_elements)
{
	x *= M_PI / 180;
	int i;
	double result = 0, middleres1 = 1., middleres2 = 1.;
	double machineResult = tan(x);

	printf("\nReference value: %lf", machineResult);

	for (i = 1; i < n_elements; i++)
	{
		double berni = bernulli(2 * i) / bernulli (2 * i - 2);
		middleres1 *= ((-4) * power(x, 2) * berni) / (double(2 * i) * double(2 * i - 1));
		middleres2 *= ((16) * power(x, 2) * berni) / (double(2 * i) * double(2 * i - 1));
		result += middleres1 + middleres2;
		if (fabs(result - machineResult) < accuracy) break;
		printf("\nFunction value: %lf\nAccuracy: %lf\nNumber of elements: %d", result, fabs(result - machineResult), i - 1);
	}
	printf("\nFunction value: %lf\nAccuracy: %lf\nNumber of elements: %d", result, fabs(result - machineResult), i - 1);
	_getch();
}

void my_tg(double x, int n_experiments) 
{

}

void my_arcsin(double x, double accuracy, int n_elements) 
{
	int i;
	double result = 0, middleres;
	double machineResult = sin(x * M_PI / 180);

	printf("\nReference value: %lf", machineResult);

	x *= M_PI / 180;
	middleres = x;
	for (i = 1; i < n_elements; i++)
	{
		result += middleres;
		middleres *= ((-1) * power(x, 2)) / (double(2 * i) * double(2 * i + 1));
		if (fabs(result - machineResult) < accuracy) break;
	}
	printf("\nFunction value: %lf\nAccuracy: %lf\nNumber of elements: %d", result, fabs(result - machineResult), i - 1);
	_getch();
}

void my_arcsin(double x, int n_experiments) 
{

}
