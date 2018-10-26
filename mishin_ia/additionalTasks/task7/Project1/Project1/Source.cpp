#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

#define LENGTH 2



typedef struct  {
	char firstName[30];
	char lastName[40];
	char patronymic[40];
	char telNumber[13];
	char email[50];
	char organization[30];
	char position[20];
	
}human;

human humans[LENGTH];

void init() {
	strcpy_s(humans[0].firstName, "Mark");
	strcpy_s(humans[0].lastName, "Hohlov");
	strcpy_s(humans[0].patronymic, "Olegovich");
	strcpy_s(humans[0].telNumber, "+79023455678");
	strcpy_s(humans[0].email, "dsfk@mail.ru");
	strcpy_s(humans[0].organization, "Intel");
	strcpy_s(humans[0].position, "Stager");

	strcpy_s(humans[1].firstName, "Pavel");
	strcpy_s(humans[1].lastName, "Petrov");
	strcpy_s(humans[1].patronymic, "Petrovich");
	strcpy_s(humans[1].telNumber, "+79033442343");
	strcpy_s(humans[1].email, "sdfksdlf@gmail.com");
	strcpy_s(humans[1].organization, "Intel");
	strcpy_s(humans[1].position, "Manager");
}

void showContacts(int length) {
	for (int i = 0; i < length; i++)
	{
		printf("\n%d: %s %s %s %s ", i, humans[i].lastName, humans[i].firstName, humans[i].patronymic, humans[i].telNumber);
	}
}

void showChoosenContact(int number ,int length) {
	printf("\n1)Last Name: %s\n2)First Name: %s\n3)Patronymic: %s\n4)Telephone Number: %s\n5)Email: %s\n6)Organization: %s\n7)Position: %s \n", humans[number].lastName, humans[number].firstName, humans[number].patronymic, humans[number].telNumber, humans[number].email, humans[number].organization, humans[number].position);
	printf("Edit this contact(y) or exit to list of contacts(n)?\n");
	printf("(y/n):");
	char a;
	a = _getch();
	printf("%c", a);
	if (a == 'y')
	{
		printf("\nEnter field number, that you want to edit{1,...,7}: ");
		int field;
		scanf_s("%d", &field);
		char newInfo[50];
		switch (field)
		{
		case 1:
			printf("\nNew Last Name: ");
			scanf_s("%s", &newInfo);
			strcpy_s(newInfo, humans[number].lastName);
		default:
			break;
		}
	}
	else
	{
		system("cls");
		showContacts(length);
	}
}



int main() {
	int length = LENGTH;
	init();
	showChoosenContact(1,length);
	_getch();
	_getch();
	return 0;
}