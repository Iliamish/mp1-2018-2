#pragma once

typedef struct file {
	char link[60];
	long long int size;
};

long long int size(char *link);
char *makeLink(char folder[250], char doc[60]);
void swap(int idx1, int idx2);
void swipe(int length);
void qs(int first, int last);
void ms(int first, int last);
void merge(int first, int split, int last);
file* bubbleSort(file *files, int length, int mode);
file* selectSort(file *files, int length, int mode);
file* insertSort(file *files, int length, int mode);
file* mergeSort(file *files, int length, int mode);
file* quickSort(file *files, int length, int mode);
file* shellSort(file *files, int length, int mode);
file* countingSort(file *files, int length, int mode);
