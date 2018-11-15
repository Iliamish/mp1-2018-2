#pragma once

typedef struct{
	char link[60];
	long long int size;
}file;

long long int size(char *link);
char *makeLink(char folder[250], char doc[60]);
file* swap(file *files, int idx1, int idx2);
file* swipe(file *files, int length);
file* qs(file *files, int first, int last);
file* ms(file *files, int first, int last);
file* merge(file *files, int first, int split, int last);
file* bubbleSort(file *files, int length, int mode);
file* selectSort(file *files, int length, int mode);
file* insertSort(file *files, int length, int mode);
file* mergeSort(file *files, int length, int mode);
file* quickSort(file *files, int length, int mode);
file* shellSort(file *files, int length, int mode);
file* countingSort(file *files, int length, int mode);
