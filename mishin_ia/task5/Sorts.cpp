#include "Header.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

file* swap(file *files, int idx1, int idx2)
{
	file x = files[idx1];
	files[idx1] = files[idx2];
	files[idx2] = x;
	return files;
}

file* swipe(file *files, int length)
{
	for (int i = 0; i < length / 2; i++)
	{
		files = swap(files ,i, length - 1 - i);
	}
	return files;
}

file* bubbleSort(file *files, int length, int mode)
{
	for (int i = 0; i < length; i++)
	{
		for (int j = length - 1; j > i; j--)
		{
			if (files[j].size < files[j - 1].size)
			{
				files = swap(files, j, j - 1);
			}
		}
	}
	if (mode == 1)
		files = swipe(files, length);
	return files;
}

file* selectSort(file *files, int length, int mode)
{
	long long int max = -2;
	int k;
	for (int i = 0; i < length; i++)
	{
		max = -2;
		for (int j = i; j < length; j++)
		{
			if (files[j].size > max)
			{
				max = files[j].size;
				k = j;
			}
		}
		files = swap(files, i, k);
	}
	if (mode == 0)
		files = swipe(files, length);
	return files;
}

file* insertSort(file *files, int length, int mode)
{
	int j;
	for (int i = 0; i < length; i++)
	{
		file x = files[i];
		for (j = i - 1; (j >= 0) && (files[j].size > x.size); j--)
			files[j + 1] = files[j];
		files[j + 1] = x;
	}
	if (mode == 1)
		files = swipe(files, length);
	return files;
}

file* mergeSort(file *files, int length, int mode)
{
	ms(files, 0, length - 1);
	if (mode == 1)
		files = swipe(files, length);
	return files;
}

file* ms(file *files, int first, int last)
{
	if (first < last)
	{
		int split = (first + last) / 2;
		ms(files, first, split);
		ms(files, split + 1, last);
		merge(files, first, split, last);
	}
	return files;
}

file* merge(file *files, int first, int split, int last)
{
	file *sorted;
	sorted = (file *)calloc(last - first + 1, sizeof(file));
	int i = first, j = split + 1;

	for (int k = 0; k <= last - first; k++)
		if ((j > last) || ((i <= split) && (files[i].size < files[j].size)))
			sorted[k] = files[i++];
		else
			sorted[k] = files[j++];
	for (int k = first; k <= last; k++)
		files[k] = sorted[k - first];
	return files;
}

file* quickSort(file *files, int length, int mode)
{
	files = qs(files, 0, length-1);
	if (mode == 1)
		files = swipe(files, length);
	return files;
}

file* qs(file *files, int first, int last)
{
	int i = first;
	int j = last;
	file x = files[(first + last) / 2];
	do {
		while (files[i].size < x.size) i++;
		while (files[j].size > x.size) j--;
		if (i <= j) {
			files = swap(files, i, j);
			i++; j--;
		}
	} while (i <= j);
	if (last > i) qs(files, i, last);
	if (j > first) qs(files, first , j);
	return files;
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
	long inc, i, j, seq[40];
	int s;
	s = increment(seq, length);
	while (s >= 0) {
		inc = seq[s--];
		for (i = inc; i < length; i++) {
			file temp = files[i];
			for (j = i - inc; (j >= 0) && (files[j].size > temp.size); j -= inc)
				files[j + inc] = files[j];
			files[j + inc] = temp;
		}
	}
	if (mode == 1)
		files = swipe(files, length);
	return files;
}

file* countingSort(file *files, int length, int mode)
{
	file *sorted;
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
		sorted = swipe(sorted, length);
	return sorted;
}
