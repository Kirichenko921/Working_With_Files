#pragma once
//#include"CountSort.h"

int getMax(int* arr, int n) // функция для нахождения максимального элемента массива
{
    int max = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > max)
            max = arr[i];
    return max;
}

void countSort(int* arr, int n, int exp)
{
    int* output = new int[n];
    int count[10] = { 0 }; // выделяем память под массив частот размером 10, так как используем 10-чную систему счисления

    // вычисление разряда элемента arr[i] выполняет выражение 
    // (arr[i] / exp) % 10
    for (int i = 0; i < n; i++)
        count[(arr[i] / exp) % 10]++;  // вычисляем значение разряда и считаем его частоту

    for (int i = 1; i < 10; i++)
        count[i] += count[i - 1];

    for (int i = n - 1; i >= 0; i--) {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }

    for (int i = 0; i < n; i++)
        arr[i] = output[i];
}

void radixSort(int* arr, int n)
{
    int m = getMax(arr, n); // находим максимальное число
    // выполняем сортировку массива, пока не дойдем до старшего разряда наибольшего числа 

    int exp = 1;

    countSort(arr, n, exp);
}