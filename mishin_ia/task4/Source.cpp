#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>

#define length 5

typedef struct{
	char *name;
	int price;
	int sale;
	int code[4];
	int quantity;
}product;


int main() {

	product products[length];
	products[0] = { "Cheese", 100 , 5 , {2,1,3,4} , 0 };
	products[1] = { "Meat" , 200 , 10 , {5,1,3,4} , 0};
	products[2] = { "Milk", 50 , 20 , {8,1,3,4} , 0 };
	products[3] = { "Bread", 30 , 2 , {7,1,3,4} , 0 };
	products[4] = { "Salt", 90 , 30 , {9,1,3,4} , 0 };

	printf("Hello!");
	 
	while (true)
	{
		int code[4];
		printf("\nPlese enter product code, enter space between each number: ");
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
			products[prodType].quantity++;
			printf("Name: %s, price: %d, sale: %d%% ", products[prodType].name, products[prodType].price, products[prodType].sale);
		}
		printf("\nPress spase to finish add products to check, or enter for continue: ");
		char a = _getch();
		if ((int)a == 32) 
			break;
	}

	printf("\n\n **** Your check ****\n");

	int cost = 0;
	float saleCost = 0.0f;

	for (int i = 0; i < length; i++)
	{
		if (products[i].quantity != 0)
		{
			printf("\n%s  %d  %d  %d", products[i].name, products[i].price, products[i].quantity, products[i].price * products[i].quantity);
			cost += products[i].price * products[i].quantity;
			saleCost += products[i].price * products[i].quantity * (float)(1 - (float)products[i].sale / 100);
		}
	}
	printf("\n\nCost: %d\nSale: %3.1f%%\nCost with discount: %d", cost, 100 * (float)(1 - (float)(saleCost / cost)), (int)saleCost);
	_getch();
	return 0;
}