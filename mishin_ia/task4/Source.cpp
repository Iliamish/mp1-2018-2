#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>

#define length 5

typedef struct{
	char *name;
	int price;
	int sale;
	char code[4];
	int quantity;
}product;

typedef struct {
	char firstName[30];
	char lastName[40];
	char patronymic[40];
	char telNumber[12];
	char email[50];
	char organization[30];
	char position[20];

}human;

int main() {

	human humans[4];
	humans[0] = { "Hohlov","Mark" ,"Olegovich", "+79023455678","dsfk@mail.ru"," "," " };
	product products[length];
	products[0] = { "Cheese", 100 , 5 , {2,1,3,4} , 0 };
	products[1] = { "Meat" , 200 , 10 , {5,1,3,4} , 0};
	products[2] = { "Milk", 50 , 20 , {8,1,3,4} , 0 };
	products[3] = { "Bread", 30 , 2 , {7,1,3,4} , 0 };
	products[4] = { "Salt", 90 , 30 , {9,1,3,4} , 0 };

	printf("Hello!\nProducts in warehouse:\n");

	for (int i = 0; i < length; i++)
	{
		printf("%10s code: ", products[i].name);
		for (int j = 0; j < 4; j++)
		{
			printf("%d ", products[i].code[j]);
		}
		printf("\n");
	}

	char a = 0;

	while (true)
	{
		int code[4];
		if (a != 'g')
			printf("\nPlese enter product code, enter space between each number: ");
		else
			printf("\nPlease enter code of purchase, that you want to cancel: ");

		scanf_s("%d %d %d %d", &code[0], &code[1], &code[2], &code[3]);
		int prodType = -1;

		for (int i = 0; i < length; i++)
		{
			int j = 0;
			for (j = 0; j < 4; j++)
			{
				if (code[j] != products[i].code[j])
				{
					break;
				}
			}
			if (j == 4)
			{
				prodType = i;
				break;
			}
		}
		if (prodType == -1)
		{
			printf("\nWrong code.\n");
		}
		else
		{
			if (a != 'g')
			{
				products[prodType].quantity++;
				printf("Name: %s, price: %d, sale: %d%% ", products[prodType].name, products[prodType].price, products[prodType].sale);
			}
			else
			{
				products[prodType].quantity--;
				printf("Canceled: %s", products[prodType].name);
			}
		}
		printf("\nPress *spase* to finish adding products to check *enter* for continue\nOr *g* for call Galya and cansel purchase: ");
		a = _getch();
		if ((int)a == 32) 
			break;
	}

	printf("\n\n      **** Your check ****\n");

	int cost = 0;
	float saleCost = 0.0f;

	for (int i = 0; i < length; i++)
	{
		if (products[i].quantity != 0)
		{
			printf("\n%10s  %5d  %2d  %5d", products[i].name, products[i].price, products[i].quantity, products[i].price * products[i].quantity);
			cost += products[i].price * products[i].quantity;
			saleCost += products[i].price * products[i].quantity * (float)(1 - (float)products[i].sale / 100);
		}
	}
	printf("\n");
	for (int i = 0; i < 33; i++)
	{
		printf("*");
	}
	printf("\n\nCost: %d\nSale: %3.1f%%\nCost with discount: %d", cost, 100 * (float)(1 - (float)(saleCost / cost)), (int)saleCost);
	_getch();
	return 0;
}