#include <stdio.h>

#define N 3
#define M 3

int main() {
	int q[N] = { 4,5,6 };
	int b[M] = { 1,2,3 };
	int c[N+M];

	int i = 0, j = 0;

	for (int k = 0; k < N+M; k++)
		if ((j > M - 1) || ((i<N) && (q[i] < b[j])))
			c[k] = q[i++];
		else
			c[k] = b[j++];

	return 0;
}