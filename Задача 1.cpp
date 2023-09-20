#define _CRT_SECURE_NO_WARNINGS // Исправление ошибок fopen

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>

int main(void)
{
	setlocale(LC_ALL, "RUS"); // Локализация Русского языка
	clock_t start, end;
	double cpu_time_used;
	int i, j, k, N, l;
	printf("Введите размер матриц: ");
	scanf("%d", &N);

	int** a = (int**)malloc(N * sizeof(int*));
	int** b = (int**)malloc(N * sizeof(int*));
	int** c = (int**)malloc(N * sizeof(int*));

	for (i = 0; i < N; i++)
	{
		a[i] = (int*)malloc(N * sizeof(int));
		b[i] = (int*)malloc(N * sizeof(int));
		c[i] = (int*)malloc(N * sizeof(int));
	}

	srand(time(NULL));

	for (i = 0; i < N; i++)
	{
		for (j = 0; j < N; j++)
		{
			a[i][j] = rand() % 100 + 1;
			b[i][j] = rand() % 100 + 1;
		}
	}

	start = clock();

	for (i = 0; i < N; i++)
	{
		for (j = 0; j < N; j++)
		{
			
			l= 0;
			for (k = 0; k < N; k++)
			{
				l += a[i][k] * b[k][j];
				c[i][j] = l;
			}
		}
	}

	end = clock();
	cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
	printf("Время выполнения: %f секунд\n", cpu_time_used);

	for (i = 0; i < N; i++)
	{
		free(a[i]);
		free(b[i]);
		free(c[i]);
	}
	free(a);
	free(b);
	free(c);

	return 0;
}
