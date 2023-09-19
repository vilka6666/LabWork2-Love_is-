#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>

void RandomArr(int* items, int count) {
    for (int i = 0; i < count; i++) {
        items[i] = rand() % 1000;
    }
}
void IncreasingArr(int* items, int count) {
    for (int i = 0; i < count; i++) {
        items[i] = i;
    }
}
void DecreasingArr(int* items, int count) {
    for (int i = 0; i < count; i++) {
        items[i] = count - i;
    }
}
void IncreasingDecreasingArr(int* items, int count) {
    int middle = count / 2;

    for (int i = 0; i < middle; i++) {
        items[i] = i;
    }

    for (int i = middle; i < count; i++) {
        items[i] = count - i;
    }
}
int compare(const void* a, const void* b) { //для стандартной функции qsort
    return (*(int*)a - *(int*)b);
}
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

int main() {
    srand(time(NULL)); // Инициализация генератора случайных чисел
    setlocale(LC_ALL, "Rus");
    int count = 200000; // Размер массива 
    int* arr = (int*)malloc(sizeof(int) * count); // Выделение памяти для массива

    RandomArr(arr, count);
    //IncreasingArr(arr, count);
    //DecreasingArr(arr, count);
    //IncreasingDecreasingArr(arr, count);

    clock_t start_time = clock(); // Засекаем начальное время

    //shell(arr, count); 
    //qs(arr, 0, count - 1);
    qsort(arr, count, sizeof(int), compare);

    clock_t end_time = clock(); // Засекаем конечное время

    double elapsed_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;
    
    printf("Время выполнения сортировки : %f секунд\n", elapsed_time);

    free(arr); // Освобождаем память, выделенную для массива
    return 0;
}
