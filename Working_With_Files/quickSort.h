#pragma once
void swap(int* a, int* b) // функция для смены местами двух значений
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int* arr, int low, int high)
{
    int pivot = arr[high];    // опорный элемент
    int i = (low - 1);  // индекс наименьшего элемента
    for (int j = low; j <= high - 1; j++)
    {
        // если текущий элемент меньше или равен опорнуму
        if (arr[j] <= pivot)
        {
            i++; // увеличиваем индекс минимального элемента
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quickSort(int* arr, int low, int high)
{
    if (low < high)
    {
        int pi = partition(arr, low, high); // индекс опорного элемента

        // рекурсивыне вызовы для правой и левой частей входного массива
        if (pi > 0 && pi < high)
        {
            quickSort(arr, low, pi - 1);
            quickSort(arr, pi + 1, high);
        }
        else if (pi == high)
        {

            --high;
            quickSort(arr, low, high);
        }
        else
        {
            ++low;
            quickSort(arr, low, high);
        }

    }
}
