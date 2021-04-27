#pragma once
void swap(int* a, int* b) // функция для смены местами двух значений
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bubbleSort(int* arr, int n)
{
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - 1; j++)
            if (arr[j + 1] < arr[j])
            swap(&arr[j], &arr[j + 1]);
}