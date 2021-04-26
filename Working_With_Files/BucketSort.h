#pragma once
struct bucket{
   int count; // количество элементов в корзине
   int* data; // массив элементов корзины
};

int getMax(int* arr, int n) // функция для нахождения максимального элемента массива
{
    int max = arr[0];
    for (int i = 1; i < n; i++)
    {
        if (arr[i] > max)
            max = arr[i];
    }
    return max;
}

int getExp(int value) {
    int exp = 1;

    while (value > 10)
    {
        value /= 10;
        exp *= 10;
    }

    return exp;
}

void countSort(int* arr, int n)
{
    if (!n)
        return;
    int* output = new int[n];
    int max = getMax(arr, n);
    int* count = new int[max + 1];

    for (int i = 0; i < max + 1; i++)
    {
        count[i] = 0;
    }

    for (int i = 0; i < n; ++i)
    {
        count[arr[i]]++;
    }// подсчитываем частоту повторения элементов

    for (int i = 1; i <= max; i++)
    {
        count[i] += count[i - 1];
    } // вычисляем накопленные суммы

    for (int i = n - 1; i >= 0; i--) {
        output[count[arr[i]] - 1] = arr[i]; // устанавливаем элемент на корректное место 
        count[arr[i]]--; // уменьшаем частоту, так как уже записали элемент
    }

    for (int i = 0; i < n; i++)
    {
        arr[i] = output[i];
    }

    delete[] output;
    delete[] count;
}

void bucketSort(int* arr, int n)
{
    struct bucket buckets[10];
    // вычисляем значение экспоненты
    int exp = getExp(getMax(arr, n));

    for (int i = 0; i < 10; i++)
    {
        buckets[i].count = 0;
        buckets[i].data = new int[n];
    }
    for (int i = 0; i < n; i++) {
        int bi = arr[i] / exp; // вычисляем индекс корзины
        buckets[bi].data[buckets[bi].count++] = arr[i]; // добавляем элемент в корзину
      
    }

    for (int i = 0; i < 10; ++i)
    {
        countSort(buckets[i].data, buckets[i].count);
    }

    for (int i = 0, k = 0; i < 10; ++i)
    {

        for (int j = 0; j < buckets[i].count; ++j)
        {
            arr[k] = buckets[i].data[j];
            k++;
        }
    }
}