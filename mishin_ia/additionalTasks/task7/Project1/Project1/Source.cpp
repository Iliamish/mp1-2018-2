#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <malloc.h>
#include "Header.h"

typedef struct  {
	char firstName[30];
	char lastName[40];
	char patronymic[40];
	char telNumber[13];
	char email[50];
	char organization[30];
	char position[20];	
}human;

human *humans;
int LENGTH = 3;

void init() {
	humans = (human *)calloc(LENGTH, sizeof(human));

	strcpy_s(humans[0].firstName, "Mark");
	strcpy_s(humans[0].lastName, "Hohlov");
	strcpy_s(humans[0].patronymic, "Olegovich");
	strcpy_s(humans[0].telNumber, "+79023455678");
	strcpy_s(humans[0].email, "dsfk@mail.ru");
	strcpy_s(humans[0].organization, "Intel");
	strcpy_s(humans[0].position, "Stager");

	strcpy_s(humans[1].firstName, "Pavel");
	strcpy_s(humans[1].lastName, "Hetrov");
	strcpy_s(humans[1].patronymic, "Petrovich");
	strcpy_s(humans[1].telNumber, "+79033442343");
	strcpy_s(humans[1].email, "sdfksdlf@gmail.com");
	strcpy_s(humans[1].organization, "Intel");
	strcpy_s(humans[1].position, "Manager");

	strcpy_s(humans[2].firstName, "Pavel");
	strcpy_s(humans[2].lastName, "Avrow");
	strcpy_s(humans[2].patronymic, "Petrovich");
	strcpy_s(humans[2].telNumber, "+79033442343");
	strcpy_s(humans[2].email, "sdfksdlf@gmail.com");
	strcpy_s(humans[2].organization, "Intel");
	strcpy_s(humans[2].position, "Manager");
}

void putInOrder(int length) {
	for (int i = 1; i < length; i++)
	{
		for (int j = i; j > 0; j--)
		{
			if (strcmp(humans[j].lastName, humans[j - 1].lastName) < 0)
				swap(j, j - 1);
		}
	}
};

void swap(int idx1, int idx2)  { 
	human swaper;
	swaper = humans[idx1];
	humans[idx1] = humans[idx2];
	humans[idx2] = swaper;
}

void shift(int number) {
	for (int i = number; i < LENGTH-1; i++)
	{
		swap(i, i + 1);
	}
}

void showContacts(int length) {
	while (true)
	{
		system("cls");
		for (int i = 0; i < length; i++)
		{
			printf("\n%d: %s %s %s %s ", i, humans[i].lastName, humans[i].firstName, humans[i].patronymic, humans[i].telNumber);
		}
		printf("\n\nEnter *0* for exit from contacts\n*1* for choose contact\n*2* for add new contact\n*3* for delete contact\n*4* for search\n");
		printf("\nYou want: ");

		char act,a = '0';
		act = _getch();
		printf("%c", act);
		char contactNumber;

		if (act == '0')
		{
			break;
		}
		switch (act)
		{
		case '1':
			printf("\nEnter contact number, that you want to view: ");
			contactNumber;
			contactNumber = _getch();
			printf("%c", contactNumber);
			system("cls");
			showChoosenContact(int(contactNumber) - 48, length, 0);
			break;
		case '2':
			newContact(length);
			break;
		case '3':
			printf("\nEnter contact number, that you want to delete: ");
			contactNumber;
			contactNumber = _getch();
			printf("%c", contactNumber);
			printf("\nAre you sure want to delete contact %s %s ?", humans[int(contactNumber) - 48].lastName, humans[int(contactNumber) - 48].firstName);
			while (a != 'n')
			{
				printf("\n(y/n):");
				a = _getch();
				printf("%c", a);
				if (a == 'y')
				{
					system("cls");
					deleteContact(int(contactNumber) - 48);
				}
			}
			break;
		case '4':
			search();
		default:
			break;
		}
	}
}

void showChoosenContact(int number, int length, int mode) {
	if (mode == 1)
		humans[number] = { 0 };
	char a = '0';
	while (a != 'n')
	{
		int flag = 0;
		system("cls");
		printf("\n1)Last Name: %s\n2)First Name: %s\n3)Patronymic: %s\n4)Telephone Number: %s\n5)Email: %s\n6)Organization: %s\n7)Position: %s ", humans[number].lastName, humans[number].firstName, humans[number].patronymic, humans[number].telNumber, humans[number].email, humans[number].organization, humans[number].position);
		
		if (!(strcmp(humans[number].lastName, "")) || !(strcmp(humans[number].firstName, "")) || !(strcmp(humans[number].telNumber, "")))
		{
			printf("\nPlease enter information in the required fields: Last Name, First Name, Telephone Number\n");
		}
		else
		{
			flag = 1;
			printf("\n\nEdit this contact(y) or exit to list of contacts(n)?\n");
		}
		if (flag == 1)
		{
			printf("\n(y/n):");
			a = _getch();
			printf("%c", a);
		}
			
		if ((a == 'y') || (flag == 0))
		{
			if (mode == 0)
				printf("\nEnter field number, that you want to edit{1,...,7}: ");
			else
				printf("\nEnter field number, that you want to fill{1,...,7}: ");
			char field;
			field = _getch();
			printf("%c", field);
			char newInfo[50];
			switch (field)
				{
				case '1':
					printf("\nNew Last Name: ");
					gets_s(newInfo);
					strcpy_s(humans[number].lastName, newInfo);
					break;
				case '2':
					printf("\nNew First Name: ");
					gets_s(newInfo);
					strcpy_s(humans[number].firstName, newInfo);
					break;
				case '3':
					printf("\nNew Patronymic: ");
					gets_s(newInfo);
					strcpy_s(humans[number].lastName, newInfo);
					break;
				case '4':
					printf("\nNew Telephone Number: ");
					gets_s(newInfo);
					strcpy_s(humans[number].telNumber, newInfo);
					break;
				case '5':
					printf("\nNew Email: ");
					gets_s(newInfo);
					strcpy_s(humans[number].email, newInfo);
					break;
				case '6':
					printf("\nNew Organization: ");
					gets_s(newInfo);
					strcpy_s(humans[number].organization, newInfo);
					break;
				case '7':
					printf("\nNew Position: ");
					gets_s(newInfo);
					strcpy_s(humans[number].position, newInfo);
					break;
				default:
					break;
			}	
		}
	}
	putInOrder(length);
	showContacts(length);
}// with edit and add contact

void newContact(int number) {
	humans = (human *)realloc(humans, (number + 1) * sizeof(human));
	LENGTH++;
	showChoosenContact(number, number + 1, 1);
}

void deleteContact(int number) {
	shift(number);
	humans = (human *)realloc(humans, (LENGTH - 1) * sizeof(human));
	LENGTH -- ;
	showContacts(LENGTH);
}

void search() {
	system("cls");
	printf("\nEnter *1* for searching by full last name\n*2* for searching by full telephone number\n*3* for searching by first last name characters\n*4* for searching by first telephone number numbers");
	printf("\nYou want: ");

	char mode, searchFor[50];
	int k = 0;

	mode = _getch();
	printf("%c", mode);

	switch (mode)
	{
	case '1':	//searching by full last name
		system("cls");
		printf("\nEnter full last name: ");
		gets_s(searchFor);
		for (int i = 0; i < LENGTH; i++)
		{
			
			if (strcmp(humans[i].lastName, searchFor) == 0)
			{
				k++;
				printf("\n%d: %s %s %s %s ", i, humans[i].lastName, humans[i].firstName, humans[i].patronymic, humans[i].telNumber);
			}
		}
		if (k == 0)
		{
			printf("\nNo matching. Press any button");
			_getch();
		}
		else
		{
			printf("\nEnter number of contact, that you want to view or (n) for exit to the contacts list: ");
			mode = _getch();
			printf("%c", mode);
			if (mode != 'n')
				showChoosenContact((int)mode - 48, LENGTH, 0);
		}
		break;
	case '2': //searching by full telNumber
		system("cls");
		printf("\nEnter full Telephone Number with '+': ");
		gets_s(searchFor);
		for (int i = 0; i < LENGTH; i++)
		{

			if (strcmp(humans[i].telNumber, searchFor) == 0)
			{
				k++;
				printf("\n%d: %s %s %s %s ", i, humans[i].lastName, humans[i].firstName, humans[i].patronymic, humans[i].telNumber);
			}
		}
		if (k == 0)
		{
			printf("\nNo matching. Press any button");
			_getch();
		}
		else
		{
			printf("\n\nEnter number of contact, that you want to view or (n) for exit to the contacts list: ");
			mode = _getch();
			printf("%c", mode);
			if (mode != 'n')
				showChoosenContact((int)mode - 48, LENGTH, 0);
		}
		break;
	case '3': //searching by first characters
		system("cls");
		printf("\nEnter first characters of last name: ");
		gets_s(searchFor);
		for (int i = 0; i < LENGTH; i++)
		{
			int j;
			for ( j = 0; j < strlen(searchFor); j++)
			{
				if (humans[i].lastName[j] != searchFor[j])
				{
					break;
				}
			}
			if (j == strlen(searchFor))
			{
				printf("\n%d: %s %s %s %s ", i, humans[i].lastName, humans[i].firstName, humans[i].patronymic, humans[i].telNumber);
				k++;
			}
		}
		if (k == 0)
		{
			printf("\nNo matching. Press any button");
			_getch();
		}
		else
		{
			printf("\nEnter number of contact, that you want to view or (n) for exit to the contacts list: ");
			mode = _getch();
			printf("%c", mode);
			if (mode != 'n')
				showChoosenContact((int)mode - 48, LENGTH, 0);
		}
		break;
	case '4': //searching by first numbers 
		system("cls");
		printf("\nEnter first characters of telephone number with '+': ");
		gets_s(searchFor);
		for (int i = 0; i < LENGTH; i++)
		{
			int j;
			for (j = 0; j < strlen(searchFor); j++)
			{
				if (humans[i].telNumber[j] != searchFor[j])
				{
					break;
				}
			}
			if (j == strlen(searchFor))
			{
				printf("\n%d: %s %s %s %s ", i, humans[i].lastName, humans[i].firstName, humans[i].patronymic, humans[i].telNumber);
				k++;
			}
		}
		if (k == 0)
		{
			printf("\nNo matching. Press any button");
			_getch();
		}
		else
		{
			printf("\nEnter number of contact, that you want to view or (n) for exit to the contacts list: ");
			mode = _getch();
			printf("%c", mode);
			if(mode != 'n')
				showChoosenContact((int)mode - 48, LENGTH, 0);
		}
		break;
	default:
		break;
	}
	
}

int main() {
	init();
	putInOrder(LENGTH);
	printf("Hello!\nPress any button to go to contacts");
	_getch();
	showContacts(LENGTH);
	return 0;
}