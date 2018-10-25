#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

typedef struct human{
	char *firstName;
};

int main() {
	human humanin;
	humanin = {"Karl"};
	printf("%d", sizeof(human));
	_getch();
	return 0;
	/*
	humans[0] = { "Hohlov","Mark" ,"Olegovich", "+79023455678","dsfk@mail.ru" };
	humans[1] = { "Petrov","Pavel", "Petrovich", "+79033442343","sdfksdlf@gmail.com",{ "Intel", "Stager" } };
	*/
}