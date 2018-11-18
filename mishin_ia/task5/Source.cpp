#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <io.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <conio.h>
#include "windows.h"
#include "Header.h"
#pragma warning(disable : 4996).

file *files;
char cop[250];

long long int size(char *link)
{
	struct _stat st;
	int res = _stat(link, &st);
	if (res == 0)
		return st.st_size;
}

char *makeLink(char folder[250], char doc[60])
{
	strcpy_s(cop, "");
	strcpy_s(cop, folder);
	strcat_s(cop, doc);
	return cop;
}

void chooseSort(int sort, int length, int mode) 
{
	clock_t t1 = clock(), t2;
	switch (sort)
	{
	case 0: 
		files = bubbleSort(files, length, mode);
		break;
	case 1:
		files = selectSort(files, length, mode);
		break;
	case 2:
		files = insertSort(files, length, mode);
		break;
	case 3:
		files = mergeSort(files, length, mode);
		break;
	case 4:
		files = quickSort(files, length, mode);
		break;
	case 5:
		files = shellSort(files, length, mode);
		break;
	case 6:
		files = countingSort(files, length, mode);
		break;
	default:
		break;
	}
	t2 = clock();
	double tt = (double)(t2 - t1) / CLOCKS_PER_SEC;
	printf("\nSort time: %f", tt);
}

void printSort(char sort) 
{	
	switch (sort)
	{
	case('0'):
		printf("bubble sort");
		break;
	case('1'):
		printf("select sort");
		break;
	case('2'):
		printf("insert sort");
		break;
	case('3'):
		printf("merge sort");
		break;
	case('4'):
		printf("quick sort");
		break;
	case('5'):
		printf("shell sort");
		break;
	case('6'):
		printf("count sort");
		break;
	default:
		break;
	}
}

char sorts()
{
	char a = ' ';
	while (a < '0' || a > '9')
	{
		system("cls");
		printf("\nChoose sorting method\n");
		printf("*0* - bubble sort\n*1* - select sort\n*2* - insert sort\n*3* - merge sort\n*4* - quick sort\n*5* - shell sort\n*6* - count sort");
		printf("\nYou choose: ");
		a = _getch();
		printSort(a);
	}
	return a;
}

char chooseMode()
{
	char mode;
	printf("\nSort ascending(0) or descending(1)? \n(1/0): ");
	mode = _getch();
	printf("%c", mode);
	return mode;
}

int main() {
	printf("Hello!\nPress any button...");
	_getch();
	int newSort = 0;
	char str[250], strs[250], link[250] = { 0 };
	while (true)
	{
		system("cls");
		files = (file*)malloc(sizeof(file));
		WIN32_FIND_DATA FindFileData;
		
		if (newSort == 0)
		{
			printf("Enter folder path (Example c:\\folder1\\folder2) : ");
			gets_s(str);

			int pos = 0, ins = 0;
			for (int i = 0; i < 250; i++)
			{
				if (str[i] == '\0')
				{
					for (int j = pos; j < i; j++)
						link[j + ins] = str[j];
					link[i + ins] = '\\';
					link[i + ins + 1] = '\\';
					link[i + ins + 2] = '\0';
					break;
				}
				else
				{
					if (str[i] == '\\')
					{
						for (int j = pos; j <= i; j++)
							link[j + ins] = str[j];
						link[i + ins + 1] = '\\';
						link[i + ins + 2] = '\0';
						ins += 1;
						pos = i + 1;
					}
				}
			}
		}
		strcpy_s(strs, link);
		strcat_s(strs, "*.*");

		system("cls");
		
		HANDLE h = FindFirstFile(strs, &FindFileData);

		int k = 0, flag = 0;
		if (h != INVALID_HANDLE_VALUE)
		{
			while (FindNextFile(h, &FindFileData))
				k++;
			
			files = (file*)malloc(k * sizeof(file));
			flag = 0;
			k = 0;
			h = FindFirstFile(strs, &FindFileData);

			do
			{
				char *fileName;
				fileName = makeLink(link, FindFileData.cFileName);
				strcpy_s(files[k].link, FindFileData.cFileName);
				files[k].size = size(fileName);
				k++;
			} while (FindNextFile(h, &FindFileData));
		}
		else
		{
			fprintf(stderr, "Error opening directory\n");
			printf("\nPress any button...");
			_getch();
			flag = 1;
		}

		char a = ' ';

		if (flag == 0 && a != '4')
		{
			char srt = sorts(), mode = chooseMode();

			system("cls");
			printf("Path: %s", str);
			printf("\nSort: ");
			printSort(srt);

			chooseSort(int(srt) - 48, k, int(mode) - 48);

			if (files == 0)
			{
				printf("\nPress any button...");
				_getch();
				a = '3';
			}
			else
			{
				printf("\nDone!");
			}			
			while (a != '4' && a != '3' && a != '1')
			{
				printf("\nWhat you want:\n*0* - see sorted list\n*1* - choose new sorting method\n*2* - flip the list(ascending->descinding or descinding->ascending)\n*3* - enter new folder path\n*4* - exit\nYou choose: ");
				a = _getch();
				printf("%c", a);
				switch (a)
				{
				case '0':
					system("cls");
					for (int i = 0; i < k; i++)
					{
						printf("\n%s size: %d", files[i].link, files[i].size);
					}
					break;
				case '1':
					flag = 1;
					newSort = 1;
					break;
				case '2':
					chooseSort(int(srt) - 48, k, 1 - int(mode) + 48);
					if (mode == '0')
						mode = '1';
					else
						mode = '0';
					printf("\nDone!");
					break;
				case '3':
					flag = 1;
					newSort = 0;
					break;
				default:
					break;
				}
				printf("\nPress any button...");
				_getch();
				system("cls");
			}
		}
		if (a == '4')
		{
			break;
		}
	}
	printf("Good bye!");
	_getch();
	return 0;
}
 