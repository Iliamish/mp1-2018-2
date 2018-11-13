#include "Header.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

file *sorted;

void swap(int idx1, int idx2)

{
	file x = sorted[idx1];
	sorted[idx1] = sorted[idx2];
	sorted[idx2] = x;
}

void swipe(int length)
{
	for (int i = 0; i < length / 2; i++)
	{
		swap(i, length - 1 - i);
	}
}

file* bubbleSort(file *files, int length, int mode)
{
	sorted = files;
	for (int i = 0; i < length; i++)
	{
		for (int j = length - 1; j > i; j--)
		{
			if (sorted[j].size < sorted[j - 1].size)
			{
				swap(j, j - 1);
			}
		}
	}
	if (mode == 1)
		swipe(length);
	return sorted;
}

file* selectSort(file *files, int length, int mode)
{
	sorted = files;
	int k, max = -1;
	for (int i = 0; i < length; i++)
	{
		max = -1;
		for (int j = i; j < length; j++)
		{
			if (sorted[j].size > max)
			{
				max = sorted[j].size;
				k = j;
			}
		}
		swap(i, k);
	}
	if (mode == 0)
		swipe(length);
	return sorted;
}

file* insertSort(file *files, int length, int mode)
{
	int j;
	sorted = files;
	for (int i = 0; i < length; i++)
	{
		file x = sorted[i];
		for (j = i - 1; (j >= 0) && (sorted[j].size > x.size); j--)
			sorted[j + 1] = sorted[j];
		sorted[j + 1] = x;
	}
	if (mode == 1)
		swipe(length);
	return sorted;
}

file* mergeSort(file *files, int length, int mode)
{
	sorted = files;
	ms(0, length - 1);
	if (mode == 1)
		swipe(length);
	return sorted;
}

void ms(int first, int last)
{
	if (first < last)
	{
		int split = (first + last) / 2;
		ms(first, split);
		ms(split + 1, last);
		merge(first, split, last);
	}
}

void merge(int first, int split, int last)
{
	file *files;
	files = (file *)calloc(last - first + 1, sizeof(file));
	int i = first, j = split + 1;

	for (int k = 0; k <= last - first; k++)
		if ((j > last) || ((i <= split) && (sorted[i].size < sorted[j].size)))
			files[k] = sorted[i++];
		else
			files[k] = sorted[j++];
	for (int k = first; k <= last; k++)
		sorted[k] = files[k - first];
}

file* quickSort(file *files, int length, int mode)
{
	sorted = files;
	qs(0, length-1);
	if (mode == 1)
		swipe(length);
	return sorted;
}

void qs(int first, int last)
{
	int i = first;
	int j = last;
	file x = sorted[(first + last) / 2];
	do {
		while (sorted[i].size < x.size) i++;
		while (sorted[j].size > x.size) j--;
		if (i <= j) {
			swap(i, j);
			i++; j--;
		}
	} while (i <= j);
	if (last > i) qs(i, last);
	if (j > first) qs(first , j);
}

int increment(long inc[], long size) {
	int p1, p2, p3, s;

	p1 = p2 = p3 = 1;
	s = -1;
	do {
		if (++s % 2) {
			inc[s] = 8 * p1 - 6 * p2 + 1;
		}
		else {
			inc[s] = 9 * p1 - 9 * p3 + 1;
			p2 *= 2;
			p3 *= 2;
		}
		p1 *= 2;
	} while (3 * inc[s] < size);

	return s > 0 ? --s : 0;
}

file* shellSort(file *files, int length, int mode)
{
	sorted = files;
	long inc, i, j, seq[40];
	int s;
	s = increment(seq, length);
	while (s >= 0) {
		inc = seq[s--];
		for (i = inc; i < length; i++) {
			file temp = sorted[i];
			for (j = i - inc; (j >= 0) && (sorted[j].size > temp.size); j -= inc)
				sorted[j + inc] = sorted[j];
			sorted[j + inc] = temp;
		}
	}
	if (mode == 1)
		swipe(length);
	return sorted;
}

file* countingSort(file *files, int length, int mode)
{
	sorted = (file *)calloc(length, sizeof(file));
	int max = 0, *counts;
	for (int i = 0; i < length; i++)
	{
		if (files[i].size > max)
			max = files[i].size;
	}
	if (max > 1000 || length < max)
	{
		printf(" (This type of sort isn't suitable for this folder) ");
		return 0;
	}

	counts = (int *)calloc(max + 2, sizeof(int));
	
	for (int i = 0; i < max + 2; i++)
		counts[i] = 0;

	for (int i = 0; i < length; i++)
		++counts[files[i].size + 1];

	if (counts[0] != 0)
		counts[0] = counts[0] * (-1);
	
	for (int i = 1; i < max + 2; i++)
		counts[i] += counts[i - 1];

	for (int i = length-1; i >= 0; i--)
	{
		counts[files[i].size + 1] -= 1;
		sorted[counts[files[i].size + 1]] = files[i];
	}
	if (mode == 1)
		swipe(length);
	return sorted;
}
