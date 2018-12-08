#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <math.h>
#include "Header.h"
#pragma warning(disable : 4996)

const int N = 5;

void mode1() 
{
	void(*funcs[N])(double x , double accuracy, int n_elements) = { my_sin, my_cos, my_exp, my_arcsin, my_tg };
	char *funcNames[N] = { "sin", "cos", "exp", "arcsin", "tg" };
	char enteredFunc[10];
	double accuracy = 0.0002, x = 0;
	int i = N, n_elements = 1000;

	while (i == N)
	{
		system("cls");
		printf("Enter your task(Example: sin 3.14): ");
		scanf("%s %lf", enteredFunc, &x);
		printf("\nEnter accuracy (>= 0.000001): ");
		scanf("%lf", &accuracy);
		printf("\nEnter number of elements of a series(between 1 and 1000): ");
		scanf("%d", &n_elements);
		printf("\nYou enter: %s %lf\nAccuracy: %lf\nNumber of elements: %d\n", enteredFunc, x, accuracy, n_elements);
		for (i = 0; i < N; i++)
			if (!strcmp(funcNames[i], enteredFunc))
			{
				funcs[i](x, accuracy, n_elements + 1);
				break;
			}
		if (i == N)
		{
			printf("Incorrect function.\nPress any button...");
			_getch();
		}
	}
}

void mode2()
{
	void(*funcs[N])(double x, int n_experiments) = { my_sin, my_cos, my_exp, my_arcsin, my_tg};
	char *funcNames[N] = { "sin", "cos", "exp", "arcsin", "tg" };
	char enteredFunc[10];
	double x = 0;
	int i = N, n_experiments = 25;

	while (i == N)
	{
		system("cls");
		printf("Enter your task(Example: sin 3.14): ");
		scanf("%s %lf", enteredFunc, &x);
		printf("\nEnter number of experiments(between 1 and 25): ");
		scanf("%d", &n_experiments);
		printf("\nYou enter: %s %lf\nNumber of experiments: %d\n", enteredFunc, x, n_experiments);
		for (i = 0; i < N; i++)
			if (!strcmp(funcNames[i], enteredFunc))
			{
				funcs[i](x, n_experiments + 1);
				break;
			}
		if (i == N)
		{
			printf("Incorrect function.\nPress any button...");
			_getch();
		}
	}
}


int main() 
{
	void (*modes[2])() = { mode1 , mode2 };
	printf("Hello!\nPress any button...");
	_getch();
	int a = -1;
	while (a != 1 && a != 2)
	{
		system("cls");
		printf("Choose mode (1/2): ");
		scanf_s("%d", &a);
	}
	modes[a-1]();
	system("cls");
	printf("Good Bye!");
	_getch();
}