#include <stdio.h>
#include <conio.h>

#define N 6
#define M 7

int main() {
	int q[N] = { -3,3,4,6,7,8 };
	int b[M] = { -2,-1,0,2,4,7,9 };
	int c[N+M];

	int i = 0, j = 0;

	for (int k = 0; k < N+M; k++)
	{
		if (((i<N) && (j<M) && (q[i]<b[j])) || (j > M-1))
		{
			c[k] = q[i];
			i++;
		}
		else
		{
			c[k] = b[j];
			j++;
		}
		printf("%d ", c[k]);
	}
	_getch();
	return 0;
}