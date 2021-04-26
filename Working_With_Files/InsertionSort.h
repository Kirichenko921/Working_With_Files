#pragma once
void insertionSort(int* arr, int n)
{
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;

        // Сдвигаем элементы arr[0..i-1], которые больше чем key, на одну позицию вперед


        arr[j + 1] = key;
    }
}