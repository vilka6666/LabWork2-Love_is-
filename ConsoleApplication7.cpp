#define _CRT_SECURE_NO_WARNINGS // Исправление ошибок fopen
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <cstdlib>
#include <time.h>
#include <locale.h>

void shell(int* items, int count)
{
    int i, j, gap, k;
    int x, a[5];
    a[0] = 9; a[1] = 5; a[2] = 3; a[3] = 2; a[4] = 1;
    for (k = 0; k < 5; k++) {
        gap = a[k];
        for (i = gap; i < count; ++i) {
            x = items[i];
            for (j = i - gap; (x < items[j]) && (j >= 0); j = j - gap)
                items[j + gap] = items[j];
            items[j + gap] = x;
        }
    }
}

void qs(int* items, int left, int right) //вызов функции: qs(items, 0, count-1);
{
    int i, j;
    int x, y;


    i = left; j = right;

    /* выбор компаранда */
    x = items[(left + right) / 2];

    do {
        while ((items[i] < x) && (i < right)) i++;
        while ((x < items[j]) && (j > left)) j--;

        if (i <= j) {
            y = items[i];
            items[i] = items[j];
            items[j] = y;
            i++; j--;
        }
    } while (i <= j);

    if (left < j) qs(items, left, j);
    if (i < right) qs(items, i, right);
}

int comp(const void* i, const void* j)
{
    return *(int*)i - *(int*)j;
}


const int N = 20000;
int a[N][N];

int main(void)
{
    setlocale(LC_ALL, "RUS"); // Локализация Русского языка
    clock_t start, end;
    double cpu_time_used;
    int i, j, k, l;
    srand(time(NULL));

    start = clock();

    a[0][0] = N * N;

    //for (i = 0; i < N; i++) // Задания 1-3 (2 часть)
    //{
    //    for (j = 0; j < N; j++)
    //    {   
    //        //a[i][j] = rand() % 100 - 1;
    //        //a[i][j] = a[i][j - 1] + 2;
    //        a[0][0] = N * N;
    //        a[i][j] = a[i][j - 1] - 2;
    //    }
    //}

    for (i = 0; i < N/2; i++) // Задание 4,5 (2 часть)
    {
        for (j = 0; j < N; j++)
        {
            a[i][j] = a[i][j - 1] + 2;
        }
    }

    for (i = N/2 - 1; i < N; i++) 
    {
        for (j = 0; j < N; j++)
        {
            a[N/2-1][0] = N * N;
            a[i][j] = a[i][j - 1] - 2;
        }
    }

    //shell(*a, N);
    //qs(*a, 0, N - 1);
    qsort(a, N, sizeof(int), comp);
    end = clock();
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Алгоритм Qsort\n");
    printf("Кол-во чисел: %d\n", N);
    printf("Время выполнения: %f секунд\n", cpu_time_used);

    return 0;
}