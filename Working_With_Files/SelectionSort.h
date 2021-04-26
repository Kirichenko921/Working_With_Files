#pragma once
void swap(int* a, int* b) // функция для смены местами двух значений
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void selectionSort(int* arr, int n)
{    
        for (int i = 0; i < n; ++i)
    {
        int j = i+1;
        int min = arr[i];
        int index = i;
        while (j < n)
        {
            if (arr[j] < min)
            {
                min = arr[j];
                index = j;
            }
            ++j;
        }
        swap(&arr[i], &arr[index]);
    }
 }